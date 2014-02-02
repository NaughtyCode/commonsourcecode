#ifndef D3DRENDERTARGET_H
#define D3DRENDERTARGET_H

#include "D3DRenderheaders.h"

class TRenderDevice;

class TRenderTarget
{
public:
    TRenderTarget(TRenderDevice* device);
    ~TRenderTarget();
    void CreateRenderTargetView();
    void CreateDepthStencilView();
    void BindRenderTarget();
    void ClearRenderTarget();
    void ResetRenderTarget();
    void ReleaseRenderTargetResource();
    
private:
    TRenderDevice*              Device;
    ID3D11RenderTargetView*     RenderTargetView;
    ID3D11DepthStencilView*     DepthStencilView;
    ID3D11DepthStencilView*     ReadOnlyDepthStencilView;
    ID3D11ShaderResourceView*   ShaderResourceView;
    ID3D11UnorderedAccessView*  UnorderedAccessView;
    ID3D11Texture2D*            Resource;
};

#endif