#include "renderer.h"

#include <glm/gtc/matrix_transform.hpp>

Renderer::Renderer(float width, float height):
	m_width(width), m_height(height)
{
	initRenderData();
}

Renderer::~Renderer()
{

}

void Renderer::draw(glm::vec2 pos, glm::vec2& size, glm::vec3& color, Shader& shader)
{
	shader.use();
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(pos, 0.0f));
	model = glm::scale(model, glm::vec3(size, 1.0f));

	shader.setMatrix4m("model", model);
	shader.setVector3v("color", color);
	
	if (size.x == size.y)
	{
		glm::vec2 fragmentBallPos = glm::vec2(pos.x, m_height-pos.y-size.y);
		shader.setVector2v("pos", fragmentBallPos);
		shader.setUniformf("doubleRadius", size.x);
	}

	glBindVertexArray(m_quadVAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}

void Renderer::initRenderData()
{
	unsigned int VBO;
	float vertices[12] = {
		 0.0f,  0.0f,
		 0.0f,  1.0f,
		 1.0f,  0.0f,

		 0.0f,  1.0f,
		 1.0f,  1.0f,
		 1.0f,  0.0f
	};

	glGenVertexArrays(1, &m_quadVAO);
	glGenBuffers(1, &VBO);
	
	glBindVertexArray(m_quadVAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}
