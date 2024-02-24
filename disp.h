#include<windows.h>
#include<math.h>
#include<time.h>
#ifndef max  
#define max(a,b)            (((a) > (b)) ? (a) : (b))  
#endif  
#ifndef min  
#define min(a,b)            (((a) < (b)) ? (a) : (b))  
#endif 
struct bitmap {
	unsigned long handle;
	unsigned long dc;
	unsigned long width;
	unsigned long height;
	unsigned long color;
};
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

extern "C" unsigned long MsgBoxW22(const short int* s,const short int* title,unsigned long i);
extern "C" unsigned long MsgBox23(const char* s,const char* title,unsigned long i);
extern "C" void Delay28(unsigned long t);
extern "C" void CreateWin39(unsigned long x,unsigned long y,unsigned long w,unsigned long h,unsigned long cfg,unsigned long cbg,unsigned long style,const char* winclass);
extern "C" void FreshWin47();
extern "C" void CloseWin48();
extern "C" bool IsWin49();
extern "C" double GetTimeR51();
extern "C" void SetTitleW54(const short int* s);
extern "C" void SetSize57(unsigned long x,unsigned long y,unsigned long w,unsigned long h);
extern "C" unsigned long GetWidth59();
extern "C" unsigned long GetHeight60();
extern "C" unsigned long GetSize61();
extern "C" long GetScrWidth62();
extern "C" long GetScrHeight63();
extern "C" unsigned long GetScrSize64();
extern "C" long GetBorderTitle67();
extern "C" long GetBorderWidth68();
extern "C" long GetBorderHeight69();
extern "C" unsigned long GetBorderSize70();
extern "C" long GetPosX72();
extern "C" long GetPosY73();
extern "C" pbitmap GetWin75();
extern "C" unsigned long GetHwnd78();
extern "C" void SetFont106(pbitmap b);
extern "C" void SetFontWidth108(unsigned long w);
extern "C" void SetFontHeight109(unsigned long h);
extern "C" void SetFontWeight111(unsigned long wg);
extern "C" void SetFontName116(const char* s);
extern "C" unsigned long GetStringWidth118(const char* s);
extern "C" void DrawTextXY120(pbitmap b,const short int* s,long x,long y,unsigned long w,unsigned long h,unsigned long cfg,unsigned long cbg,unsigned long format);
extern "C" void DrawTextXY121(pbitmap b,const short int* s,long x,long y,unsigned long w,unsigned long h,unsigned long cfg,unsigned long cbg);
extern "C" void DrawTextXY122(pbitmap b,const char* s,long x,long y,unsigned long w,unsigned long h,unsigned long cfg,unsigned long cbg);
extern "C" void DrawTextXY123(pbitmap b,const char* s,long x,long y,unsigned long cfg,unsigned long cbg);
extern "C" unsigned long GetPixel152(pbitmap b,unsigned long x,unsigned long y);
extern "C" void Line160(long x,long y,long w,long h,unsigned long c);
extern "C" void Bar165(long x,long y,long w,long h,unsigned long cfg,unsigned long cbg);
extern "C" void Bar166(long x,long y,long w,long h,unsigned long c);
extern "C" void Clear168(pbitmap b,unsigned long c);
extern "C" void Clear170(unsigned long c);
extern "C" pbitmap CreateBMP198(unsigned long w,unsigned long h,unsigned long c);
extern "C" pbitmap CreateBMP199(unsigned long w,unsigned long h);
extern "C" void ReleaseBMP201(pbitmap b);
extern "C" pbitmap LoadBMP204(const char* s);
extern "C" void SaveBMP205(pbitmap b,const char* s);
extern "C" void DrawBMP207(pbitmap bs,pbitmap bd,unsigned long xs,unsigned long ys,unsigned long ws,unsigned long hs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd);
extern "C" void DrawBMP210(pbitmap bs,pbitmap bd,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd,unsigned long c);
extern "C" void DrawBMP211(pbitmap bs,pbitmap bd,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd);
extern "C" void DrawBMP220(pbitmap bs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd,unsigned long c);
extern "C" void DrawBMP221(pbitmap bs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd);
extern "C" void DrawBMP222(pbitmap bs,unsigned long xd,unsigned long yd,unsigned long c);
extern "C" bool IsNextMsg261();
extern "C" bool IsMsg264(unsigned long uM);
extern "C" bool IsKey268();
extern "C" unsigned long GetKey269();
extern "C" bool IsMouseLeft277();
extern "C" bool IsMouseRight281();
extern "C" bool IsMouseMove286();
extern "C" long GetMousePosX297();
extern "C" long GetMousePosY298();
extern "C" unsigned long LoadAudio299(const char* s1,const char* s2);
extern "C" unsigned long LoadAudio300(const char* s);
extern "C" void StopAudio305(unsigned long id);
extern "C" unsigned long GetAudioPos311(unsigned long id);
extern "C" void SetAudioPos313(unsigned long id,unsigned long pos);
extern "C" unsigned long GetAudioLen314(unsigned long id);

