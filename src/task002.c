#include <stdio.h>
#include <stdlib.h>

int* processArrayWithNew(int arr[], int size, int *newSize) {
    // Создаем временный массив максимально возможного размера
    int *temp = malloc(size * 2 * sizeof(int));
    // int temp[size * 2];
    int count = 0; // после первого шага 2 //
    
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            temp[count++] = arr[i]; // temp[0] = 5
            
            // Проверяем, оканчивается ли число на 5
            if (arr[i] % 10 == 5 || arr[i] % 10 == -5) {
                temp[count++] = 1; // temp[1] = 1
            }
        }
        // temp = {5, 1, 5, 1}
    }
    
    *newSize = count;
    return temp;
}

int main() {
    int arr[] = {5, 0, 15, 3, 0, 25, 7, -5, 0, 10, 35};
    int size = sizeof(arr) / sizeof(arr[0]);
    int newSize;
    
    printf("Исходный массив: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    int *result = processArrayWithNew(arr, size, &newSize);
    
    int arrayLength = sizeof(*result) / sizeof(result[0]);
    printf("Результат: ");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    
    free(result);
    return 0;
}