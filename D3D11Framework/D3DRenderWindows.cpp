#include "D3DRenderWindows.h"

class TRenderDevice;
TRenderDevice* RenderDevice=0;

LRESULT CALLBACK WindowMessageProccess(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_SIZE:
			RenderDevice=(TRenderDevice*)GetWindowLong(hWnd,GWL_USERDATA);
			RenderDevice->ResetRenderDevice();
			break;
		
		case WM_LBUTTONDOWN:
			break;
		
		case WM_LBUTTONUP:
			break;
		
		case WM_SIZING:
			RenderDevice=(TRenderDevice*)GetWindowLong(hWnd,GWL_USERDATA);
			
			switch (wParam)
			{
				case WMSZ_BOTTOM:
					break;
				
				case WMSZ_BOTTOMLEFT:
					break;
				case WMSZ_BOTTOMRIGHT:
					break;
				case WMSZ_LEFT:
					break;
				case WMSZ_RIGHT:
					break;
				case WMSZ_TOP:
					break;
				case WMSZ_TOPLEFT:
					break;
				case WMSZ_TOPRIGHT:
					break;
			}
			break;
		case WM_CLOSE:
		case WM_DESTROY:
		case WM_QUIT:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

TRenderWindow::TRenderWindow():hWnd(0)
{
}

TRenderWindow::TRenderWindow(HWND hWnd)
{
	this->hWnd = hWnd;
}

TRenderWindow::~TRenderWindow()
{
	DestroyNativeWindow();
}

void TRenderWindow::CreateNativeWindow()
{
	if(this->hWnd!=0){
		return;
	}
	
	WNDCLASS wc;
	wc.style         = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowMessageProccess;
	wc.cbClsExtra    = 0;
	wc.cbWndExtra    = 0;
	wc.hInstance     = NULL;
	wc.hIcon         = NULL;
	wc.hCursor       = NULL;
	wc.hbrBackground = NULL;
	wc.lpszMenuName  = 0;
	wc.lpszClassName = L"D3D11RenderWindow";
	
	if (!RegisterClass(&wc)){
		MessageBox(0, L"×¢²á´°¿ÚÊ§°Ü", 0, 0);
		return;
	}
	
	this->hWnd = CreateWindowW(
		L"D3D11RenderWindow",
		L"3DµØÐÎäÖÈ¾",
		WS_OVERLAPPEDWINDOW,
		0,
		0,
		800,
		600,
		0,
		0,
		NULL,
		0);
	
	if (this->hWnd == 0){
		MessageBox(0, L"´´½¨´°¿ÚÊ§°Ü", 0, 0);
		return;
	}
	ShowWindow(this->hWnd, 1);
	UpdateWindow(this->hWnd);
}

void TRenderWindow::DestroyNativeWindow()
{
}

bool TRenderWindow::MessageProcess()
{
	if (GetMessage(&Messsage, hWnd, 0, 0)){
		if(Messsage.message==WM_QUIT){
			return false;
		}
		TranslateMessage(&Messsage);
		DispatchMessage(&Messsage);
		return true;
	}
	return false;
}

HWND TRenderWindow::GetHWnd()
{
	return hWnd;
}

void TRenderWindow::SetWindowSize(int width, int height)
{
	RECT WindowRect;
	GetWindowRect(hWnd,&WindowRect);
	
	int screenwidth  = GetSystemMetrics(SM_CXFULLSCREEN);
	int screenheight = GetSystemMetrics(SM_CYFULLSCREEN);
	
	int x = (screenwidth  - width)/2;
	int y = (screenheight - height)/2;
	
	SetWindowPos(hWnd,
		     NULL,
		     x,
		     y,
		     width,
		     height,
		SWP_SHOWWINDOW);
	
}

void TRenderWindow::SetWindowTiltle(const char * wintile)
{
	SetWindowTextA(hWnd,wintile);
}

void TRenderWindow::SetWindowIcon(const LPCTSTR filename)
{
	char buf[512];
	GetModuleFileNameA(0,(LPCH)&buf,512);
	HINSTANCE hinstance = GetModuleHandleA(buf);
	
	HICON hIcon = (HICON)LoadImage(hinstance,filename, IMAGE_ICON, 0,0, LR_LOADFROMFILE);
	
	if (hIcon)
	{
		SendMessageA(hWnd, WM_SETICON, 1, (LPARAM)hIcon);
		SendMessageA(hWnd, WM_SETICON, 0, (LPARAM)hIcon);
	}
}
