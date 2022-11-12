class Block
{

public:

    long w = 0;
    long h = 0;
    long n = 0;

    long sit = 0;
    long maskj = 0;
    long maski = 0;

    long tx;
    long ty;

    bool flag[100][100];
    bool qstn[100][100];
    bool mine[100][100];
    bool blck[100][100];
    bool mask[100][100];
    long numb[100][100];

    Block();
    void initbl();
    void calcnumb();
    bool isok(long k, long x, long y, long &tx, long &ty);

};


Block::Block()
{
    initbl();
}

void Block::initbl()
{
    w = 3;
    h = 5;
    for (long i = 0; i < w; i++ )
    {
        for (long j = 0; j < h; j++ )
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
}
