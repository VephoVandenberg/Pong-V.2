#version 330 core

out vec4 outColor;

uniform vec2 pos;
uniform vec3 color;
uniform float doubleRadius;

void main()
{	
	vec2 uv  = (gl_FragCoord.xy-pos)/doubleRadius*2.0f - 1.0f;

	float distance = 1.0f - length(uv);
	if (distance >= 0.0f)
	{
		outColor = vec4(color, 1.0f);
	}
	else
	{
		outColor = vec4(vec2(distance), 0.0f, 1.0f);
	}
}
	