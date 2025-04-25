#include <stdio.h>
#include <stdlib.h>
#define LEN 5

union Data {
    int i;
    float f;
    char c;
};

enum DataType {
    INT, FLOAT, CHAR
};

typedef struct MyStruct {
    union Data data;
    enum DataType type;
} MyStruct;

MyStruct inputArray(MyStruct *array);
void printArray(MyStruct *array);

int main() {
    MyStruct *array = (MyStruct*)malloc(LEN * sizeof(MyStruct));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    inputArray(array);
    printArray(array);

    free(array);    

    return EXIT_SUCCESS;
}

MyStruct inputArray(MyStruct *array) {
    printf("If you want the element to be int, press '1', float - press '2', char - press '3'\n");
    for (int i = 0; i < LEN; i++) {
        int t;
        printf("Element #%d:\n", i + 1);
        printf("\tInput element type (1, 2, 3): ");
        while (scanf("%d", &t) != 1 || (t != 1 && t != 2 && t != 3)) {
            printf("\tInvalid element type! Input '1', '2', or '3' (1 - int, 2 - float, 3 - char): ");
            while (getchar() != '\n');  // очистка буфера ввода для корректного следующего считывания
        }

        while (getchar() != '\n');  // очистка буфера ввода для корректного следующего считывания

        switch (t) {
        case 1:
            array[i].type = INT;
            float value;
            printf("\tInput the element value: ");
            // проверка того, записалось ли что-то в value и точно ли value является целым числом
            while (scanf("%f", &value) != 1 || value - (int)value != 0) {
                printf("\tWrong value! Input the integer: ");
                while (getchar() != '\n');
            }
            while (getchar() != '\n');

            // когда в value наконец-то записано именно целое число, а не дробное или другой символ,
            // то передаем в поле data значение value
            array[i].data.i = (int)value;
            break;
        case 2:
            array[i].type = FLOAT;
            printf("\tInput the element value: ");
            // проверка того, записалось ли в поле data число
            while (scanf("%f", &array[i].data.f) != 1) {
                printf("\tWrong value! Input the float: ");
                while (getchar() != '\n');
            }
            while (getchar() != '\n');
            break;
        case 3:
            array[i].type = CHAR;
            printf("\tInput the element value: ");
            // проверка, чтобы в поле data не записался символ переноса строки
            // (в таком случае ввод просто будет пропущен),
            // оставшийся из прошлого scanf()
            while (scanf("%c", &array[i].data.c) != 1) {
                printf("\tWrong value! Input the valid char: ");
                while (getchar() != '\n');
            }
            while (getchar() != '\n');
            break;
        }
    }
}

void printArray(MyStruct *array) {
    printf("\nArray printout:\n");
    for (int i = 0; i < LEN; i++) {
        switch (array[i].type) {
        case INT:
            printf("%d. data: %d, type: INT\n", i+1, array[i].data.i);
            break;
        case FLOAT:
            printf("%d. data: %.3f, type: FLOAT\n", i+1, array[i].data.f);
            break;
        case CHAR:
            printf("%d. data: %c, type: CHAR\n", i+1, array[i].data.c);
            break;
        }
    }
}