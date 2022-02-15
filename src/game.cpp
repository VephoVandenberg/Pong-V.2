#include <iostream>

#include "game.h"
#include "resourceManager.h"

Game::Game(const int width, const int height) :
	m_width(width), m_height(height)
{

}

Game::~Game()
{
	delete m_player1;
	delete m_player2;
	delete m_ball;
}

void Game::init()
{
	ResourceManager::loadShader("shaders/paddleVertex.vert", "shaders/paddleFragment.frag", "paddle");
	ResourceManager::loadShader("shaders/ball.vert", "shaders/ball.frag", "ball");

	glm::vec2 player1Pos(0.0f, m_height/2 - m_paddleSize.y/2);
	glm::vec2 player2Pos(m_width - m_paddleSize.x, m_height/2 - m_paddleSize.y/2);
	glm::vec2 ballPos(m_width / 2, m_height / 2);

	m_player1 = new GameObject(player1Pos, m_paddleSize, m_player1Color);
	m_player2 = new GameObject(player2Pos, m_paddleSize, m_player2Color);
	m_ball = new Ball(m_radius, ballPos, m_ballColor);
	m_renderer = new Renderer();
	
	glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(m_width), 
		static_cast<float>(m_height), 0.0f, -1.0f, 1.0f);

	ResourceManager::getShader("paddle").use();
	ResourceManager::getShader("paddle").setMatrix4m("projection", projection);

	ResourceManager::getShader("ball").use();
	ResourceManager::getShader("ball").setMatrix4m("projection", projection);
}

void Game::proccessInput(float dt)
{
	if (keys[GLFW_KEY_W])
	{
		float dSpeed = -m_paddleSpeed * dt;
		if (m_player1->m_pos.y >= 0.0f)
		{
			m_player1->m_pos.y += dSpeed;
		}
	}
	if (keys[GLFW_KEY_S])
	{
		float dSpeed = m_paddleSpeed * dt;
		if (m_player1->m_pos.y + m_player1->m_size.y <= m_height)
		{
			m_player1->m_pos.y += dSpeed;
		}
	}

	if (keys[GLFW_KEY_UP])
	{
		float dSpeed = -m_paddleSpeed * dt;
		if (m_player2->m_pos.y >= 0.0f)
		{
			m_player2->m_pos.y += dSpeed;
		}
	}
	if (keys[GLFW_KEY_DOWN])
	{
		float dSpeed = m_paddleSpeed * dt;
		if (m_player2->m_pos.y + m_player2->m_size.y <= m_height)
		{
			m_player2->m_pos.y += dSpeed;
		}
	}
}

void Game::updateObjects(float dt) 
{

}

void Game::renderObjects()
{
	m_player1->draw(*m_renderer, ResourceManager::getShader("paddle"));
	m_player2->draw(*m_renderer, ResourceManager::getShader("paddle"));
	m_ball->draw(*m_renderer, ResourceManager::getShader("ball"));
}

