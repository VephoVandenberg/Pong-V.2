#include "paddle.h"

Paddle::Paddle(glm::vec2 pos, glm::vec2 size, glm::vec3 color) :
	m_pos(pos), m_size(size), m_color(color)
{

}

Paddle::~Paddle()
{

}

void Paddle::move(glm::vec2 newPos)
{

}

void Paddle::draw(Renderer& renderer, Shader &shader)
{
	renderer.draw(m_pos, m_size, m_color, shader);
}