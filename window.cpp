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

    HICON hicon;

    //double time;
    //double frame;

    Board bd;

    Window();
    void initBMP();
    void resizeWindow();
    void initWindow(bool b);
    void paintMenu();
    void paintFace();
    void paintNumber(long n, long l, long x, long y);
    void paintDigit();
    void paintBoard();
    void paintEvent();
    void mousePressEvent(long x, long y, long key);
    void keyPressEvent(long key);
    void doAction();
    void nextBlock();
    //void drawWindow();
    //void checkWindow();
    int getWindowWidth();

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

    pmenu_ = loadbmp("./bmp/menu.bmp");
    for (long i = 0; i < 13; i++ )
    {
        pmenu[i] = createbmp(menuw, menuh);
        drawbmp(pmenu_, pmenu[i], 0, i * menuh, menuw, menuh, 0, 0, menuw, menuh);
    }
    pface_ = loadbmp("./bmp/face.bmp");
    for (long i = 0; i < 5; i++ )
    {
        pface[i] = createbmp(facew, faceh);
        drawbmp(pface_, pface[i], 0, i * faceh, facew, faceh, 0, 0, facew, faceh);
    }
    picon_ = loadbmp("./bmp/icon.bmp");
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
    pdigit_ = loadbmp("./bmp/digt.bmp");
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

void Window::paintMenu()
{

    drawbmp(pmenu[6], (getWindowWidth() - 2 * menuw), 0, menuw, menuh);
    drawbmp(pmenu[7], (getWindowWidth() - 1 * menuw), 0, menuw, menuh);
    if (bd.sd.soundb)
    {
        drawbmp(pmenu[8], (getWindowWidth() - 4 * menuw), 0, menuw, menuh);
    }
    else
    {
        drawbmp(pmenu[10], (getWindowWidth() - 4 * menuw), 0, menuw, menuh);
    }
    if (bd.sd.musicb)
    {
        drawbmp(pmenu[9], (getWindowWidth() - 3 * menuw), 0, menuw, menuh);
    }
    else
    {
        drawbmp(pmenu[11], (getWindowWidth() - 3 * menuw), 0, menuw, menuh);
    }
    drawbmp(pmenu[3], 0 * menuw, 0, menuw, menuh);
    drawbmp(pmenu[4], 1 * menuw, 0, menuw, menuh);
    drawbmp(pmenu[5], 2 * menuw, 0, menuw, menuh);
    if (bd.mode > 0) drawbmp(pmenu[bd.mode - 1], (bd.mode - 1) * menuw, 0, menuw, menuh);
}

void Window::paintFace()
{
    switch (bd.sit)
    {
    case 0:
        drawbmp(pface[4], (getWindowWidth() - facew) / 2, menuh, facew, faceh);
        break;
    case 1:
        drawbmp(pface[4], (getWindowWidth() - facew) / 2, menuh, facew, faceh);
        break;
    case 2:
        drawbmp(pface[3], (getWindowWidth() - facew) / 2, menuh, facew, faceh);
        break;
    case 3:
        drawbmp(pface[1], (getWindowWidth() - facew) / 2, menuh, facew, faceh);
        break;
    case 4:
        drawbmp(pface[2], (getWindowWidth() - facew) / 2, menuh, facew, faceh);
        break;
    case 5:
        drawbmp(pface[0], (getWindowWidth() - facew) / 2, menuh, facew, faceh);
        break;
    }
}

void Window::paintNumber(long n, long l, long x, long y)
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

void Window::paintDigit()
{
    paintNumber(bd.line, 4, 0, menuh);
    paintNumber(bd.level, 2, getWindowWidth() - 2 * digtw, menuh);
}

void Window::paintBoard()
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

void Window::paintEvent()
{
    clear();
    paintMenu();
    paintFace();
    paintDigit();
    paintBoard();
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
        else if (ex > getWindowWidth() - 4 * menuw)
        {
            switch ((ex - (getWindowWidth() - 4 * menuw)) / menuw)
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
        if ((ex > ((getWindowWidth() - facew) / 2)) && (ex < ((getWindowWidth() + facew) / 2)))
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

int Window::getWindowWidth()
{
    return bd.w * iconw;
}
