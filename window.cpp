class Window
{
public:

    const long launchw = 320;
    const long launchh = 320;
    const long titlew = 256;
    const long titleh = 256;
    const long menuw = 24;
    const long menuh = 24;
    const long facew = 24;
    const long faceh = 24;
    const long iconw = 16;
    const long iconh = 16;
    const long digtw = 13;
    const long digth = 24;
    const long okw = 144;
    const long okh = 36;
    const long btnw = 36;
    const long btnh = 36;
    const long aboutw = 320;
    const long abouth = 240;
    long aboutw_ = 0;
    const long helpw = 640;
    const long helph = 480;
    const long fontth = 64;
    const long fontfh = 32;
    const long fonth = 24;
    const long okh_ = abouth - (fontth + fonth * 4);
    const long clickw = 48;
    const long clickh = 72;
    const long arroww = 24;
    const long arrowh = 24;

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
    pbitmap pface[6];
    pbitmap picon_;
    pbitmap picon[11];
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
    pbitmap parrow_;
    pbitmap parrowl;
    pbitmap parrowr;
    pbitmap parrowu;
    pbitmap parrowd;
    pbitmap parrowm;
    pbitmap parrowp;

    const long cbg = 0xAFAFAF;
    const long cfg = 0xC0C0C0;
    HICON hicon;
    Board bd;
    Block bl;
    const long maxhelp = 6;
    long helpi = 0;
    bool cheatb = false;

    Window();
    void initwindow();
    void initwindow(bool b);
    void initbmp();
    void paintmenu();
    void paintface();
    void paintnumber(long n, long l, long x, long y);
    void paintlevel();
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
    createwin(launchw, launchh, cbg, cbg, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_VISIBLE, "MineSweeperTetrisClass");
    hicon = (HICON)LoadImage(GetModuleHandle(NULL), "MINESWEEPERTETEIS_ICON", IMAGE_ICON, 0, 0, 0);
    SendMessage((HWND)gethwnd(), WM_SETICON, ICON_SMALL, (LPARAM)hicon);
    settitle(bd.st.lan.LAN_TITLE);
    setfontname(bd.st.lan.LAN_FONT);
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
    parrow_ = loadbmp("./bmp/arrow.bmp");
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
    for (long i = 0; i < 6; i++)
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
    for (long i = 0; i <= 10; i++)
    {
        picon[i] = createbmp(iconw, iconh);
        drawbmp(picon_, picon[i], 0, (17 - 1 - i) * iconh, iconw, iconh, 0, 0, iconw, iconh);
    }
    drawbmp(picon_, piconp, 0, iconh * 16, iconw, iconh, 0, 0, iconw, iconh);
    picona = createbmp(iconw, iconh);
    drawbmp(picon_, picona, 0, iconh * 17, iconw, iconh, 0, 0, iconw, iconh);
    piconu = createbmp(iconw, iconh);
    drawbmp(picon_, piconu, 0, iconh * 18, iconw, iconh, 0, 0, iconw, iconh);
    picont = createbmp(iconw, iconh);
    drawbmp(picon_, picont, 0, iconh * 19, iconw, iconh, 0, 0, iconw, iconh);
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
    parrowl = createbmp(arroww, arrowh);
    drawbmp(parrow_, parrowl, 0, arrowh * 0, arroww, arrowh, 0, 0, arroww, arrowh);
    parrowr = createbmp(arroww, arrowh);
    drawbmp(parrow_, parrowr, 0, arrowh * 1, arroww, arrowh, 0, 0, arroww, arrowh);
    parrowu = createbmp(arroww, arrowh);
    drawbmp(parrow_, parrowu, 0, arrowh * 2, arroww, arrowh, 0, 0, arroww, arrowh);
    parrowd = createbmp(arroww, arrowh);
    drawbmp(parrow_, parrowd, 0, arrowh * 3, arroww, arrowh, 0, 0, arroww, arrowh);
    parrowm = createbmp(arroww, arrowh);
    drawbmp(parrow_, parrowm, 0, arrowh * 4, arroww, arrowh, 0, 0, arroww, arrowh);
    parrowp = createbmp(arroww, arrowh);
    drawbmp(parrow_, parrowp, 0, arrowh * 5, arroww, arrowh, 0, 0, arroww, arrowh);
}

