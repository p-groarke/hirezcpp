#pragma once
#include "hirez/objects.hpp"
#include "hirez/util.hpp"

#include <nlohmann/json.hpp>

namespace rez {
void to_json(nlohmann::json& j, const session_response& obj) {
	j = {
		REZ_TO_J(obj, ret_msg),
		REZ_TO_J(obj, session_id),
		REZ_TO_J(obj, timestamp),
	};
}
void from_json(const nlohmann::json& j, session_response& obj) {
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
void from_json(const nlohmann::json& j, god_rank& obj) {
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

void to_json(nlohmann::json& j, const ability_details& obj) {
	j = {
		REZ_TO_J(obj, Description),
		REZ_TO_J(obj, Id),
		REZ_TO_J(obj, Summary),
		REZ_TO_J(obj, URL),
	};
}
void from_json(const nlohmann::json& j, ability_details& obj) {
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
} // namespace rez
