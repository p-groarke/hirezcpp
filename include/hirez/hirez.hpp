#pragma once
#include "hirez/objects.hpp"
#include "hirez/objects_json.hpp"
#include "hirez/util.hpp"

#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cpprest/http_client.h>
#include <cpprest/uri.h>
#include <date/date.h>
#include <fstream>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <websocketpp/common/md5.hpp>

namespace rez {
namespace detail {
constexpr std::array<std::wstring_view, 7> game_uris{
	L"http://api.smitegame.com/smiteapi.svc",
	L"http://api.xbox.smitegame.com/smiteapi.svc",
	L"http://api.ps4.smitegame.com/smiteapi.svc",
	L"http://api.paladins.com/paladinsapi.svc",
	L"http://api.xbox.paladins.com/paladinsapi.svc",
	L"http://api.ps4.paladins.com/paladinsapi.svc",
	L"",
};

} // namespace detail

enum class game_e : size_t {
	smite_pc,
	smite_xbox,
	smite_ps4,
	paladins_pc,
	paladins_xbox,
	paladins_ps4,
	none,
};

namespace detail {
template <game_e T>
struct queue_trait {
	using type = queue_smi_e;
};
template <>
struct queue_trait<game_e::smite_pc> {
	using type = queue_smi_e;
};
template <>
struct queue_trait<game_e::smite_ps4> {
	using type = queue_smi_e;
};
template <>
struct queue_trait<game_e::smite_xbox> {
	using type = queue_smi_e;
};
template <>
struct queue_trait<game_e::paladins_pc> {
	using type = queue_pal_e;
};
template <>
struct queue_trait<game_e::paladins_ps4> {
	using type = queue_pal_e;
};
template <>
struct queue_trait<game_e::paladins_xbox> {
	using type = queue_pal_e;
};
template <game_e T>
using queue_t = typename queue_trait<T>::type;
} // namespace detail

enum class language_e : int {
	english = 1,
	german = 2,
	french = 3,
	chinese = 5,
	spanish = 7,
	spanish_latin_america = 9,
	portuguese = 10,
	russian = 11,
	polish = 12,
	turkish = 13,
	none = 0,
};

template <game_e EndPointFmt = game_e::paladins_pc>
struct session {
	const wchar_t* response = L"json";
	const wchar_t* game_url
			= detail::game_uris[static_cast<size_t>(EndPointFmt)].data();

	static constexpr bool paladins_api = EndPointFmt == game_e::paladins_pc
			|| EndPointFmt == game_e::paladins_ps4
			|| EndPointFmt == game_e::paladins_xbox;

	using queue_t = typename detail::queue_t<EndPointFmt>;

	session(const std::string& _dev_id, const std::string& _auth_key,
			bool cache_session_to_disk = true)
			: dev_id(_dev_id)
			, auth_key(_auth_key)
			, _http_client(game_url)
			, _cache_session_to_disk(cache_session_to_disk) {
		if (_cache_session_to_disk) {
			sesh_info = load_session_info();
		}
	}

	~session() {
		if (_cache_session_to_disk) {
			save_session_info(sesh_info);
		}
	}

	session(const session&) = default;
	session(session&&) = default;
	session& operator=(const session&) = default;
	session& operator=(session&&) = default;

	template <class... Ts>
	std::string call(const std::wstring& cmd, Ts&&... args) {
		using namespace web::http;
		static_assert((std::is_same_v<std::wstring, std::decay_t<Ts>> && ...),
				"arguments must be std::wstring");

		web::uri_builder builder(L"/");
		builder.append(cmd + response);
		(builder.append(std::forward<Ts>(args)), ...);

		// wprintf(L"calling : %s%s\n\n", game_url,
		// builder.to_string().c_str());

		std::string ret{ "" };
		_http_client.request(methods::GET, builder.to_string())
				.then([&](const http_response& resp) {
					// printf("recieved : %s\n",
					//		utility::conversions::to_utf8string(
					//				resp.to_string())
					//				.c_str());
					if (resp.status_code() == status_codes::OK) {
						ret = utility::conversions::to_utf8string(
								resp.extract_string().get());
						// printf("body : %s\n", ret.c_str());
					} else {
						fwprintf(stderr,
								L"Response invalid.\nStatus code : %hu\n"
								L"Calling end-point : %s%s\n"
								L"Response :\n%s\n",
								resp.status_code(), game_url,
								builder.to_string().c_str(),
								resp.to_string().c_str());
					}
				})
				.wait();
		return ret;
	}

