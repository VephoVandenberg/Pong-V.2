#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <tuple>

#include "gameObject.h"
#include "ball.h"
#include "renderer.h"


enum class Direction
{
	UP,
	RIGHT,
	DOWN,
	LEFT
};

class Game
{
public:
	bool keys[1024];
	bool keysProcessed[1024];	
	
	typedef std::tuple<bool, Direction, glm::vec2> Collision;

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
	void doCollisions();
	bool checkCollision(GameObject& one, GameObject& two);
	Collision checkCollision(Ball& ball, GameObject& paddle);
	Direction vectorDirection(glm::vec2 target);

private:
	const int m_width;
	const int m_height;

	float m_paddleVelocity = 350.0f;
	glm::vec3 m_player1Color = glm::vec3(1.0f, 0.0f, 0.0f);
	glm::vec3 m_player2Color = glm::vec3(0.0f, 0.0f, 1.0f);
	glm::vec2 m_paddleSize = glm::vec2(20.0f, 150.0f);
	

	float m_radius = 15.0f;
	glm::vec2 m_ballVelocity = glm::vec2(300.0f, 300.0f);
	glm::vec3 m_ballColor = glm::vec3(1.0f);

	int m_player1Score = 0;
	int m_player2Score = 0;
	glm::vec3 m_textColor = glm::vec3(1.0f, 1.0f, 0.0f);
};

