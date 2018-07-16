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

#define REZ_FROM_J(obj, x, j) rez::detail::get_v(j, #x, obj.x)

namespace rez {
namespace detail {
inline const char* date_format = "%m/%d/%Y %T %p";
inline const char* date_format2 = "%Y-%m-%d  %T";

template <class T>
inline void get_v(const nlohmann::json& j, const char* key, T& val) {
	if constexpr (std::is_same_v<std::string, std::decay_t<T>>) {
		if (j.at(key).is_null()) {
			val = "";
		} else if (j.at(key).is_number_integer()) {
			val = std::to_string(j.value(key, 0));
		} else {
			val = j.value(key, "");
		}
	} else if constexpr (std::is_same_v<int, std::decay_t<T>>) {
		if (j.at(key).is_null()) {
			val = 0;
		} else if (j.at(key).is_string()) {
			val = std::stoi(j.value(key, "0"));
		} else {
			val = j.value(key, 0);
		}
	} else {
		if (j.at(key).is_null()) {
			val = T{};
		} else {
			val = j.value(key, T{});
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

namespace nlohmann {
template <>
struct adl_serializer<date::sys_seconds> {
	static void to_json(json& j, const date::sys_seconds& s) {
		j = date::format(rez::detail::date_format, s);
	}

	static void from_json(const json& j, date::sys_seconds& s) {
		if (!j.is_string()) {
			s = {};
			return;
		}

		std::istringstream iss{ j.get<std::string>() };
		try {
			iss >> date::parse(rez::detail::date_format, s);
			if (s == date::sys_seconds{}) {
				iss = std::istringstream{ j.get<std::string>() };
				iss >> date::parse(rez::detail::date_format2, s);
			}
		} catch (const std::exception& e) {
			fprintf(stderr, "%s\n", e.what());
		}
	}
};
} // namespace nlohmann
