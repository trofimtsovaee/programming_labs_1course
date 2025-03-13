#include <stdio.h>
#include <math.h>

int main() {
    double x, y, u, a, b;
    printf("Input x: ");
    scanf("%lf", &x);
    printf("Input y: ");
    scanf("%lf", &y);
    a = 1 + sin(x + y) * sin(x + y);
    b = 2 + fabs(x - (2 * x * x) / (1 + fabs(sin(x + y))));
    u = a / b;
    printf("u(x, y) = %lf\n", u);

    return 0;
}