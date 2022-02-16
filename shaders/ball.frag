#version 330 core

in vec2 pos;
out vec4 outColor;

uniform vec3 color;
uniform float doubleRadius;

void main()
{
	// Here doubleRadius means resolution

	vec2 uv = gl_FragCoord.xy/doubleRadius*2.0f - 1.0f;

	float distance = 1.0f - length(uv);
	if (distance > 0.0f)
	{
		outColor = vec4(color, 1.0f);
	}
	else
	{
		outColor = vec4(vec2(distance), 0.0f, 1.0f);
	}
}