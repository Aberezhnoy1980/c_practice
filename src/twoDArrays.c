/**
 * Написать программу, генерирующую магические квадраты заданного пользователем размера.
 * размерность матрицы задается пользователем
 * Матрица заполняется числами. Числа не должны поввторяться
 * Сумма чисел по строкам, столбца, диагоналям равны
 * Рабочий пример
 *
 * дана матрица 3 х 3:
 *
 * 8 1 6
 * 3 5 7
 * 4 9 2
 */

#include <stdio.h>

// Объявление функции вывода матрицы
void printMatrix(int matrixSize, int matrix[matrixSize][matrixSize]);

// Объявление функции вывода матрицы
void fillMagicSquare(int matrixSize, int matrix[matrixSize][matrixSize]);

// Определение основного алгоритма
void algorithmSiamMethod(int matrixSize)
{
    int magicSquare[matrixSize][matrixSize];
    int sum = matrixSize * matrixSize * (matrixSize * matrixSize + 1) / 2 / matrixSize;

    // Инициализация матрицы
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            magicSquare[i][j] = 0;
        }
    }

    // Вызов функции заполнения матрицы
    fillMagicSquare(matrixSize, magicSquare);

    // Вызов функции вывода матрицы
    printMatrix(matrixSize, magicSquare);
}

// Оперделение функции вывода матрицы в консоль
void printMatrix(int matrixSize, int matrix[matrixSize][matrixSize])
{
    printf("\nМатрица %dx%d:\n", matrixSize, matrixSize);
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            printf("%3d ", matrix[i][j]); // %3d для красивого вывода
        }
        printf("\n");
    }
}

// Определение функции для заполнения матрицы
void fillMagicSquare(int matrixSize, int matrix[matrixSize][matrixSize])
{
    // {1, 2, 3, 4, 5, 6, 7, 8, 9}
    int currentRow = 0;
    int currentCol = matrixSize / 2;
    matrix[currentRow][currentCol] = 1;

    printf("Текущая позиция: Строка: %d, Столбец: %d\n", currentRow, currentCol);
    int newCol, newRow;

    // {2, 3, 4, 5, 6, 7, 8, 9} делаем движение "вверх и вправо"
    for (int i = 2; i <= matrixSize * matrixSize; i++)
    {
        newRow = currentRow - 1;
        newCol = currentCol + 1;
        // printf("Строка: %d, Столбец: %d\n", newRow, newCol);
        if (newRow >= 0 && newCol < matrixSize)
        {
            printf("На первом %d шаге прошли проверку границы матрцы\n", i - 1);
            if (matrix[newRow][newCol] == 0)
            {
                currentRow = newRow;
                currentCol = newCol;
                printf("Запись элемента %d matrix[%d][%d]\n", i, currentRow, currentCol);
            }
            else
            {
                currentRow = (currentRow + 1) % matrixSize;
                printf("Запись элемента %d со сдвигом matrix[%d][%d]\n", i, currentRow, currentCol);
            }
        }
        else
        {
            printf("На %d шаге не прошли проверку граница матрицы\n", i - 1);
            if (newRow < 0)
            {
                currentRow = matrixSize - 1;
                // currentCol++;
            }
            if (newCol >= matrixSize)
            {
                // currentRow--;
                currentCol = 0;
            }
        }
        printf("Строка current: %d, Столбец current: %d\n", currentRow, currentCol);

        matrix[currentRow][currentCol] = i;
    }
}

int main()
{
    int matrixSize;
    printf("Введите размер массива: ");
    scanf("%d", &matrixSize);

    // Вызов функции основного алгоритма
    algorithmSiamMethod(matrixSize);

    return 0;
}

/**    0           1          2
 * {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}
 *
 * {
 *  {1, 2, 3},
 *  {4, 5, 6},
 *  {7, 8, 9}
 * }
 *
 * {{{{}}, {},}, {}, {}}
 *
 * Номера по функциям: 1, 6, 11
 */