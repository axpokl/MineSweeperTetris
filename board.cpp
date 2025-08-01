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
    long rightb = 0;
    bool aliveb = false;

    long maskj0;
    bool maskjb;
    long line;
    long level;
    bool solvebb;
    bool solveb0;
    bool solveb1;
    bool solveb2;
    bool solveb3;
    long checkr;
    bool dieb;
    long diex;
    long diey;
    long tetrisi;
    long missi;
    long missline;
    long bouns;
    long sum;

    long rx;
    long ry;

    long maxbdw;
    long maxbdh;

    long w_;
    long h_;
    long cred;
    double mult;
    long delayb = 1;
    long delayb__ = 0;
    long mdb;
    long mdb_ = false;

    long mx;
    long my;

    long tutb = 1;
    long tuti;
    long tutx[13] = {5, 5, 4, 9, 8, 8, 9, 10, 2, 2, 3, 3, 2};
    long tuty[13] = {16, 17, 17, 17, 17, 18, 18, 18, 17, 16, 17, 19, 19};
    long tutm[13] = {1, 1, 3, 2, 3, 3, 3, 3, 1, 2, 3, 3, 3};

    bool relaxb = false;

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
    rule rulemain[maxw*maxh];
    long rulemainc;
    long blckrule[maxw][maxh];
    long solven;

    Board();
    void initbd();
    void initbd(long w_, long h_, long maskj_, long n_);
    void initbd(long mode_, long md_);
    void randmine(long x, long y);
    void tutmine();
    void resetbd(long x, long y);
    void solveblank();
    void solveblank_();
    void solve0();
    void solve0_();
    void solve1();
    void solve1_();
    void createrule();
    void comparerule(long rule1, long rule2);
    void comparerule();
    void applyrule(bool applyb);
    void solve2(bool applyb);
    void solve2();
    void solve2_(bool applyb);
    void solve2_();
    void solve3_();
    bool checkerror(long i, long j);
    bool checkerror();
    void checkline(bool delayb_);
    void setqstn(long x, long y, bool sb_);
    void setqstn(long x, long y);
    void setflag(long x, long y);
    void setblock(long x, long y);
    void clicknumb(long x, long y, bool sb_);
    void clickleft(long x, long y, bool sb_);
    void clickright(long x, long y, bool sb_);
    void clickleft(long x, long y, bool sb_, long md_);
    void clickright(long x, long y, bool sb_, long md_);
    void addline();
    void addline(bool misslineb);
    void delline(long l);
    bool addmask();
    void checkdie();
    void pause();

};

Board::Board()
{
    srand((unsigned)::time(NULL) + (unsigned)clock());
}

