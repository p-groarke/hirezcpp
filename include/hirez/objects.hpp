#pragma once
#include <date/date.h>
#include <string>

namespace rez {
struct session_response {
	std::string ret_msg{ "" };
	std::string session_id{ "" };
	date::sys_seconds timestamp{};
};

struct server_status {
	date::sys_seconds entry_datetime{};
	std::string ret_msg{ "" };
	std::string status{ "" };
	std::string version{ "" };
};

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

struct match_history_pal {
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
	date::sys_seconds Match_Time{};
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

struct match_history_smi {
	int ActiveId1{ 0 };
	int ActiveId2{ 0 };
	std::string Active_1{ "" };
	std::string Active_2{ "" };
	std::string Active_3{ "" };
	int Assists{ 0 };
	std::string Ban1{ "" };
	std::string Ban10{ "" };
	int Ban10Id{ 0 };
	int Ban1Id{ 0 };
	std::string Ban2{ "" };
	int Ban2Id{ 0 };
	std::string Ban3{ "" };
	int Ban3Id{ 0 };
	std::string Ban4{ "" };
	int Ban4Id{ 0 };
	std::string Ban5{ "" };
	int Ban5Id{ 0 };
	std::string Ban6{ "" };
	int Ban6Id{ 0 };
	std::string Ban7{ "" };
	int Ban7Id{ 0 };
	std::string Ban8{ "" };
	int Ban8Id{ 0 };
	std::string Ban9{ "" };
	int Ban9Id{ 0 };
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
	std::string First_Ban_Side{ "" };
	std::string God{ "" };
	int GodId{ 0 };
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
	date::sys_seconds Match_Time{};
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

struct demo_details_pal {
	int BanId1{ 0 };
	int BanId2{ 0 };
	int BanId3{ 0 };
	int BanId4{ 0 };
	date::sys_seconds Entry_Datetime{};
	int Match{ 0 };
	int Match_Time{ 0 };
	int Offline_Spectators{ 0 };
	std::string Queue{ "" };
	int Realtime_Spectators{ 0 };
	date::sys_seconds Recording_Ended{};
	date::sys_seconds Recording_Started{};
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

struct demo_details_smi {
	std::string Ban1{ "" };
	std::string Ban2{ "" };
	date::sys_seconds Entry_Datetime{};
	int Match{ 0 };
	int Match_Time{ 0 };
	int Offline_Spectators{ 0 };
	int Realtime_Spectators{ 0 };
	date::sys_seconds Recording_Ended{};
	date::sys_seconds Recording_Started{};
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

struct esports_pro_league_details {
	int away_team_clan_id{ 0 };
	std::string away_team_name{ "" };
	std::string away_team_tagname{ "" };
	int home_team_clan_id{ 0 };
	std::string home_team_name{ "" };
	std::string home_team_tagname{ "" };
	int map_instance_id{ 0 };
	date::sys_seconds match_date{};
	int match_number{ 0 };
	std::string match_status{ "" };
	int matchup_id{ 0 };
	std::string region{ "" };
	std::string ret_msg{ "" };
	std::string tournament_name{ "" };
	int winning_team_clan_id{ 0 };
};

struct friends {
	int account_id{ 0 };
	std::string name{ "" };
	int player_id{ 0 };
	std::string ret_msg{ "" };
};

struct god_rank {
	int Assists{ 0 };
	int Deaths{ 4 };
	int Kills{ 2 };
	int Losses{ 1 };
	int MinionKills{ 69 };
	int Rank{ 0 };
	int Wins{ 0 };
	int Worshippers{ 3 };
	std::string god{ "" };
	int god_id{ 0 };
	int player_id{ 0 };
	std::string ret_msg{ "" };
};

struct champion_rank {
	int Assists{ 0 };
	int Deaths{ 0 };
	int Gold{ 0 };
	int Kills{ 0 };
	date::sys_seconds LastPlayed{};
	int Losses{ 0 };
	int MinionKills{ 0 };
	int Minutes{ 0 };
	int Rank{ 0 };
	int Wins{ 0 };
	int Worshippers{ 0 };
	std::string champion{ "" };
	int champion_id{ 0 };
	int player_id{ 0 };
	std::string ret_msg{ "" };
};

struct menu_item_smi {
	std::string description{ "" };
	std::string value{ "" };
};

struct rank_item_smi {
	std::string description{ "" };
	std::string value{ "" };
};

struct item_description_smi {
	std::string cooldown{ "" };
	std::string cost{ "" };
	std::string description{ "" };
	std::vector<menu_item_smi> menuitems{};
	std::vector<rank_item_smi> rankitems{};
	std::string secondaryDescription{ "" };
};

struct ability_description_smi {
	item_description_smi itemDescription{};
};

struct ability_details_smi {
	ability_description_smi Description{};
	int Id{ 0 };
	std::string Summary{ "" };
	std::string URL{ "" };
};

struct god {
	std::string Ability1{ "" };
	std::string Ability2{ "" };
	std::string Ability3{ "" };
	std::string Ability4{ "" };
	std::string Ability5{ "" };
	int AbilityId1{ 0 };
	int AbilityId2{ 0 };
	int AbilityId3{ 0 };
	int AbilityId4{ 0 };
	int AbilityId5{ 0 };
	ability_details_smi Ability_1{};
	ability_details_smi Ability_2{};
	ability_details_smi Ability_3{};
	ability_details_smi Ability_4{};
	ability_details_smi Ability_5{};
	int AttackSpeed{ 0 };
	int AttackSpeedPerLevel{ 0 };
	std::string Cons{ "" };
	int HP5PerLevel{ 0 };
	int Health{ 0 };
	int HealthPerFive{ 0 };
	int HealthPerLevel{ 0 };
	std::string Lore{ "" };
	int MP5PerLevel{ 0 };
	int MagicProtection{ 0 };
	int MagicProtectionPerLevel{ 0 };
	int MagicalPower{ 0 };
	int MagicalPowerPerLevel{ 0 };
	int Mana{ 0 };
	int ManaPerFive{ 0 };
	int ManaPerLevel{ 0 };
	std::string Name{ "" };
	std::string OnFreeRotation{ "" };
	std::string Pantheon{ "" };
	int PhysicalPower{ 0 };
	int PhysicalPowerPerLevel{ 0 };
	int PhysicalProtection{ 0 };
	int PhysicalProtectionPerLevel{ 0 };
	std::string Pros{ "" };
	std::string Roles{ "" };
	int Speed{ 0 };
	std::string Title{ "" };
	std::string Type{ "" };
	ability_description_smi abilityDescription1{};
	ability_description_smi abilityDescription2{};
	ability_description_smi abilityDescription3{};
	ability_description_smi abilityDescription4{};
	ability_description_smi abilityDescription5{};
	ability_description_smi basicAttack{};
	std::string godAbility1_URL{ "" };
	std::string godAbility2_URL{ "" };
	std::string godAbility3_URL{ "" };
	std::string godAbility4_URL{ "" };
	std::string godAbility5_URL{ "" };
	std::string godCard_URL{ "" };
	std::string godIcon_URL{ "" };
	int id{ 0 };
	std::string latestGod{ "" };
	std::string ret_msg{ "" };
};

struct ability_details_pal {
	std::string Description{ "" };
	int Id{ 0 };
	std::string Summary{ "" };
	std::string URL{ "" };
};

struct champion {
	std::string Ability1{ "" };
	std::string Ability2{ "" };
	std::string Ability3{ "" };
	std::string Ability4{ "" };
	std::string Ability5{ "" };
	int AbilityId1{ 0 };
	int AbilityId2{ 0 };
	int AbilityId3{ 0 };
	int AbilityId4{ 0 };
	int AbilityId5{ 0 };
	ability_details_pal Ability_1{};
	ability_details_pal Ability_2{};
	ability_details_pal Ability_3{};
	ability_details_pal Ability_4{};
	ability_details_pal Ability_5{};
	std::string ChampionAbility1_URL{ "" };
	std::string ChampionAbility2_URL{ "" };
	std::string ChampionAbility3_URL{ "" };
	std::string ChampionAbility4_URL{ "" };
	std::string ChampionAbility5_URL{ "" };
	std::string ChampionCard_URL{ "" };
	std::string ChampionIcon_URL{ "" };
	std::string Cons{ "" };
	int Health{ 0 };
	std::string Lore{ "" };
	std::string Name{ "" };
	std::string OnFreeRotation{ "" };
	std::string Pantheon{ "" };
	std::string Pros{ "" };
	std::string Roles{ "" };
	int Speed{ 0 };
	std::string Title{ "" };
	std::string Type{ "" };
	std::string abilityDescription1{ "" };
	std::string abilityDescription2{ "" };
	std::string abilityDescription3{ "" };
	std::string abilityDescription4{ "" };
	std::string abilityDescription5{ "" };
	int id{ 0 };
	std::string latestChampion{ "" };
	std::string ret_msg{ "" };
};
} // namespace rez
