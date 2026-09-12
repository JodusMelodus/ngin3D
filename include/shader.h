#ifndef SHADER_H
#define SHADER_H

#include "utils.h"

#include <inttypes.h>
#include <glad/glad.h>

struct Shader
{
    GLuint id;
    GLuint colorLocation;
};

extern GLuint VAO;
extern GLuint VBO;

struct Shader createShader(const char *vertexPath, const char *fragmentPath);
void shaderUse(struct Shader *shader);
void shaderDestroy(struct Shader *shader);
void shaderSetColor(struct Shader *shader, struct Color color);

#endif