#pragma once

#include <GL/glew.h>

class Shader
{
public:
	Shader(const char* vertexFile, const char* fragmentFile);
	~Shader();
	void use();
private:
	unsigned int ID;
};