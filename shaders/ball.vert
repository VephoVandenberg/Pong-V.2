#version 330 core

layout (location = 0) in vec2 position;
out vec2 pos;

uniform mat4 projection;
uniform mat4 model;

void main()
{
	gl_Position = projection*model*vec4(position, 0.0f, 1.0f);
	pos = gl_Position.xy;
}