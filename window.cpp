class Window
{
public:

    long menuw;
    long menuh;
    long facew;
    long faceh;
    long iconw;
    long iconh;
    long digtw;
    long digth;

    pbitmap pmenu0;
    pbitmap pmenu[9];
    pbitmap pface0;
    pbitmap pface[5];
    pbitmap picon0;
    pbitmap picon[9];
    pbitmap piconc;
    pbitmap piconq;
    pbitmap piconf;
    pbitmap piconm;
    pbitmap picone;
    pbitmap piconn;
    pbitmap pdigit0;
    pbitmap pdigit[10];
    pbitmap pdigit1;
    pbitmap pdigit2;

    HICON hicon;

    //double time;
    //double frame;

    Board bd;

    Window();
    void initBMP();
    void resizeWindow();
    void initWindow(bool b);
    void paintEvent();
    void mousePressEvent(long x, long y, long key);
    void keyPressEvent(long key);
    void doAction();
    void nextBlock();
    //void drawWindow();
    //void checkWindow();

};

Window::Window()
{
    createwin(200, 200, 0xAFAFAF, 0xAFAFAF, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_VISIBLE);
    hicon=(HICON)LoadImage(GetModuleHandle(NULL),"MINESWEEPERTETEIS_ICON",IMAGE_ICON,0,0,0);
    SendMessage((HWND)gethwnd(),WM_SETICON,ICON_SMALL,(long)hicon);
    settitle("MineSweeper Tetris");
    initBMP();
    initWindow(false);
    paintEvent();

}

void Window::initBMP()
{
    menuw = 24;
    menuh = 24;
    facew = 24;
    faceh = 24;
    iconw = 16;
    iconh = 16;
    digtw = 13;
    digth = 23;

    pmenu0 = loadbmp("./bmp/menu.bmp");
    for (long i = 0; i < 9; i++ )
    {
        pmenu[i] = createbmp(menuw, menuh);
        drawbmp(pmenu0, pmenu[i], 0, i * menuh, menuw, menuh, 0, 0, menuw, menuh);
    }
    pface0 = loadbmp("./bmp/face.bmp");
    for (long i = 0; i < 5; i++ )
    {
        pface[i] = createbmp(facew, faceh);
        drawbmp(pface0, pface[i], 0, i * faceh, facew, faceh, 0, 0, facew, faceh);
    }
    picon0 = loadbmp("./bmp/icon.bmp");
    for (long i = 0; i < 9; i++ )
    {
        picon[i] = createbmp(iconw, iconh);
        drawbmp(picon0, picon[i], 0, (iconw - 1 - i) * iconh, iconw, iconh, 0, 0, iconw, iconh);
    }
    piconc = createbmp(iconw, iconh);
    drawbmp(picon0, piconc, 0, iconh * 0, iconw, iconh, 0, 0, iconw, iconh);
    piconf = createbmp(iconw, iconh);
    drawbmp(picon0, piconf, 0, iconh * 1, iconw, iconh, 0, 0, iconw, iconh);
    piconq = createbmp(iconw, iconh);
    drawbmp(picon0, piconq, 0, iconh * 2, iconw, iconh, 0, 0, iconw, iconh);
    piconm = createbmp(iconw, iconh);
    drawbmp(picon0, piconm, 0, iconh * 3, iconw, iconh, 0, 0, iconw, iconh);
    picone = createbmp(iconw, iconh);
    drawbmp(picon0, picone, 0, iconh * 4, iconw, iconh, 0, 0, iconw, iconh);
    piconn = createbmp(iconw, iconh);
    drawbmp(picon0, piconn, 0, iconh * 5, iconw, iconh, 0, 0, iconw, iconh);
    pdigit0 = loadbmp("./bmp/digt.bmp");
    for (long i = 0; i < 10; i++ )
    {
        pdigit[i] = createbmp(digtw, digth);
        drawbmp(pdigit0, pdigit[i], 0, (11-i) * digth, digtw, digth, 0, 0, digtw, digth);
    }
    pdigit1 = createbmp(digtw, digth);
    drawbmp(pdigit0, pdigit1, 0, 0, digtw, digth, 0, 0, digtw, digth);
    pdigit2 = createbmp(digtw, digth);
    drawbmp(pdigit0, pdigit2, 0, digth, digtw, digth, 0, 0, digtw, digth);
}

void Window::resizeWindow()
{
    setsize(bd.w * iconw, bd.h * iconh + faceh + menuh);
    paintEvent();
}

void Window::initWindow(bool b)
{
    if (b)
    {
        bd.initbd();
    }
    resizeWindow();
    long w = getwidth() + getborderwidth() * 2;
    long h = getheight() + getborderheight() * 2;
    long x = (getscrwidth() - w) / 2;
    long y = (getscrheight() - h) / 2;
    MoveWindow((HWND)gethwnd(), x, y, w, h + getbordertitle(), true);
    //frame = 30;
    //time = gettimer();
}

