#include "main.h"

/**
 * Print_alphabet - Prints the lowercase alphabet followed by a new line.
 *
 * Description: This program implements the print_alphabet function that
 * prints the alphabet in lowercase using '_putchar' function.
 *
 * Return: 0 (Success)
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
