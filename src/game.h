#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "paddle.h"
#include "ball.h"
#include "renderer.h"

class Game
{
public:
	GLFWwindow* m_window;

	Paddle* m_player1;
	Paddle* m_player2;
	Renderer* m_renderer;
	Ball* m_ball;

public:
	Game(GLFWwindow* window, const int width = 800, const int height = 800);
	~Game();
	void proccessInput();
	void updateObjects();
	void renderObjects();
	void init();
private:
	const int m_width;
	const int m_height;

private:
	
};

