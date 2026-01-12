#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - executes ls -l /tmp in 5 child processes
 *
 * Return: 0
 */
int main(void)
{
	pid_t pid;
	int status;
	int i;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	for (i = 0; i < 5; i++)
	{
		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			return (1);
		}

		if (pid == 0) /* Child process */
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("execve");
				exit(1);
			}
		}
		else /* Parent process */
		{
			wait(&status);
		}
	}

	return (0);
}
