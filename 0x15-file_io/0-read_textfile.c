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
	char *buff;
	ssize_t re, wr;

	if (filename == NULL)
		return (0);

	buff = malloc(sizeof(char) * letters);
	if (buff == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buff);
		return (0);
	}

	re = read(fd, buff, letters);
	wr = write(STDOUT_FILENO, buff, re);

	if (fd == -1 || re == -1 || wr == -1 || wr != re)
	{
		free(buff);
		close(fd);
		return (0);
	}

	free(buff);
	close(fd);

	return (wr);
}
