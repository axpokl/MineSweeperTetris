#include "disp.h"
//#include "stdio.h"
using namespace std;

class Sound
{

public:

    bool soundb;
    bool musicb;

    unsigned long sBlank;
    unsigned long sWin;
    unsigned long sLose;
    unsigned long sError;
    unsigned long sLeft;
    unsigned long sRight;
    unsigned long sFlag;
    unsigned long sNew;
    unsigned long sSolve;

    void initsound();
    void playsound(long id);

};

void Sound::initsound()
{
    soundb = true;
    musicb = true;
    sWin = loadaudio("./wav/Win.wav");
    sLose = loadaudio("./wav/Lose.wav");
    sError = loadaudio("./wav/Error.wav");
    sLeft = loadaudio("./wav/Left.wav");
    sRight = loadaudio("./wav/Right.wav");
    sFlag = loadaudio("./wav/Flag.wav");
    sNew = loadaudio("./wav/New.wav");
    sSolve = loadaudio("./wav/Solve.wav");
}

void Sound::playsound(long id)
{
    setaudiopos(id, 0);
}

class MineBd
{

public:
    Sound sd;
    long w;
    long h;
    long n;
    long maskj0;
    long maskj;
    long maski;
    double time;
    long mode;
    long sit;
    long line;
    long level;
    bool solveb;
    bool checkb;
    bool flag[100][100];
    bool qstn[100][100];
    bool mine[100][100];
    bool blck[100][100];
    bool mask[100][100];
    long numb[100][100];
    long i;
    long j;
    long k;
    long rx;
    long ry;
    bool mb;
    long tx;
    long ty;

    void initbd();
    void initbd(long w, long h, long maskj, long n);
    void initbd(long mode);
    bool isok(long k, long x, long y, long &tx, long &ty);
    void resetbd(long x, long y);
    void solveblank();
    void solve0();
    void solve1();
    bool checkerror();
    void checkline();
    void clickleft(long x, long y);
    void setqstn(long x, long y, bool sb);
    bool setflag(long x, long y, bool sb);
    bool setblock(long x, long y, bool sb);
    void clickright(long x, long y, bool sb);
    void addline();
    void delline(long l);
    void addmask();
    void checkdie();
    void pause();

    struct rule
    {
        long x;
        long y;
        long numbc;
        long blckc;
        long blckx[8];
        long blcky[8];
    };
    rule ruletemp;
    rule rulemain[10000];
    int rulemainc;
    long blckrule[100][100];
    void createrule();
    void comparerule2(long rule1, long rule2);
    void comparerule();
    void solve2();

};

void MineBd::initbd()
{
    sit = 0;
    line = 0;
    level = 1;
    w = min(max(w, 8), 100);
    h = min(max(h, 8), 100);
    n = max(1, min(n, w - 1));
    maskj = min(h - 4, maskj0);
    maski = 0;
    for (i = 0; i < w; i++ )
    {
        for (j = 0; j < h; j++ )
        {
            mine[i][j] = (i < n);
            flag[i][j] = false;
            qstn[i][j] = false;
            blck[i][j] = false;
            mask[i][j] = (j < maskj);
            numb[i][j] = 0;
        }
    }
    sd.playsound(sd.sNew);
}

void MineBd::initbd(long w, long h, long maskj, long n)
{
    this->w = w;
    this->h = h;
    this->n = n;
    this->maskj0 = maskj;
    initbd();
}

void MineBd::initbd(long mode)
{
    this->mode = mode;
    switch (mode)
    {
    case 1:
        initbd(12, 20, 8, 2);
        break;
    case 2:
        initbd(16, 24, 8, 3);
        break;
    case 3:
        initbd(32, 32, 8, 6);
        break;
    }
}

bool MineBd::isok(long k, long x, long y, long &tx, long &ty)
{
    switch (k)
    {
    case 0:
        tx = x - 1;
        ty = y;
        return (x > 0);
        break;
    case 1:
        tx = x + 1;
        ty = y;
        return (x < w - 1);
        break;
    case 2:
        tx = x;
        ty = y - 1;
        return (y > 0);
        break;
    case 3:
        tx = x;
        ty = y + 1;
        return (y < h - 1);
        break;
    case 4:
        tx = x - 1;
        ty = y - 1;
        return (x > 0 && y > 0);
        break;
    case 5:
        tx = x - 1;
        ty = y + 1;
        return (x > 0 && y < h - 1);
        break;
    case 6:
        tx = x + 1;
        ty = y - 1;
        return (x < w - 1 && y > 0);
        break;
    case 7:
        tx = x + 1;
        ty = y + 1;
        return (x < w - 1 && y < h - 1);
        break;
    }
}

