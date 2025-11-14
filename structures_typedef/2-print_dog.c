#include <stdio.h>
#include "dog.h"

/**
 * print_dog - prints a struct dog
 * @d: pointer to struct dog to print
 *
 * Description: Prints the name, age and owner of the dog. If d is NULL,
 * the function does nothing. If name or owner is NULL, "(nil)" is printed
 * for that field.
 *
 * Return: void
 */
void print_dog(struct dog *d)
{
char *name;
char *owner;

if (d == NULL)
return;
name = d->name != NULL ? d->name : "(nil)";
owner = d->owner != NULL ? d->owner : "(nil)";

printf("Name: %s\n", name);
printf("Age: %f\n", d->age);
printf("Owner: %s\n", owner);
}
