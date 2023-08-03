#include "main.h"

/**
 * _atoi - converts chars to integer
 *
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
 *
 * @str: string input
 *
 * Return: string length
 */
unsigned int _strlen(const char *str)
{
    unsigned int len = 0;

    while (str[len] != '\0')
        len++;

    return (len);
}

/**
 * binary_to_uint - converts a binary number to an unsigned int
 *
 * @b: string that contains 0 and 1 characters
 *
 * Return: the number converted or 0
 *         if @b contains a character
 *         that is not 0 or 1 or when
 *         @b is null
 */
unsigned int binary_to_uint(const char *b)
{
    int index;
    unsigned int result = 0, base = 1, number = 0;

    /* If b is NULL, return 0 */
    if (b == NULL)
        return (0);

#ifdef DEBUG /* Print debug statement */
    printf("String is %s, and length is %u.\n", b, _strlen(b));
#endif

    /* Iterate through the string */
    for (index = _strlen(b) - 1; index >= 0; index--)
    {
        number = _atoi(b[index]); /* Convert char to number */

#ifdef DEBUG /* Print debug statements */
        printf("Number is %u, index is %i and base is %u.\n\n", number, index, base);
#endif

        /* If the number is not 0 or 1, return 0 */
        if (number != 0 && number != 1)
            return (0);

        result += number * base; /* Enable debug to see it in action */
        base *= 2;

#ifdef DEBUG /* Print debug statements */
        printf("Result is %u.\n", result);
#endif
    }

    return (result);
}
