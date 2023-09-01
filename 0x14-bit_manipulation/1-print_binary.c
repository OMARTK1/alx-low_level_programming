#include "main.h"

/**
 * print_binary - it prints the binary representation of a decimal number
 * @n: number to be printed in binary
 */

void print_binary(unsigned long int n)
{
	if (n > 1)
		print_binary(n >> 1);

	putchar((n & 1) + '0');
}
