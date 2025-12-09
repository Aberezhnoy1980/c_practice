#include <stdio.h>
#include <string.h>

int main()
{
    char n[33];
    int vowels = 0;
    int consonants = 0;

    printf("Enter string -> ");
    if (fgets(n, sizeof(n), stdin) == NULL)
    {
        printf("Input error.\n");
        return 1;
    }

    // Remove newline character
    size_t len = strlen(n);
    if (len > 0 && n[len - 1] == '\n')
    {
        n[len - 1] = '\0';
    }

    for (size_t i = 0; n[i] != '\0'; i++)
    {
        char d = n[i];

        // Check for lowercase English letters
        if (d >= 'a' && d <= 'z')
        {
            // Check if vowel
            if (d == 'a' || d == 'e' || d == 'i' || d == 'o' || d == 'u' || d == 'y')
            {
                vowels++;
            }
            else
            {
                consonants++;
            }
        }
        // Ignore everything that's not a lowercase English letter
    }

    if (vowels > consonants)
    {
        printf("Vowels > consonants\n");
    }
    else if (vowels < consonants)
    {
        printf("Consonants > vowels\n");
    }
    else
    {
        printf("Vowels = consonants\n");
    }

    printf("%d, %d", vowels, consonants);

    return 0;
}