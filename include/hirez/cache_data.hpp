#pragma once
#include "hirez/objects.hpp"

#include <cassert>
#include <chrono>
#include <date/date.h>
#include <filesystem>
#include <fstream>
#include <string>

namespace rez {
namespace detail {

struct cache_data {
	cache_data(char* argv0)
			: _filepath(std::filesystem::absolute(argv0)
								.remove_filename()
								.u8string()
					  + _filename) {
		std::ifstream ifs{ _filepath, std::ios::binary, std::ios::trunc };
		if (!ifs.is_open())
			return;

		size_t size = 0;
		ifs.read(reinterpret_cast<char*>(&size), sizeof(size));
		_sesh_info.session_id = std::string(size, '\0');
		ifs.read(_sesh_info.session_id.data(), size);
		ifs.read(reinterpret_cast<char*>(&_sesh_info.timestamp),
				sizeof(_sesh_info.timestamp));
		ifs.read(reinterpret_cast<char*>(&_data_used.Request_Limit_Daily),
				sizeof(_data_used.Request_Limit_Daily));
		ifs.read(reinterpret_cast<char*>(&_data_used.Session_Cap),
				sizeof(_data_used.Session_Cap));
		ifs.read(reinterpret_cast<char*>(&_data_used.Session_Time_Limit),
				sizeof(_data_used.Session_Time_Limit));
		ifs.read(reinterpret_cast<char*>(&_data_used.Total_Requests_Today),
				sizeof(_data_used.Total_Requests_Today));
		ifs.read(reinterpret_cast<char*>(&_data_used.Total_Sessions_Today),
				sizeof(_data_used.Total_Sessions_Today));
		ifs.read(reinterpret_cast<char*>(&_session_limit_reached_at),
				sizeof(_session_limit_reached_at));
		ifs.read(reinterpret_cast<char*>(&_request_limit_reached_at),
				sizeof(_request_limit_reached_at));

		//_data_used.Session_Cap = 1;
		//_data_used.Session_Time_Limit = 1;
	}

	~cache_data() {
		std::ofstream ofs{ _filepath, std::ios::binary, std::ios::trunc };
		if (!ofs.is_open())
			return;

		size_t size = _sesh_info.session_id.size();
		ofs.write(reinterpret_cast<const char*>(&size), sizeof(size));
		ofs.write(_sesh_info.session_id.c_str(), _sesh_info.session_id.size());
		ofs.write(reinterpret_cast<const char*>(&_sesh_info.timestamp),
				sizeof(_sesh_info.timestamp));
		ofs.write(
				reinterpret_cast<const char*>(&_data_used.Request_Limit_Daily),
				sizeof(_data_used.Request_Limit_Daily));
		ofs.write(reinterpret_cast<const char*>(&_data_used.Session_Cap),
				sizeof(_data_used.Session_Cap));
		ofs.write(reinterpret_cast<const char*>(&_data_used.Session_Time_Limit),
				sizeof(_data_used.Session_Time_Limit));
		ofs.write(
				reinterpret_cast<const char*>(&_data_used.Total_Requests_Today),
				sizeof(_data_used.Total_Requests_Today));
		ofs.write(
				reinterpret_cast<const char*>(&_data_used.Total_Sessions_Today),
				sizeof(_data_used.Total_Sessions_Today));
		ofs.write(reinterpret_cast<const char*>(&_session_limit_reached_at),
				sizeof(_session_limit_reached_at));
		ofs.write(reinterpret_cast<const char*>(&_request_limit_reached_at),
				sizeof(_request_limit_reached_at));
	}

	cache_data(const cache_data&) = default;
	cache_data(cache_data&&) = default;
	cache_data& operator=(const cache_data&) = default;
	cache_data& operator=(cache_data&&) = default;

	bool can_create_new_session() {
		if (_session_limit_reached_at != date::sys_seconds{}) {
			if (hours_till_session_limit_reset() != std::chrono::hours{ 0 }) {
				return false;
			}
			_session_limit_reached_at = date::sys_seconds{};
			_data_used.Total_Sessions_Today = 0;
		}

		if (_data_used.Total_Sessions_Today >= _data_used.Session_Cap - 1) {
			_session_limit_reached_at
					= std::chrono::floor<std::chrono::seconds>(
							std::chrono::system_clock::now());
		}

		return _session_limit_reached_at == date::sys_seconds{};
	}

	void new_session(session_info&& si) {
		assert(can_create_new_session() && "ignored session limit");
		_sesh_info = si;
	}

	void new_data_used(data_used&& du) {
		assert(can_create_new_session() && "ignored session limit");
		_data_used = du;
		//_data_used.Session_Cap = 1;
		//_data_used.Session_Time_Limit = 1;
	}

	void invalidate() {
		_sesh_info = {};
		_data_used = {};
	}

	const session_info& get_session_info() const {
		return _sesh_info;
	}

	const data_used& get_data_used() const {
		return _data_used;
	}

	const std::string& session_id() const {
		return _sesh_info.session_id;
	}

	date::sys_seconds timestamp() const {
		return _sesh_info.timestamp;
	}

	std::chrono::minutes session_time_limit() const {
		return std::chrono::minutes{ _data_used.Session_Time_Limit };
	}

	std::chrono::hours hours_till_session_limit_reset() const {
		date::sys_seconds time = std::chrono::floor<std::chrono::seconds>(
				std::chrono::system_clock::now());
		date::sys_days time_days = date::floor<date::days>(time);
		date::year_month_day ymd{ time_days };
		date::year_month_day ymd_limit
				= date::floor<date::days>(_session_limit_reached_at);
		date::days days_passed = ymd.day() - ymd_limit.day();
		if (days_passed >= date::days{ 1 })
			return std::chrono::hours{ 0 };

		date::time_of_day tod{ time_days - time };
		return std::chrono::hours{ 24 } - tod.hours();
	}

private:
	const char* _filename = ".hrc_cache";
	std::string _filepath{ "" };
	session_info _sesh_info{};
	data_used _data_used{};
	date::sys_seconds _session_limit_reached_at{};
	date::sys_seconds _request_limit_reached_at{};
};

} // namespace detail
} // namespace rez