void Window::paintEvent()
{
    clear();
    drawbmp(pmenu[3], 0 * menuw, 0, menuw, menuh);
    drawbmp(pmenu[4], 1 * menuw, 0, menuw, menuh);
    drawbmp(pmenu[5], 2 * menuw, 0, menuw, menuh);
    if (bd.mode > 0) drawbmp(pmenu[bd.mode - 1], (bd.mode - 1) * menuw, 0, menuw, menuh);
    drawbmp(pmenu[6], (bd.w * iconw - 2 * menuw), 0, menuw, menuh);
    drawbmp(pmenu[7], (bd.w * iconw - 1 * menuw), 0, menuw, menuh);
    switch (bd.sit)
    {
    case 0:
        drawbmp(pface[4], (bd.w * iconw - facew) / 2, menuh, facew, faceh);
        break;
    case 1:
        drawbmp(pface[4], (bd.w * iconw - facew) / 2, menuh, facew, faceh);
        break;
    case 2:
        drawbmp(pface[3], (bd.w * iconw - facew) / 2, menuh, facew, faceh);
        break;
    case 3:
        drawbmp(pface[1], (bd.w * iconw - facew) / 2, menuh, facew, faceh);
        break;
    case 4:
        drawbmp(pface[2], (bd.w * iconw - facew) / 2, menuh, facew, faceh);
        break;
    case 5:
        drawbmp(pface[0], (bd.w * iconw - facew) / 2, menuh, facew, faceh);
        break;
    }
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
    long digit[4];
    long mr = bd.line;
    digit[0] = abs(mr) % 10;
    digit[1] = abs(mr) / 10 % 10;
    digit[2] = abs(mr) / 100 % 10;
    digit[3] = abs(mr) / 1000 % 10;
    long d = 0;
    long dr = 0;
    if (digit[3] == 0)
    {
        d = 1;
    }
    if (digit[2] == 0 && d == 1)
    {
        d = 2;
    }
    if (digit[1] == 0 && d == 2)
    {
        d = 3;
    }
    for (dr = 0; dr < d; dr++ )
    {
        drawbmp(pdigit2, dr * digtw, menuh, digtw, faceh);
    }
    for (dr = d; dr < 4; dr++ )
    {
        drawbmp(pdigit[digit[3-dr]], dr * digtw, menuh, digtw, faceh);
    }
    if (mr < 0)
    {
        drawbmp(pdigit1, (d - 1) * digtw, menuh, digtw, faceh);
    }
    mr = bd.level;
    digit[0] = abs(mr) % 10;
    digit[1] = abs(mr) / 10 % 10;
    digit[2] = abs(mr) / 100 % 10;
    digit[3] = abs(mr) / 1000 % 10;
    d = 0;
    if (digit[3] == 0)
    {
        d = 1;
    }
    if (digit[2] == 0 && d == 1)
    {
        d = 2;
    }
    if (digit[1] == 0 && d == 2)
    {
        d = 3;
    }
    for (dr = 2; dr < d; dr++ )
    {
        drawbmp(pdigit2, bd.w * iconw - (4 - dr) * digtw, menuh, digtw, faceh);
    }
    for (dr = d; dr < 4; dr++ )
    {
        drawbmp(pdigit[digit[3-dr]], bd.w * iconw - (4 - dr) * digtw, menuh, digtw, faceh);
    }
    freshwin();
}

void Window::mousePressEvent(long ex, long ey, long eb)
{
    long x;
    long y;
    if (ey < menuh)
    {
        if (ex < (3 * menuw))
        {
            bd.initbd(ex / menuw + 1);
            initWindow(false);
        }
    }
    else if (ey - menuh < faceh)
    {
        if ((ex > ((bd.w * iconw - facew) / 2)) && (ex < ((bd.w * iconw + facew) / 2)))
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
    paintEvent();
}

void Window::keyPressEvent(long key)
{
    switch (key)
    {
    case k_esc:
        closewin();
        break;
    case k_left:
        bd.w--;
        initWindow(true);
        break;
    case k_right:
        bd.w++ ;
        initWindow(true);
        break;
    case k_up:
        bd.h--;
        initWindow(true);
        break;
    case k_down:
        bd.h++ ;
        initWindow(true);
        break;
    case k_sub:
        bd.n--;
        initWindow(true);
        break;
    case k_add:
        bd.n++ ;
        initWindow(true);
        break;
    case k_pgup:
        bd.maskj0 = min(bd.h - 4, bd.maskj0);
        bd.maskj0--;
        bd.maskj0 = max(1, bd.maskj0);
        initWindow(true);
        break;
    case k_pgdn:
        bd.maskj0++ ;
        bd.maskj0 = min(bd.h - 4, bd.maskj0);
        initWindow(true);
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
        initWindow(false);
        break;
    case k_2:
        bd.initbd(2);
        initWindow(false);
        break;
    case k_3:
        bd.initbd(3);
        initWindow(false);
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
    paintEvent();
}

void Window::doAction()
{
    while (isnextmsg())
    {
        if (ismouseleft())
        {
            mousePressEvent(getmouseposx(), getmouseposy(), k_lmouse);
        }
        if (ismouseright())
        {
            mousePressEvent(getmouseposx(), getmouseposy(), k_rmouse);
        }
        if (iskey())
        {
            keyPressEvent(getkey());
        }

    }
}

void Window::nextBlock()
{
    if (bd.addmask())
    {
        paintEvent();
    }
}

/*
void Window::drawWindow()
{
    if (gettimer() > time + 1 / frame)
    {
        while (gettimer() > time + 1 / frame)
        {
            time = time + 1 / frame;
        }
        paintEvent();
    }
}

void Window::checkWindow()
{
    if ((getwidth() != bd.w * iconw) || (getheight() != bd.h * iconh + facew))
    {
        resizeWindow();
    }
}
*/

