#pragma once
#include "disp.h"

class Reg
{

public:

    static const long maxbuf = 16384;

    HKEY regkey;
    HKEY regkey_;
    DWORD tp;
    DWORD cb;

    Reg();
    ~Reg();
    void openreg();
    void closereg();
    void setreg(HKEY key, const char* name, long value);
    void getreg(HKEY key, const char* name, long* value);
    void setreg_(HKEY key, const char* name, char* value);
    void getreg_(HKEY key, const char* name, char* value);

};