	// /cmd[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{...}/{...}
	template <class... Ts>
	std::string session_call(const std::wstring& cmd, Ts&&... args) {
		static_assert((std::is_same_v<std::wstring, std::decay_t<Ts>> && ...),
				"arguments must be std::wstring");

		reconnect_if_needed();

		return call(cmd, wdev_id(), signature(cmd), wsession_id(), timestamp(),
				std::forward<Ts>(args)...);
	}

	std::wstring timestamp() const {
		using namespace std::chrono;
		date::sys_seconds time = floor<seconds>(system_clock::now());
		return to_wstring(date::format("%Y%m%d%H%M%S", time));
	}

	std::wstring signature(const std::wstring& method) const {
		using namespace websocketpp::md5;
		std::string ret{ dev_id + to_string(method) + auth_key
			+ to_string(timestamp()) };
		return to_wstring(md5_hash_hex(ret));
	}

	// APIs - Connectivity

	// /ping[ResponseFormat]
	// A quick way of validating access to the Hi-Rez API.
	std::string ping() {
		return call(L"ping");
	}

	// /createsession[ResponseFormat]/{developerId}/{signature}/{timestamp}
	// A required step to Authenticate the developerId/signature for further API
	// use.
	const session_info& createsession() {
		sesh_info = nlohmann::json::parse(call(L"createsession", wdev_id(),
				signature(L"createsession"), timestamp()));
		return sesh_info;
	}

	// /testsession[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}
	// A means of validating that a session is established.
	std::string testsession() {
		return session_call(L"testsession");
	}

	// /gethirezserverstatus[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}
	// Function returns UP/DOWN status for the primary game/platform
	// environments.  Data is cached once a minute.
	std::vector<server_status> gethirezserverstatus() {
		return nlohmann::json::parse(session_call(L"gethirezserverstatus"));
	}

	// APIs

	// /getdataused[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}
	// Returns API Developer daily usage limits and the current status against
	// those limits.
	std::vector<data_used> getdataused() {
		return nlohmann::json::parse(session_call(L"getdataused"));
	}

	// /getdemodetails[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{match_id}
	// Returns information regarding a particular match.  Rarely used in lieu of
	// getmatchdetails().
	auto getdemodetails(int match_id) {
		if constexpr (paladins_api) {
			std::vector<demo_details_pal> ret = nlohmann::json::parse(
					session_call(L"getdemodetails", std::to_wstring(match_id)));
			return ret;
		} else {
			std::vector<demo_details_smi> ret = nlohmann::json::parse(
					session_call(L"getdemodetails", std::to_wstring(match_id)));
			return ret;
		}
	}

	// /getesportsproleaguedetails[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}
	// Returns the matchup information for each matchup for the current
	// eSports Pro League season.  An important return value is
	// “match_status” which represents a match being scheduled (1),
	// in-progress (2), or complete (3)
	std::vector<esports_pro_league_details> getesportsproleaguedetails() {
		return nlohmann::json::parse(
				session_call(L"getesportsproleaguedetails"));
	}

	// /getfriends[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{player}
	// Returns the Smite User names of each of the player’s friends.  [PC
	// only]
	std::vector<friends> getfriends(const std::string& player) {
		static_assert(EndPointFmt == game_e::paladins_pc
						|| EndPointFmt == game_e::smite_pc,
				"getfriends only works on PC end-points");
		return nlohmann::json::parse(
				session_call(L"getfriends", to_wstring(player)));
	}

	// /getgodranks[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{player}
	// Returns the Rank and Worshippers value for each God a player has
	// played. [SmiteAPI only]
	std::vector<god_rank> getgodranks(const std::string& player) {
		static_assert(
				!paladins_api, "getgodranks only works on Smite end-points");
		return nlohmann::json::parse(
				session_call(L"getgodranks", to_wstring(player)));
	}

