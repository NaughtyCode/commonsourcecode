#include "GlobalSetting.h"
#include"AgreementInterfaceDef.h"
#include<windows.h>
#include<process.h>

typedef void(*FStartBlockRenderType)(int handle);
typedef void(*FDestoryRenderEngineType)();

static FSynchPushInterfaceMessageType PushInterfaceMessageFunc = 0;
static FSynchPopEngineMessageType     SynchPopEngineMessage = 0;

static HINSTANCE   EditorSynchModule   = 0;
static std::string EditorResourcePath  = "";
static std::string GameResourcePath    = "";
HANDLE             RenderThreadHandle  = 0;
HINSTANCE          RenderWorkerLibrary = 0;

FDestoryRenderEngineType DestoryRenderEngineFunc = 0;

const std::string GetEditorResourcePath(const std::string& filename)
{
    return EditorResourcePath+filename;
}

void SetEditorResourcePath(const std::string& pathname){
    EditorResourcePath=pathname;
}

const std::string GetGameResourcePath(const std::string& filename)
{
    return GameResourcePath+filename;
}

void SetGameResourcePath(const std::string& pathname){
    GameResourcePath=pathname;
}

void _InitializeCallBack()
{
	EditorSynchModule = LoadLibraryA(GetEditorSynchronousName());
	if (EditorSynchModule == 0){
		printf("打开%s失败\n", GetEditorSynchronousName());
		return;
	}
	else{
		printf("打开%s成功\n", GetEditorSynchronousName());
	}

	PushInterfaceMessageFunc = (FSynchPushInterfaceMessageType)GetProcAddress(EditorSynchModule, GetSynchPushInterfaceMessageName());
	if (PushInterfaceMessageFunc == 0){
		printf("获取%s失败\n", GetSynchPushInterfaceMessageName());
		FreeLibrary(EditorSynchModule);
		return;
	}
	else{
		printf("获取%s成功\n", GetSynchPushInterfaceMessageName());
	}

	SynchPopEngineMessage = (FSynchPopEngineMessageType)GetProcAddress(EditorSynchModule, GetSynchPopEngineMessageName());
	if (SynchPopEngineMessage == 0){
		printf("获取%s失败\n", GetSynchPopEngineMessageName());
		FreeLibrary(EditorSynchModule);
		return;
	}
	else{
		printf("获取%s成功\n", GetSynchPopEngineMessageName());
	}

	//FreeLibrary(EditorSynchModule);
}

void PushEditorMessage(int key, const std::string& message)
{
	if (PushInterfaceMessageFunc == 0 && SynchPopEngineMessage == 0){
		_InitializeCallBack();
	}
	else{
		PushInterfaceMessageFunc(key, message);
	}
}

void GetEngineMessage(int key, std::string& message)
{
	if (PushInterfaceMessageFunc == 0 && SynchPopEngineMessage == 0){
		_InitializeCallBack();
	}else{
		SynchPopEngineMessage(key, message);
	}
}

unsigned __stdcall RenderWorker(void* data) {
	const char* LibraryName = "EditorPlugins\\ParticlePlugin.dll";
	RenderWorkerLibrary = LoadLibraryA(LibraryName);
	if (RenderWorkerLibrary == nullptr){
		printf("Can't load %s library!!\n", LibraryName);
		return 1;
	}
	else{
		printf("load %s library success\n", LibraryName);
	}

	DestoryRenderEngineFunc = (FDestoryRenderEngineType)GetProcAddress(RenderWorkerLibrary, "DestoryRenderEngine");
	if (DestoryRenderEngineFunc == nullptr){
		printf("get fuction DestoryRenderEngine fail\n");
		FreeLibrary(RenderWorkerLibrary);
		return 1;
	}
	else{
		printf("Get fuction DestoryRenderEngine success\n");
	}
	
	FStartBlockRenderType RenderFunction = (FStartBlockRenderType)GetProcAddress(RenderWorkerLibrary, "CreateBlockRender");
	if (RenderFunction == nullptr){
		printf("get fuction CreateBlockRender fail\n");
		FreeLibrary(RenderWorkerLibrary);
		return 1;
	}
	else{
		printf("Get fuction CreateBlockRender success\n");
		RenderFunction((int)data);
	}
	FreeLibrary(RenderWorkerLibrary);
	RenderWorkerLibrary = 0;
	_endthreadex(0);
	return 0;
}

void CreateRenderEngine(int handle)
{
	RenderThreadHandle = (HANDLE)_beginthreadex(NULL, 0, &RenderWorker, (void*)handle, 0, 0);
}

void DestroyRenderEngine()
{

}
