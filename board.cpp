class Board
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
    double pausetime;
    long mode;
    long sit;
    long line;
    long level;
    bool solveb;
    bool checkb;
    bool dieb;
    long diex;
    long diey;
    bool flag[100][100];
    bool qstn[100][100];
    bool mine[100][100];
    bool blck[100][100];
    bool mask[100][100];
    long numb[100][100];
    long rx;
    long ry;
    long tx;
    long ty;

    Board();
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
    void setflag(long x, long y, bool sb);
    void setblock(long x, long y, bool sb);
    void clickright(long x, long y, bool sb);
    void addline(bool b);
    void delline(long l);
    bool addmask();
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

Board::Board()
{
    randomize();
    initbd(1);
}

void Board::initbd()
{
    sit = 0;
    line = 0;
    level = 1;
    w = min(max(w, 8), 100);
    h = min(max(h, 8), 100);
    n = max(1, min(n, w - 1));
    maskj = min(h - 4, maskj0);
    maski = 0;
    for (long i = 0; i < w; i++ )
    {
        for (long j = 0; j < h; j++ )
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

void Board::initbd(long w, long h, long maskj, long n)
{
    this->w = w;
    this->h = h;
    this->n = n;
    this->maskj0 = maskj;
    initbd();
}

void Board::initbd(long mode)
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

bool Board::isok(long k, long x, long y, long &tx, long &ty)
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

void Board::resetbd(long x, long y)
{
    delay(1);
    for (long i = 0; i < w; i++ )
    {
        for (long j = 0; j < h; j++ )
        {
            rx = rand() % w;
            ry = j;
            bool mb = mine[rx][ry];
            mine[rx][ry] = mine[i][j];
            mine[i][j] = mb;
        }
    }
    rx = x;
    ry = y;
    if (mine[x][y])
    {
        for (long i = 0; i < w; i++ )
        {
            long j = y;
            if (!mine[i][j])
            {
                rx = i;
                ry = j;
            }
        }
        mine[rx][ry] = true;
        mine[x][y] = false;
    }
    for (long i = 0; i < w; i++ )
    {
        for (long j = 0; j < h; j++ )
        {
            numb[i][j] = 0;
            for (long k = 0; k < 8; k++ )
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

void Board::solveblank()
{
    solveb = false;
    if (sit > 0 && sit < 4)
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

void Board::solve0()
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

void Board::solve1()
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

void Board::createrule()
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
                for (long k = 0; k < 8; k++ )
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

void Board::comparerule2(long rule1c, long rule2c)
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

void Board::comparerule()
{
    long i = 0;
    long j = 0;
    for (int rulemaini = 0; rulemaini < rulemainc; rulemaini++ )
    {
        i = rulemain[rulemaini].x;
        j = rulemain[rulemaini].y;
        for (long k = 0; k < 8; k++ )
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

void Board::solve2()
{
    solveb = false;
    rulemainc = 0;
    if (sit < 4)
    {
        createrule();
        comparerule();
    }
}

bool Board::checkerror()
{
    dieb = false;
    bool result = false;
    for (long i = 0; i < w; i++ )
    {
        for (long j = 0; j < h; j++ )
        {
            if (blck[i][j] && mine[i][j])
            {
                dieb = true;
                diex = i;
                diey = j;
                blck[i][j] = false;
                flag[i][j] = true;
                qstn[i][j] = false;
                sit = 2;
                result = true;
                addline(false);
                addline(true);
                sd.playsound(sd.sError);
            }
        }
    }
    return result;
}

void Board::checkline()
{
    if (sit < 4)
    {
        long j;
        if (checkb)
        {
            solveb = true;
            while (solveb)
            {
                solve0();
            }
            bool result = false;
            long blckc;
            long flagc;
            j = h - 1;
            while (j >= maskj)
            {
                blckc = 0;
                flagc = 0;
                for (long i = 0; i < w; i++ )
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
            solveb = true;
            while (solveb)
            {
                solve0();
            }
        }
    }
}

void Board::addline(bool b)
{
    maskj--;
    long j = maskj;
    for (long i = 0; i < w; i++ )
    {
        mask[i][j] = false;
    }
    for (long i = 0; i < w; i++ )
    {
        for (long j = maskj + 1; j >= maskj; j--)
        {
            numb[i][j] = 0;
            for (long k = 0; k < 8; k++ )
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
    checkb = b;
    checkline();
    checkdie();
}

bool Board::addmask()
{
    if ((sit > 0) && (sit < 4))
    {
        if (gettimer() > time + 5.0 / (level + 5.0))
        {
            checkb = true;
            checkline();
            while (gettimer() > time + 5.0 / (level + 5.0))
            {
                time += 5.0 / (level + 5.0);
                maski++ ;
                if (maski == w)
                {
                    maski = 0;
                    addline(true);
                }
            }
            checkb = true;
            checkline();
            checkdie();
            return true;
        }
    }
    else
    {
        time = gettimer() - pausetime;
    }
    return false;
}

void Board::checkdie()
{
    if (maskj == 0 && maski > 0 && sit != 4)
    {
        sit = 4;
        if (dieb)
        {
            blck[diex][diey] = true;
        }
        sd.playsound(sd.sLose);
    }
}

void Board::delline(long l)
{
    if (sit < 4)
    {
        maskj++ ;
        for (long i = 0; i < w; i++ )
        {
            for (long j = l; j >= 0; j--)
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
        delay(1);
        for (long i = 0; i < w; i++ )
        {
            rx = rand() % w;
            ry = 0;
            long j = 0;
            bool mb = mine[rx][ry];
            mine[rx][ry] = mine[i][j];
            mine[i][j] = mb;
        }
        for (long i = 0; i < w; i++ )
        {
            for (long j = l + 1; j >= l; j--)
            {
                numb[i][j] = 0;
                for (long k = 0; k < 8; k++ )
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
                addline(false);
                sit = 3;
            }
            checkb = true;
            checkline();
            sd.playsound(sd.sNew);
        }
        while ((level + 1) * (level + 1) <= line)
        {
            level++ ;
            sd.playsound(sd.sWin);
        }
    }
}

void Board::clickleft(long x, long y)
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
            checkb = true;
        }
    }
}

void Board::setqstn(long x, long y, bool sb)
{
    qstn[x][y] = !qstn[x][y];
    if (sb)
    {
        sd.playsound(sd.sFlag);
    }
}

void Board::setflag(long x, long y, bool sb)
{
    if (sit < 4)
    {
        long qc = 0;
        bool sc = false;
        for (long k = 0; k < 8; k++ )
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
            for (long k = 0; k < 8; k++ )
            {
                if (isok(k, x, y, tx, ty))
                {
                    if (!blck[tx][ty] && !mask[tx][ty])
                    {
                        flag[tx][ty] = true;
                        qstn[tx][ty] = false;
                        sc = true;
                    }
                }
            }
            if (sb && sc)
            {
                sd.playsound(sd.sFlag);
            }
        }
    }
}

void Board::setblock(long x, long y, bool sb)
{
    if (sit < 4)
    {
        long qn = 0;
        long qq = 0;
        bool sr = false;
        for (long k = 0; k < 8; k++ )
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
            for (long k = 0; k < 8; k++ )
            {
                if (isok(k, x, y, tx, ty))
                {
                    if (!blck[tx][ty] && !flag[tx][ty] && !mask[tx][ty])
                    {
                        if (!qstn[tx][ty])
                        {
                            blck[tx][ty] = true;
                            qstn[tx][ty] = false;
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
        checkerror();
    }
}

void Board::clickright(long x, long y, bool sb)
{
    if (!mask[x][y])
    {
        if (!flag[x][y])
        {
            if (!blck[x][y])
            {
                setqstn(x, y, sb);
            }
            else
            {
                setflag(x, y, sb);
                setblock(x, y, sb);
                setblock(x, y, sb);
                setflag(x, y, sb);
            }
        }
        checkb = true;
    }
}

void Board::pause()
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
    if (sit == 5)
    {
        pausetime = gettimer() - time;
    }
}
