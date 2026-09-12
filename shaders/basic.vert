#version 330 core

layout (location = 0) in vec3 position; // expect a vec3 as input

void main()
{
    gl_Position = vec4(position, 1.0);
}