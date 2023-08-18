#include "variadic_function.h"

/**
 * print_strings - prints strings with separator followed by a new line
 * @separator: the string separator to be printed between strings
 * @n: the number of strings passed to the function
 * @...: the strings to be printed
 *
 * Return: void
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	int i = n;
	char *str;
	va_list ap;

	if (!n)
	{
		printf("\n");
		return;
	}
	va_start(ap, n);
	while (i--)
		printf("%s%s", (str = va_arg(ap, char *)) ? str : "(nil)",
				i ? (separator ? separator : "") : "\n");
	va_end(ap);
}
