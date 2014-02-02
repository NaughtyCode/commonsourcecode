#include"AgreementInterfaceDef.h"

#include<windows.h>

void CreateEditor()
{
	FCreateEditorInterfaceType CreateEditorInterface;
	HINSTANCE hMode = LoadLibraryA(GetEditorInterfaceName());
	if (hMode == nullptr){
		printf("打开%s失败\n", GetEditorInterfaceName());
		return;
	}
	else{
		printf("打开%s成功\n", GetEditorInterfaceName());
	}

	CreateEditorInterface = (FCreateEditorInterfaceType)GetProcAddress(hMode, GetCreateEditorInterfaceNameName());
	if (CreateEditorInterface == nullptr){
		printf("获取%s失败\n", GetCreateEditorInterfaceNameName());
		FreeLibrary(hMode);
		return;
	}
	else{
		CreateEditorInterface();
		printf("获取%s成功\n", GetCreateEditorInterfaceNameName());
	}
	FreeLibrary(hMode);
}


int main()
{


	CreateEditor();















    return 0;
}
