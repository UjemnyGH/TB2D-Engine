#version 430 core

out vec4 oCol;

in vec4 ioCol;
in vec2 ioTexCoord;

uniform sampler2D tex;

void main()
{
    oCol = texture(tex, ioTexCoord);
}