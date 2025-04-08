#include <stdio.h>
#include <stdlib.h>

// Создаем перечисление Season с временами года
enum Season {
    WINTER, SPRING, SUMMER, AUTUMN
};

int main(void) {
    int month;
    printf("Input the month number: ");
    scanf("%d", &month);

    enum Season season; // объявляем переменную season типа перечисления Season
                        // она может принимать только одно из четырех значений, перечисленных в Season
    switch (month)
    {
    case 12:    // сквозное выполнение, так как несколько случаев обрабатываются одинаково
    case 1:
    case 2:
        season = WINTER; break;
    case 3:
    case 4:
    case 5:
        season = SPRING; break;
    case 6:
    case 7:
    case 8:
        season = SUMMER; break;
    case 9:
    case 10:
    case 11:
        season = AUTUMN; break;
    default:    // обработка неправильно введенного номера месяца
        printf("Incorrect month number!\n");
        return EXIT_FAILURE;
    }

    switch (season) {
        case WINTER: printf("Winter\n"); break;
        case SPRING: printf("Spring\n"); break;
        case SUMMER: printf("Summer\n"); break;
        case AUTUMN: printf("Autumn\n"); break;
    }

    return EXIT_SUCCESS;
}