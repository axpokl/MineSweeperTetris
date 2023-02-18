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

Reg::Reg()
{
    openreg();
}

Reg::~Reg()
{
    closereg();
}

void Reg::openreg()
{
    RegCreateKeyEx(HKEY_CURRENT_USER, "SoftWare\\MineSweeperTetris\\20221219", 0, NULL, 0, KEY_ALL_ACCESS, NULL, &regkey, NULL);
    RegCreateKeyEx(HKEY_CURRENT_USER, "SoftWare\\MineSweeperTetris\\20221219\\board", 0, NULL, 0, KEY_ALL_ACCESS, NULL, &regkey_, NULL);
}

void Reg::closereg()
{
    RegCloseKey(regkey);
    RegCloseKey(regkey_);
}

void Reg::setreg(HKEY key, const char* name, long value)
{
    RegSetValueEx(key, name, 0, REG_DWORD, (LPBYTE) &value, sizeof(DWORD));
}

void Reg::getreg(HKEY key, const char* name, long* value)
{
    long temp;
    cb = sizeof(DWORD);
    if (RegQueryValueEx(key, name, NULL, &tp, (LPBYTE) &temp, &cb) == ERROR_SUCCESS)
    {
        *value = temp;
    }
}

void Reg::setreg_(HKEY key, const char* name, char* value)
{
    RegSetValueEx(key, name, 0, REG_BINARY, (LPBYTE)value, maxbuf);
}

void Reg::getreg_(HKEY key, const char* name, char* value)
{
    char temp[maxbuf];
    DWORD cb = maxbuf;
    if (RegQueryValueEx(key, name, NULL, &tp, (LPBYTE)temp, &cb) == ERROR_SUCCESS)
    {
        memcpy(value, temp, maxbuf);
    }
}