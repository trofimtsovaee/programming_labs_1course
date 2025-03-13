#include <stdio.h>

int main() {
    int vectorX[3], vectorY[3];
    printf("Input elements of three-dimensional vector X:\n");
    for (int i = 0; i < 3; i++) {
        scanf("%d", &vectorX[i]);
        vectorY[i] = vectorX[i] * vectorX[i];
    }
    
    printf("Y = ( ");
    for (int i = 0; i < 3; i++)
        printf("%d ", vectorY[i]);
    printf(")\n");

    return 0;
}