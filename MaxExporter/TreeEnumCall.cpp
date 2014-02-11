#include "TreeEnumCall.h"

CTreeEnumCall::CTreeEnumCall(const std::wstring& filename,Interface* ip):m_FileName(filename),m_pInterface(ip)
{
	m_FileObject.open(m_FileName,std::ofstream::binary);
}

CTreeEnumCall::~CTreeEnumCall()
{
	m_FileObject.close();
}

int CTreeEnumCall::callback(INode* node)
{
	INode* root=m_pInterface->GetRootNode();
	INode* Temp;
	int num = root->NumberOfChildren();
	int idx = num;
	wchar_t* newline=L"\n";
	for(int idx=0;idx<num;++idx){
		Temp=root->GetChildNode(idx);
		const wchar_t* name=Temp->GetName();
		m_FileObject.write(name,wcslen(name));
		m_FileObject.write(newline,wcslen(newline));
	}

	return 1;
}
