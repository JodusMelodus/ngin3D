#include "object.h"

uint8_t objectCount = 0;
struct Object objects[MAX_OBJECT_COUNT] = {0};

void addObject(Vector3 r)
{
    struct Object object = {0};
    memcpy(object.r, r, sizeof(Vector3));

    float vertices[12] = {
        0.0f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f};
    object.mesh = createMesh(vertices, 4);
    object.color = (struct Color){255, 0, 0, 0};

    objects[objectCount++] = object;
}

void drawObject(struct Shader *shader, struct Object *object)
{
    shaderUse(shader);
    shaderSetColor(shader, object->color);
    drawMesh(&object->mesh);
}

void drawObjects(struct Shader *shader)
{
    for (uint8_t i = 0; i < objectCount; i++)
        drawObject(shader, &objects[i]);
}
