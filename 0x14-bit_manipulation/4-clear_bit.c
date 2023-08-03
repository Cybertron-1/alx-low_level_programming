#include "main.h"
#include <stdio.h>
/**
 * clear_bit - set the value of a bit to 0 at a given index
 * @n: pointer to decimal number to change
 * @index: index position to change
 * Return: 1 if it worked, -1 if error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int index1;
	unsigned int hold_address;

	if (index1 > 64)
		return (-1);
	hold_address = index;
	for (index1 = 1; hold_address > 0; index1 *= 2, hold_address--)
		;

	if ((*n >> index) & 1)
		*n -= i;

	return (1);
}
