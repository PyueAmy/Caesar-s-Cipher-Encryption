#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

bool only_digits(const char *s);
char rotate(char c, int n);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);
    char plaintext[100];

    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // Rotate the character
        printf("%c", rotate(plaintext[i], key));
    }
    printf("\n");
    return 0;
}

bool only_digits(const char *s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int n)
{
    char base = 0;
    if (isalpha(c))
    {
        if (isupper(c))
        {
            base = 'A';
        }
        else if (islower(c))
        {
            base = 'a';
        }
        return (c - base + n) % 26 + base;
    }
    else
    {
        return c; // Return unchanged if not a letter
    }
}
