#include<windows.h>
#include<time.h>
#include<math.h>
#include<wingdi.h>
#include<gdiplus.h>

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif
#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

typedef struct
{
    HGDIOBJ Handle;
    HDC DC;
    unsigned long Width;
    unsigned long Height;
    unsigned long Color;
} bitmap;
typedef bitmap* pbitmap;

const byte TransParent = 1;

const byte k_lmouse = 1;
const byte k_rmouse = 2;
const byte k_tab = 9;
const byte k_enter = 13;
const byte k_esc = 27;
const byte k_space = 32;
const byte k_pgup = 33;
const byte k_pgdn = 34;
const byte k_left = 37;
const byte k_up = 38;
const byte k_right = 39;
const byte k_down = 40;
const byte k_0 = 48;
const byte k_1 = 49;
const byte k_2 = 50;
const byte k_3 = 51;
const byte k_4 = 52;
const byte k_5 = 53;
const byte k_6 = 54;
const byte k_7 = 55;
const byte k_8 = 56;
const byte k_9 = 57;
const byte k_a = 65;
const byte k_b = 66;
const byte k_c = 67;
const byte k_d = 68;
const byte k_e = 69;
const byte k_f = 70;
const byte k_g = 71;
const byte k_h = 72;
const byte k_i = 73;
const byte k_j = 74;
const byte k_k = 75;
const byte k_l = 76;
const byte k_m = 77;
const byte k_n = 78;
const byte k_o = 79;
const byte k_p = 80;
const byte k_q = 81;
const byte k_r = 82;
const byte k_s = 83;
const byte k_t = 84;
const byte k_u = 85;
const byte k_v = 86;
const byte k_w = 87;
const byte k_x = 88;
const byte k_y = 89;
const byte k_z = 90;
const byte k_add = 107;
const byte k_sub = 109;
const byte k_f1 = 112;
const byte k_f2 = 113;
const byte k_f3 = 114;
const byte k_f4 = 115;
const byte k_f5 = 116;
const byte k_f6 = 117;
const byte k_f7 = 118;
const byte k_f8 = 119;
const byte k_f9 = 120;
const byte k_f10 = 121;
const byte k_f11 = 122;
const byte k_f12 = 123;
const byte k_prd = 188;
const byte k_dot = 190;

//const int MAXCHAR = 0x100;
const int BUFFSIZE = 0x1000;

const int FONTWIDTHDEFAULT = 10;
const int FONTHEIGHTDEFAULT = 20;

const unsigned long _mdn[3] = { MOUSEEVENTF_LEFTDOWN, MOUSEEVENTF_RIGHTDOWN, MOUSEEVENTF_MIDDLEDOWN };
const unsigned long _mup[3] = { MOUSEEVENTF_LEFTUP, MOUSEEVENTF_RIGHTUP, MOUSEEVENTF_MIDDLEUP };
const unsigned long _bdn[3] = { WM_LBUTTONDOWN, WM_MBUTTONDOWN, WM_RBUTTONDOWN };
const unsigned long _bup[3] = { WM_LBUTTONUP, WM_MBUTTONUP, WM_RBUTTONUP };
const int _mswinmax = 0x1000;
const int _msusrmax = 0x1000;
const int _mscntmax = 0x1000;
const char* DEFAULTCLASS = "DisplayClass";

const GUID GDIImageFormatBMP = {0x557CF400, 0x1A04, 0x11D3, {0x9A, 0x73, 0x00, 0x00, 0xF8, 0x1E, 0xF3, 0x2E}};
const GUID GDIImageFormatJPG = {0x557CF401, 0x1A04, 0x11D3, {0x9A, 0x73, 0x00, 0x00, 0xF8, 0x1E, 0xF3, 0x2E}};
const GUID GDIImageFormatGIF = {0x557CF402, 0x1A04, 0x11D3, {0x9A, 0x73, 0x00, 0x00, 0xF8, 0x1E, 0xF3, 0x2E}};
const GUID GDIImageFormatEMF = {0x557CF403, 0x1A04, 0x11D3, {0x9A, 0x73, 0x00, 0x00, 0xF8, 0x1E, 0xF3, 0x2E}};
const GUID GDIImageFormatWMF = {0x557CF404, 0x1A04, 0x11D3, {0x9A, 0x73, 0x00, 0x00, 0xF8, 0x1E, 0xF3, 0x2E}};
const GUID GDIImageFormatTIF = {0x557CF405, 0x1A04, 0x11D3, {0x9A, 0x73, 0x00, 0x00, 0xF8, 0x1E, 0xF3, 0x2E}};
const GUID GDIImageFormatPNG = {0x557CF406, 0x1A04, 0x11D3, {0x9A, 0x73, 0x00, 0x00, 0xF8, 0x1E, 0xF3, 0x2E}};
const GUID GDIImageFormatICO = {0x557CF407, 0x1A04, 0x11D3, {0x9A, 0x73, 0x00, 0x00, 0xF8, 0x1E, 0xF3, 0x2E}};

const int DELAYTIMEDEFAULT=1;
const int DELAYTIMEMIN=1;

long _w = 0, _h = 0, _x = 0, _y = 0;
unsigned long _cbg = 0, _cfg = 0;
unsigned long _style = 0;
HWND _hw = NULL;
HDC _dc = NULL;

HINSTANCE MainInstance = NULL;
WNDCLASSW _wc = {0};
ATOM _wca = 0;
LPCWSTR _class = L"DisplayClass";

MSG _ms = {0};
MSG _mst = {0};
bitmap _main = {0};
pbitmap _pmain = NULL;
bitmap _mscr = {0};
pbitmap _pmscr = NULL;

unsigned long _bufz = 0;
unsigned char _bufcb = 0, _bufcg = 0, _bufcr = 0;

LARGE_INTEGER _tbegin = {0};
LARGE_INTEGER _tfreq = {0}, _tcount = {0};
bool _winb = false;
void (*_draw)() = NULL;

HPEN _pe = NULL;
unsigned long _pec = TransParent;
unsigned long _pew = 1;
HBRUSH _br = NULL;
unsigned long _brc = TransParent;

long _fx = 0, _fy = 0;
unsigned long _fw = 0, _fh = 0, _fwg = 0;
unsigned long _flt = 0, _fud = 0, _fsk = 0, _fcs = 0;
char _ffn[256] = {0};
HFONT _fns = NULL;
SIZE _strz = {0};
TEXTMETRIC _tm = {0};

MSG _mswin[0x1000] = {0};
unsigned long _mswini = 0;
unsigned long _mswinj = 0;
MSG _msusr[0x1000] = {0};
unsigned long _msusri = 1;
unsigned long _msi = 1;
double _mscnt[0x1000] = {0};
unsigned long _mscnti = 0;
unsigned long _mscntj = 0;

Gdiplus::GdiplusStartupInput _GdiStart = {0};
ULONG_PTR _GdiToken = 0;
Gdiplus::GpGraphics* _GdiGraph = NULL;
Gdiplus::GpImage* _GdiImage = NULL;
Gdiplus::GpBitmap* _GdiBitmap = NULL;
WCHAR _GdiWideChar[MAXCHAR] = {0};

unsigned long _cid = 0;

void WinCreateMain();
LRESULT CALLBACK WndProc(HWND hW, UINT uM, WPARAM wP, LPARAM lP);
BOOL CALLBACK Monitorenumproc(HMONITOR hmon, HDC hdc, LPRECT lprect, LPARAM pdata);
ATOM WinRegister();
void WinCreate();
void WinInit();

void FreshFPS();
void AddFPS();