void MineBd::resetbd(long x, long y)
{
    srand((unsigned)clock());
    delay(1);
    for (i = 0; i < w; i++ )
    {
        for (j = 0; j < h; j++ )
        {
            rx = rand() % w;
            ry = j;
            mb = mine[rx][ry];
            mine[rx][ry] = mine[i][j];
            mine[i][j] = mb;
        }
    }
    rx = x;
    ry = y;
    if (mine[x][y])
    {
        for (i = 0; i < w; i++ )
        {
            j = y;
            if (!mine[i][j])
            {
                rx = i;
                ry = j;
            }
        }
        mine[rx][ry] = true;
        mine[x][y] = false;
    }
    for (i = 0; i < w; i++ )
    {
        for (j = 0; j < h; j++ )
        {
            numb[i][j] = 0;
            for (k = 0; k < 8; k++ )
            {
                if (isok(k, i, j, tx, ty))
                {
                    if (mine[tx][ty])
                    {
                        numb[i][j]++ ;
                    }
                }
            }
        }
    }
    time = gettimer();
    sit = 1;
}

void MineBd::solveblank()
{
    solveb = false;
    if (sit < 4)
    {
        for (long i = 0; i < w; i++ )
        {
            for (long j = 0; j < h; j++ )
            {
                if (!mask[i][j] && !mine[i][j] && (numb[i][j] == 0))
                {
                    clickleft(i, j);
                }
            }
        }
        for (long i = w - 1; i >= 0; i--)
        {
            for (long j = h - 1; j >= 0; j--)
            {
                if (!mask[i][j] && !mine[i][j] && (numb[i][j] == 0))
                {
                    clickleft(i, j);
                }
            }
        }
    }
}

void MineBd::solve0()
{
    solveb = false;
    if (sit < 4)
    {
        for (long i = 0; i < w; i++ )
        {
            for (long j = 0; j < h; j++ )
            {
                if (blck[i][j] && (numb[i][j] == 0))
                {
                    clickright(i, j, false);
                }
            }
        }
        for (long i = w - 1; i >= 0; i--)
        {
            for (long j = h - 1; j >= 0; j--)
            {
                if (blck[i][j] && (numb[i][j] == 0))
                {
                    clickright(i, j, false);
                }
            }
        }
    }
}

void MineBd::solve1()
{
    solveb = false;
    if (sit < 4)
    {
        for (long i = 0; i < w; i++ )
        {
            for (long j = 0; j < h; j++ )
            {
                if (blck[i][j] && (numb[i][j] >= 0))
                {
                    clickright(i, j, false);
                }
            }
        }
        for (long i = w - 1; i >= 0; i--)
        {
            for (long j = h - 1; j >= 0; j--)
            {
                if (blck[i][j] && (numb[i][j] >= 0))
                {
                    clickright(i, j, false);
                }
            }
        }
        sd.playsound(sd.sSolve);
    }
}

void MineBd::createrule()
{
    for (long i = 0; i < w; i++ )
    {
        for (long j = 0; j < h; j++ )
        {
            blckrule[i][j] = -1;
            if (blck[i][j])
            {
                ruletemp.x = i;
                ruletemp.y = j;
                ruletemp.numbc = numb[i][j];
                ruletemp.blckc = 0;
                for (k = 0; k < 8; k++ )
                {
                    if (isok(k, i, j, tx, ty))
                    {
                        if (flag[tx][ty])
                        {
                            ruletemp.numbc--;
                        }
                        else if (!blck[tx][ty])
                        {
                            ruletemp.blckx[ruletemp.blckc] = tx;
                            ruletemp.blcky[ruletemp.blckc] = ty;
                            ruletemp.blckc++ ;
                        }
                    }
                }
                if (ruletemp.blckc > 0)
                {
                    blckrule[i][j] = rulemainc;
                    rulemain[rulemainc] = ruletemp;
                    rulemainc++ ;
                }
            }
        }
    }
}

