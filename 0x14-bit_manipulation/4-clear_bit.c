#include "main.h"
#include <stdio.h>
/**
 * clear_bit - set the value of a bit to 0 at a given index
 * @n: pointer to decimal number  about to change
 * @index: index position about to change
 * Return: 1 if it memory bit cleared, -1 if error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int i;
	unsigned int holdmem;

	if (index > 64)
		return (-1);
	holdmem = index;
	for (i = 1; holdmem > 0; i *= 2, holdmem--)
		;

	if ((*n >> index) & 1)
		*n -= i;

	return (1);
}
