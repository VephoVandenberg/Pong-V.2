#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "Shader.h"

class Renderer
{
public:
	Renderer(float width, float height);
	~Renderer();

	void draw(glm::vec2 pos, glm::vec2& size, glm::vec3& color, Shader& shader);

private:
	unsigned int m_quadVAO;

	float m_width;
	float m_height;

private:
	void initRenderData();
};

