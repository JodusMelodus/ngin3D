#ifndef OBJECT_H
#define OBJECT_H

#include "linearAlgebra.h"
#include "shader.h"
#include "mesh.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string.h>

#define MAX_OBJECT_COUNT 50

struct Object
{
    struct Mesh mesh;
    Vector3 r;
    Vector3 f;
    Vector3 dimensions;
    struct Color color;
    double mass;
};

extern uint8_t objectCount;
extern struct Object objects[MAX_OBJECT_COUNT];

void addObject(Vector3 r);
void drawObject(struct Shader *shader, struct Object *object);
void drawObjects(struct Shader *shader);

#endif