#include "main.h"
#include <limits.h>

/**
 * _atoi - Converts a string to an integer.
 *
 * @s: Pointer to the string to be converted.
 *
 * Return: The converted integer.
 */
int _atoi(char *s)
{
	int sign = 1;
	int result = 0;
	int i = 0;

	/*Skip leading white spaces*/
	while (s[i] == ' ')
		i++;

	/*Check for sign*/
	if (s[i] == '-' || s[i] == '+')
	{
		sign = (s[i] == '-') ? -1 : 1;
		i++;
	}

	/*Convert the string to integer*/
	while (s[i] >= '0' && s[i] <= '9')
	{
		/*Check for integer overflow*/
		if (result > INT_MAX / 10 ||
			(result == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10))
		{
			return ((sign == 1) ? INT_MAX : INT_MIN);
		}

		result = result * 10 + (s[i] - '0');
		i++;
	}

	return (result * sign);
}
