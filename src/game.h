#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class game
{
public:
	GLFWwindow* window;
public:
	game(const int width = 800, const int height = 800);
	void proccessInput();
	~game();
private:
	const int width;
	const int height;
};