unsigned long msgboxw(const short int* s,const short int* title,unsigned long i){return MsgBoxW22(s,title,i);}
unsigned long msgbox(const char* s,const char* title,unsigned long i){return MsgBox23(s,title,i);}
void delay(unsigned long t){Delay28(t);}
void createwin(unsigned long x,unsigned long y,unsigned long w,unsigned long h,unsigned long cfg,unsigned long cbg,unsigned long style,const char* winclass){CreateWin39(x,y,w,h,cfg,cbg,style,winclass);}
void freshwin(){FreshWin47();}
void closewin(){CloseWin48();}
bool iswin(){return IsWin49();}
double gettimer(){return GetTimeR51();}
void settitlew(const short int* s){SetTitleW54(s);}
void setsize(unsigned long x,unsigned long y,unsigned long w,unsigned long h){SetSize57(x,y,w,h);}
unsigned long getwidth(){return GetWidth59();}
unsigned long getheight(){return GetHeight60();}
unsigned long getsize(){return GetSize61();}
long getscrwidth(){return GetScrWidth62();}
long getscrheight(){return GetScrHeight63();}
unsigned long getscrsize(){return GetScrSize64();}
long getbordertitle(){return GetBorderTitle67();}
long getborderwidth(){return GetBorderWidth68();}
long getborderheight(){return GetBorderHeight69();}
unsigned long getbordersize(){return GetBorderSize70();}
long getposx(){return GetPosX72();}
long getposy(){return GetPosY73();}
pbitmap getwin(){return GetWin75();}
unsigned long gethwnd(){return GetHwnd78();}
void setfont(pbitmap b){SetFont106(b);}
void setfontwidth(unsigned long w){SetFontWidth108(w);}
void setfontheight(unsigned long h){SetFontHeight109(h);}
void setfontweight(unsigned long wg){SetFontWeight111(wg);}
void setfontname(const char* s){SetFontName116(s);}
unsigned long getstringwidth(const char* s){return GetStringWidth118(s);}
void drawtextxy(pbitmap b,const short int* s,long x,long y,unsigned long w,unsigned long h,unsigned long cfg,unsigned long cbg,unsigned long format){DrawTextXY120(b,s,x,y,w,h,cfg,cbg,format);}
void drawtextxy(pbitmap b,const short int* s,long x,long y,unsigned long w,unsigned long h,unsigned long cfg,unsigned long cbg){DrawTextXY121(b,s,x,y,w,h,cfg,cbg);}
void drawtextxy(pbitmap b,const char* s,long x,long y,unsigned long w,unsigned long h,unsigned long cfg,unsigned long cbg){DrawTextXY122(b,s,x,y,w,h,cfg,cbg);}
void drawtextxy(pbitmap b,const char* s,long x,long y,unsigned long cfg,unsigned long cbg){DrawTextXY123(b,s,x,y,cfg,cbg);}
unsigned long getpixel(pbitmap b,unsigned long x,unsigned long y){return GetPixel152(b,x,y);}
void line(long x,long y,long w,long h,unsigned long c){Line160(x,y,w,h,c);}
void bar(long x,long y,long w,long h,unsigned long cfg,unsigned long cbg){Bar165(x,y,w,h,cfg,cbg);}
void bar(long x,long y,long w,long h,unsigned long c){Bar166(x,y,w,h,c);}
void clear(pbitmap b,unsigned long c){Clear168(b,c);}
void clear(unsigned long c){Clear170(c);}
pbitmap createbmp(unsigned long w,unsigned long h,unsigned long c){return CreateBMP198(w,h,c);}
pbitmap createbmp(unsigned long w,unsigned long h){return CreateBMP199(w,h);}
void releasebmp(pbitmap b){ReleaseBMP201(b);}
pbitmap loadbmp(const char* s){return LoadBMP204(s);}
void savebmp(pbitmap b,const char* s){SaveBMP205(b,s);}
void drawbmp(pbitmap bs,pbitmap bd,unsigned long xs,unsigned long ys,unsigned long ws,unsigned long hs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd){DrawBMP207(bs,bd,xs,ys,ws,hs,xd,yd,wd,hd);}
void drawbmp(pbitmap bs,pbitmap bd,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd,unsigned long c){DrawBMP210(bs,bd,xd,yd,wd,hd,c);}
void drawbmp(pbitmap bs,pbitmap bd,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd){DrawBMP211(bs,bd,xd,yd,wd,hd);}
void drawbmp(pbitmap bs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd,unsigned long c){DrawBMP220(bs,xd,yd,wd,hd,c);}
void drawbmp(pbitmap bs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd){DrawBMP221(bs,xd,yd,wd,hd);}
void drawbmp(pbitmap bs,unsigned long xd,unsigned long yd,unsigned long c){DrawBMP222(bs,xd,yd,c);}
bool isnextmsg(){return IsNextMsg261();}
bool ismsg(unsigned long uM){return IsMsg264(uM);}
bool iskey(){return IsKey268();}
unsigned long getkey(){return GetKey269();}
bool ismouseleft(){return IsMouseLeft277();}
bool ismouseright(){return IsMouseRight281();}
bool ismousemove(){return IsMouseMove286();}
long getmouseposx(){return GetMousePosX297();}
long getmouseposy(){return GetMousePosY298();}
unsigned long loadaudio(const char* s1,const char* s2){return LoadAudio299(s1,s2);}
unsigned long loadaudio(const char* s){return LoadAudio300(s);}
void stopaudio(unsigned long id){StopAudio305(id);}
unsigned long getaudiopos(unsigned long id){return GetAudioPos311(id);}
void setaudiopos(unsigned long id,unsigned long pos){SetAudioPos313(id,pos);}
unsigned long getaudiolen(unsigned long id){return GetAudioLen314(id);}

