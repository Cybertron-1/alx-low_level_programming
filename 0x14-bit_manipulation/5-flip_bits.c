#include "main.h"

/**
 * flip_bits - flip bits to convert one number to another number
 * @n: first number
 * @m: second number to convert to
 * Return: number of bits that were needed to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int different = n ^ m;
	unsigned int count = 0;

	while (different)
	{
		count++;
		different &= (different - 1);
	}

	return (count);
}
