#include "woody_headers.h"

int main(int argc, char **argv)
{
	bool valid_file;

	valid_file = is_validate_file(argc, argv);
	if (!valid_file)
		return (1);
	return (0);
}