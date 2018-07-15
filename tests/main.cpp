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

TEST(connection, paladins_pc) {
	rez::session sesh{ dev_id, auth_key };
	EXPECT_EQ(sesh.dev_id, dev_id);
	EXPECT_EQ(sesh.auth_key, auth_key);

	std::string str = sesh.ping();
	size_t f = str.find("Ping successful.");
	EXPECT_NE(f, std::string::npos);
	printf("ping response : %s\n\n", str.c_str());

	rez::session_response createsesh_result = sesh.createsession();
	f = createsesh_result.ret_msg.find("Approved");
	EXPECT_NE(f, std::string::npos);
	nlohmann::json j = createsesh_result;
	printf("createsession response : %s\n\n", j.dump(4).c_str());

	str = sesh.testsession();
	f = str.find(
			"This was a successful test with the following parameters added:");
	EXPECT_NE(f, std::string::npos);
	printf("testsession response : %s\n\n", str.c_str());

	std::vector<rez::server_status> server_stats = sesh.gethirezserverstatus();
	ASSERT_GT(server_stats.size(), 0);
	EXPECT_EQ(server_stats[0].status, "UP");
	j = server_stats;
	printf("getserverstatus response : %s\n\n", j.dump(4).c_str());

	std::vector<rez::data_used> dus = sesh.getdataused();
	EXPECT_GT(dus.size(), 0);
	j = dus;
	printf("getdataused response : %s\n\n", j.dump(4).c_str());

	std::vector<rez::match_history> mhs = sesh.getmatchhistory("socapex");
	EXPECT_GT(mhs.size(), 0);
	EXPECT_EQ(mhs[0].playerName, "socapex");
	j = mhs[0];
	printf("getmatchhistory response : %s\n\n", j.dump(4).c_str());

	std::vector<rez::demo_details> dds = sesh.getdemodetails(mhs[0].Match);
	EXPECT_GT(dds.size(), 0);
	EXPECT_EQ(dds[0].Match, mhs[0].Match);
	j = dds[0];
	printf("getdemodetails response : %s\n\n", j.dump(4).c_str());

	std::vector<rez::esports_pro_league_details> eplds
			= sesh.getesportsproleaguedetails();
	EXPECT_GT(eplds.size(), 0);
	j = eplds[0];
	printf("getesportsproleaguedetails response : %s\n\n", j.dump(4).c_str());
}
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