	// /getchampionranks[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{player}
	// Returns the Rank and Worshippers value for each Champion a player has
	// played. [PaladinsAPI only]
	std::vector<champion_rank> getchampionranks(const std::string& player) {
		static_assert(paladins_api,
				"getchampionranks only works on Paladins end-points");
		return nlohmann::json::parse(
				session_call(L"getchampionranks", to_wstring(player)));
	}

	// /getgods[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{languageCode}
	// Returns all Gods and their various attributes. [SmiteAPI only]
	std::vector<god> getgods(language_e language) {
		static_assert(!paladins_api, "getgods only works on Smite end-points");
		return nlohmann::json::parse(session_call(
				L"getgods", std::to_wstring(static_cast<int>(language))));
	}

	// /getchampions[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{languageCode}
	// Returns all Champions and their various attributes. [PaladinsAPI
	// only]
	std::vector<champion> getchampions(language_e language) {
		static_assert(
				paladins_api, "getchampions only works on Paladins end-points");
		return nlohmann::json::parse(session_call(
				L"getchampions", std::to_wstring(static_cast<int>(language))));
	}

	// /getgodleaderboard[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{godId}/{queue}
	// Returns the current season’s leaderboard for a god/queue combination.
	// [SmiteAPI only; queues 440, 450, 451 only]
	std::vector<god_leaderboard> getgodleaderboard(
			int god_id, queue_smi_e queue) {
		static_assert(!paladins_api,
				"getgodleaderboard only works on Smite end-points");

		bool queue_ok = queue == queue_smi_e::joust_1v1_ranked
				|| queue == queue_smi_e::joust_3v3_ranked
				|| queue == queue_smi_e::conquest_ranked;
		assert(queue_ok
				&& "getgodleaderboard queue must be joust_1v1_ranked "
				   "(440), joust_3v3_ranked (450) or conquest_ranked "
				   "(451)");

		return nlohmann::json::parse(
				session_call(L"getgodleaderboard", std::to_wstring(god_id),
						std::to_wstring(static_cast<int>(queue))));
	}

	// /getgodskins[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{godId}/{languageCode}
	// Returns all available skins for a particular God. [SmiteAPI only]
	std::vector<god_skin> getgodskins(int god_id, language_e language) {
		static_assert(
				!paladins_api, "getgodskins only works on Smite end-points");
		return nlohmann::json::parse(
				session_call(L"getgodskins", std::to_wstring(god_id),
						std::to_wstring(static_cast<int>(language))));
	}

	// /getchampionskins[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{godId}/{languageCode}
	// Returns all available skins for a particular Champion. [PaladinsAPI only]
	std::vector<champion_skin> getchampionskins(
			int champion_id, language_e language) {
		static_assert(paladins_api,
				"getchampionskins only works on Paladins end-points");
		return nlohmann::json::parse(
				session_call(L"getchampionskins", std::to_wstring(champion_id),
						std::to_wstring(static_cast<int>(language))));
	}

	// /getgodrecommendeditems[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{godid}/{languageCode}
	// Returns the Recommended Items for a particular God. [SmiteAPI only]
	std::vector<god_recommended_item> getgodrecommendeditems(
			int god_id, language_e language) {
		static_assert(!paladins_api,
				"getgodrecommendeditems only works on Smite end-points");
		return nlohmann::json::parse(
				session_call(L"getgodrecommendeditems", std::to_wstring(god_id),
						std::to_wstring(static_cast<int>(language))));
	}

	// /getchampionrecommendeditems[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{godid}/{languageCode}
	// Returns the Recommended Items for a particular Champion. [PaladinsAPI
	// only; Osbsolete - no data returned]
	std::string getchampionrecommendeditems(
			int champion_id, language_e language) {
		static_assert(paladins_api,
				"getchampionrecommendeditems only works on Paladins "
				"end-points");
		return nlohmann::json::parse(
				session_call(L"getchampionrecommendeditems",
						std::to_wstring(champion_id),
						std::to_wstring(static_cast<int>(language))))
				.dump(4);
	}

