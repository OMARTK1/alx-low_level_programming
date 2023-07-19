#include "main.h"

/**
 * largest_number - returns the largest of 3 numbers
 *
 * @a: first integer
 * @b: second integer
 * @c: third integer
 * 
 * Return: largest number
*/

int largest_number(int a, int b, int c)
{
	int largest;

	if (a >= b && a >= c) /* Change ">" to ">=" for all comparisons */
	{
		largest = a;
	}

	else if (b >= a && b >= c) /* Change ">" to ">=" for all comparisons */
	{
		largest = b;
	}

	else
	{
		largest = c;
	}

	return (largest);
}
