class Window
{
public:

    long menuw = 24;
    long menuh = 24;
    long facew = 24;
    long faceh = 24;
    long iconw = 16;
    long iconh = 16;
    long digtw = 13;
    long digth = 23;

    pbitmap pmenu_;
    pbitmap pmenu[13];
    pbitmap pface_;
    pbitmap pface[5];
    pbitmap picon_;
    pbitmap picon[9];
    pbitmap piconc;
    pbitmap piconq;
    pbitmap piconf;
    pbitmap piconm;
    pbitmap picone;
    pbitmap piconn;
    pbitmap pdigit_;
    pbitmap pdigit[10];
    pbitmap pdigitmin;
    pbitmap pdigitnul;

    Board bd;
    HICON hicon;
    bool helpb = false;
    long helpi = 0;

    Window();
    void initbmp();
    void initwindow(bool b);
    void paintmenu();
    void paintface();
    void paintnumber(long n, long l, long x, long y);
    void paintdigit();
    void paintboard();
    void painthelp();
    void paintevent();
    void mouseevent(long x, long y, long key);
    void keyevent(long key);
    void doaction();
    void nextblock();
    void checkaudio();

};

Window::Window()
{
    createwin(bd.w * iconw, bd.h * iconh + faceh + menuh, 0xAFAFAF, 0xAFAFAF, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_VISIBLE, "MineSweeperTetrisClass");
    hicon=(HICON)LoadImage(GetModuleHandle(NULL),"MINESWEEPERTETEIS_ICON",IMAGE_ICON,0,0,0);
    SendMessage((HWND)gethwnd(),WM_SETICON,ICON_SMALL,(long)hicon);
    settitle("MineSweeper Tetris");
    initbmp();
    initwindow(false);
    paintevent();
}

void Window::initbmp()
{
    pmenu_ = loadbmp("./bmp/menu.bmp");
    pface_ = loadbmp("./bmp/face.bmp");
    picon_ = loadbmp("./bmp/icon.bmp");
    pdigit_ = loadbmp("./bmp/digt.bmp");
    for (long i = 0; i < 13; i++ )
    {
        pmenu[i] = createbmp(menuw, menuh);
        drawbmp(pmenu_, pmenu[i], 0, i * menuh, menuw, menuh, 0, 0, menuw, menuh);
    }
    for (long i = 0; i < 5; i++ )
    {
        pface[i] = createbmp(facew, faceh);
        drawbmp(pface_, pface[i], 0, i * faceh, facew, faceh, 0, 0, facew, faceh);
    }
    for (long i = 0; i < 9; i++ )
    {
        picon[i] = createbmp(iconw, iconh);
        drawbmp(picon_, picon[i], 0, (16 - 1 - i) * iconh, iconw, iconh, 0, 0, iconw, iconh);
    }
    piconc = createbmp(iconw, iconh);
    drawbmp(picon_, piconc, 0, iconh * 0, iconw, iconh, 0, 0, iconw, iconh);
    piconf = createbmp(iconw, iconh);
    drawbmp(picon_, piconf, 0, iconh * 1, iconw, iconh, 0, 0, iconw, iconh);
    piconq = createbmp(iconw, iconh);
    drawbmp(picon_, piconq, 0, iconh * 2, iconw, iconh, 0, 0, iconw, iconh);
    piconm = createbmp(iconw, iconh);
    drawbmp(picon_, piconm, 0, iconh * 3, iconw, iconh, 0, 0, iconw, iconh);
    picone = createbmp(iconw, iconh);
    drawbmp(picon_, picone, 0, iconh * 4, iconw, iconh, 0, 0, iconw, iconh);
    piconn = createbmp(iconw, iconh);
    drawbmp(picon_, piconn, 0, iconh * 5, iconw, iconh, 0, 0, iconw, iconh);
    for (long i = 0; i < 10; i++ )
    {
        pdigit[i] = createbmp(digtw, digth);
        drawbmp(pdigit_, pdigit[i], 0, (11-i) * digth, digtw, digth, 0, 0, digtw, digth);
    }
    pdigitmin = createbmp(digtw, digth);
    drawbmp(pdigit_, pdigitmin, 0, 0, digtw, digth, 0, 0, digtw, digth);
    pdigitnul = createbmp(digtw, digth);
    drawbmp(pdigit_, pdigitnul, 0, digth, digtw, digth, 0, 0, digtw, digth);
}

