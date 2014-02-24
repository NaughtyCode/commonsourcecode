#pragma once
#include "D3DDevice.h"
#include "TShader.h"

class TD3DDevice;
class TShader;

struct Vertex{
	FLOAT position[4];
};

class TRenderResource
{
public:
	TRenderResource(TD3DDevice* device, TShader * shader);
	~TRenderResource();
	int CreateRenderResource();
	int CreateVertexBuffer();
	void PostRenderResource();

private:
	TD3DDevice* Device;
	TShader * Shader;
	ID3D11InputLayout* VertexLayout;
	ID3D11Buffer* VertexBuffer;
};

