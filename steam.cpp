#include "steam/steam_api.h"

class Steam
{

public:

    const long appid = 2204230;
    bool steamb;
    bool cheatb = false;

    const long achn = 26;
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
    long achcumtotal10 = 18;
    long achcumtotal100 = 19;
    long achcumtotal1000 = 20;
    long achcumtotal10000 = 21;
    long achcumline100 = 22;
    long achcumline300 = 23;
    long achcumline600 = 24;
    long achcumline1000 = 25;
    const char* achs[100] =
    {
        "GEN_START", "GEN_CUSTOM", "GEN_MODE", "GEN_PAUSE", "GEN_HELP",
        "HID_CHEAT", "HID_EDGE", "HID_MARK", "HID_RIGHT", "HID_ALIVE",
        "CUM_DEAD_1", "CUM_DEAD_10", "CUM_DEAD_100", "CUM_DEAD_1000",
        "CUM_FOUR_1", "CUM_FOUR_10", "CUM_FOUR_100", "CUM_FOUR_1000",
        "CUM_TOTAL_10", "CUM_TOTAL_100", "CUM_TOTAL_1000", "CUM_TOTAL_10000",
        "CUM_LINE_100", "CUM_LINE_300", "CUM_LINE_600", "CUM_LINE_1000"
    };
    bool achb[100];

    const long scrn = 7;
    long scrdead = 0;
    long scrfour = 1;
    long scrtotal = 2;
    long scrline = 3;
    long scrline1 = 4;
    long scrline2 = 5;
    long scrline3 = 6;
    const char* scrs[10] =
    {
        "dead", "four", "total", "line", "line1", "line2", "line3"
    };
    long scr[100];

    Steam();
    ~Steam();
    void initsteam();
    void exitsteam();
    void loadach();
    void addach(long achid);
    void checkach(long scrid, long d, long c, long b, long a, long a_d, long a_c, long a_b, long a_a);
    void loadscr();
    void addscr(long scrid, long val, long mode);

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
        msgbox("Steam initialize failed!", "MineSwepper Tetris", MB_ICONWARNING);
    }
    if (steamb)
    {
        if (!SteamUserStats()->RequestCurrentStats())
        {
            msgbox("Steam current user status load failed!", "MineSwepper Tetris", MB_ICONWARNING);
        }
        else
        {
            loadach();
            loadscr();
        }
    }
}

void Steam::exitsteam()
{
    if (steamb)
    {
        SteamUserStats()->ResetAllStats(true);
        SteamAPI_Shutdown();
    }
}

void Steam::loadach()
{
    if (steamb)
    {
        for (long achid = 0; achid < achn; achid++)
        {
            SteamUserStats()->GetAchievement(achs[achid], &achb[achid]);
        }
    }
}

void Steam::addach(long achid)
{
    if (steamb)
    {
        if (!achb[achid] && (!cheatb || achid == achhidcheat))
        {
            printf(achs[achid]);
            printf("%d \n",achid);
            SteamUserStats()->SetAchievement(achs[achid]);
            SteamUserStats()->StoreStats();
            achb[achid] = true;
        }
    }
}

void Steam::checkach(long scrid, long d, long c, long b, long a, long a_d, long a_c, long a_b, long a_a)
{
    if (scr[scrid] >= d)
    {
        addach(a_d);
    }
    else if (scr[scrid] >= c)
    {
        addach(a_c);
    }
    else if (scr[scrid] >= b)
    {
        addach(a_b);
    }
    else if (scr[scrid] >= a)
    {
        addach(a_a);
    }
}

void Steam::loadscr()
{
    if (steamb)
    {
        for (long scrid = 0; scrid < scrn; scrid++)
        {
            SteamUserStats()->GetStat(scrs[scrid], (int*)&scr[scrid]);
        }
    }
}

void Steam::addscr(long scrid, long val, long mode)
{
    if (steamb)
    {
        if (!cheatb && mode > 0)
        {
            scr[scrid] += val;
            SteamUserStats()->SetStat(scrs[scrid], (int)scr[scrid]);
            SteamUserStats()->StoreStats();
            if (scrid == scrdead)
            {
                checkach(scrdead, 1000, 100, 10, 1, achcumdead1000, achcumdead100, achcumdead10, achcumdead1);
            }
            else if (scrid == scrfour)
            {
                checkach(scrfour, 1000, 100, 10, 1, achcumdead1000, achcumfour100, achcumfour10, achcumfour1);
            }
            else if (scrid == scrtotal)
            {
                checkach(scrtotal, 10000, 1000, 100, 10, achcumtotal10000, achcumtotal1000, achcumtotal100, achcumtotal10);
            }
        }
    }
}
