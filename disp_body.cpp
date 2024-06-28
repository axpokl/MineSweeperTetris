void WinCreateMain()
{
    if (_hw > 0)
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
        if (_draw) _draw();
    }
}

LRESULT CALLBACK WndProc(HWND hW, UINT uM, WPARAM wP, LPARAM lP)
{
    LRESULT WndProcRet = 0;
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
            if (_draw) _draw();
            break;
        case WM_MOVE:
            if (_draw) _draw();
            break;
        case WM_PAINT:
            if (_draw) _draw();
            WndProcRet = DefWindowProcW(hW, uM, wP, lP);
            break;
        case WM_SETCURSOR:
            if (GetMousePosX() >= 0 && GetMousePosY() >= 0 && GetMousePosX() <= _w && GetMousePosY() <= _h)
            {
                SetCursor(LoadCursor(0, IDC_ARROW));
            }
            else
            {
                WndProcRet = DefWindowProcW(hW, uM, wP, lP);
            }
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
        default:
            WndProcRet = DefWindowProcW(hW, uM, wP, lP);
            break;
    }
    return WndProcRet;
}

ATOM WinRegister()
{
    _wc.style = CS_HREDRAW | CS_VREDRAW;
    _wc.lpfnWndProc = WndProc;
    _wc.cbClsExtra = 0;
    _wc.cbWndExtra = 0;
    _wc.hInstance = MainInstance;
    _wc.hbrBackground = CreateSolidBrush(_cbg);
    _wc.lpszMenuName = NULL;
    _wc.lpszClassName = _class;
    return RegisterClassW(&_wc);
}

void WinCreate()
{
    RECT rect;
    rect.left = _x;
    rect.top = _y;
    rect.right = rect.left + _w;
    rect.bottom = rect.top + _h;
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
unsigned long GetHwnd(pbitmap b)
{
    return (unsigned long)b->Handle;
}
unsigned long GetHwnd()
{
    return (unsigned long)_hw;
}
unsigned long GetDraw(pbitmap b)
{
    return (unsigned long)b->DC;
}
unsigned long GetDraw()
{
    return (unsigned long)_dc;
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
void Line(pbitmap b, long x, long y, long w, long h)
{
    Line(b, x, y, w, h, 0);
}
void Line(long x, long y, long w, long h, unsigned long c)
{
    Line(NULL, x, y, w, h, c);
}
void Line(long x, long y, long w, long h)
{
    Line(x, y, w, h, 0);
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
void Delay(double t)
{
    double tbegin = GetTimeR();
    Sleep(max(0, (int)(t * 1000) - 1));
    while ((GetTimeR() - tbegin) < t);
}
void Delay(unsigned long t)
{
    Sleep(t);
}
void Delay()
{
    Delay((unsigned long)DELAYTIMEDEFAULT);
}

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
