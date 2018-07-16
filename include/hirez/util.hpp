#pragma once
#include <codecvt>
#include <date/date.h>
#include <locale>
#include <nlohmann/json.hpp>
#include <sstream>
#include <string>
#include <type_traits>

#define REZ_TO_J(obj, x) \
	{ #x, obj.x }
#define REZ_TO_DATE(obj, x) \
	{ #x, rez::detail::date_to_j(obj.x) }

#define REZ_FROM_J(obj, x, j) rez::detail::get_v(j, #x, obj.x)
#define REZ_FROM_DATE(obj, x, j) obj.x = rez::detail::date_from_j(j, #x)
#define REZ_FROM_DATE2(obj, x, j) obj.x = rez::detail::date_from_j(j, #x, 2)

namespace rez {
namespace detail {
inline const char* date_format = "%m/%d/%Y %T %p";
inline const char* date_format2 = "%Y-%m-%d  %T";

inline std::string date_to_j(const date::sys_seconds& s) {
	return date::format(date_format, s);
}

inline date::sys_seconds date_from_j(
		const nlohmann::json& j, const char* key, int version = 1) {
	if (j.at(key).is_null()) {
		return {};
	}
	std::istringstream iss{ j.value(key, "") };
	date::sys_seconds ret{};
	try {
		if (version == 1) {
			iss >> date::parse(rez::detail::date_format, ret);
		} else {
			iss >> date::parse(rez::detail::date_format2, ret);
		}
	} catch (const std::exception& e) {
		fprintf(stderr, "%s\n", e.what());
	}
	return ret;
}

template <class T>
inline void get_v(const nlohmann::json& j, const char* key, T& val) {
	static_assert((std::is_same_v<std::string, std::decay_t<T>>)
					|| (std::is_same_v<int, std::decay_t<T>>),
			"get_v : unsupported type conversion");

	if constexpr (std::is_same_v<std::string, std::decay_t<T>>) {
		if (j.at(key).is_null()) {
			val = "";
		} else if (j.at(key).is_number_integer()) {
			val = std::to_string(j.value(key, 0));
		} else {
			val = j.value(key, "");
		}
	} else if (std::is_same_v<int, std::decay_t<T>>) {
		if (j.at(key).is_null()) {
			val = 0;
		} else if (j.at(key).is_string()) {
			val = std::stoi(j.value(key, "0"));
		} else {
			val = j.value(key, 0);
		}
	}
}
} // namespace detail

inline std::wstring to_wstring(const std::string& str) {
	static std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	return converter.from_bytes(str);
}

inline std::string to_string(const std::wstring& str) {
	static std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	return converter.to_bytes(str);
}
} // namespace rez
