#include "D3DRenderheaders.h"

class TD3DRenderSize;

TRenderTarget::TRenderTarget(TRenderDevice* device) :
	Device(device),
	RenderTargetView(0),
	DepthStencilView(0),
	ReadOnlyDepthStencilView(0),
	ShaderResourceView(0),
	UnorderedAccessView(0),
	Resource(0)
{
	CreateRenderTargetView();
	CreateDepthStencilView();
	BindRenderTarget();
}

TRenderTarget::~TRenderTarget()
{
	ReleaseRenderTargetResource();
}

void TRenderTarget::CreateRenderTargetView()
{
	ID3D11Texture2D* backbuffer;
	IDXGISwapChain*  swapchain;
	swapchain = Device->GetSwapChain();
	swapchain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**) &backbuffer);
	ID3D11Device*  device = Device->GetDevice();
	device->CreateRenderTargetView(backbuffer, 0, &RenderTargetView);
	backbuffer->Release();
}

void TRenderTarget::CreateDepthStencilView(){
	TD3DRenderSize* size = Device->GetRenderSize();
	D3D11_TEXTURE2D_DESC bufferdesc;
	bufferdesc.Width     = size->GetRenderWidth();
	bufferdesc.Height    = size->GetRenderHeight();
	bufferdesc.MipLevels = 1;
	bufferdesc.ArraySize = 1;
	bufferdesc.Format    = DXGI_FORMAT_D24_UNORM_S8_UINT;
	
	UINT  msaa = Device->GetMSAAQuality();
	if (msaa>0){
		bufferdesc.SampleDesc.Count = msaa;
		bufferdesc.SampleDesc.Quality = msaa - 1;
	}
	else{
		bufferdesc.SampleDesc.Count = 1;
		bufferdesc.SampleDesc.Quality = 0;
	}
	
	bufferdesc.Usage = D3D11_USAGE_DEFAULT;
	bufferdesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	bufferdesc.CPUAccessFlags = 0;
	bufferdesc.MiscFlags = 0;
	
	ID3D11Device*  dv = Device->GetDevice();
	
	if (FAILED(dv->CreateTexture2D(&bufferdesc, 0, &Resource))){
		MessageBox(0, L"创建Resource失败", 0, 0);
		return;
	}
	
	if (FAILED(dv->CreateDepthStencilView(Resource, 0, &DepthStencilView))){
		MessageBox(0, L"创建DepthStencilView失败", 0, 0);
		return;
	}
}

void TRenderTarget::BindRenderTarget()
{
	TD3DRenderSize* size = Device->GetRenderSize();

	ID3D11DeviceContext* DeviceContext = Device->GetContext();
	DeviceContext->OMSetRenderTargets(
				1,
				&RenderTargetView,
				DepthStencilView);
}

void TRenderTarget::ClearRenderTarget()
{
	static float ClearColor[4] = { 0.0f, 0.25f, 0.30f, 0.55f };
	ID3D11DeviceContext* context = Device->GetContext();
	context->ClearRenderTargetView(RenderTargetView, ClearColor);
	context->ClearDepthStencilView(DepthStencilView, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0, 0);
}

void TRenderTarget::ReleaseRenderTargetResource()
{
    if(RenderTargetView!=0){
	RenderTargetView->Release();
	RenderTargetView=0;
    }
    if(DepthStencilView!=0){
	DepthStencilView->Release();
	DepthStencilView=0;
    }
    if(ReadOnlyDepthStencilView!=0){
	ReadOnlyDepthStencilView->Release();
	ReadOnlyDepthStencilView=0;
    }
    
    if(ShaderResourceView!=0){
	ShaderResourceView->Release();
	ShaderResourceView=0;
    }
    if(UnorderedAccessView!=0){
	UnorderedAccessView->Release();
	UnorderedAccessView=0;
    }
    if(Resource!=0){
	Resource->Release();
	Resource=0;
    }
}

void TRenderTarget::ResetRenderTarget()
{
	ReleaseRenderTargetResource();
	CreateRenderTargetView();
	CreateDepthStencilView();
	BindRenderTarget();
}
