#version 330 

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 texcoord;

out vec3 TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main() {
    TexCoord = texcoord;
    gl_Position = proj * view * model * vec4(position, 1.0);
}
