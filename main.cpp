#include "disp.h"
#include "stdio.h"
using namespace std;

#include "sound.cpp"
#include "board.cpp"
#include "window.cpp"
#include "steam.cpp"

int main()
{
    if (FindWindow("MineSweeperTetrisClass", NULL) != 0)
    {
        msgbox("MineSweeper Tetris is already running!", NULL, MB_ICONINFORMATION);
        return 0;
    }
    Steam st;
    Window w;
    while (iswin())
    {
        w.doaction();
        w.nextblock();
        w.checkaudio();
        delay(1);
    }
    return 0;
}