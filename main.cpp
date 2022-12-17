#include "disp.h"
#include "stdio.h"
using namespace std;

#include "lan.cpp"
#include "reg.cpp"
#include "steam.cpp"
#include "sound.cpp"
#include "block.cpp"
#include "board.cpp"
#include "window.cpp"

int main()
{
    Lan lan;
    if (FindWindow("MineSweeperTetrisClass", NULL) != 0)
    {
        msgboxw(lan.getlan(lan.LAN_RUNNING), lan.getlan(lan.LAN_TITLE), MB_ICONINFORMATION);
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
        if (w.helpb)
        {
            w.sethelp(1);
        }
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