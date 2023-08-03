#include "main.h"
#include <stdio.h>

/**
 * binary_string_to_uint - Convert a binary string to an unsigned int.
 * @binary_str: Pointer to a char string representing the binary number.
 *
 * Return: The converted decimal number or 0 if there is an unconvertible char.
 */
unsigned int binary_string_to_uint(const char *binary_str)
{
	unsigned int result = 0, exponent = 1;
	int length = 0;

	if (binary_str == NULL)
		return (0);

	while (binary_str[length])
	{
		if (binary_str[length] != '0' && binary_str[length] != '1')
			return (0);
		length++;
	}

	for (length--; length >= 0; length--, exponent *= 2)
	{
		if (binary_str[length] == '1')
			result += exponent;
	}

	return (result);
}
