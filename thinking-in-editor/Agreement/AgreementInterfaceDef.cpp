#include"AgreementInterfaceDef.h"

//组件名
static std::string EditorProxyName               = "EditorProxy";
static std::string EditorSynchronousName         = "EditorSynchronous";
static std::string EditorInterfaceName           = "EditorInterface";

//Interface接口名
static std::string CreateEditorInterfaceName     = "CreateEditorInterface";
static std::string ReleaseEditorInterfaceName    = "ReleaseEditorInterface";

//Proxy接口名
static std::string CreateRenderEngineName        = "CreateRenderEngine";

//EditorSynchronous接口名
static std::string SynchPushInterfaceMessageName = "SynchPushInterfaceMessage";
static std::string SynchPushEngineMessageName    = "SynchPushEngineMessage";
static std::string SynchPushCancelMessageName    = "SynchPushCancelMessage";
static std::string SynchPopInterfaceMessageName  = "SynchPopInterfaceMessage";
static std::string SynchPopEngineMessageName     = "SynchPopEngineMessage";
static std::string SynchPopCancelMessageName     = "SynchPopCancelMessage";

//获取组件名
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

//获取Interface接口名
const char * GetCreateEditorInterfaceNameName()
{
	return CreateEditorInterfaceName.c_str();
}

const char * GetReleaseEditorInterfaceName()
{
	return ReleaseEditorInterfaceName.c_str();
}

//获取Proxy接口名
const char * GetCreateRenderEngineName()
{
	return CreateRenderEngineName.c_str();
}

//获取EditorSynchronous接口名

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
