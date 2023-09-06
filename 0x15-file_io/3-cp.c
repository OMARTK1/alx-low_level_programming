#include "main.h"

/**
 * main - Entry point, program copies the contents of a file to another
 * @argc: its the number of arguments
 * @argv: its an array of arguments
 *
 * Return: 0 on success, 97, 98, 99, or 100 on error
 */
int main(int argc, char *argv[])
{
	int src_fd, dest_fd, cp;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (97);
	}

	src_fd = open(argv[1], O_RDONLY);
	if (src_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		return (98);
	}

	dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (dest_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
		close(src_fd);
		return (99);
	}

	cp = copy_file(src_fd, dest_fd, buff);
	close(src_fd);
	close(dest_fd);

	if (cp == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
		return (99);
	}

	return (0);
}

/**
 * copy_file - function that copies the contents of one file to another
 * @src_fd: that is the source file descriptor
 * @dest_fd: that is the destination file descriptor
 * @buff: its a buffer for reading and writing data
 *
 * Return: 0 on success, -1 if its fails
 */
int copy_file(int src_fd, int dest_fd, char *buff)
{
	ssize_t re, wr;

	while ((re = read(src_fd, buff, READ_BUFF_SIZE)) > 0)
	{
		wr = write(dest_fd, buff, re);
		if (wr == -1 || wr != re)
			return (-1);
	}

	if (re == -1)
		return (-1);

	return (0);
}
