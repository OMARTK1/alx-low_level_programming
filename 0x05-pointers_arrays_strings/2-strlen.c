#include "main.h"

/**
 * _strlen - returns the length of a string.
 *
 * @s : String character.
 *
 * Return: The length of the string (number of characters).
 */

int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}

	return (len);
}
