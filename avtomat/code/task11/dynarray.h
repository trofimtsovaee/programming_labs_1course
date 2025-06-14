#ifndef DYNARRAY_H  // Проверка на повторное включение заголовочного файла
#define DYNARRAY_H

#include <stddef.h> // Для size_t

// Структура динамического массива целых чисел
typedef struct DynArray {
    int *data;          // Указатель на массив данных
    size_t size;        // Размер массива
    size_t capacity;    // Общая вместимость (количество выделенных ячеек памяти)
} DynArray;

// Функция инициализации динамического массива: 
// выделяет память, передает начальную вместимость и устанавливает размер массива 0
void dynarray_init(DynArray *arr, size_t init_capacity);

// Функция проверки нехватки выделенной памяти:
// увеличивает вместимость массива, если он полностью заполнен
void dynarray_ensure_capacity(DynArray *arr, const char *context);

// Функция вставки нового значения в конец массива
void dynarray_pushback(DynArray *arr, int value);

// Функция вставки значения по указанному индексу
void dynarray_insert(DynArray *arr, size_t index, int value);

// Функция удаления элемента по указанному индексу
void dynarray_delete_by_index(DynArray *arr, size_t index);

// Функция получения адреса значения по указанному индексу
int* dynarray_get_ptr(const DynArray *arr, size_t index);

// Функция вывода элементов массива
void dynarray_print(const DynArray *arr);


// Функция освобождения памяти, выделенной под массив (деструктор)
void dynarray_free(DynArray *arr);

#endif // DYNARRAY_H
