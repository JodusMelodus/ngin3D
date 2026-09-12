#ifndef MESH_H
#define MESH_H

#include "shader.h"

#include <glad/glad.h>

struct Mesh
{
    GLuint VAO;
    GLuint VBO;
    GLsizei vertexCount;
};

struct Mesh createMesh(const float *vertices, GLsizei vertexCount);
void drawMesh(struct Mesh *mesh);
void destroyMesh(struct Mesh *mesh);

#endif