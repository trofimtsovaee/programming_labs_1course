#include <stdio.h>

int main() {
    int list[10] = {7, 23, 89, 12, 45, 67, 34, 90, 56, 78};

    for (int i = 1; i < 10; i ++) {
        for (int j = i; j > 0 && list[j - 1] > list[j]; j--) {
            int t = list[j];
            list[j] = list[j - 1];
            list[j - 1] = t;
        }
    }

    for (int i = 0; i < 10; i++)
        printf("%d ", list[i]);
    printf("\n");
}