#pragma once
#include <date/date.h>
#include <string>

namespace rez {
enum class queue_smi_e : int {
	arena = 435,
	joust = 448,
	conquest = 426,
	assault = 445,
	clash = 466,
	adventures_horde = 495,
	conquest_ranked = 451,
	motd = 434,
	siege_4v4 = 459,
	joust_3v3_ranked = 450,
	joust_1v1_ranked = 440,
	joust_challenge = 441,
	arena_ai_easy = 457,
	arena_ai_medium = 468,
	basic_tutorial = 436,
	arena_challenge = 438,
	conquest_challenge = 429,
	joust_3v3_training = 482,
	arena_tutorial = 462,
	arena_training = 483,
	joust_ai_easy = 474,
	joust_ai_medium = 456,
	clash_ai_easy = 478,
	clash_ai_medium = 469,
	arena_practice_medium = 472,
	assault_ai_easy = 481,
	conquest_ai_easy = 476,
	clash_tutorial = 471,
	joust_practice_medium = 473,
	assault_challenge = 446,
	assault_ai_medium = 454,
	arena_practice_easy = 443,
	clash_challenge = 467,
	conquest_ai_medium = 461,
	joust_practice_easy = 464,
	clash_practice_medium = 477,
	siege_challenge = 460,
	assault_practice_medium = 480,
	conquest_tutorial = 463,
	clash_practice_easy = 470,
	assault_practice_easy = 479,
	conquest_practice_medium = 475,
	conquest_practice_easy = 458,
	jungle_practice = 444,
	jungle_practice_preselected = 496,
	none = 0,
};

enum class queue_pal_e : int {
	live_casual = 424,
	live_team_deathmatch = 469,
	live_onslaught = 452,
	live_competitive = 428,
	classic_siege = 465,
	live_practice_siege = 425,
	live_onslaught_practice = 453,
	live_team_deathmatch_practice = 470,
	live_test_maps = 445,
	live_battlegrounds_solo = 474,
	live_battlegrounds_duo = 475,
	live_battlegrounds_quad = 476,
	custom_t_magistrates_archives = 472,
	custom_t_trade_district = 468,
	custom_s_stonekeep = 423,
	custom_t_foremans_rise = 471,
	custom_s_frogisle = 433,
	custom_s_fishmarket = 431,
	custom_s_brightmarsh = 458,
	custom_s_timbermill = 430,
	custom_s_serpentbeach = 440,
	custom_s_jaguarfalls = 438,
	custom_s_splitstonequarry = 459,
	custom_o_magistrates_archives = 464,
	custom_s_frozenguard = 432,
	custom_o_foremans_rise = 462,
	custom_s_icemines = 439,
	custom_o_primalcourt = 455,
	custom_o_snowfalljunction = 454,
	none = 0,
};

struct session_info {
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
	queue_pal_e Match_Queue_Id{};
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
	queue_smi_e Match_Queue_Id{};
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

struct god_menu_item {
	std::string description{ "" };
	std::string value{ "" };
};

struct god_rank_item {
	std::string description{ "" };
	std::string value{ "" };
};

struct god_item_description {
	std::string cooldown{ "" };
	std::string cost{ "" };
	std::string description{ "" };
	std::vector<god_menu_item> menuitems{};
	std::vector<god_rank_item> rankitems{};
	std::string secondaryDescription{ "" };
};

struct god_ability_description {
	god_item_description itemDescription{};
};

struct god_ability_details {
	god_ability_description Description{};
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
	god_ability_details Ability_1{};
	god_ability_details Ability_2{};
	god_ability_details Ability_3{};
	god_ability_details Ability_4{};
	god_ability_details Ability_5{};
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
	god_ability_description abilityDescription1{};
	god_ability_description abilityDescription2{};
	god_ability_description abilityDescription3{};
	god_ability_description abilityDescription4{};
	god_ability_description abilityDescription5{};
	god_ability_description basicAttack{};
	std::string godAbility1_URL{ "" };
	std::string godAbility2_URL{ "" };
	std::string godAbility3_URL{ "" };
	std::string godAbility4_URL{ "" };
	std::string godAbility5_URL{ "" };
	std::string godCard_URL{ "" };
	std::string godIcon_URL{ "" };
	int id{ 0 };
	bool latestGod{};
	std::string ret_msg{ "" };
};

struct champion_ability_details {
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
	champion_ability_details Ability_1{};
	champion_ability_details Ability_2{};
	champion_ability_details Ability_3{};
	champion_ability_details Ability_4{};
	champion_ability_details Ability_5{};
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
	bool latestChampion{};
	std::string ret_msg{ "" };
};

struct god_leaderboard {
	int god_id{ 0 };
	int losses{ 0 };
	int player_id{ 0 };
	std::string player_name{ "GooW" };
	float player_ranking{ 0.f };
	int rank{ 0 };
	std::string ret_msg{ "" };
	int wins{ 0 };
};

struct god_skin {
	std::string godIcon_URL{ "" };
	std::string godSkin_URL{ "" };
	int god_id{ 0 };
	std::string god_name{ "" };
	std::string obtainability{ "" };
	int price_favor{ 0 };
	int price_gems{ 0 };
	std::string ret_msg{ "" };
	int skin_id1{ 0 };
	int skin_id2{ 0 };
	std::string skin_name{ "" };
};

struct champion_skin {
	int champion_id{ 0 };
	std::string champion_name{ "" };
	std::string rarity{ "" };
	std::string ret_msg{ "" };
	int skin_id1{ 0 };
	int skin_id2{ 0 };
	std::string skin_name{ "" };
	std::string skin_name_english{ "" };
};

struct god_recommended_item {
	std::string Category{ "" };
	std::string Item{ "" };
	std::string Role{ "" };
	int category_value_id{ 0 };
	int god_id{ 0 };
	std::string god_name{ "" };
	int icon_id{ 0 };
	int item_id{ 0 };
	std::string ret_msg{ "" };
	int role_value_id{ 0 };
};

struct item_pal {
	std::string Description{ "" };
	std::string DeviceName{ "" };
	int IconId{ 0 };
	int ItemId{ 0 };
	int Price{ 0 };
	std::string ShortDesc{ "" };
	int champion_id{ 0 };
	std::string itemIcon_URL{ "" };
	std::string item_type{ "" };
	std::string ret_msg{ "" };
	int talent_reward_level{ 0 };
};

struct item_menu_item {
	std::string Description{ "" };
	std::string Value{ "" };
};

struct item_item_description {
	std::string Description{ "" };
	std::vector<item_menu_item> Menuitems{};
	std::string SecondaryDescription{ "" };
};

struct item_smi {
	int ChildItemId{ 0 };
	std::string DeviceName{ "" };
	int IconId{ 0 };
	item_item_description ItemDescription{};
	int ItemId{ 0 };
	int ItemTier{ 0 };
	int Price{ 0 };
	int RootItemId{ 0 };
	std::string ShortDesc{ "" };
	bool StartingItem{};
	std::string Type{ "" };
	std::string itemIcon_URL{ "" };
	std::string ret_msg{ "" };
};

struct match_details_pal {
	int Account_Level{ 0 };
	int ActiveId1{ 0 };
	int ActiveId2{ 0 };
	int ActiveId3{ 0 };
	int ActiveId4{ 0 };
	int ActiveLevel1{ 0 };
	int ActiveLevel2{ 0 };
	int ActiveLevel3{ 0 };
	int ActiveLevel4{ 0 };
	int Assists{ 0 };
	int BanId1{ 0 };
	int BanId2{ 0 };
	int BanId3{ 0 };
	int BanId4{ 0 };
	std::string Ban_1{ "" };
	std::string Ban_2{ "" };
	std::string Ban_3{ "" };
	std::string Ban_4{ "" };
	int Camps_Cleared{ 0 };
	int ChampionId{ 0 };
	int Damage_Bot{ 0 };
	int Damage_Done_In_Hand{ 0 };
	int Damage_Done_Magical{ 0 };
	int Damage_Done_Physical{ 0 };
	int Damage_Mitigated{ 0 };
	int Damage_Player{ 0 };
	int Damage_Taken{ 0 };
	int Damage_Taken_Magical{ 0 };
	int Damage_Taken_Physical{ 0 };
	int Deaths{ 0 };
	int Distance_Traveled{ 0 };
	date::sys_seconds Entry_Datetime{};
	int Final_Match_Level{ 0 };
	int Gold_Earned{ 0 };
	int Gold_Per_Minute{ 0 };
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
	std::string Item_Active_1{ "" };
	std::string Item_Active_2{ "" };
	std::string Item_Active_3{ "" };
	std::string Item_Active_4{ "" };
	std::string Item_Purch_1{ "" };
	std::string Item_Purch_2{ "" };
	std::string Item_Purch_3{ "" };
	std::string Item_Purch_4{ "" };
	std::string Item_Purch_5{ "" };
	std::string Item_Purch_6{ "" };
	int Killing_Spree{ 0 };
	int Kills_Bot{ 0 };
	int Kills_Double{ 0 };
	int Kills_Fire_Giant{ 0 };
	int Kills_First_Blood{ 0 };
	int Kills_Gold_Fury{ 0 };
	int Kills_Penta{ 0 };
	int Kills_Phoenix{ 0 };
	int Kills_Player{ 0 };
	int Kills_Quadra{ 0 };
	int Kills_Siege_Juggernaut{ 0 };
	int Kills_Single{ 0 };
	int Kills_Triple{ 0 };
	int Kills_Wild_Juggernaut{ 0 };
	int League_Losses{ 0 };
	int League_Points{ 0 };
	int League_Tier{ 0 };
	int League_Wins{ 0 };
	std::string Map_Game{ "" };
	int Mastery_Level{ 0 };
	int Match{ 0 };
	int Minutes{ 0 };
	int Multi_kill_Max{ 0 };
	int Objective_Assists{ 0 };
	int PartyId{ 0 };
	int Rank_Stat_League{ 0 };
	std::string Reference_Name{ "" };
	std::string Region{ "" };
	std::string Skin{ "" };
	int SkinId{ 0 };
	int Structure_Damage{ 0 };
	int Surrendered{ 0 };
	int TaskForce{ 0 };
	int Team1Score{ 0 };
	int Team2Score{ 0 };
	int TeamId{ 0 };
	std::string Team_Name{ "" };
	int Time_In_Match_Seconds{ 0 };
	int Towers_Destroyed{ 0 };
	int Wards_Placed{ 0 };
	std::string Win_Status{ "" };
	int Winning_TaskForce{ 0 };
	bool hasReplay{};
	queue_pal_e match_queue_id{};
	std::string name{ "" };
	int playerId{ 0 };
	std::string playerName{ "" };
	std::string ret_msg{ "" };
};

struct match_details_smi {
	int Account_Level{ 0 };
	int ActiveId1{ 0 };
	int ActiveId2{ 0 };
	int ActiveId3{ 0 };
	int ActiveId4{ 0 };
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
	int Camps_Cleared{ 0 };
	int Conquest_Losses{ 0 };
	int Conquest_Points{ 0 };
	int Conquest_Tier{ 0 };
	int Conquest_Wins{ 0 };
	int Damage_Bot{ 0 };
	int Damage_Done_In_Hand{ 0 };
	int Damage_Done_Magical{ 0 };
	int Damage_Done_Physical{ 0 };
	int Damage_Mitigated{ 0 };
	int Damage_Player{ 0 };
	int Damage_Taken{ 0 };
	int Damage_Taken_Magical{ 0 };
	int Damage_Taken_Physical{ 0 };
	int Deaths{ 0 };
	int Distance_Traveled{ 0 };
	int Duel_Losses{ 0 };
	int Duel_Points{ 0 };
	int Duel_Tier{ 0 };
	int Duel_Wins{ 0 };
	date::sys_seconds Entry_Datetime{};
	int Final_Match_Level{ 0 };
	std::string First_Ban_Side{ "" };
	int GodId{ 0 };
	int Gold_Earned{ 0 };
	int Gold_Per_Minute{ 0 };
	int Healing{ 0 };
	int Healing_Bot{ 0 };
	int Healing_Player_Self{ 0 };
	int ItemId1{ 0 };
	int ItemId2{ 0 };
	int ItemId3{ 0 };
	int ItemId4{ 0 };
	int ItemId5{ 0 };
	int ItemId6{ 0 };
	std::string Item_Active_1{ "" };
	std::string Item_Active_2{ "" };
	std::string Item_Active_3{ "" };
	std::string Item_Active_4{ "" };
	std::string Item_Purch_1{ "" };
	std::string Item_Purch_2{ "" };
	std::string Item_Purch_3{ "" };
	std::string Item_Purch_4{ "" };
	std::string Item_Purch_5{ "" };
	std::string Item_Purch_6{ "" };
	int Joust_Losses{ 0 };
	int Joust_Points{ 0 };
	int Joust_Tier{ 0 };
	int Joust_Wins{ 0 };
	int Killing_Spree{ 0 };
	int Kills_Bot{ 0 };
	int Kills_Double{ 0 };
	int Kills_Fire_Giant{ 0 };
	int Kills_First_Blood{ 0 };
	int Kills_Gold_Fury{ 0 };
	int Kills_Penta{ 0 };
	int Kills_Phoenix{ 0 };
	int Kills_Player{ 0 };
	int Kills_Quadra{ 0 };
	int Kills_Siege_Juggernaut{ 0 };
	int Kills_Single{ 0 };
	int Kills_Triple{ 0 };
	int Kills_Wild_Juggernaut{ 0 };
	std::string Map_Game{ "" };
	int Mastery_Level{ 0 };
	int Match{ 0 };
	int Minutes{ 0 };
	int Multi_kill_Max{ 0 };
	int Objective_Assists{ 0 };
	int PartyId{ 0 };
	int Rank_Stat_Conquest{ 0 };
	int Rank_Stat_Duel{ 0 };
	int Rank_Stat_Joust{ 0 };
	std::string Reference_Name{ "" };
	std::string Region{ "" };
	std::string Skin{ "" };
	int SkinId{ 0 };
	int Structure_Damage{ 0 };
	int Surrendered{ 0 };
	int TaskForce{ 0 };
	int Team1Score{ 0 };
	int Team2Score{ 0 };
	int TeamId{ 0 };
	std::string Team_Name{ "" };
	int Time_In_Match_Seconds{ 0 };
	int Towers_Destroyed{ 0 };
	int Wards_Placed{ 0 };
	std::string Win_Status{ "" };
	int Winning_TaskForce{ 0 };
	bool hasReplay{};
	queue_smi_e match_queue_id{};
	std::string name{ "" };
	int playerId{ 0 };
	std::string playerName{ "" };
	std::string ret_msg{ "" };
};

struct match_id {
	bool Active_Flag{};
	int Match{ 0 };
	std::string ret_msg{ "" };
};
} // namespace rez
