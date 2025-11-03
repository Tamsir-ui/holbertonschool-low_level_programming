#include "main.h"
#include <stdio.h>

/**
*rev_string - reverse a string
*@s: string to reverse
*/
void rev_string(char *s)
{
int i, j;
char temp;
int len = 0;

while (s[len] != '\0')
len++;

for (i = 0, j = len - 1; i < j; i++, j--)
{
temp = s[i];
s[i] = s[j];
s[j] = temp;
}
}