void Window::paintmenu()
{
    drawbmp(pmenua[(helpi == -1)], (getwidth() - 1 * menuw), 0, menuw, menuh);
    drawbmp(pmenuq[(helpi >= +1)], (getwidth() - 2 * menuw), 0, menuw, menuh);
    drawbmp(pmenud[(helpi == -2)], (getwidth() - 3 * menuw), 0, menuw, menuh);
    drawbmp(pmenum[bd.sd.musicb], (getwidth() - 4 * menuw), 0, menuw, menuh);
    drawbmp(pmenus[bd.sd.soundb], (getwidth() - 5 * menuw), 0, menuw, menuh);
    drawbmp(pmenu1[(bd.mode == 1)], 0 * menuw, 0, menuw, menuh);
    drawbmp(pmenu2[(bd.mode == 2)], 1 * menuw, 0, menuw, menuh);
    drawbmp(pmenu3[(bd.mode == 3)], 2 * menuw, 0, menuw, menuh);
}

void Window::paintface()
{
    long face__[6] =
    {
        4, 4, 3, 1, 2, 0
    };
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
            drawbmp(pdigit[digit[di]], x + (dlm - di - 1) * digtw, y, digtw, digth);
        }
        else if (di == dl && minb)
        {
            drawbmp(pdigitmin, x + (dlm - di - 1) * digtw, y, digtw, digth);
        }
        else
        {
            drawbmp(pdigitnul, x + (dlm - di - 1) * digtw, y, digtw, digth);
        }
    }
}

