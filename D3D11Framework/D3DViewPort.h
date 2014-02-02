#ifndef D3DVIEWPORT_H
#define D3DVIEWPORT_H

#include "D3DRenderheaders.h"

class TRenderDevice;

class TViewPort
{
public:
    TViewPort(TRenderDevice * device);
    virtual ~TViewPort(void);
    void RefreshViewport();
    void ApplyViewPort();
    
private:
    D3D11_VIEWPORT Viewport;
    TRenderDevice* Device;
};

#endif