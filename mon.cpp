static BOOL CALLBACK Monitorenumproc(HMONITOR hmon, HDC hdc, LPRECT lprect, LPARAM pdata)
{
    Window* w = (Window*)pdata;
    MONITORINFOEX info;
    info.cbSize = sizeof(MONITORINFOEX);
    GetMonitorInfo(hmon, &info);
    RECT work = info.rcWork;
    if (getposx() >= work.left && getposx() <= work.right && getposy() >= work.top && getposy() <= work.bottom)
    {
        w->xscr = work.left;
        w->yscr = work.top;
        w->wscr = work.right - work.left;
        w->hscr = work.bottom - work.top;
    }
    return TRUE;
}