class Window
{

public:

    const long launchw = 320;
    const long launchh = 352;
    const long titlew = 256;
    const long titleh = 256;
    const long menuw = 24;
    const long menuh = 24;
    const long facew = 24;
    const long faceh = 24;
    const long iconw = 16;
    const long iconh = 16;
    const long digtw[3] = {13, 9, 13};
    const long digth[3] = {24, 17, 24};
    const long okw = 144;
    const long okh = 36;
    const long btnw = 36;
    const long btnh = 36;
    const long tutw = 120;
    const long tuth = 36;
    const long aboutw = 360;
    const long abouth = 240;
    const long helpw = 640;
    const long helph = 480;
    const long fontth = 64;
    const long fontfh = 32;
    const long fonth = 24;
    const long fontsh = 17;
    const long fontmh = 13;
    const long okh_ = abouth - (fontth + fonth * 4);
    const long cursorw = 12;
    const long cursorh = 19;
    const long clickw = 48;
    const long clickh = 72;
    const long arroww = 24;
    const long arrowh = 24;

    pbitmap ptitle_ = NULL;
    pbitmap pbg_ = NULL;
    pbitmap pmenu_ = NULL;
    pbitmap pmenu1[2] = {NULL, NULL};
    pbitmap pmenu2[2] = {NULL, NULL};
    pbitmap pmenu3[2] = {NULL, NULL};
    pbitmap pmenuq[2] = {NULL, NULL};
    pbitmap pmenua[2] = {NULL, NULL};
    pbitmap pmenus[2] = {NULL, NULL};
    pbitmap pmenum[2] = {NULL, NULL};
    pbitmap pmenut[2] = {NULL, NULL};
    pbitmap pmenud[2] = {NULL, NULL};
    pbitmap pmenun[2] = {NULL, NULL};
    pbitmap pmenug[7][2] = {{NULL, NULL}, {NULL, NULL}, {NULL, NULL}, {NULL, NULL}, {NULL, NULL}, {NULL, NULL}, {NULL, NULL}};
    pbitmap pface_ = NULL;
    pbitmap pface[9] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    pbitmap picon_ = NULL;
    pbitmap picon[11] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    pbitmap piconc = NULL;
    pbitmap piconq = NULL;
    pbitmap piconf = NULL;
    pbitmap piconm = NULL;
    pbitmap picone = NULL;
    pbitmap piconn = NULL;
    pbitmap piconp = NULL;
    pbitmap picona = NULL;
    pbitmap piconu = NULL;
    pbitmap pdigt_[3] = {NULL, NULL, NULL};
    pbitmap pdigt[10][3] = {{NULL, NULL, NULL}, {NULL, NULL, NULL}, {NULL, NULL, NULL}, {NULL, NULL, NULL}, {NULL, NULL, NULL}, {NULL, NULL, NULL}, {NULL, NULL, NULL}, {NULL, NULL, NULL}, {NULL, NULL, NULL}, {NULL, NULL, NULL}};
    pbitmap pdigtmin[3] = {NULL, NULL, NULL};
    pbitmap pdigtnul[3] = {NULL, NULL, NULL};
    pbitmap pok_ = NULL;
    pbitmap pok = NULL;
    pbitmap pbtn = NULL;
    pbitmap pcursor_ = NULL;
    pbitmap pcursor = NULL;
    pbitmap pclick_ = NULL;
    pbitmap pclickl = NULL;
    pbitmap pclickr = NULL;
    pbitmap pclickn = NULL;
    pbitmap pclicka = NULL;
    pbitmap parrow_ = NULL;
    pbitmap parrowl = NULL;
    pbitmap parrowr = NULL;
    pbitmap parrowu = NULL;
    pbitmap parrowd = NULL;
    pbitmap parrowm = NULL;
    pbitmap parrowp = NULL;

    const long transparent = 0x000001;

    long color[9] = {0xc0c0c0, 0xAFAFAF, 0x010101, 0xc0c0c0, 0x0000ff, 0xff0000, 0x008000, 0x808080, 0xc0c0c0};
    long colori = 0;
    long cfg;
    long cbg;
    long ctfg;
    long ctbg;
    long cred;
    long cblue;
    long cgreen;
    long cline;
    long cmine;
    long transparent_ = 0xAFAFAF;

    bool isbmp = false;

    Reg reg;
    HICON hicon_res;
    HICON hicon_file;
    HICON hicon;
    Board bd;
    Block bl;
    const long maxhelp = 6;
    long helpi = 0;
    bool helpb = true;
    bool cheatb = false;
    bool waitb = false;
    pbitmap pwin = NULL;
    pbitmap pwint = NULL;
    const long minh = 600;
    const long minw = 800;
    long mult_ = 0;
    double mult = 1;
    WINDOWPLACEMENT wn;
    bool showmax = false;
    bool showmax_ = false;
    long w_ = 0;
    long h_ = 0;
    long x_ = 0;
    long y_ = 0;
    RECT rect;
    long xscr = 0;
    long yscr = 0;
    long wscr = 0;
    long hscr = 0;
    bool barb = true;
    long md = 0;
    bool ml = false;
    bool mr = false;
    long mx = -1;
    long my = -1;
    bool mi = false;
    long lead_5 = 0;
    bool singleb = false;
    long boardb = 0;

    Window();
    ~Window();
    void loadsetting();
    void savesetting();
    void loadboard();
    void saveboard();
    void initmult();
    void loadicon();
    void loadall();
    void initwindow();
    void releasewindow();
    void initwindow(bool b);
    void initcolor();
    void initbmp();
    void paintmenu();
    void paintface();
    void paintnumber(long n, long l, long x, long y, long w, long h, long b);
    void paintnumber(long n, long l, long x, long y, long b);
    void paintnumber(long n, long l, long x, long y);
    void paintlevel();
    void paintblock(Block &b, long i, long j, long x, long y, long w, long h);
    void paintboard(Block &b, long x, long y);
    void paintboard(Block &b, long x, long y, long cx, long cy);
    void paintboard();
    void paintline(pbitmap p, long n, long x, long y);
    void paintline(pbitmap pa, pbitmap pb, long a, long b, long x, long y);
    void paintline(pbitmap pa, pbitmap pb, pbitmap pc, long a, long b, long c, long x, long y);
    void paintline(pbitmap pa, pbitmap pb, pbitmap pc, pbitmap pd, long a, long b, long c, long d, long x, long y);
    void paintline(pbitmap pa, pbitmap pb, pbitmap pc, pbitmap pd, pbitmap pe, long a, long b, long c, long d, long e, long x, long y);
    void painthelp();
    void painttut();
    void painttitle(long load);
    void paintevent(bool freshb);
    void paintevent();
    bool isin(long ex, long ey, long x, long y, long w, long h);
    void sethelp(long helpi_);
    void savescr();
    void switchskin();
    void switchskin(long colori_);
    void switchmd();
    void switchmd(long md_);
    void tutevent(long ex, long ey, bool tutkb);
    void mouseeventboard_(long ex_, long ey_, long eb_, long md_);
    void mouseeventboard(long ex_, long ey_, long eb_, long md_);
    void mouseevent(long ex_, long ey_, long eb_);
    void keyevent(long key);
    void doaction();

    void setfontname_(const char* s);
    void setfontheight_(unsigned long h);
    void setfontweight_(unsigned long wg);
    void drawtextxy_(pbitmap b,const short int* s,long x,long y,unsigned long w,unsigned long h,unsigned long cfg,unsigned long cbg,unsigned long format);
    void drawtextxy_(pbitmap b,const short int* s,long x,long y,unsigned long w,unsigned long h,unsigned long cfg,unsigned long cbg);
    void drawtextxy_(pbitmap b,const char* s,long x,long y,unsigned long w,unsigned long h,unsigned long cfg,unsigned long cbg);
    void drawtextxy_(pbitmap b,const char* s,long x,long y,unsigned long cfg,unsigned long cbg);
    unsigned long getstringwidth_(const char* s);

#include "mon.cpp"
#include "utf.cpp"

};

Window::Window()
{
    initwindow();
}

Window::~Window()
{
    releasewindow();
}

void Window::loadsetting()
{
    reg.getreg(reg.regkey, "helpb", (long*)&helpb);
    reg.getreg(reg.regkey, "colori", (long*)&colori);
    reg.getreg(reg.regkey, "md", (long*)&md);
    reg.getreg(reg.regkey, "soundb", (long*)&bd.sd.soundb);
    reg.getreg(reg.regkey, "musicb", (long*)&bd.sd.musicb);
    reg.getreg(reg.regkey, "mult", (long*)&mult_);
    reg.getreg(reg.regkey, "delayb", (long*)&bd.delayb);
    reg.getreg(reg.regkey, "barb", (long*)&barb);
    reg.getreg(reg.regkey, "singleb", (long*)&singleb);
}

void Window::savesetting()
{
    reg.setreg(reg.regkey, "helpb", helpb);
    reg.setreg(reg.regkey, "colori", colori);
    reg.setreg(reg.regkey, "md", md);
    reg.setreg(reg.regkey, "soundb", bd.sd.soundb);
    reg.setreg(reg.regkey, "musicb", bd.sd.musicb);
    reg.setreg(reg.regkey, "mult", mult_);
    reg.setreg(reg.regkey, "delayb", bd.delayb);
    reg.setreg(reg.regkey, "barb", barb);
    reg.setreg(reg.regkey, "singleb", singleb);
}

void Window::loadboard()
{
    reg.getreg_(reg.regkey_, "flag", (char*)&bd.flag[0][0]);
    reg.getreg_(reg.regkey_, "qstn", (char*)&bd.qstn[0][0]);
    reg.getreg_(reg.regkey_, "mine", (char*)&bd.mine[0][0]);
    reg.getreg_(reg.regkey_, "blck", (char*)&bd.blck[0][0]);
    reg.getreg_(reg.regkey_, "mask", (char*)&bd.mask[0][0]);
    reg.getreg(reg.regkey_, "mode", (long*)&bd.mode);
    reg.getreg(reg.regkey_, "w", (long*)&bd.w);
    reg.getreg(reg.regkey_, "h", (long*)&bd.h);
    reg.getreg(reg.regkey_, "n", (long*)&bd.n);
    reg.getreg(reg.regkey_, "maskj0", (long*)&bd.maskj0);
    reg.getreg(reg.regkey_, "sit", (long*)&bd.sit);
    reg.getreg(reg.regkey_, "line", (long*)&bd.line);
    reg.getreg(reg.regkey_, "level", (long*)&bd.level);
    reg.getreg(reg.regkey_, "tetrisi", (long*)&bd.tetrisi);
    reg.getreg(reg.regkey_, "missi", (long*)&bd.missi);
    reg.getreg(reg.regkey_, "missline", (long*)&bd.missline);
    reg.getreg(reg.regkey_, "sum", (long*)&bd.sum);
    reg.getreg(reg.regkey_, "maskj", (long*)&bd.maskj);
    reg.getreg(reg.regkey_, "maski", (long*)&bd.maski);
    reg.getreg(reg.regkey_, "rightb", (long*)&bd.rightb);
    reg.getreg(reg.regkey_, "tuti", (long*)&bd.tuti);
    reg.getreg(reg.regkey_, "tutb", (long*)&bd.tutb);
    reg.getreg(reg.regkey_, "checkr", (long*)&bd.checkr);
    reg.getreg(reg.regkey_, "pauseb", (long*)&bd.pauseb);
    reg.getreg(reg.regkey_, "mx", (long*)&bd.mx);
    reg.getreg(reg.regkey_, "my", (long*)&bd.my);
    reg.getreg(reg.regkey_, "bouns", (long*)&bd.bouns);
    reg.getreg(reg.regkey_, "mdb", (long*)&bd.mdb);
    reg.getreg(reg.regkey_, "solven", (long*)&bd.solven);
    bd.calcnumb();
}

