#ifndef TEXTURE_H
#define TEXTURE_H

#include "DependencyConfig.h"

class texture_type
{
public:
    texture_type();
    virtual ~texture_type();
    
private:
    GLuint Texture; 
};

#endif