	// /getitems[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{languagecode}
	// Returns all Items and their various attributes.
	auto getitems(language_e language) {
		if constexpr (paladins_api) {
			std::vector<item_pal> ret = nlohmann::json::parse(session_call(
					L"getitems", std::to_wstring(static_cast<int>(language))));
			return ret;
		} else {
			std::vector<item_smi> ret = nlohmann::json::parse(session_call(
					L"getitems", std::to_wstring(static_cast<int>(language))));
			return ret;
		}
	}

	// /getmatchdetails[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{match_id}
	// Returns the statistics for a particular completed match.
	auto getmatchdetails(int match_id) {
		if constexpr (paladins_api) {
			std::vector<match_details_pal> ret
					= nlohmann::json::parse(session_call(
							L"getmatchdetails", std::to_wstring(match_id)));
			return ret;
		} else {
			std::vector<match_details_smi> ret
					= nlohmann::json::parse(session_call(
							L"getmatchdetails", std::to_wstring(match_id)));
			return ret;
		}
	}

	// /getmatchdetailsbatch[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{match_id,match_id,match_id,...match_id}
	// Returns the statistics for a particular set of completed matches.
	// NOTE: There is a byte imit to the amount of data returned; please limit
	// the CSV parameter to 5 to 10 matches because of this and for Hi-Rez DB
	// Performance reasons.
	auto getmatchdetailsbatch(const std::vector<int>& match_ids) {
		const size_t num_batch = 5;
		std::vector<std::wstring> match_ids_s{ match_ids.size() };
		std::transform(match_ids.begin(), match_ids.end(), match_ids_s.begin(),
				[](int id) { return std::to_wstring(id) + L","; });

		auto move_data = [](auto& details, auto& ret) {
			std::unordered_map<int, std::decay_t<decltype(details)>> map;
			for (auto& d : details) {
				map[d.Match].push_back(std::move(d));
			}
			for (auto& v : map) {
				ret.push_back(std::move(v.second));
			}
		};

		auto get_data = [&](auto& ret) {
			for (size_t i = 0; i < match_ids_s.size(); i += num_batch) {
				size_t end = std::min(i + num_batch, match_ids_s.size());
				std::wstring arg;
				arg.reserve((10 + 1) * num_batch);
				arg = std::accumulate(match_ids_s.begin() + i,
						match_ids_s.begin() + end, arg);
				arg.resize(arg.size() - 1);

				if constexpr (paladins_api) {
					std::vector<match_details_pal> details
							= nlohmann::json::parse(
									session_call(L"getmatchdetailsbatch", arg));
					move_data(details, ret);
				} else {
					std::vector<match_details_smi> details
							= nlohmann::json::parse(
									session_call(L"getmatchdetailsbatch", arg));
					move_data(details, ret);
				}
			}
		};

		if constexpr (paladins_api) {
			std::vector<std::vector<match_details_pal>> ret{};
			get_data(ret);
			return ret;
		} else {
			std::vector<std::vector<match_details_smi>> ret{};
			get_data(ret);
			return ret;
		}
	}

	// /getmatchplayerdetails[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{match_id}
	// Returns player information for a live match.


