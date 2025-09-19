#pragma once
#include "steam/steam_api.h"
#include "disp.h"
#include "lan.h"

class Steam
{

public:

    Lan lan;

    const unsigned long appid = 3665840;
    bool steamb;
    bool cheatb = false;

    static const long achn = 26;
    long achgenstart = 0;
    long achgencustom = 1;
    long achgenmode = 2;
    long achgenpause = 3;
    long achgenhelp = 4;
    long achhidcheat = 5;
    long achhidedge = 6;
    long achhidmark = 7;
    long achhidright = 8;
    long achhidalive = 9;
    long achcumdead1 = 10;
    long achcumdead10 = 11;
    long achcumdead100 = 12;
    long achcumdead1000 = 13;
    long achcumfour1 = 14;
    long achcumfour10 = 15;
    long achcumfour100 = 16;
    long achcumfour1000 = 17;
    long achcumline100 = 18;
    long achcumline300 = 19;
    long achcumline600 = 20;
    long achcumline1000 = 21;
    long achcumtotal10 = 22;
    long achcumtotal100 = 23;
    long achcumtotal1000 = 24;
    long achcumtotal10000 = 25;
    const char* achs[achn] =
    {
        "GEN_START", "GEN_CUSTOM", "GEN_MODE", "GEN_PAUSE", "GEN_HELP",
        "HID_CHEAT", "HID_EDGE", "HID_MARK", "HID_RIGHT", "HID_ALIVE",
        "CUM_DEAD_1", "CUM_DEAD_10", "CUM_DEAD_100", "CUM_DEAD_1000",
        "CUM_FOUR_1", "CUM_FOUR_10", "CUM_FOUR_100", "CUM_FOUR_1000",
        "CUM_LINE_100", "CUM_LINE_300", "CUM_LINE_600", "CUM_LINE_1000",
        "CUM_TOTAL_10", "CUM_TOTAL_100", "CUM_TOTAL_1000", "CUM_TOTAL_10000"
    };
    bool achb[achn];

    static const long scrn = 19;
    long scrdead = 0;
    long scrfour = 1;
    long scrtotal = 2;
    long scrline = 3;
    long scrline1 = 4;
    long scrline2 = 5;
    long scrline3 = 6;
    long scrindexline = 0;
    long scrindexmdb = 3;
    long scrindexnomiss = 6;
    long scrindextetris = 9;
    long scrindexmiss = 12;
    const char* scrs[scrn] =
    {
        "STAT_DEAD", "STAT_FOUR", "STAT_TOTAL", "STAT_LINE",
        "STAT_LINE1", "STAT_LINE2", "STAT_LINE3",
        "STAT_LINE1_N", "STAT_LINE2_N", "STAT_LINE3_N",
        "STAT_LINE1_D", "STAT_LINE2_D", "STAT_LINE3_D",
        "STAT_LINE1_T", "STAT_LINE2_T", "STAT_LINE3_T",
        "STAT_LINE1_M", "STAT_LINE2_M", "STAT_LINE3_M"
    };
    long scr[scrn];
    bool newrecord = false;

    static const long leadn = 15;
    const char* leads[leadn] =
    {
        "1_TOP", "2_TOP", "3_TOP",
        "1_TOP_N", "2_TOP_N", "3_TOP_N",
        "1_TOP_D", "2_TOP_D", "3_TOP_D",
        "1_TOP_T", "2_TOP_T", "3_TOP_T",
        "1_TOP_M", "2_TOP_M", "3_TOP_M"
    };
    long leadk_[3] = {20, 15, 1};
    SteamAPICall_t lead[leadn];
    SteamAPICall_t lead_[3][leadn];
    LeaderboardFindResult_t leadr;
    LeaderboardScoreUploaded_t leadu;
    LeaderboardScoresDownloaded_t leadd;
    SteamLeaderboard_t leadb[leadn];
    SteamLeaderboardEntries_t leaden[3][leadn];;
    bool leadfailed = true;
    //LeaderboardEntry_t leadsn[3][leadn][20];
    LeaderboardEntry_t(*leadsn)[leadn][20] = nullptr;
    double waittime = 5;

    Steam();
    ~Steam();
    void initsteam();
    void loadlan();
    void exitsteam();
    void loadsteam();

    void resetach();
    void loadach();
    void addach(long achid);
    void checkach(long scrid, long d, long c, long b, long a, long a_d, long a_c, long a_b, long a_a);

    void loadscr();
    void setscr(long scrid);
    void addscr(long scrid, long val, long mode);
    void maxscr(long val, long scrline__);
    void compscr(long val, long mode, long index);
    void resetscr();

    void loadlead();
    void getlead();
    void setlead(long mode);
    void setlead();
    bool waitlead();
    bool waitlead_();

    void savescr(char* scrpath);

    bool ischeat(long line, long tetris);
    bool ischeat();
    void checkcheat();

};