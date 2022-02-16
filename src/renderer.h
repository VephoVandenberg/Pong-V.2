#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "Shader.h"

class Renderer
{
public:
	Renderer();
	~Renderer();

	void draw(glm::vec2 pos, glm::vec2& size, glm::vec3& color, Shader& shader);

private:
	unsigned int m_quadVAO;

private:
	void initRenderData();
};

