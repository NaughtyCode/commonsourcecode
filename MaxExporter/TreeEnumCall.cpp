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
	this->CreateFileIOObject();
	TimeValue time = m_pInterface->GetTime();
	ObjectState state = node->EvalWorldState(time);
	if (state.obj->SuperClassID()==GEOMOBJECT_CLASS_ID)
	{
		GeomObject* object;
		object = (GeomObject*)state.obj;
		const wchar_t* name=object->GetObjectName();
		m_FileObject.write((char*)name,wcslen(name));
	}


	return 1;
}



void CTreeEnumCall::CreateFileIOObject()
{
	m_FileObject.open(m_FileName,std::ofstream::binary);
}








