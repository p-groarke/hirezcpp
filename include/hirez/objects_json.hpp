#pragma once
#include "hirez/objects.hpp"
#include "hirez/util.hpp"

#include <nlohmann/json.hpp>

namespace rez {
void to_json(nlohmann::json& j, const nothing&) {
	j = {};
}
void from_json(const nlohmann::json&, nothing& obj) {
	obj = {};
}

void to_json(nlohmann::json& j, const session_info& obj) {
	j = {
		REZ_TO_J(obj, ret_msg),
		REZ_TO_J(obj, session_id),
		REZ_TO_J(obj, timestamp),
	};
}
void from_json(const nlohmann::json& j, session_info& obj) {
	REZ_FROM_J(obj, ret_msg, j);
	REZ_FROM_J(obj, session_id, j);
	REZ_FROM_J(obj, timestamp, j);
}

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

void to_json(nlohmann::json& j, const match_history_pal& obj) {
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
void from_json(const nlohmann::json& j, match_history_pal& obj) {
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

void to_json(nlohmann::json& j, const match_history_smi& obj) {
	j = {
		REZ_TO_J(obj, ActiveId1),
		REZ_TO_J(obj, ActiveId2),
		REZ_TO_J(obj, Active_1),
		REZ_TO_J(obj, Active_2),
		REZ_TO_J(obj, Active_3),
		REZ_TO_J(obj, Assists),
		REZ_TO_J(obj, Ban1),
		REZ_TO_J(obj, Ban10),
		REZ_TO_J(obj, Ban10Id),
		REZ_TO_J(obj, Ban1Id),
		REZ_TO_J(obj, Ban2),
		REZ_TO_J(obj, Ban2Id),
		REZ_TO_J(obj, Ban3),
		REZ_TO_J(obj, Ban3Id),
		REZ_TO_J(obj, Ban4),
		REZ_TO_J(obj, Ban4Id),
		REZ_TO_J(obj, Ban5),
		REZ_TO_J(obj, Ban5Id),
		REZ_TO_J(obj, Ban6),
		REZ_TO_J(obj, Ban6Id),
		REZ_TO_J(obj, Ban7),
		REZ_TO_J(obj, Ban7Id),
		REZ_TO_J(obj, Ban8),
		REZ_TO_J(obj, Ban8Id),
		REZ_TO_J(obj, Ban9),
		REZ_TO_J(obj, Ban9Id),
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
		REZ_TO_J(obj, First_Ban_Side),
		REZ_TO_J(obj, God),
		REZ_TO_J(obj, GodId),
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
void from_json(const nlohmann::json& j, match_history_smi& obj) {
	REZ_FROM_J(obj, ActiveId1, j);
	REZ_FROM_J(obj, ActiveId2, j);
	REZ_FROM_J(obj, Active_1, j);
	REZ_FROM_J(obj, Active_2, j);
	REZ_FROM_J(obj, Active_3, j);
	REZ_FROM_J(obj, Assists, j);
	REZ_FROM_J(obj, Ban1, j);
	REZ_FROM_J(obj, Ban10, j);
	REZ_FROM_J(obj, Ban10Id, j);
	REZ_FROM_J(obj, Ban1Id, j);
	REZ_FROM_J(obj, Ban2, j);
	REZ_FROM_J(obj, Ban2Id, j);
	REZ_FROM_J(obj, Ban3, j);
	REZ_FROM_J(obj, Ban3Id, j);
	REZ_FROM_J(obj, Ban4, j);
	REZ_FROM_J(obj, Ban4Id, j);
	REZ_FROM_J(obj, Ban5, j);
	REZ_FROM_J(obj, Ban5Id, j);
	REZ_FROM_J(obj, Ban6, j);
	REZ_FROM_J(obj, Ban6Id, j);
	REZ_FROM_J(obj, Ban7, j);
	REZ_FROM_J(obj, Ban7Id, j);
	REZ_FROM_J(obj, Ban8, j);
	REZ_FROM_J(obj, Ban8Id, j);
	REZ_FROM_J(obj, Ban9, j);
	REZ_FROM_J(obj, Ban9Id, j);
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
	REZ_FROM_J(obj, First_Ban_Side, j);
	REZ_FROM_J(obj, God, j);
	REZ_FROM_J(obj, GodId, j);
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

void to_json(nlohmann::json& j, const demo_details_pal& obj) {
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
void from_json(const nlohmann::json& j, demo_details_pal& obj) {
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

void to_json(nlohmann::json& j, const demo_details_smi& obj) {
	j = {
		REZ_TO_J(obj, Ban1),
		REZ_TO_J(obj, Ban2),
		REZ_TO_J(obj, Entry_Datetime),
		REZ_TO_J(obj, Match),
		REZ_TO_J(obj, Match_Time),
		REZ_TO_J(obj, Offline_Spectators),
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
void from_json(const nlohmann::json& j, demo_details_smi& obj) {
	REZ_FROM_J(obj, Ban1, j);
	REZ_FROM_J(obj, Ban2, j);
	REZ_FROM_J(obj, Entry_Datetime, j);
	REZ_FROM_J(obj, Match, j);
	REZ_FROM_J(obj, Match_Time, j);
	REZ_FROM_J(obj, Offline_Spectators, j);
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

void to_json(nlohmann::json& j, const friends& obj) {
	j = {
		REZ_TO_J(obj, account_id),
		REZ_TO_J(obj, name),
		REZ_TO_J(obj, player_id),
		REZ_TO_J(obj, ret_msg),
	};
}
void from_json(const nlohmann::json& j, friends& obj) {
	REZ_FROM_J(obj, account_id, j);
	REZ_FROM_J(obj, name, j);
	REZ_FROM_J(obj, player_id, j);
	REZ_FROM_J(obj, ret_msg, j);
}

void to_json(nlohmann::json& j, const god_rank& obj) {
	j = {
		REZ_TO_J(obj, Assists),
		REZ_TO_J(obj, Deaths),
		REZ_TO_J(obj, Kills),
		REZ_TO_J(obj, Losses),
		REZ_TO_J(obj, MinionKills),
		REZ_TO_J(obj, Rank),
		REZ_TO_J(obj, Wins),
		REZ_TO_J(obj, Worshippers),
		REZ_TO_J(obj, god),
		REZ_TO_J(obj, god_id),
		REZ_TO_J(obj, player_id),
		REZ_TO_J(obj, ret_msg),
	};
}
void from_json(const nlohmann::json& j, god_rank& obj) {
	REZ_FROM_J(obj, Assists, j);
	REZ_FROM_J(obj, Deaths, j);
	REZ_FROM_J(obj, Kills, j);
	REZ_FROM_J(obj, Losses, j);
	REZ_FROM_J(obj, MinionKills, j);
	REZ_FROM_J(obj, Rank, j);
	REZ_FROM_J(obj, Wins, j);
	REZ_FROM_J(obj, Worshippers, j);
	REZ_FROM_J(obj, god, j);
	REZ_FROM_J(obj, god_id, j);
	REZ_FROM_J(obj, player_id, j);
	REZ_FROM_J(obj, ret_msg, j);
}

void to_json(nlohmann::json& j, const champion_rank& obj) {
	j = {
		REZ_TO_J(obj, Assists),
		REZ_TO_J(obj, Deaths),
		REZ_TO_J(obj, Gold),
		REZ_TO_J(obj, Kills),
		REZ_TO_J(obj, LastPlayed),
		REZ_TO_J(obj, Losses),
		REZ_TO_J(obj, MinionKills),
		REZ_TO_J(obj, Minutes),
		REZ_TO_J(obj, Rank),
		REZ_TO_J(obj, Wins),
		REZ_TO_J(obj, Worshippers),
		REZ_TO_J(obj, champion),
		REZ_TO_J(obj, champion_id),
		REZ_TO_J(obj, player_id),
		REZ_TO_J(obj, ret_msg),
	};
}
void from_json(const nlohmann::json& j, champion_rank& obj) {
	REZ_FROM_J(obj, Assists, j);
	REZ_FROM_J(obj, Deaths, j);
	REZ_FROM_J(obj, Gold, j);
	REZ_FROM_J(obj, Kills, j);
	REZ_FROM_J(obj, LastPlayed, j);
	REZ_FROM_J(obj, Losses, j);
	REZ_FROM_J(obj, MinionKills, j);
	REZ_FROM_J(obj, Minutes, j);
	REZ_FROM_J(obj, Rank, j);
	REZ_FROM_J(obj, Wins, j);
	REZ_FROM_J(obj, Worshippers, j);
	REZ_FROM_J(obj, champion, j);
	REZ_FROM_J(obj, champion_id, j);
	REZ_FROM_J(obj, player_id, j);
	REZ_FROM_J(obj, ret_msg, j);
}

void to_json(nlohmann::json& j, const god_menu_item& obj) {
	j = {
		REZ_TO_J(obj, description),
		REZ_TO_J(obj, value),
	};
}
void from_json(const nlohmann::json& j, god_menu_item& obj) {
	REZ_FROM_J(obj, description, j);
	REZ_FROM_J(obj, value, j);
}

void to_json(nlohmann::json& j, const god_rank_item& obj) {
	j = {
		REZ_TO_J(obj, description),
		REZ_TO_J(obj, value),
	};
}
void from_json(const nlohmann::json& j, god_rank_item& obj) {
	REZ_FROM_J(obj, description, j);
	REZ_FROM_J(obj, value, j);
}

void to_json(nlohmann::json& j, const god_item_description& obj) {
	j = {
		REZ_TO_J(obj, cooldown),
		REZ_TO_J(obj, cost),
		REZ_TO_J(obj, description),
		REZ_TO_J(obj, menuitems),
		REZ_TO_J(obj, rankitems),
		REZ_TO_J(obj, secondaryDescription),
	};
}
void from_json(const nlohmann::json& j, god_item_description& obj) {
	REZ_FROM_J(obj, cooldown, j);
	REZ_FROM_J(obj, cost, j);
	REZ_FROM_J(obj, description, j);
	REZ_FROM_J(obj, menuitems, j);
	REZ_FROM_J(obj, rankitems, j);
	REZ_FROM_J(obj, secondaryDescription, j);
}

void to_json(nlohmann::json& j, const god_ability_description& obj) {
	j = {
		REZ_TO_J(obj, itemDescription),
	};
}
void from_json(const nlohmann::json& j, god_ability_description& obj) {
	REZ_FROM_J(obj, itemDescription, j);
}

void to_json(nlohmann::json& j, const god_ability_details& obj) {
	j = {
		REZ_TO_J(obj, Description),
		REZ_TO_J(obj, Id),
		REZ_TO_J(obj, Summary),
		REZ_TO_J(obj, URL),
	};
}
void from_json(const nlohmann::json& j, god_ability_details& obj) {
	REZ_FROM_J(obj, Description, j);
	REZ_FROM_J(obj, Id, j);
	REZ_FROM_J(obj, Summary, j);
	REZ_FROM_J(obj, URL, j);
}

void to_json(nlohmann::json& j, const god& obj) {
	j = {
		REZ_TO_J(obj, Ability1),
		REZ_TO_J(obj, Ability2),
		REZ_TO_J(obj, Ability3),
		REZ_TO_J(obj, Ability4),
		REZ_TO_J(obj, Ability5),
		REZ_TO_J(obj, AbilityId1),
		REZ_TO_J(obj, AbilityId2),
		REZ_TO_J(obj, AbilityId3),
		REZ_TO_J(obj, AbilityId4),
		REZ_TO_J(obj, AbilityId5),
		REZ_TO_J(obj, Ability_1),
		REZ_TO_J(obj, Ability_2),
		REZ_TO_J(obj, Ability_3),
		REZ_TO_J(obj, Ability_4),
		REZ_TO_J(obj, Ability_5),
		REZ_TO_J(obj, AttackSpeed),
		REZ_TO_J(obj, AttackSpeedPerLevel),
		REZ_TO_J(obj, Cons),
		REZ_TO_J(obj, HP5PerLevel),
		REZ_TO_J(obj, Health),
		REZ_TO_J(obj, HealthPerFive),
		REZ_TO_J(obj, HealthPerLevel),
		REZ_TO_J(obj, Lore),
		REZ_TO_J(obj, MP5PerLevel),
		REZ_TO_J(obj, MagicProtection),
		REZ_TO_J(obj, MagicProtectionPerLevel),
		REZ_TO_J(obj, MagicalPower),
		REZ_TO_J(obj, MagicalPowerPerLevel),
		REZ_TO_J(obj, Mana),
		REZ_TO_J(obj, ManaPerFive),
		REZ_TO_J(obj, ManaPerLevel),
		REZ_TO_J(obj, Name),
		REZ_TO_J(obj, OnFreeRotation),
		REZ_TO_J(obj, Pantheon),
		REZ_TO_J(obj, PhysicalPower),
		REZ_TO_J(obj, PhysicalPowerPerLevel),
		REZ_TO_J(obj, PhysicalProtection),
		REZ_TO_J(obj, PhysicalProtectionPerLevel),
		REZ_TO_J(obj, Pros),
		REZ_TO_J(obj, Roles),
		REZ_TO_J(obj, Speed),
		REZ_TO_J(obj, Title),
		REZ_TO_J(obj, Type),
		REZ_TO_J(obj, abilityDescription1),
		REZ_TO_J(obj, abilityDescription2),
		REZ_TO_J(obj, abilityDescription3),
		REZ_TO_J(obj, abilityDescription4),
		REZ_TO_J(obj, abilityDescription5),
		REZ_TO_J(obj, basicAttack),
		REZ_TO_J(obj, godAbility1_URL),
		REZ_TO_J(obj, godAbility2_URL),
		REZ_TO_J(obj, godAbility3_URL),
		REZ_TO_J(obj, godAbility4_URL),
		REZ_TO_J(obj, godAbility5_URL),
		REZ_TO_J(obj, godCard_URL),
		REZ_TO_J(obj, godIcon_URL),
		REZ_TO_J(obj, id),
		REZ_TO_J(obj, latestGod),
		REZ_TO_J(obj, ret_msg),
	};
}
void from_json(const nlohmann::json& j, god& obj) {
	REZ_FROM_J(obj, Ability1, j);
	REZ_FROM_J(obj, Ability2, j);
	REZ_FROM_J(obj, Ability3, j);
	REZ_FROM_J(obj, Ability4, j);
	REZ_FROM_J(obj, Ability5, j);
	REZ_FROM_J(obj, AbilityId1, j);
	REZ_FROM_J(obj, AbilityId2, j);
	REZ_FROM_J(obj, AbilityId3, j);
	REZ_FROM_J(obj, AbilityId4, j);
	REZ_FROM_J(obj, AbilityId5, j);
	REZ_FROM_J(obj, Ability_1, j);
	REZ_FROM_J(obj, Ability_2, j);
	REZ_FROM_J(obj, Ability_3, j);
	REZ_FROM_J(obj, Ability_4, j);
	REZ_FROM_J(obj, Ability_5, j);
	REZ_FROM_J(obj, AttackSpeed, j);
	REZ_FROM_J(obj, AttackSpeedPerLevel, j);
	REZ_FROM_J(obj, Cons, j);
	REZ_FROM_J(obj, HP5PerLevel, j);
	REZ_FROM_J(obj, Health, j);
	REZ_FROM_J(obj, HealthPerFive, j);
	REZ_FROM_J(obj, HealthPerLevel, j);
	REZ_FROM_J(obj, Lore, j);
	REZ_FROM_J(obj, MP5PerLevel, j);
	REZ_FROM_J(obj, MagicProtection, j);
	REZ_FROM_J(obj, MagicProtectionPerLevel, j);
	REZ_FROM_J(obj, MagicalPower, j);
	REZ_FROM_J(obj, MagicalPowerPerLevel, j);
	REZ_FROM_J(obj, Mana, j);
	REZ_FROM_J(obj, ManaPerFive, j);
	REZ_FROM_J(obj, ManaPerLevel, j);
	REZ_FROM_J(obj, Name, j);
	REZ_FROM_J(obj, OnFreeRotation, j);
	REZ_FROM_J(obj, Pantheon, j);
	REZ_FROM_J(obj, PhysicalPower, j);
	REZ_FROM_J(obj, PhysicalPowerPerLevel, j);
	REZ_FROM_J(obj, PhysicalProtection, j);
	REZ_FROM_J(obj, PhysicalProtectionPerLevel, j);
	REZ_FROM_J(obj, Pros, j);
	REZ_FROM_J(obj, Roles, j);
	REZ_FROM_J(obj, Speed, j);
	REZ_FROM_J(obj, Title, j);
	REZ_FROM_J(obj, Type, j);
	REZ_FROM_J(obj, abilityDescription1, j);
	REZ_FROM_J(obj, abilityDescription2, j);
	REZ_FROM_J(obj, abilityDescription3, j);
	REZ_FROM_J(obj, abilityDescription4, j);
	REZ_FROM_J(obj, abilityDescription5, j);
	REZ_FROM_J(obj, basicAttack, j);
	REZ_FROM_J(obj, godAbility1_URL, j);
	REZ_FROM_J(obj, godAbility2_URL, j);
	REZ_FROM_J(obj, godAbility3_URL, j);
	REZ_FROM_J(obj, godAbility4_URL, j);
	REZ_FROM_J(obj, godAbility5_URL, j);
	REZ_FROM_J(obj, godCard_URL, j);
	REZ_FROM_J(obj, godIcon_URL, j);
	REZ_FROM_J(obj, id, j);
	REZ_FROM_J(obj, latestGod, j);
	REZ_FROM_J(obj, ret_msg, j);
}

void to_json(nlohmann::json& j, const champion_ability_details& obj) {
	j = {
		REZ_TO_J(obj, Description),
		REZ_TO_J(obj, Id),
		REZ_TO_J(obj, Summary),
		REZ_TO_J(obj, URL),
	};
}
void from_json(const nlohmann::json& j, champion_ability_details& obj) {
	REZ_FROM_J(obj, Description, j);
	REZ_FROM_J(obj, Id, j);
	REZ_FROM_J(obj, Summary, j);
	REZ_FROM_J(obj, URL, j);
}
void to_json(nlohmann::json& j, const champion& obj) {
	j = {
		REZ_TO_J(obj, Ability1),
		REZ_TO_J(obj, Ability2),
		REZ_TO_J(obj, Ability3),
		REZ_TO_J(obj, Ability4),
		REZ_TO_J(obj, Ability5),
		REZ_TO_J(obj, AbilityId1),
		REZ_TO_J(obj, AbilityId2),
		REZ_TO_J(obj, AbilityId3),
		REZ_TO_J(obj, AbilityId4),
		REZ_TO_J(obj, AbilityId5),
		REZ_TO_J(obj, Ability_1),
		REZ_TO_J(obj, Ability_2),
		REZ_TO_J(obj, Ability_3),
		REZ_TO_J(obj, Ability_4),
		REZ_TO_J(obj, Ability_5),
		REZ_TO_J(obj, ChampionAbility1_URL),
		REZ_TO_J(obj, ChampionAbility2_URL),
		REZ_TO_J(obj, ChampionAbility3_URL),
		REZ_TO_J(obj, ChampionAbility4_URL),
		REZ_TO_J(obj, ChampionAbility5_URL),
		REZ_TO_J(obj, ChampionCard_URL),
		REZ_TO_J(obj, ChampionIcon_URL),
		REZ_TO_J(obj, Cons),
		REZ_TO_J(obj, Health),
		REZ_TO_J(obj, Lore),
		REZ_TO_J(obj, Name),
		REZ_TO_J(obj, OnFreeRotation),
		REZ_TO_J(obj, Pantheon),
		REZ_TO_J(obj, Pros),
		REZ_TO_J(obj, Roles),
		REZ_TO_J(obj, Speed),
		REZ_TO_J(obj, Title),
		REZ_TO_J(obj, Type),
		REZ_TO_J(obj, abilityDescription1),
		REZ_TO_J(obj, abilityDescription2),
		REZ_TO_J(obj, abilityDescription3),
		REZ_TO_J(obj, abilityDescription4),
		REZ_TO_J(obj, abilityDescription5),
		REZ_TO_J(obj, id),
		REZ_TO_J(obj, latestChampion),
		REZ_TO_J(obj, ret_msg),
	};
}
void from_json(const nlohmann::json& j, champion& obj) {
	REZ_FROM_J(obj, Ability1, j);
	REZ_FROM_J(obj, Ability2, j);
	REZ_FROM_J(obj, Ability3, j);
	REZ_FROM_J(obj, Ability4, j);
	REZ_FROM_J(obj, Ability5, j);
	REZ_FROM_J(obj, AbilityId1, j);
	REZ_FROM_J(obj, AbilityId2, j);
	REZ_FROM_J(obj, AbilityId3, j);
	REZ_FROM_J(obj, AbilityId4, j);
	REZ_FROM_J(obj, AbilityId5, j);
	REZ_FROM_J(obj, Ability_1, j);
	REZ_FROM_J(obj, Ability_2, j);
	REZ_FROM_J(obj, Ability_3, j);
	REZ_FROM_J(obj, Ability_4, j);
	REZ_FROM_J(obj, Ability_5, j);
	REZ_FROM_J(obj, ChampionAbility1_URL, j);
	REZ_FROM_J(obj, ChampionAbility2_URL, j);
	REZ_FROM_J(obj, ChampionAbility3_URL, j);
	REZ_FROM_J(obj, ChampionAbility4_URL, j);
	REZ_FROM_J(obj, ChampionAbility5_URL, j);
	REZ_FROM_J(obj, ChampionCard_URL, j);
	REZ_FROM_J(obj, ChampionIcon_URL, j);
	REZ_FROM_J(obj, Cons, j);
	REZ_FROM_J(obj, Health, j);
	REZ_FROM_J(obj, Lore, j);
	REZ_FROM_J(obj, Name, j);
	REZ_FROM_J(obj, OnFreeRotation, j);
	REZ_FROM_J(obj, Pantheon, j);
	REZ_FROM_J(obj, Pros, j);
	REZ_FROM_J(obj, Roles, j);
	REZ_FROM_J(obj, Speed, j);
	REZ_FROM_J(obj, Title, j);
	REZ_FROM_J(obj, Type, j);
	REZ_FROM_J(obj, abilityDescription1, j);
	REZ_FROM_J(obj, abilityDescription2, j);
	REZ_FROM_J(obj, abilityDescription3, j);
	REZ_FROM_J(obj, abilityDescription4, j);
	REZ_FROM_J(obj, abilityDescription5, j);
	REZ_FROM_J(obj, id, j);
	REZ_FROM_J(obj, latestChampion, j);
	REZ_FROM_J(obj, ret_msg, j);
}

void to_json(nlohmann::json& j, const god_leaderboard& obj) {
	j = {
		REZ_TO_J(obj, god_id),
		REZ_TO_J(obj, losses),
		REZ_TO_J(obj, player_id),
		REZ_TO_J(obj, player_name),
		REZ_TO_J(obj, player_ranking),
		REZ_TO_J(obj, rank),
		REZ_TO_J(obj, ret_msg),
		REZ_TO_J(obj, wins),
	};
}
void from_json(const nlohmann::json& j, god_leaderboard& obj) {
	REZ_FROM_J(obj, god_id, j);
	REZ_FROM_J(obj, losses, j);
	REZ_FROM_J(obj, player_id, j);
	REZ_FROM_J(obj, player_name, j);
	REZ_FROM_J(obj, player_ranking, j);
	REZ_FROM_J(obj, rank, j);
	REZ_FROM_J(obj, ret_msg, j);
	REZ_FROM_J(obj, wins, j);
}

void to_json(nlohmann::json& j, const god_skin& obj) {
	j = {
		REZ_TO_J(obj, godIcon_URL),
		REZ_TO_J(obj, godSkin_URL),
		REZ_TO_J(obj, god_id),
		REZ_TO_J(obj, god_name),
		REZ_TO_J(obj, obtainability),
		REZ_TO_J(obj, price_favor),
		REZ_TO_J(obj, price_gems),
		REZ_TO_J(obj, ret_msg),
		REZ_TO_J(obj, skin_id1),
		REZ_TO_J(obj, skin_id2),
		REZ_TO_J(obj, skin_name),
	};
}
void from_json(const nlohmann::json& j, god_skin& obj) {
	REZ_FROM_J(obj, godIcon_URL, j);
	REZ_FROM_J(obj, godSkin_URL, j);
	REZ_FROM_J(obj, god_id, j);
	REZ_FROM_J(obj, god_name, j);
	REZ_FROM_J(obj, obtainability, j);
	REZ_FROM_J(obj, price_favor, j);
	REZ_FROM_J(obj, price_gems, j);
	REZ_FROM_J(obj, ret_msg, j);
	REZ_FROM_J(obj, skin_id1, j);
	REZ_FROM_J(obj, skin_id2, j);
	REZ_FROM_J(obj, skin_name, j);
}

void to_json(nlohmann::json& j, const champion_skin& obj) {
	j = {
		REZ_TO_J(obj, champion_id),
		REZ_TO_J(obj, champion_name),
		REZ_TO_J(obj, rarity),
		REZ_TO_J(obj, ret_msg),
		REZ_TO_J(obj, skin_id1),
		REZ_TO_J(obj, skin_id2),
		REZ_TO_J(obj, skin_name),
		REZ_TO_J(obj, skin_name_english),
	};
}
void from_json(const nlohmann::json& j, champion_skin& obj) {
	REZ_FROM_J(obj, champion_id, j);
	REZ_FROM_J(obj, champion_name, j);
	REZ_FROM_J(obj, rarity, j);
	REZ_FROM_J(obj, ret_msg, j);
	REZ_FROM_J(obj, skin_id1, j);
	REZ_FROM_J(obj, skin_id2, j);
	REZ_FROM_J(obj, skin_name, j);
	REZ_FROM_J(obj, skin_name_english, j);
}

void to_json(nlohmann::json& j, const god_recommended_item& obj) {
	j = {
		REZ_TO_J(obj, Category),
		REZ_TO_J(obj, Item),
		REZ_TO_J(obj, Role),
		REZ_TO_J(obj, category_value_id),
		REZ_TO_J(obj, god_id),
		REZ_TO_J(obj, god_name),
		REZ_TO_J(obj, icon_id),
		REZ_TO_J(obj, item_id),
		REZ_TO_J(obj, ret_msg),
		REZ_TO_J(obj, role_value_id),
	};
}
void from_json(const nlohmann::json& j, god_recommended_item& obj) {
	REZ_FROM_J(obj, Category, j);
	REZ_FROM_J(obj, Item, j);
	REZ_FROM_J(obj, Role, j);
	REZ_FROM_J(obj, category_value_id, j);
	REZ_FROM_J(obj, god_id, j);
	REZ_FROM_J(obj, god_name, j);
	REZ_FROM_J(obj, icon_id, j);
	REZ_FROM_J(obj, item_id, j);
	REZ_FROM_J(obj, ret_msg, j);
	REZ_FROM_J(obj, role_value_id, j);
}

void to_json(nlohmann::json& j, const item_pal& obj) {
	j = {
		REZ_TO_J(obj, Description),
		REZ_TO_J(obj, DeviceName),
		REZ_TO_J(obj, IconId),
		REZ_TO_J(obj, ItemId),
		REZ_TO_J(obj, Price),
		REZ_TO_J(obj, ShortDesc),
		REZ_TO_J(obj, champion_id),
		REZ_TO_J(obj, itemIcon_URL),
		REZ_TO_J(obj, item_type),
		REZ_TO_J(obj, ret_msg),
		REZ_TO_J(obj, talent_reward_level),
	};
}
void from_json(const nlohmann::json& j, item_pal& obj) {
	REZ_FROM_J(obj, Description, j);
	REZ_FROM_J(obj, DeviceName, j);
	REZ_FROM_J(obj, IconId, j);
	REZ_FROM_J(obj, ItemId, j);
	REZ_FROM_J(obj, Price, j);
	REZ_FROM_J(obj, ShortDesc, j);
	REZ_FROM_J(obj, champion_id, j);
	REZ_FROM_J(obj, itemIcon_URL, j);
	REZ_FROM_J(obj, item_type, j);
	REZ_FROM_J(obj, ret_msg, j);
	REZ_FROM_J(obj, talent_reward_level, j);
}

void to_json(nlohmann::json& j, const item_menu_item& obj) {
	j = {
		REZ_TO_J(obj, Description),
		REZ_TO_J(obj, Value),
	};
}
void from_json(const nlohmann::json& j, item_menu_item& obj) {
	REZ_FROM_J(obj, Description, j);
	REZ_FROM_J(obj, Value, j);
}

void to_json(nlohmann::json& j, const item_item_description& obj) {
	j = {
		REZ_TO_J(obj, Description),
		REZ_TO_J(obj, Menuitems),
		REZ_TO_J(obj, SecondaryDescription),
	};
}
void from_json(const nlohmann::json& j, item_item_description& obj) {
	REZ_FROM_J(obj, Description, j);
	REZ_FROM_J(obj, Menuitems, j);
	REZ_FROM_J(obj, SecondaryDescription, j);
}

void to_json(nlohmann::json& j, const item_smi& obj) {
	j = {
		REZ_TO_J(obj, ChildItemId),
		REZ_TO_J(obj, DeviceName),
		REZ_TO_J(obj, IconId),
		REZ_TO_J(obj, ItemDescription),
		REZ_TO_J(obj, ItemId),
		REZ_TO_J(obj, ItemTier),
		REZ_TO_J(obj, Price),
		REZ_TO_J(obj, RootItemId),
		REZ_TO_J(obj, ShortDesc),
		REZ_TO_J(obj, StartingItem),
		REZ_TO_J(obj, Type),
		REZ_TO_J(obj, itemIcon_URL),
		REZ_TO_J(obj, ret_msg),
	};
}
void from_json(const nlohmann::json& j, item_smi& obj) {
	REZ_FROM_J(obj, ChildItemId, j);
	REZ_FROM_J(obj, DeviceName, j);
	REZ_FROM_J(obj, IconId, j);
	REZ_FROM_J(obj, ItemDescription, j);
	REZ_FROM_J(obj, ItemId, j);
	REZ_FROM_J(obj, ItemTier, j);
	REZ_FROM_J(obj, Price, j);
	REZ_FROM_J(obj, RootItemId, j);
	REZ_FROM_J(obj, ShortDesc, j);
	REZ_FROM_J(obj, StartingItem, j);
	REZ_FROM_J(obj, Type, j);
	REZ_FROM_J(obj, itemIcon_URL, j);
	REZ_FROM_J(obj, ret_msg, j);
}

void to_json(nlohmann::json& j, const match_details_pal& obj) {
	j = {
		REZ_TO_J(obj, Account_Level),
		REZ_TO_J(obj, ActiveId1),
		REZ_TO_J(obj, ActiveId2),
		REZ_TO_J(obj, ActiveId3),
		REZ_TO_J(obj, ActiveId4),
		REZ_TO_J(obj, ActiveLevel1),
		REZ_TO_J(obj, ActiveLevel2),
		REZ_TO_J(obj, ActiveLevel3),
		REZ_TO_J(obj, ActiveLevel4),
		REZ_TO_J(obj, Assists),
		REZ_TO_J(obj, BanId1),
		REZ_TO_J(obj, BanId2),
		REZ_TO_J(obj, BanId3),
		REZ_TO_J(obj, BanId4),
		REZ_TO_J(obj, Ban_1),
		REZ_TO_J(obj, Ban_2),
		REZ_TO_J(obj, Ban_3),
		REZ_TO_J(obj, Ban_4),
		REZ_TO_J(obj, Camps_Cleared),
		REZ_TO_J(obj, ChampionId),
		REZ_TO_J(obj, Damage_Bot),
		REZ_TO_J(obj, Damage_Done_In_Hand),
		REZ_TO_J(obj, Damage_Done_Magical),
		REZ_TO_J(obj, Damage_Done_Physical),
		REZ_TO_J(obj, Damage_Mitigated),
		REZ_TO_J(obj, Damage_Player),
		REZ_TO_J(obj, Damage_Taken),
		REZ_TO_J(obj, Damage_Taken_Magical),
		REZ_TO_J(obj, Damage_Taken_Physical),
		REZ_TO_J(obj, Deaths),
		REZ_TO_J(obj, Distance_Traveled),
		REZ_TO_J(obj, Entry_Datetime),
		REZ_TO_J(obj, Final_Match_Level),
		REZ_TO_J(obj, Gold_Earned),
		REZ_TO_J(obj, Gold_Per_Minute),
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
		REZ_TO_J(obj, Item_Active_1),
		REZ_TO_J(obj, Item_Active_2),
		REZ_TO_J(obj, Item_Active_3),
		REZ_TO_J(obj, Item_Active_4),
		REZ_TO_J(obj, Item_Purch_1),
		REZ_TO_J(obj, Item_Purch_2),
		REZ_TO_J(obj, Item_Purch_3),
		REZ_TO_J(obj, Item_Purch_4),
		REZ_TO_J(obj, Item_Purch_5),
		REZ_TO_J(obj, Item_Purch_6),
		REZ_TO_J(obj, Killing_Spree),
		REZ_TO_J(obj, Kills_Bot),
		REZ_TO_J(obj, Kills_Double),
		REZ_TO_J(obj, Kills_Fire_Giant),
		REZ_TO_J(obj, Kills_First_Blood),
		REZ_TO_J(obj, Kills_Gold_Fury),
		REZ_TO_J(obj, Kills_Penta),
		REZ_TO_J(obj, Kills_Phoenix),
		REZ_TO_J(obj, Kills_Player),
		REZ_TO_J(obj, Kills_Quadra),
		REZ_TO_J(obj, Kills_Siege_Juggernaut),
		REZ_TO_J(obj, Kills_Single),
		REZ_TO_J(obj, Kills_Triple),
		REZ_TO_J(obj, Kills_Wild_Juggernaut),
		REZ_TO_J(obj, League_Losses),
		REZ_TO_J(obj, League_Points),
		REZ_TO_J(obj, League_Tier),
		REZ_TO_J(obj, League_Wins),
		REZ_TO_J(obj, Map_Game),
		REZ_TO_J(obj, Mastery_Level),
		REZ_TO_J(obj, Match),
		REZ_TO_J(obj, Minutes),
		REZ_TO_J(obj, Multi_kill_Max),
		REZ_TO_J(obj, Objective_Assists),
		REZ_TO_J(obj, PartyId),
		REZ_TO_J(obj, Rank_Stat_League),
		REZ_TO_J(obj, Reference_Name),
		REZ_TO_J(obj, Region),
		REZ_TO_J(obj, Skin),
		REZ_TO_J(obj, SkinId),
		REZ_TO_J(obj, Structure_Damage),
		REZ_TO_J(obj, Surrendered),
		REZ_TO_J(obj, TaskForce),
		REZ_TO_J(obj, Team1Score),
		REZ_TO_J(obj, Team2Score),
		REZ_TO_J(obj, TeamId),
		REZ_TO_J(obj, Team_Name),
		REZ_TO_J(obj, Time_In_Match_Seconds),
		REZ_TO_J(obj, Towers_Destroyed),
		REZ_TO_J(obj, Wards_Placed),
		REZ_TO_J(obj, Win_Status),
		REZ_TO_J(obj, Winning_TaskForce),
		REZ_TO_J(obj, hasReplay),
		REZ_TO_J(obj, match_queue_id),
		REZ_TO_J(obj, name),
		REZ_TO_J(obj, playerId),
		REZ_TO_J(obj, playerName),
		REZ_TO_J(obj, ret_msg),
	};
}
void from_json(const nlohmann::json& j, match_details_pal& obj) {
	REZ_FROM_J(obj, Account_Level, j);
	REZ_FROM_J(obj, ActiveId1, j);
	REZ_FROM_J(obj, ActiveId2, j);
	REZ_FROM_J(obj, ActiveId3, j);
	REZ_FROM_J(obj, ActiveId4, j);
	REZ_FROM_J(obj, ActiveLevel1, j);
	REZ_FROM_J(obj, ActiveLevel2, j);
	REZ_FROM_J(obj, ActiveLevel3, j);
	REZ_FROM_J(obj, ActiveLevel4, j);
	REZ_FROM_J(obj, Assists, j);
	REZ_FROM_J(obj, BanId1, j);
	REZ_FROM_J(obj, BanId2, j);
	REZ_FROM_J(obj, BanId3, j);
	REZ_FROM_J(obj, BanId4, j);
	REZ_FROM_J(obj, Ban_1, j);
	REZ_FROM_J(obj, Ban_2, j);
	REZ_FROM_J(obj, Ban_3, j);
	REZ_FROM_J(obj, Ban_4, j);
	REZ_FROM_J(obj, Camps_Cleared, j);
	REZ_FROM_J(obj, ChampionId, j);
	REZ_FROM_J(obj, Damage_Bot, j);
	REZ_FROM_J(obj, Damage_Done_In_Hand, j);
	REZ_FROM_J(obj, Damage_Done_Magical, j);
	REZ_FROM_J(obj, Damage_Done_Physical, j);
	REZ_FROM_J(obj, Damage_Mitigated, j);
	REZ_FROM_J(obj, Damage_Player, j);
	REZ_FROM_J(obj, Damage_Taken, j);
	REZ_FROM_J(obj, Damage_Taken_Magical, j);
	REZ_FROM_J(obj, Damage_Taken_Physical, j);
	REZ_FROM_J(obj, Deaths, j);
	REZ_FROM_J(obj, Distance_Traveled, j);
	REZ_FROM_J(obj, Entry_Datetime, j);
	REZ_FROM_J(obj, Final_Match_Level, j);
	REZ_FROM_J(obj, Gold_Earned, j);
	REZ_FROM_J(obj, Gold_Per_Minute, j);
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
	REZ_FROM_J(obj, Item_Active_1, j);
	REZ_FROM_J(obj, Item_Active_2, j);
	REZ_FROM_J(obj, Item_Active_3, j);
	REZ_FROM_J(obj, Item_Active_4, j);
	REZ_FROM_J(obj, Item_Purch_1, j);
	REZ_FROM_J(obj, Item_Purch_2, j);
	REZ_FROM_J(obj, Item_Purch_3, j);
	REZ_FROM_J(obj, Item_Purch_4, j);
	REZ_FROM_J(obj, Item_Purch_5, j);
	REZ_FROM_J(obj, Item_Purch_6, j);
	REZ_FROM_J(obj, Killing_Spree, j);
	REZ_FROM_J(obj, Kills_Bot, j);
	REZ_FROM_J(obj, Kills_Double, j);
	REZ_FROM_J(obj, Kills_Fire_Giant, j);
	REZ_FROM_J(obj, Kills_First_Blood, j);
	REZ_FROM_J(obj, Kills_Gold_Fury, j);
	REZ_FROM_J(obj, Kills_Penta, j);
	REZ_FROM_J(obj, Kills_Phoenix, j);
	REZ_FROM_J(obj, Kills_Player, j);
	REZ_FROM_J(obj, Kills_Quadra, j);
	REZ_FROM_J(obj, Kills_Siege_Juggernaut, j);
	REZ_FROM_J(obj, Kills_Single, j);
	REZ_FROM_J(obj, Kills_Triple, j);
	REZ_FROM_J(obj, Kills_Wild_Juggernaut, j);
	REZ_FROM_J(obj, League_Losses, j);
	REZ_FROM_J(obj, League_Points, j);
	REZ_FROM_J(obj, League_Tier, j);
	REZ_FROM_J(obj, League_Wins, j);
	REZ_FROM_J(obj, Map_Game, j);
	REZ_FROM_J(obj, Mastery_Level, j);
	REZ_FROM_J(obj, Match, j);
	REZ_FROM_J(obj, Minutes, j);
	REZ_FROM_J(obj, Multi_kill_Max, j);
	REZ_FROM_J(obj, Objective_Assists, j);
	REZ_FROM_J(obj, PartyId, j);
	REZ_FROM_J(obj, Rank_Stat_League, j);
	REZ_FROM_J(obj, Reference_Name, j);
	REZ_FROM_J(obj, Region, j);
	REZ_FROM_J(obj, Skin, j);
	REZ_FROM_J(obj, SkinId, j);
	REZ_FROM_J(obj, Structure_Damage, j);
	REZ_FROM_J(obj, Surrendered, j);
	REZ_FROM_J(obj, TaskForce, j);
	REZ_FROM_J(obj, Team1Score, j);
	REZ_FROM_J(obj, Team2Score, j);
	REZ_FROM_J(obj, TeamId, j);
	REZ_FROM_J(obj, Team_Name, j);
	REZ_FROM_J(obj, Time_In_Match_Seconds, j);
	REZ_FROM_J(obj, Towers_Destroyed, j);
	REZ_FROM_J(obj, Wards_Placed, j);
	REZ_FROM_J(obj, Win_Status, j);
	REZ_FROM_J(obj, Winning_TaskForce, j);
	REZ_FROM_J(obj, hasReplay, j);
	REZ_FROM_J(obj, match_queue_id, j);
	REZ_FROM_J(obj, name, j);
	REZ_FROM_J(obj, playerId, j);
	REZ_FROM_J(obj, playerName, j);
	REZ_FROM_J(obj, ret_msg, j);
}

void to_json(nlohmann::json& j, const match_details_smi& obj) {
	j = {
		REZ_TO_J(obj, Account_Level),
		REZ_TO_J(obj, ActiveId1),
		REZ_TO_J(obj, ActiveId2),
		REZ_TO_J(obj, ActiveId3),
		REZ_TO_J(obj, ActiveId4),
		REZ_TO_J(obj, Assists),
		REZ_TO_J(obj, Ban1),
		REZ_TO_J(obj, Ban10),
		REZ_TO_J(obj, Ban10Id),
		REZ_TO_J(obj, Ban1Id),
		REZ_TO_J(obj, Ban2),
		REZ_TO_J(obj, Ban2Id),
		REZ_TO_J(obj, Ban3),
		REZ_TO_J(obj, Ban3Id),
		REZ_TO_J(obj, Ban4),
		REZ_TO_J(obj, Ban4Id),
		REZ_TO_J(obj, Ban5),
		REZ_TO_J(obj, Ban5Id),
		REZ_TO_J(obj, Ban6),
		REZ_TO_J(obj, Ban6Id),
		REZ_TO_J(obj, Ban7),
		REZ_TO_J(obj, Ban7Id),
		REZ_TO_J(obj, Ban8),
		REZ_TO_J(obj, Ban8Id),
		REZ_TO_J(obj, Ban9),
		REZ_TO_J(obj, Ban9Id),
		REZ_TO_J(obj, Camps_Cleared),
		REZ_TO_J(obj, Conquest_Losses),
		REZ_TO_J(obj, Conquest_Points),
		REZ_TO_J(obj, Conquest_Tier),
		REZ_TO_J(obj, Conquest_Wins),
		REZ_TO_J(obj, Damage_Bot),
		REZ_TO_J(obj, Damage_Done_In_Hand),
		REZ_TO_J(obj, Damage_Done_Magical),
		REZ_TO_J(obj, Damage_Done_Physical),
		REZ_TO_J(obj, Damage_Mitigated),
		REZ_TO_J(obj, Damage_Player),
		REZ_TO_J(obj, Damage_Taken),
		REZ_TO_J(obj, Damage_Taken_Magical),
		REZ_TO_J(obj, Damage_Taken_Physical),
		REZ_TO_J(obj, Deaths),
		REZ_TO_J(obj, Distance_Traveled),
		REZ_TO_J(obj, Duel_Losses),
		REZ_TO_J(obj, Duel_Points),
		REZ_TO_J(obj, Duel_Tier),
		REZ_TO_J(obj, Duel_Wins),
		REZ_TO_J(obj, Entry_Datetime),
		REZ_TO_J(obj, Final_Match_Level),
		REZ_TO_J(obj, First_Ban_Side),
		REZ_TO_J(obj, GodId),
		REZ_TO_J(obj, Gold_Earned),
		REZ_TO_J(obj, Gold_Per_Minute),
		REZ_TO_J(obj, Healing),
		REZ_TO_J(obj, Healing_Bot),
		REZ_TO_J(obj, Healing_Player_Self),
		REZ_TO_J(obj, ItemId1),
		REZ_TO_J(obj, ItemId2),
		REZ_TO_J(obj, ItemId3),
		REZ_TO_J(obj, ItemId4),
		REZ_TO_J(obj, ItemId5),
		REZ_TO_J(obj, ItemId6),
		REZ_TO_J(obj, Item_Active_1),
		REZ_TO_J(obj, Item_Active_2),
		REZ_TO_J(obj, Item_Active_3),
		REZ_TO_J(obj, Item_Active_4),
		REZ_TO_J(obj, Item_Purch_1),
		REZ_TO_J(obj, Item_Purch_2),
		REZ_TO_J(obj, Item_Purch_3),
		REZ_TO_J(obj, Item_Purch_4),
		REZ_TO_J(obj, Item_Purch_5),
		REZ_TO_J(obj, Item_Purch_6),
		REZ_TO_J(obj, Joust_Losses),
		REZ_TO_J(obj, Joust_Points),
		REZ_TO_J(obj, Joust_Tier),
		REZ_TO_J(obj, Joust_Wins),
		REZ_TO_J(obj, Killing_Spree),
		REZ_TO_J(obj, Kills_Bot),
		REZ_TO_J(obj, Kills_Double),
		REZ_TO_J(obj, Kills_Fire_Giant),
		REZ_TO_J(obj, Kills_First_Blood),
		REZ_TO_J(obj, Kills_Gold_Fury),
		REZ_TO_J(obj, Kills_Penta),
		REZ_TO_J(obj, Kills_Phoenix),
		REZ_TO_J(obj, Kills_Player),
		REZ_TO_J(obj, Kills_Quadra),
		REZ_TO_J(obj, Kills_Siege_Juggernaut),
		REZ_TO_J(obj, Kills_Single),
		REZ_TO_J(obj, Kills_Triple),
		REZ_TO_J(obj, Kills_Wild_Juggernaut),
		REZ_TO_J(obj, Map_Game),
		REZ_TO_J(obj, Mastery_Level),
		REZ_TO_J(obj, Match),
		REZ_TO_J(obj, Minutes),
		REZ_TO_J(obj, Multi_kill_Max),
		REZ_TO_J(obj, Objective_Assists),
		REZ_TO_J(obj, PartyId),
		REZ_TO_J(obj, Rank_Stat_Conquest),
		REZ_TO_J(obj, Rank_Stat_Duel),
		REZ_TO_J(obj, Rank_Stat_Joust),
		REZ_TO_J(obj, Reference_Name),
		REZ_TO_J(obj, Region),
		REZ_TO_J(obj, Skin),
		REZ_TO_J(obj, SkinId),
		REZ_TO_J(obj, Structure_Damage),
		REZ_TO_J(obj, Surrendered),
		REZ_TO_J(obj, TaskForce),
		REZ_TO_J(obj, Team1Score),
		REZ_TO_J(obj, Team2Score),
		REZ_TO_J(obj, TeamId),
		REZ_TO_J(obj, Team_Name),
		REZ_TO_J(obj, Time_In_Match_Seconds),
		REZ_TO_J(obj, Towers_Destroyed),
		REZ_TO_J(obj, Wards_Placed),
		REZ_TO_J(obj, Win_Status),
		REZ_TO_J(obj, Winning_TaskForce),
		REZ_TO_J(obj, hasReplay),
		REZ_TO_J(obj, match_queue_id),
		REZ_TO_J(obj, name),
		REZ_TO_J(obj, playerId),
		REZ_TO_J(obj, playerName),
		REZ_TO_J(obj, ret_msg),
	};
}
void from_json(const nlohmann::json& j, match_details_smi& obj) {
	REZ_FROM_J(obj, Account_Level, j);
	REZ_FROM_J(obj, ActiveId1, j);
	REZ_FROM_J(obj, ActiveId2, j);
	REZ_FROM_J(obj, ActiveId3, j);
	REZ_FROM_J(obj, ActiveId4, j);
	REZ_FROM_J(obj, Assists, j);
	REZ_FROM_J(obj, Ban1, j);
	REZ_FROM_J(obj, Ban10, j);
	REZ_FROM_J(obj, Ban10Id, j);
	REZ_FROM_J(obj, Ban1Id, j);
	REZ_FROM_J(obj, Ban2, j);
	REZ_FROM_J(obj, Ban2Id, j);
	REZ_FROM_J(obj, Ban3, j);
	REZ_FROM_J(obj, Ban3Id, j);
	REZ_FROM_J(obj, Ban4, j);
	REZ_FROM_J(obj, Ban4Id, j);
	REZ_FROM_J(obj, Ban5, j);
	REZ_FROM_J(obj, Ban5Id, j);
	REZ_FROM_J(obj, Ban6, j);
	REZ_FROM_J(obj, Ban6Id, j);
	REZ_FROM_J(obj, Ban7, j);
	REZ_FROM_J(obj, Ban7Id, j);
	REZ_FROM_J(obj, Ban8, j);
	REZ_FROM_J(obj, Ban8Id, j);
	REZ_FROM_J(obj, Ban9, j);
	REZ_FROM_J(obj, Ban9Id, j);
	REZ_FROM_J(obj, Camps_Cleared, j);
	REZ_FROM_J(obj, Conquest_Losses, j);
	REZ_FROM_J(obj, Conquest_Points, j);
	REZ_FROM_J(obj, Conquest_Tier, j);
	REZ_FROM_J(obj, Conquest_Wins, j);
	REZ_FROM_J(obj, Damage_Bot, j);
	REZ_FROM_J(obj, Damage_Done_In_Hand, j);
	REZ_FROM_J(obj, Damage_Done_Magical, j);
	REZ_FROM_J(obj, Damage_Done_Physical, j);
	REZ_FROM_J(obj, Damage_Mitigated, j);
	REZ_FROM_J(obj, Damage_Player, j);
	REZ_FROM_J(obj, Damage_Taken, j);
	REZ_FROM_J(obj, Damage_Taken_Magical, j);
	REZ_FROM_J(obj, Damage_Taken_Physical, j);
	REZ_FROM_J(obj, Deaths, j);
	REZ_FROM_J(obj, Distance_Traveled, j);
	REZ_FROM_J(obj, Duel_Losses, j);
	REZ_FROM_J(obj, Duel_Points, j);
	REZ_FROM_J(obj, Duel_Tier, j);
	REZ_FROM_J(obj, Duel_Wins, j);
	REZ_FROM_J(obj, Entry_Datetime, j);
	REZ_FROM_J(obj, Final_Match_Level, j);
	REZ_FROM_J(obj, First_Ban_Side, j);
	REZ_FROM_J(obj, GodId, j);
	REZ_FROM_J(obj, Gold_Earned, j);
	REZ_FROM_J(obj, Gold_Per_Minute, j);
	REZ_FROM_J(obj, Healing, j);
	REZ_FROM_J(obj, Healing_Bot, j);
	REZ_FROM_J(obj, Healing_Player_Self, j);
	REZ_FROM_J(obj, ItemId1, j);
	REZ_FROM_J(obj, ItemId2, j);
	REZ_FROM_J(obj, ItemId3, j);
	REZ_FROM_J(obj, ItemId4, j);
	REZ_FROM_J(obj, ItemId5, j);
	REZ_FROM_J(obj, ItemId6, j);
	REZ_FROM_J(obj, Item_Active_1, j);
	REZ_FROM_J(obj, Item_Active_2, j);
	REZ_FROM_J(obj, Item_Active_3, j);
	REZ_FROM_J(obj, Item_Active_4, j);
	REZ_FROM_J(obj, Item_Purch_1, j);
	REZ_FROM_J(obj, Item_Purch_2, j);
	REZ_FROM_J(obj, Item_Purch_3, j);
	REZ_FROM_J(obj, Item_Purch_4, j);
	REZ_FROM_J(obj, Item_Purch_5, j);
	REZ_FROM_J(obj, Item_Purch_6, j);
	REZ_FROM_J(obj, Joust_Losses, j);
	REZ_FROM_J(obj, Joust_Points, j);
	REZ_FROM_J(obj, Joust_Tier, j);
	REZ_FROM_J(obj, Joust_Wins, j);
	REZ_FROM_J(obj, Killing_Spree, j);
	REZ_FROM_J(obj, Kills_Bot, j);
	REZ_FROM_J(obj, Kills_Double, j);
	REZ_FROM_J(obj, Kills_Fire_Giant, j);
	REZ_FROM_J(obj, Kills_First_Blood, j);
	REZ_FROM_J(obj, Kills_Gold_Fury, j);
	REZ_FROM_J(obj, Kills_Penta, j);
	REZ_FROM_J(obj, Kills_Phoenix, j);
	REZ_FROM_J(obj, Kills_Player, j);
	REZ_FROM_J(obj, Kills_Quadra, j);
	REZ_FROM_J(obj, Kills_Siege_Juggernaut, j);
	REZ_FROM_J(obj, Kills_Single, j);
	REZ_FROM_J(obj, Kills_Triple, j);
	REZ_FROM_J(obj, Kills_Wild_Juggernaut, j);
	REZ_FROM_J(obj, Map_Game, j);
	REZ_FROM_J(obj, Mastery_Level, j);
	REZ_FROM_J(obj, Match, j);
	REZ_FROM_J(obj, Minutes, j);
	REZ_FROM_J(obj, Multi_kill_Max, j);
	REZ_FROM_J(obj, Objective_Assists, j);
	REZ_FROM_J(obj, PartyId, j);
	REZ_FROM_J(obj, Rank_Stat_Conquest, j);
	REZ_FROM_J(obj, Rank_Stat_Duel, j);
	REZ_FROM_J(obj, Rank_Stat_Joust, j);
	REZ_FROM_J(obj, Reference_Name, j);
	REZ_FROM_J(obj, Region, j);
	REZ_FROM_J(obj, Skin, j);
	REZ_FROM_J(obj, SkinId, j);
	REZ_FROM_J(obj, Structure_Damage, j);
	REZ_FROM_J(obj, Surrendered, j);
	REZ_FROM_J(obj, TaskForce, j);
	REZ_FROM_J(obj, Team1Score, j);
	REZ_FROM_J(obj, Team2Score, j);
	REZ_FROM_J(obj, TeamId, j);
	REZ_FROM_J(obj, Team_Name, j);
	REZ_FROM_J(obj, Time_In_Match_Seconds, j);
	REZ_FROM_J(obj, Towers_Destroyed, j);
	REZ_FROM_J(obj, Wards_Placed, j);
	REZ_FROM_J(obj, Win_Status, j);
	REZ_FROM_J(obj, Winning_TaskForce, j);
	REZ_FROM_J(obj, hasReplay, j);
	REZ_FROM_J(obj, match_queue_id, j);
	REZ_FROM_J(obj, name, j);
	REZ_FROM_J(obj, playerId, j);
	REZ_FROM_J(obj, playerName, j);
	REZ_FROM_J(obj, ret_msg, j);
}
} // namespace rez
