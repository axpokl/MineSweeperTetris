class Board: public Block
{

public:

    Steam st;
    Sound sd;

    double time;
    double time_;
    double pausetime;
    long mode = 0;
    long mode_ = 0;
    bool sb;
    bool rightb = false;
    bool aliveb = false;

    long maskj0;
    long line;
    long level;
    bool solveb;
    bool checkb;
    bool checkr;
    bool dieb;
    long diex;
    long diey;
    long tetrisi;
    long missi;
    long missline;

    long rx;
    long ry;

    long maxbdw;
    long maxbdh;

    long w_;
    long h_;
    long cred;
    double mult;
    bool delayb = true;

    bool tutb = true;
    long tuti;
    long tutx[13] = {5, 5, 4, 9, 8, 8, 9, 10, 2, 2, 3, 3, 2};
    long tuty[13] = {16, 17, 17, 17, 17, 18, 18, 18, 17, 16, 17, 19, 19};
    long tutm[13] = {1, 1, 3, 2, 3, 3, 3, 3, 1, 2, 3, 3, 3};

    Board();
    void initbd();
    void initbd(long w_, long h_, long maskj_, long n_);
    void initbd(long mode_, long md);
    void randmine(long x, long y);
    void tutmine();
    void resetbd(long x, long y);
    void solveblank();
    void solve0();
    void solve1();
    bool checkerror();
    void checkline(bool checkb_);
    void checkline();
    void setqstn(long x, long y);
    void setflag(long x, long y);
    void setblock(long x, long y);
    void clicknumb(long x, long y, bool sb_);
    void clickleft(long x, long y, bool sb_);
    void clickright(long x, long y, bool sb_);
    void clickleft(long x, long y, bool sb_, long md_);
    void clickright(long x, long y, bool sb_, long md_);
    void addline(bool b);
    void delline(long l);
    bool addmask();
    void checkdie();
    void pause();
    bool ischeat();

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
    rule rulemain[16384];
    int rulemainc;
    long blckrule[128][128];
    void createrule();
    void comparerule2(long rule1, long rule2);
    void comparerule();
    void solve2();

};

Board::Board()
{
    randomize();
}

