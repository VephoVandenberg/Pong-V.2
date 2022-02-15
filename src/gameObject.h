#pragma once

#include <glm/glm.hpp>

#include "renderer.h"
#include "shader.h"

class GameObject
{
public:
	GameObject(glm::vec2 m_pos, glm::vec2 size, glm::vec3 color);
	~GameObject();

	void move(glm::vec2 newPos);
	void draw(Renderer& renderer, Shader& shader);

private:
	glm::vec2 m_pos;
	glm::vec2 m_size;
	glm::vec3 m_color;
};
