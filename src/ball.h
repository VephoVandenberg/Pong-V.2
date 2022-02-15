#pragma once

#include <glm/glm.hpp>

#include "shader.h"
#include "renderer.h"

class Ball
{
public:
	Ball(float radius, glm::vec2 pos, glm::vec3 color);
	~Ball();

	void move(glm::vec2);
	void draw(Renderer& renderer, Shader& shader);
private:
	float m_radius;
	glm::vec2 m_pos;
	glm::vec3 m_color;
};
