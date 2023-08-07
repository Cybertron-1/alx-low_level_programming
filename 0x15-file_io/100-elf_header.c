#include "main.h"

/**
 * Reads the ELF header from the specified file and prints its contents.
 */
int main(int argc, char *argv[])
{
    int fd, read_l;
    Elf64_Ehdr header;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s elf_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    read_l = read(fd, &header, sizeof(Elf64_Ehdr));
    if (read_l != sizeof(Elf64_Ehdr))
    {
        fprintf(stderr, "Error: Can't read file %s\n", argv[1]);
        close(fd);
        exit(EXIT_FAILURE);
    }

    close(fd);

    elf_validation(header.e_ident);
    print_magic(header.e_ident);
    print_class(header.e_ident);
    print_data(header.e_ident);
    print_version(header.e_ident);
    print_osabi(header.e_ident);
    printf("  ABI Version:                       ");
    printf("%i\n", header.e_ident[EI_ABIVERSION]);
    print_type(header.e_type, header.e_ident);
    print_entry(header.e_entry, header.e_ident);

    return 0;
}

/**
 * Validates whether a file is in ELF format.
 */
void elf_validation(unsigned char *e_ident)
{
    if (e_ident[0] != 0x7f || e_ident[1] != 'E' || e_ident[2] != 'L' || e_ident[3] != 'F')
    {
        fprintf(stderr, "Error: File not an ELF\n");
        exit(EXIT_FAILURE);
    }
}

/**
 * Prints an ELF's magic number.
 */
void print_magic(unsigned char *e_ident)
{
    int i;

    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT - 1; i++)
    {
        printf("%02x ", e_ident[i]);
    }
    printf("%02x\n", e_ident[i]);
}

/**
 * Prints an ELF's class.
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
 * Prints an ELF's data.
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
 * Prints an ELF's version.
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
 * Prints an ELF's OS/ABI.
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
 * Prints an ELF's type.
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
    if (e_ident[EI_DATA] == ELFDATA2MSB)
        e_type = e_type >> 8;

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
 * Prints an ELF's entry point address.
 */
void print_entry(unsigned int e_entry, unsigned char *e_ident)
{
    if (e_ident[EI_DATA] == ELFDATA2MSB)
        e_entry = lit_to_big_endian(e_entry);

    printf("  Entry point address:               ");
    printf("%#x\n", (unsigned int)e_entry);
}

/**
 * Converts a value from little endian to big endian.
 */
unsigned int lit_to_big_endian(unsigned int x)
{
    return (((x >> 24) & 0x000000ff) |
            ((x >> 8) & 0x0000ff00) |
            ((x << 8) & 0x00ff0000) |
            ((x << 24) & 0xff000000));
}