	// /getmatchidsbyqueue[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{queue}/
	// {date}/{hour}
	// Lists all Match IDs for a particular Match Queue; useful for API
	// developers interested in constructing data by Queue.
	//
	// To limit the data returned, an {hour} parameter was added (valid values:
	// 0 - 23). An {hour} parameter of -1 represents the entire day, but be
	// warned that this may be more data than we can return for certain queues.
	// Also, a returned “active_flag” means that there is no match
	// information/stats for the corresponding match.  Usually due to a
	// match being in-progress, though there could be other reasons.
	//
	// NOTE - To avoid HTTP timeouts in the GetMatchIdsByQueue() method, you can
	// now specify a 10-minute window within the specified {hour} field to
	// lessen the size of data returned by appending a “,mm” value to the
	// end of {hour}. For example, to get the match Ids for the first 10
	// minutes of hour 3, you would specify {hour} as “3,00”.  This would
	// only return the Ids between the time 3:00 to 3:09. Rules below: Only
	// valid values for mm are “00”, “10”, “20”, “30”, “40”, “50” To get the
	// entire third hour worth of Match Ids, call GetMatchIdsByQueue() 6
	// times, specifying the following values for {hour}: “3,00”, “3,10”,
	// “3,20”, “3,30”, “3,40”, “3,50”. The standard, full hour format of
	// {hour} = “hh” is still supported.
	std::vector<match_id> getmatchidsbyqueue(queue_t queue,
			date::year_month_day date, int hour = -1, int minutes = -1) {
		if (hour != -1) {
			bool hour_ok = hour >= 0 && hour <= 23;
			assert(hour_ok && "hour must be between 0 and 23");
		} else {
			assert(minutes == -1
					&& "when requesting a full day, minutes must be -1 "
					   "(default value)");
		}

		if (minutes != -1) {
			bool minutes_ok = minutes == 0 || minutes == 10 || minutes == 20
					|| minutes == 30 || minutes == 40 || minutes == 50;
			assert(minutes_ok && "minutes must be 0, 10, 20, 30, 40 or 50");
		}

		const wchar_t* date_format = L"%Y%m%d";
		std::wstring date_s = date::format(date_format, date);

		auto get_minute = [&](int hour, int minute) {
			std::wstring m = std::to_wstring(minute);
			if (minute == 0) {
				m = L"00";
			}
			std::wstring hm = std::to_wstring(hour) + L"," + m;

			std::vector<match_id> ret = nlohmann::json::parse(session_call(
					L"getmatchidsbyqueue",
					std::to_wstring(static_cast<int>(queue)), date_s, hm));
			return ret;
		};

		auto get_hour = [&](int hour) {
			std::vector<match_id> ret{};
			for (int i = 0; i < 60; i += 10) {
				std::vector<match_id> v = get_minute(hour, i);
				ret.insert(ret.end(), std::make_move_iterator(v.begin()),
						std::make_move_iterator(v.end()));
			}
			return ret;
		};

		std::vector<match_id> ret{};
		if (hour == -1) {
			for (int i = 0; i < 24; ++i) {
				std::vector<match_id> v = get_hour(i);
				ret.insert(ret.end(), std::make_move_iterator(v.begin()),
						std::make_move_iterator(v.end()));
			}
		} else {
			if (minutes == -1) {
				std::vector<match_id> v = get_hour(hour);
				ret.insert(ret.end(), std::make_move_iterator(v.begin()),
						std::make_move_iterator(v.end()));
			} else {
				std::vector<match_id> v = get_minute(hour, minutes);
				ret.insert(ret.end(), std::make_move_iterator(v.begin()),
						std::make_move_iterator(v.end()));
			}
		}
		return ret;
	}

	// /getleagueleaderboard[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{queue}/{tier}/{season}
	// Returns the top players for a particular league (as indicated by the
	// queue/tier/season parameters).

	// /getleagueseasons[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{queue}
	// Provides a list of seasons (including the single active season) for a
	// match queue.

	// /getmatchhistory[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{player}
	// Gets recent matches and high level match statistics for a particular
	// player.
	auto getmatchhistory(const std::string& player) {
		if constexpr (EndPointFmt == game_e::paladins_pc
				|| EndPointFmt == game_e::paladins_ps4
				|| EndPointFmt == game_e::paladins_xbox) {
			std::vector<match_history_pal> ret = nlohmann::json::parse(
					session_call(L"getmatchhistory", to_wstring(player)));
			return ret;
		} else {
			std::vector<match_history_smi> ret = nlohmann::json::parse(
					session_call(L"getmatchhistory", to_wstring(player)));
			return ret;
		}
	}

	// /getmotd[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}
	// Returns information about the 20 most recent Match-of-the-Days.
	// std::string getmotd() {
	//	return session_call(L"getmotd");
	//}

	// /getplayeridinfoforxboxandswitch[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{playerName}
	// Meaningful only for the Paladins Xbox API.  Paladins Xbox data and
	// Paladins Switch data is stored in the same DB.  Therefore a Paladins
	// Gamer Tag value could be the same as a Paladins Switch Gamer Tag
	// value. Additionally, there could be multiple identical Paladins
	// Switch Gamer Tag values.  The purpose of this method is to return all
	// Player ID data associated with the playerName (gamer tag) parameter.
	// The expectation is that the unique player_id returned could then be
	// used in subsequent method calls.  [PaladinsAPI only]

