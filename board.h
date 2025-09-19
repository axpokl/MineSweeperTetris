#pragma once
#include "steam.h"
#include "sound.h"
#include "block.h"

class Board : public Block
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
    long tutx[13] = { 5, 5, 4, 9, 8, 8, 9, 10, 2, 2, 3, 3, 2 };
    long tuty[13] = { 16, 17, 17, 17, 17, 18, 18, 18, 17, 16, 17, 19, 19 };
    long tutm[13] = { 1, 1, 3, 2, 3, 3, 3, 3, 1, 2, 3, 3, 3 };

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
    rule* rulemain = nullptr;
    long rulemainc;
    long (*blckrule)[maxh] = nullptr;
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