#include "steam/steam_api.h"

class Steam
{

public:

    const long appid = 2204230;
    bool steamb;

    const long achn = 26;
    long achgenstart = 0;
    long achgencustom = 1;
    long achgenmode = 2;
    long achgenpause = 3;
    long achgenhelp = 4;
    long achcumdead1 = 5;
    long achcumdead10 = 6;
    long achcumdead100 = 7;
    long achcumdead1000 = 8;
    long achcumfour1 = 9;
    long achcumfour10 = 10;
    long achcumfour100 = 11;
    long achcumfour1000 = 12;
    long achcumline100 = 13;
    long achcumline300 = 14;
    long achcumline600 = 15;
    long achcumline1000 = 16;
    long achcumtotal10 = 17;
    long achcumtotal100 = 18;
    long achcumtotal1000 = 19;
    long achcumtotal10000 = 20;
    long achhidcheat = 21;
    long achhidedge = 22;
    long achhidmark = 23;
    long achhidright = 24;
    long achhidalive = 25;
    const char* achstr[100] =
    {
        "GEN_START", "GEN_CUSTOM", "GEN_MODE", "GEN_PAUSE", "GEN_HELP",
        "CUM_DEAD_1", "CUM_DEAD_10", "CUM_DEAD_100", "CUM_DEAD_1000",
        "CUM_FOUR_1", "CUM_FOUR_10", "CUM_FOUR_100", "CUM_FOUR_1000",
        "CUM_LINE_100", "CUM_LINE_300", "CUM_LINE_600", "CUM_LINE_1000",
        "CUM_TOTAL_10", "CUM_TOTAL_100", "CUM_TOTAL_1000", "CUM_TOTAL_10000",
        "HID_CHEAT", "HID_EDGE", "HID_MARK", "HID_RIGHT", "HID_ALIVE"
    };
    bool achb[100];

    long scoredead = 0;
    long scorefour = 0;
    long scoreline1 = 0;
    long scoreline2 = 0;
    long scoreline3 = 0;
    long scoretotal = 0;


    Steam();
    ~Steam();
    void initsteam();
    void exitsteam();
    void loadach();
    void addach(long achid);
    void delach(long achid);
    void loadscore();
    void savescore();

};

Steam::Steam()
{
    initsteam();
}

Steam::~Steam()
{
    SteamUserStats()->ResetAllStats(true);
    exitsteam();
}

void Steam::initsteam()
{
    if (SteamAPI_RestartAppIfNecessary(appid))
    {
        msgbox("Please launch MineSwepper Tetris from Steam!", "MineSwepper Tetris", MB_ICONINFORMATION);
    }
    steamb = SteamAPI_Init();
    if (!steamb)
    {
        msgbox("Steam initialize failed!", "MineSwepper Tetris", MB_ICONWARNING);
    }
    if (!SteamUserStats()->RequestCurrentStats())
    {
        msgbox("Steam current user status load failed!", "MineSwepper Tetris", MB_ICONWARNING);
    }
    loadach();
}

void Steam::exitsteam()
{
    if (steamb)
    {
        SteamAPI_Shutdown();
    }
}

void Steam::loadach()
{
    if (steamb)
    {
        for (long achid = 0; achid < achn; achid++)
        {
            SteamUserStats()->GetAchievement(achstr[achid], &achb[achid]);
        }
    }
}

void Steam::addach(long achid)
{
    if (steamb)
    {
        if (!achb[achid])
        {
            SteamUserStats()->IndicateAchievementProgress(achstr[achid], 0, 0);
            SteamUserStats()->SetAchievement(achstr[achid]);
            SteamUserStats()->StoreStats();
            achb[achid] = true;
        }
    }
}

void Steam::delach(long achid)
{
    if (steamb)
    {
        if (achb[achid])
        {
            SteamUserStats()->ClearAchievement(achstr[achid]);
            SteamUserStats()->StoreStats();
            achb[achid] = false;
        }
    }
}

void Steam::loadscore()
{
    if (steamb)
    {
        long scoredead = 0;
        long scorefour = 0;
        long scoreline1 = 0;
        long scoreline2 = 0;
        long scoreline3 = 0;
        long scoretotal = 0;
    }
}

void Steam::savescore()
{
    if (steamb)
    {
    }
}