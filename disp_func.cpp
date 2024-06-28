void createwin(unsigned long x, unsigned long y, unsigned long w, unsigned long h, unsigned long cfg, unsigned long cbg, unsigned long style, const char* winclass)
{
    CreateWin(x, y, w, h, cfg, cbg, style, winclass);
}
void freshwin()
{
    FreshWin();
}
void closewin()
{
    CloseWin();
}
bool iswin()
{
    return IsWin();
}
pbitmap getwin()
{
    return GetWin();
}
pbitmap getscr()
{
    return GetScr();
}
unsigned long gethwnd()
{
    return GetHwnd();
}
unsigned long getbgcolor()
{
    return GetBGColor();
}
char getalpha(long c)
{
    return GetAlpha(c);
}
double gettimer()
{
    return GetTimeR();
}
void settitlew(const short int* s)
{
    SetTitleW(s);
}
void setsize(unsigned long x, unsigned long y, unsigned long w, unsigned long h)
{
    SetSize(x, y, w, h);
}
unsigned long getwidth()
{
    return GetWidth();
}
unsigned long getheight()
{
    return GetHeight();
}
unsigned long getsize()
{
    return GetSize();
}
long getscrwidth()
{
    return GetScrWidth();
}
long getscrheight()
{
    return GetScrHeight();
}
unsigned long getscrsize()
{
    return GetScrSize();
}
long getbordertitle()
{
    return GetBorderTitle();
}
long getborderwidth()
{
    return GetBorderWidth();
}
long getborderheight()
{
    return GetBorderHeight();
}
unsigned long getbordersize()
{
    return GetBorderSize();
}
long getposx()
{
    return GetPosX();
}
long getposy()
{
    return GetPosY();
}
void setfont(pbitmap b)
{
    SetFont(b);
}
void setfontwidth(unsigned long w)
{
    SetFontWidth(w);
}
void setfontheight(unsigned long h)
{
    SetFontHeight(h);
}
void setfontweight(unsigned long wg)
{
    SetFontWeight(wg);
}
void setfontname(const char* s)
{
    SetFontName(s);
}
unsigned long getstringwidth(const char* s)
{
    return GetStringWidth(s);
}
void drawtextxy(pbitmap b, const short int* s, long x, long y, unsigned long w, unsigned long h, unsigned long cfg, unsigned long cbg, unsigned long format)
{
    DrawTextXY(b, s, x, y, w, h, cfg, cbg, format);
}
void drawtextxy(pbitmap b, const short int* s, long x, long y, unsigned long w, unsigned long h, unsigned long cfg, unsigned long cbg)
{
    DrawTextXY(b, s, x, y, w, h, cfg, cbg);
}
void drawtextxy(pbitmap b, const char* s, long x, long y, unsigned long w, unsigned long h, unsigned long cfg, unsigned long cbg)
{
    DrawTextXY(b, s, x, y, w, h, cfg, cbg);
}
void drawtextxy(pbitmap b, const char* s, long x, long y, unsigned long cfg, unsigned long cbg)
{
    DrawTextXY(b, s, x, y, cfg, cbg);
}
unsigned long getpixel(pbitmap b, unsigned long x, unsigned long y)
{
    return GetPixel(b, x, y);
}
void line(long x, long y, long w, long h, unsigned long c)
{
    Line(x, y, w, h, c);
}
void bar(long x, long y, long w, long h, unsigned long cfg, unsigned long cbg)
{
    Bar(x, y, w, h, cfg, cbg);
}
void bar(long x, long y, long w, long h, unsigned long c)
{
    Bar(x, y, w, h, c);
}
void clear(pbitmap b, unsigned long c)
{
    Clear(b, c);
}
void clear(unsigned long c)
{
    Clear(c);
}
pbitmap createbmp(unsigned long w, unsigned long h, unsigned long c)
{
    return CreateBMP(w, h, c);
}
pbitmap createbmp(unsigned long w, unsigned long h)
{
    return CreateBMP(w, h);
}
void releasebmp(pbitmap b)
{
    ReleaseBMP(b);
}
pbitmap loadbmp(const char* s)
{
    return LoadBMP(s);
}
void savebmp(pbitmap b, const char* s)
{
    SaveBMP(b, s);
}
void drawbmp(pbitmap bs, pbitmap bd, unsigned long xs, unsigned long ys, unsigned long ws, unsigned long hs, unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd)
{
    DrawBMP(bs, bd, xs, ys, ws, hs, xd, yd, wd, hd);
}
void drawbmp(pbitmap bs, pbitmap bd, unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd, unsigned long c)
{
    DrawBMP(bs, bd, 0UL, 0UL, 0UL, 0UL, xd, yd, wd, hd, c);
}
void drawbmp(pbitmap bs, pbitmap bd, unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd)
{
    DrawBMP(bs, bd, 0UL, 0UL, 0UL, 0UL, xd, yd, wd, hd);
}
void drawbmp(pbitmap bs, unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd, unsigned long c)
{
    DrawBMP(bs, (pbitmap)NULL, 0UL, 0UL, 0UL, 0UL, xd, yd, wd, hd, c);
}
void drawbmp(pbitmap bs, unsigned long xd, unsigned long yd, unsigned long wd, unsigned long hd)
{
    DrawBMP(bs, (pbitmap)NULL, 0UL, 0UL, 0UL, 0UL, xd, yd, wd, hd);
}
void drawbmp(pbitmap bs, unsigned long xd, unsigned long yd, unsigned long c)
{
    DrawBMP(bs, (pbitmap)NULL, 0UL, 0UL, 0UL, 0UL, xd, yd, 0UL, 0UL, c);
}
bool isnextmsg()
{
    return IsNextMsg();
}
bool ismsg(unsigned long uM)
{
    return IsMsg(uM);
}
bool iskey()
{
    return IsKey();
}
unsigned long getkey()
{
    return GetKey();
}
bool ismouseleft()
{
    return IsMouseLeft();
}
bool ismouseright()
{
    return IsMouseRight();
}
bool ismousemove()
{
    return IsMouseMove();
}
long getmouseposx()
{
    return GetMousePosX();
}
long getmouseposy()
{
    return GetMousePosY();
}
unsigned long msgboxw(const short int* s, const short int* title, unsigned long i)
{
    return MsgBoxW(s, title, i);
}
unsigned long msgbox(const char* s, const char* title, unsigned long i)
{
    return MsgBox(s, title, i);
}
void delay(unsigned long t)
{
    Delay(t);
}
unsigned long loadaudio(const char* s1, const char* s2)
{
    return LoadAudio(s1, s2);
}
unsigned long loadaudio(const char* s)
{
    return LoadAudio(s);
}
void stopaudio(unsigned long id)
{
    StopAudio(id);
}
unsigned long getaudiopos(unsigned long id)
{
    return GetAudioPos(id);
}
void setaudiopos(unsigned long id, unsigned long pos)
{
    SetAudioPos(id, pos);
}
unsigned long getaudiolen(unsigned long id)
{
    return GetAudioLen(id);
}

