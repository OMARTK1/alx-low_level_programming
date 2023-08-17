#include "function_pointers.h"

/**
 * print_name - print a name by using pointer to function
 * @name: string name
 * @f: the pointer to function
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	if (name && f)
		f(name);
}
