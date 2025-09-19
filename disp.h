#pragma once
#include <windows.h>
#include <time.h>
#include <math.h>
#include <wingdi.h>
#include <gdiplus.h>
#include <stdint.h>
#include <stdio.h>

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

extern const char* version;
extern HINSTANCE MainInstance;

extern long painttitleb;
extern long painttitlec;
extern const char* painttitles;

extern void WinCreateMain();
extern LRESULT CALLBACK WndProc(HWND hW, UINT uM, WPARAM wP, LPARAM lP);
extern BOOL CALLBACK Monitorenumproc(HMONITOR hmon, HDC hdc, LPRECT lprect, LPARAM pdata);
extern ATOM WinRegister();
extern void WinCreate();
extern void WinInit();

extern void FreshFPS();
extern void AddFPS();

extern void CreateWin(long x, long y, unsigned long w, unsigned long h, unsigned long cfg, unsigned long cbg, unsigned long style, const char* winclass);
extern void CreateWin(unsigned long w, unsigned long h, unsigned long cfg, unsigned long cbg, unsigned long style, const char* winclass);
extern void CreateWin(unsigned long w, unsigned long h, unsigned long cfg, unsigned long cbg, unsigned long style);
extern void CreateWin(unsigned long w, unsigned long h, unsigned long cfg, unsigned long cbg);
extern void CreateWin(unsigned long w, unsigned long h, unsigned long c);
extern void CreateWin(unsigned long w, unsigned long h);
extern void CreateWin(unsigned long cbg);
extern void CreateWin();
extern void FreshWin();
extern void CloseWin();
extern bool IsWin();
extern double GetTimeR();
extern unsigned long GetTime();
extern void SetTitle(const char* s);
extern void SetTitleW(const short int* s);
extern char* GetTitle();
extern short int* GetTitleW();
extern void SetSize(long x, long y, unsigned long w, unsigned long h);
extern void SetSize(unsigned long w, unsigned long h);
extern unsigned long GetWidth();
extern unsigned long GetHeight();
extern unsigned long GetSize();
extern long GetScrWidth();
extern long GetScrHeight();
extern unsigned long GetScrSize();
extern double GetScrCapsX();
extern double GetScrCapsY();
extern long GetBorderTitle();
extern long GetBorderWidth();
extern long GetBorderHeight();
extern unsigned long GetBorderSize();
extern void SetPos(long x, long y);
extern long GetPosX();
extern long GetPosY();
extern unsigned long GetPos();
extern pbitmap GetWin();
extern pbitmap GetScr();
extern HGDIOBJ GetHwnd(pbitmap b);
extern HWND GetHwnd();
extern HDC GetDraw(pbitmap b);
extern HDC GetDraw();

