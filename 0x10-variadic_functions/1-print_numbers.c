#include "variadic_functions.h"

/**
 * print_numbers - prints numbers with separator followed by a new line
 * @separator: the string separator to be printed between numbers
 * @n: the number of integers passed to the function
 * @...: the integers to be printed
 *
 * Return: void
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list nums;
	unsigned int index;

	va_start(nums, n);

	for (index = 0; index < n; index++)
	{
		printf("%d", va_arg(nums, int));

		if (index != (n - 1) && separator != NULL)
			printf("%s", separator);
	}

	printf("\n");

	va_end(nums);
}
