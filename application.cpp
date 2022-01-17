#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


const int width = 500;
const int height = 500;

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

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}


	std::cout << "OK";
	return 0;
}