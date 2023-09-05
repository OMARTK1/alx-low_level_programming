#include "main.h"

/**
 * append_text_to_file - function that appends text to the end of a file
 * @filename: its pointer to the name of the file to append to
 * @text_content: its the text to append
 *
 * Return: 1 on success, -1 if it fails
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, wr;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		wr = write(fd, text_content, strlen(text_content));
		if (wr == -1)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
