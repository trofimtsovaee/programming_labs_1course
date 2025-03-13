#include <stdio.h>

int main() {
    double A[3][3] = {{5, 12, 8},
                      {7, 3, 14},
                      {9, 6, 2}};
    
    for (int i = 0; i < 3; i++) {
        double sum = 0;
        for (int j = 0; j < 3; j++)
            sum += A[i][j];
        double avg = sum / 3.;
        A[i][0] = avg;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            printf("%5.2lf ", A[i][j]);
        printf("\n");    
    }

    return 0;
}