void CreateWin(long x, long y, unsigned long w, unsigned long h, unsigned long cfg, unsigned long cbg, unsigned long style, const char* winclass);
void CreateWin(unsigned long w, unsigned long h, unsigned long cfg, unsigned long cbg, unsigned long style, const char* winclass);
void CreateWin(unsigned long w, unsigned long h, unsigned long cfg, unsigned long cbg, unsigned long style);
void CreateWin(unsigned long w, unsigned long h, unsigned long cfg, unsigned long cbg);
void CreateWin(unsigned long w, unsigned long h, unsigned long c);
void CreateWin(unsigned long w, unsigned long h);
void CreateWin(unsigned long cbg);
void CreateWin();
void FreshWin();
void CloseWin();
bool IsWin();
double GetTimeR();
unsigned long GetTime();
void SetTitle(const char* s);
void SetTitleW(const short int* s);
char* GetTitle();
short int* GetTitleW();
void SetSize(long x, long y, unsigned long w, unsigned long h);
void SetSize(unsigned long w, unsigned long h);
unsigned long GetWidth();
unsigned long GetHeight();
unsigned long GetSize();
long GetScrWidth();
long GetScrHeight();
unsigned long GetScrSize();
double GetScrCapsX();
double GetScrCapsY();
long GetBorderTitle();
long GetBorderWidth();
long GetBorderHeight();
unsigned long GetBorderSize();
void SetPos(long x, long y);
long GetPosX();
long GetPosY();
unsigned long GetPos();
pbitmap GetWin();
pbitmap GetScr();
HGDIOBJ GetHwnd(pbitmap b);
HWND GetHwnd();
HDC GetDraw(pbitmap b);
HDC GetDraw();

