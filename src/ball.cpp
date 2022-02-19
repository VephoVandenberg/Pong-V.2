#include "ball.h"


Ball::Ball(float radius, glm::vec2 pos, glm::vec2 velocity, glm::vec3 color) :
	GameObject(pos, glm::vec2(radius*2), color), m_radius(radius), m_velocity(velocity)
{

}

Ball::~Ball()
{

}

void Ball::move(float dt, float height)
{
	m_pos += m_velocity * dt;

	if (m_pos.y <= 0.0f)
	{
		m_velocity.y = -m_velocity.y;
		m_pos.y = 0.0f;
	}
	else if (m_pos.y+2*m_radius >= height)
	{
		m_velocity.y = -m_velocity.y;
		m_pos.y = height-2*m_radius;
	}
}

void Ball::draw(Renderer& renderer, Shader& shader)
{
	renderer.draw(m_pos, m_size, m_color, shader);
} 