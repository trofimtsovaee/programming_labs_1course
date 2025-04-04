#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a = 1234567890;
    unsigned char *charPtr = (unsigned char*) &a;
    // Создаем указатель типа unsigned char*, указывающий на первый байт переменной a.
    // unsigned char, так как он хранит значения от 0 до 255,
    // в отличие от char, который хранит значения от -128 до 127, что неудобно для привычного побайтового предстапвления десятичных чисел.

    printf("a = %d\n", a);
    printf("a byte-by-byte: |");
    for (int i = 0; i < sizeof(a); i++) {   // Параметр цикла i изменяется до sizeof(a), т. е. до 4 - размер переменной типа int в байтах.
        printf("%5d |", *(charPtr + i));    // Выводим значение, записанное по адресу, смещенному от charPtr (адреса первого байта переменной a) 
    }                                       // на i байт, так как размер типа char равен 1 байт.
    printf("\n");

    return EXIT_SUCCESS;
}