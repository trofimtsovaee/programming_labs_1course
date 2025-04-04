#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double ***pointer = NULL;

    *( *( *(pointer = (double ***)malloc(sizeof(double **))) = (double **)malloc(sizeof(double *)) ) = (double *)malloc(sizeof(double)) ) = 2.0;
    // Для самого pointer выделили динамически память, чтобы хранить в нем указатель double**
    // Разыменовали double *** и получили указатель double**
    // Для указателя double** выделили динамически память, чтобы хранить в нем указатель double*
    // Разыменовали double ** и получили указатель double*
    // Для указателя double* выделили динамически память, чтобы хранить в нем double
    // Разыменовали double* и получили double
    // И уже в double записали значение 2.0

    if (pointer == NULL) {      // Проверка на успешное выделение памяти
        return EXIT_FAILURE;
    }
    
    printf("%.2lf\n", ***pointer);
    
    // Постепенно освобождаем динамическую память
    free(**pointer);    // Сначала освобождаем память, выделенную под указатель double*
    free(*pointer);     // Затем освобождаем память, выделенную под указатель double**
    free(pointer);      // Затем освобождаем память, выделенную под указатель double*** (сам указатель pointer)
    
    return EXIT_SUCCESS;
}