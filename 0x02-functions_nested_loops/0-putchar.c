#include "main.h"

/**
 * main - Entry point of the program
 *
 * Description: This program prints "_putchar" followed by a new line
 *              using the _putchar function. It demonstrates the usage of
 *		the _putchar function to print characters.
 *
 * Return: 0 (Success)
*/

int main(void)
{
	char str[] = "_putchar";
	int ch;

	for (ch = 0; ch < 8; ch++)
		_putchar(str[ch]);
	_putchar('\n');
	return (0);
}
