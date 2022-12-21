#include "steam/steam_api.h"

class Steam
{

public:

    Lan lan;

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
    long achcumline100 = 18;
    long achcumline300 = 19;
    long achcumline600 = 20;
    long achcumline1000 = 21;
    long achcumtotal100 = 22;
    long achcumtotal1000 = 23;
    long achcumtotal10000 = 24;
    long achcumtotal100000 = 25;
    const char* achs[26] =
    {
        "GEN_START", "GEN_CUSTOM", "GEN_MODE", "GEN_PAUSE", "GEN_HELP",
        "HID_CHEAT", "HID_EDGE", "HID_MARK", "HID_RIGHT", "HID_ALIVE",
        "CUM_DEAD_1", "CUM_DEAD_10", "CUM_DEAD_100", "CUM_DEAD_1000",
        "CUM_FOUR_1", "CUM_FOUR_10", "CUM_FOUR_100", "CUM_FOUR_1000",
        "CUM_LINE_100", "CUM_LINE_300", "CUM_LINE_600", "CUM_LINE_1000",
        "CUM_TOTAL_100", "CUM_TOTAL_1000", "CUM_TOTAL_10000", "CUM_TOTAL_100000"
    };
    bool achb[26];

    const long scrn = 7;
    long scrdead = 0;
    long scrfour = 1;
    long scrtotal = 2;
    long scrline = 3;
    long scrline1 = 4;
    long scrline2 = 5;
    long scrline3 = 6;
    const char* scrs[7] =
    {
        "STAT_DEAD", "STAT_FOUR", "STAT_TOTAL", "STAT_LINE", "STAT_LINE1", "STAT_LINE2", "STAT_LINE3"
    };
    int scr[7];
    bool newrecord = false;

    const long leadn = 3;
    const char* leads[3] =
    {
        "1_TOP", "2_TOP", "3_TOP"
    };
    SteamAPICall_t lead[3];
    SteamAPICall_t lead1[3];
    SteamAPICall_t lead2[3];
    SteamAPICall_t lead3[3];
    LeaderboardFindResult_t leadr[3];
    LeaderboardScoreUploaded_t leadu[3];
    LeaderboardScoresDownloaded_t leadd[3];
    SteamLeaderboard_t leadb[3];
    SteamLeaderboardEntries_t leadeg[3];
    SteamLeaderboardEntries_t leadeu[3];
    SteamLeaderboardEntries_t leadeu_[3];
    bool leadfailed = true;
    LeaderboardEntry_t leadsg[3][20];
    LeaderboardEntry_t leadsu[3][10];
    LeaderboardEntry_t leadsu_[3][1];
    double waittime = 5;

    Steam();
    ~Steam();
    void initsteam();
    void exitsteam();
    void loadsteam();

    void resetach();
    void loadach();
    void addach(long achid);
    void checkach(long scrid, long d, long c, long b, long a, long a_d, long a_c, long a_b, long a_a);

    void loadscr();
    void setscr(long scrid);
    void addscr(long scrid, long val, long mode);
    void compscr(long val, long mode);

    void loadlead();
    void getlead();
    void setlead(long val, long mode);
    bool waitlead(long leadid);
    bool waitlead();
    bool waitlead_();

    void savescr(char* scrpath);

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
        msgboxw(lan.getlan(lan.LAN_STEAM_LAUNCH), lan.getlan(lan.LAN_TITLE), MB_ICONINFORMATION);
    }
    steamb = SteamAPI_Init();
    if (!steamb)
    {
        msgboxw(lan.getlan(lan.LAN_STEAM_FAIL), lan.getlan(lan.LAN_TITLE), MB_ICONWARNING);
    }
    if (steamb)
    {
        if (SteamUtils()->GetAppID() != appid)
        {
            msgbox("This is the test version of MineSweeper Tetris, please download the  build version from Steam Store! \nhttps://store.steampowered.com/app/2204230", "MineSweeper Tetris", MB_ICONINFORMATION);
        }
        lan.initlan(SteamUtils()->GetSteamUILanguage());
        lan.initlan(SteamApps()->GetCurrentGameLanguage());
    }
}

void Steam::exitsteam()
{
    if (steamb)
    {
        SteamUserStats()->StoreStats();
        SteamAPI_Shutdown();
    }
}

