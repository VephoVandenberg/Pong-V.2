#version 330 core

in float fragRadius;
out vec4 outColor;

uniform vec3 color;

void main()
{
	vec2 uv = gl_FragCoord.xy;
	uv.x /= fragRadius;
	uv.y /= fragRadius;

	float distance = 1.0f - length(uv);
	outColor = vec4(vec3(distance), 1.0f);
}