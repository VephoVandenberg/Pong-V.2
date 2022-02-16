#include "ball.h"


Ball::Ball(float radius, glm::vec2 pos, glm::vec3 color):
	m_radius(radius), m_pos(pos), m_color(color)
{

}

Ball::~Ball()
{

}


void Ball::draw(Renderer& renderer, Shader& shader)
{
	glm::vec2 size = glm::vec2(m_radius);
	renderer.draw(m_pos, size, m_color, shader);
}