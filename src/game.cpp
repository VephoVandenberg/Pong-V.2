#include "game.h"
#include "resourceManager.h"

Game::Game(GLFWwindow *window, const int width, const int height) :
	m_window(window), m_width(width), m_height(height)
{

}

Game::~Game()
{
	delete m_player1;
	delete m_player2;
	delete m_ball;
	glfwDestroyWindow(m_window);
}

void Game::init()
{
	ResourceManager::loadShader("shaders/paddleVertex.vert", "shaders/paddleFragment.frag", "paddle");

	glm::vec2 player1Pos(0.0f, 0.0f);
	glm::vec2 player2Pos(200.0f, 200.0f);
	
	glm::vec3 player1Col(1.0f, 0.0f, 0.0f);
	glm::vec3 player2Col(0.0f, 0.0f, 1.0f);

	glm::vec2 paddleSize(20.0f, 100.0f);

	m_player1 = new Paddle(player1Pos, paddleSize, player1Col);
	m_player2 = new Paddle(player2Pos, paddleSize, player2Col);
	m_renderer = new Renderer();
	
	glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(m_width), 
		static_cast<float>(m_height), 0.0f, -1.0f, 1.0f);
	ResourceManager::getShader("paddle").use();
	ResourceManager::getShader("paddle").setMatrix4m("projection", projection);
}

void Game::proccessInput()
{

}

void Game::updateObjects() 
{

}

void Game::renderObjects()
{
	m_player1->draw(*m_renderer, ResourceManager::getShader("paddle"));
	m_player2->draw(*m_renderer, ResourceManager::getShader("paddle"));
}

