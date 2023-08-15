#ifndef DOG_H
#define DOG_H

/**
 * struct dog - the dog struct
 * @name: dog's name
 * @age: dog's age
 * @owner: name of dog's owner
 *
 * Description: Define a new struct for Poppy dog
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);

#endif