void Window::saveboard()
{
    reg.setreg_(reg.regkey_, "flag", (char*)&bd.flag[0][0]);
    reg.setreg_(reg.regkey_, "qstn", (char*)&bd.qstn[0][0]);
    reg.setreg_(reg.regkey_, "mine", (char*)&bd.mine[0][0]);
    reg.setreg_(reg.regkey_, "blck", (char*)&bd.blck[0][0]);
    reg.setreg_(reg.regkey_, "mask", (char*)&bd.mask[0][0]);
    reg.setreg(reg.regkey_, "mode", bd.mode);
    reg.setreg(reg.regkey_, "w", bd.w);
    reg.setreg(reg.regkey_, "h", bd.h);
    reg.setreg(reg.regkey_, "n", bd.n);
    reg.setreg(reg.regkey_, "maskj0", bd.maskj0);
    reg.setreg(reg.regkey_, "sit", bd.sit);
    reg.setreg(reg.regkey_, "line", bd.line);
    reg.setreg(reg.regkey_, "level", bd.level);
    reg.setreg(reg.regkey_, "tetrisi", bd.tetrisi);
    reg.setreg(reg.regkey_, "missi", bd.missi);
    reg.setreg(reg.regkey_, "missline", bd.missline);
    reg.setreg(reg.regkey_, "sum", bd.sum);
    reg.setreg(reg.regkey_, "maskj", bd.maskj);
    reg.setreg(reg.regkey_, "maski", bd.maski);
    reg.setreg(reg.regkey_, "rightb", bd.rightb);
    reg.setreg(reg.regkey_, "tuti", bd.tuti);
    reg.setreg(reg.regkey_, "tutb", bd.tutb);
    reg.setreg(reg.regkey_, "checkr", bd.checkr);
    reg.setreg(reg.regkey_, "pauseb", bd.pauseb);
    reg.setreg(reg.regkey_, "mx", bd.mx);
    reg.setreg(reg.regkey_, "my", bd.my);
    reg.setreg(reg.regkey_, "bouns", bd.bouns);
    reg.setreg(reg.regkey_, "mdb", bd.mdb);
    reg.setreg(reg.regkey_, "solven", bd.solven);
}

void Window::loadall()
{
    if (iswin())
    {
        loadsetting();
    }
    painttitle(bd.st.lan.LAN_LOAD_STEAM);
    if (iswin())
    {
        bd.st.loadsteam();
    }
    painttitle(bd.st.lan.LAN_LOAD_AUDIO);
    if (iswin())
    {
        bd.sd.initsound();
    }
    painttitle(bd.st.lan.LAN_LOAD_BOARD);
    if (iswin())
    {
        bd.initbd(1, md);
        reg.getreg(reg.regkey, "boardb", (long*)&boardb);
        bd.tutb = helpb;
        if (boardb == 1)
        {
            loadboard();
            boardb = 0;
            reg.setreg(reg.regkey, "boardb", boardb);
        }
    }
    painttitle(bd.st.lan.LAN_LOAD_GRAPH);
    if (iswin())
    {
        initbmp();
    }
    painttitle(bd.st.lan.LAN_LOAD_WINDOW);
    if (iswin())
    {
        SetWindowLongPtr((HWND)gethwnd(), GWL_STYLE, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_VISIBLE);
        sethelp(0);
    }
}

void Window::initmult()
{
    if (mult_ == 0)
    {
        mult = max(1, min((double)(wscr - getborderwidth() * 2) / max((double)minw, (double)w_), (double)(hscr - getborderheight() * 2 - getbordertitle()) / max((double)minh, (double)h_)));
        mult = (double)((int)(mult * 2) / (int)1) / (double)2.0;
    }
    else if (mult_ == 1)
    {
        mult = max(1, min((double)(wscr - getborderwidth() * 2) / (double)w_, (double)(hscr - getborderheight() * 2 - getbordertitle()) / (double)h_));
    }
    else
    {
        mult_ = min(max(mult_, 2), 8);
        mult = max(1, min((double)(wscr - getborderwidth() * 2) / (double)w_, (double)(hscr - getborderheight() * 2 - getbordertitle()) / (double)h_));
        mult = min(mult, (double)mult_ / 2.0);
    }
    bd.w_ = w_;
    bd.h_ = h_;
    bd.mult = mult;
}

void Window::loadicon()
{
    hicon_res = (HICON)LoadImage(MainInstance, "MINESWEEPERTETRIS_ICON", IMAGE_ICON, 0, 0, 0);
    hicon_file = (HICON)LoadImage(NULL, "./MineSweeperTetris.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE| LR_DEFAULTSIZE | LR_SHARED);
    if (hicon_res > 0)
    {
        hicon = hicon_res;
    }
    else
    {
        hicon = hicon_file;
    }
    SendMessage((HWND)gethwnd(), WM_SETICON, ICON_BIG, (LPARAM)hicon);
    delay(10);
    SendMessage((HWND)gethwnd(), WM_SETICON, ICON_SMALL, (LPARAM)hicon);
    delay(10);
}

void Window::initwindow()
{
    initcolor();
    SystemParametersInfoA(SPI_GETWORKAREA, 0, &rect, 0);
    wscr = rect.right - rect.left;
    hscr = rect.bottom - rect.top;
    w_ = launchw;
    h_ = launchh;
    reg.getreg(reg.regkey, "mult", (long*)&mult_);
    initmult();
    x_ = rect.left + max(0, (wscr - w_ * mult - getborderwidth() * 2) / 2);
    y_ = rect.top + max(0, (hscr - h_ * mult - getborderheight() * 2 - getbordertitle()) / 2);
    createwin(x_, y_, w_ * mult, h_ * mult, cbg, cbg, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_VISIBLE, "MineSweeperTetrisClass");
    pwin = createbmp(w_, h_);
    pwint = createbmp(w_ * mult, h_ * mult, transparent_);
    loadicon();
    settitlew(bd.st.lan.getlan(bd.st.lan.LAN_TITLE));
    LOGFONT lf;
    SystemParametersInfo(SPI_GETICONTITLELOGFONT, sizeof(LOGFONT),&lf,0);
    setfontname_(lf.lfFaceName);
    painttitle(-1);
    bd.maxbdw = (wscr - getborderwidth() * 2) / 16 - 1;
    bd.maxbdh = (hscr - menuh - faceh - getborderheight() * 2 - getbordertitle()) / 16 - 1;
}

void Window::releasewindow()
{
    savesetting();
    if (!cheatb && bd.sit > 0  && bd.sit < 4)
    {
        if (bd.tutb == 0)
        {
            bd.pauseb = 1;
        }
        saveboard();
        boardb = 1;
        reg.setreg(reg.regkey, "boardb", boardb);
    }
}

void Window::initwindow(bool b)
{
    if (iswin())
    {
        switch (helpi)
        {
            case -1:
                w_ = aboutw;
                h_ = abouth + menuh;
                break;
            case 0:
                if (b)
                {
                    bd.mode = 0;
                    bd.initbd();
                }
                w_ = bd.w * iconw;
                h_ = bd.h * iconh + faceh + menuh;
                break;
            default:
                w_ = helpw;
                h_ = helph + menuh;
                break;
        }
        initmult();
        x_ = rect.left + max(0, (wscr - w_ * mult - getborderwidth() * 2) / 2);
        y_ = rect.top + max(0, (hscr - h_ * mult - getborderheight() * 2 - getbordertitle()) / 2);
        releasebmp(pwin);
        releasebmp(pwint);
        pwin = createbmp(w_, h_);
        pwint = createbmp(w_ * mult, h_ * mult, transparent_);
        EnumDisplayMonitors(NULL, NULL, Monitorenumproc, (LPARAM)this);
        setsize(x_ + xscr, y_ + yscr, w_ * mult, h_ * mult);
        paintevent(false);
        freshwin();
    }
}

void Window::initcolor()
{
    cfg = color[0];
    cbg = color[1];
    ctfg = color[2];
    ctbg = color[3];
    cred = color[4];
    cblue = color[5];
    cgreen = color[6];
    cline = color[7];
    cmine = color[8];
    bd.cred = cred;
    transparent_ = cbg;
}

void Window::initbmp()
{
    if (iswin())
    {
        if (!isbmp)
        {
            for (long i = 0; i < 2; i++)
            {
                pmenu1[i] = createbmp(menuw, menuh);
                pmenu2[i] = createbmp(menuw, menuh);
                pmenu3[i] = createbmp(menuw, menuh);
                pmenuq[i] = createbmp(menuw, menuh);
                pmenua[i] = createbmp(menuw, menuh);
                pmenus[i] = createbmp(menuw, menuh);
                pmenum[i] = createbmp(menuw, menuh);
                pmenut[i] = createbmp(menuw, menuh);
                pmenud[i] = createbmp(menuw, menuh);
                pmenun[i] = createbmp(menuw, menuh);
                pmenug[0][i] = createbmp(menuw, menuh);
                pmenug[1][i] = createbmp(menuw, menuh);
                pmenug[2][i] = createbmp(menuw, menuh);
                pmenug[3][i] = createbmp(menuw, menuh);
                pmenug[4][i] = createbmp(menuw, menuh);
                pmenug[5][i] = createbmp(menuw, menuh);
                pmenug[6][i] = createbmp(menuw, menuh);
            }
            for (long i = 0; i < 9; i++)
            {
                pface[i] = createbmp(facew, faceh);
            }
            piconc = createbmp(iconw, iconh);
            piconf = createbmp(iconw, iconh);
            piconq = createbmp(iconw, iconh);
            piconm = createbmp(iconw, iconh);
            picone = createbmp(iconw, iconh);
            piconn = createbmp(iconw, iconh);
            for (long i = 0; i <= 10; i++)
            {
                picon[i] = createbmp(iconw, iconh);
            }
            piconp = createbmp(iconw, iconh);
            picona = createbmp(iconw, iconh);
            piconu = createbmp(iconw, iconh);
            for (long k = 0; k < 3; k++)
            {
                for (long i = 0; i < 10; i++)
                {
                    pdigt[i][k] = createbmp(digtw[k], digth[k]);
                }
                pdigtmin[k] = createbmp(digtw[k], digth[k]);
                pdigtnul[k] = createbmp(digtw[k], digth[k]);
            }
            pok = createbmp(okw, okh);
            pbtn = createbmp(btnw, btnh);
            pcursor = createbmp(cursorw, cursorh);
            pclickl = createbmp(clickw, clickh);
            pclickr = createbmp(clickw, clickh);
            pclickn = createbmp(clickw, clickh);
            pclicka = createbmp(clickw, clickh);
            parrowl = createbmp(arroww, arrowh);
            parrowr = createbmp(arroww, arrowh);
            parrowu = createbmp(arroww, arrowh);
            parrowd = createbmp(arroww, arrowh);
            parrowm = createbmp(arroww, arrowh);
            parrowp = createbmp(arroww, arrowh);
            isbmp = true;
        }
        else
        {
            releasebmp(pbg_);
            releasebmp(pmenu_);
            releasebmp(pface_);
            releasebmp(picon_);
            for (long k = 0; k < 3; k++)
            {
                releasebmp(pdigt_[k]);
            }
            releasebmp(pok_);
            releasebmp(pcursor_);
            releasebmp(pclick_);
            releasebmp(parrow_);
        }
        char pngPath[MAX_PATH];
        sprintf(pngPath, "./png/%d/bg.png", colori);
        pbg_ = loadbmp(pngPath);
        sprintf(pngPath, "./png/%d/menu.png", colori);
        pmenu_ = loadbmp(pngPath);
        sprintf(pngPath, "./png/%d/face.png", colori);
        pface_ = loadbmp(pngPath);
        sprintf(pngPath, "./png/%d/icon.png", colori);
        picon_ = loadbmp(pngPath);
        sprintf(pngPath, "./png/%d/digt.png", colori);
        pdigt_[0] = loadbmp(pngPath);
        sprintf(pngPath, "./png/%d/digt2.png", colori);
        pdigt_[1] = loadbmp(pngPath);
        sprintf(pngPath, "./png/%d/digt_.png", colori);
        pdigt_[2] = loadbmp(pngPath);
        sprintf(pngPath, "./png/%d/ok.png", colori);
        pok_ = loadbmp(pngPath);
        sprintf(pngPath, "./png/%d/cursor.png", colori);
        pcursor_ = loadbmp(pngPath);
        sprintf(pngPath, "./png/%d/click.png", colori);
        pclick_ = loadbmp(pngPath);
        sprintf(pngPath, "./png/%d/arrow.png", colori);
        parrow_ = loadbmp(pngPath);
        for (long k = 0; k < 9; k++)
        {
            color[k] = getpixel(pbg_, 0, k);
        }
        initcolor();
        for (long i = 0; i < 2; i++)
        {
            drawbmp(pmenu_, pmenu1[i], menuw * i, 0 * menuh, menuw, menuh, 0, 0, menuw, menuh);
            drawbmp(pmenu_, pmenu2[i], menuw * i, 1 * menuh, menuw, menuh, 0, 0, menuw, menuh);
            drawbmp(pmenu_, pmenu3[i], menuw * i, 2 * menuh, menuw, menuh, 0, 0, menuw, menuh);
            drawbmp(pmenu_, pmenuq[i], menuw * i, 3 * menuh, menuw, menuh, 0, 0, menuw, menuh);
            drawbmp(pmenu_, pmenua[i], menuw * i, 4 * menuh, menuw, menuh, 0, 0, menuw, menuh);
            drawbmp(pmenu_, pmenus[i], menuw * i, 5 * menuh, menuw, menuh, 0, 0, menuw, menuh);
            drawbmp(pmenu_, pmenum[i], menuw * i, 6 * menuh, menuw, menuh, 0, 0, menuw, menuh);
            drawbmp(pmenu_, pmenut[i], menuw * i, 7 * menuh, menuw, menuh, 0, 0, menuw, menuh);
            drawbmp(pmenu_, pmenud[i], menuw * i, 8 * menuh, menuw, menuh, 0, 0, menuw, menuh);
            drawbmp(pmenu_, pmenun[i], menuw * i, 9 * menuh, menuw, menuh, 0, 0, menuw, menuh);
            drawbmp(pmenu_, pmenug[0][i], menuw * i, 10 * menuh, menuw, menuh, 0, 0, menuw, menuh);
            drawbmp(pmenu_, pmenug[1][i], menuw * i, 11 * menuh, menuw, menuh, 0, 0, menuw, menuh);
            drawbmp(pmenu_, pmenug[2][i], menuw * i, 12 * menuh, menuw, menuh, 0, 0, menuw, menuh);
            drawbmp(pmenu_, pmenug[3][i], menuw * i, 13 * menuh, menuw, menuh, 0, 0, menuw, menuh);
            drawbmp(pmenu_, pmenug[4][i], menuw * i, 14 * menuh, menuw, menuh, 0, 0, menuw, menuh);
            drawbmp(pmenu_, pmenug[5][i], menuw * i, 15 * menuh, menuw, menuh, 0, 0, menuw, menuh);
            drawbmp(pmenu_, pmenug[6][i], menuw * i, 16 * menuh, menuw, menuh, 0, 0, menuw, menuh);
        }
        for (long i = 0; i < 9; i++)
        {
            drawbmp(pface_, pface[i], 0, i * faceh, facew, faceh, 0, 0, facew, faceh);
        }
        drawbmp(picon_, piconc, 0, iconh * 0, iconw, iconh, 0, 0, iconw, iconh);
        drawbmp(picon_, piconf, 0, iconh * 1, iconw, iconh, 0, 0, iconw, iconh);
        drawbmp(picon_, piconq, 0, iconh * 2, iconw, iconh, 0, 0, iconw, iconh);
        drawbmp(picon_, piconm, 0, iconh * 3, iconw, iconh, 0, 0, iconw, iconh);
        drawbmp(picon_, picone, 0, iconh * 4, iconw, iconh, 0, 0, iconw, iconh);
        drawbmp(picon_, piconn, 0, iconh * 5, iconw, iconh, 0, 0, iconw, iconh);
        for (long i = 0; i <= 10; i++)
        {
            drawbmp(picon_, picon[i], 0, (17 - 1 - i) * iconh, iconw, iconh, 0, 0, iconw, iconh);
        }
        drawbmp(picon_, piconp, 0, iconh * 16, iconw, iconh, 0, 0, iconw, iconh);
        drawbmp(picon_, picona, 0, iconh * 17, iconw, iconh, 0, 0, iconw, iconh);
        drawbmp(picon_, piconu, 0, iconh * 18, iconw, iconh, 0, 0, iconw, iconh);
        for (long k = 0; k < 3; k++)
        {
            for (long i = 0; i < 10; i++)
            {
                drawbmp(pdigt_[k], pdigt[i][k], 0, (11 - i) * digth[k], digtw[k], digth[k], 0, 0, digtw[k], digth[k]);
            }
            drawbmp(pdigt_[k], pdigtmin[k], 0, 0, digtw[k], digth[k], 0, 0, digtw[k], digth[k]);
            drawbmp(pdigt_[k], pdigtnul[k], 0, digth[k], digtw[k], digth[k], 0, 0, digtw[k], digth[k]);
        }
        drawbmp(pok_, pok, okh * 0, 0, okw, okh, 0, 0, okw, okh);
        drawbmp(pok_, pbtn, okw, 0, btnw, btnh, 0, 0, btnw, btnh);
        drawbmp(pcursor_, pcursor, 0, cursorh * 0, cursorw, cursorh, 0, 0, cursorw, cursorh);
        drawbmp(pclick_, pclickl, 0, clickh * 0, clickw, clickh, 0, 0, clickw, clickh);
        drawbmp(pclick_, pclickr, 0, clickh * 1, clickw, clickh, 0, 0, clickw, clickh);
        drawbmp(pclick_, pclickn, 0, clickh * 2, clickw, clickh, 0, 0, clickw, clickh);
        drawbmp(pclick_, pclicka, 0, clickh * 3, clickw, clickh, 0, 0, clickw, clickh);
        drawbmp(parrow_, parrowl, 0, arrowh * 0, arroww, arrowh, 0, 0, arroww, arrowh);
        drawbmp(parrow_, parrowr, 0, arrowh * 1, arroww, arrowh, 0, 0, arroww, arrowh);
        drawbmp(parrow_, parrowu, 0, arrowh * 2, arroww, arrowh, 0, 0, arroww, arrowh);
        drawbmp(parrow_, parrowd, 0, arrowh * 3, arroww, arrowh, 0, 0, arroww, arrowh);
        drawbmp(parrow_, parrowm, 0, arrowh * 4, arroww, arrowh, 0, 0, arroww, arrowh);
        drawbmp(parrow_, parrowp, 0, arrowh * 5, arroww, arrowh, 0, 0, arroww, arrowh);
    }
}

void Window::paintmenu()
{
    drawbmp(pmenua[(helpi == -1)], (w_ - 1 * menuw), 0, menuw, menuh);
    drawbmp(pmenuq[(helpi >= +1)], (w_ - 2 * menuw), 0, menuw, menuh);
    drawbmp(pmenud[(helpi == -3)], (w_ - 3 * menuw), 0, menuw, menuh);
    drawbmp(pmenut[(helpi == -2)], (w_ - 4 * menuw), 0, menuw, menuh);
    drawbmp(pface[6], (w_ - 5 * menuw), 0, menuw, menuh);
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
    if (facei == 1 && bd.checkr == 1)
    {
        facei++;
    }
    if (bd.pauseb >= 1)
    {
        facei = 5;
    }
    drawbmp(pface[face__[facei]], (w_ - facew) / 2, menuh, facew, faceh);
}

void Window::paintnumber(long n, long l, long x, long y, long w, long h, long b)
{
    long digt[10];
    long dl = 0;
    long dlm;
    bool minb = (n < 0);
    if (minb)
    {
        n = -n;
    }
    do
    {
        digt[dl] = n % 10;
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
            drawbmp(pdigt[digt[di]][b], x + (dlm - di - 1) * w, y, w, h);
        }
        else if (di == dl && minb)
        {
            drawbmp(pdigtmin[b], x + (dlm - di - 1) * w, y, w, h);
        }
        else
        {
            drawbmp(pdigtnul[b], x + (dlm - di - 1) * w, y, w, h);
        }
    }
}

