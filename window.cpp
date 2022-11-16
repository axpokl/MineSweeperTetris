class Window
{
public:

    const long titlew = 320;
    const long titleh = 384;
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
    const long clickw = 48;
    const long clickh = 72;

    pbitmap ptitle_;
    pbitmap pmenu_;
    pbitmap pmenu1[2];
    pbitmap pmenu2[2];
    pbitmap pmenu3[2];
    pbitmap pmenuq[2];
    pbitmap pmenua[2];
    pbitmap pmenus[2];
    pbitmap pmenum[2];
    pbitmap pmenud[2];
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
    pbitmap picona;
    pbitmap piconu;
    pbitmap picont;
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
    pbitmap pclickn;

    const long cbg = 0xAFAFAF;
    const long cfg = 0xC0C0C0;
    HICON hicon;
    Board bd;
    Block bl;
    const long maxhelp = 7;
    long helpi = 0;
    long cheati = 0;

    Window();
    void initwindow();
    void initwindow(bool b);
    void initbmp();
    void paintmenu();
    void paintface();
    void paintnumber(long n, long l, long x, long y);
    void paintdigit();
    void paintblock(Block &bd0, long i, long j, long x, long y, long w, long h);
    void paintboard(Block b, long x, long y);
    void paintboard(Block b, long x, long y, long cx, long cy);
    void paintboard();
    void paintline(pbitmap p, long n, long x, long y);
    void paintline(pbitmap pa, pbitmap pb, long a, long b, long x, long y);
    void paintline(pbitmap pa, pbitmap pb, pbitmap pc, long a, long b, long c, long x, long y);
    void paintline(pbitmap pa, pbitmap pb, pbitmap pc, pbitmap pd, long a, long b, long c, long d, long x, long y);
    void paintline(pbitmap pa, pbitmap pb, pbitmap pc, pbitmap pd, pbitmap pe, long a, long b, long c, long d, long e, long x, long y);
    void painthelp();
    void painttitle();
    void paintevent();
    bool isin(long ex, long ey, long x, long y, long w, long h);
    void sethelp(long helpi_);
    void mouseevent(long x, long y, long key);
    void keyevent(long key);
    void doaction();

};

Window::Window()
{
    initwindow();
}

void Window::initwindow()
{
    createwin(titlew, titleh, cbg, cbg, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_VISIBLE, "MineSweeperTetrisClass");
    hicon = (HICON)LoadImage(GetModuleHandle(NULL), "MINESWEEPERTETEIS_ICON", IMAGE_ICON, 0, 0, 0);
    SendMessage((HWND)gethwnd(), WM_SETICON, ICON_SMALL, (LPARAM)hicon);
    settitle("MineSweeper Tetris");
    setfontname("Arial");
    painttitle();
    initbmp();
}

