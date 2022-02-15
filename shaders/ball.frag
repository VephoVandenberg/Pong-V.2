#version 330 core

in float fragRadius;
out vec4 outColor;

uniform vec3 color;

void main()
{
	vec2 uv = gl_FragCoord.xy/fragRadius*2.0f - 1.0f;

	float distance = length(uv);
	outColor = vec4(vec3(distnace), 1.0f);
}