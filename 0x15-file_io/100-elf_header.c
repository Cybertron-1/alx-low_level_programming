#include "main.h"

/**
 * main - displays the contents of an ELF header
 * @argc: argument count
 * @argv: argument vector
 * Description: ./elf_header elf_file
 * Return: 0 on success, otherwise exit with error codes
 */
int main(int argc, char *argv[])
{
	int fd, read_bytes, close_ret;
	Elf64_Ehdr *header;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_file\n", argv[0]);
		exit(98);
	}

	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Memory allocation failed\n");
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		free(header);
		exit(98);
	}

	read_bytes = read(fd, header, sizeof(Elf64_Ehdr));
	if (read_bytes == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		free(header);
		close(fd);
		exit(98);
	}

	elf_validation(header->e_ident);
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);

	close_ret = close(fd);
	if (close_ret == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptor\n");
		exit(98);
	}

	return (0);
}

/* Remaining functions (elf_validation, print_magic, print_class, etc.) remain the same as in the original code. */
