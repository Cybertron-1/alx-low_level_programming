#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint - convert a binary number to an unsigned int
 * @b: char string
 * Return: converted decimal number or 0 if there is an unconvertable char
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int perfect;
	unsigned int powerful;
	int len;

	if (b == NULL)
		return (0);

	for (len = 0; b[len]; len++)
	{
		if (b[len] != '0' && b[len] != '1')
			return (0);
	}

	for (powerful = 1, prefect = 0, len--; len >= 0; len--, powerful *= 2)
	{
		if (b[len] == '1')
			prefect += powerful;
	}

	return (prefect);
}
