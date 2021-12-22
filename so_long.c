#include "so_long.h"

void program_exit(void)
{
	printf("Program exit!\n");
	exit(0);
}

void	so_long(char *filename)
{
	t_mlx	mlx;
	t_img	img;
	t_map	map;
	void	*img_ptr;
	int 	x;
	int		y;

	parsing_map(&map, filename);
	mlx.mlx_ptr = mlx_init();
	x = map.width;
	y = map.height;
	mlx.win = mlx_new_window(mlx.mlx_ptr, (x - 1) * 72, y * 72,
							 "so_long");
	map.mlx = mlx;
	init_img(&mlx, &img);
	map.img = img;
	paint_map(&mlx, &map, &img);
	mlx_hook(mlx.win, KEY, 0, (int (*)()) &handler_key_event, &map);
	mlx_hook(mlx.win, KEY_EXIT, 0, (int (*)()) &program_exit, NULL);
	mlx_loop(mlx.mlx_ptr);
	mlx_clear_window(mlx.mlx_ptr, mlx.win);
}


