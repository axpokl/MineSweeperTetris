#include "lan.h"

Lan::Lan()
{
    data = (short int*)calloc(maxcap, sizeof(*data));
    landata = (short int*)calloc(maxcap, sizeof(*landata));
    landatap = (short int**)calloc(maxcapp, sizeof(*landatap));
    initlan(getsyslan());
}

const char* Lan::getsyslan()
{
    const char* lansys = lanshort[6];
    long lansysid = GetUserDefaultUILanguage();
    for (long k = 0; k < 30; k++)
    {
        if (lanshortid[k] == lansysid)
        {
            lansys = lanshort[k];
        }
    }
    return lansys;
}

void Lan::initlan(const char* lan)
{
    char path[100];
    strcpy(&path[0],"./data/lan/");
    strcat(&path[0],lan);
    strcat(&path[0],".txt");
    DWORD startTime = GetTickCount();
    HANDLE hFile;
    do
    {
        hFile = CreateFile(path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        if (hFile == INVALID_HANDLE_VALUE)
            Sleep(100);
    }
    while (hFile == INVALID_HANDLE_VALUE && (GetTickCount() - startTime) < 3000);
    if (hFile != INVALID_HANDLE_VALUE)
    {
        DWORD bytesRead;
        ReadFile(hFile, data, maxcap * sizeof(short), &bytesRead, NULL);
        CloseHandle(hFile);
    }
    else
    {
        MessageBoxA(NULL, "Failed to load language file", "Error", MB_ICONERROR);
        ExitProcess(1);
    }
    int sequenceLength = 8;
    for (unsigned long i = 0; data[i] != 0 && i < (maxcap * sizeof(short)) / sizeof(short) - sequenceLength; ++i)
    {
        bool match = true;
        for (int j = 0; j < sequenceLength; ++j)
        {
            if (data[i + j] != 'x')
            {
                match = false;
                break;
            }
        }
        if (match)
        {
            for (int j = 0; j < sequenceLength; ++j)
            {
                data[i + j] = version[j];
            }
            i += sequenceLength - 1;
        }
    }
    long n = 0;
    short int i = 4;
    short int i_ = 4;
    short int j = 1;
    short int j_ = 1;
    landata[0] = -1;
    landata[1] = -1;
    landata[2] = 0;
    landata[3] = 0;
    for (j = 1; data[j] != 0; j++)
    {
        landata[i] = data[j];
        if (data[j] == 13)
        {
            landata[i_ - 2] = j - j_;
            landatap[n] = &landata[i_];
            landata[i] = 0;
            i++;
            landata[i] = -1;
            i++;
            landata[i] = -1;
            i++;
            landata[i] = 0;
            i++;
            n++;
        }
        if (data[j] == 10)
        {
            landata[i] = 0;
            i_ = i + 1;
            j_ = j + 1;
        }
        i++;
    }
    landata[i_ - 2] = j - j_;
    landatap[n] = &landata[i_];
    landata[i] = 0;
}

short int* Lan::getlan(long id)
{
    return landatap[id];
}