unsigned long GetBGColor();
void SetBGColor(unsigned long c);
unsigned long GetFGColor();
void SetFGColor(unsigned long c);
void SetPenWidth(unsigned long pew);
void SetPenColor(pbitmap b, unsigned long c);
void SetBrushColor(pbitmap b, unsigned long c);
void SetPenColor(unsigned long c);
void SetBrushColor(unsigned long c);
unsigned char GetRed(unsigned long c);
unsigned char GetGreen(unsigned long c);
unsigned char GetBlue(unsigned long c);
unsigned char GetAlpha(unsigned long c);
unsigned long GetRGBA(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
unsigned long GetRGB(unsigned char r, unsigned char g, unsigned char b);

void SetFont(pbitmap b);
void SetFont();
void SetFontWidth(unsigned long w);
void SetFontHeight(unsigned long h);
void SetFontSize(unsigned long w, unsigned long h);
void SetFontWeight(unsigned long wg);
void SetFontLtalic(unsigned long lt);
void SetFontUnderLine(unsigned long ud);
void SetFontStrikeOut(unsigned long sk);
void SetFontCharSet(unsigned long cs);
void SetFontName(const char* s);
void GetStringSize(const char* s);
unsigned long GetStringWidth(const char* s);
unsigned long GetStringHeight(const char* s);

void InitTextXY(pbitmap* b, const short int** s, unsigned long* cfg, unsigned long* cbg);
void InitTextXY(pbitmap* b, const char** s, unsigned long* cfg, unsigned long* cbg);
void DrawTextXY(pbitmap b, const short int* s, long x, long y, unsigned long w, unsigned long h, unsigned long cfg, unsigned long cbg, unsigned long format);
void DrawTextXY(pbitmap b, const short int* s, long x, long y, unsigned long w, unsigned long h, unsigned long cfg, unsigned long cbg);
void DrawTextXY(pbitmap b, const char* s, long x, long y, unsigned long w, unsigned long h, unsigned long cfg, unsigned long cbg);
void DrawTextXY(pbitmap b, const char* s, long x, long y, unsigned long cfg, unsigned long cbg);
void DrawTextXY(pbitmap b, const char* s, long x, long y, unsigned long cfg);
void DrawTextXY(const char* s, long x, long y, unsigned long cfg, unsigned long cbg);
void DrawTextXY(const char* s, long x, long y, unsigned long cfg);
void DrawTextXY(const char* s, long x, unsigned long y);
void DrawText(const char* s, unsigned long cfg, unsigned long cbg);
void DrawText(const char* s, unsigned long cfg);
void DrawText(const char* s);
void DrawTextlnXY(const char* s, long x, long y, unsigned long cfg, unsigned long cbg);
void DrawTextlnXY(const char* s, long x, long y, unsigned long cfg);
void DrawTextlnXY(const char* s, long x, unsigned long y);
void DrawTextln(const char* s, unsigned long cfg, unsigned long cbg);
void DrawTextln(const char* s, unsigned long cfg);
void DrawTextln(const char* s);
void DrawTextln();
void DrawTextXYw(pbitmap b, const char* s, long x, long y, unsigned long cfg, unsigned long cbg);
void DrawTextXYw(pbitmap b, const char* s, long x, long y, unsigned long cfg);
void DrawTextXYw(const char* s, long x, long y, unsigned long cfg, unsigned long cbg);
void DrawTextXYw(const char* s, long x, long y, unsigned long cfg);
void DrawTextXYw(const char* s, long x, unsigned long y);
void DrawTextw(const char* s, unsigned long cfg, unsigned long cbg);
void DrawTextw(const char* s, unsigned long cfg);
void DrawTextw(const char* s);
void DrawTextlnXYw(const char* s, long x, long y, unsigned long cfg, unsigned long cbg);
void DrawTextlnXYw(const char* s, long x, long y, unsigned long cfg);
void DrawTextlnXYw(const char* s, long x, unsigned long y);
void DrawTextlnw(const char* s, unsigned long cfg, unsigned long cbg);
void DrawTextlnw(const char* s, unsigned long cfg);
void DrawTextlnw(const char* s);

unsigned long GetPixel(pbitmap b, unsigned long x, unsigned long y);
unsigned long GetPixel(unsigned long x, unsigned long y);
void SetPixel(pbitmap b, unsigned long x, unsigned long y, unsigned long c);
void SetPixel(unsigned long x, unsigned long y, unsigned long c);
void SetPixel(unsigned long x, unsigned long y);
void Line(pbitmap b, long x, long y, long w, long h, unsigned long c);
void Line(long x, long y, long w, long h, unsigned long c);
void Bar(pbitmap b, long x, long y, long w, long h, unsigned long cfg, unsigned long cbg);
void Bar(pbitmap b, long x, long y, long w, long h, unsigned long c);
void Bar(long x, long y, long w, long h, unsigned long cfg, unsigned long cbg);
void Bar(long x, long y, long w, long h, unsigned long c);
void Bar(long x, long y, long w, long h);
void Clear(pbitmap b, unsigned long c);
void Clear(pbitmap b);
void Clear(unsigned long c);
void Clear();

pbitmap CreateBMP(pbitmap b, unsigned long w, unsigned long h, unsigned long c);
pbitmap CreateBMP(pbitmap b);
pbitmap CreateBMP(unsigned long w, unsigned long h, unsigned long c);
pbitmap CreateBMP(unsigned long w, unsigned long h);
pbitmap CreateBMP();
void ReleaseBMP(pbitmap b);
void ReleaseBMP();
pbitmap LoadBMP(const char* s, unsigned long c);
pbitmap LoadBMP(const char* s);
void SaveBMP(pbitmap b, const char* s);
void DrawBMP(pbitmap bs, pbitmap bd, unsigned long xs, unsigned long ys, unsigned long ws, unsigned long hs, unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd, unsigned long c);
void DrawBMP(pbitmap bs, pbitmap bd, unsigned long xs, unsigned long ys, unsigned long ws, unsigned long hs, unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd);
void DrawBMP(pbitmap bs, pbitmap bd, unsigned long xs, unsigned long ys, unsigned long xd, unsigned long yd, unsigned long w, unsigned long h, unsigned long c);
void DrawBMP(pbitmap bs, pbitmap bd, unsigned long xs, unsigned long ys, unsigned long xd, unsigned long yd, unsigned long w, unsigned long h);
void DrawBMP(pbitmap bs, pbitmap bd, unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd, unsigned long c);
void DrawBMP(pbitmap bs, pbitmap bd, unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd);
void DrawBMP(pbitmap bs, pbitmap bd, unsigned long xd, unsigned long yd, unsigned long c);
void DrawBMP(pbitmap bs, pbitmap bd, unsigned long xd, unsigned long yd);
void DrawBMP(pbitmap bs, pbitmap bd, unsigned long c);
void DrawBMP(pbitmap bs, pbitmap bd);
void DrawBMP(pbitmap bs, unsigned long xs, unsigned long ys, unsigned long ws, unsigned long hs, unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd, unsigned long c);
void DrawBMP(pbitmap bs, unsigned long xs, unsigned long ys, unsigned long ws, unsigned long hs, unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd);
void DrawBMP(pbitmap bs, unsigned long xs, unsigned long ys, unsigned long xd, unsigned long yd, unsigned long w, unsigned long h, unsigned long c);
void DrawBMP(pbitmap bs, unsigned long xs, unsigned long ys, unsigned long xd, unsigned long yd, unsigned long w, unsigned long h);
void DrawBMP(pbitmap bs, unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd, unsigned long c);
void DrawBMP(pbitmap bs, unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd);
void DrawBMP(pbitmap bs, unsigned long xd, unsigned long yd, unsigned long c);
void DrawBMP(pbitmap bs, unsigned long xd, unsigned long yd);
void DrawBMP(pbitmap bs, unsigned long c);
void DrawBMP(pbitmap bs);
void DrawBMP(unsigned long xs, unsigned long ys, unsigned long ws, unsigned long hs, unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd, unsigned long c);
void DrawBMP(unsigned long xs, unsigned long ys, unsigned long ws, unsigned long hs, unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd);
void DrawBMP(unsigned long xs, unsigned long ys, unsigned long xd, unsigned long yd, unsigned long w, unsigned long h, unsigned long c);
void DrawBMP(unsigned long xs, unsigned long ys, unsigned long xd, unsigned long yd, unsigned long w, unsigned long h);
void DrawBMP(unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd, unsigned long c);
void DrawBMP(unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd);
void DrawBMP(unsigned long xd, unsigned long yd, unsigned long c);
void DrawBMP(unsigned long xd, unsigned long yd);
void DrawBMP(unsigned long c);
void DrawBMP();

void SendMsg();
bool CustomMsg();
bool IsNextMsg();
unsigned long GetNextMsg();
unsigned long WaitNextMsg();
bool IsMsg(const unsigned long uM[], unsigned long length);
uint64_t GetMsg(const unsigned long uM[], unsigned long length);
uint64_t WaitMsg(const unsigned long uM[], unsigned long length);
bool IsMsg(unsigned long uM);
uint64_t GetMsg(unsigned long uM);
uint64_t WaitMsg(unsigned long uM);
bool IsKey(unsigned long k);
bool IsKey();
unsigned long GetKey();
unsigned long WaitKey(unsigned long k);
unsigned long WaitKey();
bool IsMouse(unsigned long m);
bool IsMouse();
unsigned long GetMouse();
unsigned long WaitMouse(unsigned long m);
unsigned long WaitMouse();
bool IsMouseLeft();
void WaitMouseLeft();
bool IsMouseMiddle();
void WaitMouseMiddle();
bool IsMouseRight();
void WaitMouseRight();
bool IsMouseWheel();
long GetMouseWheel();
void WaitMouseWheel();
bool IsMouseMove();
unsigned long GetMouseMove();
unsigned long WaitMouseMove();
bool IsDropFile();
char *GetDropFile();
wchar_t *GetDropFileW();
char *WaitDropFile();
long GetMouseAbsX();
long GetMouseAbsY();
long GetMouseWinX();
long GetMouseWinY();
long GetMousePosX();
long GetMousePosY();

unsigned long MsgBoxW(const short int* s, const short int* title, unsigned long i);
unsigned long MsgBox(const char* s, const char* title, unsigned long i);
void MsgBoxW(const short int* s, const short int* title);
void MsgBox(const char* s, const char* title);
void MsgBoxW(const short int* s);
void MsgBox(const char* s);
void Delay(unsigned long t);
void Delay();

unsigned long SendString(const char* s);
unsigned long LoadAudio(const char* s1, const char* s2);
unsigned long LoadAudio(const char* s);
void PlayAudio(unsigned long id, const char* s, bool b);
void PlayAudioDefaultString(unsigned long id, const char* s);
void PlayAudioDefaultBool(unsigned long id, bool b);
void PlayAudioDefault(unsigned long id);
void StopAudio(unsigned long id);
void PauseAudio(unsigned long id);
void ResumeAudio(unsigned long id);
void ReleaseAudio(unsigned long id);
unsigned long GetAudioPos(unsigned long id);
void SetAudioPos(unsigned long id, unsigned long pos, bool b);
void SetAudioPos(unsigned long id, unsigned long pos);
unsigned long GetAudioLen(unsigned long id);

bool IsFile(const char* s);

uint8_t UTF8ToUnicode(uint8_t *utf8, uint32_t *unicode);
uint8_t UnicodeToUTF16(uint32_t unicode, uint16_t *utf16);

void WinCreateMain()
{
    if (_hw)
    {
        ReleaseBMP(_pmscr);
        ReleaseBMP(_pmain);
        _dc = GetDC(_hw);
        _mscr.Handle = _hw;
        _mscr.DC = _dc;
        _mscr.Width = _w;
        _mscr.Height = _h;
        _pmscr = &_mscr;
        _pmain = CreateBMP(_pmscr);
        _pmain->Color = TransParent;
        _main = *_pmain;
        SetFont();
        if (_draw != NULL) _draw();
    }
}

LRESULT CALLBACK WndProc(HWND hW, UINT uM, WPARAM wP, LPARAM lP)
{
    switch (uM)
    {
        case WM_CREATE:
            DragAcceptFiles(hW, TRUE);
            timeBeginPeriod(1);
            break;
        case WM_NCACTIVATE:
            if ((wP & 11) > 0 && IsIconic(hW))
            {
                ShowWindow(hW, SW_SHOW);
                SetForegroundWindow(hW);
            }
            break;
        case WM_SIZE:
            _w = lP % 0x10000;
            _h = lP / 0x10000;
            WinCreateMain();
            if (_draw != NULL) _draw();
            break;
        case WM_MOVE:
            if (_draw != NULL) _draw();
            break;
        case WM_PAINT:
            if (_draw != NULL) _draw();
            break;
        case WM_SETCURSOR:
            if (GetMousePosX() >= 0 && GetMousePosY() >= 0 && GetMousePosX() <= _w && GetMousePosY() <= _h)
                SetCursor(LoadCursor(0, IDC_ARROW));
            break;
        case WM_USER:
            _msusr[_msusri].message = uM;
            _msusr[_msusri].wParam = wP;
            _msusr[_msusri].lParam = lP;
            _msusri++;
            if (_msusri > _msusrmax) _msusri = 1;
            break;
        case WM_CLOSE:
            DestroyWindow(hW);
            break;
        case WM_DESTROY:
            timeEndPeriod(1);
            _hw = 0;
            _dc = 0;
            _winb = false;
            ExitThread(0);
            break;
    }
    LRESULT result = DefWindowProcW(hW, uM, wP, lP);
    return result;
}

BOOL CALLBACK Monitorenumproc(HMONITOR hmon, HDC hdc, LPRECT lprect, LPARAM pdata)
{
    RECT* r =(RECT*)pdata;
    MONITORINFOEX info;
    info.cbSize = sizeof(MONITORINFOEX);
    long posX = GetPosX();
    long posY = GetPosY();
    if (GetMonitorInfo(hmon, &info))
    {
        RECT work = info.rcWork;
        if (posX >= work.left && posX <= work.right && posY >= work.top && posY <= work.bottom)
        {
            *r= work;
            return TRUE;
        }
    }
    return FALSE;
}

ATOM WinRegister()
{
    _wc.style = CS_HREDRAW | CS_VREDRAW;
    _wc.lpfnWndProc = WndProc;
    _wc.cbClsExtra = 0;
    _wc.cbWndExtra = 0;
    _wc.hInstance = MainInstance;
    _wc.hbrBackground = (HBRUSH)CreateSolidBrush(_cbg);
    _wc.lpszMenuName = NULL;
    _wc.lpszClassName = _class;
    return RegisterClassW(&_wc);
}

void WinCreate()
{
    RECT rect = {_x, _y, _x + _w, _y + _h};
    AdjustWindowRect(&rect, _style, FALSE);
    _w = rect.right - rect.left;
    _h = rect.bottom - rect.top;
    _hw = CreateWindowW(_class, NULL, _style, _x, _y, _w, _h, NULL, NULL, MainInstance, NULL);
}

void WinInit()
{
    if (_wca == 0) _wca = WinRegister();
    WinCreate();
    WinCreateMain();
    _winb = true;
    GetTimeR();
    _tbegin = _tcount;
    while (IsWin())
    {
        GetMessage(&_mst, 0, 0, 0);
        if (_mst.message != 0)
        {
            SendMsg();
            _mswini = (_mswini + 1) % _mswinmax;
            _mswin[_mswini] = _mst;
        }
    }
}

void FreshFPS()
{
    while (_mscnti >= _mscntmax) _mscnti = _mscnti - _mscntmax;
    _mscnt[_mscnti] = GetTimeR();
    while (_mscnt[_mscntj] <= _mscnt[_mscnti] - 1)
    {
        _mscntj = _mscntj + 1;
        while (_mscntj >= _mscntmax) _mscntj = _mscntj - _mscntmax;
    }
}
void AddFPS()
{
    _mscnti = _mscnti + 1;
    FreshFPS();
}

void CreateWin(long x, long y, unsigned long w, unsigned long h, unsigned long cfg, unsigned long cbg, unsigned long style, const char* winclass)
{
    wchar_t wstr[MAXCHAR];
    MultiByteToWideChar(CP_UTF8, 0, winclass, -1, wstr, MAXCHAR);
    _class = wstr;
    if (style == 0) style = WS_OVERLAPPEDWINDOW | WS_VISIBLE;
    _w = w;
    _h = h;
    _x = x;
    _y = y;
    _cbg = cbg;
    _cfg = cfg;
    _style = style;
    CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)WinInit, NULL, 0, NULL);
    while (!IsWin()) Sleep(1);
    SetBkMode(_dc, TransParent);
    Clear();
}
void CreateWin(unsigned long w, unsigned long h, unsigned long cfg, unsigned long cbg, unsigned long style, const char* winclass)
{
    CreateWin(max(0, (GetScrWidth() - w) / 2), max(0, (GetScrHeight() - h) / 2), w, h, cfg, cbg, style, winclass);
}
void CreateWin(unsigned long w, unsigned long h, unsigned long cfg, unsigned long cbg, unsigned long style)
{
    CreateWin(w, h, cfg, cbg, style, DEFAULTCLASS);
}
void CreateWin(unsigned long w, unsigned long h, unsigned long cfg, unsigned long cbg)
{
    CreateWin(w, h, cfg, cbg, 0);
}
void CreateWin(unsigned long w, unsigned long h, unsigned long c)
{
    CreateWin(w, h, 0, c);
}
void CreateWin(unsigned long w, unsigned long h)
{
    CreateWin(w, h, 0);
}
void CreateWin(unsigned long cbg)
{
    CreateWin(GetScrWidth() / 2, GetScrHeight() / 2, cbg);
}
void CreateWin()
{
    CreateWin(GetScrWidth() / 2, GetScrHeight() / 2);
}

