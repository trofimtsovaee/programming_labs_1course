#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* filter(int *arr, size_t n, int (*pred)(int), size_t *outCount); // Функция фильтрации
int isEven(int x);      // Функция-предикат, проверяющая четность
int isNegative(int x);  // Функция-предикат, проверяющая отрицательность

int main() {
    int N;
    scanf("%d", &N);
    // Выделяем динамически память под массив из целых чисел длины N
    // и записываем в него входные числа
    int *numbers = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &numbers[i]);
    }
    // Переменные для хранения количества элементов после фильтрации
    size_t count_of_evens;
    size_t count_of_negatives;
    // Вызываем функцию фильтрации для isEven и isNegative и сохраняем результаты
    int *evens = filter(numbers, N, isEven, &count_of_evens);
    int *negatives = filter(numbers, N, isNegative, &count_of_negatives);

    // Выводим результаты
    printf("Even: ");
    for (size_t i = 0; i < count_of_evens; i++) {
        printf("%d ", evens[i]);
    }
    printf("\n");

    printf("Negative: ");
    for (size_t i = 0; i < count_of_negatives; i++) {
        printf("%d ", negatives[i]);
    }
    printf("\n");

    // Освобождаем выделенную память
    free(evens);
    free(negatives);
    free(numbers);

    return EXIT_SUCCESS;
}

// Функция фильтрации элементов массива
// принимает указатель на массив arr длины n
// фильтрует его по условию pred
// возвращает указатель на отфильтрованный массив, а его длину записывает в *outCount
int* filter(int *arr, size_t n, int (*pred)(int), size_t *outCount) {
    size_t count = 0;
    // Подсчитываем количество элементов, удовлетворяющих условию
    // чтобы выделить память для этого числа элементов
    for (size_t i = 0; i < n; i++) {
        if (pred(arr[i])) {
            count++;
        }
    }

    // Если таких элементов нет, возращаем NULL и в *outCount записываем 0
    if (count == 0) {
        *outCount = 0;
        return NULL;
    }
    // Выделяем динамическую память под отфильтрованный массив
    int *result = (int*)malloc(count * sizeof(int));
    if (result == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Записываем в отфильтрованный массив элементы, удовлетворяющие условию
    size_t j = 0;
    for (size_t i = 0; i < n; i++) {
        if (pred(arr[i])) {
            result[j++] = arr[i];
        }
    }

    // Записываем в *outCount длину отфильтрованного массива
    // и возвращаем указатель на этот массив
    *outCount = count;
    return result;
}

// Функция-предикат: возвращает 1, если x четное
int isEven(int x) {
    return x % 2 == 0;
}

// Функция-предикат: возвращает 1, если x отрицательное
int isNegative(int x) {
    return x < 0;
}