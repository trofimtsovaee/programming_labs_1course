#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 100  // Максимальная длина входной строки

// Структура дроби
typedef struct Fraction {
    int numerator;      // Числитель
    int denominator;    // Знаменатель
} Fraction;

// Объявления функций
int GCD(int a, int b);                          // Функция нахождения НОД
Fraction reducing(Fraction f);                  // Функция сокращения дроби
Fraction make_fraction(int num, int den);       // Функция создания несокращаемой дроби
Fraction addition(Fraction f1, Fraction f2);    // Функция сложения дробей
Fraction substraction(Fraction f1, Fraction f2); // Функция вычитания дробей
Fraction multiplication(Fraction f1, Fraction f2); // Функция умножения дробей
Fraction division(Fraction f1, Fraction f2);    // Функция деления дробей

int main() {
    char buffer[MAX_LENGTH];            // Буфер для хранения входной строки
    char operation;                     // Переменная для хранения символа арифметической операции
    Fraction f1, f2;                    // Дроби f1 и f2 - экземпляры структуры Fraction

    fgets(buffer, MAX_LENGTH, stdin);   // Считываем входную строку и сохраняем ее в buffer
    // Теперь через sscanf() можем форматированно прочитать buffer и сохранить числители и знаменатели дробей и оператор
    int read = sscanf(buffer, "%d/%d %c %d/%d", &f1.numerator, &f1.denominator, &operation, &f2.numerator, &f2.denominator);
    // Переменная read нужна для проверки корректности формата ввода
    if (read != 5) {    // Если sscanf() вернул 5, то все 5 значений успешно считаны
        printf("Invalid input format\n");   // Иначе возвращаем ошибку
        return EXIT_FAILURE;
    }

    // Проверяем, что знаменатели не равны нулю
    if (f1.denominator == 0 || f2.denominator == 0) {
        printf("Invalid fraction: denominator cannot be zero\n");
        return EXIT_FAILURE;
    }

    // Сокращаем входные дроби, чтобы не производить операции с слишком большими числами
    f1 = reducing(f1);
    f2 = reducing(f2);
    Fraction result;

    // Выбор арифметической операции
    switch (operation) {
        case '+':
            result = addition(f1, f2);
            break;
        case '-':
            result = substraction(f1, f2);
            break;
        case '*':
            result = multiplication(f1, f2);
            break;
        case '/':
            // Проверка деления на дробь с нулевым числителем
            if (f2.numerator == 0) {
                printf("Division by zero\n");
                return EXIT_FAILURE;
            }
            result = division(f1, f2);
            break;
        default:
            // Некорректная операция
            printf("Invalid operation\n");
            return EXIT_FAILURE;
    }

    // Сокращаем результат до несокращаемой дроби
    result = reducing(result);
    printf("Answer: %d/%d\n", result.numerator, result.denominator);

    return EXIT_SUCCESS;
}

// Функция нахождения НОД через остаток
int GCD(int a, int b) {
    a = abs(a); // Работаем с модулями во избежание ошибок
    b = abs(b);
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Функция сокращения дроби
Fraction reducing(Fraction f) {
    // Если числитель равен нулю, сразу приводим знаменатель к единице
    if (f.numerator == 0) {
        f.denominator = 1;
        return f;
    }

    // Находим НОД числителя и знаменателя и сокращаем их
    int gcd = GCD(f.numerator, f.denominator);
    f.numerator /= gcd;
    f.denominator /= gcd;

    // Обеспечиваем положительный знаменатель
    if (f.denominator < 0) {
        f.numerator = -f.numerator;
        f.denominator = -f.denominator;
    }
    return f;
}

// Функция создания несокращаемой дроби
// Нужна, чтобы избежать повторяющегося кода в функциях операций
Fraction make_fraction(int num, int den) {
    Fraction f = {num, den};
    f = reducing(f);
    return f;
}

// Функция сложения двух дробей
Fraction addition(Fraction f1, Fraction f2) {
    return make_fraction(
        f1.numerator * f2.denominator + f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    );
}

// Функция вычитания двух дробей
Fraction substraction(Fraction f1, Fraction f2) {
    return make_fraction(
        f1.numerator * f2.denominator - f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    );
}

// Функция умножения двух дробей
Fraction multiplication(Fraction f1, Fraction f2) {
    return make_fraction(
        f1.numerator * f2.numerator,
        f1.denominator * f2.denominator
    );
}

// Функция деления двух дробей
Fraction division(Fraction f1, Fraction f2) {
    return make_fraction(
        f1.numerator * f2.denominator,
        f1.denominator * f2.numerator
    );
}
