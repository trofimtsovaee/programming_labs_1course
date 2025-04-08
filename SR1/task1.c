#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N;
    printf("Input N (number of array elements): ");
    scanf("%d", &N);
    float *array = malloc(N * sizeof(float));   // динамически выделяем память под N элементов типа float
    if (array == NULL) {    // проверка успешного выделения памяти
        printf("Memory allocation error!\n");
        return EXIT_FAILURE;
    }

    float sum = 0;
    for (int i = 0; i < N; i++) {
        printf("Input array[%d]: ", i); // считываем i-й элемент массива с клавиатуры
        scanf("%f", array + i);         // записываем его по адресу array+i
        sum += *(array + i);            // сразу же считаем сумму элементов
    }
    
    float avg = sum / N;
    printf("Average: %.2f\n", avg);
    free(array);    // освобождение динамической памяти, выделенной с помощью malloc()
    return EXIT_SUCCESS;
}