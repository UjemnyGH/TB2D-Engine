#version 430 core

layout(location = 0)int vec4 iPos;
layout(location = 1)int vec4 iCol;
layout(location = 2)int vec2 iTex;

out vec4 ioCol;
out vec2 ioTexCoord;

void main()
{
    gl_Position = mat4(1.0) * iPos;
    ioCol = iCol;
    ioTexCoord = iTex;
}