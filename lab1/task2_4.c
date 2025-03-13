#include <stdio.h>

int main() {
    int sum;
    do {
        int x;
        printf("Input a three-digit number: ");
        scanf("%d", &x);
        sum = (x / 100) + ((x % 100) / 10) + (x % 10);
        printf("Sum of digits: %d\n", sum);
    } while (sum > 10);
    
    return 0;
}