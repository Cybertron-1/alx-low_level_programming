#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: string that contains 0 and 1 characters
 *
 * Return: the number converted or 0 if @b contains a character that is not 0 or 1,
 *         or when @b is null
 */
unsigned int binary_to_uint(const char *b)
{
    if (b == NULL)
        return (0);

    unsigned int result = 0;

    while (*b)
    {
        if (*b != '0' && *b != '1')
            return (0);

        result = (result * 2) + (*b - '0');
        b++;
    }

    return (result);
}

/**
 * _atoi - converts a char to an unsigned int
 * @c: char to convert
 *
 * Return: converted integer
 */
unsigned int _atoi(char c)
{
    return ((unsigned int)(c - '0'));
}

/**
 * _strlen - gets the length of a string
 * @str: string input
 *
 * Return: string length
 */
unsigned int _strlen(const char *str)
{
    unsigned int length = 0;

    while (str[length] != '\0')
        length++;

    return (length);
}
