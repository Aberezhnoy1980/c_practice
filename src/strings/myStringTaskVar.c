#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char text[33];
    int vowelCount = 0;
    int consonantCount = 0;
    printf("Введите строку -> ");
    fgets(text, 33, stdin);

    int textIdx = 0;

    while(stricmp(text[textIdx], '\0') != 0)
    {
        char d = text[textIdx];
        if (d >= "а" && d <= "я")
        {
            if (d == "а" || d == "у" || d == "о" || d == "ы" || d == "э" || d == "е" || d == "ё" || d == "и" || d == "ю" || d == "я")
                vowelCount++;
        }
        else
        {
            consonantCount++;
        }
        textIdx++;
    }

    if (vowelCount > consonantCount)
    {
        printf("Гласных букв больше, чем согласных\n");
    }
    else if (vowelCount < consonantCount)
    {
        printf("Согласных букв больше, чем гласных\n");
    }
    else
    {
        printf("Гласных и согласных букв равное количество\n");
    }
    return 0;
}