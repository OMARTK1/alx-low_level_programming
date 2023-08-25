#include <stdio.h>

/**
 * print_message - it prints a message before main is executed
 *
 * Return: void
 */
void print_message(void) __attribute__((constructor));

void print_message(void)
{
	printf("You're beat! and yet, you must allow,\n"
			"I bore my house upon my back!\n");
}
