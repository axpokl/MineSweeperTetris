#define __STDC_WANT_LIB_EXT1__ 1
#include<string.h> 
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
struct bitbuf {
	BITMAPINFO bmi;
	unsigned long len;
	void* buf;
	pbitmap bmp;
};
typedef bitbuf* pbitbuf;
class mystring
{
public:
	char s[256];
	char s0[256];
	unsigned long len;
	mystring() { len = 0; }
#ifdef __STDC_LIB_EXT1__
	mystring(const char* d) { len = strlen(d); strcpy_s(s, d); }
	mystring operator+(const char* d) { len = len+strlen(d); strcpy_s(s0, s); strcat_s(s0, d); return s0; }
#else
	mystring(const char* d) { len = strlen(d); strcpy(s, d); }
	mystring operator+(const char* d) { len = len + strlen(d); strcpy(s0, s); strcat(s0, d); return s0; }
#endif
	operator const char*() { return s; }
};
long random(long r){return ((rand()<<16)+(rand()<<1)+rand()%2)%r;}
void randomize(){srand(time(NULL)+(unsigned)clock());}
const long transparent = 0x000001;
const long black = 0x010101;
const long navy = 0x800000;
const long darkblue = 0x8b0000;
const long mediumblue = 0xcd0000;
const long blue = 0xff0000;
const long darkgreen = 0x006400;
const long green = 0x008000;
const long teal = 0x808000;
const long darkcyan = 0x8b8b00;
const long deepskyblue = 0xffbf00;
const long darkturquoise = 0xd1ce00;
const long mediumspringgreen = 0x9afa00;
const long lime = 0x00ff00;
const long springgreen = 0x7fff00;
const long cyan = 0xffff00;
const long aqua = 0xffff00;
const long midnightblue = 0x701919;
const long dodgerblue = 0xff901e;
const long lightseagreen = 0xaab220;
const long forestgreen = 0x228b22;
const long seagreen = 0x578b2e;
const long darkslategray = 0x4f4f2f;
const long limegreen = 0x32cd32;
const long mediumseagreen = 0x71b33c;
const long turquoise = 0xd0e040;
const long royalblue = 0xe16941;
const long steelblue = 0xb48246;
const long darkslateblue = 0x8b3d48;
const long mediumturquoise = 0xccd148;
const long indigo = 0x82004b;
const long darkolivegreen = 0x2f6b55;
const long cadetblue = 0xa09e5f;
const long cornflowerblue = 0xed9564;
const long mediumaquamarine = 0xaacd66;
const long dimgray = 0x696969;
const long slateblue = 0xcd5a6a;
const long olivedrab = 0x238e6b;
const long slategray = 0x908070;
const long lightslategray = 0x998877;
const long mediumslateblue = 0xee687b;
const long lawngreen = 0x00fc7c;
const long chartreuse = 0x00ff7f;
const long aquamarine = 0xd4ff7f;
const long maroon = 0x000080;
const long purple = 0x800080;
const long olive = 0x008080;
const long gray = 0x808080;
const long skyblue = 0xebce87;
const long lightskyblue = 0xface87;
const long blueviolet = 0xe22b8a;
const long darkred = 0x00008b;
const long darkmagenta = 0x8b008b;
const long saddlebrown = 0x13458b;
const long darkseagreen = 0x8fbc8f;
const long lightgreen = 0x90ee90;
const long mediumpurple = 0xdb7093;
const long darkviolet = 0xd30094;
const long palegreen = 0x98fb98;
const long darkorchid = 0xcc3299;
const long amethyst = 0xcc6699;
const long yellowgreen = 0x32cd9a;
const long sienna = 0x2d52a0;
const long brown = 0x2a2aa5;
const long darkgray = 0xa9a9a9;
const long lightblue = 0xe6d8ad;
const long greenyellow = 0x2fffad;
const long paleturquoise = 0xeeeeaf;
const long lightsteelblue = 0xdec4b0;
const long powderblue = 0xe6e0b0;
const long firebrick = 0x2222b2;
const long darkgoldenrod = 0x0b86b8;
const long mediumorchid = 0xd355ba;
const long rosybrown = 0x8f8fbc;
const long darkkhaki = 0x6bb7bd;
const long silver = 0xc0c0c0;
const long mediumvioletred = 0x8515c7;
const long indianred = 0x5c5ccd;
const long peru = 0x3f85cd;
const long chocolate = 0x1e69d2;
const long lightgrey = 0xd3d3d3;
const long thistle = 0xd8bfd8;
const long orchid = 0xd670da;
const long goldenrod = 0x20a5da;
const long palevioletred = 0x9370db;
const long crimson = 0x3c14dc;
const long gainsboro = 0xdcdcdc;
const long plum = 0xdda0dd;
const long burlywood = 0x87b8de;
const long lightcyan = 0xffffe0;
const long lavender = 0xfae6e6;
const long darksalmon = 0x7a96e9;
const long violet = 0xee82ee;
const long palegoldenrod = 0xaae8ee;
const long lightcoral = 0x8080f0;
const long khaki = 0x8ce6f0;
const long aliceblue = 0xfff8f0;
const long honeydew = 0xf0fff0;
const long azure = 0xfffff0;
const long sandybrown = 0x60a4f4;
const long wheat = 0xb3def5;
const long beige = 0xdcf5f5;
const long whitesmoke = 0xf5f5f5;
const long mintcream = 0xfafff5;
const long ghostwhite = 0xfff8f8;
const long salmon = 0x7280fa;
const long antiquewhite = 0xd7ebfa;
const long linen = 0xe6f0fa;
const long lightgoldenrodyellow = 0xd2fafa;
const long oldlace = 0xe6f5fd;
const long red = 0x0000ff;
const long fuchsia = 0xff00ff;
const long magenta = 0xff00ff;
const long deeppink = 0x9314ff;
const long orangered = 0x0045ff;
const long tomato = 0x4763ff;
const long hotpink = 0xb469ff;
const long coral = 0x507fff;
const long darkorange = 0x008cff;
const long lightsalmon = 0x7aa0ff;
const long orange = 0x00a5ff;
const long lightpink = 0xc1b6ff;
const long pink = 0xcbc0ff;
const long gold = 0x00d7ff;
const long peachpuff = 0xb9daff;
const long navajowhite = 0xaddeff;
const long moccasin = 0xb5e4ff;
const long bisque = 0xc4e4ff;
const long mistyrose = 0xe1e4ff;
const long blanchedalmond = 0xcdebff;
const long papayawhip = 0xd5efff;
const long lavenderblush = 0xf5f0ff;
const long seashell = 0xeef5ff;
const long cornsilk = 0xdcf8ff;
const long lemonchiffon = 0xcdfaff;
const long floralwhite = 0xf0faff;
const long snow = 0xfafaff;
const long yellow = 0x00ffff;
const long lightyellow = 0xe0ffff;
const long ivory = 0xf0ffff;
const long white = 0xffffff;

const byte m_left = 0;
const byte m_right = 1;
const byte m_middle = 2;

const byte k_uk = 0;
const byte k_lmouse = 1;
const byte k_rmouse = 2;
const byte k_cancel = 3;
const byte k_mmouse = 4;
const byte k_x1mouse = 5;
const byte k_x2mouse = 6;
const byte k_back = 8;
const byte k_tab = 9;
const byte k_clear = 12;
const byte k_enter = 13;
const byte k_shift = 16;
const byte k_ctrl = 17;
const byte k_alt = 18;
const byte k_pause = 19;
const byte k_caps = 20;
const byte k_esc = 27;
const byte k_space = 32;
const byte k_pgup = 33;
const byte k_pgdn = 34;
const byte k_end = 35;
const byte k_home = 36;
const byte k_left = 37;
const byte k_up = 38;
const byte k_right = 39;
const byte k_down = 40;
const byte k_select = 41;
const byte k_print = 42;
const byte k_execute = 43;
const byte k_prtsc = 44;
const byte k_ins = 45;
const byte k_del = 46;
const byte k_help = 47;
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
const byte k_lwin = 91;
const byte k_rwin = 92;
const byte k_apps = 93;
const byte k_sleep = 95;
const byte k_n0 = 96;
const byte k_n1 = 97;
const byte k_n2 = 98;
const byte k_n3 = 99;
const byte k_n4 = 100;
const byte k_n5 = 101;
const byte k_n6 = 102;
const byte k_n7 = 103;
const byte k_n8 = 104;
const byte k_n9 = 105;
const byte k_mul = 106;
const byte k_add = 107;
const byte k_sep = 108;
const byte k_sub = 109;
const byte k_dec = 110;
const byte k_div = 111;
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
const byte k_f13 = 124;
const byte k_f14 = 125;
const byte k_f15 = 126;
const byte k_f16 = 127;
const byte k_f17 = 128;
const byte k_f18 = 129;
const byte k_f19 = 130;
const byte k_f20 = 131;
const byte k_f21 = 132;
const byte k_f22 = 133;
const byte k_f23 = 134;
const byte k_f24 = 135;
const byte k_num = 144;
const byte k_scr = 145;
const byte k_lshift = 160;
const byte k_lctrl = 162;
const byte k_lalt = 164;
const byte k_rshift = 161;
const byte k_rctrl = 163;
const byte k_ralt = 165;

