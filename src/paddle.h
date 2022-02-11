#pragma once

#include <glm/glm.hpp>

class Paddle
{
public:
	Paddle();
	~Paddle();

	void move(glm::vec2 newPos);
private:
	glm::vec2 pos;

};

