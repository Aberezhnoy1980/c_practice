#include <stdio.h>
#include <stdlib.h>

// ==================== СТРУКТУРЫ ДАННЫХ ====================
typedef struct {
    int row;
    int col;
} Position;

typedef struct {
    int** data;
    int size;
    Position current_pos;
    int current_value;
    int step_counter;
} MagicSquare;

// ==================== ОБЪЯВЛЕНИЯ ФУНКЦИЙ ====================
MagicSquare* createMagicSquare(int size);
void freeMagicSquare(MagicSquare* square);
void initializeMatrix(MagicSquare* square);
int fillMagicSquare(MagicSquare* square);
Position calculateNextPosition(MagicSquare* square, Position current);
int isValidPosition(MagicSquare* square, Position pos);
void printMatrix(const MagicSquare* square);
void printStepInfo(const MagicSquare* square, const char* action);

// ==================== ОСНОВНЫЕ ФУНКЦИИ ====================

// Создание структуры магического квадрата
MagicSquare* createMagicSquare(int size) {
    MagicSquare* square = (MagicSquare*)malloc(sizeof(MagicSquare));
    square->size = size;
    square->current_value = 0;
    square->step_counter = 0;
    
    // Выделение памяти для матрицы
    square->data = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        square->data[i] = (int*)calloc(size, sizeof(int));
    }
    
    return square;
}

// Освобождение памяти
void freeMagicSquare(MagicSquare* square) {
    for (int i = 0; i < square->size; i++) {
        free(square->data[i]);
    }
    free(square->data);
    free(square);
}

// Инициализация матрицы нулями
void initializeMatrix(MagicSquare* square) {
    printf("🔹 Инициализация матрицы %dx%d нулями\n", square->size, square->size);
    for (int i = 0; i < square->size; i++) {
        for (int j = 0; j < square->size; j++) {
            square->data[i][j] = 0;
        }
    }
    printStepInfo(square, "Матрица инициализирована");
}

// Проверка валидности позиции
int isValidPosition(MagicSquare* square, Position pos) {
    return pos.row >= 0 && pos.row < square->size && 
           pos.col >= 0 && pos.col < square->size;
}

// Расчет следующей позиции по Сиамскому методу
Position calculateNextPosition(MagicSquare* square, Position current) {
    Position next;
    
    // Движение "вверх-вправо"
    next.row = current.row - 1;
    next.col = current.col + 1;
    
    // Обработка границ - торoidal wrapping
    if (next.row < 0) next.row = square->size - 1;
    if (next.col >= square->size) next.col = 0;
    
    return next;
}

// Основной алгоритм заполнения
int fillMagicSquare(MagicSquare* square) {
    if (square->size % 2 == 0) {
        printf("❌ Ошибка: Сиамский метод работает только для нечетных размеров!\n");
        return 0;
    }
    
    printf("🚀 Начало заполнения магического квадрата\n");
    
    // Начальная позиция - середина первой строки
    square->current_pos.row = 0;
    square->current_pos.col = square->size / 2;
    square->current_value = 1;
    
    // Записываем первое число
    square->data[square->current_pos.row][square->current_pos.col] = square->current_value;
    printStepInfo(square, "Установлено начальное значение");
    
    // Заполняем остальные числа
    for (int i = 2; i <= square->size * square->size; i++) {
        square->step_counter++;
        square->current_value = i;
        
        printf("\n🔹 Шаг %d: Заполняем число %d\n", square->step_counter, i);
        
        // Пытаемся двигаться "вверх-вправо"
        Position next_pos = calculateNextPosition(square, square->current_pos);
        printf("📐 Пробуем позицию: [%d,%d]\n", next_pos.row, next_pos.col);
        
        if (square->data[next_pos.row][next_pos.col] == 0) {
            // Ячейка свободна - занимаем её
            square->current_pos = next_pos;
            printf("✅ Ячейка свободна - перемещаемся\n");
        } else {
            // Ячейка занята - двигаемся вниз
            square->current_pos.row = (square->current_pos.row + 1) % square->size;
            printf("❌ Ячейка занята - двигаемся вниз: [%d,%d]\n", 
                   square->current_pos.row, square->current_pos.col);
        }
        
        // Записываем число
        square->data[square->current_pos.row][square->current_pos.col] = i;
        printStepInfo(square, "Число записано в матрицу");
    }
    
    printf("\n🎉 Заполнение завершено!\n");
    return 1;
}

// Вывод информации о шаге
void printStepInfo(const MagicSquare* square, const char* action) {
    printf("   📍 Текущая позиция: [%d,%d]\n", 
           square->current_pos.row, square->current_pos.col);
    printf("   🔢 Текущее значение: %d\n", square->current_value);
    printf("   📝 Действие: %s\n", action);
}

// Вывод матрицы
void printMatrix(const MagicSquare* square) {
    printf("\n🧮 Итоговая матрица %dx%d:\n", square->size, square->size);
    printf("   ");
    for (int j = 0; j < square->size; j++) {
        printf(" %2d ", j);
    }
    printf("\n");
    
    for (int i = 0; i < square->size; i++) {
        printf("%2d ", i);
        for (int j = 0; j < square->size; j++) {
            if (i == square->current_pos.row && j == square->current_pos.col) {
                printf("[%2d]", square->data[i][j]); // Выделяем текущую позицию
            } else {
                printf(" %2d ", square->data[i][j]);
            }
        }
        printf("\n");
    }
}

// ==================== ГЛАВНАЯ ФУНКЦИЯ ====================
int main() {
    int matrixSize;
    
    printf("=========================================\n");
    printf("       🧙‍♂️ МАГИЧЕСКИЙ КВАДРАТ\n");
    printf("=========================================\n");
    
    printf("Введите размер матрицы (нечетное число): ");
    if (scanf("%d", &matrixSize) != 1) {
        printf("❌ Ошибка ввода!\n");
        return 1;
    }
    
    if (matrixSize <= 0 || matrixSize % 2 == 0) {
        printf("❌ Размер должен быть положительным нечетным числом!\n");
        return 1;
    }
    
    // Создаем и инициализируем магический квадрат
    MagicSquare* magicSquare = createMagicSquare(matrixSize);
    initializeMatrix(magicSquare);
    
    // Заполняем магический квадрат
    if (fillMagicSquare(magicSquare)) {
        printMatrix(magicSquare);
        
        // Расчет магической суммы
        int magic_sum = matrixSize * (matrixSize * matrixSize + 1) / 2;
        printf("\n✨ Магическая сумма: %d\n", magic_sum);
    }
    
    // Освобождаем память
    freeMagicSquare(magicSquare);
    
    return 0;
}