#include<windows.h>
#include<time.h>
#include<math.h>
#include<gdiplus.h>
#include<wingdi.h>

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
unsigned long GetHwnd(pbitmap b);
unsigned long GetHwnd();
unsigned long GetDraw(pbitmap b);
unsigned long GetDraw();

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
void Line(pbitmap b, long x, long y, long w, long h);
void Line(long x, long y, long w, long h, unsigned long c);
void Line(long x, long y, long w, long h);
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
void Delay(double t);
void Delay(unsigned long t);
void Delay();
