#pragma once
#include "hirez/objects.hpp"
#include "hirez/objects_json.hpp"
#include "hirez/util.hpp"

#include <algorithm>
#include <array>
#include <chrono>
#include <cpprest/http_client.h>
#include <cpprest/uri.h>
#include <date/date.h>
#include <string>
#include <type_traits>
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
};

template <game_e EndPointFmt = game_e::paladins_pc>
struct session {
	const wchar_t* response = L"json";
	const wchar_t* game_url
			= detail::game_uris[static_cast<size_t>(EndPointFmt)].data();

	template <class DevId, class AuthKey>
	session(DevId&& _dev_id, AuthKey&& _auth_key)
			: dev_id(std::forward<DevId>(_dev_id))
			, auth_key(std::forward<AuthKey>(_auth_key))
			, _http_client(game_url) {
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
								L"Calling end-point : %s\n"
								L"Response :\n%s\n",
								resp.status_code(), builder.to_string().c_str(),
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
	session_response createsession() {
		session_info = nlohmann::json::parse(session_call(L"createsession"));
		return session_info;
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
		if constexpr (EndPointFmt == game_e::paladins_pc
				|| EndPointFmt == game_e::paladins_ps4
				|| EndPointFmt == game_e::paladins_xbox) {
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
		static_assert(EndPointFmt == game_e::smite_pc
						|| EndPointFmt == game_e::smite_ps4
						|| EndPointFmt == game_e::smite_xbox,
				"getgodranks only works on Smite end-points");
		return nlohmann::json::parse(
				session_call(L"getgodranks", to_wstring(player)));
	}

	// /getchampionranks[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{player}
	// Returns the Rank and Worshippers value for each Champion a player has
	// played. [PaladinsAPI only]
	std::vector<champion_rank> getchampionranks(const std::string& player) {
		static_assert(EndPointFmt == game_e::paladins_pc
						|| EndPointFmt == game_e::paladins_ps4
						|| EndPointFmt == game_e::paladins_xbox,
				"getchampionranks only works on Paladins end-points");
		return nlohmann::json::parse(
				session_call(L"getchampionranks", to_wstring(player)));
	}

	// /getgods[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{languageCode}
	// Returns all Gods and their various attributes. [SmiteAPI only]
	std::vector<god> getgods(language_e language) {
		static_assert(EndPointFmt == game_e::smite_pc
						|| EndPointFmt == game_e::smite_ps4
						|| EndPointFmt == game_e::smite_xbox,
				"getgods only works on Smite end-points");
		return nlohmann::json::parse(session_call(
				L"getgods", std::to_wstring(static_cast<int>(language))));
	}

	// /getchampions[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{languageCode}
	// Returns all Champions and their various attributes. [PaladinsAPI
	// only]
	std::vector<champion> getchampions(language_e language) {
		static_assert(EndPointFmt == game_e::paladins_pc
						|| EndPointFmt == game_e::paladins_ps4
						|| EndPointFmt == game_e::paladins_xbox,
				"getchampions only works on Paladins end-points");
		return nlohmann::json::parse(session_call(
				L"getchampions", std::to_wstring(static_cast<int>(language))));
	}

	// /getgodleaderboard[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{godId}/{queue}
	// Returns the current season’s leaderboard for a god/queue
	// combination. [SmiteAPI only; queues 440, 450, 451 only]
	// template <int Queue = 440>
	// std::string getgodleaderboard(int god_id) {
	//	static_assert(EndPointFmt == game_e::smite_pc
	//					|| EndPointFmt == game_e::smite_ps4
	//					|| EndPointFmt == game_e::smite_xbox,
	//			"getgodleaderboard only works on Smite end-points");
	//	static_assert(Queue == 440 || Queue == 450 || Queue == 451,
	//			"getgodleaderboard queue must be 440, 450 or 451");
	//	return nlohmann::json::parse(
	//			session_call(L"getgodleaderboard", std::to_wstring(god_id),
	//					std::to_wstring(Queue)))
	//			.dump(4);
	//}

	// /getgodskins[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{godId}/{languageCode}
	// Returns all available skins for a particular God.

	// /getchampionskins[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{godId}/{languageCode}
	// Returns all available skins for a particular
	// Champion. [PaladinsAPI only]

	// /getgodrecommendeditems[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{godid}/{languageCode}
	// Returns the Recommended Items for a
	// particular God.  [SmiteAPI only]

	// /getchampionecommendeditems[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{godid}/{languageCode}
	// Returns the Recommended Items for
	// a particular Champion.
	// [PaladinsAPI only; Osbsolete - no
	// data returned]

	// /getitems[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{languagecode}
	// Returns all Items and
	// their various attributes.

	// /getmatchdetails[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{match_id}
	// Returns the
	// statistics for a
	// particular
	// completed match.

	// /getmatchdetailsbatch[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{match_id,match_id,match_id,...match_id}
	// Returns
	// the
	// statistics
	// for a
	// particular
	// set of
	// completed
	// matches.
	// NOTE:
	// There is
	// a byte
	// imit to
	// the
	// amount of
	// data
	// returned;
	// please
	// limit the
	// CSV
	// parameter
	// to 5 to
	// 10
	// matches
	// because
	// of this
	// and for
	// Hi-Rez DB
	// Performance
	// reasons.

	// /getmatchplayerdetails[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{match_id}
	// Returns player information for a live match.

	// /getmatchidsbyqueue[ResponseFormat]/{developerId}/{signature}/{session}/{timestamp}/{queue}/
	// {date}/{hour}
	// Lists all Match IDs for a particular Match Queue; useful for API
	// developers interested in constructing data by Queue.  To limit the
	// data returned, an {hour} parameter was added (valid values: 0 - 23).
	// An {hour} parameter of -1 represents the entire day, but be warned
	// that this may be more data than we can return for certain queues.
	// Also, a returned “active_flag” means that there is no match
	// information/stats for the corresponding match.  Usually due to a
	// match being in-progress, though there could be other reasons. NOTE -
	// To avoid HTTP timeouts in the GetMatchIdsByQueue() method, you can
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
		return to_wstring(session_info.session_id);
	}

	std::string dev_id{ "" };
	std::string auth_key{ "" };
	session_response session_info;

private:
	web::http::client::http_client _http_client;
};
} // namespace rez
