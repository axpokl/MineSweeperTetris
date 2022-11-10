class Window
{
public:

    const long menuw = 24;
    const long menuh = 24;
    const long facew = 24;
    const long faceh = 24;
    const long iconw = 16;
    const long iconh = 16;
    const long digtw = 13;
    const long digth = 23;
    const long okw = 144;
    const long okh = 36;
    const long btnw = 36;
    const long btnh = 36;
    const long aboutw = 320;
    const long abouth = 240;
    const long helpw = 640;
    const long helph = 480;
    const long fontth = 64;
    const long fontfh = 32;
    const long fonth = 24;
    const long okh_ = abouth - (fontth + fonth * 4);

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
    pbitmap piconp;
    pbitmap pdigit_;
    pbitmap pdigit[10];
    pbitmap pdigitmin;
    pbitmap pdigitnul;
    pbitmap pok_;
    pbitmap pok;
    pbitmap pbtn;
    pbitmap pcursor_;
    pbitmap pclick_;
    pbitmap pclickl;
    pbitmap pclickr;

    const long cbg = 0xAFAFAF;
    const long cfg = 0xC0C0C0;
    HICON hicon;
    Board bd;
    Block bl;
    const long maxhelp = 10;
    long helpi = 0;
    long cheati = 0;

    Window();
    void initbmp();
    void initwindow(bool b);
    void paintmenu();
    void paintface();
    void paintnumber(long n, long l, long x, long y);
    void paintdigit();
    void paintblock(Block &bd0, long i, long j, long x, long y, long w, long h);
    void paintboard(Block b, long x, long y);
    void paintboard(Block b, long x, long y, long cx, long cy);
    void paintboard();
    void painthelp();
    void paintevent();
    bool isin(long ex, long ey, long x, long y, long w, long h);
    void sethelp(long helpi_);
    void mouseevent(long x, long y, long key);
    void keyevent(long key);
    void doaction();
    void nextblock();
    void checkaudio();

};

Window::Window()
{
    createwin(bd.w * iconw, bd.h * iconh + faceh + menuh, cbg, cbg, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_VISIBLE, "MineSweeperTetrisClass");
    hicon = (HICON)LoadImage(GetModuleHandle(NULL), "MINESWEEPERTETEIS_ICON", IMAGE_ICON, 0, 0, 0);
    SendMessage((HWND)gethwnd(), WM_SETICON, ICON_SMALL, (LPARAM)hicon);
    settitle("MineSweeper Tetris");
    setfontname("Arial");
    setfontheight(fonth);
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
    pok_ = loadbmp("./bmp/ok.bmp");
    pcursor_ = loadbmp("./bmp/cursor.bmp");
    pclick_ = loadbmp("./bmp/click.bmp");
    for (long i = 0; i < 13; i++)
    {
        pmenu[i] = createbmp(menuw, menuh);
        drawbmp(pmenu_, pmenu[i], 0, i * menuh, menuw, menuh, 0, 0, menuw, menuh);
    }
    for (long i = 0; i < 5; i++)
    {
        pface[i] = createbmp(facew, faceh);
        drawbmp(pface_, pface[i], 0, i * faceh, facew, faceh, 0, 0, facew, faceh);
    }
    for (long i = 0; i < 9; i++)
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
    piconp = createbmp(iconw, iconh);
    drawbmp(picon_, piconp, 0, iconh * 6, iconw, iconh, 0, 0, iconw, iconh);
    for (long i = 0; i < 10; i++)
    {
        pdigit[i] = createbmp(digtw, digth);
        drawbmp(pdigit_, pdigit[i], 0, (11-i) * digth, digtw, digth, 0, 0, digtw, digth);
    }
    pdigitmin = createbmp(digtw, digth);
    drawbmp(pdigit_, pdigitmin, 0, 0, digtw, digth, 0, 0, digtw, digth);
    pdigitnul = createbmp(digtw, digth);
    drawbmp(pdigit_, pdigitnul, 0, digth, digtw, digth, 0, 0, digtw, digth);
    pok = createbmp(okw, okh);
    drawbmp(pok_, pok, okh * 0, 0, okw, okh, 0, 0, okw, okh);
    pbtn = createbmp(btnw, btnh);
    drawbmp(pok_, pbtn, okw, 0, btnw, btnh, 0, 0, btnw, btnh);
}

void Window::initwindow(bool b)
{
    switch (helpi)
    {
    case -1:
        setsize(aboutw, abouth + menuh);
        break;
    case 0:
        setsize(bd.w * iconw, bd.h * iconh + faceh + menuh);
        if (b)
        {
            bd.initbd();
        }
        break;
    default:
        setsize(helpw, helph + menuh);
        break;
    }
    setpos(max(0, (getscrwidth() - getwidth()) / 2), max(0, (getscrheight() - getheight()) / 2));
    paintevent();
}

