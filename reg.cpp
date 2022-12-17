class Reg
{

public:

    HKEY regkey;
    DWORD tp = REG_DWORD;
    DWORD cb = sizeof(DWORD);

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
    RegCreateKeyEx(HKEY_CURRENT_USER,"SoftWare\\MineSweeperTetris",0,NULL,0,KEY_ALL_ACCESS,NULL,&regkey,NULL);
}

void Reg::closereg()
{
    RegCloseKey(regkey);
}

void Reg::setreg(const char* name, long value)
{
    RegSetValueEx(regkey,name,0,tp,(LPBYTE)&value,cb);
}

void Reg::getreg(const char* name, long *value)
{
    long temp;
    if (RegQueryValueEx(regkey,name,NULL,&tp,(LPBYTE)&temp,&cb) == ERROR_SUCCESS)
    {
        *value = temp;
    }
}