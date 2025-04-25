#include <stdio.h>
#include <stdlib.h>
#define START_YEAR 1900 // смещение для поля year, чтобы хранить в year только года от 1900 до 2027

typedef struct BirthDate {
    unsigned int day : 5;
    unsigned int month : 4;
    unsigned int year : 7;   // чтобы структура занимала целое количество байт и не оставалось неиспользованных битов в байте
    // т. е. 5 + 4 + 7 = 16 бит = 2 байт
} BirthDate;

int main() {
    unsigned int day, month, year;
    printf("Input the day of your birth: ");
    scanf("%u", &day);
    if (!(day >= 1 && day <= 31)) {
        printf("The day value must be in the range from 1 to 31!\n");
        return EXIT_FAILURE;
    }
    printf("Input the month of your birth: ");
    scanf("%u", &month);
    if (!(month >= 1 && month <= 12)) {
        printf("The month value must be in the range from 1 to 12!\n");
        return EXIT_FAILURE;
    }
    printf("Input the year of your birth: ");
    scanf("%u", &year);
    if (!(year >= 1900 && year <= 2027)) {
        printf("The year value must be in the range from 1900 to 2027!\n");
        return EXIT_FAILURE;
    }

    BirthDate bd = {day, month, year - START_YEAR};
    printf("Your birthdate: %d.%d.%d\n", bd.day, bd.month, bd.year + START_YEAR);
    printf("sizeof(BirthDate): %lu\n", sizeof(BirthDate));

    return EXIT_SUCCESS;
}