#include"AgreementInterfaceDef.h"

#include<windows.h>

void CreateEditor()
{
	FCreateEditorInterfaceType CreateEditorInterface;
	HINSTANCE hMode = LoadLibraryA(GetEditorInterfaceName());
	if (hMode == nullptr){
		printf("��%sʧ��\n", GetEditorInterfaceName());
		return;
	}
	else{
		printf("��%s�ɹ�\n", GetEditorInterfaceName());
	}

	CreateEditorInterface = (FCreateEditorInterfaceType)GetProcAddress(hMode, GetCreateEditorInterfaceNameName());
	if (CreateEditorInterface == nullptr){
		printf("��ȡ%sʧ��\n", GetCreateEditorInterfaceNameName());
		FreeLibrary(hMode);
		return;
	}
	else{
		CreateEditorInterface();
		printf("��ȡ%s�ɹ�\n", GetCreateEditorInterfaceNameName());
	}
	FreeLibrary(hMode);
}


int main()
{


	CreateEditor();















    return 0;
}
