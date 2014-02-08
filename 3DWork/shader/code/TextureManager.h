#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "DependencyConfig.h"

class TextureManager
{
public:
	static TextureManager* Inst();
	virtual ~TextureManager();

	bool LoadTexture(const char* filename,	//where to load the file from
		const unsigned int texID,			//arbitrary id you will reference the texture by
											//does not have to be generated with glGenTextures
		GLenum image_format = GL_RGB,		//format the image is in
		GLint internal_format = GL_RGB,		//format to store the image in
		GLint level = 0,					//mipmapping level
		GLint border = 0);					//border size

	bool UnloadTexture(const unsigned int texID);

	bool BindTexture(const unsigned int texID);

	void UnloadAllTextures();

	GLuint GetTextureHanle(const unsigned int texID);

protected:
	TextureManager();
	TextureManager(const TextureManager& tm);
	TextureManager& operator=(const TextureManager& tm);

	static TextureManager* m_inst;
	std::map<unsigned int, GLuint> m_texID;
};

#endif