void Window::paintnumber(long n, long l, long x, long y, long b)
{
    paintnumber(n, l, x, y, digtw[b], digth[b], b);
}

void Window::paintnumber(long n, long l, long x, long y)
{
    paintnumber(n, l, x, y, 0);
}

void Window::paintlevel()
{
    long score = bd.line;
    if (singleb)
    {
        score = bd.line - bd.missline;
    }
    if (score < 10000)
    {
        paintnumber(score, 4, 0, digth[0], singleb * 2);
    }
    else if (score < 100000)
    {
        paintnumber(score, 5, 0, digth[0], singleb * 2);
    }
    else
    {
        paintnumber(score, 6, 0, digth[0], singleb * 2);
    }
    long score2 = bd.level;
    if (singleb)
    {
        score2 = bd.solven;
    }
    if (score2 < 100)
    {
        paintnumber(score2, 2, w_ - 2 * digtw[0], digth[0], singleb * 2);
    }
    else if (score2 < 1000)
    {
        paintnumber(score2, 3, w_ - 3 * digtw[0], digth[0], singleb * 2);
    }
    else if (score2 < 10000)
    {
        paintnumber(score2, 4, w_ - 4 * digtw[0], digth[0], singleb * 2);
    }
    else
    {
        paintnumber(score2, 5, w_ - 5 * digtw[0], digth[0], singleb * 2);
    }
}

void Window::paintblock(Block &b, long i, long j, long x, long y, long w, long h)
{
    if (b.pauseb >= 1)
    {
        drawbmp(piconp, x, y, w, h);
        bar(x, y, w - 1, h - 1, cbg);
    }
    else if (b.mask[i][j])
    {
        if (!(i >= b.maski || j < b.maskj - 1))
        {
            drawbmp(picone, x, y, w, h);
        }
    }
    else if (b.blck[i][j])
    {
        if (b.mine[i][j])
        {
            drawbmp(piconm, x, y, w, h);
        }
        else
        {
            drawbmp(picon[b.numb[i][j]], x, y, w, h);
        }
    }
    else if (b.flag[i][j])
    {
        drawbmp(piconf, x, y, w, h);
    }
    else if (b.qstn[i][j])
    {
        drawbmp(piconq, x, y, w, h);
    }
    else if (((b.sit == 4) || ((b.sit == 0) && (bd.mode == 0))) && b.mine[i][j])
    {
        drawbmp(piconn, x, y, w, h);
    }
    else
    {
        drawbmp(piconc, x, y, w, h);
    }
    if (cheatb)
    {
        if (bd.leftrule[i][j] && !bd.blck[i][j] && !bd.mask[i][j])
        {
            bar(x, y, iconw - 1, iconh - 1, cblue, transparent);
        }
        if (bd.rightrule[i][j]&& !bd.blck[i][j] && !bd.qstn[i][j] && !bd.flag[i][j] && !bd.mask[i][j])
        {
            bar(x, y, iconw - 1, iconh - 1, cred, transparent);
        }
    }
}

void Window::paintboard(Block &b, long x, long y)
{
    for (long i = 0; i < b.w; i++)
    {
        for (long j = 0; j < b.h; j++)
        {
            paintblock(b, i, j, i * iconw + x, j * iconh + menuh + y, iconw, iconh);
        }
    }
}

void Window::paintboard(Block &b, long x, long y, long cx, long cy)
{
    paintboard(b, x, y);
    drawbmp(pcursor, cx * iconw + x + iconw / 2, cy * iconh + menuh + y + iconh / 2, cursorw, cursorh, 0xc0c0c0);
}


