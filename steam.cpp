#include "steam.h"

Steam::Steam()
{
    leadsn = (LeaderboardEntry_t(*)[leadn][20])calloc(3, sizeof(*leadsn));
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
            MsgBox("The old game MineSweeper Tetris is retired, please download the new MineSweeper Rush from Steam Store! \nhttps://store.steampowered.com/app/3665840", "MineSweeper Rush", MB_ICONINFORMATION);
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
        setlead();
    }
}

void Steam::setscr(long scrid)
{
    if (steamb)
    {
        if (scr[scrid] > 0)
        {
            SteamUserStats()->SetStat(scrs[scrid], *(float*)&scr[scrid]);
            //SteamUserStats()->SetStat(scrs[scrid], (union { long l; float f; }){scr[scrid]}.f);
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
            checkach(scrtotal, 10000, 1000, 100, 10, achcumtotal10000, achcumtotal1000, achcumtotal100, achcumtotal10);
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

void Steam::resetscr()
{
    if (steamb)
    {
        for (long scrid = 0; scrid < scrn; scrid++)
        {
            scr[scrid] = 0;
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
        checkcheat();
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
        checkcheat();
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

bool Steam::ischeat()
{
    return ischeat(scr[4], scr[13]);
}

void Steam::checkcheat()
{
    if (ischeat())
    {
        resetscr();
        resetach();
    }
}