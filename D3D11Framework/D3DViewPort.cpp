#include "D3DViewPort.h"

class TD3DRenderSize;

TViewPort::TViewPort(TRenderDevice * device):Device(device)
{
	RefreshViewport();
}

TViewPort::~TViewPort(void)
{
	
}

void TViewPort::RefreshViewport()
{
	TD3DRenderSize* size;
	size = Device->GetRenderSize();
	UINT Width = size->GetRenderWidth();
	UINT Height = size->GetRenderHeight();
	
	Viewport.TopLeftX = 0.0f;
	Viewport.TopLeftY = 0.0f;
	Viewport.Width    = *((float*)&Width);
	Viewport.Height   = *((float*)&Height);
	Viewport.MinDepth = 0.0f;
	Viewport.MaxDepth = 1.0f;
	
}

void TViewPort::ApplyViewPort()
{
	ID3D11DeviceContext* DeviceContext = Device->GetContext();
	if(DeviceContext!=0){
		DeviceContext->RSSetViewports(0,&Viewport);
	}
}
