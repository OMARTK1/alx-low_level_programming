#include "main.h"

/**
 * main - Entry point of the program
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
