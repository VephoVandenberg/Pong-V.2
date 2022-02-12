#include "game.h"
#include "resourceManager.h"

Game::Game(GLFWwindow *window, const int width, const int height) :
	m_window(window), m_width(width), m_height(height)
{
	init();
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
	glm::mat4 model = glm::ortho(0.0f, static_cast<float>(m_width), static_cast<float>(m_height), 0.0f, 0.0f, 1.0f);

	glm::vec2 player1Pos(0.0f, 0.0f);
	glm::vec2 player2Pos(0.0f, 0.0f);

	m_player1 = new Paddle(player1Pos);
	m_player2 = new Paddle(player2Pos);
	m_renderer = new Renderer();
}

void Game::proccessInput()
{

}

void Game::updateObjects() 
{

}

void Game::renderObjects()
{

}

