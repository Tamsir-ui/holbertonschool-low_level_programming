#include "dog.h"

/**
 *init_dog - initialzes a variable of tupe struct dog
 *@d: pointer to struct dog to initialize
 *@name: the dog's name
 *@age: the dog's name
 *@owner: the dog's owner
 *
 *Return: void
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
if (d == NULL)
return;

d->name = name;
d->age = age;
d->owner = owner;
}
