#include "sound.h"
#include <stdlib.h>

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
            sprintf(sPath, "./data/wav/%s.wav", sSounds[id]);
            sSound[id] = LoadAudio(sPath, "");
        }
    }
}

void Sound::loadmusic()
{
    MCIERROR ret = mciSendString("open new type sequencer alias miditest", NULL, 0, NULL);
    mciSendString("close miditest", NULL, 0, NULL);
    if (ret != 0)
    {
        char sPath[MAX_PATH];
        nummusic = 0;
        for (long k = 0; ; k++)
        {
            if (IsWin())
            {
                sprintf(sPath, "./data/mid/music%ld.mid", k + 1);
                if (IsFile(sPath))
                {
                    unsigned long* sMusic_ = (unsigned long*)realloc(sMusic, (nummusic + 1) * sizeof(*sMusic));
                    if (sMusic_ == NULL)
                    {
                        break;
                    }
                    sMusic = sMusic_;
                    painttitles = sPath;
                    painttitleb = 2;
                    sMusic[nummusic] = LoadAudio(sPath, " type sequencer");
                    nummusic++;
                }
                else
                {
                    break;
                }
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
        if (IsWin() && nummusic > 0)
        {
            if (musici == musici0 || nummusic == 1)
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
            SetAudioPos(sMusic[musici], 0);
        }
        else
        {
            musici = musici0;
            musictime = 0;
        }
    }
}

void Sound::checkmusic()
{
    if (musicb && musici >= 0 && musici < nummusic)
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
    else if (musici >= 0 && musici < nummusic)
    {
        StopAudio(sMusic[musici]);
    }
    if (soundb)
    {
        playsound(sLeft);
    }
}
