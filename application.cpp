#include <iostream>
#include "src/game.h"

const int width = 500;
const int height = 500;

int main(int argc, char** argv)
{
	if (!glfwInit())
	{
		std::cout << "Could not initialize GLFW!" << std::endl;
		return -1;
	}

	Game app(width, height);
	glfwMakeContextCurrent(app.m_window);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Could not initialize GLEW!" << std::endl;
		return -1;
	}

	while (!glfwWindowShouldClose(app.m_window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(app.m_window);
		app.proccessInput();
		glfwPollEvents();
	}

	return 0;
}