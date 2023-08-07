#include "main.h"
/**
 * main - copies the content of a file to another file executable
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 if program was able to copy
 */

int main(int argc, char *argv[])
{
	int file1;
	int file2;
	int _readfile;
	int datahold1; 
	int datahold2;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);
	}
	file1 = open(argv[1], O_RDONLY);
	if (file1 < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	file2 = open(argv[2], O_TRUNC | O_CREAT | O_WRONLY, 0664);
	while ((_readfile = read(file1, buffer, 1024)) > 0)
	{
		if (file2 < 0 || (write(file2, buffer, _readfile) != _readfile))
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);
		}
	}
	if (_readfile < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	datahold1 = close(file1);
	if (datahold1 < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %i\n", file1), exit(100);
	}
	datahold2 = close(file2);
	if (datahold2 < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %i\n", file2), exit(100);
	}
	return (0);
}
