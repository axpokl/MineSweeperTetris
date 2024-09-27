class Steam
{

public:

    Lan lan;

    const unsigned long appid = 2204230;
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
    long achcumtotal100 = 22;
    long achcumtotal1000 = 23;
    long achcumtotal10000 = 24;
    long achcumtotal100000 = 25;
    const char* achs[achn] =
    {
        "GEN_START", "GEN_CUSTOM", "GEN_MODE", "GEN_PAUSE", "GEN_HELP",
        "HID_CHEAT", "HID_EDGE", "HID_MARK", "HID_RIGHT", "HID_ALIVE",
        "CUM_DEAD_1", "CUM_DEAD_10", "CUM_DEAD_100", "CUM_DEAD_1000",
        "CUM_FOUR_1", "CUM_FOUR_10", "CUM_FOUR_100", "CUM_FOUR_1000",
        "CUM_LINE_100", "CUM_LINE_300", "CUM_LINE_600", "CUM_LINE_1000",
        "CUM_TOTAL_100", "CUM_TOTAL_1000", "CUM_TOTAL_10000", "CUM_TOTAL_100000"
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
    LeaderboardEntry_t leadsn[3][leadn][20];
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

    void loadlead();
    void getlead();
    void setlead(long mode);
    void setlead();
    bool waitlead();
    bool waitlead_();

    void savescr(char* scrpath);

    bool ischeat(long line, long tetris);

};

Steam::Steam()
{
    initsteam();
    loadlan();
}

Steam::~Steam()
{
    exitsteam();
}

void Steam::initsteam()
{
    if (SteamAPI_RestartAppIfNecessary(appid))
    {
        MsgBoxW(lan.getlan(lan.LAN_STEAM_LAUNCH), lan.getlan(lan.LAN_TITLE), MB_ICONINFORMATION);
    }
    steamb = SteamAPI_Init();
    if (!steamb)
    {
        MsgBoxW(lan.getlan(lan.LAN_STEAM_FAIL), lan.getlan(lan.LAN_TITLE), MB_ICONWARNING);
    }
    if (steamb)
    {
        if (SteamUtils()->GetAppID() != appid)
        {
            MsgBox("This is the test version of MineSweeper Tetris, please download the released version from Steam Store! \nhttps://store.steampowered.com/app/2204230", "MineSweeper Tetris", MB_ICONINFORMATION);
        }
    }
}

void Steam::loadlan()
{
    if (steamb)
    {
        const char* lanui = SteamUtils()->GetSteamUILanguage();
        const char* langame = SteamApps()->GetCurrentGameLanguage();
        if (strcmp(langame, lan.lanshort[23]) == 0)
        {
            lan.initlan(lanui);
        }
        else
        {
            lan.initlan(langame);
        }
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
            MsgBoxW(lan.getlan(lan.LAN_STEAM_Status), lan.getlan(lan.LAN_TITLE), MB_ICONWARNING);
        }
        else
        {
            loadach();
            loadscr();
            loadlead();
            painttitles = NULL;
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
        painttitles = "Load Achievement";
        painttitleb = 2;
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
        painttitles = "Load Status";
        painttitleb = 2;
        for (long scrid = 0; scrid < scrn; scrid++)
        {
            scr[scrid] = -1;
            SteamUserStats()->GetStat(scrs[scrid], (float*)&scr[scrid]);
            if (scr[scrid] < 0)
            {
                SteamUserStats()->GetStat(scrs[scrid], (float*)&scr[scrid]);
            }
            if (scr[scrid] < 0)
            {
                scr[scrid] = 0;
                steamb = false;
            }
            //printf("%d %s %d\n",scrid,scrs[scrid],scr[scrid]);
        }
        if (ischeat(scr[4], scr[13]))
        {
            resetach();
        }
        setlead();
    }
}

void Steam::setscr(long scrid)
{
    if (steamb)
    {
        if (scr[scrid] > 0)
        {
            //SteamUserStats()->SetStat(scrs[scrid], *(float*)&scr[scrid]);
            SteamUserStats()->SetStat(scrs[scrid], (union { long l; float f; })
            {
                scr[scrid]
            } .f);
        }
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

void Steam::maxscr(long val, long scrline__)
{
    if (steamb)
    {
        if (val > scr[scrline__])
        {
            scr[scrline__] = val;
            setscr(scrline__);
            if (scrline__ < 7)
            {
                scr[scrline] = max(scr[scrline], scr[scrline__]);
                setscr(scrline);
            }
            newrecord = true;
        }
    }
}

void Steam::compscr(long val, long mode, long index)
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
                maxscr(val, scrline_ + index);
            }
        }
    }
}

