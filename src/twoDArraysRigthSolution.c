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
      
                // Обработка выхода за границы
        if (newRow < 0) {
            newRow = matrixSize - 1;  // Выход сверху -> переходим вниз
        }
        if (newCol >= matrixSize) {
            newCol = 0;  // Выход справа -> переходим влево
        }
        
        // Проверяем, свободна ли новая ячейка
        if (matrix[newRow][newCol] == 0) {
            // Ячейка свободна - занимаем её
            currentRow = newRow;
            currentCol = newCol;
        } else {
            // Ячейка занята - двигаемся вниз от текущей позиции
            currentRow = (currentRow + 1) % matrixSize;  // % для обработки границ
            // currentCol остается прежним
        }

        matrix[currentRow][currentCol] = i;
        printf("Запись элемента %d matrix[%d][%d]\n", i, currentRow, currentCol);
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