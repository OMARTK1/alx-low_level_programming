#include "3-calc.h"

/**
 * main - entry point.
 * @argc: argument count.
 * @argv: argument vector.
 * Return: 0 on success, 98 on wrong number of arguments,
 *         99 on invalid operator, 100 on division/modulo by 0.
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;
	int (*operator)(int, int);

	if (argc != 4)
	{
		printf("Error\n");

		return (98);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);

	operator = get_op_func(argv[2]);

	if (operator == NULL)
	{
		printf("Error\n");

		return (99);
	}

	if ((*argv[2] == '/' || *argv[2] == '%') && num2 == 0)
	{
		printf("Error\n");

		return (100);
	}

	result = operator(num1, num2);
	printf("%d\n", result);

	return (0);
}
