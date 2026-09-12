#include "shader.h"
#include "utils.h"

#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <glad/glad.h>

static uint16_t compileShader(uint16_t type, const char *source)
{
    uint16_t shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);
    return shader;
}

struct Shader createShader(const char *vertexPath, const char *fragmentPath)
{
    char *vertexSource = readfile(vertexPath);
    char *fragmentSource = readfile(fragmentPath);

    uint16_t vertexShader = compileShader(GL_VERTEX_SHADER, vertexSource);
    uint16_t fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentSource);

    free(vertexSource);
    free(fragmentSource);

    uint16_t program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    struct Shader shader;
    shader.id = program;

    return shader;
}

void shaderUse(struct Shader *shader)
{
    glUseProgram(shader->id);
}

void shaderDestroy(struct Shader *shader)
{
    glDeleteProgram(shader->id);
}
