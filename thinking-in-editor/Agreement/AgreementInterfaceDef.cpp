#include"AgreementInterfaceDef.h"

//�����
static std::string EditorProxyName               = "EditorProxy";
static std::string EditorSynchronousName         = "EditorSynchronous";
static std::string EditorInterfaceName           = "EditorInterface";

//Interface�ӿ���
static std::string CreateEditorInterfaceName     = "CreateEditorInterface";
static std::string ReleaseEditorInterfaceName    = "ReleaseEditorInterface";

//Proxy�ӿ���
static std::string CreateRenderEngineName        = "CreateRenderEngine";

//EditorSynchronous�ӿ���
static std::string SynchPushInterfaceMessageName = "SynchPushInterfaceMessage";
static std::string SynchPushEngineMessageName    = "SynchPushEngineMessage";
static std::string SynchPushCancelMessageName    = "SynchPushCancelMessage";
static std::string SynchPopInterfaceMessageName  = "SynchPopInterfaceMessage";
static std::string SynchPopEngineMessageName     = "SynchPopEngineMessage";
static std::string SynchPopCancelMessageName     = "SynchPopCancelMessage";

//��ȡ�����
const char * GetEditorProxyName()
{
	return EditorProxyName.c_str();
}

const char * GetEditorSynchronousName()
{
	return EditorSynchronousName.c_str();
}

const char * GetEditorInterfaceName()
{
	return EditorInterfaceName.c_str();
}

//��ȡInterface�ӿ���
const char * GetCreateEditorInterfaceNameName()
{
	return CreateEditorInterfaceName.c_str();
}

const char * GetReleaseEditorInterfaceName()
{
	return ReleaseEditorInterfaceName.c_str();
}

//��ȡProxy�ӿ���
const char * GetCreateRenderEngineName()
{
	return CreateRenderEngineName.c_str();
}

//��ȡEditorSynchronous�ӿ���

const char * GetSynchPushInterfaceMessageName()
{
	return SynchPushInterfaceMessageName.c_str();
}

const char * GetSynchPushEngineMessageName()
{
	return SynchPushEngineMessageName.c_str();
}

const char * GetSynchPushCancelMessageName()
{
	return SynchPushCancelMessageName.c_str();
}

const char * GetSynchPopInterfaceMessageName()
{
	return SynchPopInterfaceMessageName.c_str();
}

const char * GetSynchPopEngineMessageName()
{
	return SynchPopEngineMessageName.c_str();
}

const char * GetSynchPopCancelMessageName()
{
	return SynchPopCancelMessageName.c_str();
}
