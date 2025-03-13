#include <stdio.h>

int main() {
    int vector[5];
    printf("Input 5 elements of array:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &vector[i]);
    }
    
    printf("Reverse: ");
    for (int i = 4; i > -1; i--)
        printf("%d ", vector[i]);
    printf("\n");

    return 0;
}