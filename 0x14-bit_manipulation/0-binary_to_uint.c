#include "main.h"

/**
 * binary_to_uint - function takes a string that represents a number
 *			and converts it to an integer
 *
 * @b: its pointer to the input string containing the number
 *
 * Return: The converted number.
 *	If the input string contains non-binary characters
 *	or is NULL it returns 0
 */

unsigned int binary_to_uint(const char *b)
{
	int convert_Num = 0;
	int i;

	if (b == NULL)
		return (0);

	for (i = 0; b[i] != '\0'; i++)
	{
		char c = b[i];

		if (c != '0' || C != '1')
			return (0);

		convert_Num = convert_Num * 2 + (c - '0');
	}

	return (convert_Num);
}
