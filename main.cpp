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
        return EXIT_FAILURE;
    }
    if (!SteamAPI_Init())
    {
        return EXIT_FAILURE;
    }
    Window w;
    while (iswin())
    {
        w.doAction();
        w.nextBlock();
        //w.drawWindow();
        //w.checkWindow();
        delay(1);
    }
    SteamAPI_Shutdown();
    return 0;
}