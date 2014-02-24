#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN

// Windows head fiels
#include <windows.h>

// C head fiels
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <assert.h>
#include <stdio.h>

// Direct3D 11 head fiels
#include <d3d11.h>
#include <D3Dcompiler.h>
#include <D3DX11async.h>
#include <xnamath.h>

void DumpErrorInfo(HRESULT hr);

#ifndef SAFE_DELETE
#define SAFE_DELETE(p)       { if (p) { delete (p);     (p)=NULL; } }
#endif
#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(p) { if (p) { delete[] (p);   (p)=NULL; } }
#endif
#ifndef SAFE_RELEASE
#define SAFE_RELEASE(p)      { if (p) { (p)->Release(); (p)=NULL; } }
#endif

