#pragma once
#include "disp.h"

class Lan
{

public:

    static const int maxcap = 10000;
    static const int maxcapp = 1000;

    const char* lanshort[30] = {"arabic", "bulgarian", "czech", "danish", "german", "greek", "english", "spanish", "latam", "finnish", "french", "hungarian", "indonesian", "italian", "japanese", "koreana", "dutch", "norwegian", "polish", "portuguese", "brazilian", "romanian", "russian", "swedish", "thai", "turkish", "ukrainian", "vietnamese", "schinese", "tchinese"};
    const long lanshortid[30] = {1, 2, 5, 6, 7, 8, 9, 10, 22538, 11, 12, 14, 33, 16, 17, 18, 19, 20, 21, 22, 1046, 24, 25, 29, 30, 31, 34, 1066, 2052, 1028};

    short int* data = nullptr;
    short int* landata = nullptr;
    short int** landatap= nullptr;

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
