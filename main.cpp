#include "steam/steam_api.h"
#include "version.h"

#include "disp.cpp"
#include "cab.cpp"

#include "reg.cpp"
#include "lan.cpp"
#include "steam.cpp"
#include "sound.cpp"
#include "block.cpp"
#include "board.cpp"
#include "window.cpp"

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    MainInstance = hInstance;
    HANDLE hMutex = CreateMutex(NULL, TRUE, "MineSweeperRushMutex");
    if ((GetLastError() == ERROR_ALREADY_EXISTS) || (FindWindow("MineSweeperRushClass", NULL) != 0))
    {
        Lan lan;
        MsgBoxW(lan.getlan(lan.LAN_RUNNING), lan.getlan(lan.LAN_TITLE), MB_ICONINFORMATION);
    }
    else
    {
        CheckAndProcessCabFile();
        Lan lan;
        Window w;
        w.loadall();
        while (IsWin())
        {
            w.doaction();
            if (w.bd.addmask())
            {
                w.paintevent();
            }
            w.bd.sd.checkmusic();
            Delay(1);
        }
        ReleaseMutex(hMutex);
    }
    CloseHandle(hMutex);
    return 0;
}
