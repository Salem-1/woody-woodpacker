#include "woody_headers.h"

int main(int argc, char **argv)
{
	t_file_info file_info;

	file_info = validate_file(argc, argv);
	if (!file_info.valid)
		return (1);
	return (0);
}