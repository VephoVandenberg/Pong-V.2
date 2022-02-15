#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
public:
	Shader() {};
	Shader(const char* vertexFile, const char* fragmentFile);
	~Shader();
	void use();
	void setMatrix4m(const char *uniform, glm::mat4& mat);
	void setVector2v(const char *uniform, glm::vec2& vector);
	void setVector3v(const char *uniform, glm::vec3& color);
	void setUniformf(const char* uniform, float value);

private:
	unsigned int ID;
};