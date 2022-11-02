#include "disp.h"
#include "steam/steam_api.h"
#include "stdio.h"
using namespace std;

#include "sound.cpp"
#include "board.cpp"
#include "window.cpp"

int main()
{

    if (SteamAPI_RestartAppIfNecessary(2204230))
    {
        printf("%d\n",EXIT_FAILURE);
    }
    if (!SteamAPI_Init())
    {
        printf("%d\n",EXIT_FAILURE);
    }
    SteamUserStats()->IndicateAchievementProgress("GEN_LAUNCH_GAME", 0, 0);
    SteamUserStats()->SetAchievement("GEN_LAUNCH_GAME");

    Window w;
    while (iswin())
    {
        w.doAction();
        w.nextBlock();
        //w.drawWindow();
        //w.checkWindow();
        w.bd.sd.checkmusic();
        delay(1);
    }

    SteamUserStats()->ClearAchievement("GEN_LAUNCH_GAME");
    SteamAPI_Shutdown();

    return 0;
}