void FreshWin()
{
    DrawBMP(_pmain, _pmscr);
    AddFPS();
}
void CloseWin()
{
    SendMessage(_hw, WM_CLOSE, 0, 0);
}
bool IsWin()
{
    return _winb;
}


double GetTimeR()
{
    LARGE_INTEGER tfreq, tcount;
    if (QueryPerformanceFrequency(&tfreq)) _tfreq = tfreq;
    if (QueryPerformanceCounter(&tcount)) _tcount = tcount;
    return (double)(tcount.QuadPart - _tbegin.QuadPart) / _tfreq.QuadPart;
}
unsigned long GetTime()
{
    return (unsigned long)(GetTimeR() * 1000);
}

void SetTitle(const char* s)
{
    SetWindowTextA(_hw, s);
}
void SetTitleW(const short int* s)
{
    SetWindowTextW(_hw, (LPCWSTR)s);
}
char* GetTitle()
{
    static char c[MAXCHAR];
    GetWindowTextA(_hw, c, MAXCHAR);
    return c;
}
short int* GetTitleW()
{
    static short int c[MAXCHAR];
    GetWindowTextW(_hw, (LPWSTR)c, MAXCHAR);
    return c;
}
void SetSize(long x, long y, unsigned long w, unsigned long h)
{
    RECT rect;
    rect.left = x;
    rect.top = y;
    rect.right = rect.left + w;
    rect.bottom = rect.top + h;
    AdjustWindowRect(&rect, _style, FALSE);
    MoveWindow(_hw, x, y, rect.right - rect.left, rect.bottom - rect.top, TRUE);
}
void SetSize(unsigned long w, unsigned long h)
{
    SetSize(GetPosX(), GetPosY(), w, h);
}
unsigned long GetWidth()
{
    return _w;
}
unsigned long GetHeight()
{
    return _h;
}
unsigned long GetSize()
{
    return GetWidth() * 0x10000 + GetHeight();
}
long GetScrWidth()
{
    return GetSystemMetrics(SM_CXSCREEN);
}
long GetScrHeight()
{
    return GetSystemMetrics(SM_CYSCREEN);
}
unsigned long GetScrSize()
{
    return GetScrWidth() * 0x10000 + GetScrHeight();
}
double GetScrCapsX()
{
    return 144.0 / GetDeviceCaps(GetDC(GetDesktopWindow()), LOGPIXELSX);
}
double GetScrCapsY()
{
    return 144.0 / GetDeviceCaps(GetDC(GetDesktopWindow()), LOGPIXELSY);
}
long GetBorderTitle()
{
    return GetSystemMetrics(SM_CYCAPTION);
}
long GetBorderWidth()
{
    return (_style & WS_THICKFRAME) ? GetSystemMetrics(SM_CXSIZEFRAME) : GetSystemMetrics(SM_CXFIXEDFRAME);
}
long GetBorderHeight()
{
    return (_style & WS_THICKFRAME) ? GetSystemMetrics(SM_CYSIZEFRAME) : GetSystemMetrics(SM_CYFIXEDFRAME);
}
unsigned long GetBorderSize()
{
    return GetBorderWidth() * 0x10000 + GetBorderHeight();
}
void SetPos(long x, long y)
{
    SetSize(x, y, _w, _h);
}
long GetPosX()
{
    RECT rt = { 0, 0, 0, 0 };
    GetWindowRect(_hw, &rt);
    return rt.left;
}
long GetPosY()
{
    RECT rt = { 0, 0, 0, 0 };
    GetWindowRect(_hw, &rt);
    return rt.top;
}
unsigned long GetPos()
{
    return GetPosX() * 0x10000 + GetPosY();
}
pbitmap GetWin()
{
    return _pmain;
}
pbitmap GetScr()
{
    return _pmscr;
}
HGDIOBJ GetHwnd(pbitmap b)
{
    return b->Handle;
}
HWND GetHwnd()
{
    return _hw;
}
HDC GetDraw(pbitmap b)
{
    return b->DC;
}
HDC GetDraw()
{
    return _dc;
}

unsigned long GetBGColor()
{
    return _cbg;
}
void SetBGColor(unsigned long c)
{
    _cbg = c;
}
unsigned long GetFGColor()
{
    return _cfg;
}
void SetFGColor(unsigned long c)
{
    _cfg = c;
}
void SetPenWidth(unsigned long pew)
{
    _pew = pew;
}
void SetPenColor(pbitmap b, unsigned long c)
{
    if (c != _pec)
    {
        _pec = c;
        DeleteObject(_pe);
        _pe = (c == TransParent) ? (HPEN)GetStockObject(NULL_PEN) : CreatePen(PS_SOLID, _pew, c);
        SelectObject(b->DC, _pe);
    }
}
void SetBrushColor(pbitmap b, unsigned long c)
{
    if (c != _brc)
    {
        _brc = c;
        DeleteObject(_br);
        _br = (c == TransParent) ? (HBRUSH)GetStockObject(NULL_BRUSH) : CreateSolidBrush(c);
        SelectObject(b->DC, _br);
    }
}
void SetPenColor(unsigned long c)
{
    SetPenColor(_pmain, c);
}
void SetBrushColor(unsigned long c)
{
    SetBrushColor(_pmain, c);
}
unsigned char GetRed(unsigned long c)
{
    return (unsigned char)(c >> 0 & 0xFF);
}
unsigned char GetGreen(unsigned long c)
{
    return (unsigned char)(c >> 8 & 0xFF);
}
unsigned char GetBlue(unsigned long c)
{
    return (unsigned char)(c >> 16 & 0xFF);
}
unsigned char GetAlpha(unsigned long c)
{
    return (unsigned char)(c >> 24 & 0xFF);
}
unsigned long GetRGBA(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    return (unsigned long)(a << 24 | b << 16 | g << 8 | r);
}
unsigned long GetRGB(unsigned char r, unsigned char g, unsigned char b)
{
    return GetRGBA(r, g, b, 0);
}

