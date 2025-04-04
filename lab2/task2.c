#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a, b, sum;                                     // Объявление целочисленных переменных a, b и sum для хранения суммы a и b
    int *ptr_a = &a, *ptr_b = &b, *ptr_sum = &sum;     // Объявление указателей ptr_a, ptr_b и ptr_sum и присвоение им адресов a, b и sum соответственно

    printf("Input a: ");    // Ввод значений a и b и запись их через указатели
    scanf("%d", ptr_a);
    printf("Input b: ");
    scanf("%d", ptr_b);

    *ptr_sum = *ptr_a + *ptr_b;     // Вычисление и запись суммы a и b через разыменовывание указателей

    printf("%d + %d = %d\n", *ptr_a, *ptr_b, *ptr_sum);    // Вывод суммы

    return EXIT_SUCCESS;
}