const double pi = 3.1415926535897932384626433832795028841971694;

const long maxchar = 0x100;                   //最大字符串长度
const long buffsize = 0x1000;                 //缓冲区大小
const long delaytimekey = 20;                 //默认按键时长      
const long delaytimedefault = 1;              //默认等待时长      
const long delaytimemin = 1;                  //默认最短等待时长
const long fontwidthdefault = 10;             //默认字体宽度      
const long fontheightdefault = 20;            //默认字体高度
const long minhz = 100;                       //最小频率      
const long maxhz = 15000;                     //最大频率
const long _bufmax = 0x100000;                //文件缓冲区大小
const long _thmax = 0x100;                    //最大线程数量
const long _mswinmax = 0x10000;               //窗口消息数目
const long _msusrmax = 0x10000;               //用户消息数目
const long _mscntmax = 0x10000;               //消息时间数目

/*
long _w,_h,_x,_y;                 //窗口宽高坐标    
unsigned long _cbg,_cfg;          //窗口背前景颜色    
unsigned long _style;             //窗口样式
unsigned long _hw;                //窗口句柄    
unsigned long _dc;                //绘图句柄   
bitmap _main;                     //缓冲位图结构    
pbitmap _pmain;                   //缓冲位图指针    
bitmap _mscr;                     //屏幕位图结构    
pbitmap _pmscr;                   //屏幕位图指针
double _tbegin;                   //窗口建立时间    
bool _winb;                       //窗口状态    
unsigned long _pe;                //画笔    
unsigned long _br;                //画刷
unsigned long _fx,_fy;            //文字输出位置    
unsigned long _fw,_fh,_fwg;       //字体长宽粗细    
unsigned long _flt,_fud,_fsk,_fcs;//字体格式  
const char* _ffn;                 //字体名称    
unsigned long _fns;               //字体结构    
unsigned long _fnm=256;           //拖拽文件名长度    
const char* _fn;                  //拖拽文件名
unsigned long _cid;               //全局音频标识符    
unsigned long _cam=256;           //音频字符串长度    
const char* _ca;                  //音频字符串
unsigned long _fhdl;              //文件句柄    
unsigned long _fpos;              //文件指针位置    
unsigned long _flen;              //文件长度
*/

