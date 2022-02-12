#include "shader.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

Shader::Shader(const char* vPath, const char* fPath)
{
	std::string vSrc, fSrc;
	std::ifstream vFile, fFile;

	vFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		vFile.open(vPath);
		fFile.open(fPath);

		std::stringstream vStream, fStream;

		vStream << vFile.rdbuf();
		fStream << fFile.rdbuf();

		vFile.close();
		fFile.close();

		vSrc = vStream.str();
		fSrc = fStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "file or files weren't read succesfully." << std::endl;
	}

	char infolog[512];
	int success;

	const char* vStr = vSrc.c_str();
	const char* fStr = fSrc.c_str();

	unsigned int vShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vShader, 1, &vStr, NULL);
	glCompileShader(vShader);
	glGetShaderiv(vShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vShader, 512, NULL, infolog);
		std::cout << "VERTES:" << infolog;
	}

	unsigned int fShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fShader, 1, &fStr, NULL);
	glCompileShader(fShader);
	glGetShaderiv(fShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fShader, 512, NULL, infolog);
		std::cout << "FRAGMENT:" << infolog;
	}

	unsigned int ID = glCreateProgram();
	glAttachShader(ID, vShader);
	glAttachShader(ID, fShader);
	glLinkProgram(ID);

	glDeleteShader(vShader);
	glDeleteShader(fShader);
}

Shader::~Shader()
{

}
