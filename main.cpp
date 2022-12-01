#include "disp.h"
#include "stdio.h"
using namespace std;

#include "lan.cpp"
#include "steam.cpp"
#include "sound.cpp"
#include "block.cpp"
#include "board.cpp"
#include "window.cpp"

int main()
{
    const char* dev = "The game is currently under alpha test. If you have any comments or suggestions, please feedback to the community or email: ax_pokl@qq.com\n";
    msgbox(dev, "MineSweeper Tetris", MB_ICONINFORMATION);
    Lan lan;
    if (FindWindow("MineSweeperTetrisClass", NULL) != 0)
    {
        msgboxw(lan.getlan(lan.LAN_RUNNING_W), lan.getlan(lan.LAN_TITLE_W), MB_ICONINFORMATION);
    }
    else
    {
        Window w;
        w.painttitle(w.bd.st.lan.LAN_LOAD_STEAM);
        w.bd.st.loadsteam();
        w.painttitle(w.bd.st.lan.LAN_LOAD_AUDIO);
        w.bd.sd.initsound();
        w.painttitle(w.bd.st.lan.LAN_LOAD_BOARD);
        w.bd.initbd(1);
        w.painttitle(w.bd.st.lan.LAN_LOAD_GRAPH);
        w.initbmp();
        w.painttitle(w.bd.st.lan.LAN_LOAD_WINDOW);
        w.initwindow(false);
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