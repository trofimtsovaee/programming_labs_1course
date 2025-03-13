#include <stdio.h>
#include <math.h>
#define E 2.7182818284

double integral(double a, double b, double n) {
    double h = (b - a) / n;
    double S = 0;

    for (double x = a + h; x <= b - h + h / 2; x += h) {
        double f = pow(E, x + 2);
        S += f;
    }

    double fa = pow(E, a + 2);
    double fb = pow(E, b + 2);
    double res = h * ((fa + fb) / 2 + S);
    return res;
}

int main() {
    double n, a, b;
    printf("Input number of parts: n = ");
    scanf("%lf", &n);
    printf("Input a: a = ");
    scanf("%lf", &a);
    printf("Input b: b = ");
    scanf("%lf", &b);

    printf("%.10f\n", integral(a, b, n));

    return 0;
}