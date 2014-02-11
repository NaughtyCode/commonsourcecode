#include "TreeEnumCall.h"

CTreeEnumCall::CTreeEnumCall(const std::wstring& filename,Interface* ip):m_FileName(filename),m_pInterface(ip)
{
	
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
	int idx = num-1;
	wchar_t* newline=L"\n";

	while(idx>=0){
		Temp=root->GetChildNode(idx);
		const wchar_t* name=Temp->GetName();
		m_FileObject.write(name,wcslen(name));
		m_FileObject.write(newline,wcslen(newline));
		--idx;
	}


	return 1;
}



void CTreeEnumCall::CreateFileIOObject()
{
	m_FileObject.open(m_FileName,std::ofstream::binary);
}








