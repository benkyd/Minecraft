#version 450

vec3 SkyColour = vec3(186.0f / 255.0f, 214.0f / 255.0f, 254.0f / 255.0f);

in vec3 TexCoord;
in float Distance;

out vec4 outColour;

uniform sampler2DArray tex;

void main() {

	outColour = texture(tex, TexCoord);
	//outColour = vec4(.9, .9, .9, 1);

	if (outColour.w == .0)
		discard;
	
	float fogMax = 20000;
	
	outColour = vec4(mix(outColour.xyz, SkyColour, min(1.0f, Distance / fogMax)), outColour.w);

}
