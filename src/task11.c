/**
 * Написать функцию Procent, которая возвращает нужный процент от полученного в качестве аргумента числа
 */

float Procent(float number, float percent)
{
    return number * percent / 100;
}

#include <stdio.h>

int main()
{
    printf("%.2f ", Procent(40, 23));

    return 0;
}