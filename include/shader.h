#ifndef SHADER_H
#define SHADER_H

#include <inttypes.h>
#include <glad/glad.h>

struct Shader
{
    GLuint id;
};

extern GLuint VAO;
extern GLuint VBO;

struct Shader createShader(const char *vertexPath, const char *fragmentPath);
void shaderUse(struct Shader *shader);
void shaderDestroy(struct Shader *shader);

void shaderDrawLine(struct Shader *shader);

#endif