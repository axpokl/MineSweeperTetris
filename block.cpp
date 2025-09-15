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


Block::Block()
{
    flag     = (bool (*)[maxh])calloc(maxw, sizeof(*flag));
    qstn     = (bool (*)[maxh])calloc(maxw, sizeof(*qstn));
    mine     = (bool (*)[maxh])calloc(maxw, sizeof(*mine));
    blck     = (bool (*)[maxh])calloc(maxw, sizeof(*blck));
    mask     = (bool (*)[maxh])calloc(maxw, sizeof(*mask));
    leftrule = (bool (*)[maxh])calloc(maxw, sizeof(*leftrule));
    rightrule= (bool (*)[maxh])calloc(maxw, sizeof(*rightrule));
    numb     = (long (*)[maxh])calloc(maxw, sizeof(*numb));
    initbl();
}

void Block::initbl()
{
    w = 3;
    h = 5;
    for (long i = 0; i < w; i++)
    {
        for (long j = 0; j < h; j++)
        {
            mine[i][j] = false;
            flag[i][j] = false;
            qstn[i][j] = false;
            blck[i][j] = false;
            mask[i][j] = false;
            numb[i][j] = 0;
        }
    }
    mine[0][0] = true;
    mine[0][1] = true;
    mine[1][1] = true;
    mine[0][4] = true;
    mine[1][4] = true;
    blck[2][0] = true;
    blck[2][1] = true;
    blck[1][2] = true;
    blck[2][2] = true;
    blck[1][3] = true;
    blck[2][3] = true;
    calcnumb();
}

void Block::calcnumb()
{
    for (long i = 0; i < w; i++)
    {
        for (long j = 0; j < h; j++)
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

bool Block::isok(long k, long x, long y, long &tx, long &ty)
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
    return false;
}
