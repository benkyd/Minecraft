#version 330

in vec2 TexCoord;
out vec4 outColour;

uniform vec3 triangleColour;

uniform sampler2D tex;

void main() {
    outColour = texture(tex, TexCoord);
}
