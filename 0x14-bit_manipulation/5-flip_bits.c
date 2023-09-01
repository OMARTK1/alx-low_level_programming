#include "main.h"

/**
 * flip_bits - function that returns the number of bits you would need
 *		to flip to get from one number to another
 * @n: the first number
 * @m: the second number
 *
 * Return: number of bits to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int differ = n ^ m;
	unsigned int bit_count = 0;

	while (differ > 0)
	{
		bit_count += (differ & 1);
		differ >>= 1;
	}

	return (bit_count);
}
