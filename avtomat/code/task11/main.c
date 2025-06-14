#include <stdio.h>
#include <stdlib.h>
#include "dynarray.h"

int main() {
    DynArray arr;
    // Инициализируем динамический массив с начальнйо вместимостью 2
    dynarray_init(&arr, 2);

    // Вставляем в конец массива поочередно элементы {10, 20, 30, 40, 50}
    printf("After pushback:\n\t");
    for (size_t i = 1; i < 6; i++)
        dynarray_pushback(&arr, i * 10);
    dynarray_print(&arr);

    // Поочередно вставляем значения 25 и 5 по индексам 2 и 0 соответственно
    // Должно получиться {5, 10, 20, 25, 30, 40, 50}
    printf("After insertion:\n\t");
    dynarray_insert(&arr, 2, 25);
    dynarray_insert(&arr, 0, 5);
    dynarray_print(&arr);

    // Удаляем элемент по индексу 3, то есть 25
    // Должно получиться {5, 10, 20, 30, 40, 50}
    printf("After deletion:\n\t");
    dynarray_delete_by_index(&arr, 3);
    dynarray_print(&arr);

    // Пытаемся удалить элемент по индексу, выходящему за границы
    // Должны получить ошибку
    printf("After deletion with invalid index:\n");
    dynarray_delete_by_index(&arr, 100);

    // Получаем элемент по индексу 3, то есть 30
    int *get_ptr = dynarray_get_ptr(&arr, 3);
    if (get_ptr != NULL)
        printf("Element at index 3: %d\n", *get_ptr);

    // Пытаемся получить элемент по индексу, выходящему за границы
    // Должны получить ошибку
    get_ptr = dynarray_get_ptr(&arr, 100);
    if (get_ptr != NULL)
        printf("Element at index 100: %d\n", *get_ptr);

    // Освобождаем память, выделенную под массив
    dynarray_free(&arr);

    return EXIT_SUCCESS;
}