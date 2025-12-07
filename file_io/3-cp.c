#include "main.h"

/**
 * error_exit - prints error message and exits
 * @code: exit code
 * @message: error message
 * @file: file name
 */
void error_exit(int code, const char *message, const char *file)
{
	int i = 0;

	while (message[i])
		i++;
	write(STDERR_FILENO, message, i);

	i = 0;
	while (file[i])
		i++;
	write(STDERR_FILENO, file, i);
	write(STDERR_FILENO, "\n", 1);

	exit(code);
}

