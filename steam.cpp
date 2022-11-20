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
    long achgenhelp = 25;
    long achhidcheat = 20;
    long achhidedge = 21;
    long achhidmark = 22;
    long achhidright = 23;
    long achhidalive = 24;
    long achcumdead1 = 4;
    long achcumdead10 = 5;
    long achcumdead100 = 6;
    long achcumdead1000 = 7;
    long achcumfour1 = 8;
    long achcumfour10 = 9;
    long achcumfour100 = 10;
    long achcumfour1000 = 11;
    long achcumline100 = 12;
    long achcumline300 = 13;
    long achcumline600 = 14;
    long achcumline1000 = 15;
    long achcumtotal10 = 16;
    long achcumtotal100 = 17;
    long achcumtotal1000 = 18;
    long achcumtotal10000 = 19;
    const char* achstr[100] =
    {
        "GEN_CUSTOM", "GEN_MODE", "GEN_PAUSE", "CUM_DEAD_1", "CUM_DEAD_10",
        "CUM_DEAD_100", "CUM_DEAD_1000", "CUM_FOUR_1", "CUM_FOUR_10",
        "CUM_FOUR_100", "CUM_FOUR_1000", "CUM_LINE_100", "CUM_LINE_300",
        "CUM_LINE_600", "CUM_LINE_1000", "CUM_TOTAL_10", "CUM_TOTAL_100",
        "CUM_TOTAL_1000", "CUM_TOTAL_10000", "HID_CHEAT", "HID_EDGE",
        "HID_MARK", "HID_RIGHT", "HID_ALIVE", "GEN_HELP"
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
    void loadachievement();
    void addachievement(long achid);
    void delachievement(long achid);
    void loadscore();
    void savescore();

};

Steam::Steam()
{
    initsteam();
}

Steam::~Steam()
{
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
        msgbox("Steam initialize failed!", NULL, MB_ICONWARNING);
    }
}

void Steam::exitsteam()
{
    if (steamb)
    {
        SteamAPI_Shutdown();
    }
}

void Steam::loadachievement()
{
    for (long achid = 0; achid < achn; achid++)
    {
        achb[achid] = false;
    }
}

void Steam::addachievement(long achid)
{
    if (steamb)
    {
        if (!achb[achid])
        {
            SteamUserStats()->IndicateAchievementProgress(achstr[achid], 0, 0);
            SteamUserStats()->SetAchievement(achstr[achid]);
        }
    }
}

void Steam::delachievement(long achid)
{
    if (steamb)
    {
        if (achb[achid])
        {
            SteamUserStats()->ClearAchievement(achstr[achid]);
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