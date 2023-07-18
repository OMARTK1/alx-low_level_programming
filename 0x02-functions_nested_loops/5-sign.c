#include <stdio.h>
#include "main.h"

/**
 * print_sign - Prints the sign of a number.
 * @n: Number to be checked.
 *
 * Return: 1 and prints '+' if n is greater than zero.
 *         0 and prints '0' if n is zero.
 *        -1 and prints '-' if n is less than zero.
*/

int print_sign(int n)
{
	char plus = '+';
	char minus = '-';
	int zero = 0;

	if (n > 0)
	{
		printf("%c%d\n", plus, n);
		return (1);
	}
	else if (n == 0)
	{
		printf("%d\n", zero);
		return (0);
	}
	else
	{
		printf("%c%d\n", minus, n);
		return (-1);
	}
}