void MineBd::comparerule2(long rule1c, long rule2c)
{
    rule rule1 = rulemain[rule1c];
    rule rule2 = rulemain[rule2c];
    for (int rule1k = 0; rule1k < rulemain[rule1c].blckc; rule1k++ )
    {
        for (int rule2k = 0; rule2k < rulemain[rule2c].blckc; rule2k++ )
        {
            if ((rule1.blckx[rule1k] >= 0) && (rule1.blcky[rule1k] >= 0) &&
                    (rule2.blckx[rule2k] >= 0) && (rule2.blcky[rule2k] >= 0) &&
                    (rule1.blckx[rule1k] == rule2.blckx[rule2k]) &&
                    (rule1.blcky[rule1k] == rule2.blcky[rule2k]))
            {
                rule1.blckx[rule1k] =  - 1;
                rule1.blcky[rule1k] =  - 1;
                rule1.blckc--;
                rule2.blckx[rule2k] =  - 1;
                rule2.blcky[rule2k] =  - 1;
                rule2.blckc--;
            }
        }
    }
    if (rule1.blckc == (rule1.numbc - rule2.numbc))
    {
        for (int rule1k = 0; rule1k < rulemain[rule1c].blckc; rule1k++ )
        {
            if ((rule1.blckx[rule1k] >= 0) && (rule1.blcky[rule1k] >= 0))
            {
                clickright(rule1.blckx[rule1k], rule1.blcky[rule1k], false);
            }
        }
        for (int rule2k = 0; rule2k < rulemain[rule2c].blckc; rule2k++ )
        {
            if ((rule2.blckx[rule2k] >= 0) && (rule2.blcky[rule2k] >= 0))
            {
                clickleft(rule2.blckx[rule2k], rule2.blcky[rule2k]);
            }
        }
    }
    if (rule2.blckc == (rule2.numbc - rule1.numbc))
    {
        for (int rule2k = 0; rule2k < rulemain[rule2c].blckc; rule2k++ )
        {
            if ((rule2.blckx[rule2k] >= 0) && (rule2.blcky[rule2k] >= 0))
            {
                clickright(rule2.blckx[rule2k], rule2.blcky[rule2k], false);
            }
        }
        for (int rule1k = 0; rule1k < rulemain[rule1c].blckc; rule1k++ )
        {
            if ((rule1.blckx[rule1k] >= 0) && (rule1.blcky[rule1k] >= 0))
            {
                clickleft(rule1.blckx[rule1k], rule1.blcky[rule1k]);
            }
        }
    }
}

void MineBd::comparerule()
{
    long i = 0;
    long j = 0;
    for (int rulemaini = 0; rulemaini < rulemainc; rulemaini++ )
    {
        i = rulemain[rulemaini].x;
        j = rulemain[rulemaini].y;
        for (k = 0; k < 8; k++ )
        {
            if (isok(k, i, j, tx, ty))
            {
                if (blckrule[tx][ty] >= 0)
                {
                    comparerule2(rulemaini, blckrule[tx][ty]);
                }
            }
        }
    }
}

void MineBd::solve2()
{
    solveb = false;
    rulemainc = 0;
    if (sit < 4)
    {
        createrule();
        comparerule();
    }
}

bool MineBd::checkerror()
{
    bool result = false;
    for (long i = 0; i < w; i++ )
    {
        for (long j = 0; j < h; j++ )
        {
            if (blck[i][j] && mine[i][j])
            {
                blck[i][j] = false;
                flag[i][j] = true;
                qstn[i][j] = false;
                sit = 2;
                result = true;
                addline();
                addline();
                sd.playsound(sd.sError);
            }
        }
    }
    return result;
}

void MineBd::checkline()
{
    if (checkb)
    {
        bool result = false;
        long blckc;
        long flagc;
        j = h - 1;
        while (j >= maskj)
        {
            blckc = 0;
            flagc = 0;
            for (i = 0; i < w; i++ )
            {
                if (!blck[i][j])
                {
                    blckc++ ;
                }
                if (flag[i][j])
                {
                    flagc++ ;
                }
            }
            if (blckc == n || flagc == n)
            {
                result = true;
                delline(j);
            }
            else
            {
                j--;
            }
        }
        if (result)
        {
            sd.playsound(sd.sSolve);
        }
        checkb = false;
    }
}

void MineBd::addline()
{
    maskj--;
    j = maskj;
    for (i = 0; i < w; i++ )
    {
        mask[i][j] = false;
    }
    for (i = 0; i < w; i++ )
    {
        for (j = maskj + 1; j >= maskj; j--)
        {
            numb[i][j] = 0;
            for (k = 0; k < 8; k++ )
            {
                if (isok(k, i, j, tx, ty))
                {
                    if (mine[tx][ty])
                    {
                        numb[i][j]++ ;
                    }
                }
            }
        }
    }
    checkb = true;
    checkline();
    checkdie();
}

