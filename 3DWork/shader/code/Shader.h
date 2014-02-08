#ifndef COMPUTESHADER_H
#define COMPUTESHADER_H

#include "DependencyConfig.h"

void CreateShader();
void RenderFrame();
GLuint CompileShader(const char* source, const GLenum type);
GLuint LoadShader(const char * vert_filename, const char * frag_filename);

#endif
