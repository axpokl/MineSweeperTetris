#include "sound.h"

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
        nummusic = maxmusic;
        for (long k = 0; k < maxmusic; k++)
        {
            if (IsWin())
            {
                sprintf(sPath, "./data/mid/music%ld.mid", k + 1);
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
