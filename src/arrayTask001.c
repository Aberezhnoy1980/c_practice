#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Дан массив. Удалить из него нули и после каждого числа, оканчивающего на 5, вставить 1
*/
int main()
{

    // объявлили переменные для управления циклом и размерности исходного массива
    int i, n;
    // приглашение пользователю ввести размерность массива
    printf("Введите размерность массива -> ");
    // инициализация переменной размера массива
    scanf("%d", &n);

    // запуск генератора
    srand(time(NULL));

    // объявление исходного массива
    int originArray[n];

    // объявление и инициализация переменно для расчета длинны результирующего массива
    int resultArrayLength = 0;

    // заполнение исходного массива случайными значениями и расчет длины результирующего массива
    for (i = 0; i < n; i++)
    {
        originArray[i] = rand() % 100;

        if (originArray[i] != 0)
        {
            resultArrayLength++;

            if (originArray[i] % 10 == 5 || originArray[i] % 10 == -5)
                resultArrayLength++;
        }
    }
    // i = 9
    // printf("\n%d\n", i);

    // объявление и инициализация результирующего массива
    int resultArray[resultArrayLength];

    // int originArray2[] = {5, 5, 5, 5, 5, 5, 5, 5}; // тестовые данные
    // n = sizeof(originArray2) / sizeof(originArray2[0]);
    // int resultArray2[16];
    // for (int i = 0; i < 16; i++)
    // {
    //     resultArray2[i] = -1;
    // }

    // выяснили размер для того, что бы объявить результирующий

    // У нас на данной точке программы
    // originArray = {0, 0, 1, 2, 3, 4, 5, 6} (было 8 элементов, после расчета размера для резМассива станет 7 - это размер)
    // resultArray[7] = {1, 2, 3, 4 ,5, 1, 6}

    // переменная для итерирования результирующего массива
    // printf("%d\n", n);
    int count = 0;
    // for (i = 0; i < n; i++)
    // {
    //     if (originArray2[i] != 0)
    //     {
    //         resultArray2[count++] = originArray2[i];

    //         if (originArray2[i] % 10 == 5 || originArray2[i] % 10 == -5)
    //             resultArray2[count++] = 1;
    //     }
    //     printf("Итерация № %d : i = %d : oa = %d | count = %d : ra = {%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d,}\n", i, i, originArray2[i], count, resultArray2[0], resultArray2[1], resultArray2[2], resultArray2[3], resultArray2[4], resultArray2[5], resultArray2[6], resultArray2[7], resultArray2[8], resultArray2[9], resultArray2[10], resultArray2[11], resultArray2[12], resultArray2[13], resultArray2[14], resultArray2[15]);
    // }

    for (i = 0; i < n; i++)
    {
        if (originArray[i] != 0)
        {
            resultArray[count++] = originArray[i];

            if (originArray[i] % 10 == 5 || originArray[i] % 10 == -5)
                resultArray[count++] = 1;
        }
    }

    // вывод массивов на экран
    printf("Origin array\n");
    for (int i = 0; i < n; i++)
    {
        printf("origin array[%d] = %d\n", i, originArray[i]);
    }

    printf("\nResult array\n");

    for (int i = 0; i < resultArrayLength; i++)
    {
        printf("result array[%d] = %d\n", i, resultArray[i]);
    }

    // for (int i = 0; i < n; i++)
    // {
    //     printf("origin array[%d] = %d\n", i, originArray[i]);
    // }
    return 0;
}