extern unsigned long GetBGColor();
extern void SetBGColor(unsigned long c);
extern unsigned long GetFGColor();
extern void SetFGColor(unsigned long c);
extern void SetPenWidth(unsigned long pew);
extern void SetPenColor(pbitmap b, unsigned long c);
extern void SetBrushColor(pbitmap b, unsigned long c);
extern void SetPenColor(unsigned long c);
extern void SetBrushColor(unsigned long c);
extern unsigned char GetRed(unsigned long c);
extern unsigned char GetGreen(unsigned long c);
extern unsigned char GetBlue(unsigned long c);
extern unsigned char GetAlpha(unsigned long c);
extern unsigned long GetRGBA(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
extern unsigned long GetRGB(unsigned char r, unsigned char g, unsigned char b);

extern void SetFont(pbitmap b);
extern void SetFont();
extern void SetFontWidth(unsigned long w);
extern void SetFontHeight(unsigned long h);
extern void SetFontSize(unsigned long w, unsigned long h);
extern void SetFontWeight(unsigned long wg);
extern void SetFontLtalic(unsigned long lt);
extern void SetFontUnderLine(unsigned long ud);
extern void SetFontStrikeOut(unsigned long sk);
extern void SetFontCharSet(unsigned long cs);
extern void SetFontName(const char* s);
extern void GetStringSize(const char* s);
extern unsigned long GetStringWidth(const char* s);
extern unsigned long GetStringHeight(const char* s);

extern void InitTextXY(pbitmap* b, const short int** s, unsigned long* cfg, unsigned long* cbg);
extern void InitTextXY(pbitmap* b, const char** s, unsigned long* cfg, unsigned long* cbg);
extern void DrawTextXY(pbitmap b, const short int* s, long x, long y, unsigned long w, unsigned long h, unsigned long cfg, unsigned long cbg, unsigned long format);
extern void DrawTextXY(pbitmap b, const short int* s, long x, long y, unsigned long w, unsigned long h, unsigned long cfg, unsigned long cbg);
extern void DrawTextXY(pbitmap b, const char* s, long x, long y, unsigned long w, unsigned long h, unsigned long cfg, unsigned long cbg);
extern void DrawTextXY(pbitmap b, const char* s, long x, long y, unsigned long cfg, unsigned long cbg);
extern void DrawTextXY(pbitmap b, const char* s, long x, long y, unsigned long cfg);
extern void DrawTextXY(const char* s, long x, long y, unsigned long cfg, unsigned long cbg);
extern void DrawTextXY(const char* s, long x, long y, unsigned long cfg);
extern void DrawTextXY(const char* s, long x, unsigned long y);
extern void DrawText(const char* s, unsigned long cfg, unsigned long cbg);
extern void DrawText(const char* s, unsigned long cfg);
extern void DrawText(const char* s);
extern void DrawTextlnXY(const char* s, long x, long y, unsigned long cfg, unsigned long cbg);
extern void DrawTextlnXY(const char* s, long x, long y, unsigned long cfg);
extern void DrawTextlnXY(const char* s, long x, unsigned long y);
extern void DrawTextln(const char* s, unsigned long cfg, unsigned long cbg);
extern void DrawTextln(const char* s, unsigned long cfg);
extern void DrawTextln(const char* s);
extern void DrawTextln();
extern void DrawTextXYw(pbitmap b, const char* s, long x, long y, unsigned long cfg, unsigned long cbg);
extern void DrawTextXYw(pbitmap b, const char* s, long x, long y, unsigned long cfg);
extern void DrawTextXYw(const char* s, long x, long y, unsigned long cfg, unsigned long cbg);
extern void DrawTextXYw(const char* s, long x, long y, unsigned long cfg);
extern void DrawTextXYw(const char* s, long x, unsigned long y);
extern void DrawTextw(const char* s, unsigned long cfg, unsigned long cbg);
extern void DrawTextw(const char* s, unsigned long cfg);
extern void DrawTextw(const char* s);
extern void DrawTextlnXYw(const char* s, long x, long y, unsigned long cfg, unsigned long cbg);
extern void DrawTextlnXYw(const char* s, long x, long y, unsigned long cfg);
extern void DrawTextlnXYw(const char* s, long x, unsigned long y);
extern void DrawTextlnw(const char* s, unsigned long cfg, unsigned long cbg);
extern void DrawTextlnw(const char* s, unsigned long cfg);
extern void DrawTextlnw(const char* s);

extern unsigned long GetPixel(pbitmap b, unsigned long x, unsigned long y);
extern unsigned long GetPixel(unsigned long x, unsigned long y);
extern void SetPixel(pbitmap b, unsigned long x, unsigned long y, unsigned long c);
extern void SetPixel(unsigned long x, unsigned long y, unsigned long c);
extern void SetPixel(unsigned long x, unsigned long y);
extern void Line(pbitmap b, long x, long y, long w, long h, unsigned long c);
extern void Line(long x, long y, long w, long h, unsigned long c);
extern void Bar(pbitmap b, long x, long y, long w, long h, unsigned long cfg, unsigned long cbg);
extern void Bar(pbitmap b, long x, long y, long w, long h, unsigned long c);
extern void Bar(long x, long y, long w, long h, unsigned long cfg, unsigned long cbg);
extern void Bar(long x, long y, long w, long h, unsigned long c);
extern void Bar(long x, long y, long w, long h);
extern void Clear(pbitmap b, unsigned long c);
extern void Clear(pbitmap b);
extern void Clear(unsigned long c);
extern void Clear();

extern pbitmap CreateBMP(pbitmap b, unsigned long w, unsigned long h, unsigned long c);
extern pbitmap CreateBMP(pbitmap b);
extern pbitmap CreateBMP(unsigned long w, unsigned long h, unsigned long c);
extern pbitmap CreateBMP(unsigned long w, unsigned long h);
extern pbitmap CreateBMP();
extern void ReleaseBMP(pbitmap b);
extern void ReleaseBMP();
extern pbitmap LoadBMP(const char* s, unsigned long c);
extern pbitmap LoadBMP(const char* s);
extern void SaveBMP(pbitmap b, const char* s);
extern void DrawBMP(pbitmap bs, pbitmap bd, unsigned long xs, unsigned long ys, unsigned long ws, unsigned long hs, unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd, unsigned long c);
extern void DrawBMP(pbitmap bs, pbitmap bd, unsigned long xs, unsigned long ys, unsigned long ws, unsigned long hs, unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd);
extern void DrawBMP(pbitmap bs, pbitmap bd, unsigned long xs, unsigned long ys, unsigned long xd, unsigned long yd, unsigned long w, unsigned long h, unsigned long c);
extern void DrawBMP(pbitmap bs, pbitmap bd, unsigned long xs, unsigned long ys, unsigned long xd, unsigned long yd, unsigned long w, unsigned long h);
extern void DrawBMP(pbitmap bs, pbitmap bd, unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd, unsigned long c);
extern void DrawBMP(pbitmap bs, pbitmap bd, unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd);
extern void DrawBMP(pbitmap bs, pbitmap bd, unsigned long xd, unsigned long yd, unsigned long c);
extern void DrawBMP(pbitmap bs, pbitmap bd, unsigned long xd, unsigned long yd);
extern void DrawBMP(pbitmap bs, pbitmap bd, unsigned long c);
extern void DrawBMP(pbitmap bs, pbitmap bd);
extern void DrawBMP(pbitmap bs, unsigned long xs, unsigned long ys, unsigned long ws, unsigned long hs, unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd, unsigned long c);
extern void DrawBMP(pbitmap bs, unsigned long xs, unsigned long ys, unsigned long ws, unsigned long hs, unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd);
extern void DrawBMP(pbitmap bs, unsigned long xs, unsigned long ys, unsigned long xd, unsigned long yd, unsigned long w, unsigned long h, unsigned long c);
extern void DrawBMP(pbitmap bs, unsigned long xs, unsigned long ys, unsigned long xd, unsigned long yd, unsigned long w, unsigned long h);
extern void DrawBMP(pbitmap bs, unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd, unsigned long c);
extern void DrawBMP(pbitmap bs, unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd);
extern void DrawBMP(pbitmap bs, unsigned long xd, unsigned long yd, unsigned long c);
extern void DrawBMP(pbitmap bs, unsigned long xd, unsigned long yd);
extern void DrawBMP(pbitmap bs, unsigned long c);
extern void DrawBMP(pbitmap bs);
extern void DrawBMP(unsigned long xs, unsigned long ys, unsigned long ws, unsigned long hs, unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd, unsigned long c);
extern void DrawBMP(unsigned long xs, unsigned long ys, unsigned long ws, unsigned long hs, unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd);
extern void DrawBMP(unsigned long xs, unsigned long ys, unsigned long xd, unsigned long yd, unsigned long w, unsigned long h, unsigned long c);
extern void DrawBMP(unsigned long xs, unsigned long ys, unsigned long xd, unsigned long yd, unsigned long w, unsigned long h);
extern void DrawBMP(unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd, unsigned long c);
extern void DrawBMP(unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd);
extern void DrawBMP(unsigned long xd, unsigned long yd, unsigned long c);
extern void DrawBMP(unsigned long xd, unsigned long yd);
extern void DrawBMP(unsigned long c);
extern void DrawBMP();

extern void SendMsg();
extern bool CustomMsg();
extern bool IsNextMsg();
extern unsigned long GetNextMsg();
extern unsigned long WaitNextMsg();
extern bool IsMsg(const unsigned long uM[], unsigned long length);
extern uint64_t GetMsg(const unsigned long uM[], unsigned long length);
extern uint64_t WaitMsg(const unsigned long uM[], unsigned long length);
extern bool IsMsg(unsigned long uM);
extern uint64_t GetMsg(unsigned long uM);
extern uint64_t WaitMsg(unsigned long uM);
extern bool IsKey(unsigned long k);
extern bool IsKey();
extern unsigned long GetKey();
extern unsigned long WaitKey(unsigned long k);
extern unsigned long WaitKey();
extern bool IsMouse(unsigned long m);
extern bool IsMouse();
extern unsigned long GetMouse();
extern unsigned long WaitMouse(unsigned long m);
extern unsigned long WaitMouse();
extern bool IsMouseLeft();
extern void WaitMouseLeft();
extern bool IsMouseMiddle();
extern void WaitMouseMiddle();
extern bool IsMouseRight();
extern void WaitMouseRight();
extern bool IsMouseWheel();
extern long GetMouseWheel();
extern void WaitMouseWheel();
extern bool IsMouseMove();
extern unsigned long GetMouseMove();
extern unsigned long WaitMouseMove();
extern bool IsDropFile();
extern char *GetDropFile();
extern wchar_t *GetDropFileW();
extern char *WaitDropFile();
extern long GetMouseAbsX();
extern long GetMouseAbsY();
extern long GetMouseWinX();
extern long GetMouseWinY();
extern long GetMousePosX();
extern long GetMousePosY();

extern unsigned long MsgBoxW(const short int* s, const short int* title, unsigned long i);
extern unsigned long MsgBox(const char* s, const char* title, unsigned long i);
extern void MsgBoxW(const short int* s, const short int* title);
extern void MsgBox(const char* s, const char* title);
extern void MsgBoxW(const short int* s);
extern void MsgBox(const char* s);
extern void Delay(unsigned long t);
extern void Delay();

extern unsigned long SendString();
extern unsigned long LoadAudio(const char* s1, const char* s2);
extern unsigned long LoadAudio(const char* s);
extern void PlayAudio(unsigned long id, const char* s = "", bool b = false);
extern void StopAudio(unsigned long id);
extern void PauseAudio(unsigned long id);
extern void ResumeAudio(unsigned long id);
extern void ReleaseAudio(unsigned long id);
extern unsigned long GetAudioPos(unsigned long id);
extern void SetAudioPos(unsigned long id, unsigned long pos = 0, bool b = false);
extern unsigned long GetAudioLen(unsigned long id);

extern bool IsFile(const char* s);

extern uint8_t UTF8ToUnicode(uint8_t *utf8, uint32_t *unicode);
extern uint8_t UnicodeToUTF16(uint32_t unicode, uint16_t *utf16);
