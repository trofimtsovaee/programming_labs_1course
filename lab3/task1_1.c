#include <stdio.h>
#include <stdlib.h>

void printHello() {
    printf("Hello\n");
}

struct Struct
{
    void (*funcPtr)();  // указатель на функцию, не принимающую ничего и возвращающую void, то есть тоже ничего
};

int main() {
    struct Struct f;
    f.funcPtr = printHello; // записываем в поле funcPtr переменной f типа Struct адрес на функцию
    f.funcPtr();            // вызываем функцию через структуру

    return EXIT_SUCCESS;
}