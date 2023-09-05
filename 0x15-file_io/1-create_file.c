#include "main.h"
/**
 * create_file - function that creates a file
 *		with specific permissions and content
 * @filename: its pointer to the name of the file to create
 * @text_content: its the text content to write to the file (can be NULL)
 *
 * Return: 1 on success, -1 if its fails
 */
int create_file(const char *filename, char *text_content)
{
	int fd, wr;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
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
