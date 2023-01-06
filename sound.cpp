class Sound
{

public:

    long musicn;

    unsigned long sBlank;
    unsigned long sWin;
    unsigned long sLose;
    unsigned long sError;
    unsigned long sLeft;
    unsigned long sRight;
    unsigned long sFlag;
    unsigned long sNew;
    unsigned long sSolve;
    unsigned long sMusic[10];

    bool soundb = true;
    bool musicb = true;
    long musici = -256;
    double musictime;

    Sound();
    void initsound();
    void loadsound();
    void loadmusic();
    void playsound(long id);
    void switchsound();
    void playmusic();
    void checkmusic();
    void switchmusic();

};

Sound::Sound()
{
    musicn = 5;
}

void Sound::initsound()
{
    loadsound();
    loadmusic();
    playmusic();
}

void Sound::loadsound()
{
    if (iswin())
    {
        sWin = loadaudio("./wav/Win.wav");
        sLose = loadaudio("./wav/Lose.wav");
        sError = loadaudio("./wav/Error.wav");
        sLeft = loadaudio("./wav/Left.wav");
        sRight = loadaudio("./wav/Right.wav");
        sFlag = loadaudio("./wav/Flag.wav");
        sNew = loadaudio("./wav/New.wav");
        sSolve = loadaudio("./wav/Solve.wav");
    }
}

void Sound::loadmusic()
{
    for (long k = 0; k < musicn; k++)
    {
        if (iswin())
        {
            sMusic[k] = loadaudio((mystring)"./mid/music"+i2s(k+1)+(mystring)".mid", " type sequencer");
        }
    }
}

void Sound::playsound(long id)
{
    if (iswin() && soundb)
    {
        setaudiopos(id, 0);
    }
}

void Sound::switchsound()
{
    soundb = !soundb;
    if (iswin() && soundb)
    {
        setaudiopos(sLeft, 0);
    }
}

void Sound::playmusic()
{
    if (musicb)
    {
        if (iswin())
        {
            if (musici == -256)
            {
                musici = 0;
            }
            else
            {
                long musici_ = rand() % (musicn - 1);
                if (musici_ >= musici)
                {
                    musici_++;
                }
                musici = musici_;
            }
            musictime = gettimer();
        }
        else
        {
            musici = -256;
            musictime = 0;
        }
        setaudiopos(sMusic[musici], 0);
    }
}

void Sound::checkmusic()
{
    if (musicb)
    {
        if (gettimer() > musictime)
        {
            if (getaudiopos(sMusic[musici]) < getaudiolen(sMusic[musici]))
            {
                musictime += 10;
            }
            else
            {
                playmusic();
            }
        }
    }
}

void Sound::switchmusic()
{
    musicb = !musicb;
    if (musicb)
    {
        playmusic();
    }
    else
    {
        stopaudio(sMusic[musici]);
    }
    if (soundb)
    {
        setaudiopos(sLeft, 0);
    }
}
