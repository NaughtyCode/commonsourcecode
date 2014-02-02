#ifndef D3DRENDER_H
#define D3DRENDER_H

#include "D3DRenderheaders.h"

class TRenderWindow;
class TRenderDevice;

class TD3DRender
{
public:
    TD3DRender();
    TD3DRender(HWND hWnd);
    ~TD3DRender();
    void CreateRender();
    
    void RenderDrawOneFrame();
    
    void StartWorld();
private:
    TRenderWindow* RenderWindow;
    TRenderDevice* RenderDevice;
};

#endif