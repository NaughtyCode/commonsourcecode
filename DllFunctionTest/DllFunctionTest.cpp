#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <windows.h>

typedef int (*SetExternelWindowHandle_t)(int windowhandle);

void DllFunctionTest(const char* LibraryName)
{
	HINSTANCE hLibrary = LoadLibraryA(LibraryName);
	if (hLibrary == nullptr){
		printf("Can't open %s library!!\n",LibraryName);
		return;
	}else{
		printf("open %s library successfully\n",LibraryName);
	}
	
	SetExternelWindowHandle_t SetExternelWindowHandle = (SetExternelWindowHandle_t)GetProcAddress(hLibrary, "SetExternelWindowHandle");
	if (SetExternelWindowHandle == nullptr){
		printf("get fuction SetExternelWindowHandle fail\n");
		FreeLibrary(hLibrary);
		return;
	}else{
		printf("get fuction SetExternelWindowHandle successfully\n");
	}
	FreeLibrary(hLibrary);
}

int main()
{
	DllFunctionTest("glfw3.dll");
	return 0;
}