#include <stdio.h>
#include <stdlib.h>
#define N sizeof(unsigned long)

union number {
    unsigned long n;
    unsigned char b[N];
};

int main() {
    union number num;
    num.n = 1234567890987654321;

    printf("num = %lu\n", num.n);
    printf("num byte-by-byte: |");
    for (int i = 0; i < N; i++) {
        printf("%3d|", num.b[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}