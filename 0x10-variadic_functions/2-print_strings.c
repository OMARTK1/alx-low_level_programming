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
	va_list strs;
	char *str;
	int i = n;

	if (!n)
	{
		printf("\n");
		return;
	}
	va_start(strs, n);
	while (i--)
		printf("%s%s", (str = va_arg(strs, char *)) ? str : "(nil)",
				i ? (separator ? separator : "") : "\n");
	va_end(strs);
}
