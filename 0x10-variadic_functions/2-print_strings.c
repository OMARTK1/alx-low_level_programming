#include "variadic_functions.h"

/**
 * print_strings - prints strings with separator followed by a new line
 * @separator: the string separator to be printed between strings
 * @n: the number of strings passed to the function
 * @...: the strings to be printed
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	char *str;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(args, char *);
		if (str == NULL)
			str = "(nil)";

		printf("%s", str);

		if (separator != NULL && i < n - 1)
			printf("%s", separator);
	}

	printf("\n");
	va_end(args);
}
