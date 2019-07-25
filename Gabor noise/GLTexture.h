#pragma once
#include "Image.h"
#include "qgl.h"
namespace Karl07{

template<int size = 6>
class GLTexture
{
private:
	unsigned int m_id;
	unsigned char *data;
public:
	
	GLTexture(){ glGenTextures(1, &m_id); }
	void SetUse(bool f) { glBindTexture(GL_TEXTURE_2D, m_id * f);}
	void SetCubeUse(bool f) { glBindTexture(GL_TEXTURE_CUBE_MAP, m_id * f); }
	void ResetCube(const Image &d) {
		glBindTexture(GL_TEXTURE_CUBE_MAP, m_id);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, GL_RGBA, 1 << size, 1 << size, 0, GL_RGBA, GL_UNSIGNED_BYTE, d.m_data);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, GL_RGBA, 1 << size, 1 << size, 0, GL_RGBA, GL_UNSIGNED_BYTE, d.m_data);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, GL_RGBA, 1 << size, 1 << size, 0, GL_RGBA, GL_UNSIGNED_BYTE, d.m_data);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, GL_RGBA, 1 << size, 1 << size, 0, GL_RGBA, GL_UNSIGNED_BYTE, d.m_data);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, GL_RGBA, 1 << size, 1 << size, 0, GL_RGBA, GL_UNSIGNED_BYTE, d.m_data);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, GL_RGBA, 1 << size, 1 << size, 0, GL_RGBA, GL_UNSIGNED_BYTE, d.m_data);
		
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
	}
	void Reset(const Image & d)
	{
		glBindTexture(GL_TEXTURE_2D, m_id);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 1 << size, 1 << size, 0, GL_RGBA, GL_UNSIGNED_BYTE, d.m_data);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
	}
	
	~GLTexture() { glDeleteTextures(1, &m_id); }
};

}