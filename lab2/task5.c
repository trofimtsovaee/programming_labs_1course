#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int len;
    printf("Input length of array A: ");
    scanf("%d", &len);

    int *A = (int*)malloc(len * sizeof(int));  // Динамическое выделение памяти для массива A типа int длины len 
    
    // Проверка на успешное выделение памяти
    if (A == NULL) {
        return EXIT_FAILURE;
    }

    // Ввод элементов массива
    // Каждый проход цикла i увеличивается на 1, а адрес A+i смещается на sizeof(int)
    for (int i = 0; i < len; i++) {
        printf("Input A[%d]: ", i);
        scanf("%d", A + i);
    }

    // Вывод элементов массива
    int *ptr = A + len - 1;     // Устанавливаем указатель на последний элемент
    for (int i = 0; i < len; i++) {
        printf("%d ", *ptr--);  // Разыменовая указатель, получаем значение (len-1-i)-го элемента массива, выводим его и декрементируем указатель
    }
    printf("\n");

    free(A);    // Освобождение динамической памяти, выделенной под массив A
    return EXIT_SUCCESS;
}