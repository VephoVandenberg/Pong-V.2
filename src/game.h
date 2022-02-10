#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Game
{
public:
	GLFWwindow* m_window;
public:
	Game(const int width = 800, const int height = 800);
	void proccessInput();
	void init();
	~Game();
private:
	const int m_width;
	const int m_height;
};