void Window::paintlevel()
{
    if (bd.line < 10000)
    {
        paintnumber(bd.line, 4, 0, menuh);
    }
    else if (bd.line < 100000)
    {
        paintnumber(bd.line, 5, 0, menuh);
    }
    else
    {
        paintnumber(bd.line, 6, 0, menuh);
    }
    if (bd.level < 100)
    {
        paintnumber(bd.level, 2, getwidth() - 2 * digtw, menuh);
    }
    else
    {
        paintnumber(bd.level, 3, getwidth() - 3 * digtw, menuh);
    }
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
            {
                setfontheight(fontfh);
                drawtextxy(getwin(), bd.st.lan.LAN_ABOUT_TITLE, fontfh / 2, menuh, aboutw, fontth, black, cbg);
                aboutw_ = getstringwidth(bd.st.lan.LAN_ABOUT_TITLE) + getstringwidth("  ");
                pbitmap pcheat__[2] = {piconn, piconm};
                drawbmp(pcheat__[cheatb], (aboutw - fontfh - aboutw_) / 2, (fontth - fontfh) / 2 + menuh, fontfh, fontfh, cbg);
                setfontheight(fonth);
                drawtextxy(getwin(), bd.st.lan.LAN_ABOUT_NAME, 0, menuh + fontth, aboutw, fonth, black, cbg);
                drawtextxy(getwin(), bd.st.lan.LAN_ABOUT_VERSION, 0, menuh + fontth + fonth, aboutw, fonth, black, cbg);
                drawtextxy(getwin(), bd.st.lan.LAN_ABOUT_AUTHOR, 0, menuh + fontth + fonth * 2, aboutw, fonth, black, cbg);
                drawtextxy(getwin(), bd.st.lan.LAN_ABOUT_LICENSE, 0, menuh + fontth + fonth * 3, aboutw, fonth, black, cbg);
                break;
            }
        case -2:
            {
                break;
            }
        case 1:
            {
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
                            if (picon__[j][i][k] == picona)
                            {
                                drawbmp(picon__[j][i][k], helpw * (i * 2 + 2) / 8 + iconw * (k * 2 - k__[j][i]) / 2, (helph - okh_) * (j * 2 + 1) / 6 - iconh * 3 + clickh + menuh, cfg);
                            }
                            else
                            {
                                drawbmp(picon__[j][i][k], helpw * (i * 2 + 2) / 8 + iconw * (k * 2 - k__[j][i]) / 2, (helph - okh_) * (j * 2 + 1) / 6 - iconh * 3 + clickh + menuh, cbg);
                            }
                        }
                    }
                }
                line(helpw / 2, menuh, 0, helph - okh_, cfg);
                for (long k = 1; k <= 2; k++)
                {
                    line(0, menuh + (helph - okh_) * k / 3, helpw, 0, cfg);
                }
                break;
            }
        case 2:
            {
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

                            if (picon__[j][i][k] == piconu)
                            {
                                drawbmp(picon__[j][i][k], helpw * (i * 2 + 2 + (j != 0)) / 8 + iconw * (k * 2 - k__[j][i]) / 2, (helph - okh_) * (j * 2 + 1) / 6 - iconh * 3 + clickh + menuh, cfg);
                            }
                            else
                            {
                                drawbmp(picon__[j][i][k], helpw * (i * 2 + 2 + (j != 0)) / 8 + iconw * (k * 2 - k__[j][i]) / 2, (helph - okh_) * (j * 2 + 1) / 6 - iconh * 3 + clickh + menuh, cbg);
                            }
                        }
                    }
                }
                line(helpw / 2, menuh, 0, (helph - okh_) / 3, cfg);
                for (long k = 1; k <= 2; k++)
                {
                    line(0, menuh + (helph - okh_) * k / 3, helpw, 0, cfg);
                }
                break;
            }
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
                    paintnumber(k * 5, 2, iconw * iconwn, iconh * (k * 3 + (iconh2 + 1)) + menuh - digth / 2);
                    drawbmp(picona, iconw * iconwm, iconh * (k * 3 + (iconh2 + 1)) + menuh, cfg);
                }
                paintline(picone, 12, iconw * iconwl, iconh * (iconh3 + 0) + menuh);
                paintline(piconc, 12, iconw * iconwr, iconh * (iconh3 + 0) + menuh);
                paintline(piconc, 12, iconw * iconwl, iconh * (iconh3 + 1) + menuh);
                paintline(piconc, 12, iconw * iconwr, iconh * (iconh3 + 1) + menuh);
                drawbmp(picona, iconw * iconwm, iconh * (iconh3 + 1) + menuh, cfg);
                line(0, menuh + iconh * (iconh2 - 2), helpw, 0, cfg);
                line(0, menuh + iconh * (iconh3 - 2) + iconh / 2, helpw, 0, cfg);
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
                long iconh3 = 11;
                long iconh4 = 22;
                paintline(piconc, picon[2], piconp, 4, 1, 7, iconw * iconwl, iconh * (iconh1 + 0) + menuh);
                paintline(piconc, piconf, picon[2], piconp, 2, 2, 1, 7, iconw * iconwl, iconh * (iconh1 + 1) + menuh);
                paintline(piconc, piconf, picon[3], picon[1], piconp, 2, 1, 1, 1, 7, iconw * iconwl, iconh * (iconh1 + 2) + menuh);
                paintline(piconc, picon[1], piconp, 4, 1, 7, iconw * iconwr, iconh * (iconh1 + 1) + menuh);
                paintline(piconc, piconf, picon[3], picon[1], piconp, 2, 1, 1, 1, 7, iconw * iconwr, iconh * (iconh1 + 2) + menuh);
                line(iconw * iconwl, iconh * (iconh1 + 1) + iconh / 2 + menuh, iconw * 12, 0, red);
                drawbmp(piconf, iconw * (iconwm + 0), iconh * (iconh1 + 2) + menuh, cbg);
                drawbmp(piconu, iconw * (iconwm + 1), iconh * (iconh1 + 2) + menuh, cfg);
                drawbmp(piconn, iconw * (iconwm + 2), iconh * (iconh1 + 2) + menuh, cbg);
                paintnumber(1, 4, iconw * iconwn, iconh * (iconh1 + 2) + menuh - digth / 2);
                paintline(piconc, picon[2], piconp, 4, 1, 7, iconw * iconwl, iconh * (iconh2 + 0) + menuh);
                paintline(picon[1],  picon[4], piconc, picon[2], piconp, 1, 1, 2, 1, 7, iconw * iconwl, iconh * (iconh2 + 1) + menuh);
                paintline(piconc, piconc, picon[3], picon[1], piconp, 2, 1, 1, 1, 7, iconw * iconwl, iconh * (iconh2 + 2) + menuh);
                paintline(piconc, picon[1], piconp, 4, 1, 7, iconw * iconwr, iconh * (iconh2 + 1) + menuh);
                paintline(piconc, picon[3], picon[1], piconp, 3, 1, 1, 7, iconw * iconwr, iconh * (iconh2 + 2) + menuh);
                line(iconw * iconwl, iconh * (iconh2 + 1) + iconh / 2 + menuh, iconw * 12, 0, red);
                drawbmp(piconc, iconw * (iconwm + 0), iconh * (iconh2 + 2) + menuh, cbg);
                drawbmp(piconu, iconw * (iconwm + 1), iconh * (iconh2 + 2) + menuh, cfg);
                drawbmp(piconn, iconw * (iconwm + 2), iconh * (iconh2 + 2) + menuh, cbg);
                paintnumber(1, 4, iconw * iconwn, iconh * (iconh2 + 2) + menuh - digth / 2);
                paintline(piconp, 12, iconw * iconwl, iconh * (iconh3 + 4) + menuh);
                line(iconw * iconwl, iconh * (iconh3 + 4) + iconh / 2 + menuh, iconw * 12, 0, red);
                for (long k = 0; k < 8; k++)
                {
                    if (k > 4)
                    {
                        paintline(piconc, 12, iconw * iconwl, iconh * (iconh3 + k) + menuh);
                    }
                    if (k > 0)
                    {
                        paintline(piconc, 12, iconw * iconwr, iconh * (iconh3 + k) + menuh);
                    }
                }
                drawbmp(picona, iconw * (iconwm + 1), iconh * (iconh3 + 7) + menuh, cfg);
                paintnumber(5, 4, iconw * iconwn, iconh * (iconh3 + 7) + menuh - digth / 2);
                for (long k = 0; k < 3; k++)
                {
                    paintnumber((k + 2) * (k + 2), 4, helpw * (k * 2 + 1) / 6 - 4 * digtw - 1 * iconw / 2, iconh * iconh4 + menuh - digth / 2 + iconw / 2);
                    paintnumber((k + 2), 2, helpw * (k * 2 + 1) / 6 + 2 * digtw + 1 * iconw / 2, iconh * iconh4 + menuh - digth / 2 + iconw / 2);
                    drawbmp(picona, helpw * (k * 2 + 1) / 6 + digtw - iconw / 2, iconh * iconh4 + menuh, cfg);
                    line(0, menuh + iconh * (iconh3 - 1) + iconh / 2, helpw, 0, cfg);
                    line(0, menuh + iconh * (iconh4 - 2), helpw, 0, cfg);
                }
                line(helpw / 3 * 1, menuh + iconh * (iconh4 - 2), 0, helph - okh_ - iconh * (iconh4 - 2), cfg);
                line(helpw / 3 * 2, menuh + iconh * (iconh4 - 2), 0, helph - okh_ - iconh * (iconh4 - 2), cfg);
            }
            break;
        case 5:
            {
                for (long i = 0; i < 32; i++)
                {
                    for (long j = 0; j < 24; j++)
                    {
                        drawbmp(piconp, iconw * (4 + i), iconh / 2 + menuh + iconh * j, cfg);
                    }
                }
                for (long j = 0; j < 24; j++)
                {
                    drawbmp(picon[j % 10 + 1], iconw * 4, iconh / 2 + iconh * j + menuh, cbg);
                }
                for (long i = 0; i < 32; i++)
                {
                    drawbmp(picon[i % 10 + 1], iconw * 4 + iconw * i, iconh / 2 + menuh, cbg);
                }
                drawbmp(pmenu1[0], iconw * 4 + iconw * 12 - menuw, iconh / 2 + menuh + iconh * 12 - menuh, cbg);
                drawbmp(pmenu2[0], iconw * 4 + iconw * 16 - menuw, iconh / 2 + menuh + iconh * 16 - menuh, cbg);
                drawbmp(pmenu3[0], iconw * 4 + iconw * 32 - menuw, iconh / 2 + menuh + iconh * 24 - menuh, cbg);
                paintline(piconn, 2, iconw * 4 + iconw, iconh / 2 + menuh + iconh * 12 - iconh);
                paintline(piconn, 3, iconw * 4 + iconw, iconh / 2 + menuh + iconh * 16 - iconh);
                paintline(piconn, 6, iconw * 4 + iconw, iconh / 2 + menuh + iconh * 24 - iconh);
                line(iconw * 4, iconh / 2 + menuh + iconh * 12 - 1, iconw * 12, 0, black);
                line(iconw * 4, iconh / 2 + menuh + iconh * 16 - 1, iconw * 16, 0, black);
                line(iconw * 4, iconh / 2 + menuh + iconh * 24 - 1, iconw * 32, 0, black);
                line(iconw * 4, iconh / 2 + menuh + iconh * 0 - 1, iconw * 32, 0, black);
                line(iconw * 4 + iconw * 12 - 1, iconh / 2 + menuh, 0, iconh * 12, black);
                line(iconw * 4 + iconw * 16 - 1, iconh / 2 + menuh, 0, iconh * 16, black);
                line(iconw * 4 + iconw * 32 - 1, iconh / 2 + menuh, 0, iconh * 24, black);
                line(iconw * 4 + iconw * 0 - 1, iconh / 2 + menuh, 0, iconh * 24, black);
                break;
            }
        case 6:
            {
                setfontheight(faceh);
                pbitmap pmenu__[11] = {pface[5], pmenua[0], pmenuq[0], pmenud[0], pmenus[0], pmenum[0], pface[4], pface[0], pmenu1[0], pmenu2[0], pmenu3[0]};
                const char* keys[11] = {"Q / ESC", "A / F12", "H / F1", "T / F2", "S / F3", "M / F4", "N / F5", "P / Space", "1", "2", "3"};
                const char* cheats[7] = {"Smart Solve", "Board Right ", "Auto Right", "Open Blank", "Add Line", "Del Line", "Up Level"};
                long cheatc[7] = {blue, blue, blue, blue, red, blue, red};
                long helph__ = (helph - okh_ - faceh * 11 - iconh * 10 / 2) / 2;
                long helpw__ = helpw / 6;
                if (cheatb)
                {
                    helpw__ = iconw;
                }
                for (long k = 0; k < 11; k++)
                {
                    drawbmp(pmenu__[k], helpw__, faceh * k + iconh * k / 2 + helph__ + menuh, facew, faceh, cfg);
                    drawtextxy(getwin(), keys[k],  helpw__ + facew + iconw, faceh * k + iconh * k / 2 + helph__ + menuh, black, cbg);
                }
                if (cheatb)
                {
                    for (long k = 0; k < 7; k++)
                    {
                        drawtextxy(getwin(), cheats[k], helpw / 4 + facew, faceh * k + iconh * k / 2 + helph__ + menuh, cheatc[k], cbg);
                        drawtextxy(getwin(), i2s((k + 4) % 10), helpw / 4, faceh * k + iconh * k / 2 + helph__ + menuh, cheatc[k], cbg);
                    }
                }
                line(helpw / 2, menuh, 0, helph - okh_, cfg);
                for (long k = 0; k < 12; k++)
                {
                    paintline(piconn, piconc, 2, 10, (helpw * 3 / 2 - iconw * 12) / 2, (helph - okh_ - iconh * 20) / 2 + menuh + iconh * (k + 8));
                }
                drawtextxy(getwin(), "PgUp", (helpw * 3 / 2 - getstringwidth("PgUp")) / 2, (helph - okh_ - iconh * 20) / 2 + menuh + iconh * 8 - faceh * 1, red, cbg);
                drawtextxy(getwin(), "PgDn", (helpw * 3 / 2 - getstringwidth("PgDn")) / 2, (helph - okh_ - iconh * 20) / 2 + menuh + iconh * 8 - faceh * 0, blue, cfg);
                bar((helpw * 3 / 2 - iconw * 12) / 2 + iconw * 2 - arroww * 1,  (helph - okh_ - iconh * 20) / 2 + menuh + iconh * 14 - arrowh / 2, arroww, arrowh, cfg);
                bar((helpw * 3 / 2 - iconw * 12) / 2 + iconw * 2 - arroww * 0,  (helph - okh_ - iconh * 20) / 2 + menuh + iconh * 14 - arrowh / 2, arroww, arrowh, cfg);
                bar((helpw * 3 / 2 - arroww) / 2,  (helph - okh_ - iconh * 20) / 2 + menuh + iconh * 20 - arrowh * 1, arroww, arrowh, cfg);
                bar((helpw * 3 / 2 - arroww) / 2,  (helph - okh_ - iconh * 20) / 2 + menuh + iconh * 20 - arrowh * 0, arroww, arrowh, cbg);
                bar((helpw * 3 / 2 - iconw * 12) / 2 + iconw * 12 - arroww * 1,  (helph - okh_ - iconh * 20) / 2 + menuh + iconh * 14 - arrowh / 2, arroww, arrowh, cfg);
                bar((helpw * 3 / 2 - iconw * 12) / 2 + iconw * 12 - arroww * 0,  (helph - okh_ - iconh * 20) / 2 + menuh + iconh * 14 - arrowh / 2, arroww, arrowh, cbg);
                drawbmp(parrowm, (helpw * 3 / 2 - iconw * 12) / 2 + iconw * 2 - arroww * 1,  (helph - okh_ - iconh * 20) / 2 + menuh + iconh * 14 - arrowh / 2, arroww, arrowh, cfg);
                drawbmp(parrowp, (helpw * 3 / 2 - iconw * 12) / 2 + iconw * 2 - arroww * 0,  (helph - okh_ - iconh * 20) / 2 + menuh + iconh * 14 - arrowh / 2, arroww, arrowh, cfg);
                drawbmp(parrowu, (helpw * 3 / 2 - arroww) / 2,  (helph - okh_ - iconh * 20) / 2 + menuh + iconh * 20 - arrowh * 1, arroww, arrowh, cfg);
                drawbmp(parrowd, (helpw * 3 / 2 - arroww) / 2,  (helph - okh_ - iconh * 20) / 2 + menuh + iconh * 20 - arrowh * 0, arroww, arrowh, cfg);
                drawbmp(parrowl, (helpw * 3 / 2 - iconw * 12) / 2 + iconw * 12 - arroww * 1,  (helph - okh_ - iconh * 20) / 2 + menuh + iconh * 14 - arrowh / 2, arroww, arrowh, cfg);
                drawbmp(parrowr, (helpw * 3 / 2 - iconw * 12) / 2 + iconw * 12 - arroww * 0,  (helph - okh_ - iconh * 20) / 2 + menuh + iconh * 14 - arrowh / 2, arroww, arrowh, cfg);
                line((helpw * 3 / 2 - iconw * 12) / 2, (helph - okh_ - iconh * 20) / 2 + menuh + iconh * 0 - 1, iconw * 12, 0, black);
                line((helpw * 3 / 2 - iconw * 12) / 2, (helph - okh_ - iconh * 20) / 2 + menuh + iconh * 8 - 1, iconw * 12, 0, black);
                line((helpw * 3 / 2 - iconw * 12) / 2, (helph - okh_ - iconh * 20) / 2 + menuh + iconh * 20 - 1, iconw * 12, 0, black);
                line((helpw * 3 / 2 - iconw * 12) / 2 + iconw * 0 - 1, (helph - okh_ - iconh * 20) / 2 + menuh, 0, iconh * 20, black);
                line((helpw * 3 / 2 - iconw * 12) / 2 + iconw * 2 - 1, (helph - okh_ - iconh * 4) / 2 + menuh, 0, iconh * 12, black);
                line((helpw * 3 / 2 - iconw * 12) / 2 + iconw * 12 - 1, (helph - okh_ - iconh * 20) / 2 + menuh, 0, iconh * 20, black);
            }
            break;
    }
    if (helpi == -1)
    {
        setfontheight(fonth);
        drawbmp(pok, getwin(), (aboutw - okw) / 2, abouth - (okh_ + okh) / 2 + menuh, okw, okh);
        drawtextxy(getwin(), "OK", (aboutw - okw) / 2, abouth - (okh_ + okh) / 2 + menuh, okw, okh, black, cfg);
    }
    else if (helpi != 0)
    {
        setfontheight(fonth);
        drawbmp(pok, getwin(), (helpw - okw) / 2, helph - (okh_ + okh) / 2 + menuh, okw, okh);
        drawtextxy(getwin(), "OK", (helpw - okw) / 2, helph - (okh_ + okh) / 2 + menuh, okw, okh, black, cfg);
        if (helpi > 1 && helpi <= maxhelp)
        {
            drawbmp(pbtn, getwin(), (helpw - okw) / 2 - btnw * 2, helph - (okh_ + okh) / 2 + menuh, btnw, btnh);
            drawtextxy(getwin(), "<", (helpw - okw) / 2 - btnw * 2, helph - (okh_ + okh) / 2 + menuh, btnw, btnh, black, cfg);
        }
        if (helpi >= 1 && helpi < maxhelp)
        {
            drawbmp(pbtn, getwin(), (helpw + okw) / 2 + btnw, helph - (okh_ + okh) / 2 + menuh, btnw, btnh);
            drawtextxy(getwin(), ">", (helpw + okw) / 2 + btnw, helph - (okh_ + okh) / 2 + menuh, btnw, btnh, black, cfg);
        }
        line(0, menuh, helpw, 0, cfg);
        line(0, menuh + helph - okh_, helpw, 0, cfg);
    }
}

