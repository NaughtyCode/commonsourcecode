#include "CocoRenderDLL.h"
#include "TRenderApplication.h"

USING_NS_CC;

typedef int(*SetExternelWindowHandle_T)(int windowhandle);

static TRenderApplication* RenderApp=0;
static EGLView* glView=0;
static HANDLE ThreadHandle = 0;

void SetExternelWindowHandle(int renderwindowhandle)
{
	HINSTANCE hMode = LoadLibrary(L"glfw3.dll");
	if (hMode == nullptr){
		printf("打开glfw3.dll失败\n");
		return;
	}
	else{
		printf("打开glfw3.dll成功\n");
	}
	
	SetExternelWindowHandle_T SetExternelWindowHandlePtr = (SetExternelWindowHandle_T)GetProcAddress(hMode, "SetExternelWindowHandle");
	if (SetExternelWindowHandle == nullptr){
		printf("获取SetExternelWindowHandle失败\n");
		FreeLibrary(hMode);
		return;
	}
	else{
		SetExternelWindowHandlePtr(renderwindowhandle);
		printf("获取SetExternelWindowHandle成功\n");
	}
	FreeLibrary(hMode);
}

unsigned __stdcall RenderWorker(void* data) {
	SetExternelWindowHandle((int)data);
	RenderApp = new TRenderApplication;
	glView = new EGLView;
	glView->init("GameEditorDLL",900,640);
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nLast;
	LARGE_INTEGER nNow;

	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nLast);

	if (!Application::getInstance()->applicationDidFinishLaunching())
	{
		return 0;
	}

	EGLView* pMainWnd = EGLView::getInstance();

	LONGLONG delta = { 50 };

	while (!pMainWnd->windowShouldClose())
	{
		QueryPerformanceCounter(&nNow);
		if (nNow.QuadPart - nLast.QuadPart > delta)
		{
			nLast.QuadPart = nNow.QuadPart;
			Director::getInstance()->mainLoop();
			pMainWnd->pollEvents();
		}
		else
		{
			Sleep(0);
		}
	}

	Director::getInstance()->end();
	Director::getInstance()->mainLoop();
	_endthreadex(0);
	return 0;
}

COCORENDERDLLAPI void CreateRenderEngine(int handle)
{
	if (ThreadHandle == 0){
		ThreadHandle=(HANDLE)_beginthreadex(NULL,0,&RenderWorker,(void*)handle,0,0);
	}
}

COCORENDERDLLAPI void RenderFrame()
{
}

COCORENDERDLLAPI void DestoryRenderEngine()
{
	if(RenderApp!=0){
		delete RenderApp;
		RenderApp=0;
	}
	if(glView!=0){
		delete glView;
		glView=0;
	}
	Director::getInstance()->end();
	if(ThreadHandle!=0){
		CloseHandle(ThreadHandle);
		ThreadHandle=0;
	}
}


