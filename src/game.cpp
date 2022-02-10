#include "game.h"


Game::Game(const int width, const int height) :
	m_width(width), m_height(height)
{
	m_window = glfwCreateWindow(width, height, "Pong2", NULL, NULL);
}

Game::~Game()
{
	glfwDestroyWindow(m_window);
}

void Game::init()
{

}

void Game::proccessInput()
{

}