void Window::initwindow(bool b)
{
    if (b)
    {
        bd.initbd();
    }
    if (helpb)
    {
        setsize(600, 400 + menuh);
    }
    else
    {
        setsize(bd.w * iconw, bd.h * iconh + faceh + menuh);
    }
    setpos(max(0, (getscrwidth() - getwidth()) / 2), max(0, (getscrheight() - getheight()) / 2));
    paintevent();
}

void Window::paintmenu()
{

    drawbmp(pmenu[6], (getwidth() - 2 * menuw), 0, menuw, menuh);
    drawbmp(pmenu[7], (getwidth() - 1 * menuw), 0, menuw, menuh);
    if (bd.sd.soundb)
    {
        drawbmp(pmenu[8], (getwidth() - 4 * menuw), 0, menuw, menuh);
    }
    else
    {
        drawbmp(pmenu[10], (getwidth() - 4 * menuw), 0, menuw, menuh);
    }
    if (bd.sd.musicb)
    {
        drawbmp(pmenu[9], (getwidth() - 3 * menuw), 0, menuw, menuh);
    }
    else
    {
        drawbmp(pmenu[11], (getwidth() - 3 * menuw), 0, menuw, menuh);
    }
    drawbmp(pmenu[3], 0 * menuw, 0, menuw, menuh);
    drawbmp(pmenu[4], 1 * menuw, 0, menuw, menuh);
    drawbmp(pmenu[5], 2 * menuw, 0, menuw, menuh);
    if (bd.mode > 0) drawbmp(pmenu[bd.mode - 1], (bd.mode - 1) * menuw, 0, menuw, menuh);
}

void Window::paintface()
{
    switch (bd.sit)
    {
    case 0:
        drawbmp(pface[4], (getwidth() - facew) / 2, menuh, facew, faceh);
        break;
    case 1:
        drawbmp(pface[4], (getwidth() - facew) / 2, menuh, facew, faceh);
        break;
    case 2:
        drawbmp(pface[3], (getwidth() - facew) / 2, menuh, facew, faceh);
        break;
    case 3:
        drawbmp(pface[1], (getwidth() - facew) / 2, menuh, facew, faceh);
        break;
    case 4:
        drawbmp(pface[2], (getwidth() - facew) / 2, menuh, facew, faceh);
        break;
    case 5:
        drawbmp(pface[0], (getwidth() - facew) / 2, menuh, facew, faceh);
        break;
    }
}

void Window::paintnumber(long n, long l, long x, long y)
{
    long digit[10];
    long dl = 0;
    long dlm;
    bool minb = (n < 0);
    if (minb)
    {
        n = -n;
    }
    do
    {
        digit[dl] = n % 10;
        n /= 10;
        dl++;
    }
    while (n != 0);
    if (minb)
    {
        dlm = max(dl + 1, l);
    }
    else
    {
        dlm = max(dl, l);
    }

    for (long di = 0; di < dlm; di++)
    {
        if ( di < dl)
        {
            drawbmp(pdigit[digit[di]], x + (dlm - di - 1) * digtw, y, digtw, faceh);
        }
        else if (di == dl && minb)
        {
            drawbmp(pdigitmin, x + (dlm - di - 1) * digtw, y, digtw, faceh);
        }
        else
        {
            drawbmp(pdigitnul, x + (dlm - di - 1) * digtw, y, digtw, faceh);
        }
    }
}

void Window::paintdigit()
{
    paintnumber(bd.line, 4, 0, menuh);
    paintnumber(bd.level, 2, getwidth() - 2 * digtw, menuh);
}

void Window::paintboard()
{
    for (long i = 0; i < bd.w; i++ )
    {
        for (long j = 0; j < bd.h; j++ )
        {
            if (bd.sit == 5)
            {
                drawbmp(picone, i * iconw, j * iconh + faceh + menuh, iconw, iconh);
            }
            else if (bd.mask[i][j] && (i >= bd.maski || j < bd.maskj - 1))
            {
                ;
            }
            else if (bd.blck[i][j])
            {
                if (bd.mine[i][j])
                {
                    drawbmp(piconm, i * iconw, j * iconh + faceh + menuh, iconw, iconh);
                }
                else
                {
                    drawbmp(picon[bd.numb[i][j]], i * iconw, j * iconh + faceh + menuh, iconw, iconh);
                }
            }
            else if (bd.flag[i][j])
            {
                drawbmp(piconf, i * iconw, j * iconh + faceh + menuh, iconw, iconh);
            }
            else if (bd.qstn[i][j])
            {
                drawbmp(piconq, i * iconw, j * iconh + faceh + menuh, iconw, iconh);
            }
            else if ((bd.sit == 4) && bd.mine[i][j])
            {
                drawbmp(piconn, i * iconw, j * iconh + faceh + menuh, iconw, iconh);
            }
            else if (bd.mask[i][j])
            {
                drawbmp(picone, i * iconw, j * iconh + faceh + menuh, iconw, iconh);
            }
            else
            {
                drawbmp(piconc, i * iconw, j * iconh + faceh + menuh, iconw, iconh);
            }
        }
    }
}

