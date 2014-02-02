#ifndef D3DRENDERDEVICE_H
#define D3DRENDERDEVICE_H

#include "D3DRenderheaders.h"

class TD3DRenderSize;
class TRenderWindow;
class TViewPort;

class TRenderDevice
{
public:
    TRenderDevice(TRenderWindow* renderwindow);
    virtual ~TRenderDevice(void);
    BOOL CreateRenderDevice();
    
    bool CreateSwapChain();
    
    BOOL CreateRenderTargetView();
    BOOL CreateDepthStencilView();
    
    BOOL SetRenderViews();
    
    bool RenderFrame();
    
    void DrawOneFrame();
    
    IDXGISwapChain* GetSwapChain();
    
    ID3D11Device*  GetDevice();
    
    ID3D11DeviceContext* GetContext();
    
    UINT GetMSAAQuality();
    TD3DRenderSize* GetRenderSize();
    
    void ResetRenderDevice();
    
private:
    ID3D11Device*        Device;
    ID3D11DeviceContext* DeviceContext;
    UINT                 m_CreateFlags;
    UINT                 MsaaQuality;
    D3D_FEATURE_LEVEL    m_OutFeatureLevel;
    IDXGISwapChain*      SwapChain;
    TRenderTarget*       RenderTarget;
    TD3DRenderSize*      RenderSize;
    TRenderWindow*       RenderWindow;
    TViewPort*           ViewPort;
    
};

#endif