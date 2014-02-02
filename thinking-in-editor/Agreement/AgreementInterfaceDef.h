#ifndef AGREEMENTINTERFACEDEF_H
#define AGREEMENTINTERFACEDEF_H

#include<string>


//ϵͳ��������ӿ�Э��

//Interface�ӿ����Ͷ���
typedef void(*FEditorEngineMessageProcessType)(const std::string& message);
typedef void(*FCreateEditorInterfaceType)();
typedef void(*FReleaseEditorInterfaceType)();

//Proxy�ӿ����Ͷ���
typedef void(*FCreateRenderEngineType)(const std::string& message);

//EditorSynchronous�ӿ����Ͷ���
typedef void (*FSynchPushInterfaceMessageType)(int key, const std::string& message);

typedef void(*FSynchPushEngineMessageType)(int key, const std::string& message);

typedef void(*FSynchPushCancelMessageType)(int key, const std::string& message);

typedef void(*FSynchPopInterfaceMessageType)(int key, std::string& message);

typedef void(*FSynchPopEngineMessageType)(int key, std::string& message);

typedef void(*FSynchPopCancelMessageType)(int key, std::string& message);

//���ݷ��ʽӿ�

//��ȡ�����
const char * GetEditorProxyName();
const char * GetEditorSynchronousName();
const char * GetEditorInterfaceName();

//��ȡInterface�ӿ���
const char * GetCreateEditorInterfaceNameName();
const char * GetReleaseEditorInterfaceName();

//��ȡProxy�ӿ���
const char * GetCreateRenderEngineName();

//��ȡEditorSynchronous�ӿ���
const char * GetSynchPushInterfaceMessageName();
const char * GetSynchPushEngineMessageName();
const char * GetSynchPushCancelMessageName();
const char * GetSynchPopInterfaceMessageName();
const char * GetSynchPopEngineMessageName();
const char * GetSynchPopCancelMessageName();

#endif