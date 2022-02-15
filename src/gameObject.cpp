#include "gameObject.h"

GameObject::GameObject(glm::vec2 pos, glm::vec2 size, glm::vec3 color) :
	m_pos(pos), m_size(size), m_color(color)
{

}

GameObject::~GameObject()
{

}

void GameObject::draw(Renderer& renderer, Shader& shader)
{
	renderer.draw(m_pos, m_size, m_color, shader);
}