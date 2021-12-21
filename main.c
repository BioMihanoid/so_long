#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
		so_long(argv[1]);
	else
		printf("Error! Invalid argument number!\n");
	return (0);
}

