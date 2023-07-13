#include <unistd.h>

/**
 * main -Entry point
 *
 * Description: A C program that prints a quote with write function.
 *
 * Return: 1 (Unsuccess)
*/

int main(void)
{
	const char *quote = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";

	write(2, quote, 59);
	return (1);
}
