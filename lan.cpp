class Lan
{

public:

    const char* LAN_FONT = "Consolas";
    const char* LAN_TITLE = "MineSweeper Tetris";
    const char* LAN_RUNNING = "MineSweeper Tetris is already running!";
    const char* LAN_STEAM_LAUNCH = "Please launch MineSwepper Tetris from Steam!";
    const char* LAN_STEAM_FAIL = "Steam initialize failed!";
    const char* LAN_STEAM_Status_FAIL = "Steam current user status load failed!";
    const char* LAN_ABOUT_TITLE = "About";
    const char* LAN_ABOUT_NAME = "MineSweeper Tetris (32-bit)";
    const char* LAN_ABOUT_VERSION = "Version 0.1 dev (Steam)";
    const char* LAN_ABOUT_AUTHOR = "Made by ax_pokl";
    const char* LAN_ABOUT_LICENSE = "Licensed under GPL-3.0";

    Lan();
    void initlan();

};

Lan::Lan()
{
    initlan();
}

void Lan::initlan()
{
}