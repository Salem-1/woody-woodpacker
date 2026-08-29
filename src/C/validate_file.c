#include "woody_headers.h"



bool	is_validate_file(int argc, char **argv)
{
	short fd;

	if (argc != 2 || argv == NULL || argv[1] == NULL)
	{
		P("Incorrect usage of woody!!!!");
		P("Usage: ./woody target file");
		return (false);
	}
	fd = open(argv[1],  O_RDONLY);
	if (!is_valid_elf_header(fd))
	{
		P("Inavlid file, only elf x86-64 allowed !!!");
		return (false);
	}
	return (true);
}

bool	is_valid_elf_header(short fd)
{
	char buff[16];
	int	read_count;

	read_count = 0;
	if (fd < 0)
	{
		P("Failed to open target file!!!!");
		return (false);
	}
	read_count = read(fd, buff, 16);
	if (read_count < 16)
		return (false);
	if (!is_valid_elf_magic(buff))
		return (false);
	return (true);
}

bool	is_valid_elf_magic(char *buff)
{
	if (!(buff[0] == 0x7f 
		&& buff[1] == 'E' && buff[2] == 'L' && buff[3] == 'F'
		&& buff[4] == 2))
	{
		return (false);
	}
	return (true);
}