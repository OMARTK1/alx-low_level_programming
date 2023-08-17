#include "variadic_functions.h"

/**
 * sum_them_all - returns the sum of all variable arguments
 * @n: the number of paramters
 * @...: variable integers to calculate the sum of them
 *
 * Return: If n == 0 - 0.
 *         Otherwise - the sum of all parameters
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list ap;
	unsigned int i, sum = 0;

	va_start(ap, n);

	for (i = 0; i < n; i++)
		sum += va_arg(ap, int);

	va_end(ap);

	return (sum);
}
