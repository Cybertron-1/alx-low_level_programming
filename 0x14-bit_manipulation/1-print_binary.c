#include "main.h"
#include <stdio.h>

/**
 * print_binary - Print the binary representation of a number.
 * @n: Decimal number to print as binary.
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;
	int num_bits = sizeof(unsigned long int) * 8;
	int bit;

	for (bit = num_bits - 1; bit >= 0; bit--)
	{
		if ((n & (mask << bit)) != 0)
			putchar('1');
		else
			putchar('0');
	}
	putchar('\n');
}