void Window::paintmenu()
{

    drawbmp(pmenu[6], (getwidth() - 2 * menuw), 0, menuw, menuh);
    drawbmp(pmenu[7], (getwidth() - 1 * menuw), 0, menuw, menuh);
    if (cheati == 2)
    {
        drawbmp(pmenu[12], (getwidth() - 5 * menuw), 0, menuw, menuh);
    }
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
    if (bd.mode > 0)
    {
        drawbmp(pmenu[bd.mode - 1], (bd.mode - 1) * menuw, 0, menuw, menuh);
    }
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
        if (di < dl)
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

void Window::paintblock(Block &bl, long i, long j, long x, long y, long w, long h)
{
    if (bl.sit == 5)
    {
        drawbmp(piconp, x, y, w, h);
        bar(x, y, w - 1, h - 1, cbg);
    }
    else if (bl.mask[i][j])
    {
        if (!(i >= bl.maski || j < bl.maskj - 1))
        {
            drawbmp(picone, x, y, w, h);
        }
    }
    else if (bl.blck[i][j])
    {
        if (bl.mine[i][j])
        {
            drawbmp(piconm, x, y, w, h);
        }
        else
        {
            drawbmp(picon[bl.numb[i][j]], x, y, w, h);
        }
    }
    else if (bl.flag[i][j])
    {
        drawbmp(piconf, x, y, w, h);
    }
    else if (bl.qstn[i][j])
    {
        drawbmp(piconq, x, y, w, h);
    }
    else if ((bl.sit == 4) && bl.mine[i][j])
    {
        drawbmp(piconn, x, y, w, h);
    }
    else
    {
        drawbmp(piconc, x, y, w, h);
    }

}


void Window::paintboard(Block b, long x, long y)
{
    for (long i = 0; i < b.w; i++)
    {
        for (long j = 0; j < b.h; j++)
        {
            paintblock(b, i, j, i * iconw + x, j * iconh + menuh + y, iconw, iconh);
        }
    }
}

void Window::paintboard(Block b, long x, long y, long cx, long cy)
{
    paintboard(b, x, y);
    drawbmp(pcursor_, cx * iconw + x + iconw / 2, cy * iconh + menuh + y + iconh / 2, silver);
}


void Window::paintboard()
{
    paintboard(bd, 0, faceh);
}

void Window::painthelp()
{

    switch (helpi)
    {
    case 1:
        for (long i = 0; i < 4; i++)
        {
            for (long j = 0; j < 3; j++)
            {
                bl.initbl();
                switch (i)
                {
                case 1:
                    switch (j)
                    {
                    case 0:
                        bl.blck[1][min(j, 1)] = true;
                    case 1:
                        bl.flag[1][min(j, 1)] = true;
                    case 2:
                        bl.qstn[1][min(j, 1)] = true;
                    }
                    break;
                case 2:
                    switch (j)
                    {
                    case 0:
                        bl.qstn[1][min(j, 1)] = true;
                    case 1:
                        bl.qstn[1][min(j, 1)] = true;
                    case 2:
                        bl.qstn[1][min(j, 1)] = true;
                    }
                    break;
                case 3:
                    switch (j)
                    {
                    case 0:
                        bl.blck[1][min(j, 1)] = true;
                    case 1:
                        bl.flag[1][min(j, 1)] = true;
                    }
                    break;
                }
                paintboard(bl, helpw / 8 * (i * 2 + 1) - bl.w * iconw / 2, (helph - okh_) / 6 * (j * 2 + 1) - bl.h * iconh / 2, 1, min(j, 1));
            }
        }
        break;
    case 2:
        break;
    case -1:
        setfontheight(fontfh);
        drawtextxy(getwin(),"About", 0, menuh, aboutw, fontth, black, cbg);
        setfontheight(fonth);
        drawtextxy(getwin(),"MineSwepper Tetris (32-bit)", 0, menuh + fontth, aboutw, fonth, black, cbg);
        drawtextxy(getwin(),"Version 0.1 (Steam)", 0, menuh + fontth + fonth, aboutw, fonth, black, cbg);
        drawtextxy(getwin(),"Made by ax_pokl", 0, menuh + fontth + fonth * 2, aboutw, fonth, black, cbg);
        drawtextxy(getwin(),"Licensed under GPL-3.0", 0, menuh + fontth + fonth * 3, aboutw, fonth, black, cbg);
        break;
    }
    if (helpi > 0)
    {
        setfontheight(fonth);
        drawbmp(pok, getwin(), (helpw - okw) / 2, helph - (okh_ + okh) / 2 + menuh, okw, okh);
        drawtextxy(getwin(),"OK", (helpw - okw) / 2, helph - (okh_ + okh) / 2 + menuh, okw, okh, black, cfg);
        if (helpi > 1)
        {
            drawbmp(pbtn, getwin(), (helpw - okw) / 2 - btnw * 2, helph - (okh_ + okh) / 2 + menuh, btnw, btnh);
            drawtextxy(getwin(),"<", (helpw - okw) / 2 - btnw * 2, helph - (okh_ + okh) / 2 + menuh, btnw, btnh, black, cfg);
        }
        if (helpi < maxhelp)
        {
            drawbmp(pbtn, getwin(), (helpw + okw) / 2 + btnw, helph - (okh_ + okh) / 2 + menuh, btnw, btnh);
            drawtextxy(getwin(),">", (helpw + okw) / 2 + btnw, helph - (okh_ + okh) / 2 + menuh, btnw, btnh, black, cfg);
        }
    }
    else if (helpi < 0)
    {
        setfontheight(fonth);
        drawbmp(pok, getwin(), (aboutw - okw) / 2, abouth - (okh_ + okh) / 2 + menuh, okw, okh);
        drawtextxy(getwin(),"OK", (aboutw - okw) / 2, abouth - (okh_ + okh) / 2 + menuh, okw, okh, black, cfg);
    }
}

void Window::paintevent()
{
    clear();
    paintmenu();
    if (helpi != 0)
    {
        painthelp();
    }
    else
    {
        paintface();
        paintdigit();
        paintboard();
    }
    freshwin();
}

bool Window::isin(long ex, long ey, long x, long y, long w, long h)
{
    return (ex > x && ey > y && ex < (x + w) && ey < (y + h));
}

void Window::sethelp(long helpi_)
{
    if ((helpi != helpi_) && (helpi_ != 0))
    {
        if (helpi == 0 && bd.sit != 5)
        {
            bd.pause();
        }
        helpi = helpi_;
    }
    else
    {
        bd.pause();
        helpi = 0;
    }
    initwindow(false);
}

void Window::mouseevent(long ex, long ey, long eb)
{
    long x;
    long y;
    if (ey < menuh)
    {
        if (ex < (3 * menuw))
        {
            helpi = 0;
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
                sethelp(1);
                break;
            case 3:
                sethelp(-1);
                break;
            }
        }
    }
    else if (helpi == 0)
    {
        if (ey - menuh < faceh)
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
            y = (ey - faceh - menuh) / iconh;
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
    }
    else if (helpi > 0)
    {
        if (isin(ex, ey, (helpw - okw) / 2, helph - (okh_ + okh) / 2 + menuh, okw, okh))
        {
            sethelp(0);
        }
        if (helpi > 1)
        {
            if (isin(ex, ey, (helpw - okw) / 2 - btnw * 2, helph - (okh_ + okh) / 2 + menuh, btnw, btnh))
            {
                helpi--;
            }
        }
        if (helpi < maxhelp)
        {
            if (isin(ex, ey, (helpw + okw) / 2 + btnw, helph - (okh_ + okh) / 2 + menuh, btnw, btnh))
            {
                helpi++;
            }
        }
    }
    else if (helpi < 0)
    {
        if (isin(ex, ey, (aboutw - okw) / 2, abouth - (okh_ + okh) / 2 + menuh, okw, okh))
        {
            sethelp(0);
        }
    }
    paintevent();
}