extern "C" long sgn1(double x);
extern "C" double abs2(double a,double b);
extern "C" double abs3(double a,double b,double c);
extern "C" double arcsin4(double x);
extern "C" double arccos5(double x);
extern "C" double arctan26(double x,double y);
extern "C" const char* i2s7(long i);
extern "C" unsigned long s2i8(const char* s);
extern "C" unsigned char as2i9(const char* s);
extern "C" char i2hc10(unsigned char i);
extern "C" unsigned char hc2i11(char c);
extern "C" const char* i2hs12(unsigned char i);
extern "C" unsigned char hs2i13(const char* s);
extern "C" const char* as2hs14(const char* s);
extern "C" const char* hs2as15(const char* s);
extern "C" const char* i2as16(unsigned long i);
extern "C" const char* i2hs17(unsigned long i);
extern "C" unsigned long NewThread18(void* th);
extern "C" void PauseThread19(unsigned long thi);
extern "C" void ResumeThread20(unsigned long thi);
extern "C" void StopThread21(unsigned long thi);
extern "C" unsigned long MsgBoxW22(const short int* s,const short int* title,unsigned long i);
extern "C" unsigned long MsgBox23(const char* s,const char* title,unsigned long i);
extern "C" void MsgBoxW24(const short int* s,const short int* title);
extern "C" void MsgBox25(const char* s,const char* title);
extern "C" void MsgBoxW26(const short int* s);
extern "C" void MsgBox27(const char* s);
extern "C" void Delay28(unsigned long t);
extern "C" void Delay29();
extern "C" void Sound30(unsigned long hz,unsigned long t);
extern "C" void Sound31(unsigned long hz,double t);
extern "C" void Sound32(unsigned long hz);
extern "C" void FreshFPS33();
extern "C" void AddFPS34();
extern "C" unsigned long GetFPSL35();
extern "C" double GetFPSR36();
extern "C" unsigned long GetFPS37();
extern "C" unsigned long GetError38();
extern "C" void CreateWin39(unsigned long w,unsigned long h,unsigned long cfg,unsigned long cbg,unsigned long style,const char* winclass);
extern "C" void CreateWin40(unsigned long w,unsigned long h,unsigned long cfg,unsigned long cbg,unsigned long style);
extern "C" void CreateWin41(unsigned long w,unsigned long h,unsigned long cfg,unsigned long cbg);
extern "C" void CreateWin42(unsigned long w,unsigned long h,unsigned long c);
extern "C" void CreateWin43(unsigned long w,unsigned long h);
extern "C" void CreateWin44(unsigned long cbg);
extern "C" void CreateWin45();
extern "C" void FreshWin46();
extern "C" void CloseWin47();
extern "C" bool IsWin48();
extern "C" void SetDrawProcedure49(void* th);
extern "C" double GetTimeR50();
extern "C" unsigned long GetTime51();
extern "C" void SetTitle52(const char* s);
extern "C" void SetTitleW53(const short int* s);
extern "C" const char* GetTitle54();
extern "C" const short int* GetTitleW55();
extern "C" void SetSize56(unsigned long w,unsigned long h);
extern "C" unsigned long GetWidth57();
extern "C" unsigned long GetHeight58();
extern "C" unsigned long GetSize59();
extern "C" long GetScrWidth60();
extern "C" long GetScrHeight61();
extern "C" unsigned long GetScrSize62();
extern "C" double GetScrCapsX63();
extern "C" double GetScrCapsY64();
extern "C" long GetBorderTitle65();
extern "C" long GetBorderWidth66();
extern "C" long GetBorderHeight67();
extern "C" unsigned long GetBorderSize68();
extern "C" void SetPos69(unsigned long x,unsigned long y);
extern "C" long GetPosX70();
extern "C" long GetPosY71();
extern "C" unsigned long GetPos72();
extern "C" pbitmap GetWin73();
extern "C" pbitmap GetScr74();
extern "C" unsigned long GetHwnd75(pbitmap b);
extern "C" unsigned long GetHwnd76();
extern "C" unsigned long GetDraw77(pbitmap b);
extern "C" unsigned long GetDraw78();
extern "C" unsigned long GetBGColor79();
extern "C" void SetBGColor80(unsigned long c);
extern "C" unsigned long GetFGColor81();
extern "C" void SetFGColor82(unsigned long c);
extern "C" void SetPenWidth83(unsigned long pew);
extern "C" void SetPenColor84(pbitmap b,unsigned long c);
extern "C" void SetPenColor85(unsigned long c);
extern "C" void SetBrushColor86(pbitmap b,unsigned long c);
extern "C" void SetBrushColor87(unsigned long c);
extern "C" unsigned char GetAlpha88(unsigned long c);
extern "C" unsigned char GetBlue89(unsigned long c);
extern "C" unsigned char GetGreen90(unsigned long c);
extern "C" unsigned char GetRed91(unsigned long c);
extern "C" unsigned long GetRGBA92(unsigned char r,unsigned char g,unsigned char b,unsigned char a);
extern "C" unsigned long GetRGB93(unsigned char r,unsigned char g,unsigned char b);
extern "C" unsigned long RGB2HSL94(unsigned long rgb);
extern "C" unsigned long RGB2HSV95(unsigned long rgb);
extern "C" unsigned long RGB2HSI96(unsigned long rgb);
extern "C" unsigned long RGB2HSN97(unsigned long rgb);
extern "C" unsigned long HSL2RGB98(unsigned long hsn);
extern "C" unsigned long HSV2RGB99(unsigned long hsn);
extern "C" unsigned long HSI2RGB100(unsigned long hsn);
extern "C" unsigned long HSN2RGB101(unsigned long hsn);
extern "C" void MixColor102(unsigned long rgb1,unsigned long rgb2,unsigned long rgb3,double m);
extern "C" void MixColor103(unsigned long rgb1,unsigned long rgb2,unsigned long rgb3);
extern "C" void SetFont104(pbitmap b);
extern "C" void SetFont105();
extern "C" void SetFontWidth106(unsigned long w);
extern "C" void SetFontHeight107(unsigned long h);
extern "C" void SetFontSize108(unsigned long w,unsigned long h);
extern "C" void SetFontWeight109(unsigned long wg);
extern "C" void SetFontLtalic110(unsigned long lt);
extern "C" void SetFontUnderLine111(unsigned long ud);
extern "C" void SetFontStrikeOut112(unsigned long sk);
extern "C" void SetFontCharSet113(unsigned long cs);
extern "C" void SetFontName114(const char* s);
extern "C" void GetStringSize115(const char* s);
extern "C" unsigned long GetStringWidth116(const char* s);
extern "C" unsigned long GetStringHeight117(const char* s);
extern "C" void DrawTextXY118(pbitmap b,const short int* s,long x,long y,unsigned long w,unsigned long h,unsigned long cfg,unsigned long cbg,unsigned long format);
extern "C" void DrawTextXY119(pbitmap b,const short int* s,long x,long y,unsigned long w,unsigned long h,unsigned long cfg,unsigned long cbg);
extern "C" void DrawTextXY120(pbitmap b,const char* s,long x,long y,unsigned long w,unsigned long h,unsigned long cfg,unsigned long cbg);
extern "C" void DrawTextXY121(pbitmap b,const char* s,long x,long y,unsigned long cfg,unsigned long cbg);
extern "C" void DrawTextXY122(pbitmap b,const char* s,long x,long y,unsigned long cfg);
extern "C" void DrawTextXY123(const char* s,long x,long y,unsigned long cfg,unsigned long cbg);
extern "C" void DrawTextXY124(const char* s,long x,long y,unsigned long cfg);
extern "C" void DrawTextXY125(const char* s,unsigned long x,unsigned long y);
extern "C" void DrawText126(const char* s,unsigned long cfg,unsigned long cbg);
extern "C" void DrawText127(const char* s,unsigned long cfg);
extern "C" void DrawText128(const char* s);
extern "C" void DrawTextlnXY129(const char* s,long x,long y,unsigned long cfg,unsigned long cbg);
extern "C" void DrawTextlnXY130(const char* s,long x,long y,unsigned long cfg);
extern "C" void DrawTextlnXY131(const char* s,unsigned long x,unsigned long y);
extern "C" void DrawTextln132(const char* s,unsigned long cfg,unsigned long cbg);
extern "C" void DrawTextln133(const char* s,unsigned long cfg);
extern "C" void DrawTextln134(const char* s);
extern "C" void DrawTextln135();
extern "C" void DrawTextXYw136(pbitmap b,const char* s,long x,long y,unsigned long cfg,unsigned long cbg);
extern "C" void DrawTextXYw137(pbitmap b,const char* s,long x,long y,unsigned long cfg);
extern "C" void DrawTextXYw138(const char* s,long x,long y,unsigned long cfg,unsigned long cbg);
extern "C" void DrawTextXYw139(const char* s,long x,long y,unsigned long cfg);
extern "C" void DrawTextXYw140(const char* s,unsigned long x,unsigned long y);
extern "C" void DrawTextw141(const char* s,unsigned long cfg,unsigned long cbg);
extern "C" void DrawTextw142(const char* s,unsigned long cfg);
extern "C" void DrawTextw143(const char* s);
extern "C" void DrawTextlnXYw144(const char* s,long x,long y,unsigned long cfg,unsigned long cbg);
extern "C" void DrawTextlnXYw145(const char* s,long x,long y,unsigned long cfg);
extern "C" void DrawTextlnXYw146(const char* s,unsigned long x,unsigned long y);
extern "C" void DrawTextlnw147(const char* s,unsigned long cfg,unsigned long cbg);
extern "C" void DrawTextlnw148(const char* s,unsigned long cfg);
extern "C" void DrawTextlnw149(const char* s);
extern "C" unsigned long GetPixel150(pbitmap b,unsigned long x,unsigned long y);
extern "C" unsigned long GetPixel151(unsigned long x,unsigned long y);
extern "C" void SetPixel152(pbitmap b,unsigned long x,unsigned long y,unsigned long c);
extern "C" void SetPixel153(unsigned long x,unsigned long y,unsigned long c);
extern "C" void SetPixel154(unsigned long x,unsigned long y);
extern "C" unsigned long GetBBPixel155(pbitbuf bb,unsigned long x,unsigned long y);
extern "C" void SetBBPixel156(pbitbuf bb,unsigned long x,unsigned long y,unsigned long c);
extern "C" void Line157(pbitmap b,long x,long y,long w,long h,unsigned long c);
extern "C" void Line158(long x,long y,long w,long h,unsigned long c);
extern "C" void Line159(long x,long y,long w,long h);
extern "C" void LineBB160(pbitbuf bb,long x,long y,long w,long h,unsigned long c);
extern "C" void Bar161(pbitmap b,long x,long y,long w,long h,unsigned long cfg,unsigned long cbg);
extern "C" void Bar162(pbitmap b,long x,long y,long w,long h,unsigned long c);
extern "C" void Bar163(long x,long y,long w,long h,unsigned long cfg,unsigned long cbg);
extern "C" void Bar164(long x,long y,long w,long h,unsigned long c);
extern "C" void Bar165(long x,long y,long w,long h);
extern "C" void Clear166(pbitmap b,unsigned long c);
extern "C" void Clear167(pbitmap b);
extern "C" void Clear168(unsigned long c);
extern "C" void Clear169();
extern "C" void Triangle170(pbitmap b,long x1,long y1,long x2,long y2,long x3,long y3,unsigned long cfg,unsigned long cbg);
extern "C" void Triangle171(long x1,long y1,long x2,long y2,long x3,long y3,unsigned long cfg,unsigned long cbg);
extern "C" void Triangle172(long x1,long y1,long x2,long y2,long x3,long y3,unsigned long c);
extern "C" void Triangle173(long x1,long y1,long x2,long y2,long x3,long y3);
extern "C" void Arc174(pbitmap b,long x,long y,long rx,long ry,double sa,double ea,unsigned long cfg,unsigned long cbg);
extern "C" void Arc175(long x,long y,long rx,long ry,double sa,double ea,unsigned long cfg,unsigned long cbg);
extern "C" void Arc176(long x,long y,long rx,long ry,double sa,double ea,unsigned long c);
extern "C" void Arc177(long x,long y,long rx,long ry,double sa,double ea);
extern "C" void Pie178(pbitmap b,long x,long y,long rx,long ry,double sa,double ea,unsigned long cfg,unsigned long cbg);
extern "C" void Pie179(long x,long y,long rx,long ry,double sa,double ea,unsigned long cfg,unsigned long cbg);
extern "C" void Pie180(long x,long y,long rx,long ry,double sa,double ea,unsigned long c);
extern "C" void Pie181(long x,long y,long rx,long ry,double sa,double ea);
extern "C" void Chord182(pbitmap b,long x,long y,long rx,long ry,double sa,double ea,unsigned long cfg,unsigned long cbg);
extern "C" void Chord183(long x,long y,long rx,long ry,double sa,double ea,unsigned long cfg,unsigned long cbg);
extern "C" void Chord184(long x,long y,long rx,long ry,double sa,double ea,unsigned long c);
extern "C" void Chord185(long x,long y,long rx,long ry,double sa,double ea);
extern "C" void Ellipse186(pbitmap b,long x,long y,long rx,long ry,unsigned long cfg,unsigned long cbg);
extern "C" void Ellipse187(long x,long y,long rx,long ry,unsigned long cfg,unsigned long cbg);
extern "C" void Ellipse188(long x,long y,long rx,long ry,unsigned long c);
extern "C" void Ellipse189(long x,long y,long rx,long ry);
extern "C" void Circle190(pbitmap b,long x,long y,long r,unsigned long cfg,unsigned long cbg);
extern "C" void Circle191(long x,long y,long r,unsigned long cfg,unsigned long cbg);
extern "C" void Circle192(long x,long y,long r,unsigned long c);
extern "C" void Circle193(long x,long y,long r);
extern "C" pbitmap CreateBMP194(pbitmap b,unsigned long w,unsigned long h,unsigned long c);
extern "C" pbitmap CreateBMP195(pbitmap b);
extern "C" pbitmap CreateBMP196(unsigned long w,unsigned long h,unsigned long c);
extern "C" pbitmap CreateBMP197(unsigned long w,unsigned long h);
extern "C" pbitmap CreateBMP198();
extern "C" void ReleaseBMP199(pbitmap b);
extern "C" void ReleaseBMP200();
extern "C" pbitmap LoadBMP201(const char* s,unsigned long c);
extern "C" pbitmap LoadBMP202(const char* s);
extern "C" void SaveBMP203(pbitmap b,const char* s);
extern "C" void DrawBMP204(pbitmap bs,pbitmap bd,unsigned long xs,unsigned long ys,unsigned long ws,unsigned long hs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd,unsigned long c);
extern "C" void DrawBMP205(pbitmap bs,pbitmap bd,unsigned long xs,unsigned long ys,unsigned long ws,unsigned long hs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd);
extern "C" void DrawBMP206(pbitmap bs,pbitmap bd,unsigned long xs,unsigned long ys,unsigned long xd,unsigned long yd,unsigned long w,unsigned long h,unsigned long c);
extern "C" void DrawBMP207(pbitmap bs,pbitmap bd,unsigned long xs,unsigned long ys,unsigned long xd,unsigned long yd,unsigned long w,unsigned long h);
extern "C" void DrawBMP208(pbitmap bs,pbitmap bd,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd,unsigned long c);
extern "C" void DrawBMP209(pbitmap bs,pbitmap bd,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd);
extern "C" void DrawBMP210(pbitmap bs,pbitmap bd,unsigned long xd,unsigned long yd,unsigned long c);
extern "C" void DrawBMP211(pbitmap bs,pbitmap bd,unsigned long xd,unsigned long yd);
extern "C" void DrawBMP212(pbitmap bs,pbitmap bd,unsigned long c);
extern "C" void DrawBMP213(pbitmap bs,pbitmap bd);
extern "C" void DrawBMP214(pbitmap bs,unsigned long xs,unsigned long ys,unsigned long ws,unsigned long hs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd,unsigned long c);
extern "C" void DrawBMP215(pbitmap bs,unsigned long xs,unsigned long ys,unsigned long ws,unsigned long hs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd);
extern "C" void DrawBMP216(pbitmap bs,unsigned long xs,unsigned long ys,unsigned long xd,unsigned long yd,unsigned long w,unsigned long h,unsigned long c);
extern "C" void DrawBMP217(pbitmap bs,unsigned long xs,unsigned long ys,unsigned long xd,unsigned long yd,unsigned long w,unsigned long h);
extern "C" void DrawBMP218(pbitmap bs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd,unsigned long c);
extern "C" void DrawBMP219(pbitmap bs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd);
extern "C" void DrawBMP220(pbitmap bs,unsigned long xd,unsigned long yd,unsigned long c);
extern "C" void DrawBMP221(pbitmap bs,unsigned long xd,unsigned long yd);
extern "C" void DrawBMP222(pbitmap bs,unsigned long c);
extern "C" void DrawBMP223(pbitmap bs);
extern "C" void DrawBMP224(unsigned long xs,unsigned long ys,unsigned long ws,unsigned long hs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd,unsigned long c);
extern "C" void DrawBMP225(unsigned long xs,unsigned long ys,unsigned long ws,unsigned long hs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd);
extern "C" void DrawBMP226(unsigned long xs,unsigned long ys,unsigned long xd,unsigned long yd,unsigned long w,unsigned long h,unsigned long c);
extern "C" void DrawBMP227(unsigned long xs,unsigned long ys,unsigned long xd,unsigned long yd,unsigned long w,unsigned long h);
extern "C" void DrawBMP228(unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd,unsigned long c);
extern "C" void DrawBMP229(unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd);
extern "C" void DrawBMP230(unsigned long xd,unsigned long yd,unsigned long c);
extern "C" void DrawBMP231(unsigned long xd,unsigned long yd);
extern "C" void DrawBMP232(unsigned long c);
extern "C" void DrawBMP233();
extern "C" void MixBMP234(pbitmap b1,pbitmap b2,pbitmap b3);
extern "C" void BlurBMPBox235(pbitmap b,unsigned long d,unsigned long n);
extern "C" void BlurBMPBox236(pbitmap b,unsigned long d);
extern "C" void BlurBMPGau237(pbitmap b,double d);
extern "C" pbitbuf CreateBB238(pbitmap b);
extern "C" void ReleaseBB239(pbitbuf bb);
extern "C" void GetBB240(pbitbuf bb);
extern "C" void SetBB241(pbitbuf bb);
extern "C" void MixBB242(pbitbuf bb1,pbitbuf bb2,pbitbuf bb3);
extern "C" void BlurBBBox243(pbitbuf bb,unsigned long d,unsigned long n);
extern "C" void BlurBBGau244(pbitbuf bb,double d);
extern "C" void PressKey245(unsigned char k,unsigned long t);
extern "C" void PressKey246(unsigned char k);
extern "C" void DownKey247(unsigned char k);
extern "C" void UpKey248(unsigned char k);
extern "C" void PressMouse249(unsigned char m,unsigned long t);
extern "C" void PressMouse250(unsigned char m);
extern "C" void DownMouse251(unsigned char m);
extern "C" void UpMouse252(unsigned char m);
extern "C" void WheelMouse253(long wl);
extern "C" void MoveMouse254(long x,long y);
extern "C" void MoveMouseAbs255(long x,long y);
extern "C" void MoveMouseWin256(long x,long y);
extern "C" void MoveMousePos257(long x,long y);
extern "C" void SendMsg258();
extern "C" bool IsNextMsg259();
extern "C" unsigned long GetNextMsg260();
extern "C" unsigned long WaitNextMsg261();
extern "C" bool IsMsg262(unsigned long uM);
extern "C" long long GetMsg263(unsigned long uM);
extern "C" long long WaitMsg264(unsigned long uM);
extern "C" bool IsKey265(unsigned long k);
extern "C" bool IsKey266();
extern "C" unsigned long GetKey267();
extern "C" unsigned long WaitKey268(unsigned long k);
extern "C" unsigned long WaitKey269();
extern "C" bool IsMouse270(unsigned long m);
extern "C" bool IsMouse271();
extern "C" unsigned long GetMouse272();
extern "C" unsigned long WaitMouse273(unsigned long m);
extern "C" unsigned long WaitMouse274();
extern "C" bool IsMouseLeft275();
extern "C" void WaitMouseLeft276();
extern "C" bool IsMouseMiddle277();
extern "C" void WaitMouseMiddle278();
extern "C" bool IsMouseRight279();
extern "C" void WaitMouseRight280();
extern "C" bool IsMouseWheel281();
extern "C" long GetMouseWheel282();
extern "C" void WaitMouseWheel283();
extern "C" bool IsMouseMove284();
extern "C" unsigned long GetMouseMove285();
extern "C" unsigned long WaitMouseMove286();
extern "C" bool IsDropFile287();
extern "C" const char* GetDropFile288();
extern "C" const short int* GetDropFileW289();
extern "C" const char* WaitDropFile290();
extern "C" long GetMouseAbsX291();
extern "C" long GetMouseAbsY292();
extern "C" long GetMouseWinX293();
extern "C" long GetMouseWinY294();
extern "C" long GetMousePosX295();
extern "C" long GetMousePosY296();
extern "C" unsigned long LoadAudio297(const char* s1,const char* s2);
extern "C" unsigned long LoadAudio298(const char* s);
extern "C" void PlayAudio299(unsigned long id,const char* s,bool b);
extern "C" void PlayAudio300(unsigned long id,const char* s);
extern "C" void PlayAudio301(unsigned long id,bool b);
extern "C" void PlayAudio302(unsigned long id);
extern "C" void StopAudio303(unsigned long id);
extern "C" void PauseAudio304(unsigned long id);
extern "C" void ResumeAudio305(unsigned long id);
extern "C" void ReleaseAudio306(unsigned long id);
extern "C" unsigned long GetAudioVol307(unsigned long id);
extern "C" void SetAudioVol308(unsigned long id,unsigned long v);
extern "C" unsigned long GetAudioPos309(unsigned long id);
extern "C" void SetAudioPos310(unsigned long id,unsigned long pos,bool b);
extern "C" void SetAudioPos311(unsigned long id,unsigned long pos);
extern "C" unsigned long GetAudioLen312(unsigned long id);
extern "C" bool IsFile313(const char* s);
extern "C" bool IsFileW314(const short int* s);
extern "C" bool NewFile315(const char* s);
extern "C" bool NewDir316(const char* s);
extern "C" bool CopyFile317(const char* src,const char* des);
extern "C" bool MoveFile318(const char* src,const char* des);
extern "C" bool DeleteFile319(const char* s);
extern "C" const char* GetFileName320(const char* s);
extern "C" const short int* GetFileNameW321(const short int* s);
extern "C" const char* GetFileDir322(const char* s);
extern "C" const short int* GetFileDirW323(const short int* s);
extern "C" void OpenFile324(const char* s);
extern "C" void OpenFileW325(const short int* s);
extern "C" void CloseFile326();
extern "C" unsigned long GetFileLen327();
extern "C" unsigned long GetFilePos328();
extern "C" void SetFilePos329(unsigned long pos);
extern "C" unsigned char GetByte330();
extern "C" unsigned short GetWord331();
extern "C" unsigned long GetLongword332();
extern "C" unsigned long GetInteger333();
extern "C" const char* GetPchar334();
extern "C" const char* GetString335(unsigned long len);
extern "C" const char* GetPara336();
extern "C" const char* GetPara337(unsigned long n);
extern "C" const short int* GetParaW338();
extern "C" const short int* GetParaW339(unsigned long n);

