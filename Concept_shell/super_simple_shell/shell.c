#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - super simple shell
 *
 * Return: 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	pid_t pid;

	while (1)
	{
		printf("#cisfun$ ");
		read = getline(&line, &len, stdin);

		if (read == -1) /* EOF (Ctrl+D) */
		{
			printf("\n");
			break;
		}

		/* remove newline */
		line[read - 1] = '\0';

		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			continue;
		}

		if (pid == 0) /* child */
		{
			char *argv[] = {line, NULL};

			if (execve(line, argv, NULL) == -1)
			{
				perror("execve");
				exit(1);
			}
		}
		else /* parent */
		{
			wait(NULL);
		}
	}

	free(line);
	return (0);
}
