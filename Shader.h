#pragma once
#include <fstream>
#include "GPrint.h"
#include <GL\glew.h>
#include <string>

class Shader
{
public:
	Shader();
	virtual ~Shader();

	void Bind();
	void createProgram(const char* frag, const char* vert);
private:
	static const unsigned int NUM_SHADERS = 2;
	GLuint m_shader[NUM_SHADERS];
	GLuint m_program;
};

