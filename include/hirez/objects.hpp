#pragma once
#include "hirez/util.hpp"

#include <nlohmann/json.hpp>
#include <string>

#define REZ_TO_J(obj, x) \
	{ #x, obj.x }

#define REZ_FROM_STR(obj, x, j) obj.x = get_str(j, #x)
#define REZ_FROM_INT(obj, x, j) obj.x = get_int(j, #x)

namespace rez {
namespace detail {
inline std::string get_str(const nlohmann::json& j, const char* key) {
	if (j.at(key).is_null())
		return "";
	return j.value(key, "");
}

inline int get_int(const nlohmann::json& j, const char* key) {
	if (j.at(key).is_null())
		return 0;
	return j.value(key, 0);
}
} // namespace detail

struct session_response {
	std::string ret_msg{ "" };
	std::string session_id{ "" };
	std::string timestamp{ "" };
};
void to_json(nlohmann::json& j, const session_response& obj) {
	using namespace nlohmann;
	j = json{
		REZ_TO_J(obj, ret_msg),
		REZ_TO_J(obj, session_id),
		REZ_TO_J(obj, timestamp),
	};
}
void from_json(const nlohmann::json& j, session_response& obj) {
	using namespace nlohmann;
	using namespace detail;
	REZ_FROM_STR(obj, ret_msg, j);
	REZ_FROM_STR(obj, session_id, j);
	REZ_FROM_STR(obj, timestamp, j);
}

struct server_status {
	std::string entry_datetime{ "" };
	std::string ret_msg{ "" };
	std::string status{ "" };
	std::string version{ "" };
};
void to_json(nlohmann::json& j, const server_status& obj) {
	using namespace nlohmann;
	j = json{
		REZ_TO_J(obj, entry_datetime),
		REZ_TO_J(obj, ret_msg),
		REZ_TO_J(obj, status),
		REZ_TO_J(obj, version),
	};
}
void from_json(const nlohmann::json& j, server_status& obj) {
	using namespace nlohmann;
	using namespace detail;
	REZ_FROM_STR(obj, entry_datetime, j);
	REZ_FROM_STR(obj, ret_msg, j);
	REZ_FROM_STR(obj, status, j);
	REZ_FROM_STR(obj, version, j);
}

struct data_used {
	int Active_Sessions{ 0 };
	int Concurrent_Sessions{ 0 };
	int Request_Limit_Daily{ 0 };
	int Session_Cap{ 0 };
	int Session_Time_Limit{ 0 };
	int Total_Requests_Today{ 0 };
	int Total_Sessions_Today{ 0 };
	std::string ret_msg{ "" };
};
void to_json(nlohmann::json& j, const data_used& obj) {
	using namespace nlohmann;
	j = json{
		REZ_TO_J(obj, Active_Sessions),
		REZ_TO_J(obj, Concurrent_Sessions),
		REZ_TO_J(obj, Request_Limit_Daily),
		REZ_TO_J(obj, Session_Cap),
		REZ_TO_J(obj, Session_Time_Limit),
		REZ_TO_J(obj, Total_Requests_Today),
		REZ_TO_J(obj, Total_Sessions_Today),
		REZ_TO_J(obj, ret_msg),
	};
}
void from_json(const nlohmann::json& j, data_used& obj) {
	using namespace nlohmann;
	using namespace detail;
	REZ_FROM_INT(obj, Active_Sessions, j);
	REZ_FROM_INT(obj, Concurrent_Sessions, j);
	REZ_FROM_INT(obj, Request_Limit_Daily, j);
	REZ_FROM_INT(obj, Session_Cap, j);
	REZ_FROM_INT(obj, Session_Time_Limit, j);
	REZ_FROM_INT(obj, Total_Requests_Today, j);
	REZ_FROM_INT(obj, Total_Sessions_Today, j);
	REZ_FROM_STR(obj, ret_msg, j);
}

} // namespace rez
