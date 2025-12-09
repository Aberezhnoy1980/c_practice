#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n;
    srand(time(NULL));
    printf("Введите размерность массива -> ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10;
        printf("%d ", arr[i]);
    }

    // int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};

    printf("\n");

    for (int i = 1; i < 18; i*=2)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}