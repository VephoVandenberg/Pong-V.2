#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

class Renderer
{
public:
	Renderer();
	~Renderer();
	void initRenderData();
	void draw(glm::vec2 pos);
private:
};