void SetFont(pbitmap b)
{
    DeleteObject((HGDIOBJ)_fns);
    _fns = CreateFont(
               _fh, _fw, 0, 0, _fwg,
               _flt, _fud, _fsk, _fcs,
               OUT_DEFAULT_PRECIS,
               CLIP_DEFAULT_PRECIS,
               DEFAULT_QUALITY,
               DEFAULT_PITCH | FF_DONTCARE,
               _ffn
           );
    SelectObject(b->DC, _fns);
    if (_fh == 0)
    {
        GetTextMetrics(_dc, &_tm);
        _fh = _tm.tmHeight;
    }
}
void SetFont()
{
    SetFont(_pmain);
}
void SetFontWidth(unsigned long w)
{
    _fw = w;
    SetFont();
}
void SetFontHeight(unsigned long h)
{
    _fh = h;
    SetFont();
}
void SetFontSize(unsigned long w, unsigned long h)
{
    _fh = h;
    _fw = w;
    SetFont();
}
void SetFontWeight(unsigned long wg)
{
    _fwg = wg;
    SetFont();
}
void SetFontLtalic(unsigned long lt)
{
    _flt = lt;
    SetFont();
}
void SetFontUnderLine(unsigned long ud)
{
    _fud = ud;
    SetFont();
}
void SetFontStrikeOut(unsigned long sk)
{
    _fsk = sk;
    SetFont();
}
void SetFontCharSet(unsigned long cs)
{
    _fcs = cs;
    SetFont();
}
void SetFontName(const char* s)
{
    strcpy(_ffn, s);
    SetFont();
}
void GetStringSize(const char* s)
{
    GetTextExtentPoint32A(_dc, s, strlen(s), &_strz);
}
unsigned long GetStringWidth(const char* s)
{
    GetStringSize(s);
    return (_strz.cy > 0) ? (unsigned long)(_strz.cx * _fh / _strz.cy) : 0;
}
unsigned long GetStringHeight(const char* s)
{
    GetStringSize(s);
    return (_strz.cy > 0) ? (unsigned long)(_strz.cy * _fh / _strz.cy) : 0;
}