void MineBd::addmask()
{
    if (gettimer() > time + 5.0 / (level + 5.0))
    {
        time += 5.0 / (level + 5.0);
        if ((sit > 0) && (sit < 4))
        {
            maski++ ;
            if (maski == w)
            {
                maski = 0;
                addline();
                solveb = true;
                while (solveb)
                {
                    solve0();
                }
            }
        }
        checkb = true;
        checkline();
        checkdie();
    }
}

void MineBd::checkdie()
{
    if (maskj == 0 && maski > 0)
    {
        sit = 4;
        sd.playsound(sd.sLose);
    }
}

void MineBd::delline(long l)
{
    maskj++ ;
    for (i = 0; i < w; i++ )
    {
        for (j = l; j >= 0; j--)
        {
            if (j == 0)
            {
                mine[i][j] = (i < n);
                mask[i][j] = true;
                flag[i][j] = false;
                qstn[i][j] = false;
                blck[i][j] = false;
                numb[i][j] = 0;
            }
            else
            {
                mine[i][j] = mine[i][j - 1];
                mask[i][j] = mask[i][j - 1];
                flag[i][j] = flag[i][j - 1];
                qstn[i][j] = qstn[i][j - 1];
                blck[i][j] = blck[i][j - 1];
                numb[i][j] = numb[i][j - 1];
            }
        }
    }
    srand((unsigned)clock());
    delay(1);
    for (i = 0; i < w; i++ )
    {
        rx = rand() % w;
        ry = 0;
        j = 0;
        mb = mine[rx][ry];
        mine[rx][ry] = mine[i][j];
        mine[i][j] = mb;
    }
    for (i = 0; i < w; i++ )
    {
        for (j = l + 1; j >= l; j--)
        {
            numb[i][j] = 0;
            for (k = 0; k < 8; k++ )
            {
                if (isok(k, i, j, tx, ty))
                {
                    if (mine[tx][ty])
                    {
                        numb[i][j]++ ;
                    }
                }
            }
        }
    }
    line++ ;
    line = min(line, 9999);
    if (maskj > h - 4)
    {
        for (long k = 0; k < 4; k++ )
        {
            line++ ;
            line = min(line, 9999);
            addline();
            sit = 3;
        }
        sd.playsound(sd.sNew);
    }
    while ((level + 1) * (level + 1) <= line)
    {
        level++ ;
        sd.playsound(sd.sWin);
    }
}

void MineBd::clickleft(long x, long y)
{
    if (!mask[x][y])
    {
        if (!blck[x][y] && !flag[x][y])
        {
            blck[x][y] = true;
            qstn[x][y] = false;
            if (sit == 2)
            {
                sit = 1;
            }
            if (sit == 3)
            {
                sit = 1;
            }
            if (!checkerror())
            {
                sd.playsound(sd.sLeft);
            }
        }
        checkb = true;
    }
}

void MineBd::setqstn(long x, long y, bool sb)
{
    qstn[x][y] = !qstn[x][y];
    if (sb)
    {
        sd.playsound(sd.sFlag);
    }
}

bool MineBd::setflag(long x, long y, bool sb)
{
    long qc = 0;
    bool sc = false;
    for (k = 0; k < 8; k++ )
    {
        if (isok(k, x, y, tx, ty))
        {
            if (!blck[tx][ty])
            {
                qc++ ;
            }
        }
    }
    if (qc == numb[x][y])
    {
        for (k = 0; k < 8; k++ )
        {
            if (isok(k, x, y, tx, ty))
            {
                if (!blck[tx][ty] && !mask[tx][ty])
                {
                    flag[tx][ty] = true;
                    sc = true;
                }
            }
        }
        if (sb && sc)
        {
            sd.playsound(sd.sFlag);
        }
    }
    return sc;
}

bool MineBd::setblock(long x, long y, bool sb)
{
    long qn = 0;
    long qq = 0;
    bool sr = false;
    for (k = 0; k < 8; k++ )
    {
        if (isok(k, x, y, tx, ty))
        {
            if (flag[tx][ty])
            {
                qn++ ;
            }
            if (qstn[tx][ty])
            {
                qq++ ;
            }
        }
    }
    if ((qn == numb[x][y]) || ((qn + qq) == numb[x][y]))
    {
        for (k = 0; k < 8; k++ )
        {
            if (isok(k, x, y, tx, ty))
            {
                if (!blck[tx][ty] && !flag[tx][ty] && !mask[tx][ty])
                {
                    if (!qstn[tx][ty])
                    {
                        blck[tx][ty] = true;
                        sr = true;
                        solveb = true;
                    }
                    else
                    {
                        qstn[tx][ty] = false;
                    }
                }
            }
        }
        if (sb && sr)
        {
            sd.playsound(sd.sRight);
        }
    }
    return checkerror();
}

