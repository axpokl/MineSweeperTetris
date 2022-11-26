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
    printf("The game is currently under development. If you have any comments or suggestions, please feedback to the community or email: ax_pokl@qq.com\n");
    Lan lan;
    if (FindWindow("MineSweeperTetrisClass", NULL) != 0)
    {
        msgbox(lan.LAN_RUNNING, lan.LAN_TITLE, MB_ICONINFORMATION);
    }
    else
    {
        Window w;
        w.bd.st.lan = lan;
        w.bd.sd.initsound();
        w.bd.initbd(1);
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