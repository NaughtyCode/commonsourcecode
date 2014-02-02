#include <python.h>
#include <windows.h>

//
//int main(int, char **) {
//	Py_Initialize(); 
//	PyRun_SimpleString("print(\"Test Engine Module\")");
//
//	PyRun_SimpleString("import os\n"			
//		"print(dir(os))\n"			
//		"print(os.SEEK_SET)\n"			
//		"import C_Object\n"
//		"obj = C_Object.TBaseIterator(1000)\n"			
//		"print(obj)\n"			
//		"print(dir(obj))\n"			
//		"print(obj.GetIndex())\n"			
//		"obj.SetIndex(200000)\n"			
//		"print(obj.GetIndex())\n"		
//		);
//	
//	Py_Finalize();
//
//	Sleep(100000);
//	return 0;
//}

int
wmain(int argc, wchar_t **argv)
{
	return Py_Main(argc, argv);
}
