#include <iostream>
#include "src/game.h"

const int width = 800;
const int height = 800;

int main(int argc, char** argv)
{
	if (!glfwInit())
	{
		std::cout << "Could not initialize GLFW!" << std::endl;
		return -1;
	}

	GLFWwindow* window = glfwCreateWindow(width, height, "Pong2", NULL, NULL);
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Could not initialize GLEW!" << std::endl;
		return -1;
	}

	Game app(window, width, height);
	app.init();

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		app.proccessInput();
		app.updateObjects();

		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		app.renderObjects();

		glfwSwapBuffers(window);
	}

	return 0;
}