void Window::paintboard()
{
    paintboard(bd, 0, faceh);
    if (bd.mx >= 0 && bd.my >= 0 && barb)
    {
        bar(bd.mx * iconw, bd.my * iconh + menuh + faceh, iconw - 1, iconh - 1, ctfg, transparent);
    }
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
                setfontheight_(faceh);
                drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_HELP + 7), 0, 0, aboutw, faceh, ctfg, cbg);
                setfontheight_(fontfh);
                pbitmap pcheat__[2] = {piconn, piconm};
                drawbmp(pcheat__[cheatb], (aboutw - fontfh) / 2, (fontth - fontfh) / 2 + menuh, fontfh, fontfh, cbg);
                setfontheight_(fonth);
                drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_ABOUT_NAME), 0, menuh + fontth, aboutw, fonth, ctfg, cbg);
                drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_ABOUT_VERSION), 0, menuh + fontth + fonth, aboutw, fonth, ctfg, cbg);
                drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_ABOUT_AUTHOR), 0, menuh + fontth + fonth * 2, aboutw, fonth, ctfg, cbg);
                drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_ABOUT_LICENSE), 0, menuh + fontth + fonth * 3, aboutw, fonth, ctfg, cbg);
                break;
            }
        case -2:
            {
                setfontheight_(faceh);
                drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_HELP + 9), 0, 0, helpw, faceh, ctfg, cbg);
                setfontheight_(fontfh);
                if (bd.st.steamb)
                {
                    char rankStr[MAX_PATH];
                    setfontheight_(fontsh - 1);
                    pbitmap pmenu__[3] = {pmenu1[0], pmenu2[0], pmenu3[0]};
                    const char* usernamec;
                    short int usernames[100];
                    long usernamel;
                    LeaderboardEntry_t leads;
                    for (long leadid = 0; leadid < 3; leadid++)
                    {
                        drawbmp(pmenu__[leadid], helpw * (leadid * 2 + 1) / 6 - facew / 2, menuh, facew, faceh, cfg);
                        long rank_ = 0;
                        while (bd.st.leadsn[0][leadid + lead_5 * 3][rank_].m_nScore >= 9998)
                        {
                            rank_++;
                        }
                        for (long k = 0; k < 20; k++)
                        {
                            if (k < 10)
                            {
                                leads = bd.st.leadsn[0][leadid + lead_5 * 3][k + rank_];
                            }
                            else
                            {
                                leads = bd.st.leadsn[1][leadid + lead_5 * 3][k - 10];
                            }
                            if (bd.st.leadsn[2][leadid + lead_5 * 3][0].m_nGlobalRank == leads.m_nGlobalRank && leads.m_steamIDUser.GetEAccountType() > 0)
                            {
                                setfontweight_(700);
                            }
                            if (leads.m_steamIDUser.GetEAccountType() > 0)
                            {
                                usernamec = SteamFriends()->GetFriendPersonaName(leads.m_steamIDUser);
                                uint32_t buffer;
                                uint16_t utf16[2] = {0};
                                long posc = 0;
                                long lenc = 0;
                                long poss = 0;
                                long lens = 0;
                                while (usernamec[posc] != 0)
                                {
                                    lenc = UTF8ToUnicode((uint8_t*)&usernamec[posc], &buffer);
                                    posc += lenc;
                                    lens = UnicodeToUTF16(buffer, utf16);
                                    if (lens > 0)
                                    {
                                        usernames[4 + poss] = utf16[0];
                                        poss++;
                                    }
                                    if (lens > 1)
                                    {
                                        usernames[4 + poss] = utf16[1];
                                        poss++;
                                    }
                                }
                                usernames[0] = -1;
                                usernames[1] = -1;
                                usernames[2] = poss;
                                usernames[3] = 0;
                                usernames[4 + poss] = 0;
                                sprintf(rankStr, "%d", leads.m_nGlobalRank - rank_);
                                drawtextxy_(pwint, rankStr, helpw * leadid / 3, k * fontsh + faceh + menuh + 1, ctfg, cbg);
                                drawtextxy_(pwint, &usernames[4], helpw * leadid / 3 + getstringwidth_("00000"), k * fontsh + faceh + menuh + 1, helpw / 3 - getstringwidth_("00000") - digtw[1] * fontsh / digth[1] * 4, fontsh, ctfg, cbg, DT_LEFT);
                                paintnumber(leads.m_nScore, 4, helpw * (leadid + 1) / 3 - digtw[1] * fontsh / digth[1] * 4, k * fontsh + faceh + menuh, digtw[1] * fontsh / digth[1], fontsh, 1);
                            }
                            setfontweight_(0);
                        }
                    }
                    setfontheight_(fonth);
                    pbitmap pface__[3] = {pface[1], pface[3], piconf};
                    long scr__[3] = {bd.st.scrfour, bd.st.scrdead, bd.st.scrtotal};
                    long n__[3] = {0, 0, 1};
                    for (long k = 0; k < 3; k++)
                    {
                        long score = bd.st.scr[scr__[k]];
                        if (singleb)
                        {
                            if (k == 0)
                            {
                                score = bd.tetrisi;
                            }
                            if (k == 1)
                            {
                                score = bd.missi;
                            }
                        }
                        drawbmp(pface__[k], helpw * (k * 2 + 1) / 6 - 2 * digtw[0] - facew - digtw[0] * n__[k], menuh + (fontsh * 20 + helph - okh_) / 2 + 1, facew, faceh, cfg);
                        paintnumber(score, 4 + n__[k] * 2 + (bd.st.scr[scr__[k]] >= 10000) * (k < 2), helpw * (k * 2 + 1) / 6 - 2 * digtw[0] + facew - digtw[0] * n__[k], menuh + (fontsh * 20 + helph - okh_) / 2 + 1, singleb * (k < 2) * 2);
                    }
                    line(helpw / 3 * 1, menuh, 0, helph - okh_, cline);
                    line(helpw / 3 * 2, menuh, 0, helph - okh_, cline);
                    line(0, menuh, helpw, 0, cline);
                    line(0, menuh + faceh, helpw, 0, cline);
                    line(0, menuh + faceh + fontsh * 10, helpw, 0, cline);
                    line(0, menuh + faceh + fontsh * 20, helpw, 0, cline);
                    long k_[5] = {3, 0, 5, 4, 6};
                    for (long k = 0; k < 5; k++)
                    {
                        drawbmp(pmenug[k_[k]][lead_5 == k], getwin(), ((helpw + okw) / 2 + helpw) / 2+ facew * (k) - facew * 5 / 2, helph - (okh_ + okh) / 2 + menuh, facew, faceh);
                    }
                    setfontheight_(faceh);
                    drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_MODE + lead_5), (helpw + okw) / 2, helph - (okh_ + okh) / 2 + menuh + faceh, helpw - (helpw + okw) / 2, faceh, ctfg, cbg);
                    setfontheight_(fonth);
                    break;
                }
            }
        case -3:
            {
                setfontheight_(faceh);
                drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_HELP + 8), 0, 0, helpw, faceh, ctfg, cbg);
                setfontheight_(fonth);
                pbitmap psetting__[10] = {pmenus[bd.sd.soundb], pmenum[bd.sd.musicb], pmenug[md][0], NULL, pface[8], pface[7], NULL, picon[0], picon[0], pmenun[singleb]};
                long settinglan[10] = {10, 11, 12, 0, 17, 14, 0, 18, 19, 13};
                long settingj[10] = {2, 2, 2, 2, 3, 3, 3, 2, 2, 2};
                long settingb[10][3] = {{bd.sd.soundb, !bd.sd.soundb, 0}, {bd.sd.musicb, !bd.sd.musicb, 0}, {md == 0, md == 1, 0}, {md == 2, md == 3, 0}, {mult_ == 0, mult_ == 1, mult_ >= 2}, {colori == 0, colori == 1, colori == 2}, {colori == 3, colori == 4, colori == 5}, {bd.delayb == 1, bd.delayb == 0, 0}, {barb, !barb, 0}, {!singleb, singleb, 0}};
                pbitmap psettingicon[2] = {piconc, piconf};
                long settinglanj[10][3] = {{0, 1, 0}, {0, 1, 0}, {2, 3, 0}, {4, 5, 0}, {6, 7, 16}, {8, 9, 10}, {11, 12, 13}, {0, 1, 0}, {0, 1, 0}, {14, 15, 0}};
                long helpw__ = iconw;
                double helph__ =  (double)(helph - okh_ - iconh * 2 - faceh) / (double)(10 - 1);
                for (long k = 0; k < 10; k++)
                {
                    if (psetting__[k] != NULL)
                    {
                        drawbmp(psetting__[k], helpw__, helph__ * k + menuh + iconh, facew, faceh, cfg);
                    }
                    if (k != 3 && k != 6)
                    {
                        drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_HELP + settinglan[k]), helpw__ + facew + iconw, helph__ * k + menuh + iconh, helpw / 4 - facew - iconw * 2, faceh, ctfg, cbg, DT_LEFT);
                    }
                    for (long j = 0; j < settingj[k]; j++)
                    {
                        drawbmp(psettingicon[settingb[k][j]], helpw / 4 * (j + 1), helph__ * k + menuh + iconh, facew, faceh, cfg);
                        if (k == 4 && j == 2)
                        {
                            drawbmp(parrowm, helpw / 4 * (j + 1) + facew, helph__ * k + menuh + iconh, facew, faceh, cfg);
                            drawbmp(parrowp, helpw / 4 * (j + 1) + facew * 2, helph__ * k + menuh + iconh, facew, faceh, cfg);
                            drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_SET + settinglanj[k][j] + max(2, mult_) - 2), helpw / 4 * (j + 1) + facew * 3 + iconw, helph__ * k + menuh + iconh, helpw / 4 - facew - iconw * 2, faceh, ctfg, cbg, DT_LEFT);
                        }
                        else
                        {
                            drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_SET + settinglanj[k][j]), helpw / 4 * (j + 1) + facew + iconw, helph__ * k + menuh + iconh, helpw / 4 - facew - iconw * 2, faceh, ctfg, cbg, DT_LEFT);
                        }
                    }
                }
                if (bd.delayb == 1)
                {
                    line(helpw__, helph__ * 7 + menuh + iconh + faceh / 2, facew, 0, cred);
                }
                if (barb)
                {
                    bar(helpw__, helph__ * 8 + menuh + iconh, facew - 1, faceh - 1, ctfg, transparent);
                }
                break;
            }
        case 1:
            {
                setfontheight_(faceh);
                drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_HELP + 6), 0, 0, helpw, faceh, ctfg, cbg);
                drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_HELP_TITLE), helpw / 2, menuh, helpw / 2, (helph - okh_ - iconh * 20) / 2, ctfg, cbg);
                setfontheight_(fonth);
                pbitmap pmenu__[17] = {pmenu1[0], pmenu2[0], pmenu3[0], pface[4], pface[0], picone, pmenuq[0], pmenua[0], pmenud[0], pmenut[0], pmenus[0], pmenum[0], pmenug[md][0], pmenun[singleb], pface[7], pface[6], pface[5]};
                const char* keys[17] = {"1", "2", "3", "N", "Space", "U", "H / F1", "B / F2", "E / F3", "T / F4", "S / F5", "M / F6", "G / F7", "R / F8", "K / F11", "P / F12", "Q / ESC"};
                const char* cheatn[8] = {"4", "5", "6", "7", "8", "9", "0", "C"};
                const char* cheats[8] = {"Smart Solve", "Number Board ", "Auto Smart", "Auto Number", "Auto Blank", "Del Line", "Up Level", "Reset Steam"};
                long cheatc[8] = {cblue, cblue, cblue, cblue, cblue, cblue, cred, cred};
                long helpw__ = iconw;
                double helph__ =  (double)(helph - okh_ - iconh - faceh) / (double)(17 - 1);
                for (long k = 0; k < 17; k++)
                {
                    drawbmp(pmenu__[k], helpw__, helph__ * k + menuh + iconh / 2, facew, faceh, cfg);
                    drawtextxy_(pwint, keys[k], helpw__ + facew + iconw, helph__ * k + menuh + iconh / 2, ctfg, cbg);
                }
                if (!cheatb)
                {
                    for (long k = 0; k < 17; k++)
                    {
                        drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_HELP + k), helpw / 4, helph__ * k + menuh + iconh / 2, helpw / 4, faceh, ctfg, cbg, DT_LEFT);
                    }
                }
                else
                {
                    for (long k = 0; k < 8; k++)
                    {
                        drawtextxy_(pwint, cheatn[k], helpw / 4, helph__ * k + menuh + iconh / 2, cheatc[k], cbg);
                        drawtextxy_(pwint, cheats[k], helpw / 4 + facew, helph__ * k + menuh + iconh / 2, cheatc[k], cbg);
                    }
                }
                line(helpw / 2, menuh, 0, helph - okh_, cline);
                for (long k = 0; k < 12; k++)
                {
                    paintline(piconn, piconc, 2, 10, (helpw * 3 / 2 - iconw * 12) / 2, (helph - okh_ - iconh * 20) / 2 + menuh + iconh * (k + 8));
                }
                drawtextxy_(pwint, "PgUp", (helpw * 3 / 2 - getstringwidth_("PgUp")) / 2, (helph - okh_ - iconh * 20) / 2 + menuh + iconh * 8 - faceh * 1, cred, cbg);
                drawtextxy_(pwint, "PgDn", (helpw * 3 / 2 - getstringwidth_("PgDn")) / 2, (helph - okh_ - iconh * 20) / 2 + menuh + iconh * 8 - faceh * 0, cblue, cfg);
                bar((helpw * 3 / 2 - iconw * 12) / 2 + iconw * 2 - arroww * 1, (helph - okh_ - iconh * 20) / 2 + menuh + iconh * 15 - arrowh / 2, arroww, arrowh, cmine);
                bar((helpw * 3 / 2 - iconw * 12) / 2 + iconw * 2 - arroww * 0, (helph - okh_ - iconh * 20) / 2 + menuh + iconh * 15 - arrowh / 2, arroww, arrowh, cfg);
                bar((helpw * 3 / 2 - arroww) / 2, (helph - okh_ - iconh * 20) / 2 + menuh + iconh * 20 - arrowh * 1, arroww, arrowh, cfg);
                bar((helpw * 3 / 2 - arroww) / 2, (helph - okh_ - iconh * 20) / 2 + menuh + iconh * 20 - arrowh * 0, arroww, arrowh, cbg);
                bar((helpw * 3 / 2 - iconw * 12) / 2 + iconw * 12 - arroww * 1, (helph - okh_ - iconh * 20) / 2 + menuh + iconh * 15 - arrowh / 2, arroww, arrowh, cfg);
                bar((helpw * 3 / 2 - iconw * 12) / 2 + iconw * 12 - arroww * 0, (helph - okh_ - iconh * 20) / 2 + menuh + iconh * 15 - arrowh / 2, arroww, arrowh, cbg);
                drawbmp(parrowm, (helpw * 3 / 2 - iconw * 12) / 2 + iconw * 2 - arroww * 1, (helph - okh_ - iconh * 20) / 2 + menuh + iconh * 15 - arrowh / 2, arroww, arrowh, cfg);
                drawbmp(parrowp, (helpw * 3 / 2 - iconw * 12) / 2 + iconw * 2 - arroww * 0, (helph - okh_ - iconh * 20) / 2 + menuh + iconh * 15 - arrowh / 2, arroww, arrowh, cfg);
                drawbmp(parrowu, (helpw * 3 / 2 - arroww) / 2, (helph - okh_ - iconh * 20) / 2 + menuh + iconh * 20 - arrowh * 1, arroww, arrowh, cfg);
                drawbmp(parrowd, (helpw * 3 / 2 - arroww) / 2, (helph - okh_ - iconh * 20) / 2 + menuh + iconh * 20 - arrowh * 0, arroww, arrowh, cfg);
                drawbmp(parrowl, (helpw * 3 / 2 - iconw * 12) / 2 + iconw * 12 - arroww * 1, (helph - okh_ - iconh * 20) / 2 + menuh + iconh * 15 - arrowh / 2, arroww, arrowh, cfg);
                drawbmp(parrowr, (helpw * 3 / 2 - iconw * 12) / 2 + iconw * 12 - arroww * 0, (helph - okh_ - iconh * 20) / 2 + menuh + iconh * 15 - arrowh / 2, arroww, arrowh, cfg);
                line((helpw * 3 / 2 - iconw * 12) / 2, (helph - okh_ - iconh * 20) / 2 + menuh + iconh * 0 - 1, iconw * 12, 0, ctfg);
                line((helpw * 3 / 2 - iconw * 12) / 2, (helph - okh_ - iconh * 20) / 2 + menuh + iconh * 8 - 1, iconw * 12, 0, ctfg);
                line((helpw * 3 / 2 - iconw * 12) / 2, (helph - okh_ - iconh * 20) / 2 + menuh + iconh * 20 - 1, iconw * 12, 0, ctfg);
                line((helpw * 3 / 2 - iconw * 12) / 2 + iconw * 0 - 1, (helph - okh_ - iconh * 20) / 2 + menuh, 0, iconh * 20, ctfg);
                line((helpw * 3 / 2 - iconw * 12) / 2 + iconw * 2 - 1, (helph - okh_ - iconh * 4) / 2 + menuh, 0, iconh * 12, ctfg);
                line((helpw * 3 / 2 - iconw * 12) / 2 + iconw * 12 - 1, (helph - okh_ - iconh * 20) / 2 + menuh, 0, iconh * 20, ctfg);
                break;
            }
        case 2:
            {
                setfontheight_(faceh);
                drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_HELP_TITLE + 1), 0, 0, helpw, faceh, ctfg, cbg);
                setfontheight_(fontmh);
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
                        if ((i == 0 || i == 2))
                        {
                            drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_HELP_MENU + i / 2 + j * 2), i / 2 * helpw / 2, (helph - okh_) * (j * 2 + 1) / 6 - iconh * 3 + clickh + menuh + iconh, helpw / 2, (helph - okh_) / 6+ iconh * 2 - clickh, ctfg, cbg);
                        }
                    }
                }
                line(helpw / 2, menuh, 0, helph - okh_, cline);
                for (long k = 1; k <= 2; k++)
                {
                    line(0, menuh + (helph - okh_) * k / 3, helpw, 0, cline);
                }
                setfontheight_(fonth);
                break;
            }
        case 3:
            {
                setfontheight_(faceh);
                drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_HELP_TITLE + 2), 0, 0, helpw, faceh, ctfg, cbg);
                setfontheight_(fontmh);
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
                            drawbmp(pclicka, helpw * (i * 2 + 2 + (j != 0)) / 8 - clickw / 2, (helph - okh_) * (j * 2 + 1) / 6 - iconh * 3 + menuh, cfg);
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
                        if (((i == 0 || i == 2)) && (j == 0))
                        {
                            drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_HELP_MENU + i / 2 + 6), i / 2 * helpw / 2, (helph - okh_) * (j * 2 + 1) / 6 - iconh * 3 + clickh + menuh + iconh, helpw / 2, (helph - okh_) / 6+ iconh * 2 - clickh, ctfg, cbg);
                        }
                        if ((i == 0) && (j > 0))
                        {
                            drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_HELP_MENU + j + 7), 0, (helph - okh_) * (j * 2 + 1) / 6 - iconh * 3 + clickh + menuh + iconh, helpw, (helph - okh_) / 6+ iconh * 2 - clickh, ctfg, cbg);
                        }
                    }
                }
                line(helpw / 2, menuh, 0, (helph - okh_) / 3, cline);
                for (long k = 1; k <= 2; k++)
                {
                    line(0, menuh + (helph - okh_) * k / 3, helpw, 0, cline);
                }
                break;
                setfontheight_(fonth);
            }
        case 4:
            {
                setfontheight_(faceh);
                drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_HELP_TITLE + 3), 0, 0, helpw, faceh, ctfg, cbg);
                setfontheight_(fontmh);
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
                drawbmp(pface[3], iconw * iconwm - (facew - iconw) / 2, iconh * (iconh1 + 3) + menuh - iconh - faceh / 2, cfg);
                drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_HELP_MENU + 10), 0, iconh * (iconh1 + 4) + menuh, helpw, iconh * (iconh2 - iconh1 - 6), ctfg, cbg);
                for (long k = 0; k <= 2; k++)
                {
                    paintline(picone, 2, iconw * iconwl, iconh * (k * 3 + (iconh2 + 0)) + menuh);
                    paintline(picone, k + 3, iconw * iconwr, iconh * (k * 3 + (iconh2 + 0)) + menuh);
                    paintline(piconc, 12, iconw * iconwl, iconh * (k * 3 + (iconh2 + 1)) + menuh);
                    paintline(piconc, 12, iconw * iconwr, iconh * (k * 3 + (iconh2 + 1)) + menuh);
                    paintnumber(k * 5, 2, iconw * iconwn, iconh * (k * 3 + (iconh2 + 1)) + menuh - digth[0] / 2);
                    drawbmp(picona, iconw * iconwm, iconh * (k * 3 + (iconh2 + 1)) + menuh, cfg);
                }
                drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_HELP_MENU + 11), 0, iconh * (iconh2 + 8) + menuh, helpw,  iconh * (iconh3 - iconh2 - 10) + iconh / 2, ctfg, cbg);
                paintline(picone, 12, iconw * iconwl, iconh * (iconh3 + 0) + menuh);
                paintline(piconc, 12, iconw * iconwr, iconh * (iconh3 + 0) + menuh);
                paintline(piconc, 12, iconw * iconwl, iconh * (iconh3 + 1) + menuh);
                paintline(piconc, 12, iconw * iconwr, iconh * (iconh3 + 1) + menuh);
                drawbmp(picona, iconw * iconwm, iconh * (iconh3 + 1) + menuh, cfg);
                drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_HELP_MENU + 12), 0, iconh * (iconh3 + 2) + menuh, helpw,  helph - okh_ - iconh * (iconh3 + 2), ctfg, cbg);
                line(0, menuh + iconh * (iconh2 - 2), helpw, 0, cline);
                line(0, menuh + iconh * (iconh3 - 2) + iconh / 2, helpw, 0, cline);
                setfontheight_(fonth);
                break;
            }
        case 5:
            {
                setfontheight_(faceh);
                drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_HELP_TITLE + 4), 0, 0, helpw, faceh, ctfg, cbg);
                setfontheight_(fontmh);
                long iconwl = 3;
                long iconwm = iconwl + 13;
                long iconwr = iconwl + 17;
                long iconwn = iconwr + 14;
                long iconh1 = 2;
                long iconh2 = 6;
                long iconh3 = 11;
                long iconh4 = 22;
                paintline(piconc, picon[2], piconp, 4, 1, 7, iconw * iconwl, iconh * (iconh1 + 0) - iconh / 2 + menuh);
                paintline(piconc, piconf, picon[2], piconp, 2, 2, 1, 7, iconw * iconwl, iconh * (iconh1 + 1) - iconh / 2 + menuh);
                paintline(piconc, piconf, picon[3], picon[1], piconp, 2, 1, 1, 1, 7, iconw * iconwl, iconh * (iconh1 + 2) - iconh / 2 + menuh);
                paintline(piconc, picon[1], piconp, 4, 1, 7, iconw * iconwr, iconh * (iconh1 + 1) - iconh / 2 + menuh);
                paintline(piconc, piconf, picon[3], picon[1], piconp, 2, 1, 1, 1, 7, iconw * iconwr, iconh * (iconh1 + 2) - iconh / 2 + menuh);
                line(iconw * iconwl, iconh * (iconh1 + 1) - iconh / 2 + iconh / 2 + menuh, iconw * 12, 0, cred);
                drawbmp(piconf, iconw * (iconwm + 0), iconh * (iconh1 + 2) - iconh / 2 + menuh, cbg);
                drawbmp(piconu, iconw * (iconwm + 1), iconh * (iconh1 + 2) - iconh / 2 + menuh, cfg);
                drawbmp(piconn, iconw * (iconwm + 2), iconh * (iconh1 + 2) - iconh / 2 + menuh, cbg);
                drawbmp(pface[4], iconw * (iconwm + 1) - (facew - iconw) / 2, iconh * (iconh1 + 2) - iconh / 2 + menuh - iconh - faceh / 2, cbg);
                paintnumber(1, 4, iconw * iconwn, iconh * (iconh1 + 2) - iconh / 2 + menuh - digth[0] / 2);
                drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_HELP_MENU + 13), 0, iconh * (iconh1 + 3) - iconh / 2 + menuh, helpw,  iconh * 3 / 2, ctfg, cbg);
                paintline(piconc, picon[2], piconp, 4, 1, 7, iconw * iconwl, iconh * (iconh2 + 0) + menuh);
                paintline(picon[1], picon[4], piconc, picon[2], piconp, 1, 1, 2, 1, 7, iconw * iconwl, iconh * (iconh2 + 1) + menuh);
                paintline(piconc, piconc, picon[3], picon[1], piconp, 2, 1, 1, 1, 7, iconw * iconwl, iconh * (iconh2 + 2) + menuh);
                paintline(piconc, picon[1], piconp, 4, 1, 7, iconw * iconwr, iconh * (iconh2 + 1) + menuh);
                paintline(piconc, picon[3], picon[1], piconp, 3, 1, 1, 7, iconw * iconwr, iconh * (iconh2 + 2) + menuh);
                line(iconw * iconwl, iconh * (iconh2 + 1) + iconh / 2 + menuh, iconw * 12, 0, cred);
                drawbmp(piconc, iconw * (iconwm + 0), iconh * (iconh2 + 2) + menuh, cbg);
                drawbmp(piconu, iconw * (iconwm + 1), iconh * (iconh2 + 2) + menuh, cfg);
                drawbmp(piconn, iconw * (iconwm + 2), iconh * (iconh2 + 2) + menuh, cbg);
                drawbmp(pface[4], iconw * (iconwm + 1) - (facew - iconw) / 2, iconh * (iconh2 + 2) + menuh - iconh - faceh / 2, cbg);
                paintnumber(1, 4, iconw * iconwn, iconh * (iconh2 + 2) + menuh - digth[0] / 2);
                drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_HELP_MENU + 14), 0, iconh * (iconh2 + 3) + menuh, helpw,  iconh * 3 / 2, ctfg, cbg);
                paintline(piconp, 12, iconw * iconwl, iconh * (iconh3 + 4) - iconh / 2 + menuh);
                line(iconw * iconwl, iconh * (iconh3 + 4) - iconh / 2 + iconh / 2 + menuh, iconw * 12, 0, cred);
                for (long k = 0; k < 8; k++)
                {
                    if (k > 4)
                    {
                        paintline(piconc, 12, iconw * iconwl, iconh * (iconh3 + k) - iconh / 2 + menuh);
                    }
                    if (k > 0)
                    {
                        paintline(piconc, 12, iconw * iconwr, iconh * (iconh3 + k) - iconh / 2 + menuh);
                    }
                }
                drawbmp(picona, iconw * (iconwm + 1), iconh * (iconh3 + 7) - iconh / 2 + menuh, cfg);
                drawbmp(pface[1], iconw * (iconwm + 1) - (facew - iconw) / 2, iconh * (iconh3 + 7) - iconh / 2 + menuh - iconh - faceh / 2, cfg);
                paintnumber(5, 4, iconw * iconwn, iconh * (iconh3 + 7) - iconh / 2 + menuh - digth[0] / 2);
                drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_HELP_MENU + 15), 0, iconh * (iconh3 + 8) - iconh / 2 + menuh, helpw,  iconh * 3 / 2, ctfg, cbg);
                for (long k = 0; k < 3; k++)
                {
                    paintnumber((k + 2) * (k + 2), 4, helpw * (k * 2 + 1) / 6 - 4 * digtw[0] - 1 * iconw / 2, iconh * iconh4 + menuh - digth[0] / 2);
                    paintnumber((k + 2), 2, helpw * (k * 2 + 1) / 6 + 2 * digtw[0] + 1 * iconw / 2, iconh * iconh4 + menuh - digth[0] / 2);
                    drawbmp(picona, helpw * (k * 2 + 1) / 6 + digtw[0] - iconw / 2, iconh * iconh4 + menuh - iconh / 2, cfg);
                }
                drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_HELP_MENU + 16), 0, iconh * iconh4 + digth[0] / 2 + menuh, helpw, helph - okh_ - (iconh * iconh4 + digth[0] / 2), ctfg, cbg);
                line(0, iconh * (iconh3 - 1) + menuh + iconh / 2, helpw, 0, cline);
                line(0, iconh * (iconh4 - 2) + menuh, helpw, 0, cline);
                setfontheight_(fonth);
                break;
            }
        case 6:
            {
                setfontheight_(faceh);
                drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_HELP_TITLE + 5), 0, 0, helpw, faceh, ctfg, cbg);
                setfontheight_(fontmh);
                for (long i = 0; i < 32; i++)
                {
                    for (long j = 0; j < 24; j++)
                    {
                        drawbmp(piconp, iconw * (4 + i), iconh / 2 + menuh + iconh * j, cfg);
                    }
                }
                for (long j = 0; j < 24; j++)
                {
                    paintline(piconn, 2 + (j >= 12) + (j >= 16) * 3, iconw * 4 + iconw, iconh / 2 + menuh + iconh * (j + 1) - iconh);
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
                line(iconw * 4, iconh / 2 + menuh + iconh * 12 - 1, iconw * 12, 0, ctfg);
                line(iconw * 4, iconh / 2 + menuh + iconh * 16 - 1, iconw * 16, 0, ctfg);
                line(iconw * 4, iconh / 2 + menuh + iconh * 24 - 1, iconw * 32, 0, ctfg);
                line(iconw * 4, iconh / 2 + menuh + iconh * 0 - 1, iconw * 32, 0, ctfg);
                line(iconw * 4 + iconw * 12 - 1, iconh / 2 + menuh, 0, iconh * 12, ctfg);
                line(iconw * 4 + iconw * 16 - 1, iconh / 2 + menuh, 0, iconh * 16, ctfg);
                line(iconw * 4 + iconw * 32 - 1, iconh / 2 + menuh, 0, iconh * 24, ctfg);
                line(iconw * 4 + iconw * 0 - 1, iconh / 2 + menuh, 0, iconh * 24, ctfg);
                drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_HELP_MENU + 17), iconw * 4 + iconw * 1, iconh / 2 + menuh + iconh * 12 - fontmh - 1, iconw * 15 - menuw, fontmh, ctfg, cfg, DT_LEFT);
                drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_HELP_MENU + 18), iconw * 4 + iconw * 1, iconh / 2 + menuh + iconh * 16 - fontmh - 1, iconw * 15 - menuw, fontmh, ctfg, cfg, DT_LEFT);
                drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_HELP_MENU + 19), iconw * 4 + iconw * 1, iconh / 2 + menuh + iconh * 24 - fontmh - 1, iconw * 15 - menuw, fontmh, ctfg, cfg, DT_LEFT);
                setfontheight_(fonth);
                break;
            }
    }
    if (helpi == -1)
    {
        setfontheight_(fonth);
        drawbmp(pok, getwin(), (aboutw - okw) / 2, abouth - (okh_ + okh) / 2 + menuh, okw, okh);
        drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_ABOUT_OK), (aboutw - okw) / 2, abouth - (okh_ + okh) / 2 + menuh, okw, okh, ctfg, ctbg);
    }
    else if (helpi != 0)
    {
        setfontheight_(fonth);
        drawbmp(pok, getwin(), (helpw - okw) / 2, helph - (okh_ + okh) / 2 + menuh, okw, okh);
        if (waitb)
        {
            drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_ABOUT_OK), (helpw - okw) / 2, helph - (okh_ + okh) / 2 + menuh, okw, okh, cline, ctbg);
        }
        else
        {
            drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_ABOUT_OK), (helpw - okw) / 2, helph - (okh_ + okh) / 2 + menuh, okw, okh, ctfg, ctbg);
        }
        if (helpi > 1 && helpi <= maxhelp)
        {
            drawbmp(pbtn, getwin(), (helpw - okw) / 2 - btnw * 2, helph - (okh_ + okh) / 2 + menuh, btnw, btnh);
            drawtextxy_(pwint, "<", (helpw - okw) / 2 - btnw * 2, helph - (okh_ + okh) / 2 + menuh, btnw, btnh, ctfg, ctbg);
        }
        if (helpi >= 1 && helpi < maxhelp)
        {
            drawbmp(pbtn, getwin(), (helpw + okw) / 2 + btnw, helph - (okh_ + okh) / 2 + menuh, btnw, btnh);
            drawtextxy_(pwint, ">", (helpw + okw) / 2 + btnw, helph - (okh_ + okh) / 2 + menuh, btnw, btnh, ctfg, ctbg);
        }
        drawbmp(pok, getwin(), (helpw - okw) / 2 - btnw * 3 - tutw, helph - (okh_ + okh) / 2 + menuh, tutw, tuth);
        if (waitb)
        {
            drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_TUT_), (helpw - okw) / 2 - btnw * 3 - tutw, helph - (okh_ + okh) / 2 + menuh, tutw, tuth, cline, ctbg);
        }
        else
        {
            drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_TUT_), (helpw - okw) / 2 - btnw * 3 - tutw, helph - (okh_ + okh) / 2 + menuh, tutw, tuth, ctfg, ctbg);
        }
        line(0, menuh, helpw, 0, cline);
        line(0, menuh + helph - okh_, helpw, 0, cline);
    }
}

