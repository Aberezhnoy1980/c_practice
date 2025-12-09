#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void CE(int mass[], int a, int b) 
{
    int c;
    c = mass[a];
    mass[a] = mass[b];
    mass[b] = c;
}
void arrayItemsExchange(int array[], int firstElementNumber, int secondElementNumber)
{
    int tempValue = array[firstElementNumber - 1];
    array[firstElementNumber - 1] = array[secondElementNumber - 1];
    array[secondElementNumber - 1] = tempValue;
}
int main() 
{
    int *p;
    int i, n;
    printf("Введите размер массива: ");
    scanf("%d", &n);
    srand(time(NULL));
    p = (int *)malloc(n * sizeof(int));
    for(i=0; i<n; i++) 
    {
        p[i] = rand() % 5;  
    }
    printf("Исходный массив: ");
    for(i=0; i<n ; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");
    int e1, e2;
    printf("Введите номера элементов которые нужно поменять: ");
    scanf("%d", &e1);
    scanf("%d", &e2);
    arrayItemsExchange(p, e1, e2);
    printf("Измененный массив: ");
    for(i=0; i<n; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");
    free(p);
    return 0;
}