void Window::keyevent(long key)
{
    if (cheati == 1)
    {
        if (key == k_x)
        {
            cheati = 2;
        }
        else
        {
            cheati = 0;
        }
    }
    switch (key)
    {
    case k_esc:
        closewin();
        break;
    case k_1:
        helpi = 0;
        bd.initbd(1);
        initwindow(false);
        break;
    case k_2:
        helpi = 0;
        bd.initbd(2);
        initwindow(false);
        break;
    case k_3:
        helpi = 0;
        bd.initbd(3);
        initwindow(false);
        break;
    case k_a:
        if (cheati == 0)
        {
            cheati = 1;
        }
        break;
    case k_f1:
        sethelp(1);
        break;
    case k_f12:
        sethelp(-1);
        break;
    }
    if (helpi == 0)
    {
        switch (key)
        {
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
        }
        if (cheati == 2)
        {
            switch (key)
            {
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
        }
    }
    else
    {
        if (key == k_enter || key == k_space)
        {
            helpi = 0;
            bd.pause();
            initwindow(false);
        }
        if (helpi > 0)
        {
            if (key == k_left && helpi > 1)
            {
                helpi--;
            }
            if (key == k_right && helpi < maxhelp)
            {
                helpi++;
            }
        }
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
        if (ismsg(WM_PAINT))
        {
            paintevent();
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
