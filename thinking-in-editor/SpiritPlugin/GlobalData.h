#ifndef PROXYGLOBALDATA_H
#define PROXYGLOBALDATA_H

#include"SpiritPlugin.h"
#include"AgreementInterfaceDef.h"

void ResetAllGlobalData();

void SetFilePath(const std::string& path);

int GetWorkScene();
void SetWorkScene(int workscene);

int GetRootScene();
void SetRootScene(int workscene);

int GetSelectedObject();
void SetSelectedObject(int obj);

bool IsCapture();
void SetCapture(bool capture);

void GetMousePos(float& x,float& y);

void GetDeltaMousePos(float& x,float& y);

float GetMouseX();

float GetMouseY();

void SetMousePos(float x,float y);

void PushEngineMessage(int key, const std::string& message);

void GetInterfaceMessage(int key, std::string& message);

void PushCancelMessage(int key, const std::string& message);

void GetCancelMessage(int key, std::string& message);

#endif