#pragma once
#include "disp.h"

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
