#include "main.h"

/**
 * print_abs - Prints the absolute value of an integer.
 * @n: The integer to print the absolute value for.
*/

void print_abs(int n)
{
	if (n < 0)
		putchar('-');
	if (n == 0)
		_putchar('0');
	while (n != 0)
	{
		int digit = n % 10;

		if (digit < 0)
			digit = -digit;
		_putchar('0' + digit);
		n /= 10;
	}
}

/**
 * main - Entry point
 *
 * Return: Always 0
*/

int main(void)
{
	int num = -10;

	print_abs(num);
	_putchar('\n');
	return (0);
}
