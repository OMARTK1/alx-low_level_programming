#include "main.h"

/**
 * puts_half - Prints half of a string, followed by a new line.
 *
 * @str: input parameter of the string.
 */

void puts_half(char *str)
{
	int len = 0;
	int start_idx; /*start index*/

	if (len % 2 == 0)
		start_idx = len / 2;
	else
		start_idx = (len + 1) / 2;

	while (str[start_idx] != '\0')
	{
		_putchar(str[start_idx]);
		start_idx++;
	}
	_putchar('\n');
}
