#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Vector {
    int x;
    int y;
    int z;
} Vector;

int scalarMultiplyVectors(Vector, Vector);
Vector vectorMultiplyVectors(Vector, Vector);
double vectorModule(Vector);
void printVector(Vector);

int main() {
    Vector a = {1, 2, 3};
    Vector b = {4, 5, 6};
    int sc_prod = scalarMultiplyVectors(a, b);
    Vector vec_prod = vectorMultiplyVectors(a, b);
    double a_mod = vectorModule(a);
    double b_mod = vectorModule(b);

    printf("a = ");
    printVector(a);
    printf("b = ");
    printVector(b);
    printf("a • b = %d\n", sc_prod);
    printf("a × b = ");
    printVector(vec_prod);
    printf("|a| = %.3lf\n", a_mod);
    printf("|b| = %.3lf\n", b_mod);

    return EXIT_SUCCESS;
}

int scalarMultiplyVectors(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector vectorMultiplyVectors(Vector a, Vector b) {
    Vector res;
    res.x = a.y * b.z - a.z * b.y;
    res.y = -(a.x * b.z - a.z * b.x);
    res.z = a.x * b.y - a.y * b.x;
    return res;
}

double vectorModule(Vector a) {
    return sqrt(a.x * a.x + a.y * a.y + a.z *a.z);
}

void printVector(Vector a) {
    printf("(%d, %d, %d)\n", a.x, a.y, a.z);
}