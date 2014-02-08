#include "Shader.h"
#include "FileIO.h"
#include "TextureManager.h"

static GLuint      RenderHandle = 0;

GLuint genRenderProg(GLuint texHandle) {
	GLuint progHandle = glCreateProgram();
	GLuint vp = glCreateShader(GL_VERTEX_SHADER);
	GLuint fp = glCreateShader(GL_FRAGMENT_SHADER);
	const char *vpcode= ReadFileData("resource\\shader\\vertexshader.glsl");
	const char *fpcode = ReadFileData("resource\\shader\\fragmentshader.glsl");
	glShaderSource(vp,1, &vpcode, 0);
	glShaderSource(fp,1, &fpcode, 0);

	glCompileShader(vp);
	int rvalue=0;
	glGetShaderiv(vp, GL_COMPILE_STATUS, &rvalue);
	assert(rvalue);
	glAttachShader(progHandle, vp);

	rvalue=0;
	glCompileShader(fp);
	glGetShaderiv(fp, GL_COMPILE_STATUS, &rvalue);
	assert(rvalue);

	glAttachShader(progHandle, fp);

	glBindFragDataLocation(progHandle, 0, "color");
	glLinkProgram(progHandle);

	rvalue = 0;
	glGetProgramiv(progHandle, GL_LINK_STATUS, &rvalue);
	assert(rvalue);

	glUseProgram(progHandle);
	glUniform1i(glGetUniformLocation(progHandle, "srcTex"), 0);

	GLuint posBuf;
	glGenBuffers(1, &posBuf);
	glBindBuffer(GL_ARRAY_BUFFER, posBuf);
	float data[] = {
		-1.0f, -1.0f,
		-1.0f, 1.0f,
		1.0f, -1.0f,
		1.0f, 1.0f
	};
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)* 8, data, GL_STREAM_DRAW);
	GLint posPtr = glGetAttribLocation(progHandle, "pos");
	glVertexAttribPointer(posPtr, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(posPtr);

	return progHandle;
}

void CreateShader(){
	TextureManager* TextMgr = TextureManager::Inst();
	unsigned int TexID = 1;
	GLuint texHandle;
	if (TextMgr->LoadTexture("resource//cy2.png", TexID, GL_RGB, GL_RGB, 0, 0)){
		texHandle=TextMgr->GetTextureHanle(TexID);
	}
	else{
		return;
	}
	RenderHandle = genRenderProg(texHandle);
}

void RenderFrame() {
	if (RenderHandle){
		glUseProgram(RenderHandle);
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	}
}

GLuint CompileShader(const char* source, const GLenum type){
	GLint compile_status;
	GLuint handle = glCreateShader(type);
	glShaderSource(handle, 1, &source, 0);
	glCompileShader(handle);

	glGetShaderiv(handle, GL_COMPILE_STATUS, &compile_status);
	if (compile_status == GL_FALSE)
	{
		GLchar messages[256];
		glGetShaderInfoLog(handle, sizeof(messages), 0, &messages[0]);
		fprintf(stderr, "%s\n", messages);
		exit(EXIT_FAILURE);
	}
	return handle;
}

GLuint LoadShader(const char * vert_filename, const char * frag_filename){
	GLuint handle = glCreateProgram();
	GLint link_status;

	if (vert_filename && strlen(vert_filename))
	{
		char *vert_source = ReadFileData(vert_filename);
		GLuint vert_shader = CompileShader(vert_source, GL_VERTEX_SHADER);
		glAttachShader(handle, vert_shader);
		free(vert_source);
	}
	if (frag_filename && strlen(frag_filename))
	{
		char *frag_source = ReadFileData(frag_filename);
		GLuint frag_shader = CompileShader(frag_source, GL_FRAGMENT_SHADER);
		glAttachShader(handle, frag_shader);
		free(frag_source);
	}

	glLinkProgram(handle);

	glGetProgramiv(handle, GL_LINK_STATUS, &link_status);
	if (link_status == GL_FALSE)
	{
		GLchar messages[256];
		glGetProgramInfoLog(handle, sizeof(messages), 0, &messages[0]);
		fprintf(stderr, "%s\n", messages);
		exit(1);
	}
	return handle;
}