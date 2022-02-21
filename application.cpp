#include <iostream>
#include "src/game.h"

const int width = 1000;
const int height = 800;

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);

Game app(width, height);

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

	glfwSetKeyCallback(window, keyCallback);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	app.init();

	float dt = 0.0f;
	float lastFrame = 0.0f;

	while (!glfwWindowShouldClose(window))
	{
		float currentTime = glfwGetTime();
		dt = currentTime - lastFrame;
		lastFrame = currentTime;

		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		app.renderObjects();

		glfwSwapBuffers(window);

		glfwPollEvents();
		app.proccessInput(dt);
		app.updateObjects(dt);
	}

	return 0;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key >= 0 && key <= 1024)
	{
		if (action == GLFW_PRESS)
		{
			app.keys[key] = true;
		}
		else if (action == GLFW_RELEASE)
		{
			app.keys[key] = false;
			app.keysProcessed[key] = false;
		}
	}
}