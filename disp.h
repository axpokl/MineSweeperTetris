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
void randomize(){srand(time(NULL));}
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
extern "C" void CreateWin39(unsigned long w,unsigned long h,unsigned long cfg,unsigned long cbg,unsigned long style);
extern "C" void CreateWin40(unsigned long w,unsigned long h,unsigned long cfg,unsigned long cbg);
extern "C" void CreateWin41(unsigned long w,unsigned long h,unsigned long c);
extern "C" void CreateWin42(unsigned long w,unsigned long h);
extern "C" void CreateWin43(unsigned long cbg);
extern "C" void CreateWin44();
extern "C" void FreshWin45();
extern "C" void CloseWin46();
extern "C" bool IsWin47();
extern "C" void SetDrawProcedure48(void* th);
extern "C" double GetTimeR49();
extern "C" unsigned long GetTime50();
extern "C" void SetTitle51(const char* s);
extern "C" void SetTitleW52(const short int* s);
extern "C" const char* GetTitle53();
extern "C" const short int* GetTitleW54();
extern "C" void SetSize55(unsigned long w,unsigned long h);
extern "C" unsigned long GetWidth56();
extern "C" unsigned long GetHeight57();
extern "C" unsigned long GetSize58();
extern "C" long GetScrWidth59();
extern "C" long GetScrHeight60();
extern "C" unsigned long GetScrSize61();
extern "C" double GetScrCapsX62();
extern "C" double GetScrCapsY63();
extern "C" long GetBorderTitle64();
extern "C" long GetBorderWidth65();
extern "C" long GetBorderHeight66();
extern "C" unsigned long GetBorderSize67();
extern "C" void SetPos68(unsigned long x,unsigned long y);
extern "C" long GetPosX69();
extern "C" long GetPosY70();
extern "C" unsigned long GetPos71();
extern "C" pbitmap GetWin72();
extern "C" pbitmap GetScr73();
extern "C" unsigned long GetHwnd74(pbitmap b);
extern "C" unsigned long GetHwnd75();
extern "C" unsigned long GetDraw76(pbitmap b);
extern "C" unsigned long GetDraw77();
extern "C" unsigned long GetBGColor78();
extern "C" void SetBGColor79(unsigned long c);
extern "C" unsigned long GetFGColor80();
extern "C" void SetFGColor81(unsigned long c);
extern "C" void SetPenWidth82(unsigned long pew);
extern "C" void SetPenColor83(pbitmap b,unsigned long c);
extern "C" void SetPenColor84(unsigned long c);
extern "C" void SetBrushColor85(pbitmap b,unsigned long c);
extern "C" void SetBrushColor86(unsigned long c);
extern "C" unsigned char GetAlpha87(unsigned long c);
extern "C" unsigned char GetBlue88(unsigned long c);
extern "C" unsigned char GetGreen89(unsigned long c);
extern "C" unsigned char GetRed90(unsigned long c);
extern "C" unsigned long GetRGBA91(unsigned char r,unsigned char g,unsigned char b,unsigned char a);
extern "C" unsigned long GetRGB92(unsigned char r,unsigned char g,unsigned char b);
extern "C" unsigned long RGB2HSL93(unsigned long rgb);
extern "C" unsigned long RGB2HSV94(unsigned long rgb);
extern "C" unsigned long RGB2HSI95(unsigned long rgb);
extern "C" unsigned long RGB2HSN96(unsigned long rgb);
extern "C" unsigned long HSL2RGB97(unsigned long hsn);
extern "C" unsigned long HSV2RGB98(unsigned long hsn);
extern "C" unsigned long HSI2RGB99(unsigned long hsn);
extern "C" unsigned long HSN2RGB100(unsigned long hsn);
extern "C" void MixColor101(unsigned long rgb1,unsigned long rgb2,unsigned long rgb3,double m);
extern "C" void MixColor102(unsigned long rgb1,unsigned long rgb2,unsigned long rgb3);
extern "C" void SetFont103(pbitmap b);
extern "C" void SetFont104();
extern "C" void SetFontWidth105(unsigned long w);
extern "C" void SetFontHeight106(unsigned long h);
extern "C" void SetFontSize107(unsigned long w,unsigned long h);
extern "C" void SetFontWeight108(unsigned long wg);
extern "C" void SetFontLtalic109(unsigned long lt);
extern "C" void SetFontUnderLine110(unsigned long ud);
extern "C" void SetFontStrikeOut111(unsigned long sk);
extern "C" void SetFontCharSet112(unsigned long cs);
extern "C" void SetFontName113(const char* s);
extern "C" void GetStringSize114(const char* s);
extern "C" unsigned long GetStringWidth115(const char* s);
extern "C" unsigned long GetStringHeight116(const char* s);
extern "C" void DrawTextXY117(pbitmap b,const char* s,long x,long y,unsigned long w,unsigned long h,unsigned long cfg,unsigned long cbg);
extern "C" void DrawTextXY118(pbitmap b,const char* s,long x,long y,unsigned long cfg,unsigned long cbg);
extern "C" void DrawTextXY119(pbitmap b,const char* s,long x,long y,unsigned long cfg);
extern "C" void DrawTextXY120(const char* s,long x,long y,unsigned long cfg,unsigned long cbg);
extern "C" void DrawTextXY121(const char* s,long x,long y,unsigned long cfg);
extern "C" void DrawTextXY122(const char* s,unsigned long x,unsigned long y);
extern "C" void DrawText123(const char* s,unsigned long cfg,unsigned long cbg);
extern "C" void DrawText124(const char* s,unsigned long cfg);
extern "C" void DrawText125(const char* s);
extern "C" void DrawTextlnXY126(const char* s,long x,long y,unsigned long cfg,unsigned long cbg);
extern "C" void DrawTextlnXY127(const char* s,long x,long y,unsigned long cfg);
extern "C" void DrawTextlnXY128(const char* s,unsigned long x,unsigned long y);
extern "C" void DrawTextln129(const char* s,unsigned long cfg,unsigned long cbg);
extern "C" void DrawTextln130(const char* s,unsigned long cfg);
extern "C" void DrawTextln131(const char* s);
extern "C" void DrawTextln132();
extern "C" void DrawTextXYw133(pbitmap b,const char* s,long x,long y,unsigned long cfg,unsigned long cbg);
extern "C" void DrawTextXYw134(pbitmap b,const char* s,long x,long y,unsigned long cfg);
extern "C" void DrawTextXYw135(const char* s,long x,long y,unsigned long cfg,unsigned long cbg);
extern "C" void DrawTextXYw136(const char* s,long x,long y,unsigned long cfg);
extern "C" void DrawTextXYw137(const char* s,unsigned long x,unsigned long y);
extern "C" void DrawTextw138(const char* s,unsigned long cfg,unsigned long cbg);
extern "C" void DrawTextw139(const char* s,unsigned long cfg);
extern "C" void DrawTextw140(const char* s);
extern "C" void DrawTextlnXYw141(const char* s,long x,long y,unsigned long cfg,unsigned long cbg);
extern "C" void DrawTextlnXYw142(const char* s,long x,long y,unsigned long cfg);
extern "C" void DrawTextlnXYw143(const char* s,unsigned long x,unsigned long y);
extern "C" void DrawTextlnw144(const char* s,unsigned long cfg,unsigned long cbg);
extern "C" void DrawTextlnw145(const char* s,unsigned long cfg);
extern "C" void DrawTextlnw146(const char* s);
extern "C" unsigned long GetPixel147(pbitmap b,unsigned long x,unsigned long y);
extern "C" unsigned long GetPixel148(unsigned long x,unsigned long y);
extern "C" void SetPixel149(pbitmap b,unsigned long x,unsigned long y,unsigned long c);
extern "C" void SetPixel150(unsigned long x,unsigned long y,unsigned long c);
extern "C" void SetPixel151(unsigned long x,unsigned long y);
extern "C" unsigned long GetBBPixel152(pbitbuf bb,unsigned long x,unsigned long y);
extern "C" void SetBBPixel153(pbitbuf bb,unsigned long x,unsigned long y,unsigned long c);
extern "C" void Line154(pbitmap b,long x,long y,long w,long h,unsigned long c);
extern "C" void Line155(long x,long y,long w,long h,unsigned long c);
extern "C" void Line156(long x,long y,long w,long h);
extern "C" void LineBB157(pbitbuf bb,long x,long y,long w,long h,unsigned long c);
extern "C" void Bar158(pbitmap b,long x,long y,long w,long h,unsigned long cfg,unsigned long cbg);
extern "C" void Bar159(pbitmap b,long x,long y,long w,long h,unsigned long c);
extern "C" void Bar160(long x,long y,long w,long h,unsigned long cfg,unsigned long cbg);
extern "C" void Bar161(long x,long y,long w,long h,unsigned long c);
extern "C" void Bar162(long x,long y,long w,long h);
extern "C" void Clear163(pbitmap b,unsigned long c);
extern "C" void Clear164(pbitmap b);
extern "C" void Clear165(unsigned long c);
extern "C" void Clear166();
extern "C" void Triangle167(pbitmap b,long x1,long y1,long x2,long y2,long x3,long y3,unsigned long cfg,unsigned long cbg);
extern "C" void Triangle168(long x1,long y1,long x2,long y2,long x3,long y3,unsigned long cfg,unsigned long cbg);
extern "C" void Triangle169(long x1,long y1,long x2,long y2,long x3,long y3,unsigned long c);
extern "C" void Triangle170(long x1,long y1,long x2,long y2,long x3,long y3);
extern "C" void Arc171(pbitmap b,long x,long y,long rx,long ry,double sa,double ea,unsigned long cfg,unsigned long cbg);
extern "C" void Arc172(long x,long y,long rx,long ry,double sa,double ea,unsigned long cfg,unsigned long cbg);
extern "C" void Arc173(long x,long y,long rx,long ry,double sa,double ea,unsigned long c);
extern "C" void Arc174(long x,long y,long rx,long ry,double sa,double ea);
extern "C" void Pie175(pbitmap b,long x,long y,long rx,long ry,double sa,double ea,unsigned long cfg,unsigned long cbg);
extern "C" void Pie176(long x,long y,long rx,long ry,double sa,double ea,unsigned long cfg,unsigned long cbg);
extern "C" void Pie177(long x,long y,long rx,long ry,double sa,double ea,unsigned long c);
extern "C" void Pie178(long x,long y,long rx,long ry,double sa,double ea);
extern "C" void Chord179(pbitmap b,long x,long y,long rx,long ry,double sa,double ea,unsigned long cfg,unsigned long cbg);
extern "C" void Chord180(long x,long y,long rx,long ry,double sa,double ea,unsigned long cfg,unsigned long cbg);
extern "C" void Chord181(long x,long y,long rx,long ry,double sa,double ea,unsigned long c);
extern "C" void Chord182(long x,long y,long rx,long ry,double sa,double ea);
extern "C" void Ellipse183(pbitmap b,long x,long y,long rx,long ry,unsigned long cfg,unsigned long cbg);
extern "C" void Ellipse184(long x,long y,long rx,long ry,unsigned long cfg,unsigned long cbg);
extern "C" void Ellipse185(long x,long y,long rx,long ry,unsigned long c);
extern "C" void Ellipse186(long x,long y,long rx,long ry);
extern "C" void Circle187(pbitmap b,long x,long y,long r,unsigned long cfg,unsigned long cbg);
extern "C" void Circle188(long x,long y,long r,unsigned long cfg,unsigned long cbg);
extern "C" void Circle189(long x,long y,long r,unsigned long c);
extern "C" void Circle190(long x,long y,long r);
extern "C" pbitmap CreateBMP191(pbitmap b,unsigned long w,unsigned long h,unsigned long c);
extern "C" pbitmap CreateBMP192(pbitmap b);
extern "C" pbitmap CreateBMP193(unsigned long w,unsigned long h,unsigned long c);
extern "C" pbitmap CreateBMP194(unsigned long w,unsigned long h);
extern "C" pbitmap CreateBMP195();
extern "C" void ReleaseBMP196(pbitmap b);
extern "C" void ReleaseBMP197();
extern "C" pbitmap LoadBMP198(const char* s,unsigned long c);
extern "C" pbitmap LoadBMP199(const char* s);
extern "C" void SaveBMP200(pbitmap b,const char* s);
extern "C" void DrawBMP201(pbitmap bs,pbitmap bd,unsigned long xs,unsigned long ys,unsigned long ws,unsigned long hs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd,unsigned long c);
extern "C" void DrawBMP202(pbitmap bs,pbitmap bd,unsigned long xs,unsigned long ys,unsigned long ws,unsigned long hs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd);
extern "C" void DrawBMP203(pbitmap bs,pbitmap bd,unsigned long xs,unsigned long ys,unsigned long xd,unsigned long yd,unsigned long w,unsigned long h,unsigned long c);
extern "C" void DrawBMP204(pbitmap bs,pbitmap bd,unsigned long xs,unsigned long ys,unsigned long xd,unsigned long yd,unsigned long w,unsigned long h);
extern "C" void DrawBMP205(pbitmap bs,pbitmap bd,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd,unsigned long c);
extern "C" void DrawBMP206(pbitmap bs,pbitmap bd,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd);
extern "C" void DrawBMP207(pbitmap bs,pbitmap bd,unsigned long xd,unsigned long yd,unsigned long c);
extern "C" void DrawBMP208(pbitmap bs,pbitmap bd,unsigned long xd,unsigned long yd);
extern "C" void DrawBMP209(pbitmap bs,pbitmap bd,unsigned long c);
extern "C" void DrawBMP210(pbitmap bs,pbitmap bd);
extern "C" void DrawBMP211(pbitmap bs,unsigned long xs,unsigned long ys,unsigned long ws,unsigned long hs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd,unsigned long c);
extern "C" void DrawBMP212(pbitmap bs,unsigned long xs,unsigned long ys,unsigned long ws,unsigned long hs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd);
extern "C" void DrawBMP213(pbitmap bs,unsigned long xs,unsigned long ys,unsigned long xd,unsigned long yd,unsigned long w,unsigned long h,unsigned long c);
extern "C" void DrawBMP214(pbitmap bs,unsigned long xs,unsigned long ys,unsigned long xd,unsigned long yd,unsigned long w,unsigned long h);
extern "C" void DrawBMP215(pbitmap bs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd,unsigned long c);
extern "C" void DrawBMP216(pbitmap bs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd);
extern "C" void DrawBMP217(pbitmap bs,unsigned long xd,unsigned long yd,unsigned long c);
extern "C" void DrawBMP218(pbitmap bs,unsigned long xd,unsigned long yd);
extern "C" void DrawBMP219(pbitmap bs,unsigned long c);
extern "C" void DrawBMP220(pbitmap bs);
extern "C" void DrawBMP221(unsigned long xs,unsigned long ys,unsigned long ws,unsigned long hs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd,unsigned long c);
extern "C" void DrawBMP222(unsigned long xs,unsigned long ys,unsigned long ws,unsigned long hs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd);
extern "C" void DrawBMP223(unsigned long xs,unsigned long ys,unsigned long xd,unsigned long yd,unsigned long w,unsigned long h,unsigned long c);
extern "C" void DrawBMP224(unsigned long xs,unsigned long ys,unsigned long xd,unsigned long yd,unsigned long w,unsigned long h);
extern "C" void DrawBMP225(unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd,unsigned long c);
extern "C" void DrawBMP226(unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd);
extern "C" void DrawBMP227(unsigned long xd,unsigned long yd,unsigned long c);
extern "C" void DrawBMP228(unsigned long xd,unsigned long yd);
extern "C" void DrawBMP229(unsigned long c);
extern "C" void DrawBMP230();
extern "C" void MixBMP231(pbitmap b1,pbitmap b2,pbitmap b3);
extern "C" void BlurBMPBox232(pbitmap b,unsigned long d,unsigned long n);
extern "C" void BlurBMPBox233(pbitmap b,unsigned long d);
extern "C" void BlurBMPGau234(pbitmap b,double d);
extern "C" pbitbuf CreateBB235(pbitmap b);
extern "C" void ReleaseBB236(pbitbuf bb);
extern "C" void GetBB237(pbitbuf bb);
extern "C" void SetBB238(pbitbuf bb);
extern "C" void MixBB239(pbitbuf bb1,pbitbuf bb2,pbitbuf bb3);
extern "C" void BlurBBBox240(pbitbuf bb,unsigned long d,unsigned long n);
extern "C" void BlurBBGau241(pbitbuf bb,double d);
extern "C" void PressKey242(unsigned char k,unsigned long t);
extern "C" void PressKey243(unsigned char k);
extern "C" void DownKey244(unsigned char k);
extern "C" void UpKey245(unsigned char k);
extern "C" void PressMouse246(unsigned char m,unsigned long t);
extern "C" void PressMouse247(unsigned char m);
extern "C" void DownMouse248(unsigned char m);
extern "C" void UpMouse249(unsigned char m);
extern "C" void WheelMouse250(long wl);
extern "C" void MoveMouse251(long x,long y);
extern "C" void MoveMouseAbs252(long x,long y);
extern "C" void MoveMouseWin253(long x,long y);
extern "C" void MoveMousePos254(long x,long y);
extern "C" void SendMsg255();
extern "C" bool IsNextMsg256();
extern "C" unsigned long GetNextMsg257();
extern "C" unsigned long WaitNextMsg258();
extern "C" bool IsMsg259(unsigned long uM);
extern "C" long long GetMsg260(unsigned long uM);
extern "C" long long WaitMsg261(unsigned long uM);
extern "C" bool IsKey262(unsigned long k);
extern "C" bool IsKey263();
extern "C" unsigned long GetKey264();
extern "C" unsigned long WaitKey265(unsigned long k);
extern "C" unsigned long WaitKey266();
extern "C" bool IsMouse267(unsigned long m);
extern "C" bool IsMouse268();
extern "C" unsigned long GetMouse269();
extern "C" unsigned long WaitMouse270(unsigned long m);
extern "C" unsigned long WaitMouse271();
extern "C" bool IsMouseLeft272();
extern "C" void WaitMouseLeft273();
extern "C" bool IsMouseMiddle274();
extern "C" void WaitMouseMiddle275();
extern "C" bool IsMouseRight276();
extern "C" void WaitMouseRight277();
extern "C" bool IsMouseWheel278();
extern "C" long GetMouseWheel279();
extern "C" void WaitMouseWheel280();
extern "C" bool IsMouseMove281();
extern "C" unsigned long GetMouseMove282();
extern "C" unsigned long WaitMouseMove283();
extern "C" bool IsDropFile284();
extern "C" const char* GetDropFile285();
extern "C" const short int* GetDropFileW286();
extern "C" const char* WaitDropFile287();
extern "C" long GetMouseAbsX288();
extern "C" long GetMouseAbsY289();
extern "C" long GetMouseWinX290();
extern "C" long GetMouseWinY291();
extern "C" long GetMousePosX292();
extern "C" long GetMousePosY293();
extern "C" unsigned long LoadAudio294(const char* s);
extern "C" void PlayAudio295(unsigned long id,const char* s,bool b);
extern "C" void PlayAudio296(unsigned long id,const char* s);
extern "C" void PlayAudio297(unsigned long id,bool b);
extern "C" void PlayAudio298(unsigned long id);
extern "C" void StopAudio299(unsigned long id);
extern "C" void PauseAudio300(unsigned long id);
extern "C" void ResumeAudio301(unsigned long id);
extern "C" void ReleaseAudio302(unsigned long id);
extern "C" unsigned long GetAudioVol303(unsigned long id);
extern "C" void SetAudioVol304(unsigned long id,unsigned long v);
extern "C" unsigned long GetAudioPos305(unsigned long id);
extern "C" void SetAudioPos306(unsigned long id,unsigned long pos,bool b);
extern "C" void SetAudioPos307(unsigned long id,unsigned long pos);
extern "C" unsigned long GetAudioLen308(unsigned long id);
extern "C" bool IsFile309(const char* s);
extern "C" bool IsFileW310(const short int* s);
extern "C" bool NewFile311(const char* s);
extern "C" bool NewDir312(const char* s);
extern "C" bool CopyFile313(const char* src,const char* des);
extern "C" bool MoveFile314(const char* src,const char* des);
extern "C" bool DeleteFile315(const char* s);
extern "C" const char* GetFileName316(const char* s);
extern "C" const short int* GetFileNameW317(const short int* s);
extern "C" const char* GetFileDir318(const char* s);
extern "C" const short int* GetFileDirW319(const short int* s);
extern "C" void OpenFile320(const char* s);
extern "C" void OpenFileW321(const short int* s);
extern "C" void CloseFile322();
extern "C" unsigned long GetFileLen323();
extern "C" unsigned long GetFilePos324();
extern "C" void SetFilePos325(unsigned long pos);
extern "C" unsigned char GetByte326();
extern "C" unsigned short GetWord327();
extern "C" unsigned long GetLongword328();
extern "C" unsigned long GetInteger329();
extern "C" const char* GetPchar330();
extern "C" const char* GetString331(unsigned long len);
extern "C" const char* GetPara332();
extern "C" const char* GetPara333(unsigned long n);
extern "C" const short int* GetParaW334();
extern "C" const short int* GetParaW335(unsigned long n);

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
void createwin(unsigned long w,unsigned long h,unsigned long cfg,unsigned long cbg,unsigned long style){CreateWin39(w,h,cfg,cbg,style);}
void createwin(unsigned long w,unsigned long h,unsigned long cfg,unsigned long cbg){CreateWin40(w,h,cfg,cbg);}
void createwin(unsigned long w,unsigned long h,unsigned long c){CreateWin41(w,h,c);}
void createwin(unsigned long w,unsigned long h){CreateWin42(w,h);}
void createwin(unsigned long cbg){CreateWin43(cbg);}
void createwin(){CreateWin44();}
void freshwin(){FreshWin45();}
void closewin(){CloseWin46();}
bool iswin(){return IsWin47();}
void setdrawprocedure(void* th){SetDrawProcedure48(th);}
double gettimer(){return GetTimeR49();}
unsigned long gettime(){return GetTime50();}
void settitle(const char* s){SetTitle51(s);}
void settitlew(const short int* s){SetTitleW52(s);}
mystring gettitle(){return GetTitle53();}
const short int* gettitlew(){return GetTitleW54();}
void setsize(unsigned long w,unsigned long h){SetSize55(w,h);}
unsigned long getwidth(){return GetWidth56();}
unsigned long getheight(){return GetHeight57();}
unsigned long getsize(){return GetSize58();}
long getscrwidth(){return GetScrWidth59();}
long getscrheight(){return GetScrHeight60();}
unsigned long getscrsize(){return GetScrSize61();}
double getscrcapsx(){return GetScrCapsX62();}
double getscrcapsy(){return GetScrCapsY63();}
long getbordertitle(){return GetBorderTitle64();}
long getborderwidth(){return GetBorderWidth65();}
long getborderheight(){return GetBorderHeight66();}
unsigned long getbordersize(){return GetBorderSize67();}
void setpos(unsigned long x,unsigned long y){SetPos68(x,y);}
long getposx(){return GetPosX69();}
long getposy(){return GetPosY70();}
unsigned long getpos(){return GetPos71();}
pbitmap getwin(){return GetWin72();}
pbitmap getscr(){return GetScr73();}
unsigned long gethwnd(pbitmap b){return GetHwnd74(b);}
unsigned long gethwnd(){return GetHwnd75();}
unsigned long getdraw(pbitmap b){return GetDraw76(b);}
unsigned long getdraw(){return GetDraw77();}
unsigned long getbgcolor(){return GetBGColor78();}
void setbgcolor(unsigned long c){SetBGColor79(c);}
unsigned long getfgcolor(){return GetFGColor80();}
void setfgcolor(unsigned long c){SetFGColor81(c);}
void setpenwidth(unsigned long pew){SetPenWidth82(pew);}
void setpencolor(pbitmap b,unsigned long c){SetPenColor83(b,c);}
void setpencolor(unsigned long c){SetPenColor84(c);}
void setbrushcolor(pbitmap b,unsigned long c){SetBrushColor85(b,c);}
void setbrushcolor(unsigned long c){SetBrushColor86(c);}
unsigned char getalpha(unsigned long c){return GetAlpha87(c);}
unsigned char getblue(unsigned long c){return GetBlue88(c);}
unsigned char getgreen(unsigned long c){return GetGreen89(c);}
unsigned char getred(unsigned long c){return GetRed90(c);}
unsigned long getrgba(unsigned char r,unsigned char g,unsigned char b,unsigned char a){return GetRGBA91(r,g,b,a);}
unsigned long getrgb(unsigned char r,unsigned char g,unsigned char b){return GetRGB92(r,g,b);}
unsigned long rgb2hsl(unsigned long rgb){return RGB2HSL93(rgb);}
unsigned long rgb2hsv(unsigned long rgb){return RGB2HSV94(rgb);}
unsigned long rgb2hsi(unsigned long rgb){return RGB2HSI95(rgb);}
unsigned long rgb2hsn(unsigned long rgb){return RGB2HSN96(rgb);}
unsigned long hsl2rgb(unsigned long hsn){return HSL2RGB97(hsn);}
unsigned long hsv2rgb(unsigned long hsn){return HSV2RGB98(hsn);}
unsigned long hsi2rgb(unsigned long hsn){return HSI2RGB99(hsn);}
unsigned long hsn2rgb(unsigned long hsn){return HSN2RGB100(hsn);}
void mixcolor(unsigned long rgb1,unsigned long rgb2,unsigned long rgb3,double m){MixColor101(rgb1,rgb2,rgb3,m);}
void mixcolor(unsigned long rgb1,unsigned long rgb2,unsigned long rgb3){MixColor102(rgb1,rgb2,rgb3);}
void setfont(pbitmap b){SetFont103(b);}
void setfont(){SetFont104();}
void setfontwidth(unsigned long w){SetFontWidth105(w);}
void setfontheight(unsigned long h){SetFontHeight106(h);}
void setfontsize(unsigned long w,unsigned long h){SetFontSize107(w,h);}
void setfontweight(unsigned long wg){SetFontWeight108(wg);}
void setfontltalic(unsigned long lt){SetFontLtalic109(lt);}
void setfontunderline(unsigned long ud){SetFontUnderLine110(ud);}
void setfontstrikeout(unsigned long sk){SetFontStrikeOut111(sk);}
void setfontcharset(unsigned long cs){SetFontCharSet112(cs);}
void setfontname(const char* s){SetFontName113(s);}
void getstringsize(const char* s){GetStringSize114(s);}
unsigned long getstringwidth(const char* s){return GetStringWidth115(s);}
unsigned long getstringheight(const char* s){return GetStringHeight116(s);}
void drawtextxy(pbitmap b,const char* s,long x,long y,unsigned long w,unsigned long h,unsigned long cfg,unsigned long cbg){DrawTextXY117(b,s,x,y,w,h,cfg,cbg);}
void drawtextxy(pbitmap b,const char* s,long x,long y,unsigned long cfg,unsigned long cbg){DrawTextXY118(b,s,x,y,cfg,cbg);}
void drawtextxy(pbitmap b,const char* s,long x,long y,unsigned long cfg){DrawTextXY119(b,s,x,y,cfg);}
void drawtextxy(const char* s,long x,long y,unsigned long cfg,unsigned long cbg){DrawTextXY120(s,x,y,cfg,cbg);}
void drawtextxy(const char* s,long x,long y,unsigned long cfg){DrawTextXY121(s,x,y,cfg);}
void drawtextxy(const char* s,unsigned long x,unsigned long y){DrawTextXY122(s,x,y);}
void drawtext(const char* s,unsigned long cfg,unsigned long cbg){DrawText123(s,cfg,cbg);}
void drawtext(const char* s,unsigned long cfg){DrawText124(s,cfg);}
void drawtext(const char* s){DrawText125(s);}
void drawtextlnxy(const char* s,long x,long y,unsigned long cfg,unsigned long cbg){DrawTextlnXY126(s,x,y,cfg,cbg);}
void drawtextlnxy(const char* s,long x,long y,unsigned long cfg){DrawTextlnXY127(s,x,y,cfg);}
void drawtextlnxy(const char* s,unsigned long x,unsigned long y){DrawTextlnXY128(s,x,y);}
void drawtextln(const char* s,unsigned long cfg,unsigned long cbg){DrawTextln129(s,cfg,cbg);}
void drawtextln(const char* s,unsigned long cfg){DrawTextln130(s,cfg);}
void drawtextln(const char* s){DrawTextln131(s);}
void drawtextln(){DrawTextln132();}
void drawtextxyw(pbitmap b,const char* s,long x,long y,unsigned long cfg,unsigned long cbg){DrawTextXYw133(b,s,x,y,cfg,cbg);}
void drawtextxyw(pbitmap b,const char* s,long x,long y,unsigned long cfg){DrawTextXYw134(b,s,x,y,cfg);}
void drawtextxyw(const char* s,long x,long y,unsigned long cfg,unsigned long cbg){DrawTextXYw135(s,x,y,cfg,cbg);}
void drawtextxyw(const char* s,long x,long y,unsigned long cfg){DrawTextXYw136(s,x,y,cfg);}
void drawtextxyw(const char* s,unsigned long x,unsigned long y){DrawTextXYw137(s,x,y);}
void drawtextw(const char* s,unsigned long cfg,unsigned long cbg){DrawTextw138(s,cfg,cbg);}
void drawtextw(const char* s,unsigned long cfg){DrawTextw139(s,cfg);}
void drawtextw(const char* s){DrawTextw140(s);}
void drawtextlnxyw(const char* s,long x,long y,unsigned long cfg,unsigned long cbg){DrawTextlnXYw141(s,x,y,cfg,cbg);}
void drawtextlnxyw(const char* s,long x,long y,unsigned long cfg){DrawTextlnXYw142(s,x,y,cfg);}
void drawtextlnxyw(const char* s,unsigned long x,unsigned long y){DrawTextlnXYw143(s,x,y);}
void drawtextlnw(const char* s,unsigned long cfg,unsigned long cbg){DrawTextlnw144(s,cfg,cbg);}
void drawtextlnw(const char* s,unsigned long cfg){DrawTextlnw145(s,cfg);}
void drawtextlnw(const char* s){DrawTextlnw146(s);}
unsigned long getpixel(pbitmap b,unsigned long x,unsigned long y){return GetPixel147(b,x,y);}
unsigned long getpixel(unsigned long x,unsigned long y){return GetPixel148(x,y);}
void setpixel(pbitmap b,unsigned long x,unsigned long y,unsigned long c){SetPixel149(b,x,y,c);}
void setpixel(unsigned long x,unsigned long y,unsigned long c){SetPixel150(x,y,c);}
void setpixel(unsigned long x,unsigned long y){SetPixel151(x,y);}
unsigned long getbbpixel(pbitbuf bb,unsigned long x,unsigned long y){return GetBBPixel152(bb,x,y);}
void setbbpixel(pbitbuf bb,unsigned long x,unsigned long y,unsigned long c){SetBBPixel153(bb,x,y,c);}
void line(pbitmap b,long x,long y,long w,long h,unsigned long c){Line154(b,x,y,w,h,c);}
void line(long x,long y,long w,long h,unsigned long c){Line155(x,y,w,h,c);}
void line(long x,long y,long w,long h){Line156(x,y,w,h);}
void linebb(pbitbuf bb,long x,long y,long w,long h,unsigned long c){LineBB157(bb,x,y,w,h,c);}
void bar(pbitmap b,long x,long y,long w,long h,unsigned long cfg,unsigned long cbg){Bar158(b,x,y,w,h,cfg,cbg);}
void bar(pbitmap b,long x,long y,long w,long h,unsigned long c){Bar159(b,x,y,w,h,c);}
void bar(long x,long y,long w,long h,unsigned long cfg,unsigned long cbg){Bar160(x,y,w,h,cfg,cbg);}
void bar(long x,long y,long w,long h,unsigned long c){Bar161(x,y,w,h,c);}
void bar(long x,long y,long w,long h){Bar162(x,y,w,h);}
void clear(pbitmap b,unsigned long c){Clear163(b,c);}
void clear(pbitmap b){Clear164(b);}
void clear(unsigned long c){Clear165(c);}
void clear(){Clear166();}
void triangle(pbitmap b,long x1,long y1,long x2,long y2,long x3,long y3,unsigned long cfg,unsigned long cbg){Triangle167(b,x1,y1,x2,y2,x3,y3,cfg,cbg);}
void triangle(long x1,long y1,long x2,long y2,long x3,long y3,unsigned long cfg,unsigned long cbg){Triangle168(x1,y1,x2,y2,x3,y3,cfg,cbg);}
void triangle(long x1,long y1,long x2,long y2,long x3,long y3,unsigned long c){Triangle169(x1,y1,x2,y2,x3,y3,c);}
void triangle(long x1,long y1,long x2,long y2,long x3,long y3){Triangle170(x1,y1,x2,y2,x3,y3);}
void arc(pbitmap b,long x,long y,long rx,long ry,double sa,double ea,unsigned long cfg,unsigned long cbg){Arc171(b,x,y,rx,ry,sa,ea,cfg,cbg);}
void arc(long x,long y,long rx,long ry,double sa,double ea,unsigned long cfg,unsigned long cbg){Arc172(x,y,rx,ry,sa,ea,cfg,cbg);}
void arc(long x,long y,long rx,long ry,double sa,double ea,unsigned long c){Arc173(x,y,rx,ry,sa,ea,c);}
void arc(long x,long y,long rx,long ry,double sa,double ea){Arc174(x,y,rx,ry,sa,ea);}
void pie(pbitmap b,long x,long y,long rx,long ry,double sa,double ea,unsigned long cfg,unsigned long cbg){Pie175(b,x,y,rx,ry,sa,ea,cfg,cbg);}
void pie(long x,long y,long rx,long ry,double sa,double ea,unsigned long cfg,unsigned long cbg){Pie176(x,y,rx,ry,sa,ea,cfg,cbg);}
void pie(long x,long y,long rx,long ry,double sa,double ea,unsigned long c){Pie177(x,y,rx,ry,sa,ea,c);}
void pie(long x,long y,long rx,long ry,double sa,double ea){Pie178(x,y,rx,ry,sa,ea);}
void chord(pbitmap b,long x,long y,long rx,long ry,double sa,double ea,unsigned long cfg,unsigned long cbg){Chord179(b,x,y,rx,ry,sa,ea,cfg,cbg);}
void chord(long x,long y,long rx,long ry,double sa,double ea,unsigned long cfg,unsigned long cbg){Chord180(x,y,rx,ry,sa,ea,cfg,cbg);}
void chord(long x,long y,long rx,long ry,double sa,double ea,unsigned long c){Chord181(x,y,rx,ry,sa,ea,c);}
void chord(long x,long y,long rx,long ry,double sa,double ea){Chord182(x,y,rx,ry,sa,ea);}
void ellipse(pbitmap b,long x,long y,long rx,long ry,unsigned long cfg,unsigned long cbg){Ellipse183(b,x,y,rx,ry,cfg,cbg);}
void ellipse(long x,long y,long rx,long ry,unsigned long cfg,unsigned long cbg){Ellipse184(x,y,rx,ry,cfg,cbg);}
void ellipse(long x,long y,long rx,long ry,unsigned long c){Ellipse185(x,y,rx,ry,c);}
void ellipse(long x,long y,long rx,long ry){Ellipse186(x,y,rx,ry);}
void circle(pbitmap b,long x,long y,long r,unsigned long cfg,unsigned long cbg){Circle187(b,x,y,r,cfg,cbg);}
void circle(long x,long y,long r,unsigned long cfg,unsigned long cbg){Circle188(x,y,r,cfg,cbg);}
void circle(long x,long y,long r,unsigned long c){Circle189(x,y,r,c);}
void circle(long x,long y,long r){Circle190(x,y,r);}
pbitmap createbmp(pbitmap b,unsigned long w,unsigned long h,unsigned long c){return CreateBMP191(b,w,h,c);}
pbitmap createbmp(pbitmap b){return CreateBMP192(b);}
pbitmap createbmp(unsigned long w,unsigned long h,unsigned long c){return CreateBMP193(w,h,c);}
pbitmap createbmp(unsigned long w,unsigned long h){return CreateBMP194(w,h);}
pbitmap createbmp(){return CreateBMP195();}
void releasebmp(pbitmap b){ReleaseBMP196(b);}
void releasebmp(){ReleaseBMP197();}
pbitmap loadbmp(const char* s,unsigned long c){return LoadBMP198(s,c);}
pbitmap loadbmp(const char* s){return LoadBMP199(s);}
void savebmp(pbitmap b,const char* s){SaveBMP200(b,s);}
void drawbmp(pbitmap bs,pbitmap bd,unsigned long xs,unsigned long ys,unsigned long ws,unsigned long hs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd,unsigned long c){DrawBMP201(bs,bd,xs,ys,ws,hs,xd,yd,wd,hd,c);}
void drawbmp(pbitmap bs,pbitmap bd,unsigned long xs,unsigned long ys,unsigned long ws,unsigned long hs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd){DrawBMP202(bs,bd,xs,ys,ws,hs,xd,yd,wd,hd);}
void drawbmp(pbitmap bs,pbitmap bd,unsigned long xs,unsigned long ys,unsigned long xd,unsigned long yd,unsigned long w,unsigned long h,unsigned long c){DrawBMP203(bs,bd,xs,ys,xd,yd,w,h,c);}
void drawbmp(pbitmap bs,pbitmap bd,unsigned long xs,unsigned long ys,unsigned long xd,unsigned long yd,unsigned long w,unsigned long h){DrawBMP204(bs,bd,xs,ys,xd,yd,w,h);}
void drawbmp(pbitmap bs,pbitmap bd,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd,unsigned long c){DrawBMP205(bs,bd,xd,yd,wd,hd,c);}
void drawbmp(pbitmap bs,pbitmap bd,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd){DrawBMP206(bs,bd,xd,yd,wd,hd);}
void drawbmp(pbitmap bs,pbitmap bd,unsigned long xd,unsigned long yd,unsigned long c){DrawBMP207(bs,bd,xd,yd,c);}
void drawbmp(pbitmap bs,pbitmap bd,unsigned long xd,unsigned long yd){DrawBMP208(bs,bd,xd,yd);}
void drawbmp(pbitmap bs,pbitmap bd,unsigned long c){DrawBMP209(bs,bd,c);}
void drawbmp(pbitmap bs,pbitmap bd){DrawBMP210(bs,bd);}
void drawbmp(pbitmap bs,unsigned long xs,unsigned long ys,unsigned long ws,unsigned long hs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd,unsigned long c){DrawBMP211(bs,xs,ys,ws,hs,xd,yd,wd,hd,c);}
void drawbmp(pbitmap bs,unsigned long xs,unsigned long ys,unsigned long ws,unsigned long hs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd){DrawBMP212(bs,xs,ys,ws,hs,xd,yd,wd,hd);}
void drawbmp(pbitmap bs,unsigned long xs,unsigned long ys,unsigned long xd,unsigned long yd,unsigned long w,unsigned long h,unsigned long c){DrawBMP213(bs,xs,ys,xd,yd,w,h,c);}
void drawbmp(pbitmap bs,unsigned long xs,unsigned long ys,unsigned long xd,unsigned long yd,unsigned long w,unsigned long h){DrawBMP214(bs,xs,ys,xd,yd,w,h);}
void drawbmp(pbitmap bs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd,unsigned long c){DrawBMP215(bs,xd,yd,wd,hd,c);}
void drawbmp(pbitmap bs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd){DrawBMP216(bs,xd,yd,wd,hd);}
void drawbmp(pbitmap bs,unsigned long xd,unsigned long yd,unsigned long c){DrawBMP217(bs,xd,yd,c);}
void drawbmp(pbitmap bs,unsigned long xd,unsigned long yd){DrawBMP218(bs,xd,yd);}
void drawbmp(pbitmap bs,unsigned long c){DrawBMP219(bs,c);}
void drawbmp(pbitmap bs){DrawBMP220(bs);}
void drawbmp(unsigned long xs,unsigned long ys,unsigned long ws,unsigned long hs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd,unsigned long c){DrawBMP221(xs,ys,ws,hs,xd,yd,wd,hd,c);}
void drawbmp(unsigned long xs,unsigned long ys,unsigned long ws,unsigned long hs,unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd){DrawBMP222(xs,ys,ws,hs,xd,yd,wd,hd);}
void drawbmp(unsigned long xs,unsigned long ys,unsigned long xd,unsigned long yd,unsigned long w,unsigned long h,unsigned long c){DrawBMP223(xs,ys,xd,yd,w,h,c);}
void drawbmp(unsigned long xs,unsigned long ys,unsigned long xd,unsigned long yd,unsigned long w,unsigned long h){DrawBMP224(xs,ys,xd,yd,w,h);}
void drawbmp(unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd,unsigned long c){DrawBMP225(xd,yd,wd,hd,c);}
void drawbmp(unsigned long xd,unsigned long yd,unsigned long wd,unsigned long hd){DrawBMP226(xd,yd,wd,hd);}
void drawbmp(unsigned long xd,unsigned long yd,unsigned long c){DrawBMP227(xd,yd,c);}
void drawbmp(unsigned long xd,unsigned long yd){DrawBMP228(xd,yd);}
void drawbmp(unsigned long c){DrawBMP229(c);}
void drawbmp(){DrawBMP230();}
void mixbmp(pbitmap b1,pbitmap b2,pbitmap b3){MixBMP231(b1,b2,b3);}
void blurbmpbox(pbitmap b,unsigned long d,unsigned long n){BlurBMPBox232(b,d,n);}
void blurbmpbox(pbitmap b,unsigned long d){BlurBMPBox233(b,d);}
void blurbmpgau(pbitmap b,double d){BlurBMPGau234(b,d);}
pbitbuf createbb(pbitmap b){return CreateBB235(b);}
void releasebb(pbitbuf bb){ReleaseBB236(bb);}
void getbb(pbitbuf bb){GetBB237(bb);}
void setbb(pbitbuf bb){SetBB238(bb);}
void mixbb(pbitbuf bb1,pbitbuf bb2,pbitbuf bb3){MixBB239(bb1,bb2,bb3);}
void blurbbbox(pbitbuf bb,unsigned long d,unsigned long n){BlurBBBox240(bb,d,n);}
void blurbbgau(pbitbuf bb,double d){BlurBBGau241(bb,d);}
void presskey(unsigned char k,unsigned long t){PressKey242(k,t);}
void presskey(unsigned char k){PressKey243(k);}
void downkey(unsigned char k){DownKey244(k);}
void upkey(unsigned char k){UpKey245(k);}
void pressmouse(unsigned char m,unsigned long t){PressMouse246(m,t);}
void pressmouse(unsigned char m){PressMouse247(m);}
void downmouse(unsigned char m){DownMouse248(m);}
void upmouse(unsigned char m){UpMouse249(m);}
void wheelmouse(long wl){WheelMouse250(wl);}
void movemouse(long x,long y){MoveMouse251(x,y);}
void movemouseabs(long x,long y){MoveMouseAbs252(x,y);}
void movemousewin(long x,long y){MoveMouseWin253(x,y);}
void movemousepos(long x,long y){MoveMousePos254(x,y);}
void sendmsg(){SendMsg255();}
bool isnextmsg(){return IsNextMsg256();}
unsigned long getnextmsg(){return GetNextMsg257();}
unsigned long waitnextmsg(){return WaitNextMsg258();}
bool ismsg(unsigned long uM){return IsMsg259(uM);}
long long getmsg(unsigned long uM){return GetMsg260(uM);}
long long waitmsg(unsigned long uM){return WaitMsg261(uM);}
bool iskey(unsigned long k){return IsKey262(k);}
bool iskey(){return IsKey263();}
unsigned long getkey(){return GetKey264();}
unsigned long waitkey(unsigned long k){return WaitKey265(k);}
unsigned long waitkey(){return WaitKey266();}
bool ismouse(unsigned long m){return IsMouse267(m);}
bool ismouse(){return IsMouse268();}
unsigned long getmouse(){return GetMouse269();}
unsigned long waitmouse(unsigned long m){return WaitMouse270(m);}
unsigned long waitmouse(){return WaitMouse271();}
bool ismouseleft(){return IsMouseLeft272();}
void waitmouseleft(){WaitMouseLeft273();}
bool ismousemiddle(){return IsMouseMiddle274();}
void waitmousemiddle(){WaitMouseMiddle275();}
bool ismouseright(){return IsMouseRight276();}
void waitmouseright(){WaitMouseRight277();}
bool ismousewheel(){return IsMouseWheel278();}
long getmousewheel(){return GetMouseWheel279();}
void waitmousewheel(){WaitMouseWheel280();}
bool ismousemove(){return IsMouseMove281();}
unsigned long getmousemove(){return GetMouseMove282();}
unsigned long waitmousemove(){return WaitMouseMove283();}
bool isdropfile(){return IsDropFile284();}
mystring getdropfile(){return GetDropFile285();}
const short int* getdropfilew(){return GetDropFileW286();}
mystring waitdropfile(){return WaitDropFile287();}
long getmouseabsx(){return GetMouseAbsX288();}
long getmouseabsy(){return GetMouseAbsY289();}
long getmousewinx(){return GetMouseWinX290();}
long getmousewiny(){return GetMouseWinY291();}
long getmouseposx(){return GetMousePosX292();}
long getmouseposy(){return GetMousePosY293();}
unsigned long loadaudio(const char* s){return LoadAudio294(s);}
void playaudio(unsigned long id,const char* s,bool b){PlayAudio295(id,s,b);}
void playaudio(unsigned long id,const char* s){PlayAudio296(id,s);}
void playaudio(unsigned long id,bool b){PlayAudio297(id,b);}
void playaudio(unsigned long id){PlayAudio298(id);}
void stopaudio(unsigned long id){StopAudio299(id);}
void pauseaudio(unsigned long id){PauseAudio300(id);}
void resumeaudio(unsigned long id){ResumeAudio301(id);}
void releaseaudio(unsigned long id){ReleaseAudio302(id);}
unsigned long getaudiovol(unsigned long id){return GetAudioVol303(id);}
void setaudiovol(unsigned long id,unsigned long v){SetAudioVol304(id,v);}
unsigned long getaudiopos(unsigned long id){return GetAudioPos305(id);}
void setaudiopos(unsigned long id,unsigned long pos,bool b){SetAudioPos306(id,pos,b);}
void setaudiopos(unsigned long id,unsigned long pos){SetAudioPos307(id,pos);}
unsigned long getaudiolen(unsigned long id){return GetAudioLen308(id);}
bool isfile(const char* s){return IsFile309(s);}
bool isfilew(const short int* s){return IsFileW310(s);}
bool newfile(const char* s){return NewFile311(s);}
bool newdir(const char* s){return NewDir312(s);}
bool copyfile(const char* src,const char* des){return CopyFile313(src,des);}
bool movefile(const char* src,const char* des){return MoveFile314(src,des);}
bool deletefile(const char* s){return DeleteFile315(s);}
mystring getfilename(const char* s){return GetFileName316(s);}
const short int* getfilenamew(const short int* s){return GetFileNameW317(s);}
mystring getfiledir(const char* s){return GetFileDir318(s);}
const short int* getfiledirw(const short int* s){return GetFileDirW319(s);}
void openfile(const char* s){OpenFile320(s);}
void openfilew(const short int* s){OpenFileW321(s);}
void closefile(){CloseFile322();}
unsigned long getfilelen(){return GetFileLen323();}
unsigned long getfilepos(){return GetFilePos324();}
void setfilepos(unsigned long pos){SetFilePos325(pos);}
unsigned char getbyte(){return GetByte326();}
unsigned short getword(){return GetWord327();}
unsigned long getlongword(){return GetLongword328();}
unsigned long getinteger(){return GetInteger329();}
const char* getpchar(){return GetPchar330();}
mystring getstring(unsigned long len){return GetString331(len);}
mystring getpara(){return GetPara332();}
mystring getpara(unsigned long n){return GetPara333(n);}
const short int* getparaw(){return GetParaW334();}
const short int* getparaw(unsigned long n){return GetParaW335(n);}
