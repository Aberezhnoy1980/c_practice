#include <stdio.h>

int main() 
{
    char n[33];
    int a = 0;  
    int b = 0;  
    printf("Введите строку -> ");
    fgets(n, 33, stdin);
    
    for(int i = 0; n[i] != '\0'; i++)
    {
        char d = n[i];
        if(d >= 'а' && d <= 'я')
        {
            if(d == 'а' || d == 'у' || d == 'о' ||  d == 'ы' ||  d == 'э' ||  d == 'е' || d == 'ё' || d == 'и' || d == 'ю' || d == 'я')
            a++;
        }
        else
        {
            b++;
        }
    }
    
    if(a > b) 
    {
        printf("Гласных букв больше, чем согласных\n");
    }
    else if(a < b)
    {
        printf("Согласных букв больше, чем гласных\n");
    }
    else
    {
        printf("Гласных и согласных букв равное количество\n");
    }
    return 0;
}