#include "stdafx.h"
#include "TRender.h"

TRender::TRender() :Device(0), RenderTarget(0), ViewPort(0), Resource(0)
{
}

TRender::~TRender()
{

}

int TRender::CreateRender(HWND hWnd)
{
	Device = new TD3DDevice(hWnd);
	assert(Device);
	int rt;
	rt=Device->CreateDevice();
	assert(rt);
	RenderTarget = new TRenderTarget(Device);
	assert(RenderTarget);
	RenderTarget->CreateRenderTarget();
	ViewPort = new TViewPort(Device);
	assert(RenderTarget);
	ViewPort->CreateViewPort();

	Resource = new TResource(Device);
	assert(Resource);
	Resource->CreateResource();
	return 1;
}

void TRender::RenderFrame(FLOAT* color)
{
	if (!color){
		float ClearColor[4] = { 0.3f, 0.3f, 0.8f, 1.0f };
		Device->GetImmediateContext()->ClearRenderTargetView(RenderTarget->GetRenderTargetView(), ClearColor);
		Device->GetSwapChain()->Present(0, 0);
	}
	else{
		Device->GetImmediateContext()->ClearRenderTargetView(RenderTarget->GetRenderTargetView(), color);
		Device->GetSwapChain()->Present(0, 0);
	}
	Resource->PostResource();
}



void TRender::Release()
{

}
