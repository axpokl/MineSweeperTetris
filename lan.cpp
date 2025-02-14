class Lan
{

public:

    const char* lanshort[29] = {"arabic", "bulgarian", "czech", "danish", "german", "greek", "english", "spanish", "latam", "finnish", "french", "hungarian", "italian", "japanese", "koreana", "dutch", "norwegian", "polish", "portuguese", "brazilian", "romanian", "russian", "swedish", "thai", "turkish", "ukrainian", "vietnamese", "schinese", "tchinese"};
    const long lanshortid[29] = {1, 2, 5, 6, 7, 8, 9, 10, 22538, 11, 12, 14, 16, 17, 18, 19, 20, 21, 22, 1046, 24, 25, 29, 30, 31, 34, 1066, 2052, 1028};

    short int data[10000];
    short int landata[10000];
    short int* landatap[1000];

    long LAN_TITLE = 0;
    long LAN_RUNNING = 1;
    long LAN_STEAM_LAUNCH = 2;
    long LAN_STEAM_FAIL = 3;
    long LAN_STEAM_Status = 4;
    long LAN_ABOUT_NAME = 5;
    long LAN_ABOUT_VERSION = 6;
    long LAN_ABOUT_AUTHOR = 7;
    long LAN_ABOUT_LICENSE = 8;
    long LAN_ABOUT_OK = 9;
    long LAN_LOAD_STEAM = 10;
    long LAN_LOAD_AUDIO = 11;
    long LAN_LOAD_BOARD = 12;
    long LAN_LOAD_GRAPH = 13;
    long LAN_LOAD_WINDOW = 14;
    long LAN_HELP = 15;
    long LAN_SET = LAN_HELP + 20;
    long LAN_TUT_ = LAN_SET + 23;
    long LAN_TUT = LAN_TUT_ + 1;
    long LAN_MODE = LAN_TUT + 15;
    long LAN_TUT_QUIT = LAN_MODE + 5;
    long LAN_HELP_MENU = LAN_TUT_QUIT + 3;
    long LAN_HELP_TITLE = LAN_HELP_MENU + 20;

    Lan();
    const char* getsyslan();
    void initlan(const char* lan);
    short int* getlan(long id);

};

Lan::Lan()
{
    initlan(getsyslan());
}

const char* Lan::getsyslan()
{
    const char* lansys = lanshort[6];
    long lansysid = GetUserDefaultUILanguage();
    for (long k = 0; k < 29; k++)
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
        ReadFile(hFile, data, sizeof(data), &bytesRead, NULL);
        CloseHandle(hFile);
    }
    else
    {
        MessageBoxA(NULL, "Failed to load language file", "Error", MB_ICONERROR);
        ExitProcess(1);
    }
    int sequenceLength = 8;
    for (unsigned long i = 0; data[i] != 0 && i < sizeof(data) / sizeof(data[0]) - sequenceLength; ++i)
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
