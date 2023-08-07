#include "main.h"

/**
 * main - Copies the content of a file to another file
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 if success, 97, 98, 99, or 100 on failure
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, bytes_read, close_status1, close_status2;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	if (file_from < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	file_to = open(argv[2], O_TRUNC | O_CREAT | O_WRONLY, 0664);
	while ((bytes_read = read(file_from, buffer, 1024)) > 0)
	{
		if (file_to < 0 || (write(file_to, buffer, bytes_read) != bytes_read))
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}

	if (bytes_read < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	close_status1 = close(file_from);
	if (close_status1 < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %i\n", file_from);
		exit(100);
	}

	close_status2 = close(file_to);
	if (close_status2 < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %i\n", file_to);
		exit(100);
	}

	return (0);
}
