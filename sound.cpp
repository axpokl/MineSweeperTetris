class Sound
{

public:

    static const long musici0 = -256;
    static const long maxsound = 8;
    static const long maxmusic = 5;

    unsigned long sSound[maxsound];
    unsigned long sMusic[maxmusic];

    const char* sSounds[maxsound] = {"Win", "Lose", "Error", "Left", "Right", "Flag", "New", "Solve"};

    long sWin = 0;
    long sLose = 1;
    long sError = 2;
    long sLeft = 3;
    long sRight = 4;
    long sFlag = 5;
    long sNew = 6;
    long sSolve = 7;

    bool soundb = true;
    bool musicb = true;
    long musici = musici0;
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
        for (long id = 0; id < maxsound; id++)
        {
            sSound[id] = loadaudio((mystring)"./wav/"+sSounds[id]+(mystring)".wav");
        }
    }
}

void Sound::loadmusic()
{
    for (long k = 0; k < maxmusic; k++)
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
        setaudiopos(sSound[id], 0);
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
            if (musici == musici0)
            {
                musici = 0;
            }
            else
            {
                long musici_ = rand() % (maxmusic - 1);
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
            musici = musici0;
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
