#include "steam/steam_api.h"
#include "version.h"

#include "disp.cpp"

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
    Lan lan;
    if (FindWindow("MineSweeperTetrisClass", NULL) != 0)
    {
        MsgBoxW(lan.getlan(lan.LAN_RUNNING), lan.getlan(lan.LAN_TITLE), MB_ICONINFORMATION);
    }
    else
    {
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
    }
    return 0;
}
