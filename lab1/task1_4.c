#include <stdio.h>
#include <math.h>

double h(double a, double b, double c, double x) {
    double t1, t2, t3, t4;

    t1 = x - a;
    t2 = pow(x * x + a * a, 1.0 / 3.0);
    t3 = 4.0 * pow(x * x + b * b, 3.0 / 4.0);
    t4 = 2 + a + b + pow((x - c) * (x - c), 1.0 / 3.0);

    return -t1 / t2 - t3 / t4;
}

int main() {
    double a1 = 0.12, b1 = 3.5, c1 = 2.4, x1 = 1.4;
    double a2 = a1, b2 = b1, c2 = c1, x2 = 1.6;
    double a3 = 0.27, b3 = 3.9, c3 = 2.8, x3 = 1.8;
    printf("For a = %.2f, b = %.2f, c = %.2f, x = %.2f: h(x) = %.2f\n", a1, b1, c1, x1, h(a1, b1, c1, x1));
    printf("For a = %.2f, b = %.2f, c = %.2f, x = %.2f: h(x) = %.2f\n", a2, b2, c2, x2, h(a2, b2, c2, x2));
    printf("For a = %.2f, b = %.2f, c = %.2f, x = %.2f: h(x) = %.2f\n", a3, b3, c3, x3, h(a3, b3, c3, x3));
    return 0;
}
