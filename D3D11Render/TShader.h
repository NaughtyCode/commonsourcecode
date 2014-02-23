#pragma once
#include "D3DDevice.h"

class TD3DDevice;

class TShader
{
public:
	TShader(TD3DDevice* device);
	~TShader();
	int CompileShaderFromFile(const WCHAR* szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut);
	int CreateShaders(const WCHAR* VSFilename, const WCHAR* PSFilename, const char* vs, const char* ps);
	void PostShaders();
	ID3DBlob* GetVSBlob();
	ID3DBlob* GetPSBlob();

	void Release();
private:
	TD3DDevice* Device;
	ID3D11VertexShader* VertexShader;
	ID3D11PixelShader* PixelShader;
	ID3DBlob* VSBlob;
	ID3DBlob* PSBlob;
};

