#pragma once
#include "hirez/util.hpp"

#include <nlohmann/json.hpp>
#include <string>
#include <type_traits>

#define REZ_TO_J(obj, x) \
	{ #x, obj.x }

#define REZ_FROM_J(obj, x, j) detail::get_v(j, #x, obj.x)

namespace rez {
namespace detail {
template <class T>
inline void get_v(const nlohmann::json& j, const char* key, T& val) {
	if constexpr (std::is_same_v<std::string, std::decay_t<T>>) {
		if (j.at(key).is_null()) {
			val = "";
			return;
		}
		val = j.value(key, "");
	} else if (std::is_same_v<int, std::decay_t<T>>) {
		if (j.at(key).is_null()) {
			val = 0;
			return;
		}
		val = j.value(key, 0);
	}
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
	REZ_FROM_J(obj, ret_msg, j);
	REZ_FROM_J(obj, session_id, j);
	REZ_FROM_J(obj, timestamp, j);
}

struct server_status {
	std::string entry_datetime{ "" };
	std::string ret_msg{ "" };
	std::string status{ "" };
	std::string version{ "" };
};
void to_json(nlohmann::json& j, const server_status& obj) {
	j = {
		REZ_TO_J(obj, entry_datetime),
		REZ_TO_J(obj, ret_msg),
		REZ_TO_J(obj, status),
		REZ_TO_J(obj, version),
	};
}
void from_json(const nlohmann::json& j, server_status& obj) {
	REZ_FROM_J(obj, entry_datetime, j);
	REZ_FROM_J(obj, ret_msg, j);
	REZ_FROM_J(obj, status, j);
	REZ_FROM_J(obj, version, j);
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
	j = {
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
	REZ_FROM_J(obj, Active_Sessions, j);
	REZ_FROM_J(obj, Concurrent_Sessions, j);
	REZ_FROM_J(obj, Request_Limit_Daily, j);
	REZ_FROM_J(obj, Session_Cap, j);
	REZ_FROM_J(obj, Session_Time_Limit, j);
	REZ_FROM_J(obj, Total_Requests_Today, j);
	REZ_FROM_J(obj, Total_Sessions_Today, j);
	REZ_FROM_J(obj, ret_msg, j);
}

struct match_history {
	int ActiveId1{ 0 };
	int ActiveId2{ 0 };
	int ActiveId3{ 0 };
	int ActiveId4{ 0 };
	int ActiveLevel1{ 0 };
	int ActiveLevel2{ 0 };
	int ActiveLevel3{ 0 };
	int ActiveLevel4{ 0 };
	std::string Active_1{ "" };
	std::string Active_2{ "" };
	std::string Active_3{ "" };
	std::string Active_4{ "" };
	int Assists{ 0 };
	std::string Champion{ "" };
	int ChampionId{ 0 };
	int Creeps{ 0 };
	int Damage{ 0 };
	int Damage_Bot{ 0 };
	int Damage_Done_In_Hand{ 0 };
	int Damage_Mitigated{ 0 };
	int Damage_Structure{ 0 };
	int Damage_Taken{ 0 };
	int Damage_Taken_Magical{ 0 };
	int Damage_Taken_Physical{ 0 };
	int Deaths{ 0 };
	int Distance_Traveled{ 0 };
	int Gold{ 0 };
	int Healing{ 0 };
	int Healing_Bot{ 0 };
	int Healing_Player_Self{ 0 };
	int ItemId1{ 0 };
	int ItemId2{ 0 };
	int ItemId3{ 0 };
	int ItemId4{ 0 };
	int ItemId5{ 0 };
	int ItemId6{ 0 };
	int ItemLevel1{ 0 };
	int ItemLevel2{ 0 };
	int ItemLevel3{ 0 };
	int ItemLevel4{ 0 };
	int ItemLevel5{ 0 };
	int ItemLevel6{ 0 };
	std::string Item_1{ "" };
	std::string Item_2{ "" };
	std::string Item_3{ "" };
	std::string Item_4{ "" };
	std::string Item_5{ "" };
	std::string Item_6{ "" };
	int Killing_Spree{ 0 };
	int Kills{ 0 };
	int Level{ 0 };
	std::string Map_Game{ "" };
	int Match{ 0 };
	int Match_Queue_Id{ 0 };
	std::string Match_Time{ "" };
	int Minutes{ 0 };
	int Multi_kill_Max{ 0 };
	int Objective_Assists{ 0 };
	std::string Queue{ "" };
	std::string Region{ "" };
	std::string Skin{ "" };
	int SkinId{ 0 };
	int Surrendered{ 0 };
	int TaskForce{ 0 };
	int Team1Score{ 0 };
	int Team2Score{ 0 };
	int Time_In_Match_Seconds{ 0 };
	int Wards_Placed{ 0 };
	std::string Win_Status{ "" };
	int Winning_TaskForce{ 0 };
	std::string playerName{ "" };
	std::string ret_msg{ "" };
};
void to_json(nlohmann::json& j, const match_history& obj) {
	j = {
		REZ_TO_J(obj, ActiveId1),
		REZ_TO_J(obj, ActiveId2),
		REZ_TO_J(obj, ActiveId3),
		REZ_TO_J(obj, ActiveId4),
		REZ_TO_J(obj, ActiveLevel1),
		REZ_TO_J(obj, ActiveLevel2),
		REZ_TO_J(obj, ActiveLevel3),
		REZ_TO_J(obj, ActiveLevel4),
		REZ_TO_J(obj, Active_1),
		REZ_TO_J(obj, Active_2),
		REZ_TO_J(obj, Active_3),
		REZ_TO_J(obj, Active_4),
		REZ_TO_J(obj, Assists),
		REZ_TO_J(obj, Champion),
		REZ_TO_J(obj, ChampionId),
		REZ_TO_J(obj, Creeps),
		REZ_TO_J(obj, Damage),
		REZ_TO_J(obj, Damage_Bot),
		REZ_TO_J(obj, Damage_Done_In_Hand),
		REZ_TO_J(obj, Damage_Mitigated),
		REZ_TO_J(obj, Damage_Structure),
		REZ_TO_J(obj, Damage_Taken),
		REZ_TO_J(obj, Damage_Taken_Magical),
		REZ_TO_J(obj, Damage_Taken_Physical),
		REZ_TO_J(obj, Deaths),
		REZ_TO_J(obj, Distance_Traveled),
		REZ_TO_J(obj, Gold),
		REZ_TO_J(obj, Healing),
		REZ_TO_J(obj, Healing_Bot),
		REZ_TO_J(obj, Healing_Player_Self),
		REZ_TO_J(obj, ItemId1),
		REZ_TO_J(obj, ItemId2),
		REZ_TO_J(obj, ItemId3),
		REZ_TO_J(obj, ItemId4),
		REZ_TO_J(obj, ItemId5),
		REZ_TO_J(obj, ItemId6),
		REZ_TO_J(obj, ItemLevel1),
		REZ_TO_J(obj, ItemLevel2),
		REZ_TO_J(obj, ItemLevel3),
		REZ_TO_J(obj, ItemLevel4),
		REZ_TO_J(obj, ItemLevel5),
		REZ_TO_J(obj, ItemLevel6),
		REZ_TO_J(obj, Item_1),
		REZ_TO_J(obj, Item_2),
		REZ_TO_J(obj, Item_3),
		REZ_TO_J(obj, Item_4),
		REZ_TO_J(obj, Item_5),
		REZ_TO_J(obj, Item_6),
		REZ_TO_J(obj, Killing_Spree),
		REZ_TO_J(obj, Kills),
		REZ_TO_J(obj, Level),
		REZ_TO_J(obj, Map_Game),
		REZ_TO_J(obj, Match),
		REZ_TO_J(obj, Match_Queue_Id),
		REZ_TO_J(obj, Match_Time),
		REZ_TO_J(obj, Minutes),
		REZ_TO_J(obj, Multi_kill_Max),
		REZ_TO_J(obj, Objective_Assists),
		REZ_TO_J(obj, Queue),
		REZ_TO_J(obj, Region),
		REZ_TO_J(obj, Skin),
		REZ_TO_J(obj, SkinId),
		REZ_TO_J(obj, Surrendered),
		REZ_TO_J(obj, TaskForce),
		REZ_TO_J(obj, Team1Score),
		REZ_TO_J(obj, Team2Score),
		REZ_TO_J(obj, Time_In_Match_Seconds),
		REZ_TO_J(obj, Wards_Placed),
		REZ_TO_J(obj, Win_Status),
		REZ_TO_J(obj, Winning_TaskForce),
		REZ_TO_J(obj, playerName),
		REZ_TO_J(obj, ret_msg),
	};
}
void from_json(const nlohmann::json& j, match_history& obj) {
	REZ_FROM_J(obj, ActiveId1, j);
	REZ_FROM_J(obj, ActiveId2, j);
	REZ_FROM_J(obj, ActiveId3, j);
	REZ_FROM_J(obj, ActiveId4, j);
	REZ_FROM_J(obj, ActiveLevel1, j);
	REZ_FROM_J(obj, ActiveLevel2, j);
	REZ_FROM_J(obj, ActiveLevel3, j);
	REZ_FROM_J(obj, ActiveLevel4, j);
	REZ_FROM_J(obj, Active_1, j);
	REZ_FROM_J(obj, Active_2, j);
	REZ_FROM_J(obj, Active_3, j);
	REZ_FROM_J(obj, Active_4, j);
	REZ_FROM_J(obj, Assists, j);
	REZ_FROM_J(obj, Champion, j);
	REZ_FROM_J(obj, ChampionId, j);
	REZ_FROM_J(obj, Creeps, j);
	REZ_FROM_J(obj, Damage, j);
	REZ_FROM_J(obj, Damage_Bot, j);
	REZ_FROM_J(obj, Damage_Done_In_Hand, j);
	REZ_FROM_J(obj, Damage_Mitigated, j);
	REZ_FROM_J(obj, Damage_Structure, j);
	REZ_FROM_J(obj, Damage_Taken, j);
	REZ_FROM_J(obj, Damage_Taken_Magical, j);
	REZ_FROM_J(obj, Damage_Taken_Physical, j);
	REZ_FROM_J(obj, Deaths, j);
	REZ_FROM_J(obj, Distance_Traveled, j);
	REZ_FROM_J(obj, Gold, j);
	REZ_FROM_J(obj, Healing, j);
	REZ_FROM_J(obj, Healing_Bot, j);
	REZ_FROM_J(obj, Healing_Player_Self, j);
	REZ_FROM_J(obj, ItemId1, j);
	REZ_FROM_J(obj, ItemId2, j);
	REZ_FROM_J(obj, ItemId3, j);
	REZ_FROM_J(obj, ItemId4, j);
	REZ_FROM_J(obj, ItemId5, j);
	REZ_FROM_J(obj, ItemId6, j);
	REZ_FROM_J(obj, ItemLevel1, j);
	REZ_FROM_J(obj, ItemLevel2, j);
	REZ_FROM_J(obj, ItemLevel3, j);
	REZ_FROM_J(obj, ItemLevel4, j);
	REZ_FROM_J(obj, ItemLevel5, j);
	REZ_FROM_J(obj, ItemLevel6, j);
	REZ_FROM_J(obj, Item_1, j);
	REZ_FROM_J(obj, Item_2, j);
	REZ_FROM_J(obj, Item_3, j);
	REZ_FROM_J(obj, Item_4, j);
	REZ_FROM_J(obj, Item_5, j);
	REZ_FROM_J(obj, Item_6, j);
	REZ_FROM_J(obj, Killing_Spree, j);
	REZ_FROM_J(obj, Kills, j);
	REZ_FROM_J(obj, Level, j);
	REZ_FROM_J(obj, Map_Game, j);
	REZ_FROM_J(obj, Match, j);
	REZ_FROM_J(obj, Match_Queue_Id, j);
	REZ_FROM_J(obj, Match_Time, j);
	REZ_FROM_J(obj, Minutes, j);
	REZ_FROM_J(obj, Multi_kill_Max, j);
	REZ_FROM_J(obj, Objective_Assists, j);
	REZ_FROM_J(obj, Queue, j);
	REZ_FROM_J(obj, Region, j);
	REZ_FROM_J(obj, Skin, j);
	REZ_FROM_J(obj, SkinId, j);
	REZ_FROM_J(obj, Surrendered, j);
	REZ_FROM_J(obj, TaskForce, j);
	REZ_FROM_J(obj, Team1Score, j);
	REZ_FROM_J(obj, Team2Score, j);
	REZ_FROM_J(obj, Time_In_Match_Seconds, j);
	REZ_FROM_J(obj, Wards_Placed, j);
	REZ_FROM_J(obj, Win_Status, j);
	REZ_FROM_J(obj, Winning_TaskForce, j);
	REZ_FROM_J(obj, playerName, j);
	REZ_FROM_J(obj, ret_msg, j);
}

struct demo_details {
	int BanId1{ 0 };
	int BanId2{ 0 };
	int BanId3{ 0 };
	int BanId4{ 0 };
	std::string Entry_Datetime{ "" };
	int Match{ 0 };
	int Match_Time{ 0 };
	int Offline_Spectators{ 0 };
	std::string Queue{ "" };
	int Realtime_Spectators{ 0 };
	std::string Recording_Ended{ "" };
	std::string Recording_Started{ "" };
	int Team1_AvgLevel{ 0 };
	int Team1_Gold{ 0 };
	int Team1_Kills{ 0 };
	int Team1_Score{ 0 };
	int Team2_AvgLevel{ 0 };
	int Team2_Gold{ 0 };
	int Team2_Kills{ 0 };
	int Team2_Score{ 0 };
	int Winning_Team{ 0 };
	std::string ret_msg{ "" };
};
void to_json(nlohmann::json& j, const demo_details& obj) {
	j = {
		REZ_TO_J(obj, BanId1),
		REZ_TO_J(obj, BanId2),
		REZ_TO_J(obj, BanId3),
		REZ_TO_J(obj, BanId4),
		REZ_TO_J(obj, Entry_Datetime),
		REZ_TO_J(obj, Match),
		REZ_TO_J(obj, Match_Time),
		REZ_TO_J(obj, Offline_Spectators),
		REZ_TO_J(obj, Queue),
		REZ_TO_J(obj, Realtime_Spectators),
		REZ_TO_J(obj, Recording_Ended),
		REZ_TO_J(obj, Recording_Started),
		REZ_TO_J(obj, Team1_AvgLevel),
		REZ_TO_J(obj, Team1_Gold),
		REZ_TO_J(obj, Team1_Kills),
		REZ_TO_J(obj, Team1_Score),
		REZ_TO_J(obj, Team2_AvgLevel),
		REZ_TO_J(obj, Team2_Gold),
		REZ_TO_J(obj, Team2_Kills),
		REZ_TO_J(obj, Team2_Score),
		REZ_TO_J(obj, Winning_Team),
		REZ_TO_J(obj, ret_msg),
	};
}
void from_json(const nlohmann::json& j, demo_details& obj) {
	REZ_FROM_J(obj, BanId1, j);
	REZ_FROM_J(obj, BanId2, j);
	REZ_FROM_J(obj, BanId3, j);
	REZ_FROM_J(obj, BanId4, j);
	REZ_FROM_J(obj, Entry_Datetime, j);
	REZ_FROM_J(obj, Match, j);
	REZ_FROM_J(obj, Match_Time, j);
	REZ_FROM_J(obj, Offline_Spectators, j);
	REZ_FROM_J(obj, Queue, j);
	REZ_FROM_J(obj, Realtime_Spectators, j);
	REZ_FROM_J(obj, Recording_Ended, j);
	REZ_FROM_J(obj, Recording_Started, j);
	REZ_FROM_J(obj, Team1_AvgLevel, j);
	REZ_FROM_J(obj, Team1_Gold, j);
	REZ_FROM_J(obj, Team1_Kills, j);
	REZ_FROM_J(obj, Team1_Score, j);
	REZ_FROM_J(obj, Team2_AvgLevel, j);
	REZ_FROM_J(obj, Team2_Gold, j);
	REZ_FROM_J(obj, Team2_Kills, j);
	REZ_FROM_J(obj, Team2_Score, j);
	REZ_FROM_J(obj, Winning_Team, j);
	REZ_FROM_J(obj, ret_msg, j);
}

struct esports_pro_league_details {
	int away_team_clan_id{ 0 };
	std::string away_team_name{ "" };
	std::string away_team_tagname{ "" };
	int home_team_clan_id{ 0 };
	std::string home_team_name{ "" };
	std::string home_team_tagname{ "" };
	std::string map_instance_id{ "" };
	std::string match_date{ "" };
	std::string match_number{ "" };
	std::string match_status{ "" };
	std::string matchup_id{ "" };
	std::string region{ "" };
	std::string ret_msg{ "" };
	std::string tournament_name{ "" };
	int winning_team_clan_id{ 0 };
};
void to_json(nlohmann::json& j, const esports_pro_league_details& obj) {
	j = {
		REZ_TO_J(obj, away_team_clan_id),
		REZ_TO_J(obj, away_team_name),
		REZ_TO_J(obj, away_team_tagname),
		REZ_TO_J(obj, home_team_clan_id),
		REZ_TO_J(obj, home_team_name),
		REZ_TO_J(obj, home_team_tagname),
		REZ_TO_J(obj, map_instance_id),
		REZ_TO_J(obj, match_date),
		REZ_TO_J(obj, match_number),
		REZ_TO_J(obj, match_status),
		REZ_TO_J(obj, matchup_id),
		REZ_TO_J(obj, region),
		REZ_TO_J(obj, ret_msg),
		REZ_TO_J(obj, tournament_name),
		REZ_TO_J(obj, winning_team_clan_id),
	};
}
void from_json(const nlohmann::json& j, esports_pro_league_details& obj) {
	REZ_FROM_J(obj, away_team_clan_id, j);
	REZ_FROM_J(obj, away_team_name, j);
	REZ_FROM_J(obj, away_team_tagname, j);
	REZ_FROM_J(obj, home_team_clan_id, j);
	REZ_FROM_J(obj, home_team_name, j);
	REZ_FROM_J(obj, home_team_tagname, j);
	REZ_FROM_J(obj, map_instance_id, j);
	REZ_FROM_J(obj, match_date, j);
	REZ_FROM_J(obj, match_number, j);
	REZ_FROM_J(obj, match_status, j);
	REZ_FROM_J(obj, matchup_id, j);
	REZ_FROM_J(obj, region, j);
	REZ_FROM_J(obj, ret_msg, j);
	REZ_FROM_J(obj, tournament_name, j);
	REZ_FROM_J(obj, winning_team_clan_id, j);
}
} // namespace rez
