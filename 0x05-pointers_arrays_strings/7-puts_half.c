#include "main.h"

/**
 * _strlen - Returns the length of a string.
 *
 * @s: inputr of the string.
 *
 * Return: The lemght of the string.
 */

int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * puts_half - Prints half of a string, followed by a new line.
 *
 * @str: input of the string.
 */

void puts_half(char *str)
{
	int len = _strlen(str);
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
