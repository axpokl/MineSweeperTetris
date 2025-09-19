#pragma once
#include "disp.h"

class Block
{

public:

    static const long maxw = 128;
    static const long maxh = 128;

    long w = 0;
    long h = 0;
    long n = 0;

    long sit = 0;
    long pauseb = 0;
    long maskj = 0;
    long maski = 0;

    long tx;
    long ty;

    bool (*flag)[maxh];
    bool (*qstn)[maxh];
    bool (*mine)[maxh];
    bool (*blck)[maxh];
    bool (*mask)[maxh];
    long (*numb)[maxh];
    bool (*leftrule)[maxh];
    bool (*rightrule)[maxh];

    Block();
    void initbl();
    void calcnumb();
    bool isok(long k, long x, long y, long &tx, long &ty);

};
