#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    /*
    Дан массив. Удалить из него нули и после каждого числа, оканчивающего на 5, вставить 1
    */

    // переменные для управления циклом и размерности исходного массива 
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
    for (int i = 0; i < n; i++)
    {
        originArray[i] = rand()%100;

        if (originArray[i] != 0)
        {
            resultArrayLength++;

            if (originArray[i] % 10 == 5 || originArray[i] % 10 == -5) resultArrayLength++;
        }
    }

    // объявление и инициализация результирующего массива
    int resultArray[resultArrayLength];
    
    // переменная для итерирования результирующего массива
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (originArray[i] != 0)
        {
            resultArray[count++] = originArray[i];

            if (originArray[i] % 10 == 5 || originArray[i] % 10 == -5) resultArray[count++] = 1;
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
    
    
    
    


    return 0;
}