#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 50
#define N 3

struct Book
{
    char title[MAX_LENGTH];
    char author[MAX_LENGTH];
    int year;
};

// передаем в функцию указатель на массив структур Book и количество книг в этом массиве
void printBooks(struct Book *books, int n) {
    printf("\n---CATALOGUE--\n");
    for (int i = 0; i < n; i++) {
        printf("Book №%d\n", i + 1);
        printf("\tTitle: %s", books[i].title);      // обращаемся сначала к конкретной книге по порядковому номеру в массиве,
        printf("\tAuthor: %s", books[i].author);    // а затем через точку к полю структуры Book
        // после вывода названия и автора перенос строки "\n" писать не нужно, 
        //так как fgets() уже считал его при вводе названия и автора
        printf("\tYear of release: %d\n", books[i].year);
    }
}

int main(void) {
    struct Book books[N];
    for (int i = 0; i < N; i++) {
        printf("Book №%d\n", i + 1);
        printf("\tInput the name of the book: ");
        fgets(books[i].title, MAX_LENGTH, stdin);
        // fgets() принимает строку, в которую будет записывать, длину этой строки
        // и источник ввода (в данном случае стандартный поток ввода)

        printf("\tInput the author of the book: ");
        fgets(books[i].author, MAX_LENGTH, stdin);

        printf("\tInput the year of the book's release: ");
        scanf("%d", &books[i].year);
        while (getchar() != '\n');
        // очищаем буфер ввода от оставшегося в нем '\n',
        // чтобы следующий fgets() не считал пустую строку
    }
    
    printBooks(books, N);

    return EXIT_SUCCESS;
}
