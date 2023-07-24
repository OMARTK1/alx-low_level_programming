#include "main.h"

/**
 * _puts - Prints a string, followed by a new line.
 *
 * @str: The input string to be printed.
 */

void _puts(char *str)
{
	char *ptr = str

	while (*ptr != '\0')
	{
		_putchar(*ptr);
		ptr++;
	}

	_putchar('\n');
}
