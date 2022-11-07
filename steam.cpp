#include "steam/steam_api.h"

class Steam
{

public:

    const long appid = 2204230;
    bool steamb;

    Steam();
    ~Steam();
    void initsteam();
    void exitsteam();
    void addachievement();
    void delachievement();

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
        msgbox("Please launch MineSwepper Tetris from Steam!", NULL, MB_ICONINFORMATION);
    }
    steamb = SteamAPI_Init();
    if (!steamb)
    {
        msgbox("Steam initialize failed!", NULL, MB_ICONWARNING);
    }
}

void Steam::exitsteam()
{
    SteamAPI_Shutdown();
}

void Steam::addachievement()
{
    if (steamb)
    {
        SteamUserStats()->IndicateAchievementProgress("GEN_LAUNCH_GAME", 0, 0);
        SteamUserStats()->SetAchievement("GEN_LAUNCH_GAME");
    }
}

void Steam::delachievement()
{
    if (steamb)
    {
        SteamUserStats()->ClearAchievement("GEN_LAUNCH_GAME");
    }
}