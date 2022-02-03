#include "game.h"


game::game(const int width, const int height) :
	width(width), height(height)
{
	window = glfwCreateWindow(width, height, "Pong2", NULL, NULL);
}

game::~game()
{
	glfwDestroyWindow(window);
}

void game::proccessInput()
{

}