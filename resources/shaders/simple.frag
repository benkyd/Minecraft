#version 450

in vec3 TexCoord;

out vec4 outColour;

uniform sampler2DArray tex;

void main() {
    outColour = texture(tex, TexCoord);
}
