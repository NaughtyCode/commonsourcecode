#pragma once

#include "D3DDevice.h"
#include "TRenderTarget.h"
#include "TViewPort.h"
#include "TResource.h"

class TD3DDevice;
class TRenderTarget;
class TViewPort;
class TShader;
class TResource;

class TRender
{
public:
	TRender();
	~TRender();
	int CreateRender(HWND hWnd);
	void RenderFrame(FLOAT* color=0);
	void Release();
private:
	TD3DDevice* Device;
	TRenderTarget* RenderTarget;
	TViewPort* ViewPort;
	TResource* Resource;
};

