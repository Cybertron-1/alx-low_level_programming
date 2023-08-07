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
	int src_fd, dest_fd, bytes_read, close_status1, close_status2;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (97);
	}

	src_fd = open(argv[1], O_RDONLY);
	if (src_fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		return (98);
	}

	dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (dest_fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(src_fd);
		return (99);
	}

	while ((bytes_read = read(src_fd, buffer, 1024)) > 0)
	{
		if (write(dest_fd, buffer, bytes_read) != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(src_fd);
			close(dest_fd);
			return (99);
		}
	}

	if (bytes_read < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		close(src_fd);
		close(dest_fd);
		return (98);
	}

	close_status1 = close(src_fd);
	close_status2 = close(dest_fd);

	if (close_status1 < 0 || close_status2 < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptors\n");
		return (100);
	}

	return (0);
}
