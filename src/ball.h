#pragma once

#include <glm/glm.hpp>

#include "shader.h"
#include "renderer.h"
#include "gameObject.h"

class Ball
{
public:
	glm::vec2 m_pos;
	glm::vec2 m_velocity;
	glm::vec2 m_size;

public:
	Ball(float radius, glm::vec2 pos, glm::vec2 velocity, glm::vec3 color);
	~Ball();

	void draw(Renderer& renderer, Shader& shader);
	void move(float dt, float height);

private:
	float m_radius;
	glm::vec3 m_color;
};
