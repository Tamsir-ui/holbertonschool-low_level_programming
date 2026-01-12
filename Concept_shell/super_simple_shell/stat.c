#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

/**
 * main - looks for files in PATH
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0
 */
int main(int ac, char **av)
{
	char *path, *path_copy, *dir;
	char fullpath[1024];
	struct stat st;
	int i;

	if (ac < 2)
	{
		printf("Usage: %s filename ...\n", av[0]);
		return (1);
	}

	path = getenv("PATH");
	if (!path)
		return (1);

	path_copy = strdup(path);

	for (i = 1; i < ac; i++)
	{
		dir = strtok(path_copy, ":");
		while (dir)
		{
			snprintf(fullpath, sizeof(fullpath), "%s/%s", dir, av[i]);
			if (stat(fullpath, &st) == 0)
			{
				printf("%s\n", fullpath);
				break;
			}
			dir = strtok(NULL, ":");
		}
		strcpy(path_copy, path);
	}

	free(path_copy);
	return (0);
}
