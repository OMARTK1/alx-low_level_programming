#include "main.h"

/**
 * read_textfile - function that reads a text file
 *			and prints it to the POSIX standard output
 * @filename: its pointer to name of the file to read
 * @letters: the number of letters it should read and print
 *
 * Return: Number of letters it could read and print, or 0 if it fails
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char buff[READ_BUFF_SIZE];
	ssize_t re, wr;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);

	re = read(fd, buff, letters);
	if (re == -1)
	{
		close(fd);
		return (-1);
	}

	wr = write(STDOUT_FILENO, buff, re);
	if (wr == -1 || wr != re)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (wr);
}
