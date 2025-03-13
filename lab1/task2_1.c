#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979

int main() {
    double r1 = 228, r2 = 149.6, T1 = 687, T2 = 365;
    double w1 = 2 * PI / T1;
    double w2 = 2 * PI / T2;
    for (int t = 1; t <= 12000; t += 15) {
        double x = r1 * cos(w1 * t) - r2 * cos(w2 * t);
        double y = r1 * sin(w1 * t) - r2 * sin(w2 * t);
        printf("t = %d сут \t x = %.3f млн км \t y = %.3f млн км\n", t, x, y);
    }

    return 0;
}