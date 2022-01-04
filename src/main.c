#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
		so_long(argv[1]);
	else
		write(1, "Error! Invalid argument number!\n", 32);
	return (0);
}