void Steam::loadlead()
{
    if (steamb)
    {
        painttitles = "Load Leaderboard";
        painttitleb = 2;
        for (long leadid = 0; leadid < leadn; leadid++)
        {
            lead[leadid] = SteamUserStats()->FindLeaderboard(leads[leadid]);
        }
        if (waitlead())
        {
            for (long leadid = 0; leadid < leadn; leadid++)
            {
                SteamUtils()->GetAPICallResult(lead[leadid], &leadr, sizeof(leadr), leadr.k_iCallback, &leadfailed);
                leadb[leadid] = leadr.m_hSteamLeaderboard;
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
                lead_[0][leadid] = SteamUserStats()->DownloadLeaderboardEntries(leadb[leadid], k_ELeaderboardDataRequestGlobal, 1, 20);
                lead_[1][leadid] = SteamUserStats()->DownloadLeaderboardEntries(leadb[leadid], k_ELeaderboardDataRequestGlobalAroundUser, -5, 4);
                lead_[2][leadid] = SteamUserStats()->DownloadLeaderboardEntries(leadb[leadid], k_ELeaderboardDataRequestGlobalAroundUser, 0, 0);
            }
        }
        if (waitlead_())
        {
            for (long n = 0; n < 3; n++)
            {
                for (long leadid = 0; leadid < leadn; leadid++)
                {
                    SteamUtils()->GetAPICallResult(lead_[n][leadid], &leadd, sizeof(leadd), leadd.k_iCallback, &leadfailed);
                    leadb[leadid] = leadd.m_hSteamLeaderboard;
                    leaden[n][leadid] = leadd.m_hSteamLeaderboardEntries;
                    for (long k = 0; k < leadk_[n]; k++)
                    {
                        SteamUserStats()->GetDownloadedLeaderboardEntry(leaden[n][leadid],k,&leadsn[n][leadid][k],NULL,0);
                    }
                }
            }
        }
    }
}

void Steam::setlead()
{
    if (steamb)
    {
        long leadid;
        for (leadid = 0; leadid < 3; leadid++)
        {
            if (leadb[leadid] == 0)
            {
                loadlead();
            }
            if (leadb[leadid] != 0)
            {
                for (long k = 0; k < 5; k++)
                {
                    lead[leadid + k * 3] = SteamUserStats()->UploadLeaderboardScore(leadb[leadid + k * 3], k_ELeaderboardUploadScoreMethodKeepBest, scr[leadid + k * 3 + 4], NULL, 0);
                }
            }
        }
        if (waitlead())
        {
            for (leadid = 0; leadid < 3; leadid++)
            {
                if (leadb[leadid] != 0)
                {
                    for (long k = 0; k < 5; k++)
                    {
                        SteamUtils()->GetAPICallResult(lead[leadid + k * 3], &leadu, sizeof(leadu), leadu.k_iCallback, &leadfailed);
                        leadb[leadid + k * 3] = leadu.m_hSteamLeaderboard;
                    }
                }
            }
        }
    }
}

void Steam::setlead(long mode)
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
                for (long k = 0; k < 5; k++)
                {
                    lead[leadid + k * 3] = SteamUserStats()->UploadLeaderboardScore(leadb[leadid + k * 3], k_ELeaderboardUploadScoreMethodKeepBest, scr[leadid + k * 3 + 4], NULL, 0);
                    if (waitlead())
                    {
                        SteamUtils()->GetAPICallResult(lead[leadid + k * 3], &leadu, sizeof(leadu), leadu.k_iCallback, &leadfailed);
                        leadb[leadid + k * 3] = leadu.m_hSteamLeaderboard;
                    }
                }
            }
        }
    }
}

bool Steam::waitlead()
{
    if (steamb)
    {
        bool waitb = true;
        long time = GetTimeR();
        for (long leadid = 0; leadid < leadn; leadid++)
        {
            while (IsWin() && !SteamUtils()->IsAPICallCompleted(lead[leadid], &leadfailed) && (GetTimeR() < (time + waittime)))
            {
                Delay(1);
            }
            waitb = waitb && SteamUtils()->IsAPICallCompleted(lead[leadid], &leadfailed);
        }
        return waitb;
    }
    return false;
}

bool Steam::waitlead_()
{
    if (steamb)
    {
        bool waitb = true;
        long time = GetTimeR();
        for (long n = 0; n < 3; n++)
        {
            for (long leadid = 0; leadid < leadn; leadid++)
            {
                while (IsWin() && !SteamUtils()->IsAPICallCompleted(lead_[n][leadid], &leadfailed) && (GetTimeR() < (time + waittime)))
                {
                    Delay(1);
                }
                waitb = waitb && SteamUtils()->IsAPICallCompleted(lead_[n][leadid], &leadfailed);
            }
        }
        return waitb;
    }
    return false;
}

void Steam::savescr(char* scrpath)
{
    if (steamb)
    {
        SteamScreenshots()->AddScreenshotToLibrary(scrpath, NULL, GetWin()->Width, GetWin()->Height);
    }
}

bool Steam::ischeat(long line, long tetris)
{
    if (line > 9998)
    {
        return true;
    }
    if ((line > 3000) && ((tetris<=98) || (tetris>998)))
    {
        return true;
    }
    return false;
}
