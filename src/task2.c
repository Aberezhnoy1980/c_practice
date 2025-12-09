#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Случайным образом генерируется массив чисел. Пользователь вводит числа a и b. Заменить элемент массива на сумму его соседей, если элемент массива четный и номер его лежит в промежутке от a до b.
*/

int main()
{
    // объявлили переменные для управления циклом и размерности исходного массива
    int i, n;
    // приглашение пользователю ввести размерность массива
    // printf("Введите размерность массива -> \n");
    // инициализация переменной размера массива
    // scanf("%d", &n);

    // запуск генератора
    srand(time(NULL));

    int originArray[n];

    for (size_t i = 0; i < n; i++)
    {
        originArray[i] = rand() % 100;
    }

    // for (size_t i = 0; i < n; i++)
    // {
    //     printf("%d ", originArray[i]);
    // }
    printf("\n");

    int a, b;
    // printf("Введите два целочисленных числа -> \n");
    // scanf("%d, %d", &a, &b);

    // printf("a = %d | b = %d\n", a, b);

    // {1, 2, 3, 4, 5, 6, 7, 8}

    for (int i = 0; i < n; i++)
    {
        if (originArray[i] % 2 == 0 && i >= a && i <= b)
        {
            if (i == 0)
            {
                originArray[i] = originArray[n - 1] + originArray[i + 1];
                continue;
            }
            if (i == n - 1)
            {
                originArray[i] = originArray[i - 1] + originArray[0];
                continue;
            }
            originArray[i] = originArray[i - 1] + originArray[i + 1];
        }
    }

    // printf("Результат:\n");
    // for (size_t i = 0; i < n; i++)
    // {
    //     printf("%d ", originArray[i]);
    // }

    // ===================
    // вариант без перезаписанных значений

    int testArr[] = {8, 14, 32, 78, 4};
    int testA = 0;
    int testB = 4;

    int testN = sizeof(testArr) / sizeof(testArr[0]);

    int resArr[testN];

    for (size_t i = 0; i < testN; i++)
    {
        if (testArr[i] % 2 == 0 && i >= testA && i <= testB)
        {
            if (i == 0)
                resArr[i] = testArr[testN - 1] + testArr[i + 1];
            else if (i == testN - 1)
                resArr[i] = testArr[i - 1] + testArr[0];
            else
                resArr[i] = testArr[i - 1] + testArr[i + 1];
        }
        else
            resArr[i] = testArr[i];
    }

    printf("\nРезультат с сохранением исходного:\n");
    for (size_t i = 0; i < testN; i++)
    {
        printf("%d ", resArr[i]);
    }

    return 0;
}