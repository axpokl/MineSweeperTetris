class Sound
{

public:

    const long musicn = 3;

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
    long musici = -1;
    double musictime;

    Sound();
    void initsound();
    void initmusic();
    void playsound(long id);
    void playmusic();
    void checkmusic();
    void switchmusic();

};

Sound::Sound()
{
}

void Sound::initsound()
{
    initmusic();
    playmusic();
}

void Sound::initmusic()
{
    sWin = loadaudio("./wav/Win.wav");
    sLose = loadaudio("./wav/Lose.wav");
    sError = loadaudio("./wav/Error.wav");
    sLeft = loadaudio("./wav/Left.wav");
    sRight = loadaudio("./wav/Right.wav");
    sFlag = loadaudio("./wav/Flag.wav");
    sNew = loadaudio("./wav/New.wav");
    sSolve = loadaudio("./wav/Solve.wav");
    sMusic[0] = loadaudio("./wav/music1.mid"," type sequencer");
    sMusic[1] = loadaudio("./wav/music2.mid"," type sequencer");
    sMusic[2] = loadaudio("./wav/music3.mid"," type sequencer");
}

void Sound::playsound(long id)
{
    if (soundb)
    {
        setaudiopos(id, 0);
    }
}

void Sound::playmusic()
{
    if (musicb)
    {
        if (iswin())
        {
            musici = (musici + 1) % musicn;
            musictime = gettimer();
        }
        else
        {
            musici = 0;
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
}
