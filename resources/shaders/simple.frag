#version 450

vec3 SkyColour = vec3(186.0f / 255.0f, 214.0f / 255.0f, 254.0f / 255.0f);

in vec3 TexCoord;
in float Distance;

out vec4 outColour;

uniform sampler2DArray tex;

void main() {

	outColour = texture(tex, TexCoord);
	// outColour = vec4(.9, .9, .9, 1);

	if (outColour.w == .0)
		discard;
	
	float fogMax = 200000;
	
	vec3 colour = mix(outColour.xyz, SkyColour, min(1.0f, Distance / fogMax));

	// Retain fragment transparency
	outColour = vec4(colour, outColour.w);

}