void Window::initwindow(bool b)
{
    switch (helpi)
    {
    case -1:
        setsize(aboutw, abouth + menuh);
        break;
    case 0:
        if (b)
        {
            bd.mode = 0;
            bd.initbd();
        }
        setsize(bd.w * iconw, bd.h * iconh + faceh + menuh);
        break;
    default:
        setsize(helpw, helph + menuh);
        break;
    }
    setpos(max(0, (getscrwidth() - getwidth()) / 2), max(0, (getscrheight() - getheight()) / 2));
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
    for (long i = 0; i < 2; i++)
    {
        pmenu1[i] = createbmp(menuw, menuh);
        drawbmp(pmenu_, pmenu1[i], menuw * i, 0 * menuh, menuw, menuh, 0, 0, menuw, menuh);
        pmenu2[i] = createbmp(menuw, menuh);
        drawbmp(pmenu_, pmenu2[i], menuw * i, 1 * menuh, menuw, menuh, 0, 0, menuw, menuh);
        pmenu3[i] = createbmp(menuw, menuh);
        drawbmp(pmenu_, pmenu3[i], menuw * i, 2 * menuh, menuw, menuh, 0, 0, menuw, menuh);
        pmenuq[i] = createbmp(menuw, menuh);
        drawbmp(pmenu_, pmenuq[i], menuw * i, 3 * menuh, menuw, menuh, 0, 0, menuw, menuh);
        pmenua[i] = createbmp(menuw, menuh);
        drawbmp(pmenu_, pmenua[i], menuw * i, 4 * menuh, menuw, menuh, 0, 0, menuw, menuh);
        pmenus[i] = createbmp(menuw, menuh);
        drawbmp(pmenu_, pmenus[i], menuw * i, 5 * menuh, menuw, menuh, 0, 0, menuw, menuh);
        pmenum[i] = createbmp(menuw, menuh);
        drawbmp(pmenu_, pmenum[i], menuw * i, 6 * menuh, menuw, menuh, 0, 0, menuw, menuh);
        pmenud[i] = createbmp(menuw, menuh);
        drawbmp(pmenu_, pmenud[i], menuw * i, 7 * menuh, menuw, menuh, 0, 0, menuw, menuh);
    }
    for (long i = 0; i < 5; i++)
    {
        pface[i] = createbmp(facew, faceh);
        drawbmp(pface_, pface[i], 0, i * faceh, facew, faceh, 0, 0, facew, faceh);
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
    for (long i = 0; i < 9; i++)
    {
        picon[i] = createbmp(iconw, iconh);
        drawbmp(picon_, picon[i], 0, (16 - 1 - i) * iconh, iconw, iconh, 0, 0, iconw, iconh);
    }
    drawbmp(picon_, piconp, 0, iconh * 15, iconw, iconh, 0, 0, iconw, iconh);
    picona = createbmp(iconw, iconh);
    drawbmp(picon_, picona, 0, iconh * 16, iconw, iconh, 0, 0, iconw, iconh);
    piconu = createbmp(iconw, iconh);
    drawbmp(picon_, piconu, 0, iconh * 17, iconw, iconh, 0, 0, iconw, iconh);
    picont = createbmp(iconw, iconh);
    drawbmp(picon_, picont, 0, iconh * 18, iconw, iconh, 0, 0, iconw, iconh);
    for (long i = 0; i < 10; i++)
    {
        pdigit[i] = createbmp(digtw, digth);
        drawbmp(pdigit_, pdigit[i], 0, (11 - i) * digth, digtw, digth, 0, 0, digtw, digth);
    }
    pdigitmin = createbmp(digtw, digth);
    drawbmp(pdigit_, pdigitmin, 0, 0, digtw, digth, 0, 0, digtw, digth);
    pdigitnul = createbmp(digtw, digth);
    drawbmp(pdigit_, pdigitnul, 0, digth, digtw, digth, 0, 0, digtw, digth);
    pok = createbmp(okw, okh);
    drawbmp(pok_, pok, okh * 0, 0, okw, okh, 0, 0, okw, okh);
    pbtn = createbmp(btnw, btnh);
    drawbmp(pok_, pbtn, okw, 0, btnw, btnh, 0, 0, btnw, btnh);
    pclickl = createbmp(clickw, clickh);
    drawbmp(pclick_, pclickl, 0, clickh * 0, clickw, clickh, 0, 0, clickw, clickh);
    pclickr = createbmp(clickw, clickh);
    drawbmp(pclick_, pclickr, 0, clickh * 1, clickw, clickh, 0, 0, clickw, clickh);
    pclickn = createbmp(clickw, clickh);
    drawbmp(pclick_, pclickn, 0, clickh * 2, clickw, clickh, 0, 0, clickw, clickh);
}

void Window::paintmenu()
{

    drawbmp(pmenuq[(helpi > 0)], (getwidth() - 2 * menuw), 0, menuw, menuh);
    drawbmp(pmenua[(helpi < 0)], (getwidth() - 1 * menuw), 0, menuw, menuh);
    if (cheati == 2)
    {
        drawbmp(pmenud[(cheati == 2)], (getwidth() - 5 * menuw), 0, menuw, menuh);
    }
    drawbmp(pmenus[bd.sd.soundb], (getwidth() - 4 * menuw), 0, menuw, menuh);
    drawbmp(pmenum[bd.sd.musicb], (getwidth() - 3 * menuw), 0, menuw, menuh);
    drawbmp(pmenu1[(bd.mode == 1)], 0 * menuw, 0, menuw, menuh);
    drawbmp(pmenu2[(bd.mode == 2)], 1 * menuw, 0, menuw, menuh);
    drawbmp(pmenu3[(bd.mode == 3)], 2 * menuw, 0, menuw, menuh);
}

void Window::paintface()
{
    long face__[6] = {4, 4, 3, 1, 2, 0};
    long facei = bd.sit;
    if (facei == 1 && bd.checkr)
    {
        facei++;
    }
    drawbmp(pface[face__[facei]], (getwidth() - facew) / 2, menuh, facew, faceh);
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


void Window::paintline(pbitmap p, long n, long x, long y)
{
    for (long k = 0; k < n; k++)
    {
        drawbmp(p, x + k * iconw, y, iconw, iconh);
    }
}


void Window::paintline(pbitmap pa, pbitmap pb, long a, long b, long x, long y)
{
    paintline(pa, a, x, y);
    paintline(pb, b, x + iconw * a, y);
}

void Window::paintline(pbitmap pa, pbitmap pb, pbitmap pc, long a, long b, long c, long x, long y)
{
    paintline(pa, pb, a, b, x, y);
    paintline(pc, c, x + iconw * (a + b), y);
}

void Window::paintline(pbitmap pa, pbitmap pb, pbitmap pc, pbitmap pd, long a, long b, long c, long d, long x, long y)
{
    paintline(pa, pb, pc, a, b, c, x, y);
    paintline(pd, d, x + iconw * (a + b + c), y);
}

void Window::paintline(pbitmap pa, pbitmap pb, pbitmap pc, pbitmap pd, pbitmap pe, long a, long b, long c, long d, long e, long x, long y)
{
    paintline(pa, pb, pc, pd, a, b, c, d, x, y);
    paintline(pe, e, x + iconw * (a + b + c + d), y);
}

void Window::painthelp()
{
    switch (helpi)
    {
    case -1:
        setfontheight(fontfh);
        drawtextxy(getwin(), "About", 0, menuh, aboutw, fontth, black, cbg);
        setfontheight(fonth);
        drawtextxy(getwin(), "MineSwepper Tetris (32-bit)", 0, menuh + fontth, aboutw, fonth, black, cbg);
        drawtextxy(getwin(), "Version 0.1 (Steam)", 0, menuh + fontth + fonth, aboutw, fonth, black, cbg);
        drawtextxy(getwin(), "Made by ax_pokl", 0, menuh + fontth + fonth * 2, aboutw, fonth, black, cbg);
        drawtextxy(getwin(), "Licensed under GPL-3.0", 0, menuh + fontth + fonth * 3, aboutw, fonth, black, cbg);
        break;
    case 1:
        for (long j = 0; j < 3; j++)
        {
            for (long i = 0; i < 4; i++)
            {
                bl.initbl();
                long j_ = min(j, 1);
                switch (j)
                {
                case 0:
                    if (i == 1 || i == 3)
                    {
                        bl.blck[1][j_] = true;
                    }
                    break;
                case 1:
                    if (i == 1 || i == 3)
                    {
                        bl.flag[1][j_] = true;
                    }
                    break;
                case 2:
                    if (i == 1)
                    {
                        bl.qstn[1][j_] = true;
                    }
                    break;
                }
                if (i == 2)
                {
                    bl.qstn[1][j_] = true;
                }
                paintboard(bl, helpw * (i * 2 + 1) / 8 - bl.w * iconw / 2, (helph - okh_) * (j * 2 + 1) / 6 - bl.h * iconh / 2, 1, j_);
            }
        }
        for (long i = 0; i < 3; i++)
        {
            for (long j = 0; j < 3; j++)
            {
                pbitmap picon__[3][3][5] =
                {
                    {{piconc,picona,picon[3],piconp,piconp},{piconp,piconp,piconp,piconp,piconp},{piconq,picona,picon[3],piconp,piconp}},
                    {{piconc,picona,piconm,picona,piconf},{piconp,piconp,piconp,piconp,piconp},{piconq,picona,piconm,picona,piconf}},
                    {{piconc,picona,piconq,piconp,piconp},{piconp,piconp,piconp,piconp,piconp},{piconq,picona,piconc,piconp,piconp}}
                };
                long k__[3][3] = {{3, 0, 3}, {5, 0, 5}, {3, 0, 3}};
                if ((i == 0 || i == 2) && j != 2)
                {
                    drawbmp(pclickl, helpw * (i * 2 + 2) / 8 - clickw / 2, (helph - okh_) * (j * 2 + 1) / 6 - iconh * 3 + menuh, cfg);
                }
                else if ((i == 0 || i == 2) && j == 2)
                {
                    drawbmp(pclickr, helpw * (i * 2 + 2) / 8 - clickw / 2, (helph - okh_) * (j * 2 + 1) / 6 - iconh * 3 + menuh, cfg);
                }
                for (long k = 0; k < k__[j][i]; k++)
                {
                    drawbmp(picon__[j][i][k], helpw * (i * 2 + 2) / 8 + iconw * (k * 2 - k__[j][i]) / 2, (helph - okh_) * (j * 2 + 1) / 6 - iconh * 3 + clickh + menuh, cfg);
                }
            }
        }
        line(helpw / 2, menuh, 0, helph - okh_, cfg);
        for (long k = 0; k <= 3; k++)
        {
            line(0, menuh + (helph - okh_) * k / 3, helpw, 0, cfg);
        }
        break;
    case 2:
        for (long j = 0; j < 3; j++)
        {
            for (long i = 0; i < 4; i++)
            {
                bl.initbl();
                bl.blck[1][0] = true;
                bl.flag[1][1] = true;
                long j_ = 2;
                switch (j)
                {
                case 0:
                    if (i <= 1)
                    {
                        j_ = 0;
                    }
                    if (i == 0)
                    {
                        bl.qstn[0][1] = true;
                    }
                    if (i >= 1)
                    {
                        bl.flag[0][0] = true;
                        bl.flag[0][1] = true;
                    }
                    if (i == 3)
                    {
                        bl.blck[0][2] = true;
                        bl.blck[0][3] = true;
                    }
                    break;
                case 1:
                    bl.flag[1][1] = true;
                    if (i == 0)
                    {
                        bl.qstn[0][1] = true;
                    }
                    if (i >= 1)
                    {
                        bl.blck[0][2] = true;
                        bl.blck[0][3] = true;
                    }

                    if (i == 2)
                    {
                        bl.flag[0][1] = true;
                    }
                    break;
                case 2:
                    bl.flag[1][1] = true;
                    if (i == 0)
                    {
                        bl.qstn[0][3] = true;
                    }
                    if (i >= 1)
                    {
                        bl.blck[0][2] = true;
                        bl.flag[0][1] = true;
                    }
                    if (i == 2)
                    {
                        bl.blck[0][3] = true;
                    }
                    break;
                }
                if (j == 0 || i<= 2)
                {
                    paintboard(bl, helpw * (i * 2 + 1 + (j != 0)) / 8 - bl.w * iconw / 2, (helph - okh_) * (j * 2 + 1) / 6 - bl.h * iconh / 2, 1, j_);
                }
            }
        }
        for (long i = 0; i < 3; i++)
        {
            for (long j = 0; j < 3; j++)
            {
                pbitmap picon__[3][4][5] =
                {
                    {{piconc,piconq,piconf,piconu,picon[3]},{piconp,piconp,piconp,piconp,piconp},{piconf,piconu,picon[2],piconp,piconp}},
                    {{piconq,piconf,piconu,picon[2],piconp},{piconc,piconq,piconf,piconu,picon[2]},{piconp,piconp,piconp,piconp,piconp}},
                    {{piconq,piconf,piconu,picon[2],piconp},{piconf,piconu,picon[2],piconp,piconp},{piconp,piconp,piconp,piconp,piconp}}
                };
                long k__[3][3] = {{5, 0, 3}, {4, 5, 0}, {4, 3, 0}};
                if (i == 0 || (i == 2 && j == 0))
                {
                    drawbmp(pclickr, helpw * (i * 2 + 2 + (j != 0)) / 8 - clickw / 2, (helph - okh_) * (j * 2 + 1) / 6 - iconh * 3 + menuh, cfg);
                }
                else if (i == 1 && j != 0)
                {
                    drawbmp(pclickn, helpw * (i * 2 + 2 + (j != 0)) / 8 - clickw / 2, (helph - okh_) * (j * 2 + 1) / 6 - iconh * 3 + menuh, cfg);
                }
                for (long k = 0; k < k__[j][i]; k++)
                {
                    drawbmp(picon__[j][i][k], helpw * (i * 2 + 2 + (j != 0)) / 8 + iconw * (k * 2 - k__[j][i]) / 2, (helph - okh_) * (j * 2 + 1) / 6 - iconh * 3 + clickh + menuh, cfg);
                }
            }
        }
        line(helpw / 2, menuh, 0, (helph - okh_) / 3, cfg);
        for (long k = 0; k <= 3; k++)
        {
            line(0, menuh + (helph - okh_) * k / 3, helpw, 0, cfg);
        }
        break;
    case 3:
    {
        long iconwl = 5;
        long iconwm = iconwl + 13;
        long iconwr = iconwl + 15;
        long iconwn = iconwr + 14;
        long iconh1 = 2;
        long iconh2 = 10;
        long iconh3 = 21;
        paintline(picone, 2, iconw * iconwr, iconh * (iconh1 + 0) + menuh);
        paintline(piconc, 12, iconw * iconwr, iconh * (iconh1 + 1) + menuh);
        paintline(piconc, 12, iconw * iconwr, iconh * (iconh1 + 2) + menuh);
        paintline(picone, 2, iconw * iconwl, iconh * (iconh1 + 2) + menuh);
        paintline(piconc, piconm, picon[1], piconp, 5, 1, 1, 5, iconw * iconwl, iconh * (iconh1 + 3) + menuh);
        paintline(piconc, piconf, picon[1], piconp, 5, 1, 1, 5, iconw * iconwr, iconh * (iconh1 + 3) + menuh);
        drawbmp(picona, iconw * iconwm, iconh * (iconh1 + 3) + menuh, cfg);
        for (long k = 0; k <= 2; k++)
        {
            paintline(picone, 2, iconw * iconwl, iconh * (k * 3 + (iconh2 + 0)) + menuh);
            paintline(picone, k + 3, iconw * iconwr, iconh * (k * 3 + (iconh2 + 0)) + menuh);
            paintline(piconc, 12, iconw * iconwl, iconh * (k * 3 + (iconh2 + 1)) + menuh);
            paintline(piconc, 12, iconw * iconwr, iconh * (k * 3 + (iconh2 + 1)) + menuh);
            paintnumber(k * 5, 2, iconw * iconwn, iconh * (k * 3 + (iconh2 + 1)) + menuh - faceh / 2);
            drawbmp(picona, iconw * iconwm, iconh * (k * 3 + (iconh2 + 1)) + menuh, cfg);
        }
        paintline(picone, 12, iconw * iconwl, iconh * (iconh3 + 0) + menuh);
        paintline(piconc, 12, iconw * iconwr, iconh * (iconh3 + 0) + menuh);
        paintline(piconc, 12, iconw * iconwl, iconh * (iconh3 + 1) + menuh);
        paintline(piconc, 12, iconw * iconwr, iconh * (iconh3 + 1) + menuh);
        drawbmp(picona, iconw * iconwm, iconh * (iconh3 + 1) + menuh, cfg);
        line(0, menuh, helpw, 0, cfg);
        line(0, menuh + iconh * (iconh2 - 2), helpw, 0, cfg);
        line(0, menuh + iconh * (iconh3 - 2) + iconh / 2, helpw, 0, cfg);
        line(0, menuh + helph - okh_, helpw, 0, cfg);
        break;
    }
    case 4:
    {
        long iconwl = 3;
        long iconwm = iconwl + 13;
        long iconwr = iconwl + 17;
        long iconwn = iconwr + 14;
        long iconh1 = 2;
        long iconh2 = 6;
        paintline(piconc, picon[2], piconp, 4, 1, 7, iconw * iconwl, iconh * (iconh1 + 0) + menuh);
        paintline(piconc, piconf, picon[2], piconp, 2, 2, 1, 7, iconw * iconwl, iconh * (iconh1 + 1) + menuh);
        paintline(piconc, piconf, picon[3], picon[1], piconp, 2, 1, 1, 1, 7, iconw * iconwl, iconh * (iconh1 + 2) + menuh);
        paintline(piconc, picon[1], piconp, 4, 1, 7, iconw * iconwr, iconh * (iconh1 + 1) + menuh);
        paintline(piconc, piconf, picon[3], picon[1], piconp, 2, 1, 1, 1, 7, iconw * iconwr, iconh * (iconh1 + 2) + menuh);
        line(iconw * iconwl, iconh * (iconh1 + 2) - iconh / 2 + menuh, iconw * 12, 0, red);
        drawbmp(piconf, iconw * (iconwm + 0), iconh * (iconh1 + 2) + menuh, cfg);
        drawbmp(piconu, iconw * (iconwm + 1), iconh * (iconh1 + 2) + menuh, cfg);
        drawbmp(picon[2], iconw * (iconwm + 2), iconh * (iconh1 + 2) + menuh, cfg);
        paintnumber(1, 4, iconw * iconwn, iconh * (iconh1 + 2) + menuh - faceh / 2);
        paintline(piconc, picon[2], piconp, 4, 1, 7, iconw * iconwl, iconh * (iconh2 + 0) + menuh);
        paintline(picon[1],  picon[4], piconc, picon[2], piconp, 1, 1, 2, 1, 7, iconw * iconwl, iconh * (iconh2 + 1) + menuh);
        paintline(piconc, piconc, picon[3], picon[1], piconp, 2, 1, 1, 1, 7, iconw * iconwl, iconh * (iconh2 + 2) + menuh);
        paintline(piconc, picon[1], piconp, 4, 1, 7, iconw * iconwr, iconh * (iconh2 + 1) + menuh);
        paintline(piconc, picon[3], picon[1], piconp, 3, 1, 1, 7, iconw * iconwr, iconh * (iconh2 + 2) + menuh);
        line(iconw * iconwl, iconh * (iconh2 + 2) - iconh / 2 + menuh, iconw * 12, 0, red);
        drawbmp(piconc, iconw * (iconwm + 0), iconh * (iconh2 + 2) + menuh, cfg);
        drawbmp(piconu, iconw * (iconwm + 1), iconh * (iconh2 + 2) + menuh, cfg);
        drawbmp(picon[2], iconw * (iconwm + 2), iconh * (iconh2 + 2) + menuh, cfg);
        paintnumber(2, 4, iconw * iconwn, iconh * (iconh2 + 2) + menuh - faceh / 2);
//消4
//line level *3
    }
    break;
    case 5:
//123大小
        break;
    case 6:
//按键
        break;
    }
    if (helpi > 0)
    {
        setfontheight(fonth);
        drawbmp(pok, getwin(), (helpw - okw) / 2, helph - (okh_ + okh) / 2 + menuh, okw, okh);
        drawtextxy(getwin(), "OK", (helpw - okw) / 2, helph - (okh_ + okh) / 2 + menuh, okw, okh, black, cfg);
        if (helpi > 1)
        {
            drawbmp(pbtn, getwin(), (helpw - okw) / 2 - btnw * 2, helph - (okh_ + okh) / 2 + menuh, btnw, btnh);
            drawtextxy(getwin(), "<", (helpw - okw) / 2 - btnw * 2, helph - (okh_ + okh) / 2 + menuh, btnw, btnh, black, cfg);
        }
        if (helpi < maxhelp)
        {
            drawbmp(pbtn, getwin(), (helpw + okw) / 2 + btnw, helph - (okh_ + okh) / 2 + menuh, btnw, btnh);
            drawtextxy(getwin(), ">", (helpw + okw) / 2 + btnw, helph - (okh_ + okh) / 2 + menuh, btnw, btnh, black, cfg);
        }
    }
    else if (helpi < 0)
    {
        setfontheight(fonth);
        drawbmp(pok, getwin(), (aboutw - okw) / 2, abouth - (okh_ + okh) / 2 + menuh, okw, okh);
        drawtextxy(getwin(), "OK", (aboutw - okw) / 2, abouth - (okh_ + okh) / 2 + menuh, okw, okh, black, cfg);
    }
}

void Window::painttitle()
{
    ptitle_ = loadbmp("./bmp/title.bmp");
    drawbmp(ptitle_, getwin(), (titlew - ptitle_->width) / 2, fontth, ptitle_->width, ptitle_->height, cfg);
    setfontheight(fontfh);
    drawtextxy(getwin(), "MineSwepper Tetris", 0, 0, titlew, fontth, black, cbg);
    drawtextxy(getwin(), "Made by ax_pokl", 0, fontth + ptitle_->height, titlew, fontth, black, cbg);
    setfontheight(fonth);
    freshwin();
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
        case k_space:
            bd.pause();
            break;
        }
        if (cheati == 2)
        {
            switch (key)
            {
            case k_a:
                bd.solve2();
                break;
            case k_s:
                bd.solve1();
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

