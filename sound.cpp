class Sound
{

public:

    static const long musici0 = -256;
    static const long maxsound = 8;
    static const long maxmusic = 100;

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

    long nummusic = 0;
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
    painttitles = NULL;
}

void Sound::loadsound()
{
    char sPath[MAX_PATH];
    if (IsWin())
    {
        for (long id = 0; id < maxsound; id++)
        {
            sprintf(sPath, "./wav/%s.wav", sSounds[id]);
            sSound[id] = LoadAudio(sPath, "");
        }
    }
}

void Sound::loadmusic()
{
    char sPath[MAX_PATH];
    nummusic = maxmusic;
    for (long k = 0; k < maxmusic; k++)
    {
        if (IsWin())
        {
            sprintf(sPath, "./mid/music%d.mid", k + 1);
            if (IsFile(sPath))
            {
                painttitles = sPath;
                painttitleb = 2;
                sMusic[k] = LoadAudio(sPath, " type sequencer");
                nummusic = k;
            }
            else
            {
                break;
            }
        }
    }
}

void Sound::playsound(long id)
{
    if (IsWin() && soundb)
    {
        SetAudioPos(sSound[id], 0);
    }
}

void Sound::switchsound()
{
    soundb = !soundb;
    if (IsWin() && soundb)
    {
        playsound(sLeft);
    }
}

void Sound::playmusic()
{
    if (musicb)
    {
        if (IsWin())
        {
            if (musici == musici0)
            {
                musici = 0;
            }
            else
            {
                long musici_ = rand() % (nummusic - 1);
                if (musici_ >= musici)
                {
                    musici_++;
                }
                musici = musici_;
            }
            musictime = GetTimeR();
        }
        else
        {
            musici = musici0;
            musictime = 0;
        }
        SetAudioPos(sMusic[musici], 0);
    }
}

void Sound::checkmusic()
{
    if (musicb)
    {
        if (GetTimeR() > musictime)
        {
            if (GetAudioPos(sMusic[musici]) < GetAudioLen(sMusic[musici]))
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
        StopAudio(sMusic[musici]);
    }
    if (soundb)
    {
        playsound(sLeft);
    }
}