void Window::painttut()
{
    setfontheight_(fonth);
    long i = bd.tutx[bd.tuti];
    long j = bd.tuty[bd.tuti];
    bar(i * iconw, j * iconh + menuh + faceh, iconw - 1, iconh - 1, cred, transparent);
    bar(i * iconw + 1, j * iconh + menuh + faceh + 1, iconw - 3, iconh - 3, cred, transparent);
    switch (bd.tuti)
    {
        case 1:
            bar(4 * iconw - 1, 15 * iconh + menuh + faceh - 1, iconw * 3 + 1, iconh * 3 + 1, cblue, transparent);
            bar(4 * iconw - 2, 15 * iconh + menuh + faceh - 2, iconw * 3 + 3, iconh * 3 + 3, cblue, transparent);
            break;
        case 2:
            bar(3 * iconw - 1, 16 * iconh + menuh + faceh - 1, iconw * 1 + 1, iconh * 1 + 1, cblue, transparent);
            bar(3 * iconw - 2, 16 * iconh + menuh + faceh - 2, iconw * 1 + 3, iconh * 1 + 3, cblue, transparent);
            break;
        case 3:
            bar(9 * iconw, 18 * iconh + menuh + faceh, iconw - 1, iconh * 2 - 1, cblue, transparent);
            bar(9 * iconw + 1, 18 * iconh + menuh + faceh + 1, iconw - 3, iconh * 2 - 3, cblue, transparent);
            bar(9 * iconw - 1, 17 * iconh + menuh + faceh - 1, iconw + 1, iconh * 3 + 1, cgreen, transparent);
            bar(9 * iconw - 2, 17 * iconh + menuh + faceh - 2, iconw + 3, iconh * 3 + 3, cgreen, transparent);
            break;
        case 4:
            bar(7 * iconw - 1, 16 * iconh + menuh + faceh - 1, iconw * 3 + 1, iconh * 3 + 1, cblue, transparent);
            bar(7 * iconw - 2, 16 * iconh + menuh + faceh - 2, iconw * 3 + 3, iconh * 3 + 3, cblue, transparent);
            break;
        case 5:
            bar(9 * iconw - 1, 19 * iconh + menuh + faceh - 1, iconw * 1 + 1, iconh * 1 + 1, cgreen, transparent);
            bar(9 * iconw - 2, 19 * iconh + menuh + faceh - 2, iconw * 1 + 3, iconh * 1 + 3, cgreen, transparent);
            break;
        case 6:
            bar(8 * iconw - 1, 17 * iconh + menuh + faceh - 1, iconw * 3 + 1, iconh * 3 + 1, cgreen, transparent);
            bar(8 * iconw - 2, 17 * iconh + menuh + faceh - 2, iconw * 3 + 3, iconh * 3 + 3, cgreen, transparent);
            break;
        case 7:
            bar(9 * iconw - 1, 17 * iconh + menuh + faceh - 1, iconw * 3 + 1, iconh * 3 + 1, cgreen, transparent);
            bar(9 * iconw - 2, 17 * iconh + menuh + faceh - 2, iconw * 3 + 3, iconh * 3 + 3, cgreen, transparent);
            break;
        case 8:
            bar(2 * iconw + 0, 18 * iconh + menuh + faceh + 0, iconw - 1, iconh * 2 - 1, cblue, transparent);
            bar(2 * iconw + 1, 18 * iconh + menuh + faceh + 1, iconw - 3, iconh * 2 - 1, cblue, transparent);
            bar(2 * iconw - 1, 17 * iconh + menuh + faceh - 1, iconw + 1, iconh * 3 + 1, cgreen, transparent);
            bar(2 * iconw - 2, 17 * iconh + menuh + faceh - 2, iconw + 3, iconh * 3 + 3, cgreen, transparent);
            break;
        case 10:
            bar(2 * iconw - 1, 16 * iconh + menuh + faceh - 1, iconw * 3 + 1, iconh * 3 + 1, cgreen, transparent);
            bar(2 * iconw - 2, 16 * iconh + menuh + faceh - 2, iconw * 3 + 3, iconh * 3 + 3, cgreen, transparent);
            break;
        case 11:
            bar(2 * iconw - 1, 18 * iconh + menuh + faceh - 1, iconw * 3 + 1, iconh * 2 + 1, cblue, transparent);
            bar(2 * iconw - 2, 18 * iconh + menuh + faceh - 2, iconw * 3 + 3, iconh * 2 + 3, cblue, transparent);
            bar(0 * iconw - 1, 6 * iconh + menuh + faceh - 1, iconw * 12 + 1, iconh * 2 + 1, cred, transparent);
            bar(0 * iconw - 2, 6 * iconh + menuh + faceh - 2, iconw * 12 + 3, iconh * 2 + 3, cred, transparent);
            break;
        case 12:
            bar(1 * iconw - 1, 18 * iconh + menuh + faceh - 1, iconw * 3 + 1, iconh * 2 + 1, cblue, transparent);
            bar(1 * iconw - 2, 18 * iconh + menuh + faceh - 2, iconw * 3 + 3, iconh * 2 + 3, cblue, transparent);
            break;
        case 13:
            bar(0 * iconw - 1, 18 * iconh + menuh + faceh - 1, iconw * 12 + 1, iconh * 2 + 1, cred, transparent);
            bar(0 * iconw - 2, 18 * iconh + menuh + faceh - 2, iconw * 12 + 3, iconh * 2 + 3, cred, transparent);
            bar(0 * digtw[0], menuh, digtw[0] * 4, digth[0], cred, transparent);
            bar(0 * digtw[0] + 1, menuh + 1, digtw[0] * 4 - 2, digth[0] - 2, cred, transparent);
            bar(w_ - 2 * digtw[0], menuh, digtw[0] * 2, digth[0], cred, transparent);
            bar(w_ - 2 * digtw[0] + 1, menuh + 1, digtw[0] * 2 - 2, digth[0] - 2, cred, transparent);
            if  (bd.tutb < 2)
            {
                drawbmp(pok, getwin(), (iconw * 12 - okw) / 2, 10 * iconh + menuh + faceh, okw, okh);
                drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_ABOUT_OK), (iconw * 12 - okw) / 2, 10 * iconh + menuh + faceh, okw, okh, ctfg, ctbg);
            }
            break;
        case 14:
            bar(w_ - 2 * digtw[0], menuh, digtw[0] * 2, digth[0], cred, transparent);
            bar(w_ - 2 * digtw[0] + 1, menuh + 1, digtw[0] * 2 - 2, digth[0] - 2, cred, transparent);
            bar(0 * iconw - 1, 7 * iconh + menuh + faceh - 1, iconw * 12 + 1, iconh + 1, cred, transparent);
            bar(0 * iconw - 2, 7 * iconh + menuh + faceh - 2, iconw * 12 + 3, iconh + 3, cred, transparent);
            if  (bd.tutb < 2)
            {
                drawbmp(pok, getwin(), (iconw * 12 - okw) / 2, 10 * iconh + menuh + faceh, okw, okh);
                drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_ABOUT_OK), (iconw * 12 - okw) / 2, 10 * iconh + menuh + faceh, okw, okh, ctfg, ctbg);
            }
            break;
    }
    setfontheight_(fontsh);
    drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_TUT + bd.tuti), 0, menuh + faceh, iconw * 12, fontsh * 8, ctfg, cbg, DT_WORDBREAK);
    setfontheight_(fonth);
    if (bd.tutb == 2)
    {
        drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_TUT_QUIT + 0), 0, menuh + faceh, iconw * 12, fontsh * 8, ctfg, cbg);
        drawbmp(pok, getwin(), iconw * 0, 10 * iconh + menuh + faceh, iconw * 6 - 1, okh);
        drawbmp(pok, getwin(), iconw * 6, 10 * iconh + menuh + faceh, iconw * 6 - 1, okh);
        drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_TUT_QUIT + 1), iconw * 0, 10 * iconh + menuh + faceh, iconw * 6 - 1, okh, ctfg, ctbg);
        drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_TUT_QUIT + 2), iconw * 6, 10 * iconh + menuh + faceh, iconw * 6 - 1, okh, ctfg, ctbg);
    }
}

