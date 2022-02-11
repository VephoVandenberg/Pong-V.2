#include "game.h"

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
	m_player1 = new Paddle();
	m_player2 = new Paddle();
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

