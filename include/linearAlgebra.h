#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

#include <inttypes.h>
#include <math.h>

typedef double Matrix3x3[3 * 3];
typedef double Matrix2x2[2 * 2];
typedef double Vector2[2];
typedef double Vector3[3];

uint8_t multiplyMatrix3x3WithMatrix3x3(Matrix3x3 *matrix1, Matrix3x3 *matrix2, Matrix3x3 *result);
uint8_t multiplyMatrix3x3WithVector3(Matrix3x3 *matrix, Vector3 *vector, Vector3 *result);
double dotProductVector3WithVector3(Vector3 *vector1, Vector3 *vector2);

uint8_t multiplyMatrix2x2WithMatrix2x2(Matrix2x2 *matrix1, Matrix2x2 *matrix2, Matrix2x2 *result);
uint8_t multiplyMatrix2x2WithVector2(Matrix2x2 *matrix, Vector2 *vector, Vector2 *result);
double dotProductVector2WithVector2(Vector2 *vector1, Vector2 *vector2);

#endif