#include "D3DRenderheaders.h"

TRenderDevice::TRenderDevice(TRenderWindow* renderwindow):
		RenderWindow(renderwindow),
		RenderTarget(0),
		ViewPort(0),
		RenderSize(0),
		SwapChain(0)
{
	CreateRenderDevice();
}

TRenderDevice::~TRenderDevice(void)
{
	delete RenderTarget;
	DeviceContext->Release();
	Device->Release();
	if (RenderSize != 0){
		delete RenderSize;
	}
	if (ViewPort != 0){
		delete ViewPort;
	}
}

BOOL TRenderDevice::CreateRenderDevice(){
	HRESULT  hr;
	RenderSize = new TD3DRenderSize();
	
	if(RenderWindow!=0){
		RenderWindow->CreateNativeWindow();
		SetWindowLong(RenderWindow->GetHWnd(), GWL_USERDATA, (LONG)this);
		RenderWindow->SetWindowSize(RenderSize->GetRenderWidth(),RenderSize->GetRenderHeight());
	}
	
#if defined(DEBUG) || defined(_DEBUG)
	m_CreateFlags|=D3D10_CREATE_DEVICE_DEBUG;
#endif
	D3D_FEATURE_LEVEL pFeatureLevels[] = {
				D3D_FEATURE_LEVEL_11_0,
				D3D_FEATURE_LEVEL_10_1,
				D3D_FEATURE_LEVEL_10_0,
				D3D_FEATURE_LEVEL_9_3,
				D3D_FEATURE_LEVEL_9_2,
				D3D_FEATURE_LEVEL_9_1,
			};
	
	hr = D3D11CreateDevice(0,D3D_DRIVER_TYPE_HARDWARE,0,m_CreateFlags,
						pFeatureLevels,
						6,
						D3D11_SDK_VERSION,
						&Device,
						&m_OutFeatureLevel,
						&DeviceContext);
	if(FAILED(hr)){
		MessageBox(0,L"创建设备失败",0,0);
		return S_FALSE;
	}
	if(m_OutFeatureLevel!=D3D_FEATURE_LEVEL_11_0){
		MessageBox(0,L"m_OutFeatureLevel!=D3D_FEATURE_LEVEL_11_0",0,0);
	}
	
	Device->CheckMultisampleQualityLevels(DXGI_FORMAT_R8G8B8A8_UNORM, 4, &MsaaQuality);
	assert(MsaaQuality>0);
	
	CreateSwapChain();
	
	RenderTarget = new TRenderTarget(this);
	ViewPort = new TViewPort(this);
	ViewPort->ApplyViewPort();
	
	return S_OK;
}

bool TRenderDevice::CreateSwapChain(){
	IDXGIDevice* device;
	if (FAILED(Device->QueryInterface(__uuidof(IDXGIDevice), (void**) &device))){
		MessageBox(0,L"获取设备接口失败",0,0);
		return false;
	}
	
	IDXGIAdapter* adapter;
	if (FAILED(device->GetParent(__uuidof(IDXGIAdapter), (void**) &adapter))){
		MessageBox(0,L"获取适配器接口失败",0,0);
		return false;
	}
	
	IDXGIFactory* factory;
	if (FAILED(adapter->GetParent(__uuidof(IDXGIFactory), (void**) &factory))){
		MessageBox(0,L"获取Factory接口失败",0,0);
		return false;
	}
	
	DXGI_SWAP_CHAIN_DESC sd;
	sd.BufferDesc.Width                   = RenderSize->GetRenderWidth();
	sd.BufferDesc.Height                  = RenderSize->GetRenderHeight();
	sd.BufferDesc.RefreshRate.Numerator   = 60;
	sd.BufferDesc.RefreshRate.Denominator = 1;
	sd.BufferDesc.Format                  = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.ScanlineOrdering        = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	sd.BufferDesc.Scaling                 = DXGI_MODE_SCALING_UNSPECIFIED;
	
	if (MsaaQuality>0){
		sd.SampleDesc.Count = MsaaQuality;
		sd.SampleDesc.Quality = MsaaQuality - 1;
	}else{
		sd.SampleDesc.Count=1;
		sd.SampleDesc.Quality=0;
	}
	
	sd.BufferUsage  = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.BufferCount  = 1;
	sd.OutputWindow = RenderWindow->GetHWnd();
	sd.Windowed     = true;
	sd.SwapEffect   = DXGI_SWAP_EFFECT_DISCARD;
	sd.Flags        = 0;
	
	if (FAILED(factory->CreateSwapChain(Device, &sd, &SwapChain))){
		MessageBox(0,L"创建SwapChain失败",0,0);
		return false;
	}
	
	device->Release();
	adapter->Release();
	factory->Release();
	
	return true;
}

bool TRenderDevice::RenderFrame()
{
	assert(Device!=0);
	assert(DeviceContext!=0);
	assert(RenderWindow!=0);
	assert(SwapChain!=0);
	
	if(RenderWindow->MessageProcess()){
		RenderTarget->ClearRenderTarget();
		SwapChain->Present(0, 0);
		return true;
	}
	return false;
}

void TRenderDevice::DrawOneFrame()
{
	assert(Device!=0);
	assert(DeviceContext!=0);
	assert(RenderWindow!=0);
	assert(SwapChain!=0);
	
	RenderTarget->ClearRenderTarget();
	SwapChain->Present(0, 0);
}

IDXGISwapChain* TRenderDevice::GetSwapChain()
{
	return SwapChain;
}

ID3D11DeviceContext* TRenderDevice::GetContext()
{
	return DeviceContext;
}

UINT TRenderDevice::GetMSAAQuality()
{
	return MsaaQuality;
}

ID3D11Device* TRenderDevice::GetDevice()
{
	return Device;
}

TD3DRenderSize* TRenderDevice::GetRenderSize()
{
	return RenderSize;
}

void TRenderDevice::ResetRenderDevice()
{
	return;

	if(SwapChain==0){
		return;
	}else{
		SwapChain->Release();
		SwapChain->Release();
		SwapChain=0;
	}
	
	HWND hWnd;
	RECT Rect;
	hWnd = RenderWindow->GetHWnd();
	GetClientRect(hWnd,&Rect);
	UINT width  = (UINT)Rect.right;
	UINT height = (UINT)Rect.bottom;
	RenderSize->RefreshRenderSize(width,height);
	
	if(!CreateSwapChain()){
	}
	
	RenderTarget->ReleaseRenderTargetResource();
	
	RenderTarget->ResetRenderTarget();
	
	ViewPort->RefreshViewport();
	
}
