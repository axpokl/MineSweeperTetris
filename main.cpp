#include "disp.h"
#include "stdio.h"
using namespace std;

#include "sound.cpp"
#include "block.cpp"
#include "board.cpp"
#include "window.cpp"
//#include "steam.cpp"

int main()
{
    if (FindWindow("MineSweeperTetrisClass", NULL) != 0)
    {
        msgbox("MineSweeper Tetris is already running!", NULL, MB_ICONINFORMATION);
    }
    else
    {
        //Steam st;
        Window w;
        w.bd.sd.initsound();
        w.bd.initbd(1);
        w.initwindow(false);
        while (iswin())
        {
            w.doaction();
            w.nextblock();
            w.checkaudio();
            delay(1);
        }
    }
    return 0;
}