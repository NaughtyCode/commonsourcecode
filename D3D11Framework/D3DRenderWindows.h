#ifndef PRIMARYWINDOWS_H
#define PRIMARYWINDOWS_H

#include "D3DRenderheaders.h"

class TRenderWindow
{
public:
    TRenderWindow();
    TRenderWindow(HWND hWnd);
    ~TRenderWindow();
    void CreateNativeWindow();
    void DestroyNativeWindow();
    bool MessageProcess();
    void SetWindowSize(int width,int height);
    void SetWindowTiltle(const char * wintile);
    void SetWindowIcon(const LPCTSTR filename);
    HWND GetHWnd();
private:
    HWND hWnd;
    MSG  Messsage;
};

#endif