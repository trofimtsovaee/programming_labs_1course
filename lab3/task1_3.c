#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPS 10E-5

typedef struct ComplexNum
{
    double real;
    double imag;
} ComplexNum;

ComplexNum complexExp(ComplexNum);

int main() {
    ComplexNum z;
    printf("Input the real part of z: ");
    scanf("%lf", &(z.real));
    printf("Input the imaginary part of z: ");
    scanf("%lf", &(z.imag));
    
    ComplexNum exp = complexExp(z);
    printf("exp(z) = %.5lf + %.5lf*i\n", exp.real, exp.imag);

    return EXIT_SUCCESS;
}

ComplexNum complexExp(ComplexNum z) {
    ComplexNum res = {1.0, 0.0};
    ComplexNum k = z;
    double n = 1;

    while ((fabs(k.real) > EPS) || (fabs(k.imag) > EPS)) {
        res.real += k.real;
        res.imag += k.imag;
        
        double real_prev = k.real;
        double imag_prev = k.imag;
        n ++;

        k.real = (real_prev * z.real - imag_prev * z.imag) / n;
        k.imag = (real_prev * z.imag + imag_prev * z.real) / n;
    }

    return res;
}