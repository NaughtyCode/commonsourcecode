#include "D3DRender.h"

TD3DRender::TD3DRender():RenderWindow(0), RenderDevice(0)
{
	CreateRender();
}

TD3DRender::TD3DRender(HWND hWnd):RenderWindow(0), RenderDevice(0)
{
	RenderWindow = new TRenderWindow(hWnd);
	this->RenderDevice = new TRenderDevice(RenderWindow);
	RenderWindow->SetWindowIcon(L"..\\resource\\Icons\\WindowIcon.ico");
}

TD3DRender::~TD3DRender()
{
	delete RenderWindow;
	delete RenderDevice;
}

void TD3DRender::CreateRender()
{
	RenderWindow = new TRenderWindow();
	this->RenderDevice = new TRenderDevice(RenderWindow);
	RenderWindow->SetWindowIcon(L"..\\resource\\Icons\\WindowIcon.ico");
}

void TD3DRender::StartWorld()
{
	while(true){
		if(!RenderDevice->RenderFrame())
		{
			break;
		}
	}
}

void TD3DRender::RenderDrawOneFrame()
{
	if(RenderDevice!=0){
		RenderDevice->DrawOneFrame();
	}
}