	// /getplayer[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{player}
	// Returns league and other high level data for a particular player.

	// /getplayerloadouts[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/playerId}/{languageCode}
	// Returns deck loadouts per Champion. [PaladinsAPI only]

	// /getplayerstatus[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{player}
	// Returns player status as follows:

	// 0 - Offline
	// 1 - In Lobby  (basically anywhere except god selection or in game)
	// 2 - god Selection (player has accepted match and is selecting god
	// before start of game)
	//       	3 - In Game (match has started)
	//       	4 - Online (player is logged in, but may be blocking
	//       broadcast of player state)
	// 	5 - Unknown (player not found)

	// /getqueuestats[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{player}/{queue}
	// Returns match summary statistics for a (player, queue) combination
	// grouped by gods played.

	// /getteamdetails[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{clanid}
	// Lists the number of players and other high level details for a
	// particular clan.

	// /getteammatchhistory[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{clanid}
	// Gets recent matches and high level match statistics for a particular
	// clan/team. *DEPRECATED* - As of 2.14 Patch, /getteammatchhistory is
	// no longer supported and will return a NULL dataset.

	// /getteamplayers[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{clanid}
	// Lists the players for a particular clan.

	// /gettopmatches[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}
	// Lists the 50 most watched / most recent recorded matches.

	// /searchteams[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{searchTeam}
	// Returns high level information for Clan names containing the
	// “searchTeam” string.  [SmiteAPI only]

	// /getplayerachievements[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{playerId}
	// Returns select achievement totals (Double kills, Tower Kills, First
	// Bloods, etc) for the specified playerId.

	// /getpatchinfo[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}
	// Function returns information about current deployed patch. Currently,
	// this information only includes patch version.

	std::wstring wdev_id() const {
		return to_wstring(dev_id);
	}

	std::wstring wauth_key() const {
		return to_wstring(auth_key);
	}

	std::wstring wsession_id() const {
		return to_wstring(sesh_info.session_id);
	}

	void save_session_info(const session_info& si) const {
		std::ofstream ofs{ ".cache", std::ios::binary };
		if (!ofs.is_open())
			return;

		size_t size = si.ret_msg.size();
		ofs.write(reinterpret_cast<const char*>(&size), sizeof(size));
		ofs.write(si.ret_msg.c_str(), si.ret_msg.size());
		size = si.session_id.size();
		ofs.write(reinterpret_cast<const char*>(&size), sizeof(size));
		ofs.write(si.session_id.c_str(), si.session_id.size());
		ofs.write(reinterpret_cast<const char*>(&si.timestamp),
				sizeof(si.timestamp));
	}

	session_info load_session_info() const {
		session_info ret{};
		std::ifstream ifs{ ".cache", std::ios::binary };
		if (!ifs.is_open())
			return ret;

		size_t size = 0;
		ifs.read(reinterpret_cast<char*>(&size), sizeof(size));
		ret.ret_msg = std::string(size, '\0');
		ifs.read(ret.ret_msg.data(), size);
		ifs.read(reinterpret_cast<char*>(&size), sizeof(size));
		ret.session_id = std::string(size, '\0');
		ifs.read(ret.session_id.data(), size);
		ifs.read(
				reinterpret_cast<char*>(&ret.timestamp), sizeof(ret.timestamp));
		return ret;
	}

	std::string dev_id{ "" };
	std::string auth_key{ "" };
	session_info sesh_info;

private:
	void reconnect_if_needed() {
		using namespace std::chrono_literals;
		date::sys_seconds time = std::chrono::floor<std::chrono::seconds>(
				std::chrono::system_clock::now());
		if (time - sesh_info.timestamp >= 14min) {
			createsession();
			printf("session expired, reconnected\n\n");
		}
	}

	web::http::client::http_client _http_client;
	bool _cache_session_to_disk;
};
} // namespace rez
