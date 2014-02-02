#ifndef D3DRENDERSIZE_H
#define D3DRENDERSIZE_H

#include "D3DRenderheaders.h"

class TD3DRenderSize
{
public:
    TD3DRenderSize();
    ~TD3DRenderSize();
    
    void RefreshRenderSize(UINT width,UINT height);
    
    UINT GetRenderWidth();
    UINT GetRenderHeight();
    
private:
    UINT Width;
    UINT Height;
};

#endif