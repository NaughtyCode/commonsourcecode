#ifndef TREEENUMERATE_H
#define TREEENUMERATE_H

#include "MaxExporter.h"

class ITreeEnumProc;


class CTreeEnumCall:public ITreeEnumProc
{
public:
	CTreeEnumCall();
	~CTreeEnumCall();
	virtual int callback(INode* node);
	void SetFileName(const std::wstring& filename);
	void CreateFileIOObject();
private:
	std::wstring m_FileName;
	std::ofstream m_FileObject;
};

#endif