void Steam::loadsteam()
{
    if (steamb)
    {
        if (!SteamUserStats()->RequestCurrentStats())
        {
            msgboxw(lan.getlan(lan.LAN_STEAM_Status), lan.getlan(lan.LAN_TITLE), MB_ICONWARNING);
        }
        else
        {
            loadach();
            loadscr();
            loadlead();
        }
    }
}

void Steam::resetach()
{
    if (steamb)
    {
        SteamUserStats()->ResetAllStats(true);
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
            SteamUserStats()->SetAchievement(achs[achid]);
            SteamUserStats()->StoreStats();
            achb[achid] = true;
        }
    }
}

void Steam::checkach(long scrid, long d, long c, long b, long a, long a_d, long a_c, long a_b, long a_a)
{
    if (steamb)
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
}

void Steam::loadscr()
{
    if (steamb)
    {
        for (long scrid = 0; scrid < scrn; scrid++)
        {
            SteamUserStats()->GetStat(scrs[scrid], (float*)&scr[scrid]);
        }
    }
}

void Steam::setscr(long scrid)
{
    if (steamb)
    {
        SteamUserStats()->SetStat(scrs[scrid], *(float*)&scr[scrid]);
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
            checkach(scrtotal, 100000, 10000, 1000, 100, achcumtotal100000, achcumtotal10000, achcumtotal1000, achcumtotal100);
        }
        else if (scrid == scrline)
        {
            checkach(scrline, 1000, 600, 300, 100, achcumline1000, achcumline600, achcumline300, achcumline100);
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
            setscr(scrid);
        }
    }
}

void Steam::compscr(long line, long mode)
{
    if (steamb)
    {
        if (!cheatb && mode > 0)
        {
            long scrline_ = -1;
            switch (mode)
            {
                case 1:
                    scrline_ = scrline1;
                    break;
                case 2:
                    scrline_ = scrline2;
                    break;
                case 3:
                    scrline_ = scrline3;
                    break;
            }
            if (scrline_ > 0)
            {
                if (line > scr[scrline_])
                {
                    scr[scrline_] = line;
                    scr[scrline] = max(scr[scrline], scr[scrline_]);
                    setscr(scrline_);
                    setscr(scrline);
                    newrecord = true;
                }
            }
        }
    }
}

void Steam::loadlead()
{
    if (steamb)
    {
        for (long leadid = 0; leadid < leadn; leadid++)
        {
            lead[leadid] = SteamUserStats()->FindLeaderboard(leads[leadid]);
        }
        if (waitlead())
        {
            for (long leadid = 0; leadid < leadn; leadid++)
            {
                SteamUtils()->GetAPICallResult(lead[leadid], &leadr[leadid], sizeof(leadr[leadid]), leadr[leadid].k_iCallback, &leadfailed);
                leadb[leadid] = leadr[leadid].m_hSteamLeaderboard;
            }
        }
    }
}

