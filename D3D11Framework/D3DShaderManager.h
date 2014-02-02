#ifndef D3DSHADERMANAGER_H
#define D3DSHADERMANAGER_H

#include "D3DRenderheaders.h"

class TRenderDevice;

class TD3DShaderManager
{
public:
    TD3DShaderManager(TRenderDevice* device);
    ~TD3DShaderManager();
private:
    TRenderDevice* Device;
};

#endif