void Window::painttitle()
{
    ptitle_ = loadbmp("./bmp/title.png");
    drawbmp(ptitle_, getwin(), (launchw - titlew) / 2, fontth, titlew, titleh, cfg);
    setfontheight(fontfh);
    drawtextxy(getwin(), bd.st.lan.LAN_TITLE, 0, fontth - fontfh, launchw, fontfh, black, cbg);
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
        paintlevel();
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
    if (helpi > 0 && helpi_ > 0)
    {
        helpi_ = helpi;
    }
    if ((helpi != helpi_) && (helpi_ != 0))
    {
        if (helpi == 0 && bd.sit != 5)
        {
            bd.pause();
        }
        helpi = helpi_;
        bd.sd.playsound(bd.sd.sLeft);
    }
    else
    {
        bd.pause();
        helpi = 0;
        bd.sd.playsound(bd.sd.sLeft);
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
        else if (ex > getwidth() - 5 * menuw)
        {
            switch ((ex - (getwidth() - 5 * menuw)) / menuw)
            {
                case 0:
                    bd.sd.switchsound();
                    break;
                case 1:
                    bd.sd.switchmusic();
                    break;
                case 2:
                    sethelp(-2);
                    break;
                case 3:
                    sethelp(1);
                    break;
                case 4:
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
                    if (bd.sit > 0)
                    {
                        bd.pause();
                        bd.sd.playsound(bd.sd.sSolve);
                        bd.st.addach(bd.st.achgenpause);
                    }
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
    else if (helpi == -1)
    {
        if (isin(ex, ey, (aboutw - okw) / 2, abouth - (okh_ + okh) / 2 + menuh, okw, okh))
        {
            sethelp(0);
        }
        if (isin(ex, ey, (aboutw - fontfh - aboutw_) / 2, (fontth - fontfh) / 2 + menuh, fontfh, fontfh))
        {
            if (!cheatb)
            {
                bd.sd.playsound(bd.sd.sSolve);
                cheatb = true;
                bd.st.cheatb = true;
                bd.st.addach(bd.st.achhidcheat);
            }
        }
    }
    else if (helpi != 0)
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
                bd.sd.playsound(bd.sd.sLeft);
            }
        }
        if (helpi < maxhelp)
        {
            if (isin(ex, ey, (helpw + okw) / 2 + btnw, helph - (okh_ + okh) / 2 + menuh, btnw, btnh))
            {
                helpi++;
                bd.sd.playsound(bd.sd.sLeft);
                if (helpi == maxhelp)
                {
                    bd.st.addach(bd.st.achgenhelp);
                }
            }
        }
    }
    paintevent();
}