void Steam::getlead()
{
    if (steamb)
    {
        if (leadb[0] == 0 || leadb[1] == 0 || leadb[2] == 0)
        {
            loadlead();
        }
        for (long leadid = 0; leadid < leadn; leadid++)
        {
            if (leadb[leadid] != 0)
            {
                lead1[leadid] = SteamUserStats()->DownloadLeaderboardEntries(leadb[leadid], k_ELeaderboardDataRequestGlobal, 1, 20);
                lead2[leadid] = SteamUserStats()->DownloadLeaderboardEntries(leadb[leadid], k_ELeaderboardDataRequestGlobalAroundUser, -5, 4);
                lead3[leadid] = SteamUserStats()->DownloadLeaderboardEntries(leadb[leadid], k_ELeaderboardDataRequestGlobalAroundUser, 0, 0);
            }
        }
        if (waitlead_())
        {
            for (long leadid = 0; leadid < leadn; leadid++)
            {
                SteamUtils()->GetAPICallResult(lead1[leadid], &leadd[leadid], sizeof(leadd[leadid]), leadd[leadid].k_iCallback, &leadfailed);
                leadb[leadid] = leadd[leadid].m_hSteamLeaderboard;
                leadeg[leadid] = leadd[leadid].m_hSteamLeaderboardEntries;
                for (long k = 0; k < 20; k++)
                {
                    SteamUserStats()->GetDownloadedLeaderboardEntry(leadeg[leadid],k,&leadsg[leadid][k],NULL,0);
                }
                SteamUtils()->GetAPICallResult(lead2[leadid], &leadd[leadid], sizeof(leadd[leadid]), leadd[leadid].k_iCallback, &leadfailed);
                leadb[leadid] = leadd[leadid].m_hSteamLeaderboard;
                leadeu[leadid] = leadd[leadid].m_hSteamLeaderboardEntries;
                for (long k = 0; k < 10; k++)
                {
                    SteamUserStats()->GetDownloadedLeaderboardEntry(leadeu[leadid],k,&leadsu[leadid][k],NULL,0);
                }
                SteamUtils()->GetAPICallResult(lead3[leadid], &leadd[leadid], sizeof(leadd[leadid]), leadd[leadid].k_iCallback, &leadfailed);
                leadb[leadid] = leadd[leadid].m_hSteamLeaderboard;
                leadeu_[leadid] = leadd[leadid].m_hSteamLeaderboardEntries;
                for (long k = 0; k < 1; k++)
                {
                    SteamUserStats()->GetDownloadedLeaderboardEntry(leadeu_[leadid],k,&leadsu_[leadid][k],NULL,0);
                }
            }
        }
    }
}

void Steam::setlead(long val, long mode)
{
    if (steamb)
    {
        if (mode > 0 && newrecord)
        {
            newrecord = false;
            long leadid = mode - 1;
            if (leadb[leadid] == 0)
            {
                loadlead();
            }
            if (leadb[leadid] != 0)
            {
                lead[leadid] = SteamUserStats()->UploadLeaderboardScore(leadb[leadid], k_ELeaderboardUploadScoreMethodKeepBest, val, NULL, 0);
                if (waitlead(leadid))
                {
                    SteamUtils()->GetAPICallResult(lead[leadid], &leadu[leadid], sizeof(leadu[leadid]), leadu[leadid].k_iCallback, &leadfailed);
                    leadb[leadid] = leadu[leadid].m_hSteamLeaderboard;
                }
            }
        }
    }
}

bool Steam::waitlead(long leadid)
{
    if (steamb)
    {
        bool waitb = true;
        long time = gettimer();
        while (iswin() && !SteamUtils()->IsAPICallCompleted(lead[leadid], &leadfailed) && (gettimer() < (time + waittime)))
        {
            delay(1);
        }
        waitb = waitb && SteamUtils()->IsAPICallCompleted(lead[leadid], &leadfailed);
        return waitb;
    }
}

bool Steam::waitlead()
{
    if (steamb)
    {
        bool waitb = true;
        long time = gettimer();
        for (long leadid = 0; leadid < leadn; leadid++)
        {
            while (iswin() && !SteamUtils()->IsAPICallCompleted(lead[leadid], &leadfailed) && (gettimer() < (time + waittime)))
            {
                delay(1);
            }
            waitb = waitb && SteamUtils()->IsAPICallCompleted(lead[leadid], &leadfailed);
        }
        return waitb;
    }
}

bool Steam::waitlead_()
{
    if (steamb)
    {
        bool waitb = true;
        long time = gettimer();
        for (long leadid = 0; leadid < leadn; leadid++)
        {
            while (iswin() && !SteamUtils()->IsAPICallCompleted(lead1[leadid], &leadfailed) && (gettimer() < (time + waittime)))
            {
                delay(1);
            }
            waitb = waitb && SteamUtils()->IsAPICallCompleted(lead1[leadid], &leadfailed);
            while (iswin() && !SteamUtils()->IsAPICallCompleted(lead2[leadid], &leadfailed) && (gettimer() < (time + waittime)))
            {
                delay(1);
            }
            waitb = waitb && SteamUtils()->IsAPICallCompleted(lead2[leadid], &leadfailed);
        }
        return waitb;
    }
}

void Steam::savescr(char* scrpath)
{
    if (steamb)
    {
        ScreenshotHandle screenshot = SteamScreenshots()->AddScreenshotToLibrary(scrpath, NULL, getwin()->width, getwin()->height);
    }
}