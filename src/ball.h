#pragma once

#include <glm/glm.hpp>

#include "shader.h"
#include "renderer.h"
#include "gameObject.h"

class Ball : public GameObject
{
public:
	glm::vec2 m_velocity;
	float m_radius;

public:
	Ball(float radius, glm::vec2 pos, glm::vec2 velocity, glm::vec3 color);
	~Ball();

	void move(float dt, float height);

};
