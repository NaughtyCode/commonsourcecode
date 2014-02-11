#ifndef TREEENUMERATE_H
#define TREEENUMERATE_H

#include "MaxExporter.h"

class ITreeEnumProc;


class CTreeEnumCall:public ITreeEnumProc
{
public:
	CTreeEnumCall(const std::wstring& filename,Interface* ip);
	~CTreeEnumCall();
	virtual int callback(INode* node);
	void SetFileName(const std::wstring& filename);
	void CreateFileIOObject();
private:
	std::wstring   m_FileName;
	std::wofstream m_FileObject;
	Interface*     m_pInterface;
};

#endif