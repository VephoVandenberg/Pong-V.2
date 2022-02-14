#pragma once

#include <glm/glm.hpp>

#include "renderer.h"
#include "shader.h"

class Paddle
{
public:
	Paddle(glm::vec2 m_pos, glm::vec2 size, glm::vec3 color);
	~Paddle();

	void move(glm::vec2 newPos);
	void draw(Renderer& renderer, Shader &shader);

private:
	glm::vec2 m_pos;
	glm::vec2 m_size;
	glm::vec3 m_color;
};

