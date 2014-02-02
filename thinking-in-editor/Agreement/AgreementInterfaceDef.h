#ifndef AGREEMENTINTERFACEDEF_H
#define AGREEMENTINTERFACEDEF_H

#include<string>


//系统组件交互接口协议

//Interface接口类型定义
typedef void(*FEditorEngineMessageProcessType)(const std::string& message);
typedef void(*FCreateEditorInterfaceType)();
typedef void(*FReleaseEditorInterfaceType)();

//Proxy接口类型定义
typedef void(*FCreateRenderEngineType)(const std::string& message);

//EditorSynchronous接口类型定义
typedef void (*FSynchPushInterfaceMessageType)(int key, const std::string& message);

typedef void(*FSynchPushEngineMessageType)(int key, const std::string& message);

typedef void(*FSynchPushCancelMessageType)(int key, const std::string& message);

typedef void(*FSynchPopInterfaceMessageType)(int key, std::string& message);

typedef void(*FSynchPopEngineMessageType)(int key, std::string& message);

typedef void(*FSynchPopCancelMessageType)(int key, std::string& message);

//数据访问接口

//获取组件名
const char * GetEditorProxyName();
const char * GetEditorSynchronousName();
const char * GetEditorInterfaceName();

//获取Interface接口名
const char * GetCreateEditorInterfaceNameName();
const char * GetReleaseEditorInterfaceName();

//获取Proxy接口名
const char * GetCreateRenderEngineName();

//获取EditorSynchronous接口名
const char * GetSynchPushInterfaceMessageName();
const char * GetSynchPushEngineMessageName();
const char * GetSynchPushCancelMessageName();
const char * GetSynchPopInterfaceMessageName();
const char * GetSynchPopEngineMessageName();
const char * GetSynchPopCancelMessageName();

#endif