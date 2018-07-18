#include <codecvt>
#include <cstdio>
#include <gtest/gtest.h>
#include <hirez/hirez.hpp>
#include <locale>
#include <string>

namespace {
inline std::wstring to_wstring(const std::string& str) {
	static std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	return converter.from_bytes(str);
}
inline std::string to_string(const std::wstring& str) {
	static std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	return converter.to_bytes(str);
}
inline std::string dev_id;
inline std::string auth_key;

// TEST(all_apis, create_session) {
//	{
//		rez::session sesh{ dev_id, auth_key };
//		EXPECT_EQ(sesh.dev_id, dev_id);
//		EXPECT_EQ(sesh.auth_key, auth_key);
//
//		rez::session_info createsesh_result = sesh.createsession();
//		size_t f = createsesh_result.ret_msg.find("Approved");
//		EXPECT_NE(f, std::string::npos);
//		EXPECT_NE(createsesh_result.timestamp, date::sys_seconds{});
//		nlohmann::json j = createsesh_result;
//		printf("createsession response : %s\n\n", j.dump(4).c_str());
//	}
//
//	{
//		rez::session<rez::game_e::smite_pc> sesh{ dev_id, auth_key };
//		EXPECT_EQ(sesh.dev_id, dev_id);
//		EXPECT_EQ(sesh.auth_key, auth_key);
//
//		rez::session_info createsesh_result = sesh.createsession();
//		size_t f = createsesh_result.ret_msg.find("Approved");
//		EXPECT_NE(f, std::string::npos);
//		EXPECT_NE(createsesh_result.timestamp, date::sys_seconds{});
//		nlohmann::json j = createsesh_result;
//		printf("createsession response : %s\n\n", j.dump(4).c_str());
//	}
//}

TEST(paladins_pc, everything) {
	std::string str{};
	size_t f{};
	nlohmann::json j{};

	rez::session sesh{ dev_id, auth_key };
	EXPECT_EQ(sesh.dev_id, dev_id);
	EXPECT_EQ(sesh.auth_key, auth_key);

	// str = sesh.ping();
	// f = str.find("Ping successful.");
	// EXPECT_NE(f, std::string::npos);
	// printf("ping response : %s\n\n", str.c_str());

	// str = sesh.testsession();
	// f = str.find(
	//		"This was a successful test with the following parameters added:");
	// EXPECT_NE(f, std::string::npos);
	// printf("testsession response : %s\n\n", str.c_str());

	// std::vector<rez::server_status> server_stats =
	// sesh.gethirezserverstatus(); ASSERT_GT(server_stats.size(), 0);
	// EXPECT_EQ(server_stats[0].status, "UP");
	// EXPECT_NE(server_stats[0].entry_datetime, date::sys_seconds{});
	// j = server_stats;
	// printf("getserverstatus response : %s\n\n", j.dump(4).c_str());

	// std::vector<rez::data_used> dus = sesh.getdataused();
	// EXPECT_GT(dus.size(), 0);
	// j = dus;
	// printf("getdataused response : %s\n\n", j.dump(4).c_str());

	// std::vector<rez::match_history_pal> mhs =
	// sesh.getmatchhistory("socapex"); EXPECT_GT(mhs.size(), 0);
	// EXPECT_EQ(mhs[0].playerName, "socapex");
	// EXPECT_NE(mhs[0].Match_Time, date::sys_seconds{});
	// j = mhs.back();
	// printf("getmatchhistory response : %s\n\n", j.dump(4).c_str());

	// std::vector<rez::demo_details_pal> dds =
	// sesh.getdemodetails(mhs[0].Match); EXPECT_GT(dds.size(), 0);
	// EXPECT_EQ(dds[0].Match, mhs[0].Match);
	// EXPECT_NE(dds[0].Entry_Datetime, date::sys_seconds{});
	// j = dds[0];
	// printf("getdemodetails response : %s\n\n", j.dump(4).c_str());

	// std::vector<rez::esports_pro_league_details> eplds
	//		= sesh.getesportsproleaguedetails();
	// EXPECT_GT(eplds.size(), 0);
	// EXPECT_NE(eplds[0].match_date, date::sys_seconds{});
	// j = eplds[0];
	// printf("getesportsproleaguedetails response : %s\n\n",
	// j.dump(4).c_str());

	// std::vector<rez::friends> fs = sesh.getfriends("socapex");
	// EXPECT_GT(fs.size(), 0);
	// j = fs[0];
	// printf("getfriends response : %s\n\n", j.dump(4).c_str());

	// std::vector<rez::champion_rank> crs = sesh.getchampionranks("socapex");
	// EXPECT_GT(crs.size(), 0);
	// EXPECT_NE(crs[0].LastPlayed, date::sys_seconds{});
	// j = crs[0];
	// printf("getchampionranks response : %s\n\n", j.dump(4).c_str());

	// std::vector<rez::champion> cs =
	// sesh.getchampions(rez::language_e::english); EXPECT_GT(cs.size(), 0); j =
	// cs[0]; printf("getchampions response : %s\n\n", j.dump(4).c_str());

	// std::vector<rez::champion_skin> chss = sesh.getchampionskins(
	//		crs[0].champion_id, rez::language_e::english);
	// EXPECT_GT(chss.size(), 0);
	// j = chss[0];
	// printf("getchampionskins response : %s\n\n", j.dump(4).c_str());

	// str = sesh.getchampionrecommendeditems(
	//		crs[0].champion_id, rez::language_e::english);
	// printf("getchampionrecommendeditems response : %s\n\n", str.c_str());

	// std::vector<rez::item_pal> ips = sesh.getitems(rez::language_e::english);
	// EXPECT_GT(ips.size(), 0);
	// j = ips[0];
	// printf("getitems response : %s\n\n", j.dump(4).c_str());

	// std::vector<rez::match_details_pal> mdps
	//		= sesh.getmatchdetails(mhs.back().Match);
	// EXPECT_GT(mdps.size(), 0);
	// j = mdps[0];
	// printf("getmatchdetails response : %s\n\n", j.dump(4).c_str());

	// size_t num_batch = std::min(mhs.size(), size_t{ 20 });
	// std::vector<int> match_ids(num_batch);
	// std::transform(mhs.end() - num_batch, mhs.end(), match_ids.begin(),
	//		[](const rez::match_history_pal& mh) { return mh.Match; });

	// std::vector<std::vector<rez::match_details_pal>> mdbs
	//		= sesh.getmatchdetailsbatch(match_ids);
	// EXPECT_GT(mdbs.size(), 0);
	// EXPECT_GT(mdbs.front().size(), 0);
	// for (const auto& v1 : mdbs) {
	//	int id = v1.front().Match;
	//	for (const auto& v2 : v1) {
	//		EXPECT_EQ(v2.Match, id);
	//	}
	//}
	// j = mdbs.back();
	// printf("getmatchdetailsbatch response : %s\n\n", j.dump(4).c_str());

	// date::year_month_day ymd
	//		= date::floor<date::days>(std::chrono::system_clock::now());
	// std::vector<rez::match_id> mids
	//		= sesh.getmatchidsbyqueue(rez::queue_pal_e::live_casual, ymd, 0, 0);
	// EXPECT_GT(mids.size(), 0);
	// j = mids.back();
	// printf("getmatchidsbyqueue response : %s\n\n", j.dump(4).c_str());
}

TEST(smite_pc, everything) {
	const char* player = "Rowe";
	std::string str{};
	size_t f{};
	nlohmann::json j{};

	rez::session<rez::game_e::smite_pc> sesh{ dev_id, auth_key };
	EXPECT_EQ(sesh.dev_id, dev_id);
	EXPECT_EQ(sesh.auth_key, auth_key);

	// str = sesh.ping();
	// f = str.find("Ping successful.");
	// EXPECT_NE(f, std::string::npos);
	// printf("ping response : %s\n\n", str.c_str());

	// str = sesh.testsession();
	// f = str.find(
	//		"This was a successful test with the following parameters added:");
	// EXPECT_NE(f, std::string::npos);
	// printf("testsession response : %s\n\n", str.c_str());

	// std::vector<rez::server_status> server_stats =
	// sesh.gethirezserverstatus(); ASSERT_GT(server_stats.size(), 0);
	// EXPECT_EQ(server_stats[0].status, "UP");
	// EXPECT_NE(server_stats[0].entry_datetime, date::sys_seconds{});
	// j = server_stats;
	// printf("getserverstatus response : %s\n\n", j.dump(4).c_str());

	// std::vector<rez::data_used> dus = sesh.getdataused();
	// EXPECT_GT(dus.size(), 0);
	// j = dus;
	// printf("getdataused response : %s\n\n", j.dump(4).c_str());

	// std::vector<rez::match_history_smi> mhs = sesh.getmatchhistory(player);
	// EXPECT_GT(mhs.size(), 0);
	// EXPECT_STREQ(mhs[0].playerName.c_str(), player);
	// EXPECT_NE(mhs[0].Match_Time, date::sys_seconds{});
	// j = mhs.back();
	// printf("getmatchhistory response : %s\n\n", j.dump(4).c_str());

	// std::vector<rez::demo_details_smi> dds =
	// sesh.getdemodetails(mhs[0].Match); EXPECT_GT(dds.size(), 0);
	// EXPECT_EQ(dds[0].Match, mhs[0].Match);
	// EXPECT_NE(dds[0].Entry_Datetime, date::sys_seconds{});
	// j = dds[0];
	// printf("getdemodetails response : %s\n\n", j.dump(4).c_str());

	// std::vector<rez::esports_pro_league_details> eplds
	//		= sesh.getesportsproleaguedetails();
	// EXPECT_GT(eplds.size(), 0);
	// EXPECT_NE(eplds[0].match_date, date::sys_seconds{});
	// j = eplds[0];
	// printf("getesportsproleaguedetails response : %s\n\n",
	// j.dump(4).c_str());

	// std::vector<rez::friends> fs = sesh.getfriends(player);
	// EXPECT_GT(fs.size(), 0);
	// j = fs[0];
	// printf("getfriends response : %s\n\n", j.dump(4).c_str());

	// std::vector<rez::god_rank> grs = sesh.getgodranks(player);
	// EXPECT_GT(grs.size(), 0);
	// j = grs[0];
	// printf("getgodranks response : %s\n\n", j.dump(4).c_str());

	// std::vector<rez::god> gs = sesh.getgods(rez::language_e::english);
	// EXPECT_GT(gs.size(), 0);
	// j = gs[0];
	// printf("getgods response : %s\n\n", j.dump(4).c_str());

	// std::vector<rez::god_leaderboard> gls = sesh.getgodleaderboard(
	//		grs[0].god_id, rez::queue_smi_e::conquest_ranked);
	// EXPECT_GT(gls.size(), 0);
	// j = gls[0];
	// printf("getgodleaderboard response : %s\n\n", j.dump(4).c_str());

	// std::vector<rez::god_skin> gss
	//		= sesh.getgodskins(grs[0].god_id, rez::language_e::english);
	// EXPECT_GT(gss.size(), 0);
	// j = gss[0];
	// printf("getgodskins response : %s\n\n", j.dump(4).c_str());

	// std::vector<rez::god_recommended_item> gris =
	// sesh.getgodrecommendeditems( 		grs[0].god_id,
	// rez::language_e::english); EXPECT_GT(gris.size(), 0); j = gris[0];
	// printf("getgodrecommendeditems response : %s\n\n", j.dump(4).c_str());

	// std::vector<rez::item_smi> iss = sesh.getitems(rez::language_e::english);
	// EXPECT_GT(iss.size(), 0);
	// j = iss[0];
	// printf("getitems response : %s\n\n", j.dump(4).c_str());

	// std::vector<rez::match_details_smi> mdss
	//		= sesh.getmatchdetails(mhs.back().Match);
	// EXPECT_GT(mdss.size(), 0);
	// j = mdss.back();
	// printf("getmatchdetails response : %s\n\n", j.dump(4).c_str());

	// size_t num_batch = std::min(mhs.size(), size_t{ 20 });
	// std::vector<int> match_ids(num_batch);
	// std::transform(mhs.end() - num_batch, mhs.end(), match_ids.begin(),
	//		[](const rez::match_history_smi& mh) { return mh.Match; });

	// std::vector<std::vector<rez::match_details_smi>> mdbs
	//		= sesh.getmatchdetailsbatch(match_ids);
	// EXPECT_GT(mdbs.size(), 0);
	// EXPECT_GT(mdbs.front().size(), 0);
	// for (const auto& v1 : mdbs) {
	//	int id = v1.front().Match;
	//	for (const auto& v2 : v1) {
	//		EXPECT_EQ(v2.Match, id);
	//	}
	//}
	// j = mdbs.back();
	// printf("getmatchdetailsbatch response : %s\n\n", j.dump(4).c_str());

	// date::year_month_day ymd
	//		= date::floor<date::days>(std::chrono::system_clock::now());
	// std::vector<rez::match_id> mids
	//		= sesh.getmatchidsbyqueue(rez::queue_smi_e::arena, ymd, 0, 0);
	// EXPECT_GT(mids.size(), 0);
	// j = mids.back();
	// printf("getmatchidsbyqueue response : %s\n\n", j.dump(4).c_str());
}

// TEST(example, date) {
//	const char* parse_me = "05/28/2018 07:00:00 PM";
//	const char* date_format = "%m/%d/%Y %I:%M:%S %p";
//
//	std::istringstream iss{ parse_me };
//	date::sys_seconds s;
//	iss >> date::parse(date_format, s);
//
//	printf("parse result : %s\n", date::format(date_format, s).c_str());
//}
} // namespace

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);

	if (argc != 3) {
		fprintf(stderr, "Please provide [dev_id] [auth_key].\n");
		std::exit(0);
	}

	dev_id = { argv[1] };
	auth_key = { argv[2] };

	return RUN_ALL_TESTS();
}
