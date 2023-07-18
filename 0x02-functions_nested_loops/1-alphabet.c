#include "main.h"

/**
 * print_alphabet - Prints the lowercase alphabet a - z
 * by using _putchar function, followed by a new line.
*/

void print_alphabet(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
	{
		_putchar(letter);
	}

	_putchar('\n');
}
