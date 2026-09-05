#ifndef WOODY_HEADERS_H
# define WOODY_HEADERS_H

# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>

# define P(x) perror(((x)))
# define PD(x) printf("%d\n", ((x)))
# define debug_me printf("%s: %d\n", __FILE__, __LINE__)
# define Elf64_Half uint16_t 
# define Elf64_Word uint32_t
# define Elf64_Addr uint64_t 
# define Elf64_Off uint64_t
# define EI_NIDENT 16

typedef struct {
        unsigned char   e_ident[EI_NIDENT];
        Elf64_Half      e_type;
        Elf64_Half      e_machine;
        Elf64_Word      e_version;
        Elf64_Addr      e_entry;
        Elf64_Off       e_phoff;
        Elf64_Off       e_shoff;
        Elf64_Word      e_flags;
        Elf64_Half      e_ehsize;
        Elf64_Half      e_phentsize;
        Elf64_Half      e_phnum;
        Elf64_Half      e_shentsize;
        Elf64_Half      e_shnum;
        Elf64_Half      e_shstrndx;
} Elf64_Ehdr;

typedef struct file_info {
	bool	valid;
	short	fd;
	ssize_t	read_count;
} t_file_info;


t_file_info	validate_file(int argc, char **argv);
bool	is_valid_elf_magic(char *buff);
bool		is_valid_elf_header(short fd);




#endif