long sgn(double x){return sgn1(x);}
double abs(double a,double b){return abs2(a,b);}
double abs(double a,double b,double c){return abs3(a,b,c);}
double arcsin(double x){return arcsin4(x);}
double arccos(double x){return arccos5(x);}
double arctan2(double x,double y){return arctan26(x,y);}
mystring i2s(long i){return i2s7(i);}
unsigned long s2i(const char* s){return s2i8(s);}
unsigned char as2i(const char* s){return as2i9(s);}
char i2hc(unsigned char i){return i2hc10(i);}
unsigned char hc2i(char c){return hc2i11(c);}
mystring i2hs(unsigned char i){return i2hs12(i);}
unsigned char hs2i(const char* s){return hs2i13(s);}
mystring as2hs(const char* s){return as2hs14(s);}
mystring hs2as(const char* s){return hs2as15(s);}
mystring i2as(unsigned long i){return i2as16(i);}
mystring i2hs(unsigned long i){return i2hs17(i);}
unsigned long newthread(void* th){return NewThread18(th);}
void pausethread(unsigned long thi){PauseThread19(thi);}
void resumethread(unsigned long thi){ResumeThread20(thi);}
void stopthread(unsigned long thi){StopThread21(thi);}
unsigned long msgboxw(const short int* s,const short int* title,unsigned long i){return MsgBoxW22(s,title,i);}
unsigned long msgbox(const char* s,const char* title,unsigned long i){return MsgBox23(s,title,i);}
void msgboxw(const short int* s,const short int* title){MsgBoxW24(s,title);}
void msgbox(const char* s,const char* title){MsgBox25(s,title);}
void msgboxw(const short int* s){MsgBoxW26(s);}
void msgbox(const char* s){MsgBox27(s);}
void delay(unsigned long t){Delay28(t);}
void delay(){Delay29();}
void sound(unsigned long hz,unsigned long t){Sound30(hz,t);}
void sound(unsigned long hz,double t){Sound31(hz,t);}
void sound(unsigned long hz){Sound32(hz);}
void freshfps(){FreshFPS33();}
void addfps(){AddFPS34();}
unsigned long getfpsl(){return GetFPSL35();}
double getfpsr(){return GetFPSR36();}
unsigned long getfps(){return GetFPS37();}
unsigned long geterror(){return GetError38();}
void createwin(unsigned long w,unsigned long h,unsigned long cfg,unsigned long cbg,unsigned long style,const char* winclass){CreateWin39(w,h,cfg,cbg,style,winclass);}
void createwin(unsigned long w,unsigned long h,unsigned long cfg,unsigned long cbg,unsigned long style){CreateWin40(w,h,cfg,cbg,style);}
void createwin(unsigned long w,unsigned long h,unsigned long cfg,unsigned long cbg){CreateWin41(w,h,cfg,cbg);}
void createwin(unsigned long w,unsigned long h,unsigned long c){CreateWin42(w,h,c);}
void createwin(unsigned long w,unsigned long h){CreateWin43(w,h);}
void createwin(unsigned long cbg){CreateWin44(cbg);}
void createwin(){CreateWin45();}
void freshwin(){FreshWin46();}
void closewin(){CloseWin47();}
bool iswin(){return IsWin48();}
void setdrawprocedure(void* th){SetDrawProcedure49(th);}
double gettimer(){return GetTimeR50();}
unsigned long gettime(){return GetTime51();}
void settitle(const char* s){SetTitle52(s);}
void settitlew(const short int* s){SetTitleW53(s);}
mystring gettitle(){return GetTitle54();}
const short int* gettitlew(){return GetTitleW55();}
void setsize(unsigned long w,unsigned long h){SetSize56(w,h);}
unsigned long getwidth(){return GetWidth57();}
unsigned long getheight(){return GetHeight58();}
unsigned long getsize(){return GetSize59();}
long getscrwidth(){return GetScrWidth60();}
long getscrheight(){return GetScrHeight61();}
unsigned long getscrsize(){return GetScrSize62();}
double getscrcapsx(){return GetScrCapsX63();}
double getscrcapsy(){return GetScrCapsY64();}
long getbordertitle(){return GetBorderTitle65();}
long getborderwidth(){return GetBorderWidth66();}
long getborderheight(){return GetBorderHeight67();}
unsigned long getbordersize(){return GetBorderSize68();}
void setpos(unsigned long x,unsigned long y){SetPos69(x,y);}
long getposx(){return GetPosX70();}
long getposy(){return GetPosY71();}
unsigned long getpos(){return GetPos72();}
pbitmap getwin(){return GetWin73();}
pbitmap getscr(){return GetScr74();}
unsigned long gethwnd(pbitmap b){return GetHwnd75(b);}
unsigned long gethwnd(){return GetHwnd76();}
unsigned long getdraw(pbitmap b){return GetDraw77(b);}
unsigned long getdraw(){return GetDraw78();}
unsigned long getbgcolor(){return GetBGColor79();}
void setbgcolor(unsigned long c){SetBGColor80(c);}
unsigned long getfgcolor(){return GetFGColor81();}
void setfgcolor(unsigned long c){SetFGColor82(c);}
void setpenwidth(unsigned long pew){SetPenWidth83(pew);}
void setpencolor(pbitmap b,unsigned long c){SetPenColor84(b,c);}
void setpencolor(unsigned long c){SetPenColor85(c);}
void setbrushcolor(pbitmap b,unsigned long c){SetBrushColor86(b,c);}
void setbrushcolor(unsigned long c){SetBrushColor87(c);}
unsigned char getalpha(unsigned long c){return GetAlpha88(c);}
unsigned char getblue(unsigned long c){return GetBlue89(c);}
unsigned char getgreen(unsigned long c){return GetGreen90(c);}
unsigned char getred(unsigned long c){return GetRed91(c);}
unsigned long getrgba(unsigned char r,unsigned char g,unsigned char b,unsigned char a){return GetRGBA92(r,g,b,a);}
unsigned long getrgb(unsigned char r,unsigned char g,unsigned char b){return GetRGB93(r,g,b);}
unsigned long rgb2hsl(unsigned long rgb){return RGB2HSL94(rgb);}
unsigned long rgb2hsv(unsigned long rgb){return RGB2HSV95(rgb);}
unsigned long rgb2hsi(unsigned long rgb){return RGB2HSI96(rgb);}
unsigned long rgb2hsn(unsigned long rgb){return RGB2HSN97(rgb);}
unsigned long hsl2rgb(unsigned long hsn){return HSL2RGB98(hsn);}
unsigned long hsv2rgb(unsigned long hsn){return HSV2RGB99(hsn);}
unsigned long hsi2rgb(unsigned long hsn){return HSI2RGB100(hsn);}
unsigned long hsn2rgb(unsigned long hsn){return HSN2RGB101(hsn);}
void mixcolor(unsigned long rgb1,unsigned long rgb2,unsigned long rgb3,double m){MixColor102(rgb1,rgb2,rgb3,m);}
void mixcolor(unsigned long rgb1,unsigned long rgb2,unsigned long rgb3){MixColor103(rgb1,rgb2,rgb3);}
void setfont(pbitmap b){SetFont104(b);}
void setfont(){SetFont105();}
void setfontwidth(unsigned long w){SetFontWidth106(w);}
void setfontheight(unsigned long h){SetFontHeight107(h);}
void setfontsize(unsigned long w,unsigned long h){SetFontSize108(w,h);}
void setfontweight(unsigned long wg){SetFontWeight109(wg);}
void setfontltalic(unsigned long lt){SetFontLtalic110(lt);}
void setfontunderline(unsigned long ud){SetFontUnderLine111(ud);}
void setfontstrikeout(unsigned long sk){SetFontStrikeOut112(sk);}
void setfontcharset(unsigned long cs){SetFontCharSet113(cs);}
void setfontname(const char* s){SetFontName114(s);}
void getstringsize(const char* s){GetStringSize115(s);}
unsigned long getstringwidth(const char* s){return GetStringWidth116(s);}
unsigned long getstringheight(const char* s){return GetStringHeight117(s);}
void drawtextxy(pbitmap b,const short int* s,long x,long y,unsigned long w,unsigned long h,unsigned long cfg,unsigned long cbg,unsigned long format){DrawTextXY118(b,s,x,y,w,h,cfg,cbg,format);}
void drawtextxy(pbitmap b,const short int* s,long x,long y,unsigned long w,unsigned long h,unsigned long cfg,unsigned long cbg){DrawTextXY119(b,s,x,y,w,h,cfg,cbg);}
void drawtextxy(pbitmap b,const char* s,long x,long y,unsigned long w,unsigned long h,unsigned long cfg,unsigned long cbg){DrawTextXY120(b,s,x,y,w,h,cfg,cbg);}
void drawtextxy(pbitmap b,const char* s,long x,long y,unsigned long cfg,unsigned long cbg){DrawTextXY121(b,s,x,y,cfg,cbg);}
void drawtextxy(pbitmap b,const char* s,long x,long y,unsigned long cfg){DrawTextXY122(b,s,x,y,cfg);}
void drawtextxy(const char* s,long x,long y,unsigned long cfg,unsigned long cbg){DrawTextXY123(s,x,y,cfg,cbg);}
void drawtextxy(const char* s,long x,long y,unsigned long cfg){DrawTextXY124(s,x,y,cfg);}
void drawtextxy(const char* s,unsigned long x,unsigned long y){DrawTextXY125(s,x,y);}
void drawtext(const char* s,unsigned long cfg,unsigned long cbg){DrawText126(s,cfg,cbg);}
void drawtext(const char* s,unsigned long cfg){DrawText127(s,cfg);}
void drawtext(const char* s){DrawText128(s);}
void drawtextlnxy(const char* s,long x,long y,unsigned long cfg,unsigned long cbg){DrawTextlnXY129(s,x,y,cfg,cbg);}
void drawtextlnxy(const char* s,long x,long y,unsigned long cfg){DrawTextlnXY130(s,x,y,cfg);}
void drawtextlnxy(const char* s,unsigned long x,unsigned long y){DrawTextlnXY131(s,x,y);}
void drawtextln(const char* s,unsigned long cfg,unsigned long cbg){DrawTextln132(s,cfg,cbg);}
void drawtextln(const char* s,unsigned long cfg){DrawTextln133(s,cfg);}
void drawtextln(const char* s){DrawTextln134(s);}
void drawtextln(){DrawTextln135();}
void drawtextxyw(pbitmap b,const char* s,long x,long y,unsigned long cfg,unsigned long cbg){DrawTextXYw136(b,s,x,y,cfg,cbg);}
void drawtextxyw(pbitmap b,const char* s,long x,long y,unsigned long cfg){DrawTextXYw137(b,s,x,y,cfg);}
void drawtextxyw(const char* s,long x,long y,unsigned long cfg,unsigned long cbg){DrawTextXYw138(s,x,y,cfg,cbg);}
void drawtextxyw(const char* s,long x,long y,unsigned long cfg){DrawTextXYw139(s,x,y,cfg);}
void drawtextxyw(const char* s,unsigned long x,unsigned long y){DrawTextXYw140(s,x,y);}
void drawtextw(const char* s,unsigned long cfg,unsigned long cbg){DrawTextw141(s,cfg,cbg);}
void drawtextw(const char* s,unsigned long cfg){DrawTextw142(s,cfg);}
void drawtextw(const char* s){DrawTextw143(s);}
void drawtextlnxyw(const char* s,long x,long y,unsigned long cfg,unsigned long cbg){DrawTextlnXYw144(s,x,y,cfg,cbg);}
void drawtextlnxyw(const char* s,long x,long y,unsigned long cfg){DrawTextlnXYw145(s,x,y,cfg);}
void drawtextlnxyw(const char* s,unsigned long x,unsigned long y){DrawTextlnXYw146(s,x,y);}
void drawtextlnw(const char* s,unsigned long cfg,unsigned long cbg){DrawTextlnw147(s,cfg,cbg);}
void drawtextlnw(const char* s,unsigned long cfg){DrawTextlnw148(s,cfg);}
void drawtextlnw(const char* s){DrawTextlnw149(s);}
unsigned long getpixel(pbitmap b,unsigned long x,unsigned long y){return GetPixel150(b,x,y);}
unsigned long getpixel(unsigned long x,unsigned long y){return GetPixel151(x,y);}
void setpixel(pbitmap b,unsigned long x,unsigned long y,unsigned long c){SetPixel152(b,x,y,c);}
void setpixel(unsigned long x,unsigned long y,unsigned long c){SetPixel153(x,y,c);}
void setpixel(unsigned long x,unsigned long y){SetPixel154(x,y);}
unsigned long getbbpixel(pbitbuf bb,unsigned long x,unsigned long y){return GetBBPixel155(bb,x,y);}
void setbbpixel(pbitbuf bb,unsigned long x,unsigned long y,unsigned long c){SetBBPixel156(bb,x,y,c);}
void line(pbitmap b,long x,long y,long w,long h,unsigned long c){Line157(b,x,y,w,h,c);}
void line(long x,long y,long w,long h,unsigned long c){Line158(x,y,w,h,c);}
void line(long x,long y,long w,long h){Line159(x,y,w,h);}
void linebb(pbitbuf bb,long x,long y,long w,long h,unsigned long c){LineBB160(bb,x,y,w,h,c);}
void bar(pbitmap b,long x,long y,long w,long h,unsigned long cfg,unsigned long cbg){Bar161(b,x,y,w,h,cfg,cbg);}
void bar(pbitmap b,long x,long y,long w,long h,unsigned long c){Bar162(b,x,y,w,h,c);}
void bar(long x,long y,long w,long h,unsigned long cfg,unsigned long cbg){Bar163(x,y,w,h,cfg,cbg);}
void bar(long x,long y,long w,long h,unsigned long c){Bar164(x,y,w,h,c);}
void bar(long x,long y,long w,long h){Bar165(x,y,w,h);}
void clear(pbitmap b,unsigned long c){Clear166(b,c);}
void clear(pbitmap b){Clear167(b);}
void clear(unsigned long c){Clear168(c);}
void clear(){Clear169();}
void triangle(pbitmap b,long x1,long y1,long x2,long y2,long x3,long y3,unsigned long cfg,unsigned long cbg){Triangle170(b,x1,y1,x2,y2,x3,y3,cfg,cbg);}
void triangle(long x1,long y1,long x2,long y2,long x3,long y3,unsigned long cfg,unsigned long cbg){Triangle171(x1,y1,x2,y2,x3,y3,cfg,cbg);}
void triangle(long x1,long y1,long x2,long y2,long x3,long y3,unsigned long c){Triangle172(x1,y1,x2,y2,x3,y3,c);}
void triangle(long x1,long y1,long x2,long y2,long x3,long y3){Triangle173(x1,y1,x2,y2,x3,y3);}
void arc(pbitmap b,long x,long y,long rx,long ry,double sa,double ea,unsigned long cfg,unsigned long cbg){Arc174(b,x,y,rx,ry,sa,ea,cfg,cbg);}
void arc(long x,long y,long rx,long ry,double sa,double ea,unsigned long cfg,unsigned long cbg){Arc175(x,y,rx,ry,sa,ea,cfg,cbg);}
void arc(long x,long y,long rx,long ry,double sa,double ea,unsigned long c){Arc176(x,y,rx,ry,sa,ea,c);}
void arc(long x,long y,long rx,long ry,double sa,double ea){Arc177(x,y,rx,ry,sa,ea);}
void pie(pbitmap b,long x,long y,long rx,long ry,double sa,double ea,unsigned long cfg,unsigned long cbg){Pie178(b,x,y,rx,ry,sa,ea,cfg,cbg);}
void pie(long x,long y,long rx,long ry,double sa,double ea,unsigned long cfg,unsigned long cbg){Pie179(x,y,rx,ry,sa,ea,cfg,cbg);}
void pie(long x,long y,long rx,long ry,double sa,double ea,unsigned long c){Pie180(x,y,rx,ry,sa,ea,c);}
void pie(long x,long y,long rx,long ry,double sa,double ea){Pie181(x,y,rx,ry,sa,ea);}
void chord(pbitmap b,long x,long y,long rx,long ry,double sa,double ea,unsigned long cfg,unsigned long cbg){Chord182(b,x,y,rx,ry,sa,ea,cfg,cbg);}
void chord(long x,long y,long rx,long ry,double sa,double ea,unsigned long cfg,unsigned long cbg){Chord183(x,y,rx,ry,sa,ea,cfg,cbg);}
void chord(long x,long y,long rx,long ry,double sa,double ea,unsigned long c){Chord184(x,y,rx,ry,sa,ea,c);}
void chord(long x,long y,long rx,long ry,double sa,double ea){Chord185(x,y,rx,ry,sa,ea);}
void ellipse(pbitmap b,long x,long y,long rx,long ry,unsigned long cfg,unsigned long cbg){Ellipse186(b,x,y,rx,ry,cfg,cbg);}
void ellipse(long x,long y,long rx,long ry,unsigned long cfg,unsigned long cbg){Ellipse187(x,y,rx,ry,cfg,cbg);}
void ellipse(long x,long y,long rx,long ry,unsigned long c){Ellipse188(x,y,rx,ry,c);}
void ellipse(long x,long y,long rx,long ry){Ellipse189(x,y,rx,ry);}
void circle(pbitmap b,long x,long y,long r,unsigned long cfg,unsigned long cbg){Circle190(b,x,y,r,cfg,cbg);}
void circle(long x,long y,long r,unsigned long cfg,unsigned long cbg){Circle191(x,y,r,cfg,cbg);}
void circle(long x,long y,long r,unsigned long c){Circle192(x,y,r,c);}
void circle(long x,long y,long r){Circle193(x,y,r);}
pbitmap createbmp(pbitmap b,unsigned long w,unsigned long h,unsigned long c){return CreateBMP194(b,w,h,c);}
pbitmap createbmp(pbitmap b){return CreateBMP195(b);}
pbitmap createbmp(unsigned long w,unsigned long h,unsigned long c){return CreateBMP196(w,h,c);}
pbitmap createbmp(unsigned long w,unsigned long h){return CreateBMP197(w,h);}
pbitmap createbmp(){return CreateBMP198();}
void releasebmp(pbitmap b){ReleaseBMP199(b);}
void releasebmp(){ReleaseBMP200();}
pbitmap loadbmp(const char* s,unsigned long c){return LoadBMP201(s,c);}
pbitmap loadbmp(const char* s){return LoadBMP202(s);}
void savebmp(pbitmap b,const char* s){SaveBMP203(b,s);}
void drawbmp(pbitmap bs,pbitmap bd,unsigned long xs,unsigned long ys,unsigned long ws,unsigned long hs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd,unsigned long c){DrawBMP204(bs,bd,xs,ys,ws,hs,xd,yd,wd,hd,c);}
void drawbmp(pbitmap bs,pbitmap bd,unsigned long xs,unsigned long ys,unsigned long ws,unsigned long hs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd){DrawBMP205(bs,bd,xs,ys,ws,hs,xd,yd,wd,hd);}
void drawbmp(pbitmap bs,pbitmap bd,unsigned long xs,unsigned long ys,unsigned long xd,unsigned long yd,unsigned long w,unsigned long h,unsigned long c){DrawBMP206(bs,bd,xs,ys,xd,yd,w,h,c);}
void drawbmp(pbitmap bs,pbitmap bd,unsigned long xs,unsigned long ys,unsigned long xd,unsigned long yd,unsigned long w,unsigned long h){DrawBMP207(bs,bd,xs,ys,xd,yd,w,h);}
void drawbmp(pbitmap bs,pbitmap bd,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd,unsigned long c){DrawBMP208(bs,bd,xd,yd,wd,hd,c);}
void drawbmp(pbitmap bs,pbitmap bd,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd){DrawBMP209(bs,bd,xd,yd,wd,hd);}
void drawbmp(pbitmap bs,pbitmap bd,unsigned long xd,unsigned long yd,unsigned long c){DrawBMP210(bs,bd,xd,yd,c);}
void drawbmp(pbitmap bs,pbitmap bd,unsigned long xd,unsigned long yd){DrawBMP211(bs,bd,xd,yd);}
void drawbmp(pbitmap bs,pbitmap bd,unsigned long c){DrawBMP212(bs,bd,c);}
void drawbmp(pbitmap bs,pbitmap bd){DrawBMP213(bs,bd);}
void drawbmp(pbitmap bs,unsigned long xs,unsigned long ys,unsigned long ws,unsigned long hs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd,unsigned long c){DrawBMP214(bs,xs,ys,ws,hs,xd,yd,wd,hd,c);}
void drawbmp(pbitmap bs,unsigned long xs,unsigned long ys,unsigned long ws,unsigned long hs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd){DrawBMP215(bs,xs,ys,ws,hs,xd,yd,wd,hd);}
void drawbmp(pbitmap bs,unsigned long xs,unsigned long ys,unsigned long xd,unsigned long yd,unsigned long w,unsigned long h,unsigned long c){DrawBMP216(bs,xs,ys,xd,yd,w,h,c);}
void drawbmp(pbitmap bs,unsigned long xs,unsigned long ys,unsigned long xd,unsigned long yd,unsigned long w,unsigned long h){DrawBMP217(bs,xs,ys,xd,yd,w,h);}
void drawbmp(pbitmap bs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd,unsigned long c){DrawBMP218(bs,xd,yd,wd,hd,c);}
void drawbmp(pbitmap bs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd){DrawBMP219(bs,xd,yd,wd,hd);}
void drawbmp(pbitmap bs,unsigned long xd,unsigned long yd,unsigned long c){DrawBMP220(bs,xd,yd,c);}
void drawbmp(pbitmap bs,unsigned long xd,unsigned long yd){DrawBMP221(bs,xd,yd);}
void drawbmp(pbitmap bs,unsigned long c){DrawBMP222(bs,c);}
void drawbmp(pbitmap bs){DrawBMP223(bs);}
void drawbmp(unsigned long xs,unsigned long ys,unsigned long ws,unsigned long hs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd,unsigned long c){DrawBMP224(xs,ys,ws,hs,xd,yd,wd,hd,c);}
void drawbmp(unsigned long xs,unsigned long ys,unsigned long ws,unsigned long hs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd){DrawBMP225(xs,ys,ws,hs,xd,yd,wd,hd);}
void drawbmp(unsigned long xs,unsigned long ys,unsigned long xd,unsigned long yd,unsigned long w,unsigned long h,unsigned long c){DrawBMP226(xs,ys,xd,yd,w,h,c);}
void drawbmp(unsigned long xs,unsigned long ys,unsigned long xd,unsigned long yd,unsigned long w,unsigned long h){DrawBMP227(xs,ys,xd,yd,w,h);}
void drawbmp(unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd,unsigned long c){DrawBMP228(xd,yd,wd,hd,c);}
void drawbmp(unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd){DrawBMP229(xd,yd,wd,hd);}
void drawbmp(unsigned long xd,unsigned long yd,unsigned long c){DrawBMP230(xd,yd,c);}
void drawbmp(unsigned long xd,unsigned long yd){DrawBMP231(xd,yd);}
void drawbmp(unsigned long c){DrawBMP232(c);}
void drawbmp(){DrawBMP233();}
void mixbmp(pbitmap b1,pbitmap b2,pbitmap b3){MixBMP234(b1,b2,b3);}
void blurbmpbox(pbitmap b,unsigned long d,unsigned long n){BlurBMPBox235(b,d,n);}
void blurbmpbox(pbitmap b,unsigned long d){BlurBMPBox236(b,d);}
void blurbmpgau(pbitmap b,double d){BlurBMPGau237(b,d);}
pbitbuf createbb(pbitmap b){return CreateBB238(b);}
void releasebb(pbitbuf bb){ReleaseBB239(bb);}
void getbb(pbitbuf bb){GetBB240(bb);}
void setbb(pbitbuf bb){SetBB241(bb);}
void mixbb(pbitbuf bb1,pbitbuf bb2,pbitbuf bb3){MixBB242(bb1,bb2,bb3);}
void blurbbbox(pbitbuf bb,unsigned long d,unsigned long n){BlurBBBox243(bb,d,n);}
void blurbbgau(pbitbuf bb,double d){BlurBBGau244(bb,d);}
void presskey(unsigned char k,unsigned long t){PressKey245(k,t);}
void presskey(unsigned char k){PressKey246(k);}
void downkey(unsigned char k){DownKey247(k);}
void upkey(unsigned char k){UpKey248(k);}
void pressmouse(unsigned char m,unsigned long t){PressMouse249(m,t);}
void pressmouse(unsigned char m){PressMouse250(m);}
void downmouse(unsigned char m){DownMouse251(m);}
void upmouse(unsigned char m){UpMouse252(m);}
void wheelmouse(long wl){WheelMouse253(wl);}
void movemouse(long x,long y){MoveMouse254(x,y);}
void movemouseabs(long x,long y){MoveMouseAbs255(x,y);}
void movemousewin(long x,long y){MoveMouseWin256(x,y);}
void movemousepos(long x,long y){MoveMousePos257(x,y);}
void sendmsg(){SendMsg258();}
bool isnextmsg(){return IsNextMsg259();}
unsigned long getnextmsg(){return GetNextMsg260();}
unsigned long waitnextmsg(){return WaitNextMsg261();}
bool ismsg(unsigned long uM){return IsMsg262(uM);}
long long getmsg(unsigned long uM){return GetMsg263(uM);}
long long waitmsg(unsigned long uM){return WaitMsg264(uM);}
bool iskey(unsigned long k){return IsKey265(k);}
bool iskey(){return IsKey266();}
unsigned long getkey(){return GetKey267();}
unsigned long waitkey(unsigned long k){return WaitKey268(k);}
unsigned long waitkey(){return WaitKey269();}
bool ismouse(unsigned long m){return IsMouse270(m);}
bool ismouse(){return IsMouse271();}
unsigned long getmouse(){return GetMouse272();}
unsigned long waitmouse(unsigned long m){return WaitMouse273(m);}
unsigned long waitmouse(){return WaitMouse274();}
bool ismouseleft(){return IsMouseLeft275();}
void waitmouseleft(){WaitMouseLeft276();}
bool ismousemiddle(){return IsMouseMiddle277();}
void waitmousemiddle(){WaitMouseMiddle278();}
bool ismouseright(){return IsMouseRight279();}
void waitmouseright(){WaitMouseRight280();}
bool ismousewheel(){return IsMouseWheel281();}
long getmousewheel(){return GetMouseWheel282();}
void waitmousewheel(){WaitMouseWheel283();}
bool ismousemove(){return IsMouseMove284();}
unsigned long getmousemove(){return GetMouseMove285();}
unsigned long waitmousemove(){return WaitMouseMove286();}
bool isdropfile(){return IsDropFile287();}
mystring getdropfile(){return GetDropFile288();}
const short int* getdropfilew(){return GetDropFileW289();}
mystring waitdropfile(){return WaitDropFile290();}
long getmouseabsx(){return GetMouseAbsX291();}
long getmouseabsy(){return GetMouseAbsY292();}
long getmousewinx(){return GetMouseWinX293();}
long getmousewiny(){return GetMouseWinY294();}
long getmouseposx(){return GetMousePosX295();}
long getmouseposy(){return GetMousePosY296();}
unsigned long loadaudio(const char* s1,const char* s2){return LoadAudio297(s1,s2);}
unsigned long loadaudio(const char* s){return LoadAudio298(s);}
void playaudio(unsigned long id,const char* s,bool b){PlayAudio299(id,s,b);}
void playaudio(unsigned long id,const char* s){PlayAudio300(id,s);}
void playaudio(unsigned long id,bool b){PlayAudio301(id,b);}
void playaudio(unsigned long id){PlayAudio302(id);}
void stopaudio(unsigned long id){StopAudio303(id);}
void pauseaudio(unsigned long id){PauseAudio304(id);}
void resumeaudio(unsigned long id){ResumeAudio305(id);}
void releaseaudio(unsigned long id){ReleaseAudio306(id);}
unsigned long getaudiovol(unsigned long id){return GetAudioVol307(id);}
void setaudiovol(unsigned long id,unsigned long v){SetAudioVol308(id,v);}
unsigned long getaudiopos(unsigned long id){return GetAudioPos309(id);}
void setaudiopos(unsigned long id,unsigned long pos,bool b){SetAudioPos310(id,pos,b);}
void setaudiopos(unsigned long id,unsigned long pos){SetAudioPos311(id,pos);}
unsigned long getaudiolen(unsigned long id){return GetAudioLen312(id);}
bool isfile(const char* s){return IsFile313(s);}
bool isfilew(const short int* s){return IsFileW314(s);}
bool newfile(const char* s){return NewFile315(s);}
bool newdir(const char* s){return NewDir316(s);}
bool copyfile(const char* src,const char* des){return CopyFile317(src,des);}
bool movefile(const char* src,const char* des){return MoveFile318(src,des);}
bool deletefile(const char* s){return DeleteFile319(s);}
mystring getfilename(const char* s){return GetFileName320(s);}
const short int* getfilenamew(const short int* s){return GetFileNameW321(s);}
mystring getfiledir(const char* s){return GetFileDir322(s);}
const short int* getfiledirw(const short int* s){return GetFileDirW323(s);}
void openfile(const char* s){OpenFile324(s);}
void openfilew(const short int* s){OpenFileW325(s);}
void closefile(){CloseFile326();}
unsigned long getfilelen(){return GetFileLen327();}
unsigned long getfilepos(){return GetFilePos328();}
void setfilepos(unsigned long pos){SetFilePos329(pos);}
unsigned char getbyte(){return GetByte330();}
unsigned short getword(){return GetWord331();}
unsigned long getlongword(){return GetLongword332();}
unsigned long getinteger(){return GetInteger333();}
const char* getpchar(){return GetPchar334();}
mystring getstring(unsigned long len){return GetString335(len);}
mystring getpara(){return GetPara336();}
mystring getpara(unsigned long n){return GetPara337(n);}
const short int* getparaw(){return GetParaW338();}
const short int* getparaw(unsigned long n){return GetParaW339(n);}
