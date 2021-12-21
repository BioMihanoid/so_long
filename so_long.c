#include "so_long.h"

void	so_long(char *filename)
{
	t_mlx	mlx;
	t_img	img;
	t_map	map;
	int 	x;
	int		y;

	parsing_map(&map, filename);
	mlx.mlx_ptr = mlx_init();
	x = map.width;
	y = map.height;
	mlx.win = mlx_new_window(mlx.mlx_ptr, x * 72, y * 72, "so_long");
	init_img(&mlx, &img);
	mlx_loop(mlx.mlx_ptr);
}


