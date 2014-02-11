#include "MaxExporter.h"
#include "TreeEnumCall.h"





#define MaxExporter_CLASS_ID	Class_ID(0x6f88c988, 0xa8fb641a)

class MaxExporter : public SceneExport {
public:
	MaxExporter();
	~MaxExporter();

	int				ExtCount();	
	const TCHAR *	Ext(int n);	
	const TCHAR *	LongDesc();
	const TCHAR *	ShortDesc();
	const TCHAR *	AuthorName();
	const TCHAR *	CopyrightMessage();
	const TCHAR *	OtherMessage1();
	const TCHAR *	OtherMessage2();
	unsigned int	Version();
	void			ShowAbout(HWND hWnd);

	BOOL SupportsOptions(int ext, DWORD options);
	int  DoExport(const TCHAR *name,ExpInterface *ei,Interface *i, BOOL suppressPrompts=FALSE, DWORD options=0);
};



class MaxExporterClassDesc : public ClassDesc2 
{
public:
	virtual int IsPublic() 							{ return TRUE; }
	virtual void* Create(BOOL loading = FALSE) 		{ return new MaxExporter(); }
	virtual const TCHAR *	ClassName() 			{ return GetString(IDS_CLASS_NAME); }
	virtual SClass_ID SuperClassID() 				{ return SCENE_EXPORT_CLASS_ID; }
	virtual Class_ID ClassID() 						{ return MaxExporter_CLASS_ID; }
	virtual const TCHAR* Category() 				{ return GetString(IDS_CATEGORY); }

	virtual const TCHAR* InternalName() 			{ return _T("MaxExporter"); }
	virtual HINSTANCE HInstance() 					{ return hInstance; }
	

};


ClassDesc2* GetMaxExporterDesc() { 
	static MaxExporterClassDesc MaxExporterDesc;
	return &MaxExporterDesc; 
}


INT_PTR CALLBACK MaxExporterOptionsDlgProc(HWND hWnd,UINT message,WPARAM,LPARAM lParam) {
	static MaxExporter* imp = nullptr;

	switch(message) {
		case WM_INITDIALOG:
			imp = (MaxExporter *)lParam;
			CenterWindow(hWnd,GetParent(hWnd));
			return TRUE;

		case WM_CLOSE:
			EndDialog(hWnd, 0);
			return 1;
	}
	return 0;
}

MaxExporter::MaxExporter()
{

}

MaxExporter::~MaxExporter() 
{

}

int MaxExporter::ExtCount()
{
	return 1;
}

const TCHAR *MaxExporter::Ext(int /*i*/)
{
	return _T("mdl");
}

const TCHAR *MaxExporter::LongDesc()
{
	return _T("");
}
	
const TCHAR *MaxExporter::ShortDesc() 
{
	return _T("");
}

const TCHAR *MaxExporter::AuthorName()
{
	return _T("ZhangGuofa");
}

const TCHAR *MaxExporter::CopyrightMessage() 
{
	return _T("");
}

const TCHAR *MaxExporter::OtherMessage1() 
{
	return _T("");
}

const TCHAR *MaxExporter::OtherMessage2() 
{
	return _T("");
}

unsigned int MaxExporter::Version()
{
	return 100;
}

void MaxExporter::ShowAbout(HWND hWnd)
{

}

BOOL MaxExporter::SupportsOptions(int /*ext*/, DWORD /*options*/)
{
	return TRUE;
}

int	MaxExporter::DoExport(const TCHAR* name, ExpInterface* ei, Interface* ip, BOOL suppressPrompts, DWORD options)
{
	ExpInterface* pExpInterface = ei;
	Interface* pInterface = ip;

	if(!suppressPrompts){
		DialogBoxParam(hInstance,MAKEINTRESOURCE(IDD_PANEL),GetActiveWindow(),MaxExporterOptionsDlgProc, (LPARAM)this);
	}

	std::wstring filename(name);
	CTreeEnumCall Enume(filename,pInterface);

	pExpInterface->theScene->EnumTree( &Enume);

























	pInterface->PushPrompt(_M("导出模型成功"));
	return TRUE;
}
