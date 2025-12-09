#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    printf("Локаль по умолчанию: %s\n", setlocale(LC_ALL, NULL));
    printf("Локаль после установки: %s\n", setlocale(LC_ALL, ""));
    
    char test[] = "Привет";
    printf("Тестовая строка: %s\n", test);
    printf("Длина строки: %zu\n", strlen(test));
    
    // Посмотрим на байты
    printf("Байты строки: ");
    for(int i = 0; test[i] != '\0'; i++) {
        printf("%02x ", (unsigned char)test[i]);
    }
    printf("\n");
    
    return 0;
}