#include <iostream>

#include "game.h"
#include "resourceManager.h"

Game::Game(const int width, const int height) :
	m_width(width), m_height(height)
{

}

Game::~Game()
{	
	delete m_player1;
	delete m_player2;
	delete m_ball;
}

void Game::init()
{
	ResourceManager::loadShader("shaders/paddle.vert", "shaders/paddle.frag", "paddle");
	ResourceManager::loadShader("shaders/ball.vert", "shaders/ball.frag", "ball");
	ResourceManager::loadShader("shaders/text.vert", "shaders/text.frag", "text2D");

	glm::vec2 player1Pos(0.0f, m_height/2 - m_paddleSize.y/2);
	glm::vec2 player2Pos(m_width - m_paddleSize.x, m_height/2 - m_paddleSize.y/2);
	glm::vec2 ballPos(m_width/2, m_height/2);

	m_player1 = new GameObject(player1Pos, m_paddleSize, m_player1Color);
	m_player2 = new GameObject(player2Pos, m_paddleSize, m_player2Color);
	m_ball = new Ball(m_radius, ballPos, m_ballVelocity, m_ballColor);
	m_renderer = new Renderer(m_width, m_height);
	m_textRenderer = new Text();
	m_textRenderer->loadFont("fonts/ocraext.ttf", 21);
	
	glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(m_width), 
		static_cast<float>(m_height), 0.0f, -1.0f, 1.0f);

	ResourceManager::getShader("paddle").use();		
	ResourceManager::getShader("paddle").setMatrix4m("projection", projection);

	ResourceManager::getShader("ball").use();
	ResourceManager::getShader("ball").setMatrix4m("projection", projection);

	ResourceManager::getShader("text2D").use();
	ResourceManager::getShader("text2D").setUniformi("text", 0);
	ResourceManager::getShader("text2D").setMatrix4m("projection", projection);

}

Direction Game::vectorDirection(glm::vec2 target)
{
	glm::vec2 directions[4] = {
		glm::vec2(0.0f, 1.0f),
		glm::vec2(1.0f, 0.0f),
		glm::vec2(0.0f, -1.0f),
		glm::vec2(-1.0f, 0.0f)
	};

	float max = 0.0f;
	int bestMatch = -1;
	for (int i = 0; i < 4; i++)
	{
		float dotProduct = glm::dot(glm::normalize(target), directions[i]);
		if (dotProduct > max)
		{
			max = dotProduct;
			bestMatch = i;
		}
	}

	return (Direction)bestMatch;
}

void Game::proccessInput(float dt)
{
	float dSpeed = m_paddleVelocity * dt;
	if (keys[GLFW_KEY_W])
	{
		if (m_player1->m_pos.y >= 0.0f)
		{
			m_player1->m_pos.y -= dSpeed;
		}
	}
	if (keys[GLFW_KEY_S])
	{
		if (m_player1->m_pos.y + m_paddleSize.y <= m_height)
		{
			m_player1->m_pos.y += dSpeed;
		}
	}

	if (keys[GLFW_KEY_UP])
	{
		if (m_player2->m_pos.y >= 0.0f)
		{
			m_player2->m_pos.y -= dSpeed;
		}
	}
	if (keys[GLFW_KEY_DOWN])
	{
		if (m_player2->m_pos.y + m_paddleSize.y <= m_height)
		{
			m_player2->m_pos.y += dSpeed;
		}
	}
}

bool Game::checkCollision(GameObject& one, GameObject& two)
{
	bool collisionX = (one.m_pos.x + one.m_size.x >= two.m_pos.x) && 
					  (two.m_pos.x + two.m_size.x >= one.m_pos.x);
	
	bool collisionY = (one.m_pos.y + one.m_size.y >= two.m_pos.y) &&
					  (two.m_pos.y + two.m_size.y >= one.m_pos.y);

	return collisionX && collisionY;
}


Game::Collision Game::checkCollision(Ball& ball, GameObject& paddle)
{
	glm::vec2 ballCenter(ball.m_pos + m_radius);

	glm::vec2 paddleHalfExtents(paddle.m_size.x / 2.0f, paddle.m_size.y / 2.0f);
	glm::vec2 paddleCenter(paddle.m_pos.x + paddleHalfExtents.x,
		paddle.m_pos.y + paddleHalfExtents.y);

	glm::vec2 diff = ballCenter - paddleCenter;
	glm::vec2 clamped = glm::clamp(diff, -paddleHalfExtents, paddleHalfExtents);

	glm::vec2 closest = paddleCenter + clamped;

	diff = closest - ballCenter;

	if (glm::length(diff) < ball.m_radius)
	{
		return std::make_tuple(true, vectorDirection(diff), diff);
	}
	else
	{
		return std::make_tuple(false, Direction::RIGHT, glm::vec2(0.0f));
	}

}


void Game::doCollisions()
{
	Collision player1Collision = checkCollision(*m_ball, *m_player1);
	Collision player2Collision = checkCollision(*m_ball, *m_player2);

	if (std::get<0>(player1Collision))
	{
		float paddleCenter = m_player1->m_pos.y + m_player1->m_size.y / 2.0f;
		float distance = (m_ball->m_pos.y + m_radius) - paddleCenter;
		float percentage = distance / (m_player1->m_size.y / 2.0f);

		float strength = 1.5f;
		glm::vec2 oldVelocity = m_ball->m_velocity;
		m_ball->m_velocity.y = m_ballVelocity.y * percentage * strength;
		m_ball->m_velocity.x = m_ballVelocity.x;
		m_ball->m_velocity = glm::normalize(m_ball->m_velocity) * glm::length(oldVelocity);
	}
	else if (std::get<0>(player2Collision))
	{
		float paddleCenter = m_player2->m_pos.y + m_player2->m_size.y / 2.0f;
		float distance = (m_ball->m_pos.y + m_radius) - paddleCenter;
		float percentage = distance / (m_player2->m_size.y / 2.0f);

		float strength = 1.5f;
		glm::vec2 oldVelocity = m_ball->m_velocity;
		m_ball->m_velocity.y = m_ballVelocity.y * percentage * strength;
		m_ball->m_velocity.x = -m_ballVelocity.x;
		m_ball->m_velocity = glm::normalize(m_ball->m_velocity) * glm::length(oldVelocity);
	}
}

void Game::updateObjects(float dt) 
{
	m_ball->move(dt, m_height);
	doCollisions();
	if (m_ball->m_pos.x + m_ball->m_radius * 2 < 0.0f)
	{
		m_player2Score++;
		m_ball->m_pos = glm::vec2(m_width / 2, m_height / 2);
	}
	else if (m_ball->m_pos.x > m_width)
	{
		m_player1Score++;
		m_ball->m_pos = glm::vec2(m_width / 2, m_height / 2);
	}
}

void Game::renderObjects()
{
	m_player1->draw(*m_renderer, ResourceManager::getShader("paddle"));
	m_player2->draw(*m_renderer, ResourceManager::getShader("paddle"));
	m_ball->draw(*m_renderer, ResourceManager::getShader("ball"));
	m_textRenderer->renderText("SCORE", m_width / 2, m_height  / 2, 0.5f, m_textColor, ResourceManager::getShader("text2D"));
}

