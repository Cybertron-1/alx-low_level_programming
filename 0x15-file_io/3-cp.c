#include "main.h"

/**
 * main - copies the content of a file to another file
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 if success
 */
int main(int argc, char *argv[])
{
	int file1, file2, read_bytes, c1, c2;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	file1 = open(argv[1], O_RDONLY);
	if (file1 < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	file2 = open(argv[2], O_TRUNC | O_CREAT | O_WRONLY, 0664);
	while ((read_bytes = read(file1, buffer, 1024)) > 0)
	{
		if (file2 < 0 || (write(file2, buffer, read_bytes) != read_bytes))
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}

	if (read_bytes < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	c1 = close(file1);
	if (c1 < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %i\n", file1);
		exit(100);
	}

	c2 = close(file2);
	if (c2 < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %i\n", file2);
		exit(100);
	}

	return (0);
}
