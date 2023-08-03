#include "main.h"

/**
 * get_endianness - check endianness
 * Return: 0 if big endian, or 1 if little endian
 */
int get_endianness(void)
{
	int num_to_check_endianness;

	num_to_check_endianness = 1;

	if (*(char *)&num_to_check_endianness == 1)
		return (1);
	else
		return (0);
}
