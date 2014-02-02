#ifndef EDITORSYNCHRONOUS_H
#define EDITORSYNCHRONOUS_H

#ifdef EDITORSYNC_EXPORTS
#define EDITORSYNCAPI __declspec(dllexport) 
#else
#define EDITORSYNCAPI __declspec(dllimport) 
#endif

#ifdef __cplusplus
extern "C" {
#endif

//编辑器相关
	EDITORSYNCAPI void EditorBeginPack();
	EDITORSYNCAPI void EditorBeginUnPack();
EDITORSYNCAPI void EditorPackInt(void *data,int size);
EDITORSYNCAPI void EditorPackUint(void *data,int size);
EDITORSYNCAPI void EditorPackFloat(void *data,int size);
EDITORSYNCAPI void EditorPackStr(const char* value);
EDITORSYNCAPI int  EditorUnPackInt(void *data,int size);
EDITORSYNCAPI int  EditorUnPackUint(void *data,int size);
EDITORSYNCAPI int  EditorUnPackFloat(void *data,int size);
EDITORSYNCAPI int  EditorUnPackStr(void *buffer);

//引擎相关
EDITORSYNCAPI void EngineBeginPack();
EDITORSYNCAPI void EngineBeginUnPack();
EDITORSYNCAPI void EnginePackInt(void *data,int size);
EDITORSYNCAPI void EnginePackUint(void *data,int size);
EDITORSYNCAPI void EnginePackFloat(void *data,int size);
EDITORSYNCAPI void EnginePackStr(const char* value);
EDITORSYNCAPI int  EngineUnPackInt(void *data,int size);
EDITORSYNCAPI int  EngineUnPackUint(void *data,int size);
EDITORSYNCAPI int  EngineUnPackFloat(void *data,int size);
EDITORSYNCAPI int  EngineUnPackStr(void *buffer);

#ifdef __cplusplus
}
#endif



#endif