void Window::painthelp()
{
}

void Window::paintevent()
{
    clear();
    paintmenu();
    paintface();
    paintdigit();
    paintboard();
    freshwin();
}

void Window::mouseevent(long ex, long ey, long eb)
{
    long x;
    long y;
    if (ey < menuh)
    {
        if (ex < (3 * menuw))
        {
            bd.initbd(ex / menuw + 1);
            initwindow(false);
        }
        else if (ex > getwidth() - 4 * menuw)
        {
            switch ((ex - (getwidth() - 4 * menuw)) / menuw)
            {
            case 0:
                bd.sd.soundb = !bd.sd.soundb;
                break;
            case 1:
                bd.sd.switchmusic();
                break;
            case 2:
                break;
            case 3:
                break;
            }
        }
    }
    else if (ey - menuh < faceh)
    {
        if ((ex > ((getwidth() - facew) / 2)) && (ex < ((getwidth() + facew) / 2)))
        {
            if (eb == k_lmouse)
            {
                bd.initbd();
            }
            else if (eb == k_rmouse)
            {
                bd.pause();
            }
        }
    }
    else if (bd.sit < 4)
    {
        x = ex / iconw;
        y = (ey - faceh-menuh) / iconh;
        if (eb == k_lmouse)
        {
            if (bd.sit == 0 && y >= bd.maskj)
            {
                bd.resetbd(x, y);
            }
            bd.clickleft(x, y);
            bd.checkline();
        }
        else if (eb == k_rmouse)
        {
            bd.clickright(x, y, true);
            bd.checkline();
        }
        bd.solveb = true;
        while (bd.solveb)
        {
            bd.solve0();
        }
        bd.checkline();
    }
    paintevent();
}

void Window::keyevent(long key)
{
    switch (key)
    {
    case k_esc:
        closewin();
        break;
    case k_left:
        bd.w--;
        initwindow(true);
        break;
    case k_right:
        bd.w++ ;
        initwindow(true);
        break;
    case k_up:
        bd.h--;
        initwindow(true);
        break;
    case k_down:
        bd.h++ ;
        initwindow(true);
        break;
    case k_sub:
        bd.n--;
        initwindow(true);
        break;
    case k_add:
        bd.n++ ;
        initwindow(true);
        break;
    case k_pgup:
        bd.maskj0 = min(bd.h - 4, bd.maskj0);
        bd.maskj0--;
        bd.maskj0 = max(1, bd.maskj0);
        initwindow(true);
        break;
    case k_pgdn:
        bd.maskj0++ ;
        bd.maskj0 = min(bd.h - 4, bd.maskj0);
        initwindow(true);
        break;
    case k_p:
        bd.pause();
        break;
    case k_s:
        bd.solve2();
        break;
    case k_d:
        bd.solveb = true;
        while (bd.solveb)
        {
            bd.solve1();
        }
        break;
    case k_f:
        bd.solveb = true;
        while (bd.solveb)
        {
            bd.solveblank();
        }
        break;
    case k_1:
        bd.initbd(1);
        initwindow(false);
        break;
    case k_2:
        bd.initbd(2);
        initwindow(false);
        break;
    case k_3:
        bd.initbd(3);
        initwindow(false);
        break;
    case k_8:
        bd.addline(true);
        break;
    case k_9:
        bd.delline(bd.h - 1);
        break;
    case k_0:
        bd.level++ ;
        break;
    case k_space:
        bd.solve1();
        break;
    }
    paintevent();
}

void Window::doaction()
{
    while (isnextmsg())
    {
        if (ismouseleft())
        {
            mouseevent(getmouseposx(), getmouseposy(), k_lmouse);
        }
        if (ismouseright())
        {
            mouseevent(getmouseposx(), getmouseposy(), k_rmouse);
        }
        if (iskey())
        {
            keyevent(getkey());
        }

    }
}

void Window::nextblock()
{
    if (bd.addmask())
    {
        paintevent();
    }
}

void Window::checkaudio()
{
    bd.sd.checkmusic();
}
