#ifndef OBJECT_H
#define OBJECT_H

#include "linearAlgebra.h"

#define OBJECT_COUNT 50

typedef struct
{
    Vector3 r;
    Vector3 f;
    Vector3 dimensions;
    double mass;
} Object;

Object objects[OBJECT_COUNT] = {0};

void drawObjects();

#endif