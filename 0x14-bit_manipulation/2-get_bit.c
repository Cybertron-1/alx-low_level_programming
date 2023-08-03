#include "main.h"
#include <stdio.h>
/**
 * get_bit - get the value of a bit at a given index in memory
 * @n: number to check
 * @index: index starting from 0, of the bit we want to get
 * Return: Value of bit at index, or -1 if error retrogress
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int holdbits;

	if (index > 64)
		return (-1);

	holdbits = n >> index;

	return (holdbits & 1);
}
