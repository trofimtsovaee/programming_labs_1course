#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1000

typedef struct Stack {
    char *data;    // Указатель на массив для хранения скобок
    int top;       // Индекс вершины стека (последнего добавленного элемента)
} Stack;

void init(Stack *s, size_t len);    // Функция инициализации стека
bool isEmpty(Stack *s);             // Функция проверки стека на пустоту
bool push(Stack *s, char value);    // Функция добавления элемента в стек
bool pop(Stack *s, char *value);    // Функция удаления элемента из стека
bool peek(Stack *s, char *value);   // Функция получения значения на вершине стека

int main() {
    char buffer[MAX_SIZE];                  // Буфер для хранения входной строки
    fgets(buffer, MAX_SIZE, stdin);         // Считываем входную строку и сохраняем ее в buffer
    size_t len = strlen(buffer);            // Получаем длину входной строки
    
    if (len > 0 && buffer[len-1] == '\n') {
        buffer[len - 1] = '\0';     // Удаляем символ новой строки, если он есть
        len--;                      // Корректируем длину строки
    }

    Stack stack;
    init(&stack, len);  // Инициализируем стек

    for (int i = 0; buffer[i] != '\0'; i++) {
        // Если это открывающая скобка, то добавляем ее в стек
        if (buffer[i] == '(' || buffer[i] == '[' || buffer[i] == '{') {
            push(&stack, buffer[i]);
        } 
        // Если скобка закрывающая:
        else if (buffer[i] == ')' || buffer[i] == ']' || buffer[i] == '}') {
            char value;
            // Получаем элемент на вершине стека
            if (!peek(&stack, &value)) {
                // Стек пуст - значит закрывающая скобка без пары - ошибка
                printf("NO\n");
                return EXIT_SUCCESS;
            }
            // Удаляем соответствующую открывающую скобку из стека
            // Иначе возвращаем "NO"
            switch (buffer[i]) {
            case ')':
                if (value == '(') {
                    pop(&stack, &value);
                }
                else {
                    printf("NO\n");
                    return EXIT_SUCCESS;
                }
                break;
            case ']':
                if (value == '[') {
                    pop(&stack, &value);
                }
                else {
                    printf("NO\n");
                    return EXIT_SUCCESS;
                }
                break;
            case '}':
                if (value == '{') {
                    pop(&stack, &value);
                }
                else {
                    printf("NO\n");
                    return EXIT_SUCCESS;
                }
                break;
            }
        }
    }

    // Если стек пуст - значит все скобки закрыты правильно
    if (isEmpty(&stack)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    free(stack.data);   // Освобождаем динамическую память, выделенную под стек

    return EXIT_SUCCESS;
}

// Функция инициализации стека
void init(Stack *s, size_t len) {
    s->top = -1;    // Изначально стек пуст - присваиваем вершине стека значение -1
    s->data = malloc(len * sizeof(char)); // И динамически выделяем под стек память по размеру входной строки
    // Проверка на успешное выделение памяти
    if (s->data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}

// Функция проверки стека на пустоту
bool isEmpty(Stack *s) {
    return s->top == -1;
    // Проверяем, что индекс вершины стека -1
    // Если да - возвращается true
    // Если нет - false и значит стек не пуст
}

// Функция добавления элемента в стек
bool push(Stack *s, char value) {
    s->data[++(s->top)] = value;    // Увеличиваем индекс вершины стека на 1 и сохраняем значение
    return true;
}

// Функция удаления элемента из стека
bool pop(Stack *s, char *value) {
    if (isEmpty(s)) {               // Если стек пуст,
        printf("Stack is empty\n"); // то удаление элемента из стека не происходит
        return false;               // и функция возвращает false
    }
    *value = s->data[(s->top)--];   // Сохраняем удаляемое значение в value и после этого уменьшаем индекс вершины стека на 1
    return true;
}

// Функция получения значения на вершине стека
bool peek(Stack *s, char *value) {
    if (isEmpty(s)) {   // Если стек пуст, то мы не можем получить значение на его вершине
        return false;   // и возращаем false
    }
    *value = s->data[s->top];   // Сохраняем значение на вершине стека в value
    return true;
}