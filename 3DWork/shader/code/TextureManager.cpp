#include "TextureManager.h"

TextureManager* TextureManager::m_inst(0);

TextureManager* TextureManager::Inst()
{
	if(!m_inst)
		m_inst = new TextureManager();

	return m_inst;
}

TextureManager::TextureManager()
{
	#ifdef FREEIMAGE_LIB
		FreeImage_Initialise();
	#endif
}

TextureManager::~TextureManager()
{
	#ifdef FREEIMAGE_LIB
		FreeImage_DeInitialise();
	#endif
	UnloadAllTextures();
	m_inst = 0;
}

bool TextureManager::LoadTexture(const char* filename, const unsigned int texID, GLenum image_format, GLint internal_format, GLint level, GLint border)
{
	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
	FIBITMAP *Bitmap=0;
	BYTE* Data = 0;
	unsigned int width = 0;
	unsigned int height = 0;
	GLuint TextureHandle;
	fif = FreeImage_GetFileType(filename, 0);
	if(fif == FIF_UNKNOWN) 
		fif = FreeImage_GetFIFFromFilename(filename);
	if(fif == FIF_UNKNOWN)
		return false;

	if(FreeImage_FIFSupportsReading(fif))
		Bitmap = FreeImage_Load(fif, filename);

	if (!Bitmap){
		return false;
	}
	
	Data = FreeImage_GetBits(Bitmap);

	width = FreeImage_GetWidth(Bitmap);
	height = FreeImage_GetHeight(Bitmap);

	if ((Data == 0) || (width == 0) || (height == 0)){
		return false;
	}

	if (m_texID.find(texID) != m_texID.end()){
		glDeleteTextures(1, &(m_texID[texID]));
	}
	glGenTextures(1, &TextureHandle);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, TextureHandle);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, level, internal_format, width, height, border, image_format, GL_UNSIGNED_BYTE, Data);
	glBindImageTexture(0, TextureHandle, 0, GL_FALSE, 0, GL_WRITE_ONLY, internal_format);
	m_texID[texID] = TextureHandle;
	FreeImage_Unload(Bitmap);
	return true;
}

bool TextureManager::UnloadTexture(const unsigned int texID)
{
	bool result(true);
	if(m_texID.find(texID) != m_texID.end()){
		glDeleteTextures(1, &(m_texID[texID]));
		m_texID.erase(texID);
	}
	else{
		result = false;
	}
	return result;
}

bool TextureManager::BindTexture(const unsigned int texID)
{
	bool result(true);
	if(m_texID.find(texID) != m_texID.end())
		glBindTexture(GL_TEXTURE_2D, m_texID[texID]);
	else
		result = false;
	return result;
}

void TextureManager::UnloadAllTextures()
{
	std::map<unsigned int, GLuint>::iterator i = m_texID.begin();
	while(i != m_texID.end())
		UnloadTexture(i->first);
	m_texID.clear();
}

GLuint TextureManager::GetTextureHanle(const unsigned int texID)
{
	if (m_texID.find(texID) != m_texID.end()){
		return m_texID[texID];
	}
	return 0;
}