void Window::painttitle(long load)
{
    clear(cbg);
    clear(pwint, transparent_);
    if (load < 0)
    {
        ptitle_ = loadbmp("./png/title.png");
    }
    drawbmp(ptitle_, getwin(), (launchw - titlew) / 2, fontth, titlew, titleh, cfg);
    setfontheight_(fontfh);
    drawtextxy_(pwint, bd.st.lan.getlan(bd.st.lan.LAN_TITLE), 0, fontth - fontfh, launchw, fontfh, ctfg, cbg);
    if (load >= 0)
    {
        drawtextxy_(pwint, bd.st.lan.getlan(load), 0, fontth + titleh - titleh / 16, launchw, fontfh, ctfg, cbg);
    }
    setfontheight_(fonth);
    if (mult > 1)
    {
        drawbmp(getwin(), pwin, 0, 0, w_, h_, 0, 0, w_, h_);
        drawbmp(pwin, getwin(), 0, 0, w_ * mult, h_ * mult);
    }
    drawbmp(pwint, getwin(),0,0, w_ * mult, h_ * mult, transparent_);
    freshwin();
}

void Window::paintevent(bool freshb)
{
    clear(cbg);
    clear(pwint, transparent_);
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
        if (bd.tutb >= 1 && bd.pauseb == 0)
        {
            painttut();
        }
    }
    if (mult > 1)
    {
        drawbmp(getwin(), pwin, 0, 0, w_, h_, 0, 0, w_, h_);
        drawbmp(pwin, getwin(), 0, 0, w_ * mult, h_ * mult);
    }
    drawbmp(pwint, getwin(), 0, 0, w_ * mult, h_ * mult, transparent_);
    if (freshb)
    {
        freshwin();
    }
}