void Board::initbd()
{
    st.setlead(mode);
    sit = 0;
    line = 0;
    level = 0;
    tetrisi = 0;
    missi = 0;
    missline = 0;
    sum = 0;
    w = min(max(w, 12), min(maxw, maxbdw));
    h = min(max(h, 8), min(maxh, maxbdh));
    n = max(1, min(n, w - 1));
    maskj = min(h - 4, maskj0);
    if (relaxb == true) maskj = 1;
    maski = 0;
    maskjb = false;
    for (long i = 0; i < w; i++)
    {
        for (long j = 0; j < h; j++)
        {
            mine[i][j] = (i < n);
            flag[i][j] = false;
            leftrule[i][j] = false;
            rightrule[i][j] = false;
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
    rightb = 0;
    tuti = 0;
    tutb = 0;
    checkr = 0;
    pauseb = 0;
    mx = -1;
    my = -1;
    bouns = 0;
    solven = 0;
}

void Board::initbd(long w_, long h_, long maskj_, long n_)
{
    w = w_;
    h = h_;
    n = n_;
    maskj0 = maskj_;
    initbd();
}

void Board::initbd(long mode_, long md_)
{
    st.setlead(mode);
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
    mdb = (md_ <= 1);
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
    for (long k = 0; k < n ; k++)
    {
        for (long j = y - 1; j <= y + 1; j++)
        {
            for (long i = x - 1; i <= x + 1; i++)
            {
                if (j >= 0 && i >= 0 && j < h && i < w)
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
    if (tutb == 1)
    {
        tutmine();
    }
    else
    {
        randmine(x, y);
    }
    calcnumb();
    time = GetTimeR();
    time_ = time;
    sit = 1;
    st.addach(st.achgenstart);
}

void Board::solveblank()
{
    solvebb = false;
    if (sit > 0 && sit < 4 && pauseb == 0)
    {
        for (long i = 0; i < w; i++)
        {
            for (long j = 2; j < h; j++)
            {
                if (!mask[i][j] && !mine[i][j] && (numb[i][j] == 0))
                {
                    clickleft(i, j, false);
                }
            }
        }
        for (long i = w - 1; i >= 0; i--)
        {
            for (long j = h - 1; j >= 2; j--)
            {
                if (!mask[i][j] && !mine[i][j] && (numb[i][j] == 0))
                {
                    clickleft(i, j, false);
                }
            }
        }
    }
}

void Board::solveblank_()
{
    solvebb = true;
    while (solvebb)
    {
        solveblank();
    }
}

void Board::solve0()
{
    solveb0 = false;
    if (sit < 4 && pauseb == 0)
    {
        for (long i = 0; i < w; i++)
        {
            for (long j = 2; j < h; j++)
            {
                if (blck[i][j] && (numb[i][j] == 0))
                {
                    clicknumb(i, j, false);
                }
            }
        }
        for (long i = w - 1; i >= 0; i--)
        {
            for (long j = h - 1; j >= 2; j--)
            {
                if (blck[i][j] && (numb[i][j] == 0))
                {
                    clicknumb(i, j, false);
                }
            }
        }
    }
}

void Board::solve0_()
{
    solveb0 = true;
    while (solveb0)
    {
        solve0();
    }
}

void Board::solve1()
{
    solveb1 = false;
    if (sit < 4 && pauseb == 0)
    {
        for (long i = 0; i < w; i++)
        {
            for (long j = 2; j < h; j++)
            {
                if (blck[i][j] && (numb[i][j] >= 0))
                {
                    clicknumb(i, j, false);
                }
            }
        }
        for (long i = w - 1; i >= 0; i--)
        {
            for (long j = h - 1; j >= 2; j--)
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

void Board::solve1_()
{
    solveb1 = true;
    while (solveb1)
    {
        checkline(false);
        solve1();
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
                        if (flag[tx][ty] || rightrule[tx][ty])
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
                blckrule[i][j] = rulemainc;
                rulemain[rulemainc] = ruletemp;
                rulemainc++;
            }
        }
    }
}

void Board::comparerule(long rule1c, long rule2c)
{
    rule rule1 = rulemain[rule1c];
    rule rule2 = rulemain[rule2c];
    for (long rule1k = 0; rule1k < rulemain[rule1c].blckc; rule1k++)
    {
        for (long rule2k = 0; rule2k < rulemain[rule2c].blckc; rule2k++)
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
        for (long rule1k = 0; rule1k < rulemain[rule1c].blckc; rule1k++)
        {
            if ((rule1.blckx[rule1k] >= 0) && (rule1.blcky[rule1k] >= 0))
            {
                if (!mask[rule1.blckx[rule1k]][rule1.blcky[rule1k]])
                {
                    rightrule[rule1.blckx[rule1k]][rule1.blcky[rule1k]] = true;
                }
            }
        }
        for (long rule2k = 0; rule2k < rulemain[rule2c].blckc; rule2k++)
        {
            if ((rule2.blckx[rule2k] >= 0) && (rule2.blcky[rule2k] >= 0))
            {
                if (!mask[rule2.blckx[rule2k]][rule2.blcky[rule2k]])
                {
                    leftrule[rule2.blckx[rule2k]][rule2.blcky[rule2k]] = true;
                }
            }
        }
    }
}

void Board::comparerule()
{
    long x = 0;
    long y = 0;
    for (long rulemaini = 0; rulemaini < rulemainc; rulemaini++)
    {
        x = rulemain[rulemaini].x;
        y = rulemain[rulemaini].y;
        for (long k = 0; k < 8; k++)
        {
            if (isok(k, x, y, tx, ty))
            {
                if (blckrule[tx][ty] >= 0)
                {
                    comparerule(rulemaini, blckrule[tx][ty]);
                }
            }
        }
    }
}

void Board::applyrule(bool applyb)
{
    for (long i = 0; i < w; i++)
    {
        for (long j = 2; j < h; j++)
        {
            if (leftrule[i][j] && !blck[i][j] && !mask[i][j])
            {
                solvebb = true;
                solveb0 = true;
                solveb1 = true;
                solveb2 = true;
                solveb3 = true;
                solven++;
                if (applyb)
                {
                    clickleft(i, j, false);
                }
            }
            if (rightrule[i][j] && !blck[i][j] && !qstn[i][j] && !flag[i][j] && !mask[i][j])
            {
                solvebb = true;
                solveb0 = true;
                solveb1 = true;
                solveb2 = true;
                solveb3 = true;
                solven++;
                if (applyb)
                {
                    clickright(i, j, false);
                }
            }
        }
    }
}

void Board::solve2(bool applyb)
{
    solveb2 = false;
    rulemainc = 0;
    solven = 0;
    if (sit < 4 && pauseb == 0)
    {
        createrule();
        comparerule();
        applyrule(applyb);
        if (applyb)
        {
            sd.playsound(sd.sSolve);
        }
    }
}

void Board::solve2()
{
    solve2(true);
}

void Board::solve2_(bool applyb)
{
    solveb2 = true;
    long solven_ = -1;
    while (solveb2 && ((solven_ < solven) || applyb))
    {
        solven_ = solven;
        if (applyb)
        {
            checkline(false);
        }
        solve2(applyb);
    }
}

void Board::solve2_()
{
    solve2_(true);
}

void Board::solve3_()
{
    solveb3 = true;
    while (solveb3)
    {
        checkline(false);
        solve1();
        checkline(false);
        solve2();
        solveb3 = solveb1 || solveb2;
    }
}

bool Board::checkerror(long i, long j)
{
    bool result = false;
    if (blck[i][j] && mine[i][j] && sit != 2 && sit < 4)
    {
        dieb = true;
        diex = i;
        diey = j;
        blck[i][j] = false;
        flag[i][j] = true;
        qstn[i][j] = false;
        sit = 2;
        if (solven > 0 || tutb > 0)
        {
            addline();
            addline();
            st.compscr(line - missline, mode, st.scrindexnomiss);
            missline = line;
            missi++;
            st.compscr(missi, mode, st.scrindexmiss);
            checkline(true);
            checkdie();
        }
        if (sit == 2)
        {
            sit = 1;
        }
        st.addscr(st.scrdead, 1, mode);
        sd.playsound(sd.sError);
        sb = false;
        result = true;
        checkr = 1;
    }
    return result;
}

bool Board::checkerror()
{
    bool result = false;
    if (sit != 2 && sit < 4)
    {
        dieb = false;
        for (long i = 0; i < w; i++)
        {
            for (long j = 0; j < h; j++)
            {
                result = checkerror(i, j);
            }
        }
    }
    return result;
}

void Board::checkline(bool delayb_)
{
    if (sit > 0 && sit < 4 && pauseb == 0)
    {
        long j;
        solve0_();
        bool delb = false;
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
                delb = true;
                delline(j);
                if ((delayb & delayb_) || (tutb == 1))
                {
                    for (long k = 0; k < mult; k++)
                    {
                        Line(0, (16 * (j - j_ + 3) + 8) * mult + k - (mult - 1) / 2, w_ * mult, 0, (unsigned long) cred);
                    }
                }
                j_++;
            }
            else
            {
                j--;
            }
        }
        if (delb)
        {
            sd.playsound(sd.sSolve);
            if ((delayb & delayb_) || (tutb == 1))
            {
                FreshWin();
                long dl = 1000.0 / (1.0 + (double)level /5.0);
                time += dl / 1000.0;
                Delay(dl);
                delayb__ = 1;
            }
        }
        solve0_();
        solve2_(false);
    }
}

void Board::addline(bool misslineb)
{
    if (sit > 0 && sit < 4 && pauseb == 0)
    {
        bouns--;
        maskj--;
        if (relaxb == true)
        {
            if ((maskj < 1))
            {
                line--;
                sum--;
                line = max(line, 0);
                if (misslineb == true)
                {
                    missline--;
                    missline = max(missline, 0);
                }
                sum = max(sum, 0);
                maskj++;
            }
        }
        long j = maskj;
        if (maskj < 0)
        {
            maskjb = true;
        }
        else
        {
            for (long i = 0; i < w; i++)
            {
                mask[i][j] = false;
            }
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
    }
}

void Board::addline()
{
    addline(true);
}


bool Board::addmask()
{
    if (sit > 0 && sit < 4 && pauseb == 0)
    {
        if (tutb == 0)
        {
            if (GetTimeR() > time + 5.0 / (level + 5.0))
            {
                while (GetTimeR() > time + 5.0 / (level + 5.0))
                {
                    time += 5.0 / (level + 5.0);
                    maski++;
                    if (maski == w)
                    {
                        maski = 0;
                        addline();
                        checkline(true);
                    }
                }
                checkdie();
                return true;
            }
        }
    }
    else
    {
        time = GetTimeR() - pausetime;
    }
    return false;
}

void Board::checkdie()
{
    if ((((maskj == 0 && maski > 0) || maskj < 0) && sit < 4) && (relaxb == false))
    {
        st.compscr(line - missline, mode, st.scrindexnomiss);
        missline = line;
        aliveb = false;
        sit = 4;
        if (dieb)
        {
            blck[diex][diey] = true;
        }
        sd.playsound(sd.sLose);
        if (rightb == 0)
        {
            st.addach(st.achhidright);
        }
        st.setlead(mode);
    }
    if (((maskj == 0 && maski == 0)) && sit < 4)
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
    if (sit > 0 && sit < 4 && pauseb == 0)
    {
        checkr = 0;
        if (relaxb == true)
        {
            line++;
            sum++;
            line = min(line, 999999);
            addline(false);
        }
        else
        {
            maskj++;
        }
        for (long i = 0; i < w; i++)
        {
            for (long j = l; j >= 0; j--)
            {
                if (j == 0)
                {
                    mine[i][j] = (i < n);
                    mask[i][j] = !maskjb;
                    flag[i][j] = false;
                    leftrule[i][j] = false;
                    rightrule[i][j] = false;
                    qstn[i][j] = false;
                    blck[i][j] = false;
                }
                else
                {
                    mine[i][j] = mine[i][j - 1];
                    mask[i][j] = mask[i][j - 1] && !relaxb;
                    flag[i][j] = flag[i][j - 1];
                    leftrule[i][j] = leftrule[i][j - 1];
                    rightrule[i][j] = rightrule[i][j - 1];
                    qstn[i][j] = qstn[i][j - 1];
                    blck[i][j] = blck[i][j - 1];
                    numb[i][j] = numb[i][j - 1];
                }
            }
        }
        maskjb = false;
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
        sum++;
        line = min(line, 999999);
        if (sum == line + tetrisi)
        {
            st.compscr(line, mode, st.scrindexline);
            if (mdb == 1)
            {
                st.compscr(line, mode, st.scrindexmdb);
            }
            st.compscr(line - missline, mode, st.scrindexnomiss);
            long scrtotal_[4] = {0, 2, 3, 6};
            st.addscr(st.scrtotal, scrtotal_[mode], mode);
            if (line > 9999)
            {
                st.addach(st.achhidedge);
            }
        }
        if (maskj > h - 4)
        {
            tetrisi++;
            sum++;
            st.compscr(tetrisi, mode, st.scrindextetris);
            line = line + 4 + max(0, bouns);
            sum = sum + 4 + max(0, bouns);
            line = min(line, 999999);
            if (sum == line + tetrisi)
            {
                st.compscr(line, mode, st.scrindexline);
                if (mdb == 1)
                {
                    st.compscr(line, mode, st.scrindexmdb);
                }
                st.compscr(line - missline, mode, st.scrindexnomiss);
            }
            for (long k = 0; k < 4; k++)
            {
                addline();
            }
            checkline(false);
            sit = 3;
            bouns = 4;
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

void Board::setqstn(long x, long y, bool sb_)
{
    qstn[x][y] = !qstn[x][y];
    if (sb_)
    {
        sd.playsound(sd.sFlag);
    }
}

void Board::setqstn(long x, long y)
{
    setqstn(x, y, true);
}

void Board::setflag(long x, long y)
{
    if (sit > 0 && sit < 4 && pauseb == 0)
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
                    if (!blck[tx][ty] && !flag[tx][ty] && !mask[tx][ty])
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
    if (sit > 0 && sit < 4 && pauseb == 0)
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
                            solvebb = true;
                            solveb0 = true;
                            solveb1 = true;
                            solveb2 = true;
                            solveb3 = true;
                            checkerror(tx, ty);
                        }
                        else if (!mdb_ || tutb == 1)
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
        if (sb)
        {
            checkerror();
        }
    }
}

void Board::clicknumb(long x, long y, bool sb_)
{
    sb = sb_;
    if (sb)
    {
        rightb = 1;
    }
    setblock(x, y);
    if (!mdb_ || tutb == 1)
    {
        setblock(x, y);
        setflag(x, y);
    }
}

void Board::clickleft(long x, long y, bool sb_)
{
    clickleft(x, y, sb_, 3);
}

void Board::clickright(long x, long y, bool sb_)
{
    clickright(x, y, sb_, 3);
}

void Board::clickleft(long x, long y, bool sb_, long md_)
{
    if (!mask[x][y])
    {
        if (!flag[x][y])
        {
            if (!blck[x][y])
            {
                if (md_ >= 3)
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
                    if (!checkerror() && sb_)
                    {
                        sd.playsound(sd.sLeft);
                    }
                }
            }
            else if (sb_)
            {
                mdb_ = (md_ == 5);
                clicknumb(x, y, sb_);
                mdb_ = false;
            }
        }
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
                if (md_ >= 3)
                {
                    setqstn(x, y, sb_);
                }
            }
            else if (sb_ && md_ != 5)
            {
                clicknumb(x, y, sb_);
            }
        }
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
    if (pauseb == 0)
    {
        pausetime = GetTimeR() - time;
    }
    pauseb = (pauseb == 0);
}
