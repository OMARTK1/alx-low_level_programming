#include "main.h"

/**
 * print_number - Prints an integer using _putchar
 * @n: The integer to be printed
 */
void print_number(int n)
{
	int divisor = 1;
	int num_digits = 0;
	int temp;

	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	temp = n;

	/* Count the number of digits in the integer */
	while (temp > 0)
	{
		temp /= 10;
		divisor *= 10;
		num_digits++;
	}

	/* Special case for printing 0 */
	if (n == 0)
	{
		_putchar('0');
		return;
	}

	/* Print each digit one by one */
	while (num_digits > 0)
	{
		divisor /= 10;
		_putchar((n / divisor) + '0');
		n %= divisor;
		num_digits--;
	}
}
