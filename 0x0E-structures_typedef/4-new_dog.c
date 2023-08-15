#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * new_dog - Creates a new dog struct
 * @name: dog's name
 * @age: dog's age
 * @owner: the owner's name of the dog
 *
 * Return: Pointer to the newly created dog structure.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog = malloc(sizeof(dog_t));

	if (new_dog == NULL)
		return (NULL);

	new_dog->name = copy_str(name);
	if (new_dog->name == NULL)
	{
		free(new_dog);
		return (NULL);
	}

	new_dog->age = age;

	new_dog->owner = copy_str(owner);
	if (new_dog->owner == NULL)
	{
		free(new_dog->name);
		free(new_dog);
		return (NULL);
	}

	return (new_dog);
}

/**
 * copy_str - Creates a copy of a string
 * @str: Pointer to the string to copy
 *
 * Return: Pointer to the newly allocated copied string
 */
char *copy_str(char *str)
{
	char *copy;
	unsigned int length = 0;

	while (str[length])
		length++;

	copy = malloc(length + 1);
	if (copy == NULL)
		return (NULL);

	for (unsigned int i = 0; i <= length; i++)
		copy[i] = str[i];

	return (copy);
}
