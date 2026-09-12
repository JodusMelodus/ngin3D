#version 330 core

uniform vec4 meshColor;

out vec4 color;

void main()
{
    color = meshColor;
}