class Reg
{

public:

    HKEY regkey;

    Reg();
    ~Reg();
    void openreg();
    void closereg();
    void setreg(const char* name, long value);
    void getreg(const char* name, long *value);

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
    RegCreateKeyEx(HKEY_CURRENT_USER,"SoftWare\\MineSweeperTetris\\20221219",0,NULL,0,KEY_ALL_ACCESS,NULL,&regkey,NULL);
}

void Reg::closereg()
{
    RegCloseKey(regkey);
}

void Reg::setreg(const char* name, long value)
{
    DWORD tp = REG_DWORD;
    DWORD cb = sizeof(DWORD);
    RegSetValueEx(regkey,name,0,tp,(LPBYTE)&value,cb);
}

void Reg::getreg(const char* name, long *value)
{
    long temp;
    DWORD tp = REG_DWORD;
    DWORD cb = sizeof(DWORD);
    if (RegQueryValueEx(regkey,name,NULL,&tp,(LPBYTE)&temp,&cb) == ERROR_SUCCESS)
    {
        *value = temp;
    }
}