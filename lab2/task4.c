#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int len;
    printf("Input length of array A: ");
    scanf("%d", &len);

    double *A = (double*)malloc(len * sizeof(double));  // Динамическое выделение памяти для массива A типа double длины len 

    // Проверка на успешное выделение памяти
    if (A == NULL) {
        return EXIT_FAILURE;
    } 
    
    // Ввод элементов массива
    // Каждый проход цикла i увеличивается на 1, а адрес A+i смещается на sizeof(double)
    for (int i = 0; i < len; i++) {
        printf("Input A[%d]: ", i);
        scanf("%lf", A + i);
    }

    // Вывод элементов массива
    // Аналогично, каждый проход цикла i увеличивается на 1, а адрес A+i смещается на sizeof(double)
    printf("\nElements of array A:\n");
    for (int i = 0; i < len; i++) {
        printf("%.2lf ", *(A + i));    // Разыменовая указатель, получаем значение i-го элемента массива
    }
    printf("\n");

    free(A);    // Освобождение динамической памяти, выделенной под массив A
    return EXIT_SUCCESS;
}