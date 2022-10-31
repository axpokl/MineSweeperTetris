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

    void initsound();
    void playsound(long id);

};

void Sound::initsound()
{
    soundb = true;
    musicb = true;
    sWin = loadaudio("./wav/Win.wav");
    sLose = loadaudio("./wav/Lose.wav");
    sError = loadaudio("./wav/Error.wav");
    sLeft = loadaudio("./wav/Left.wav");
    sRight = loadaudio("./wav/Right.wav");
    sFlag = loadaudio("./wav/Flag.wav");
    sNew = loadaudio("./wav/New.wav");
    sSolve = loadaudio("./wav/Solve.wav");
}

void Sound::playsound(long id)
{
    setaudiopos(id, 0);
}
