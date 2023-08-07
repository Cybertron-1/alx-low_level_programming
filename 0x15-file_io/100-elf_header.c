#include "main.h"

/**
 * main - displays the contents of an ELF header
 * @argc: argument count
 * @argv: argument vector
 *
 * Description: ./elf_header elf_file
 * Return: 0 - success, 98 - error
 */
int main(int argc, char *argv[])
{
    int ret;

    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "Usage: %s elf_file\n", argv[0]);
        return (98);
    }

    ret = print_elf_header_info(argv[1]);
    return (ret);
}

/**
 * print_elf_header_info - prints information from the ELF header
 * @filename: the name of the ELF file
 *
 * Return: 0 - success, 98 - error
 */
int print_elf_header_info(const char *filename)
{
    int fd, read_l;
    Elf64_Ehdr header;
    unsigned char e_ident[EI_NIDENT];

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
        return (98);
    }

    read_l = read(fd, &header, sizeof(Elf64_Ehdr));
    if (read_l == -1)
    {
        dprintf(STDERR_FILENO, "Can't read file %s\n", filename);
        close(fd);
        return (98);
    }

    memcpy(e_ident, header.e_ident, EI_NIDENT);
    close(fd);

    elf_validation(e_ident);
    print_magic(e_ident);
    print_class(e_ident);
    print_data(e_ident);
    print_version(e_ident);
    print_osabi(e_ident);
    printf("  ABI Version:                       %i\n", e_ident[EI_ABIVERSION]);
    
    unsigned int e_type = header.e_type;
    if (e_ident[EI_DATA] == ELFDATA2MSB)
    {
        e_type = (e_type >> 8) & 0xFF;
    }
    print_type(e_type, e_ident);

    unsigned int e_entry = header.e_entry;
    if (e_ident[EI_DATA] == ELFDATA2MSB)
    {
        e_entry = ((e_entry >> 24) & 0xFF) | ((e_entry >> 8) & 0xFF00) | ((e_entry << 8) & 0xFF0000) | ((e_entry << 24) & 0xFF000000);
    }
    print_entry(e_entry, e_ident);

    return (0);
}

/**
 * elf_validation - validates whether a file is in ELF format
 * @e_ident: file description
 */
void elf_validation(unsigned char *e_ident)
{
    if (e_ident[0] != 0x7f || e_ident[1] != 'E' || e_ident[2] != 'L' || e_ident[3] != 'F')
    {
        dprintf(STDERR_FILENO, "Error: File not an ELF\n");
        exit(98);
    }
}

/**
 * print_magic - prints an ELF's magic number
 * @e_ident: file description
 */
void print_magic(unsigned char *e_ident)
{
    int i;

    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++)
    {
        printf("%02x ", e_ident[i]);
    }
    printf("\n");
}

/**
 * print_class - prints an ELF's class
 * @e_ident: pointer to string
 */
void print_class(unsigned char *e_ident)
{
    printf("  Class:                             ");
    switch (e_ident[EI_CLASS])
    {
    case ELFCLASSNONE:
        printf("This class is invalid\n");
        break;
    case ELFCLASS32:
        printf("ELF32\n");
        break;
    case ELFCLASS64:
        printf("ELF64\n");
        break;
    default:
        printf("<unknown: %x>\n", e_ident[EI_CLASS]);
    }
}

/**
 * print_data - prints an ELF's data
 * @e_ident: pointer to string
 */
void print_data(unsigned char *e_ident)
{
    printf("  Data:                              ");
    switch (e_ident[EI_DATA])
    {
    case ELFDATANONE:
        printf("Unknown data format\n");
        break;
    case ELFDATA2LSB:
        printf("2's complement, little endian\n");
        break;
    case ELFDATA2MSB:
        printf("2's complement, big endian\n");
        break;
    default:
        printf("<unknown: %x>\n", e_ident[EI_DATA]);
    }
}

/**
 * print_version - prints an ELF's version
 * @e_ident: string pointer
 */
void print_version(unsigned char *e_ident)
{
    printf("  Version:                           ");
    if (e_ident[EI_VERSION] == EV_CURRENT)
        printf("%i (current)\n", EV_CURRENT);
    else
        printf("%i\n", e_ident[EI_VERSION]);
}

/**
 * print_osabi - prints an ELF's OS/ABI
 * @e_ident: string pointer
 */
void print_osabi(unsigned char *e_ident)
{
    printf("  OS/ABI:                            ");
    switch (e_ident[EI_OSABI])
    {
    case ELFOSABI_SYSV:
        printf("UNIX - System V\n");
        break;
    case ELFOSABI_HPUX:
        printf("UNIX - HP-UX\n");
        break;
    case ELFOSABI_NETBSD:
        printf("UNIX - NetBSD\n");
        break;
    case ELFOSABI_LINUX:
        printf("UNIX - Linux\n");
        break;
    case ELFOSABI_SOLARIS:
        printf("UNIX - Solaris\n");
        break;
    case ELFOSABI_IRIX:
        printf("UNIX - IRIX\n");
        break;
    case ELFOSABI_FREEBSD:
        printf("UNIX - FreeBSD\n");
        break;
    case ELFOSABI_TRU64:
        printf("UNIX - TRU64\n");
        break;
    case ELFOSABI_ARM:
        printf("ARM\n");
        break;
    case ELFOSABI_STANDALONE:
        printf("Standalone App\n");
        break;
    default:
        printf("<unknown: %x>\n", e_ident[EI_OSABI]);
    }
}

/**
 * print_type - prints an ELF's type
 * @e_type: status int
 * @e_ident: pointer to string
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
    if (e_ident[EI_DATA] == ELFDATA2MSB)
    {
        e_type = e_type >> 8;
    }

    printf("  Type:                              ");
    switch (e_type)
    {
    case ET_NONE:
        printf("NONE (Unknown type)\n");
        break;
    case ET_REL:
        printf("REL (Relocatable file)\n");
        break;
    case ET_EXEC:
        printf("EXEC (Executable file)\n");
        break;
    case ET_DYN:
        printf("DYN (Shared object file)\n");
        break;
    case ET_CORE:
        printf("CORE (Core file)\n");
        break;
    default:
        printf("<unknown: %x>\n", e_type);
    }
}

/**
 * print_entry - prints an ELF's entry point address
 * @e_entry: e_entry address
 * @e_ident: pointer to char string
 */
void print_entry(unsigned int e_entry, unsigned char *e_ident)
{
    if (e_ident[EI_DATA] == ELFDATA2MSB)
    {
        e_entry = ((e_entry >> 24) & 0xFF) | ((e_entry >> 8) & 0xFF00) | ((e_entry << 8) & 0xFF0000) | ((e_entry << 24) & 0xFF000000);
    }

    printf("  Entry point address:               %#x\n", e_entry);
}
