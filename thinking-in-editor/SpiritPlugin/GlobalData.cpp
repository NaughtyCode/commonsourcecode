#include "GlobalData.h"
#include"AgreementInterfaceDef.h"

#include <windows.h>
#include<process.h>

static int                   WorkScene = 0;
static int                   RootScene = 0;
static int                   SelectedObject = 0;
static bool                           IsCaptured=false;
static float                          MouseX=0;
static float                          MouseY=0;
static float                          DeltaMouseX=0;
static float                          DeltaMouseY=0;
static FSynchPushEngineMessageType    PushEngineMessageFunc=0;
static FSynchPopInterfaceMessageType  PopInterfaceMessageFunc = 0;
static FSynchPushCancelMessageType    PushCancelMessageFunc=0;
static FSynchPopCancelMessageType     PopCancelMessageFunc=0;
static HINSTANCE                      EditorSynchModule = 0;

void ResetAllGlobalData(){
    WorkScene=0;
    RootScene=0;
    SelectedObject=0;
    IsCaptured=false;
    MouseX=0;
    MouseY=0;
    DeltaMouseX=0;
    DeltaMouseY=0;
}

void SetFilePath(const std::string& path){
    std::vector<std::string> resourcepath;
    resourcepath.push_back(path);
    cocos2d::FileUtils::getInstance()->setSearchPaths(resourcepath);
}

int GetWorkScene(){
    return WorkScene;
}

void SetWorkScene(int workscene){
    WorkScene=workscene;
}

int GetRootScene(){
    return RootScene;
}

void SetRootScene(int rootscene){
    RootScene = rootscene;
}

int GetSelectedObject()
{
    return SelectedObject;
}

void SetSelectedObject(int obj)
{
    SelectedObject=obj;
}

bool IsCapture()
{
    return IsCaptured;
}

void SetCapture(bool capture)
{
    IsCaptured = capture;
}

void GetMousePos(float& x,float& y)
{
   x = MouseX;
   y = MouseY;
}

void GetDeltaMousePos(float& x,float& y){
    x = DeltaMouseX;
    y = DeltaMouseY;
}

void SetMousePos(float x,float y)
{
    DeltaMouseX = x-MouseX;
    DeltaMouseY = MouseY-y;
    MouseX = x;
    MouseY = y;
}

float GetMouseX()
{
   return MouseX;
}

float GetMouseY()
{
   return MouseY;
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

	PushEngineMessageFunc = (FSynchPushEngineMessageType)GetProcAddress(EditorSynchModule, GetSynchPushEngineMessageName());
	if (PushEngineMessageFunc == 0){
		printf("获取%s失败\n", GetSynchPushEngineMessageName());
		FreeLibrary(EditorSynchModule);
		return;
	}
	else{
		printf("获取%s成功\n", GetSynchPushEngineMessageName());
	}

	PopInterfaceMessageFunc = (FSynchPopInterfaceMessageType)GetProcAddress(EditorSynchModule, GetSynchPopInterfaceMessageName());
	if (PopInterfaceMessageFunc == 0){
		printf("获取%s失败\n", GetSynchPopInterfaceMessageName());
		FreeLibrary(EditorSynchModule);
		return;
	}
	else{
		printf("获取%s成功\n", GetSynchPopInterfaceMessageName());
	}

	PushCancelMessageFunc = (FSynchPushCancelMessageType)GetProcAddress(EditorSynchModule, GetSynchPushCancelMessageName());
	if (PushCancelMessageFunc == 0){
		printf("获取%s失败\n", GetSynchPushCancelMessageName());
		FreeLibrary(EditorSynchModule);
		return;
	}
	else{
		printf("获取%s成功\n", GetSynchPushCancelMessageName());
	}
	     
	PopCancelMessageFunc = (FSynchPopCancelMessageType)GetProcAddress(EditorSynchModule, GetSynchPopCancelMessageName());
	if (PopCancelMessageFunc == 0){
		printf("获取%s失败\n", GetSynchPopCancelMessageName());
		FreeLibrary(EditorSynchModule);
		return;
	}
	else{
		printf("获取%s成功\n", GetSynchPopCancelMessageName());
	}

	//FreeLibrary(EditorSynchModule);
}

void PushEngineMessage(int key, const std::string& message)
{
	if (PopInterfaceMessageFunc == 0){
		_InitializeCallBack();
	}
	else{
		PushEngineMessageFunc(key, message);
	}
}

void GetInterfaceMessage(int key, std::string& message)
{
	if (PopInterfaceMessageFunc == 0){
		_InitializeCallBack();
	}
	else{
		PopInterfaceMessageFunc(key, message);
	}
}

void PushCancelMessage(int key,const std::string& message)
{
	if (PopInterfaceMessageFunc == 0){
		_InitializeCallBack();
	}
	else{
		PushCancelMessageFunc(key, message);
	}
}

void GetCancelMessage(int key, std::string& message)
{
	if (PopInterfaceMessageFunc == 0){
		_InitializeCallBack();
	}
	else{
		PopCancelMessageFunc(key, message);
	}
}