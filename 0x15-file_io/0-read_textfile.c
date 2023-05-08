#include "main.h"

/**
 * read_textfile - read a file and writes to standard output
 * @filename: name of file
 * @letters: expected number of letters to read
 * Return: the number of bytes read
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t r_num_bytes, w_num_bytes, fd;
	char *buff;

	if (filename == NULL)
	{
		return (0);
	}

	fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		return (0);
	}

	buff = malloc(sizeof(char) * letters);
	if (buff == NULL)
	{
		free(buff);
		return (0);
	}
	r_num_bytes = read(fd, buff, letters);
	if (r_num_bytes == -1)
		return (0);

	w_num_bytes = write(STDOUT_FILENO, buff, r_num_bytes);
	if (w_num_bytes == -1 || r_num_bytes != w_num_bytes)
		return (0);

	close(fd);
	free(buff);

	return (w_num_bytes);
}
