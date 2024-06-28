#include "steam/steam_api.h"
#include "version.h"

#include "disp_head.cpp"
#include "disp_body.cpp"
#include "disp_func.cpp"

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
        msgboxw(lan.getlan(lan.LAN_RUNNING), lan.getlan(lan.LAN_TITLE), MB_ICONINFORMATION);
    }
    else
    {
        Window w;
        w.loadall();
        while (iswin())
        {
            w.doaction();
            if (w.bd.addmask())
            {
                w.paintevent();
            }
            w.bd.sd.checkmusic();
            delay(1);
        }
    }
    return 0;
}