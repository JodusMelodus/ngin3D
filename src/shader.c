#include "shader.h"
#include "utils.h"

#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <glad/glad.h>

static GLuint compileShader(GLuint type, const char *source)
{
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);

    int success = 0;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(shader, sizeof(infoLog), NULL, infoLog);
        fprintf(stderr, "Shader compilation failed: \n%s\n", infoLog);
        glDeleteShader(shader);
        return 0;
    }

    return shader;
}

struct Shader createShader(const char *vertexPath, const char *fragmentPath)
{
    char *vertexSource = readFile(vertexPath);
    char *fragmentSource = readFile(fragmentPath);

    GLuint vertexShader = compileShader(GL_VERTEX_SHADER, vertexSource);
    GLuint fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentSource);

    free(vertexSource);
    free(fragmentSource);

    if (!vertexShader || !fragmentShader)
    {
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        return (struct Shader){0};
    }

    GLuint program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    int success = 0;
    char infoLog[1024];
    glGetProgramiv(program, GL_LINK_STATUS, &success);

    if (!success)
    {
        glGetProgramInfoLog(program, sizeof(infoLog), NULL, infoLog);
        fprintf(stderr, "Shader linking failed: \n%s\n", infoLog);
        glDeleteProgram(program);
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        return (struct Shader){0};
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    GLint colorLocation = glGetUniformLocation(program, "meshColor");

    return (struct Shader){
        .id = program,
        .colorLocation = colorLocation};
}

void shaderUse(struct Shader *shader)
{
    glUseProgram(shader->id);
}

void shaderDestroy(struct Shader *shader)
{
    glDeleteProgram(shader->id);
}

void shaderSetColor(struct Shader *shader, struct Color color)
{
    glUniform4f(
        shader->colorLocation,
        color.r / UINT8_MAX,
        color.g / UINT8_MAX,
        color.b / UINT8_MAX,
        color.a / UINT8_MAX);
}
