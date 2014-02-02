#ifndef CONTROLMAIN_H
#define CONTROLMAIN_H

#ifdef EDITORINTERFACE_EXPORTS
#define EDITORINTERFACEAPI __declspec(dllexport) 
#else
#define EDITORINTERFACEAPI __declspec(dllimport) 
#endif

#ifdef __cplusplus
extern "C" {
#endif

EDITORINTERFACEAPI void EditorEngineMessageProcess(const char* message);
EDITORINTERFACEAPI void CreateEditorInterface();
EDITORINTERFACEAPI void ReleaseEditorInterface();

#ifdef __cplusplus
}
#endif

#endif