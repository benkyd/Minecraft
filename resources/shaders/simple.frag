#version 330

in vec3 TexCoord;

out vec4 outColour;

// uniform sampler2D tex;

void main() {
    outColour = vec4(TexCoord, 1.0); // texture(tex, TexCoord);
}
