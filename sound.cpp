class Sound
{

public:

    bool soundb;
    bool musicb;

    unsigned long sBlank;
    unsigned long sWin;
    unsigned long sLose;
    unsigned long sError;
    unsigned long sLeft;
    unsigned long sRight;
    unsigned long sFlag;
    unsigned long sNew;
    unsigned long sSolve;

    unsigned long sMusic[2];
    long musici;
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
    initsound();
    initmusic();
    playmusic();
}

void Sound::initsound()
{
    soundb = true;
    sWin = loadaudio("./wav/Win.wav");
    sLose = loadaudio("./wav/Lose.wav");
    sError = loadaudio("./wav/Error.wav");
    sLeft = loadaudio("./wav/Left.wav");
    sRight = loadaudio("./wav/Right.wav");
    sFlag = loadaudio("./wav/Flag.wav");
    sNew = loadaudio("./wav/New.wav");
    sSolve = loadaudio("./wav/Solve.wav");
}

void Sound::initmusic()
{
    musicb = true;
    sMusic[0] = loadaudio("./wav/music1.mid"," type sequencer");
    sMusic[1] = loadaudio("./wav/music2.mid"," type sequencer");
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
            musici = (musici + 1) % 2;
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

                musictime += 5;
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
