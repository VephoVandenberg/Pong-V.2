#version 330 core

layout (location = 0) in vec2 position;

uniform mat4 model;
uniform mat4 projection;
uniform vec3 color;

out vec3 inColor;

void main()
{
	gl_Position = projection*model*vec4(position, 0.0f, 1.0f);
	inColor = color;
}