#version 330 core

out vec4 outColor;

uniform vec2 pos;
uniform vec3 color;
uniform float doubleRadius;

void main()
{	
	vec2 uv  = (gl_FragCoord.xy-pos)/doubleRadius*2.0f-1.0f;

	float distance = 1.0f - length(uv);
	outColor = vec4(vec3(smoothstep(0.0f, 0.2f, distance)), 1.0f);
}