void InitTextXY(pbitmap* b, const short int** s, unsigned long* cfg, unsigned long* cbg)
{
    if (*b == NULL) *b = _pmain;
    if (**s == 0) *s = (const short int*)L" ";
    if (*cfg == 0) *cfg = RGB(255, 255, 255);
    SetTextColor((*b)->DC, *cfg);
    if (*cbg == 0) SetBkMode((*b)->DC, TransParent);
    else
    {
        SetBkColor((*b)->DC, *cbg);
        SetBkMode((*b)->DC, OPAQUE);
    }
}
void InitTextXY(pbitmap* b, const char** s, unsigned long* cfg, unsigned long* cbg)
{
    if (*b == NULL) *b = _pmain;
    if (**s == 0) *s = " ";
    if (*cfg == 0) *cfg = RGB(255, 255, 255);
    SetTextColor((*b)->DC, *cfg);
    if (*cbg == 0) SetBkMode((*b)->DC, TransParent);
    else
    {
        SetBkColor((*b)->DC, *cbg);
        SetBkMode((*b)->DC, OPAQUE);
    }
}
void DrawTextXY(pbitmap b, const short int* s, long x, long y, unsigned long w, unsigned long h, unsigned long cfg, unsigned long cbg, unsigned long format)
{
    RECT lpRect;
    InitTextXY(&b, &s, &cfg, &cbg);
    lpRect.left = x;
    lpRect.top = y;
    lpRect.right = x + w;
    lpRect.bottom = y + h;
    DrawTextW(b->DC, (LPCWSTR)s, wcslen((LPCWSTR)s), &lpRect, format);
    _fx = x + w;
    _fy = y;
}
void DrawTextXY(pbitmap b, const short int* s, long x, long y, unsigned long w, unsigned long h, unsigned long cfg, unsigned long cbg)
{
    RECT lpRect;
    InitTextXY(&b, &s, &cfg, &cbg);
    lpRect.left = x;
    lpRect.top = y;
    lpRect.right = x + w;
    lpRect.bottom = y + h;
    DrawTextW(b->DC, (LPCWSTR)s, wcslen((LPCWSTR)s), &lpRect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
    _fx = x + w;
    _fy = y;
}
void DrawTextXY(pbitmap b, const char* s, long x, long y, unsigned long w, unsigned long h, unsigned long cfg, unsigned long cbg)
{
    RECT lpRect;
    InitTextXY(&b, &s, &cfg, &cbg);
    lpRect.left = x;
    lpRect.top = y;
    lpRect.right = x + w;
    lpRect.bottom = y + h;
    DrawTextA(b->DC, s, strlen(s), &lpRect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
    _fx = x + w;
    _fy = y;
}
void DrawTextXY(pbitmap b, const char* s, long x, long y, unsigned long cfg, unsigned long cbg)
{
    InitTextXY(&b, &s, &cfg, &cbg);
    TextOutA(b->DC, x, y, s, strlen(s));
    _fx = x + GetStringWidth(s);
    _fy = y;
}
void DrawTextXY(pbitmap b, const char* s, long x, long y, unsigned long cfg)
{
    DrawTextXY(b, s, x, y, cfg, 0);
}
void DrawTextXY(const char* s, long x, long y, unsigned long cfg, unsigned long cbg)
{
    DrawTextXY(NULL, s, x, y, cfg, cbg);
}
void DrawTextXY(const char* s, long x, long y, unsigned long cfg)
{
    DrawTextXY(NULL, s, x, y, cfg);
}
void DrawTextXY(const char* s, long x, unsigned long y)
{
    DrawTextXY(s, x, y, 0);
}
void DrawText(const char* s, unsigned long cfg, unsigned long cbg)
{
    DrawTextXY(s, _fx, _fy, cfg, cbg);
}
void DrawText(const char* s, unsigned long cfg)
{
    DrawText(s, cfg, 0);
}
void DrawText(const char* s)
{
    DrawText(s, 0);
}
void DrawTextlnXY(const char* s, long x, long y, unsigned long cfg, unsigned long cbg)
{
    DrawTextXY(s, x, y, cfg, cbg);
    _fx = x;
    _fy = y + GetStringHeight(s);
}
void DrawTextlnXY(const char* s, long x, long y, unsigned long cfg)
{
    DrawTextlnXY(s, x, y, cfg, 0);
}
void DrawTextlnXY(const char* s, long x, unsigned long y)
{
    DrawTextlnXY(s, x, y, 0);
}
void DrawTextln(const char* s, unsigned long cfg, unsigned long cbg)
{
    DrawTextlnXY(s, _fx, _fy, cfg, cbg);
}
void DrawTextln(const char* s, unsigned long cfg)
{
    DrawTextln(s, cfg, 0);
}
void DrawTextln(const char* s)
{
    DrawTextln(s, 0);
}
void DrawTextln()
{
    DrawTextln("");
}
void DrawTextXYw(pbitmap b, const char* s, long x, long y, unsigned long cfg, unsigned long cbg)
{
    unsigned long fi;
    InitTextXY(&b, &s, &cfg, &cbg);
    for (fi = 0; fi < strlen(s); fi++)
    {
        TextOutA(b->DC, x, y, &s[fi], 1);
        x += _fw;
    }
    _fx = x;
    _fy = y;
}
void DrawTextXYw(pbitmap b, const char* s, long x, long y, unsigned long cfg)
{
    DrawTextXYw(b, s, x, y, cfg, 0);
}
void DrawTextXYw(const char* s, long x, long y, unsigned long cfg, unsigned long cbg)
{
    DrawTextXYw(NULL, s, x, y, cfg, cbg);
}
void DrawTextXYw(const char* s, long x, long y, unsigned long cfg)
{
    DrawTextXYw(NULL, s, x, y, cfg);
}
void DrawTextXYw(const char* s, long x, unsigned long y)
{
    DrawTextXYw(s, x, y, 0);
}
void DrawTextw(const char* s, unsigned long cfg, unsigned long cbg)
{
    DrawTextXYw(s, _fx, _fy, cfg, cbg);
}
void DrawTextw(const char* s, unsigned long cfg)
{
    DrawTextw(s, cfg, 0);
}
void DrawTextw(const char* s)
{
    DrawTextw(s, 0);
}
void DrawTextlnXYw(const char* s, long x, long y, unsigned long cfg, unsigned long cbg)
{
    DrawTextXYw(s, x, y, cfg, cbg);
    _fx = x;
    _fy = y + _fh;
}
void DrawTextlnXYw(const char* s, long x, long y, unsigned long cfg)
{
    DrawTextlnXYw(s, x, y, cfg, 0);
}
void DrawTextlnXYw(const char* s, long x, unsigned long y)
{
    DrawTextlnXYw(s, x, y, 0);
}
void DrawTextlnw(const char* s, unsigned long cfg, unsigned long cbg)
{
    DrawTextlnXYw(s, _fx, _fy, cfg, cbg);
}
void DrawTextlnw(const char* s, unsigned long cfg)
{
    DrawTextlnw(s, cfg, 0);
}
void DrawTextlnw(const char* s)
{
    DrawTextlnw(s, 0);
}



unsigned long GetPixel(pbitmap b, unsigned long x, unsigned long y)
{
    if (b == NULL) b = _pmain;
    return GetPixel(b->DC, x, y);
}
unsigned long GetPixel(unsigned long x, unsigned long y)
{
    return GetPixel(NULL, x, y);
}
void SetPixel(pbitmap b, unsigned long x, unsigned long y, unsigned long c)
{
    if (b == NULL) b = _pmain;
    if (c == 0) c = _cfg;
    SetPixel(b->DC, x, y, c);
}
void SetPixel(unsigned long x, unsigned long y, unsigned long c)
{
    SetPixel(NULL, x, y, c);
}
void SetPixel(unsigned long x, unsigned long y)
{
    SetPixel(x, y, 0);
}
void Line(pbitmap b, long x, long y, long w, long h, unsigned long c)
{
    if (b == NULL) b = _pmain;
    if (c == 0) c = _cfg;
    SetPenColor(b, c);
    MoveToEx(b->DC, x, y, NULL);
    LineTo(b->DC, x + w, y + h);
}
void Line(long x, long y, long w, long h, unsigned long c)
{
    Line(NULL, x, y, w, h, c);
}
void Bar(pbitmap b, long x, long y, long w, long h, unsigned long cfg, unsigned long cbg)
{
    RECT lpRect;
    if (b == NULL) b = _pmain;
    if (cfg == 0) cfg = TransParent;
    if (cbg == 0) cbg = _cfg;
    lpRect.left = x;
    lpRect.top = y;
    lpRect.right = x + w;
    lpRect.bottom = y + h;
    if (cbg != TransParent)
    {
        SetBrushColor(b, cbg);
        FillRect(b->DC, &lpRect, (HBRUSH)_br);
    }
    if (cfg != TransParent)
    {
        SetBrushColor(b, cfg);
        SetPenColor(b, cfg);
        FrameRect(b->DC, &lpRect, (HBRUSH)_pe);
    }
}
void Bar(pbitmap b, long x, long y, long w, long h, unsigned long c)
{
    Bar(b, x, y, w, h, 0, c);
}
void Bar(long x, long y, long w, long h, unsigned long cfg, unsigned long cbg)
{
    Bar(NULL, x, y, w, h, cfg, cbg);
}
void Bar(long x, long y, long w, long h, unsigned long c)
{
    Bar(x, y, w, h, 0, c);
}
void Bar(long x, long y, long w, long h)
{
    Bar(x, y, w, h, 0);
}
void Clear(pbitmap b, unsigned long c)
{
    if (b == NULL) b = _pmain;
    if (c == 0) c = _cbg;
    Bar(b, 0, 0, b->Width, b->Height, 0, c);
}
void Clear(pbitmap b)
{
    Clear(b, 0);
}
void Clear(unsigned long c)
{
    Clear(NULL, c);
}
void Clear()
{
    Clear((unsigned long)0);
}

pbitmap CreateBMP(pbitmap b, unsigned long w, unsigned long h, unsigned long c)
{
    if (b == NULL) b = GetWin();
    if (w == 0) w = b->Width;
    if (h == 0) h = b->Height;
    if (c == 0) c = b->Color;
    pbitmap bmp = (pbitmap)calloc(1, sizeof(bitmap));
    bmp->Width = w;
    bmp->Height = h;
    bmp->Color = c;
    while (bmp->DC == 0) bmp->DC = CreateCompatibleDC(_dc);
    while (bmp->Handle == 0) bmp->Handle = CreateCompatibleBitmap(_dc, bmp->Width, bmp->Height);
    SelectObject(bmp->DC, bmp->Handle);
    Clear(bmp, c);
    return bmp;
}
pbitmap CreateBMP(pbitmap b)
{
    return CreateBMP(b, 0, 0, 0);
}
pbitmap CreateBMP(unsigned long w, unsigned long h, unsigned long c)
{
    return CreateBMP(NULL, w, h, c);
}
pbitmap CreateBMP(unsigned long w, unsigned long h)
{
    return CreateBMP(w, h, 0);
}
pbitmap CreateBMP()
{
    return CreateBMP(0, 0);
}
void ReleaseBMP(pbitmap b)
{
    if (b != NULL)
    {
        if (b->DC == _dc)
        {
            ReleaseDC(_hw, b->DC);
        }
        if (b->DC != _dc)
        {
            DeleteObject(b->DC);
        }
        if (b->Handle != _hw)
        {
            DeleteObject(b->Handle);
        }
        if (b != _pmscr)
        {
            free(b);
        }
    }
}
void ReleaseBMP()
{
    ReleaseBMP(GetScr());
    ReleaseBMP(GetWin());
}
pbitmap LoadBMP(const char* s, unsigned long c)
{
    UINT bw, bh;
    if (c == 0) c = GetBGColor();
    MultiByteToWideChar(CP_ACP, 0, s, -1, _GdiWideChar, MAXCHAR);
    Gdiplus::GdiplusStartup(&_GdiToken, &_GdiStart, NULL);
    Gdiplus::DllExports::GdipLoadImageFromFile(_GdiWideChar, &_GdiImage);
    Gdiplus::DllExports::GdipGetImageWidth(_GdiImage, &bw);
    Gdiplus::DllExports::GdipGetImageHeight(_GdiImage, &bh);
    pbitmap bmp = CreateBMP(bw, bh, c);
    Gdiplus::DllExports::GdipCreateFromHDC(bmp->DC, &_GdiGraph);
    Gdiplus::DllExports::GdipDrawImageRect(_GdiGraph, _GdiImage, 0, 0, bw, bh);
    Gdiplus::DllExports::GdipDisposeImage(_GdiImage);
    Gdiplus::DllExports::GdipDeleteGraphics(_GdiGraph);
    Gdiplus::GdiplusShutdown(_GdiToken);
    return bmp;
}
pbitmap LoadBMP(const char* s)
{
    return LoadBMP(s, 0);
}
void SaveBMP(pbitmap b, const char* s)
{
    MultiByteToWideChar(CP_ACP, 0, s, -1, _GdiWideChar, MAXCHAR);
    Gdiplus::GdiplusStartup(&_GdiToken, &_GdiStart, NULL);
    Gdiplus::DllExports::GdipCreateBitmapFromHBITMAP((HBITMAP)b->Handle, NULL, &_GdiBitmap);
    Gdiplus::DllExports::GdipSaveImageToFile(_GdiBitmap, _GdiWideChar, &GDIImageFormatPNG, NULL);
    Gdiplus::DllExports::GdipDisposeImage(_GdiBitmap);
    Gdiplus::GdiplusShutdown(_GdiToken);
}
void DrawBMP(pbitmap bs, pbitmap bd, unsigned long xs, unsigned long ys, unsigned long ws, unsigned long hs, unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd, unsigned long c)
{
    if (!bs) bs = GetWin();
    if (!bd) bd = GetWin();
    if (ws == 0) ws = bs->Width;
    if (hs == 0) hs = bs->Height;
    if (wd == 0) wd = bs->Width;
    if (hd == 0) hd = bs->Height;
    if (c == 0) c = bs->Color;
    unsigned long alpha = GetAlpha(c);
    c &= 0xFFFFFF;
    if (alpha == 0)
    {
        TransparentBlt(bd->DC, xd, yd, wd, hd, bs->DC, xs, ys, ws, hs, c);
    }
    else
    {
        pbitmap bm = CreateBMP(wd, hd, c);
        StretchBlt(bm->DC, 0, 0, wd, hd, bd->DC, xd, yd, wd, hd, SRCCOPY);
        TransparentBlt(bm->DC, 0, 0, wd, hd, bs->DC, xs, ys, ws, hs, c);
        BLENDFUNCTION ftn = {AC_SRC_OVER, 0, (BYTE)(255 - alpha), 0};
        AlphaBlend(bd->DC, xd, yd, wd, hd, bm->DC, 0, 0, wd, hd, ftn);
        ReleaseBMP(bm);
    }
}
void DrawBMP(pbitmap bs, pbitmap bd, unsigned long xs, unsigned long ys, unsigned long ws, unsigned long hs, unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd)
{
    DrawBMP(bs, bd, xs, ys, ws, hs, xd, yd, wd, hd, 0UL);
}
void DrawBMP(pbitmap bs, pbitmap bd, unsigned long xs, unsigned long ys, unsigned long xd, unsigned long yd, unsigned long w, unsigned long h, unsigned long c)
{
    DrawBMP(bs, bd, xs, ys, w, h, xd, yd, w, h, c);
}
void DrawBMP(pbitmap bs, pbitmap bd, unsigned long xs, unsigned long ys, unsigned long xd, unsigned long yd, unsigned long w, unsigned long h)
{
    DrawBMP(bs, bd, xs, ys, xd, yd, w, h, 0UL);
}
void DrawBMP(pbitmap bs, pbitmap bd, unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd, unsigned long c)
{
    DrawBMP(bs, bd, 0UL, 0UL, 0UL, 0UL, xd, yd, wd, hd, c);
}
void DrawBMP(pbitmap bs, pbitmap bd, unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd)
{
    DrawBMP(bs, bd, xd, yd, wd, hd, 0UL);
}
void DrawBMP(pbitmap bs, pbitmap bd, unsigned long xd, unsigned long yd, unsigned long c)
{
    DrawBMP(bs, bd, xd, yd, 0UL, 0UL, c);
}
void DrawBMP(pbitmap bs, pbitmap bd, unsigned long xd, unsigned long yd)
{
    DrawBMP(bs, bd, xd, yd, 0UL);
}
void DrawBMP(pbitmap bs, pbitmap bd, unsigned long c)
{
    DrawBMP(bs, bd, 0UL, 0UL, c);
}
void DrawBMP(pbitmap bs, pbitmap bd)
{
    DrawBMP(bs, bd, 0UL);
}
void DrawBMP(pbitmap bs, unsigned long xs, unsigned long ys, unsigned long ws, unsigned long hs, unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd, unsigned long c)
{
    DrawBMP(bs, (pbitmap)NULL, xs, ys, ws, hs, xd, yd, wd, hd, c);
}
void DrawBMP(pbitmap bs, unsigned long xs, unsigned long ys, unsigned long ws, unsigned long hs, unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd)
{
    DrawBMP(bs, xs, ys, ws, hs, xd, yd, wd, hd, 0UL);
}
void DrawBMP(pbitmap bs, unsigned long xs, unsigned long ys, unsigned long xd, unsigned long yd, unsigned long w, unsigned long h, unsigned long c)
{
    DrawBMP(bs, xs, ys, w, h, xd, yd, w, h, c);
}
void DrawBMP(pbitmap bs, unsigned long xs, unsigned long ys, unsigned long xd, unsigned long yd, unsigned long w, unsigned long h)
{
    DrawBMP(bs, xs, ys, xd, yd, w, h, 0UL);
}
void DrawBMP(pbitmap bs, unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd, unsigned long c)
{
    DrawBMP(bs, 0UL, 0UL, 0UL, 0UL, xd, yd, wd, hd, c);
}
void DrawBMP(pbitmap bs, unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd)
{
    DrawBMP(bs, xd, yd, wd, hd, 0UL);
}
void DrawBMP(pbitmap bs, unsigned long xd, unsigned long yd, unsigned long c)
{
    DrawBMP(bs, xd, yd, 0UL, 0UL, c);
}
void DrawBMP(pbitmap bs, unsigned long xd, unsigned long yd)
{
    DrawBMP(bs, xd, yd, 0UL);
}
void DrawBMP(pbitmap bs, unsigned long c)
{
    DrawBMP(bs, 0UL, 0UL, c);
}
void DrawBMP(pbitmap bs)
{
    DrawBMP(bs, 0UL);
}
void DrawBMP(unsigned long xs, unsigned long ys, unsigned long ws, unsigned long hs, unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd, unsigned long c)
{
    DrawBMP((pbitmap)NULL, xs, ys, ws, hs, xd, yd, wd, hd, c);
}
void DrawBMP(unsigned long xs, unsigned long ys, unsigned long ws, unsigned long hs, unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd)
{
    DrawBMP((pbitmap)NULL, xs, ys, ws, hs, xd, yd, wd, hd);
}
void DrawBMP(unsigned long xs, unsigned long ys, unsigned long xd, unsigned long yd, unsigned long w, unsigned long h, unsigned long c)
{
    DrawBMP((pbitmap)NULL, xs, ys, xd, yd, w, h, c);
}
void DrawBMP(unsigned long xs, unsigned long ys, unsigned long xd, unsigned long yd, unsigned long w, unsigned long h)
{
    DrawBMP((pbitmap)NULL, xs, ys, xd, yd, w, h);
}
void DrawBMP(unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd, unsigned long c)
{
    DrawBMP((pbitmap)NULL, xd, yd, wd, hd, c);
}
void DrawBMP(unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd)
{
    DrawBMP((pbitmap)NULL, xd, yd, wd, hd);
}
void DrawBMP(unsigned long xd, unsigned long yd, unsigned long c)
{
    DrawBMP((pbitmap)NULL, xd, yd, c);
}
void DrawBMP(unsigned long xd, unsigned long yd)
{
    DrawBMP((pbitmap)NULL, xd, yd);
}
void DrawBMP(unsigned long c)
{
    DrawBMP((pbitmap)NULL, c);
}
void DrawBMP()
{
    DrawBMP((pbitmap)NULL);
}

unsigned long HI(uint64_t val)
{
    return (unsigned long)(val >> 32);
}
unsigned long LO(uint64_t val)
{
    return (unsigned long)(val & 0xFFFFFFFF);
}
void SendMsg()
{
    TranslateMessage(&_mst);
    DispatchMessage(&_mst);
}
bool CustomMsg()
{
    bool result = _msusr[_msi].message != 0;
    if (result)
    {
        _ms = _msusr[_msi];
        _msusr[_msi].message = 0;
        _msi++;
        if (_msi > _msusrmax) _msi = 1;
    }
    return result;
}
bool IsNextMsg()
{
    if (!CustomMsg())
    {
        bool result = _mswini != _mswinj;
        if (_mswini != _mswinj)
        {
            _mswinj = (_mswinj + 1) % _mswinmax;
            _ms = _mswin[_mswinj];
            while (_ms.message == 0) _ms = _mswin[_mswinj];
        }
        return result;
    }
    return true;
}
unsigned long GetNextMsg()
{
    return _ms.message;
}
unsigned long WaitNextMsg()
{
    if (!CustomMsg())
    {
        while (!IsNextMsg() && IsWin()) Sleep(1);
    }
    return GetNextMsg();
}
bool IsMsg(const unsigned long uM[], unsigned long length)
{
    for (unsigned long mi = 0; mi < length; mi++) if (_ms.message == uM[mi]) return true;
    return false;
}
uint64_t GetMsg(const unsigned long uM[], unsigned long length)
{
    return !IsMsg(uM, length) ? 0 : ((uint64_t)_ms.wParam << 32) | _ms.lParam;
}
uint64_t WaitMsg(const unsigned long uM[], unsigned long length)
{
    do
    {
        WaitNextMsg();
    }
    while (!IsMsg(uM, length));
    return GetMsg(uM, length);
}
bool IsMsg(unsigned long uM)
{
    unsigned long ums[1] = {uM};
    return IsMsg(ums, 1);
}
uint64_t GetMsg(unsigned long uM)
{
    unsigned long ums[1] = {uM};
    return GetMsg(ums, 1);
}
uint64_t WaitMsg(unsigned long uM)
{
    unsigned long ums[1] = {uM};
    return WaitMsg(ums, 1);
}
bool IsKey(unsigned long k)
{
    return IsMsg(WM_KEYDOWN) && (!k || (GetKey() == k));
}
bool IsKey()
{
    return IsKey(0);
}
unsigned long GetKey()
{
    return HI(GetMsg(WM_KEYDOWN));
}
unsigned long WaitKey(unsigned long k)
{
    while (!IsKey()) WaitNextMsg();
    return GetKey();
}
unsigned long WaitKey()
{
    return WaitKey(0);
}
bool IsMouse(unsigned long m)
{
    return IsMsg(_bdn, 3) && (!m || (GetMouse() == m));
}
bool IsMouse()
{
    return IsMouse(0);
}
unsigned long GetMouse()
{
    return HI(GetMsg(_bdn, 3));
}
unsigned long WaitMouse(unsigned long m)
{
    while (!IsMouse()) WaitNextMsg();
    return GetMouse();
}
unsigned long WaitMouse()
{
    return WaitMouse(0);
}
bool IsMouseLeft()
{
    return IsMsg(WM_LBUTTONDOWN);
}
void WaitMouseLeft()
{
    WaitMsg(WM_LBUTTONDOWN);
}
bool IsMouseMiddle()
{
    return IsMsg(WM_MBUTTONDOWN);
}
void WaitMouseMiddle()
{
    WaitMsg(WM_MBUTTONDOWN);
}
bool IsMouseRight()
{
    return IsMsg(WM_RBUTTONDOWN);
}
void WaitMouseRight()
{
    WaitMsg(WM_RBUTTONDOWN);
}
bool IsMouseWheel()
{
    return IsMsg(WM_MOUSEWHEEL);
}
long GetMouseWheel()
{
    return (long)HIWORD(HI(GetMsg(WM_MOUSEWHEEL)));
}
void WaitMouseWheel()
{
    WaitMsg(WM_MOUSEWHEEL);
}
bool IsMouseMove()
{
    return IsMsg(WM_MOUSEMOVE);
}
unsigned long GetMouseMove()
{
    return LO(GetMsg(WM_MOUSEMOVE));
}
unsigned long WaitMouseMove()
{
    return LO(WaitMsg(WM_MOUSEMOVE));
}
bool IsDropFile()
{
    return IsMsg(WM_DROPFILES);
}
char* GetDropFile()
{
    char c[MAXCHAR];
    DragQueryFileA((HDROP)_ms.wParam, 0, c, MAXCHAR);
    return strdup(c);
}
wchar_t *GetDropFileW()
{
    wchar_t c[MAXCHAR];
    DragQueryFileW((HDROP)_ms.wParam, 0, c, MAXCHAR);
    return wcsdup(c);
}
char* WaitDropFile()
{
    WaitMsg(WM_DROPFILES);
    return GetDropFile();
}
long GetMouseAbsX()
{
    POINT p;
    GetCursorPos(&p);
    return p.x;
}
long GetMouseAbsY()
{
    POINT p;
    GetCursorPos(&p);
    return p.y;
}
long GetMouseWinX()
{
    return GetMouseAbsX() - GetPosX();
}
long GetMouseWinY()
{
    return GetMouseAbsY() - GetPosY();
}
long GetMousePosX()
{
    return GetMouseWinX() - ((_style & WS_POPUP == WS_POPUP) ? 0 : GetBorderWidth());
}
long GetMousePosY()
{
    return GetMouseWinY() - ((_style & WS_POPUP == WS_POPUP) ? 0 : GetBorderHeight() + GetBorderTitle());
}

unsigned long MsgBoxW(const short int* s, const short int* title, unsigned long i)
{
    return MessageBoxW(NULL, (LPCWSTR)s, (LPCWSTR)title, i);
}
unsigned long MsgBox(const char* s, const char* title, unsigned long i)
{
    return MessageBox(NULL, s, title, i);
}
void MsgBoxW(const short int* s, const short int* title)
{
    MsgBoxW(s, title, 0);
}
void MsgBox(const char* s, const char* title)
{
    MsgBox(s, title, 0);
}
void MsgBoxW(const short int* s)
{
    MsgBoxW(s, (const short int*)L"");
}
void MsgBox(const char* s)
{
    MsgBox(s, "");
}
void Delay(unsigned long t)
{
    Sleep(t);
}
void Delay()
{
    Delay((unsigned long)DELAYTIMEDEFAULT);
}

unsigned long SendString(const char* s)
{
    char c[MAXCHAR];
    mciSendString(s, c, MAXCHAR, (HWND)NULL);
    return strtoul(c, NULL, 10);
}
unsigned long LoadAudio(const char* s1, const char* s2)
{
    char command[256];
    _cid++;
    sprintf(command, "open \"%s\"%s alias s%lu", s1, s2, _cid);
    SendString(command);
    return _cid;
}
unsigned long LoadAudio(const char* s)
{
    return LoadAudio(s, "");
}
void PlayAudio(unsigned long id, const char* s, bool b)
{
    char command[256];
    sprintf(command, b ? "play s%lu%s wait repeat" : "play s%lu%s", id, s);
    SendString(command);
}
void PlayAudio(unsigned long id, const char* s)
{
    PlayAudio(id, s, false);
}
void PlayAudio(unsigned long id, bool b)
{
    PlayAudio(id, "", b);
}
void PlayAudio(unsigned long id)
{
    PlayAudio(id, "", false);
}
void StopAudio(unsigned long id)
{
    char command[256];
    SetAudioPos(id, 0, false);
    sprintf(command, "stop s%lu", id);
    SendString(command);
}
void PauseAudio(unsigned long id)
{
    char command[128];
    sprintf(command, "pause s%lu", id);
    SendString(command);
}
void ResumeAudio(unsigned long id)
{
    char command[128];
    sprintf(command, "resume s%lu", id);
    SendString(command);
}
void ReleaseAudio(unsigned long id)
{
    char command[128];
    sprintf(command, "close s%lu", id);
    SendString(command);
}
unsigned long GetAudioPos(unsigned long id)
{
    char command[128];
    sprintf(command, "status s%lu position", id);
    return SendString(command);
}
void SetAudioPos(unsigned long id, unsigned long pos, bool b)
{
    char command[256];
    unsigned long len = GetAudioLen(id);
    sprintf(command, " from %lu to %lu", pos, len);
    PlayAudio(id, command, b);
}
void SetAudioPos(unsigned long id, unsigned long pos)
{
    SetAudioPos(id, pos, false);
}
unsigned long GetAudioLen(unsigned long id)
{
    char command[128];
    sprintf(command, "status s%lu length", id);
    return SendString(command);
}

bool IsFile(const char* s)
{
    WIN32_FIND_DATA fd;
    HANDLE fh = FindFirstFile(s, &fd);
    bool result = fh != INVALID_HANDLE_VALUE;
    if (result)
    {
        FindClose(fh);
    }
    return result;
}

uint8_t UTF8ToUnicode(uint8_t *utf8, uint32_t *unicode)
{
    const uint8_t lut_size = 3;
    const uint8_t length_lut[] = {2, 3, 4};
    const uint8_t range_lut[] = {0xE0, 0xF0, 0xF8};
    const uint8_t mask_lut[] = {0x1F, 0x0F, 0x07};
    uint8_t length = 0;
    byte b = *(utf8 + 0);
    uint32_t i = 0;
    if (utf8 == NULL)
    {
        *unicode = 0;
        return 1;
    }
    if (b < 0x80)
    {
        *unicode = b;
        return 1;
    }
    if (b < 0xC0 || b > 0xFD)
    {
        *unicode = 0;
        return 1;
    }
    for (i = 0; i < lut_size; i++)
    {
        if (b < range_lut[i])
        {
            *unicode = b &mask_lut[i];
            length = length_lut[i];
            break;
        }
    }
    if (length == 0)
    {
        *unicode = 0;
        return 1;
    }
    for (i = 1; i < length; i++)
    {
        b = *(utf8 + i);
        if (b < 0x80 || b > 0xBF)
        {
            break;
        }
        *unicode <<= 6;
        *unicode |= (b &0x3F);
    }
    return (i < length) ? 1 : length;
}

uint8_t UnicodeToUTF16(uint32_t unicode, uint16_t *utf16)
{
    if (unicode <= 0xFFFF)
    {
        if (utf16 != NULL)
        {
            *utf16 = (unicode &0xFFFF);
        }
        return 1;
    }
    else if (unicode <= 0xEFFFF)
    {
        if (utf16 != NULL)
        {
            *(utf16 + 0) = 0xD800 + (unicode >> 10) - 0x40;
            *(utf16 + 1) = 0xDC00 + (unicode &0x03FF);
        }
        return 2;
    }
    return 0;
}
