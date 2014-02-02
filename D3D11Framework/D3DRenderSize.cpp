#include "D3DRenderSize.h"

TD3DRenderSize::TD3DRenderSize():Width(1440),Height(900)
{
	
}

TD3DRenderSize::~TD3DRenderSize()
{
	
}

void TD3DRenderSize::RefreshRenderSize(UINT width, UINT height)
{
	this->Width  = width;
	this->Height = height;
}

UINT TD3DRenderSize::GetRenderWidth()
{
	return Width;
}

UINT TD3DRenderSize::GetRenderHeight()
{
	return Height;
}