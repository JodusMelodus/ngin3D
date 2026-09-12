#include "mesh.h"

struct Mesh createMesh(const float *vertices, GLsizei vertexCount)
{
    GLuint VAO;
    GLuint VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, vertexCount * 3 * sizeof(float), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);

    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

    return (struct Mesh){
        .vertexCount = vertexCount,
        .VAO = VAO,
        .VBO = VBO};
}

void drawMesh(struct Mesh *mesh)
{
    glBindVertexArray(mesh->VAO);
    glDrawArrays(GL_TRIANGLES, 0, mesh->vertexCount);
    glBindVertexArray(0);
}

void destroyMesh(struct Mesh *mesh)
{
    glDeleteBuffers(1, &mesh->VBO);
    glDeleteVertexArrays(1, &mesh->VAO);
}
