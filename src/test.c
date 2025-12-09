#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    for (size_t i = 0; i < sizeof(arr) / sizeof(int) ; i++)
    {
        printf("%d ", arr[i]);
    }
}