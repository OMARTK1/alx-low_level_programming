#include <stdio.h>
#include <math.h>

/**
 * is_prime - Checks if a number is prime.
 * @num: The number to check.
 * Return: 1 if prime, 0 otherwise.
 */
int is_prime(unsigned long num)
{
	unsigned long i;

	if (num <= 1)
		return (0);

	if (num <= 3)
		return (1);

	if (num % 2 == 0 || num % 3 == 0)
		return (0);

	for (i = 5; i * i <= num; i += 6)
	{
		if (num % i == 0 || num % (i + 2) == 0)
			return (0);
	}

	return (1);
}

/**
 * largest_prime_factor - Finds the largest prime factor of a number.
 * @num: The number to factorize.
 * Return: The largest prime factor.
 */
unsigned long largest_prime_factor(unsigned long num)
{
	unsigned long largest_prime = 0;
	unsigned long i;

	while (num % 2 == 0)
	{
		largest_prime = 2;
		num /= 2;
	}

	for (i = 3; i <= sqrt(num); i += 2)
	{
		while (num % i == 0)
		{
			largest_prime = i;
			num /= i;
		}
	}

	if (num > 2)
		largest_prime = num;

	return (largest_prime);
}

/**
 * main - Entry point of the program.
 * Return: Always 0 (Success).
 */
int main(void)
{
	unsigned long number_to_factorize = 612852475143;
	unsigned long result = largest_prime_factor(number_to_factorize);

	printf("%lu\n", result);

	return (0);
}
