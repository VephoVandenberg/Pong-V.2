#pragma once

#include <glm/glm.hpp>

#include "renderer.h"

class Paddle
{
public:
	Paddle(glm::vec2 m_pos);
	~Paddle();

	void move(glm::vec2 newPos);
	void draw(Renderer& renderer);
private:
	glm::vec2 m_pos;

};

