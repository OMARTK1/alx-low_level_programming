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
	char str[] = "_putchar\n";
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	return (0);
}
