#include <stdio.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void processArray(int arr[], int *size) {
    // Сначала подсчитаем, сколько элементов будет в результате
    int count = 0;
    for (int i = 0; i < *size; i++) {
        if (arr[i] != 0) {
            count++;
            if (arr[i] % 10 == 5 || arr[i] % 10 == -5) {
                count++; // +1 для вставляемой единицы
            }
        }
    }
    
    // Создаем временный массив
    int temp[count];
    int index = 0;
    
    // Заполняем временный массив
    for (int i = 0; i < *size; i++) {
        if (arr[i] != 0) {
            temp[index++] = arr[i];
            if (arr[i] % 10 == 5 || arr[i] % 10 == -5) {
                temp[index++] = 1;
            }
        }
    }
    
    // Копируем обратно в исходный массив
    for (int i = 0; i < count; i++) {
        arr[i] = temp[i];
    }
    
    *size = count;
}

int main() {
    int arr[20] = {5, 0, 15, 3, 0, 25, 7, -5, 0, 10, 35}; // Задаем с запасом
    int size = 11; // Только для инициализированных элементов
    
    printf("Исходный массив: ");
    printArray(arr, size);
    
    processArray(arr, &size);
    
    printf("Результат: ");
    printArray(arr, size);
    
    return 0;
}