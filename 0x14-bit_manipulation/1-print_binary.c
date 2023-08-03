#include "main.h"
#include <stdio.h>

/**
 * print_binary - print binary representation of a number
 * @n:  decimal number to print as binary
 */
void print_binary(unsigned long int n)
{
	unsigned long int tempaddress;
	int bitshifts;

	if (n == 0)
	{
		printf("0");
		return;
	}

	for (tempaddress = n, bitshifts = 0; (tempaddress >>= 1) > 0; bitshifts++)
		;

	for (; bitshifts >= 0; bitshifts--)
	{
		if ((n >> bitshifts) & 1)
			printf("1");
		else
			printf("0");
	}
}
