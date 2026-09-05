#include "woody_headers.h"



t_file_info	validate_file(int argc, char **argv)
{
	t_file_info file_info;

	file_info.valid = false;
	file_info.fd = -1;
	if (argc != 2 || argv == NULL || argv[1] == NULL)
	{
		P("Incorrect usage of woody!!!!\nUsage: ./woody target file");
		return (file_info);
	}
	file_info.fd = open(argv[1],  O_RDONLY);
	if (!is_valid_elf_header(file_info.fd))
	{
		P("Inavlid file, only elf x86-64 allowed !!!\n");
		return (file_info);
	}
	file_info.read_count = 16;
	file_info.valid = true;
	return (file_info);
}

bool	is_valid_elf_header(short fd)
{
	char buff[16];
	int	read_count;

	read_count = 0;
	if (fd < 0)
	{
		P("Failed to open target file!!!!\n");
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
		return (false);
	return (true);
}