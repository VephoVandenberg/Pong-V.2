#pragma once

#include <glm/glm.hpp>

#include <map>
#include <string>

#include "shader.h"

class Text
{
public:
	struct Character
	{
		unsigned int textureID;
		glm::ivec2 size;
		glm::ivec2 bearing;
		unsigned int advance;
	};

	std::map<char, Character> characters;

public:
	Text();
	~Text();
	void loadFont(const char *fontPath, unsigned int fontSize);
	void renderText(std::string text, float x, float y, float scale, glm::vec3& color, Shader& shader);

private:
	unsigned int VAO;
	unsigned int VBO;
};