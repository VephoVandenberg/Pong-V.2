#version 330 core

layout (location = 0) in vec2 position;

out float fragRadius;

uniform mat4 projection;
uniform mat4 model;
uniform float radius;

void main()
{
	gl_Position = projection*model*vec4(position, 0.0f, 1.0f);
	fragRadius = radius;
}