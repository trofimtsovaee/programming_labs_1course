#include <stdio.h>
#include <stdlib.h>

int find_max(int *x, int *y);

int main(void)
{
    int a, b, mx;                                   // Объявление целочисленных переменных a, b и mx для хранения максимума из a и b
    int *ptr_a = &a, *ptr_b = &b, *ptr_mx = &mx;    // Объявление указателей ptr_a, ptr_b и ptr_mx и присвоение им адресов a, b и mx соответственно

    printf("Input a: ");    // Ввод значений a и b и сохранение их через указатели
    scanf("%d", ptr_a);
    printf("Input b: ");
    scanf("%d", ptr_b);

    mx = find_max(ptr_a, ptr_b);    // Нахождение максимума из двух чисел a и b с использованием пользовательской функции

    printf("Max of %d and %d is %d\n", a, b, mx);    // Вывод максимума

    return EXIT_SUCCESS;
}

// Функция нахождения максимума из двух чисел
int find_max(int *x, int *y) {
    return (*x > *y) ? *x : *y;
}