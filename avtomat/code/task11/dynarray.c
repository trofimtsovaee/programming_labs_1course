#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>     // Для size_t
#include "dynarray.h"

// Инициализация динамического массива
// init_capacity - начальная вместимость, сколько элементов сможем хранить
void dynarray_init(DynArray *arr, size_t init_capacity) {
    arr->data = (int*)malloc(init_capacity * sizeof(int));  // Выделяем память под массив
    if (arr->data == NULL) {    // Проверка успешного выделения памяти
        fprintf(stderr, "Memory allocation failed in init\n");
        exit(EXIT_FAILURE); // Если не выделилась, прекращаем выполнение программы
    }
    arr->size = 0;                  // Передаем начальный размер массива 0 в поле элемента структуры
    arr->capacity = init_capacity;  // Передаем вместимость
}

// Проверка, хватает ли выделенной памяти, и расширение при необходимости
// context нужен для вывода, во время выполнения какой функции произошла ошибка
void dynarray_ensure_capacity(DynArray *arr, const char *context) {
    if (arr->size == arr->capacity) {   // Если заполненная вся память, выделенная под массив
        size_t new_capacity = arr->capacity > 0 ? arr->capacity * 2 : 1;    // Увеличиваем вместимость в 2 раза
        int *tmp = (int*)realloc(arr->data, new_capacity * sizeof(int));    // Выделяем новую память
        if (tmp == NULL) {  // Проверка успешного выделения памяти
            fprintf(stderr,"Memory allocation failed in %s\n", context);
            exit(EXIT_FAILURE);
        }
        arr->data = tmp;    // Передаем в arr->data указатель на новую память
        arr->capacity = new_capacity;   // Обновляем вместимость
    }
}

// Вставка нового элемента в конец массива
void dynarray_pushback(DynArray *arr, int value) {
    dynarray_ensure_capacity(arr, "pushback");  // Проверяем, хватает ли выделенной памяти
    arr->data[arr->size++] = value;             // Вставляем элемент в конец и увеличиваем size
}

// Вставка элемента по указанному индексу
void dynarray_insert(DynArray *arr, size_t index, int value) {
    if (index > arr->size) {    // Проверяем, не выходит ли индекс за границы массива
        fprintf(stderr, "Invalid index in insert: %zu\n", index);
        return; // Завершаем выполнение функции
    }

    dynarray_ensure_capacity(arr, "insert");    // Проверяем, хватает ли выделенной памяти

    // Сдвигаем элементы вправо от индекса вставки
    for (size_t i = arr->size; i > index; i--) {
        arr->data[i] = arr->data[i - 1];
    }
    // Вставляем значение и увеличиваем size
    arr->data[index] = value;
    arr->size++;
}

// Удаление элемента по индексу
void dynarray_delete_by_index(DynArray *arr, size_t index) {
    if (index >= arr->size) {   // Проверяем, не выходит ли индекс за границы массива
        fprintf(stderr, "Invalid index in delete_by_index: %zu\n", index);
        return;
    }
    // Сдвигаем элементы влево от индекса удаления и уменьшаем size
    for (size_t i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
}

// Получение указателя на значение по индексу
int* dynarray_get_ptr(const DynArray *arr, size_t index) {
    // Если индекс выходит за границы массива, возвращаем NULL
    if (index >= arr->size) {
        fprintf(stderr, "Invalid index in get: %zu\n", index);
        return NULL;
    }
    return &arr->data[index];   // Возврашаем адрес элемента по указанному индексу
}

// Вывод элементов массива на экран
void dynarray_print(const DynArray *arr) {
    for (size_t i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

// Освобождение памяти, выделенной под массив (деструктор)
void dynarray_free(DynArray *arr) {
    free(arr->data);    // Освобождаем память
    arr->data = NULL;   // Обнуляем указатель на сам массив
    arr->size = 0;      // Обнуляем размер массива
    arr->capacity = 0;  // Обнуляем вместимость
    
    // Проверяем, успешно ли освободилась память
    if (arr->data == NULL) {
        printf("\nMemory cleared succesfully\n");
    } else {
        fprintf(stderr, "\nMemory has not cleared\n");
    }
}