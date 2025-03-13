#include <stdio.h>

int main() {
    int m;
    printf("Input m: m = ");
    scanf("%d", &m);
    int p0, p1, p2;
    p0 = p1 = p2 = 1;
    printf("Padovan sequence (< m = %d): %d, %d, %d, ", m, p0, p1, p2);

    for (int p = p0 + p1; p <= m; p = p0 + p1) { 
        printf("%d, ", p);
        p0 = p1;
        p1 = p2;
        p2 = p;
    }

    printf("...\n");

    return 0;
}