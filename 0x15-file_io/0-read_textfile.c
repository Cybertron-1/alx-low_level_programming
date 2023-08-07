#include "main.h"

/**
 * read_textfile - Read a file text and print to stdout
 * @filename: Name of the file
 * @letters: The number of letters it should read and print
 *
 * Return: The actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int _open, _read, _write;
	char *buffer;
	ssize_t num_letters_read = 0;

	if (!filename)
		return (0);

	_open = open(filename, O_RDONLY);
	if (_open == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (!buffer)
	{
		close(_open);
		return (0);
	}

	_read = read(_open, buffer, letters);
	if (_read == -1)
	{
		free(buffer);
		close(_open);
		return (0);
	}

	_write = write(STDOUT_FILENO, buffer, _read);
	if (_write == -1 || _write != _read)
	{
		free(buffer);
		close(_open);
		return (0);
	}

	num_letters_read = _write;

	free(buffer);
	close(_open);

	return (num_letters_read);
}