void Board::initbd()
{
    if (!ischeat())
    {
        st.setlead(mode);
    }
    sit = 0;
    line = 0;
    level = 0;
    tetrisi = 0;
    missi = 0;
    missline = 0;
    w = min(max(w, 12), min(128, maxbdw));
    h = min(max(h, 8), min(128, maxbdh));
    n = max(1, min(n, w - 1));
    maskj = min(h - 4, maskj0);
    maski = 0;
    for (long i = 0; i < w; i++)
    {
        for (long j = 0; j < h; j++)
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
    long mode__[4] = {0, 1, 2, 4};
    mode_ = mode_ | mode__[mode];
    if (mode == 0)
    {
        st.addach(st.achgencustom);
    }
    if (mode_ == 7)
    {
        st.addach(st.achgenmode);
    }
    rightb = false;
    tuti = 0;
    tutb = 0;
    checkr = false;
}

void Board::initbd(long w_, long h_, long maskj_, long n_)
{
    w = w_;
    h = h_;
    n = n_;
    maskj0 = maskj_;
    initbd();
}

void Board::initbd(long mode_, long md)
{
    if (!ischeat())
    {
        st.setlead(mode);
    }
    mode = mode_;
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
    st.mdb = (md == 0);
}

void Board::randmine(long x, long y)
{
    for (long j = 0; j < h; j++)
    {
        for (long i = 0; i < w; i++)
        {
            rx = rand() % w;
            ry = j;
            bool mb = mine[rx][ry];
            mine[rx][ry] = mine[i][j];
            mine[i][j] = mb;
        }
    }
    for (long k = 0; k < 10; k++)
    {
        for (long j = y - 1; j <= y + 1; j++)
        {
            for (long i = x - 1; i <= x + 1; i++)
            {
                if (j >= 0 && i >= 0 & j < h & i < w)
                {
                    if (mine[i][j])
                    {
                        rx = rand() % w;
                        ry = j;
                        bool mb = mine[rx][ry];
                        mine[rx][ry] = mine[i][j];
                        mine[i][j] = mb;
                    }
                }
            }
        }
    }
    rx = x;
    ry = y;
    if (mine[x][y])
    {
        for (long i = 0; i < w; i++)
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
}

void Board::tutmine()
{
    long rx0_[5] = {8,10,1,0,0};
    long rx1_[5] = {5,3,9,2,9};
    long i;
    bool mb;
    for (long j = 0; j < h; j++)
    {
        if (j >= h - 5)
        {
            i = 1;
            rx = rx1_[j - h + 5];
            ry = j;
            mb = mine[rx][ry];
            mine[rx][ry] = mine[i][j];
            mine[i][j] = mb;
            i = 0;
            rx = rx0_[j - h + 5];
            ry = j;
            mb = mine[rx][ry];
            mine[rx][ry] = mine[i][j];
            mine[i][j] = mb;
        }
        else
        {
            for (long i = 0; i < w; i++)
            {
                rx = rand() % w;
                ry = j;
                bool mb = mine[rx][ry];
                mine[rx][ry] = mine[i][j];
                mine[i][j] = mb;
            }
        }
    }
}

void Board::resetbd(long x, long y)
{
    if (tutb)
    {
        tutmine();
    }
    else
    {
        randmine(x, y);
    }
    calcnumb();
    time = gettimer();
    time_ = time;
    sit = 1;
    st.addach(st.achgenstart);
}

void Board::solveblank()
{
    solveb = false;
    if (sit > 0 && sit < 4)
    {
        for (long i = 0; i < w; i++)
        {
            for (long j = 0; j < h; j++)
            {
                if (!mask[i][j] && !mine[i][j] && (numb[i][j] == 0))
                {
                    clickleft(i, j, false);
                }
            }
        }
        for (long i = w - 1; i >= 0; i--)
        {
            for (long j = h - 1; j >= 0; j--)
            {
                if (!mask[i][j] && !mine[i][j] && (numb[i][j] == 0))
                {
                    clickleft(i, j, false);
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
        for (long i = 0; i < w; i++)
        {
            for (long j = 0; j < h; j++)
            {
                if (blck[i][j] && (numb[i][j] == 0))
                {
                    clicknumb(i, j, false);
                }
            }
        }
        for (long i = w - 1; i >= 0; i--)
        {
            for (long j = h - 1; j >= 0; j--)
            {
                if (blck[i][j] && (numb[i][j] == 0))
                {
                    clicknumb(i, j, false);
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
        for (long i = 0; i < w; i++)
        {
            for (long j = 0; j < h; j++)
            {
                if (blck[i][j] && (numb[i][j] >= 0))
                {
                    clicknumb(i, j, false);
                }
            }
        }
        for (long i = w - 1; i >= 0; i--)
        {
            for (long j = h - 1; j >= 0; j--)
            {
                if (blck[i][j] && (numb[i][j] >= 0))
                {
                    clicknumb(i, j, false);
                }
            }
        }
        sd.playsound(sd.sSolve);
    }
}

void Board::createrule()
{
    for (long i = 0; i < w; i++)
    {
        for (long j = 0; j < h; j++)
        {
            blckrule[i][j] = -1;
            if (blck[i][j])
            {
                ruletemp.x = i;
                ruletemp.y = j;
                ruletemp.numbc = numb[i][j];
                ruletemp.blckc = 0;
                for (long k = 0; k < 8; k++)
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
                            ruletemp.blckc++;
                        }
                    }
                }
                if (ruletemp.blckc > 0)
                {
                    blckrule[i][j] = rulemainc;
                    rulemain[rulemainc] = ruletemp;
                    rulemainc++;
                }
            }
        }
    }
}

void Board::comparerule2(long rule1c, long rule2c)
{
    rule rule1 = rulemain[rule1c];
    rule rule2 = rulemain[rule2c];
    for (int rule1k = 0; rule1k < rulemain[rule1c].blckc; rule1k++)
    {
        for (int rule2k = 0; rule2k < rulemain[rule2c].blckc; rule2k++)
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
        for (int rule1k = 0; rule1k < rulemain[rule1c].blckc; rule1k++)
        {
            if ((rule1.blckx[rule1k] >= 0) && (rule1.blcky[rule1k] >= 0))
            {
                clickright(rule1.blckx[rule1k], rule1.blcky[rule1k], false);
            }
        }
        for (int rule2k = 0; rule2k < rulemain[rule2c].blckc; rule2k++)
        {
            if ((rule2.blckx[rule2k] >= 0) && (rule2.blcky[rule2k] >= 0))
            {
                clickleft(rule2.blckx[rule2k], rule2.blcky[rule2k], false);
            }
        }
    }
    if (rule2.blckc == (rule2.numbc - rule1.numbc))
    {
        for (int rule2k = 0; rule2k < rulemain[rule2c].blckc; rule2k++)
        {
            if ((rule2.blckx[rule2k] >= 0) && (rule2.blcky[rule2k] >= 0))
            {
                clickright(rule2.blckx[rule2k], rule2.blcky[rule2k], false);
            }
        }
        for (int rule1k = 0; rule1k < rulemain[rule1c].blckc; rule1k++)
        {
            if ((rule1.blckx[rule1k] >= 0) && (rule1.blcky[rule1k] >= 0))
            {
                clickleft(rule1.blckx[rule1k], rule1.blcky[rule1k], false);
            }
        }
    }
}

void Board::comparerule()
{
    long i = 0;
    long j = 0;
    for (int rulemaini = 0; rulemaini < rulemainc; rulemaini++)
    {
        i = rulemain[rulemaini].x;
        j = rulemain[rulemaini].y;
        for (long k = 0; k < 8; k++)
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
    bool result = false;
    if (sit != 2)
    {
        dieb = false;
        for (long i = 0; i < w; i++)
        {
            for (long j = 0; j < h; j++)
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
                    st.compscr(line - missline, mode, 6);
                    missline = line;
                    missi++;
                    st.compscr(missi, mode, 12);
                    addline(false);
                    addline(true);
                    if (sit == 2)
                    {
                        sit = 1;
                    }
                    st.addscr(st.scrdead, 1, mode);
                    sd.playsound(sd.sError);
                    sb = false;
                    result = true;
                    checkr = true;
                }
            }
        }
    }
    return result;
}

void Board::checkline(bool checkb_)
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
            long j_ = 0;
            while (j >= maskj)
            {
                blckc = 0;
                flagc = 0;
                for (long i = 0; i < w; i++)
                {
                    if (!blck[i][j])
                    {
                        blckc++;
                    }
                    if (flag[i][j])
                    {
                        flagc++;
                    }
                }
                if (blckc == n || flagc == n)
                {
                    result = true;
                    delline(j);
                    if (delayb & checkb_)
                    {
                        for (long k = 0; k < mult; k++)
                        {
                            Line158(0, (16 * (j - j_ + 3) + 8) * mult + k - (mult - 1) / 2, w_ * mult, 0, cred);
                        }
                    }
                    j_++;
                }
                else
                {
                    j--;
                }
            }
            if (result)
            {
                sd.playsound(sd.sSolve);
                if (delayb & checkb_)
                {
                    freshwin();
                    long dl = 500.0 / (1.0 + (double)level /5.0);
                    time += dl / 1000.0;
                    delay(dl);
                }
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

void Board::checkline()
{
    checkline(true);
}

void Board::addline(bool b)
{
    maskj--;
    long j = maskj;
    for (long i = 0; i < w; i++)
    {
        mask[i][j] = false;
    }
    for (long i = 0; i < w; i++)
    {
        for (long j = maskj + 1; j >= maskj; j--)
        {
            numb[i][j] = 0;
            for (long k = 0; k < 8; k++)
            {
                if (isok(k, i, j, tx, ty))
                {
                    if (mine[tx][ty])
                    {
                        numb[i][j]++;
                    }
                }
            }
        }
    }
    checkb = b;
    checkline(false);
    checkdie();
}

bool Board::addmask()
{
    if ((sit > 0) && (sit < 4))
    {
        if (!tutb)
        {
            if (gettimer() > time + 5.0 / (level + 5.0))
            {
                checkb = true;
                checkline(false);
                while (gettimer() > time + 5.0 / (level + 5.0))
                {
                    time += 5.0 / (level + 5.0);
                    maski++;
                    if (maski == w)
                    {
                        maski = 0;
                        addline(true);
                    }
                }
                checkb = true;
                checkline(false);
                checkdie();
                return true;
            }
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
    if (((maskj == 0 && maski > 0) || maskj < 0) && sit != 4)
    {
        st.compscr(line - missline, mode, 6);
        missline = line;
        aliveb = false;
        sit = 4;
        if (dieb)
        {
            blck[diex][diey] = true;
        }
        sd.playsound(sd.sLose);
        if (!rightb)
        {
            st.addach(st.achhidright);
        }
        if (!ischeat())
        {
            st.setlead(mode);
        }
    }
    if (((maskj == 0 && maski == 0)) && sit != 4)
    {
        aliveb = true;
    }
    else
    {
        if (aliveb)
        {
            st.addach(st.achhidalive);
        }
    }
}

void Board::delline(long l)
{
    if (sit < 4)
    {
        checkr = false;
        maskj++;
        for (long i = 0; i < w; i++)
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
        for (long i = 0; i < w; i++)
        {
            rx = rand() % w;
            ry = 0;
            long j = 0;
            bool mb = mine[rx][ry];
            mine[rx][ry] = mine[i][j];
            mine[i][j] = mb;
        }
        for (long i = 0; i < w; i++)
        {
            for (long j = l + 1; j >= l; j--)
            {
                numb[i][j] = 0;
                for (long k = 0; k < 8; k++)
                {
                    if (isok(k, i, j, tx, ty))
                    {
                        if (mine[tx][ty])
                        {
                            numb[i][j]++;
                        }
                    }
                }
            }
        }
        line++;
        line = min(line, 999999);
        st.compscr(line, mode, 0);
        if (st.mdb)
        {
            st.compscr(line, mode, 3);
        }
        long scrtotal_[4] = {0, 2, 3, 6};
        st.addscr(st.scrtotal, scrtotal_[mode], mode);
        if (line > 9999)
        {
            st.addach(st.achhidedge);
        }
        if (maskj > h - 4)
        {
            tetrisi++;
            st.compscr(tetrisi, mode, 9);
            for (long k = 0; k < 4; k++)
            {
                line++;
                line = min(line, 999999);
                st.compscr(line, mode, 0);
                if (st.mdb)
                {
                    st.compscr(line, mode, 3);
                }
                addline(false);
                sit = 3;
            }
            checkb = true;
            checkline(false);
            sd.playsound(sd.sNew);
            st.addscr(st.scrfour, 1, mode);
        }
        while ((level + 1)*(level + 1) <= line)
        {
            level++;
            sd.playsound(sd.sWin);
        }
    }
}

void Board::setqstn(long x, long y)
{
    qstn[x][y] = !qstn[x][y];
    sd.playsound(sd.sFlag);
}

void Board::setflag(long x, long y)
{
    if (sit < 4)
    {
        long qc = 0;
        bool sc = false;
        for (long k = 0; k < 8; k++)
        {
            if (isok(k, x, y, tx, ty))
            {
                if (!blck[tx][ty])
                {
                    qc++;
                }
            }
        }
        if (qc == numb[x][y])
        {
            for (long k = 0; k < 8; k++)
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
                sb = false;
            }
        }
    }
}

void Board::setblock(long x, long y)
{
    if (sit < 4)
    {
        long qn = 0;
        long qq = 0;
        bool sr = false;
        for (long k = 0; k < 8; k++)
        {
            if (isok(k, x, y, tx, ty))
            {
                if (flag[tx][ty])
                {
                    qn++;
                }
                if (qstn[tx][ty])
                {
                    qq++;
                }
            }
        }
        if ((qn == numb[x][y]) || ((qn + qq) == numb[x][y]))
        {
            for (long k = 0; k < 8; k++)
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
                sb = false;
            }
        }
        checkerror();
    }
}

void Board::clicknumb(long x, long y, bool sb_)
{
    sb = sb_;
    if (sb)
    {
        rightb = true;
    }
    setflag(x, y);
    setblock(x, y);
    setblock(x, y);
    setflag(x, y);
}


void Board::clickleft(long x, long y, bool sb_)
{
    clickleft(x, y, sb_, 2);
}

void Board::clickright(long x, long y, bool sb_)
{
    clickright(x, y, sb_, 2);
}

void Board::clickleft(long x, long y, bool sb_, long md_)
{
    if (!mask[x][y])
    {
        if (!flag[x][y])
        {
            if (!blck[x][y])
            {
                if (md_ == 2)
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
            }
            else if (sb_)
            {
                clicknumb(x, y, sb_);
            }
        }
        checkb = true;
    }
}

void Board::clickright(long x, long y, bool sb_, long md_)
{
    if (!mask[x][y])
    {
        if (!flag[x][y])
        {
            if (!blck[x][y])
            {
                if (md_ == 2)
                {
                    setqstn(x, y);
                }
            }
            else if (sb_)
            {
                clicknumb(x, y, sb_);
            }
        }
        checkb = true;
    }
    if (sit == 0)
    {
        bool qstnb = true;
        for (long i = 0; i < w; i++)
        {
            for (long j = maskj; j < h; j++)
            {
                if (!qstn[i][j])
                {
                    qstnb = false;
                }
            }
        }
        if (qstnb)
        {
            st.addach(st.achhidmark);
        }
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

bool Board::ischeat()
{
    long mines[4] = {0, 12, 16, 32};
    long score = line - tetrisi * 4 - missi * 2 - 8;
    double gametime = time - time_;
    double basetime = (double) mines[mode] / (1.0 + (double) level / 5.0);
    double mintime = basetime * score;
    return (gametime < mintime);
}