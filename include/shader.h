#ifndef SHADER_H
#define SHADER_H

#include <inttypes.h>

struct Shader
{
    uint8_t id;
};

struct Shader createShader(const char *vertexPath, const char *fragmentPath);
void shaderUse(struct Shader *shader);
void shaderDestroy(struct Shader *shader);

#endif