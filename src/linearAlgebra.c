#include "linearAlgebra.h"

uint8_t multiplyMatrix3x3WithMatrix3x3(Matrix3x3 *matrix1, Matrix3x3 *matrix2, Matrix3x3 *result)
{
    for (uint8_t i = 0; i < 9; i++)
        *result[i] = 0;

    for (uint8_t matrix2Column = 0; matrix2Column < 3; matrix2Column++)
        for (uint8_t matrix1Row = 0; matrix1Row < 3; matrix1Row++)
            for (uint8_t value = 0; value < 3; value++)
                *result[matrix1Row * 3 + matrix2Column] +=
                    *matrix1[matrix1Row * 3 + value] *
                    *matrix2[value * 3 + matrix2Column];
    return 0;
}

uint8_t multiplyMatrix3x3WithVector3(Matrix3x3 *matrix, Vector3 *vector, Vector3 *result)
{
    for (uint8_t i = 0; i < 3; i++)
        *result[i] = 0;

    for (uint8_t row = 0; row < 3; row++)
        for (uint8_t value = 0; value < 3; value++)
            *result[row] += *matrix[row * 3 + value] * *vector[value];

    return 0;
}

double dotProductVector3WithVector3(Vector3 *vector1, Vector3 *vector2)
{
    double result = 0;
    for (uint8_t i = 0; i < 3; i++)
        result += *vector1[i] * *vector2[i];

    return result;
}

uint8_t multiplyMatrix2x2WithMatrix2x2(Matrix2x2 *matrix1, Matrix2x2 *matrix2, Matrix2x2 *result)
{
    for (uint8_t i = 0; i < 4; i++)
        *result[i] = 0;

    for (uint8_t matrix2Column = 0; matrix2Column < 2; matrix2Column++)
        for (uint8_t matrix1Row = 0; matrix1Row < 2; matrix1Row++)
            for (uint8_t value = 0; value < 2; value++)
                *result[matrix1Row * 2 + matrix2Column] +=
                    *matrix1[matrix1Row * 2 + value] *
                    *matrix2[value * 2 + matrix2Column];
    return 0;
}

uint8_t multiplyMatrix2x2WithVector2(Matrix2x2 *matrix, Vector2 *vector, Vector2 *result)
{
    for (uint8_t i = 0; i < 2; i++)
        *result[i] = 0;

    for (uint8_t row = 0; row < 2; row++)
        for (uint8_t value = 0; value < 2; value++)
            *result[row] += *matrix[row * 2 + value] * *vector[value];

    return 0;
}

double dotProductVector2WithVector2(Vector2 *vector1, Vector2 *vector2)
{
    double result = 0;
    for (uint8_t i = 0; i < 2; i++)
        result += *vector1[i] * *vector2[i];

    return result;
}