void Window::paintevent()
{
    paintevent(true);
}

bool Window::isin(long ex, long ey, long x, long y, long w, long h)
{
    return (ex > x && ey > y && ex < (x + w) && ey < (y + h));
}

void Window::sethelp(long helpi_)
{
    mi = false;
    if (helpi != helpi_ || helpi != 0)
    {
        bd.sd.playsound(bd.sd.sLeft);
    }
    if (helpi > 0 && helpi_ > 0)
    {
        helpi_ = helpi;
    }
    if ((helpi != helpi_) && (helpi_ != 0))
    {
        if (helpi == 0 && bd.sit > 0)
        {
            if (bd.pauseb == 0)
            {
                bd.pause();
                bd.pauseb = 2;
            }
        }
        helpi = helpi_;
    }
    else
    {
        if (bd.pauseb == 2 && bd.sit > 0)
        {
            bd.pause();
        }
        helpi = 0;
    }
    initwindow(false);
    if (helpi == -2)
    {
        waitb = true;
        paintevent();
        bd.st.getlead();
        waitb = false;
    }
}

void Window::savescr()
{
    char scrpath[MAX_PATH];
    GetTempPath(MAX_PATH, scrpath);
    strcat(scrpath, "screenshot_");
    time_t rawtime;
    time(&rawtime);
    struct tm * timed;
    timed = localtime(&rawtime);
    char times[MAX_PATH];
    sprintf(times, "%d%d%d%d%d%d", timed->tm_mday, timed->tm_mon + 1, timed->tm_year + 1900, timed->tm_hour, timed->tm_min, timed->tm_sec);
    strcat(scrpath, times);
    strcat(scrpath, ".png");
    savebmp(getwin(), scrpath);
    bd.st.savescr(&scrpath[0]);
    bd.sd.playsound(bd.sd.sSolve);
}

void Window::switchskin()
{
    switchskin((colori + 1) % 6);
}

void Window::switchskin(long colori_)
{
    colori = colori_;
    initbmp();
    paintevent();
    bd.sd.playsound(bd.sd.sRight);
}

void Window::switchmd()
{
    switchmd((md + 1) % 4);
}

void Window::switchmd(long md_)
{
    md = md_;
    if (md > 1)
    {
        bd.mdb = 0;
    }
    bd.sd.playsound(bd.sd.sLeft);
}

void Window::tutevent(long ex, long ey, bool tutkb)
{
    bool tutmb = isin(ex, ey, (iconw * 12 - okw) / 2, 10 * iconh + menuh + faceh, okw, okh);
    if (bd.tutb == 1 && (tutmb || tutkb))
    {
        if (bd.tuti == 13)
        {
            bd.maski++;
            bd.tuti++;
            bd.sd.playsound(bd.sd.sLeft);
        }
        else if (bd.tuti == 14)
        {
            bd.tutb = 0;
            bd.time = gettimer();
            helpb = false;
            sethelp(1);
        }
    }
    bool tutmb_y = isin(ex, ey, iconw * 0, 10 * iconh + menuh + faceh, iconw * 6 - 1, okh);
    bool tutmb_n = isin(ex, ey, iconw * 6, 10 * iconh + menuh + faceh, iconw * 6 - 1, okh);
    if (bd.tutb == 2 && (tutmb_y || tutmb_n || tutkb))
    {
        if (tutmb_y || tutkb)
        {
            bd.tutb = 0;
            bd.time = gettimer();
            helpb = false;
            bd.sd.playsound(bd.sd.sLeft);
        }
        if (tutmb_n)
        {
            bd.tutb = 1;
            bd.sd.playsound(bd.sd.sLeft);
        }
    }
}

void Window::mouseeventboard_(long x, long y, long eb_, long md_)
{
    bool tutmb = (bd.tutb == 0) || (bd.tutx[bd.tuti] == x && bd.tuty[bd.tuti] == y && ((bd.tutm[bd.tuti] & eb_) > 0));
    if ((x != mx || y != my) && tutmb && (bd.tutb < 2))
    {
        bd.mx = x;
        bd.my = y;
        if (eb_ == k_lmouse)
        {
            if (bd.sit == 0 && y >= bd.maskj && md_ >= 3)
            {
                bd.resetbd(x, y);
            }
            bd.clickleft(x, y, true, md_);
        }
        else if (eb_ == k_rmouse)
        {
            bd.clickright(x, y, true, md_);
        }
        paintevent();
        bd.checkline(true);
        mx = x;
        my = y;
        if (bd.tutb >= 1)
        {
            bd.tuti++;
        }
        paintevent();
    }
}

void Window::mouseeventboard(long ex_, long ey_, long eb_, long md_)
{
    long ex = ex_ / mult;
    long ey = ey_ / mult;
    if ((ey - menuh >= faceh) && (helpi == 0) && (bd.sit < 4 && bd.pauseb == 0))
    {
        long x = ex / iconw;
        long y = (ey - faceh - menuh) / iconh;
        mouseeventboard_(x, y, eb_, md_);
        tutevent(ex, ey, false);
    }
}

