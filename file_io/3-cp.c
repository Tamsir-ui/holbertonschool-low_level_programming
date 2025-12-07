#include "main.h"


/**
 * print_error - prints an error message to STDERR and exits
 * @msg: error message
 * @arg: argument to print
 * @code: exit code
 *
 */
void print_error(const char *msg, const char *arg, int code)
{
	int i = 0;

	while (msg[i])
		i++;
	write(STDERR_FILENO, msg, i);

	if (arg)
	{
		i = 0;
		while (arg[i])
			i++;
		write(STDERR_FILENO, arg, i);
	}

	write(STDERR_FILENO, "\n", 1);

	exit(code);
}

/**
 * print_fd_error - prints fd close error
 * @fd: file descriptor
 */
void print_fd_error(int fd)
{
	char buf[20];
	int i = 0;

	if (fd == 0)
		buf[i++] = '0';
	else
	{
		int n = fd, tmp[10], j = 0;

		while (n > 0)
		{
			tmp[j++] = n % 10;
			n /= 10;
		}
		while (j--)
			buf[i++] = tmp[j] + '0';
	}
	buf[i++] = '\n';

	write(STDERR_FILENO, "Error: Can't close fd ", 22);
	write(STDERR_FILENO, buf, i);
	exit(100);
}

/**
 * main - copies content of a file to another
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t r, w;
	char buffer[1024];

	if (argc != 3)
		print_error("Usage: cp file_from file_to", NULL, 97);

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		print_error("Error: Can't read from file ", argv[1], 98);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		print_error("Error: Can't write to ", argv[2], 99);

	while ((r = read(fd_from, buffer, 1024)) > 0)
	{
		w = write(fd_to, buffer, r);
		if (w == -1 || w != r)
			print_error("Error: Can't write to ", argv[2], 99);
	}

	if (r == -1)
		print_error("Error: Can't read from file ", argv[1], 98);

	if (close(fd_from) == -1)
		print_fd_error(fd_from);

	if (close(fd_to) == -1)
		print_fd_error(fd_to);

	return (0);
}