void Window::keyevent(long key)
{
    switch (key)
    {
        case k_f12:
            sethelp(-1);
            break;
        case k_a:
            sethelp(-1);
            break;
        case k_f1:
            sethelp(1);
            break;
        case k_h:
            sethelp(1);
            break;
        case k_f2:
            sethelp(-2);
            break;
        case k_t:
            sethelp(-2);
            break;
        case k_f3:
            bd.sd.switchsound();
            break;
        case k_s:
            bd.sd.switchsound();
            break;
        case k_f4:
            bd.sd.switchmusic();
            break;
        case k_m:
            bd.sd.switchmusic();
            break;
        case k_f5:
            helpi = 0;
            bd.initbd();
            initwindow(false);
            break;
        case k_n:
            helpi = 0;
            bd.initbd();
            initwindow(false);
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
    }
    if (helpi == 0)
    {
        switch (key)
        {
            case k_esc:
                closewin();
                break;
            case k_q:
                closewin();
                break;
            case k_p:
                if (bd.sit > 0)
                {
                    bd.pause();
                    bd.sd.playsound(bd.sd.sSolve);
                    bd.st.addach(bd.st.achgenpause);
                }
                break;
            case k_space:
                bd.pause();
                bd.sd.playsound(bd.sd.sSolve);
                bd.st.addach(bd.st.achgenpause);
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
        }
        if (cheatb)
        {
            switch (key)
            {
                case k_4:
                    bd.solve2();
                    break;
                case k_5:
                    bd.solve1();
                    break;
                case k_6:
                    bd.solveb = true;
                    while (bd.solveb)
                    {
                        bd.solve1();
                    }
                    break;
                case k_7:
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
        if (key == k_enter || key == k_space || key == k_esc || key == k_q)
        {
            sethelp(0);
        }
        if (helpi > 0)
        {
            if (key == k_left && helpi > 1)
            {
                helpi--;
                bd.sd.playsound(bd.sd.sLeft);
            }
            if (key == k_right && helpi < maxhelp)
            {
                helpi++;
                bd.sd.playsound(bd.sd.sLeft);
                if (helpi == maxhelp)
                {
                    bd.st.addach(bd.st.achgenhelp);
                }
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