void Window::mouseevent(long ex_, long ey_, long eb_)
{
    long ex = ex_ / mult;
    long ey = ey_ / mult;
    if (ey < menuh)
    {
        if (ex < (3 * menuw))
        {
            if (bd.tutb >= 1)
            {
                bd.tutb = 2;
                bd.sd.playsound(bd.sd.sRight);
            }
            else
            {
                helpi = 0;
                bd.initbd(ex / menuw + 1, md);
                initwindow(false);
            }
        }
        else if (ex > w_ - 5 * menuw)
        {
            switch ((ex - (w_ - 5 * menuw)) / menuw)
            {
                case 4:
                    sethelp(-1);
                    break;
                case 3:
                    sethelp(1);
                    break;
                case 2:
                    sethelp(-3);
                    break;
                case 1:
                    sethelp(-2);
                    break;
                case 0:
                    savescr();
                    break;
            }
        }
    }
    else if (helpi == 0)
    {
        if (ey - menuh < faceh)
        {
            if ((ex > ((w_ - facew) / 2)) && (ex < ((w_ + facew) / 2)))
            {
                if (eb_ == k_lmouse)
                {
                    if (bd.tutb >= 1)
                    {
                        bd.tutb = 2;
                        bd.sd.playsound(bd.sd.sRight);
                    }
                    else
                    {
                        bd.initbd();
                    }
                }
                else if (eb_ == k_rmouse)
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
        else if (bd.sit < 4 && bd.pauseb == 0)
        {
            mouseeventboard(ex_, ey_, eb_, md + 4);
        }
    }
    else if (helpi == -1)
    {
        if (isin(ex, ey, (aboutw - okw) / 2, abouth - (okh_ + okh) / 2 + menuh, okw, okh))
        {
            sethelp(0);
        }
        if (isin(ex, ey, (aboutw - fontfh) / 2, (fontth - fontfh) / 2 + menuh, fontfh, fontfh))
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
        if (isin(ex, ey, (helpw - okw) / 2 - btnw * 3 - tutw, helph - (okh_ + okh) / 2 + menuh, tutw, tuth))
        {
            sethelp(0);
            bd.initbd(1, md);
            initwindow(false);
            bd.tutb = 1;
        }
        if (helpi > 1)
        {
            if (isin(ex, ey, (helpw - okw) / 2 - btnw * 2, helph - (okh_ + okh) / 2 + menuh, btnw, btnh))
            {
                helpi--;
                bd.sd.playsound(bd.sd.sLeft);
            }
        }
        if (helpi > 0 && helpi < maxhelp)
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
        if (helpi == -2)
        {
            if (isin(ex, ey, ((helpw + okw) / 2 + helpw) / 2 - facew * 5 / 2, helph - (okh_ + okh) / 2 + menuh, facew * 5, faceh))
            {
                lead_5 = (ex - (((helpw + okw) / 2 + helpw) / 2 - facew * 5 / 2)) / facew;
                bd.sd.playsound(bd.sd.sLeft);
            }
            if (isin(ex, ey, (helpw - okw) / 2 - btnw * 3 - tutw, helph - (okh_ + okh) / 2 + menuh, tutw, tuth))
            {
                sethelp(0);
                bd.initbd(1, md);
                initwindow(false);
                bd.tutb = 1;
            }
        }
        if (helpi == -3)
        {
            if (isin(ex, ey, (helpw - okw) / 2 - btnw * 3 - tutw, helph - (okh_ + okh) / 2 + menuh, tutw, tuth))
            {
                sethelp(0);
                bd.initbd(1, md);
                initwindow(false);
                bd.tutb = 1;
            }
            long helpw__ = iconw;
            double helph__ =  (double)(helph - okh_ - iconh * 2 - faceh) / (double)(10 - 1);
            for (long k = 0; k < 10; k++)
            {
                long helpw__ = iconw;
                if (isin(ex, ey, helpw__, helph__ * k + menuh + iconh, facew, faceh))
                {
                    switch (k)
                    {
                        case 0:
                            bd.sd.switchsound();
                            break;
                        case 1:
                            bd.sd.switchmusic();
                            break;
                        case 2:
                            switchmd();
                            break;
                        case 3:
                            break;
                        case 4:
                            if (mult_ == 0)
                            {
                                mult_ = 1;
                            }
                            else
                            {
                                mult_ = 0;
                            }
                            initwindow(false);
                            bd.sd.playsound(bd.sd.sRight);
                            break;
                        case 5:
                            switchskin();
                            break;
                        case 6:
                            break;
                        case 7:
                            bd.delayb = !bd.delayb;
                            bd.sd.playsound(bd.sd.sLeft);
                            break;
                        case 8:
                            barb = !barb;
                            bd.sd.playsound(bd.sd.sLeft);
                            break;
                        case 9:
                            singleb = !singleb;
                            bd.sd.playsound(bd.sd.sLeft);
                            break;
                    }
                }
                for (long j = 0; j < 3; j++)
                {
                    if (isin(ex, ey, helpw / 4 * (j + 1), helph__ * k + menuh + iconh, facew, faceh))
                    {
                        switch (k)
                        {
                            case 0:
                                if (j <= 1 && bd.sd.soundb == j)
                                {
                                    bd.sd.switchsound();
                                }
                                break;
                            case 1:
                                if (j <= 1 && bd.sd.musicb == j)
                                {
                                    bd.sd.switchmusic();
                                }
                                break;
                            case 2:
                                if (j <= 2 && md != j)
                                {
                                    switchmd(j);
                                }
                                break;
                            case 3:
                                if (j <= 2 && md != (j + 2))
                                {
                                    switchmd(j+2);
                                }
                                break;
                            case 4:
                                if (mult_ != j)
                                {
                                    mult_ = j;
                                    initwindow(false);
                                    bd.sd.playsound(bd.sd.sRight);
                                }
                                break;
                            case 5:
                                if (j <= 2 && colori != j)
                                {
                                    switchskin(j);
                                }
                                break;
                            case 6:
                                if (j <= 2 && colori != (j + 3))
                                {
                                    switchskin(j + 3);
                                }
                                break;
                            case 7:
                                if (j <= 1 && bd.delayb == j)
                                {
                                    bd.delayb = !bd.delayb;
                                    bd.sd.playsound(bd.sd.sLeft);
                                }
                                break;
                            case 8:
                                if (j <= 1 && barb == j)
                                {
                                    barb = !barb;
                                    bd.sd.playsound(bd.sd.sLeft);
                                }
                                break;
                            case 9:
                                if (j <= 1 && singleb != j)
                                {
                                    singleb = !singleb;
                                    bd.sd.playsound(bd.sd.sLeft);
                                }
                                break;
                        }
                    }
                }
            }
            if (mult_ >= 2)
            {
                if (isin(ex, ey, helpw / 4 * (2 + 1) + facew, helph__ * 4 + menuh + iconh, facew, faceh))
                {
                    mult_ = max(2, mult_ - 1);
                    initwindow(false);
                    bd.sd.playsound(bd.sd.sRight);
                }
                if (isin(ex, ey, helpw / 4 * (2 + 1) + facew * 2, helph__ * 4 + menuh + iconh, facew, faceh))
                {
                    mult_ = min(8, mult_ + 1);
                    initwindow(false);
                    bd.sd.playsound(bd.sd.sRight);
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
            savescr();
            break;
        case k_p:
            savescr();
            break;
        case k_f11:
            switchskin();
            break;
        case k_k:
            switchskin();
            break;
        case k_f1:
            sethelp(1);
            break;
        case k_h:
            sethelp(1);
            break;
        case k_f2:
            sethelp(-1);
            break;
        case k_b:
            sethelp(-1);
            break;
        case k_f3:
            sethelp(-3);
            break;
        case k_e:
            sethelp(-3);
            break;
        case k_f4:
            sethelp(-2);
            break;
        case k_t:
            sethelp(-2);
            break;
        case k_f5:
            bd.sd.switchsound();
            break;
        case k_s:
            bd.sd.switchsound();
            break;
        case k_f6:
            bd.sd.switchmusic();
            break;
        case k_m:
            bd.sd.switchmusic();
            break;
        case k_f7:
            switchmd();
            break;
        case k_g:
            switchmd();
            break;
        case k_f8:
            singleb = !singleb;
            bd.sd.playsound(bd.sd.sLeft);
            break;
        case k_r:
            singleb = !singleb;
            bd.sd.playsound(bd.sd.sLeft);
            break;
        case k_n:
            if (bd.tutb >= 1)
            {
                bd.tutb = 2;
                bd.sd.playsound(bd.sd.sRight);
            }
            else
            {
                helpi = 0;
                bd.initbd();
                initwindow(false);
            }
            break;
        case k_1:
            if (bd.tutb >= 1)
            {
                bd.tutb = 2;
                bd.sd.playsound(bd.sd.sRight);
            }
            else
            {
                helpi = 0;
                bd.initbd(1, md);
                initwindow(false);
            }
            break;
        case k_2:
            if (bd.tutb >= 1)
            {
                bd.tutb = 2;
                bd.sd.playsound(bd.sd.sRight);
            }
            else
            {
                helpi = 0;
                bd.initbd(2, md);
                initwindow(false);
            }
            break;
        case k_3:
            if (bd.tutb >= 1)
            {
                bd.tutb = 2;
                bd.sd.playsound(bd.sd.sRight);
            }
            else
            {
                helpi = 0;
                bd.initbd(3, md);
                initwindow(false);
            }
            break;
    }
    if (cheatb)
    {
        if (key == k_c)
        {
            bd.st.resetach();
        }
    }
    if (helpi == -2)
    {
        switch (key)
        {
            case k_tab:
                lead_5 = (lead_5 + 1) % 5;
                bd.sd.playsound(bd.sd.sLeft);
                break;
        }
    }
    if (helpi == 0)
    {
        if (bd.mx == -1 && bd.my == -1 && (key == k_a || key == k_d || key == k_w || key == k_s || key == k_prd || key == k_dot))
        {
            bd.mx = bd.w / 2;
            bd.my = bd.h - 3;
        }
        switch (key)
        {
            case k_esc:
                closewin();
                break;
            case k_q:
                closewin();
                break;
            case k_space:
                if (bd.sit > 0)
                {
                    bd.pause();
                    bd.sd.playsound(bd.sd.sSolve);
                    bd.st.addach(bd.st.achgenpause);
                }
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
            case 189:
                bd.n--;
                initwindow(true);
                break;
            case 187:
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
            case k_a:
                bd.mx--;
                bd.mx = max(0, bd.mx);
                break;
            case k_d:
                bd.mx++;
                bd.mx = min(bd.w - 1, bd.mx);
                break;
            case k_w:
                bd.my--;
                bd.my = max(0, bd.my);
                break;
            case k_s:
                bd.my++;
                bd.my = min(bd.h - 1, bd.my);
                break;
            case k_prd:
                mx = -1;
                my = -1;
                tutevent(0, 0, true);
                mouseeventboard_(bd.mx, bd.my, k_lmouse, md + 4);
                break;
            case k_dot:
                mx = -1;
                my = -1;
                tutevent(0, 0, true);
                mouseeventboard_(bd.mx, bd.my, k_rmouse, md + 4);
                break;
            case k_u:
                if (bd.tutb == 0)
                {
                    bd.addline();
                    bd.sd.playsound(bd.sd.sLeft);
                    paintevent();
                    bd.checkline(true);
                    bd.checkdie();
                    break;
                }
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
                    bd.solve2_();
                    break;
                case k_7:
                    bd.solve1_();
                    break;
                case k_8:
                    bd.solveblank_();
                    break;
                case k_9:
                    bd.delline(bd.h - 1);
                    break;
                case k_0:
                    bd.level++ ;
                    break;
            }
            if (key >= k_4 || key <= k_0)
            {
                paintevent();
                bd.checkline(true);
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
        if (bd.delayb__ == 0)
        {
            ml = GetAsyncKeyState(VK_LBUTTON);
            mr = GetAsyncKeyState(VK_RBUTTON);
            if (ismouseleft())
            {
                mi = true;
                mx = -1;
                my = -1;
                mouseevent(getmouseposx(), getmouseposy(), k_lmouse);
            }
            if (ismouseright())
            {
                mi = true;
                mx = -1;
                my = -1;
                mouseevent(getmouseposx(), getmouseposy(), k_rmouse);
            }
            if (ismousemove() && (md >= 2) && (bd.tutb == 0) && mi)
            {
                if (ml)
                {
                    mouseeventboard(getmouseposx(), getmouseposy(), k_lmouse, md);
                }
                if (mr)
                {
                    mouseeventboard(getmouseposx(), getmouseposy(), k_rmouse, md);
                }
            }
            if (iskey())
            {
                keyevent(getkey());
            }
            if (ismsg(WM_PAINT) || ismsg(WM_NCLBUTTONDOWN) || ismsg(WM_SYSCOMMAND))
            {
                GetWindowPlacement((HWND)gethwnd(),&wn);
                showmax = ((wn.showCmd & SW_SHOWMAXIMIZED) == SW_SHOWMAXIMIZED);
                if (showmax != showmax_ || (((w_ * mult) != getwidth() || (h_ * mult) != getheight()) && ismsg(WM_NCLBUTTONDOWN)))
                {
                    mult_ = showmax;
                    initwindow(false);
                    bd.sd.playsound(bd.sd.sRight);
                    showmax_ = showmax;
                }
                paintevent();
            }
        }
    }
    bd.delayb__ = 0;
}

void Window::setfontname_(const char* s)
{
    setfontname(s);
    setfont(pwint);
}

void Window::setfontheight_(unsigned long h)
{
    setfontheight(h * mult);
    setfont(pwint);
}

void Window::setfontweight_(unsigned long wg)
{
    setfontweight(wg);
    setfont(pwint);
}

void Window::drawtextxy_(pbitmap b,const short int* s,long x,long y,unsigned long w,unsigned long h,unsigned long cfg,unsigned long cbg,unsigned long format)
{
    drawtextxy(b, s, x * mult, y * mult, w * mult, h * mult, cfg, cbg, format);
}

void Window::drawtextxy_(pbitmap b,const short int* s,long x,long y,unsigned long w,unsigned long h,unsigned long cfg,unsigned long cbg)
{
    drawtextxy(b, s, x * mult, y * mult, w * mult, h * mult, cfg, cbg);
}

void Window::drawtextxy_(pbitmap b,const char* s,long x,long y,unsigned long w,unsigned long h,unsigned long cfg,unsigned long cbg)
{
    drawtextxy(b, s, x * mult, y * mult, w * mult, h * mult, cfg, cbg);
}

void Window::drawtextxy_(pbitmap b,const char* s,long x,long y,unsigned long cfg,unsigned long cbg)
{
    drawtextxy(b, s, x * mult, y * mult, cfg, cbg);
}

unsigned long Window::getstringwidth_(const char* s)
{
    return (double)getstringwidth(s) / mult;
}
