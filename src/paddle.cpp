#include "paddle.h"

Paddle::Paddle(glm::vec2 pos) :
	m_pos(pos)
{

}

Paddle::~Paddle()
{

}

void Paddle::move(glm::vec2 newPos)
{

}

void Paddle::draw(Renderer& renderer)
{
	renderer.draw(m_pos);
}