void MineBd::clickright(long x, long y, bool sb)
{
    if (!mask[x][y])
    {
        if (!blck[x][y] && !mask[x][y])
        {
            setqstn(x, y, sb);
        }
        else
        {
            if (!setflag(x, y, sb))
            {
                if (!setblock(x, y, sb))
                {
                    setflag(x, y, sb);
                }
            }
        }
        checkb = true;
    }
}

void MineBd::pause()
{
    switch (sit)
    {
    case 0:
        sit = 0;
        break;
    case 1:
        sit = 5;
        break;
    case 2:
        sit = 5;
        break;
    case 3:
        sit = 5;
        break;
    case 4:
        sit = 4;
        break;
    case 5:
        sit = 1;
        break;
    }
}



class MainWindow
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

    MineBd bd;
    HICON hicon;

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

    MainWindow();
    void initBMP();
    void initWindow0();
    void initWindow();
    void paintEvent();
    void mousePressEvent(long x, long y, long key);
    void keyPressEvent(long key);
    void doAction();

};

MainWindow::MainWindow()
{
    createwin(200, 200, 0xAFAFAF, 0xAFAFAF, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_VISIBLE);
    hicon=(HICON)LoadImage(GetModuleHandle(NULL),"MINESWEEPERTETEIS_ICON",IMAGE_ICON,0,0,0);
    SendMessage((HWND)gethwnd(),WM_SETICON,ICON_SMALL,(long)hicon);
    settitle("MineSweeperTetris");
    bd.sd.initsound();
    bd.initbd(1);
    initBMP();
    initWindow();
    paintEvent();

}

void MainWindow::initBMP()
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

void MainWindow::initWindow0()
{
    setsize(bd.w * iconw, bd.h * iconh + faceh + menuh);
    paintEvent();
}

void MainWindow::initWindow()
{
    bd.initbd();
    initWindow0();
    long w = getwidth() + getborderwidth() * 2;
    long h = getheight() + getborderheight() * 2;
    long x = (getscrwidth() - w) / 2;
    long y = (getscrheight() - h) / 2;
    MoveWindow((HWND)gethwnd(), x, y, w, h + getbordertitle(), true);
}

void MainWindow::paintEvent()
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

void MainWindow::mousePressEvent(long ex, long ey, long eb)
{
    long x;
    long y;
    if (ey < menuh)
    {
        if (ex < (3 * menuw))
        {
            bd.initbd(ex / menuw + 1);
            initWindow();
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
        }
        else if (eb == k_rmouse)
        {
            bd.clickright(x, y, true);
        }
        bd.solveb = true;
        while (bd.solveb)
        {
            bd.solve0();
        }
    }
    paintEvent();
}

void MainWindow::keyPressEvent(long key)
{
    switch (key)
    {
    case k_esc:
        closewin();
        break;
    case k_left:
        bd.w--;
        initWindow();
        break;
    case k_right:
        bd.w++ ;
        initWindow();
        break;
    case k_up:
        bd.h--;
        initWindow();
        break;
    case k_down:
        bd.h++ ;
        initWindow();
        break;
    case k_sub:
        bd.n--;
        initWindow();
        break;
    case k_add:
        bd.n++ ;
        initWindow();
        break;
    case k_pgup:
        bd.maskj0 = min(bd.h - 4, bd.maskj0);
        bd.maskj0--;
        bd.maskj0 = max(1, bd.maskj0);
        initWindow();
        break;
    case k_pgdn:
        bd.maskj0++ ;
        bd.maskj0 = min(bd.h - 4, bd.maskj0);
        initWindow();
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
        initWindow();
        break;
    case k_2:
        bd.initbd(2);
        initWindow();
        break;
    case k_3:
        bd.initbd(3);
        initWindow();
        break;
    case k_8:
        bd.addline();
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

void MainWindow::doAction()
{
    if (isnextmsg())
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
    else
    {
        delay(1);
    }
}

int main()
{
    double time = 0;
    double frame = 15.0;
    MainWindow w;
    time = gettimer();
    while (iswin())
    {

        w.doAction();
        w.bd.checkline();
        w.bd.addmask();

        if (gettimer() > time + 1 / frame)
        {
            while (gettimer() > time + 1 / frame)
            {
                time = time + 1 / frame;
            }
            w.paintEvent();
        }

        if ((getwidth() != w.bd.w * w.iconw) || (getheight() != w.bd.h * w.iconh + w.facew))
        {
            w.initWindow0();
        }
    }
    return 0;
}