#include "TreeEnumCall.h"

CTreeEnumCall::CTreeEnumCall()
{
	
}

CTreeEnumCall::~CTreeEnumCall()
{
	m_FileObject.close();
}

int CTreeEnumCall::callback(INode* node)
{
	this->CreateFileIOObject();
	






	return 1;
}



void CTreeEnumCall::CreateFileIOObject()
{
	m_FileObject.open(m_FileName,std::ofstream::binary);
}

void CTreeEnumCall::SetFileName(const std::wstring& filename)
{
	m_FileName.assign(filename);
}
