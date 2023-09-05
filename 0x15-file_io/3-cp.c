#include "main.h"

/**
 * error_exit - function that prints an error message to STDERR
 *		and exit with a code
 * @message: its the error message to be printed
 * @exit_code: its the exit code to be useed
 *
 * Return: void
 */
void error_exit(const char *message, int exit_code)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(exit_code);
}

/**
 * main - function that copies the contents of a file to another file
 * @argc: its the number of arguments
 * @argv: its array of pointers to the arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t re, wr;
	char buff[READ_BUFF_SIZE];

	if (argc != 3)
	{
		error_exit("Usage: cp file_from file_to", 97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		error_exit("Error: Can't read from file", 98);
	}

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_to == -1)
	{
		error_exit("Error: Can't write to file", 99);
	}

	while ((re = read(fd_from, buff, READ_BUFF_SIZE)) > 0)
	{
		wr = write(fd_to, buff, re);
		if (wr == -1)
		{
			error_exit("Error: Can't write to file", 99);
		}
	}

	if (re == -1)
	{
		error_exit("Error: Can't read from file", 98);
	}

	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		error_exit("Error: Can't close fd", 100);
	}

	return (0);
}
