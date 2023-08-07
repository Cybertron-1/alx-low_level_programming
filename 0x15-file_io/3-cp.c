#include "main.h"

/**
 * main - copies the content of a file to another file
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 if success, otherwise exit with error codes
 */

int main(int argc, char *argv[])
{
	int _file1, _file2, _read, c1, c2;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	/* Open the source file for reading */
	_file1 = open(argv[1], O_RDONLY);
	if (_file1 < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	/* Open the destination file for writing, creating if it doesn't exist */
	_file2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (_file2 < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(_file1);
		exit(99);
	}

	/* Read and write the content from source to destination */
	while ((_read = read(_file1, buffer, sizeof(buffer))) > 0)
	{
		if (write(_file2, buffer, _read) != _read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(_file1);
			close(_file2);
			exit(99);
		}
	}

	/* Error handling for read operation */
	if (_read < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		close(_file1);
		close(_file2);
		exit(98);
	}

	/* Close both file descriptors */
	c1 = close(_file1);
	if (c1 < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", _file1);
		exit(100);
	}

	c2 = close(_file2);
	if (c2 < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", _file2);
		exit(100);
	}

	return (0);
}
