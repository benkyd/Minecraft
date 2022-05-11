#version 450 

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 texcoord;

out vec3 TexCoord;
out float Distance;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main() {
	
	TexCoord = texcoord;
	
	gl_Position = proj * view * model * vec4(position, 1.0);

	// Makes no sense but it works
	Distance = (
		gl_Position.x * gl_Position.x + 
		gl_Position.y * gl_Position.y + 
		gl_Position.z * gl_Position.z
	);

}
