#include "function_pointers.h"
#include <stdio.h>
/**
 * print_name - prints a name using a function pointer
 * @name: someone's name
 * @f pointer to the funtion that prints
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;
	f(name);
}
