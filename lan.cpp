class Lan
{

public:

/*
    const char* LAN_TITLE = "MineSweeper Tetris";
    const char* LAN_RUNNING = "MineSweeper Tetris is already running!";
    const char* LAN_STEAM_LAUNCH = "Please launch MineSwepper Tetris from Steam!";
    const char* LAN_STEAM_FAIL = "Steam initialize failed!";
    const char* LAN_STEAM_Status = "Steam current user status load failed!";
    const char* LAN_ABOUT_NAME = "MineSweeper Tetris (32-bit)";
    const char* LAN_ABOUT_VERSION = "Version 0.1 dev (Steam)";
    const char* LAN_ABOUT_AUTHOR = "Made by ax_pokl";
    const char* LAN_ABOUT_LICENSE = "Licensed under GPL-3.0";
*/

    const char* lanshort[29] = {"arabic", "bulgarian", "czech", "danish", "german", "greek", "english", "spanish", "latam", "finnish", "french", "hungarian", "italian", "japanese", "koreana", "dutch", "norwegian", "polish", "portuguese", "brazilian", "romanian", "russian", "swedish", "thai", "turkish", "ukrainian", "vietnamese", "schinese", "tchinese"};
    const long lanshortid[29] = {1, 2, 5, 6, 7, 8, 9, 10, 22538, 11, 12, 14, 16, 17, 18, 19, 20, 21, 22, 1046, 24, 25, 29, 30, 31, 34, 1066, 2052, 1028};

    short int data[10000];
    short int* datap[100];

    long LAN_TITLE_W = 0;
    long LAN_RUNNING_W = 1;
    long LAN_STEAM_LAUNCH_W = 2;
    long LAN_STEAM_FAIL_W = 3;
    long LAN_STEAM_Status_W = 4;
    long LAN_ABOUT_NAME_W = 5;
    long LAN_ABOUT_VERSION_W = 6;
    long LAN_ABOUT_AUTHOR_W = 7;
    long LAN_ABOUT_LICENSE_W = 8;

    Lan();
    const char* getlan();
    void initlan(const char* lan);

};

Lan::Lan()
{
    initlan(getlan());
}

const char* Lan::getlan()
{
    const char* lansys = lanshort[6];
    long lansysid = GetUserDefaultUILanguage();
    printf("%d ", lansysid);
    for (long k = 0; k < 29; k++)
    {
        if (lanshortid[k] == lansysid)
        {
            lansys = lanshort[k];
        }
    }
    printf(lansys);
    return lansys;
}

void Lan::initlan(const char* lan)
{
    char path[100];
    strcpy(&path[0],"lan\\");
    strcat(&path[0],lan);
    strcat(&path[0],".txt");
    FILE *f = fopen(&path[0], "rb");
    fread(&data[1],1,sizeof(data),f);
    fclose(f);
    long n = 0;
    short int k_ = 0;
    short int k = 2;
    data[0] = 0;
    data[1] = 0;
    datap[n] = &data[k];
    for (k = 2; data[k] != 0; k++)
    {
        if (data[k] == 13)
        {
            data[k] = 0;
            data[k_] = k - k_ - 2;
            k_ = k;
        }
        if (data[k] == 10)
        {
            data[k] = 0;
            n++;
            datap[n] = &data[k+1];
        }
    }
    data[k_] = k_ - k - 2;
    k_ = k;
}