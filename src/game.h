#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "gameObject.h"
#include "ball.h"
#include "renderer.h"

class Game
{
public:
	bool keys[1024];
	bool keysProcessed[1024];
public:
	GameObject* m_player1;
	GameObject* m_player2;
	Renderer* m_renderer;
	Ball* m_ball;

public:
	Game(const int width = 1000, const int height = 800);
	~Game();

	void proccessInput(float dt);
	void updateObjects(float dt);
	void renderObjects();
	void init();

private:
	const int m_width;
	const int m_height;

	glm::vec3 m_player1Color = glm::vec3(1.0f, 0.0f, 0.0f);
	glm::vec3 m_player2Color = glm::vec3(0.0f, 0.0f, 1.0f);
	glm::vec2 m_paddleSize = glm::vec2(20.0f, 150.0f);
	float m_paddleSpeed = 250.0f;

	float m_radius = 13.5f;
	glm::vec3 m_ballColor = glm::vec3(1.0f);
};

