#include "main.h"

/**
 * create_file - create a file with read/write access for user
 * @filename: name of file to create
 * @text_content: string to write to file
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd, r_num_bytes, idx;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);

	if (text_content)
	{
		for (idx = 0; text_content[idx] != '\0'; idx++)
			;
		r_num_bytes = write(fd, text_content, idx);
		if (r_num_bytes == -1)
			return (-1);
	}
	else
	{
		r_num_bytes = write(fd, "", 0);
		if (r_num_bytes == -1)
			return (-1);
	}
	close(fd);
	return (1);
}

