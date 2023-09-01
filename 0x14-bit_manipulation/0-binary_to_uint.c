#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - function that onverts a binary number to an unsigned int
 * @b: its pointer to a string containing a binary number
 *
 * Return: The converted number, or 0 if the input string contains
 *         non-binary characters or is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int convert_Num = 0;
	int i;

	if (b == NULL)
		return (0);

	for (i = 0; b[i] != '\0'; i++)
	{
		char c = b[i];

		if (c != '0' && c != '1')
			return (0);

		convert_Num = convert_Num * 2 + (c - '0');
	}

	return (convert_Num);
}
