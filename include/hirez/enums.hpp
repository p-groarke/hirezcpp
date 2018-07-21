#pragma once

namespace rez {
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
	none = 0,
};

enum class tier_e : int {
	bronze_5 = 1,
	bronze_4 = 2,
	bronze_3 = 3,
	bronze_2 = 4,
	bronze_1 = 5,
	silver_5 = 6,
	silver_4 = 7,
	silver_3 = 8,
	silver_2 = 9,
	silver_1 = 10,
	gold_5 = 11,
	gold_4 = 12,
	gold_3 = 13,
	gold_2 = 14,
	gold_1 = 15,
	platinum_5 = 16,
	platinum_4 = 17,
	platinum_3 = 18,
	platinum_2 = 19,
	platinum_1 = 20,
	diamond_5 = 21,
	diamond_4 = 22,
	diamond_3 = 23,
	diamond_2 = 24,
	diamond_1 = 25,
	masters_1 = 26,
	grandmaster = 27,
	none = 0,
};

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

namespace detail {
template <game_e T>
struct queue_trait {
	using type = queue_smi_e;
};
template <>
struct queue_trait<rez::game_e::smite_pc> {
	using type = queue_smi_e;
};
template <>
struct queue_trait<rez::game_e::smite_ps4> {
	using type = queue_smi_e;
};
template <>
struct queue_trait<rez::game_e::smite_xbox> {
	using type = queue_smi_e;
};
template <>
struct queue_trait<rez::game_e::paladins_pc> {
	using type = queue_pal_e;
};
template <>
struct queue_trait<rez::game_e::paladins_ps4> {
	using type = queue_pal_e;
};
template <>
struct queue_trait<rez::game_e::paladins_xbox> {
	using type = queue_pal_e;
};
template <game_e T>
using queue_t = typename queue_trait<T>::type;
} // namespace detail
} // namespace rez
