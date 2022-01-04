#include "../includes/so_long.h"

static void	paint_img(t_mlx *mlx, t_img *img, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img->wall, x, y);
	if (c == 'P')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img->player, x, y);
	if (c == 'C')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img->collectable_item,
								x, y);
	if (c == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img->exit, x, y);
}

void	paint_background(t_mlx *mlx, int width, int height)
{
	t_back	b;
	int		i;
	int		j;

	b.img_ptr = mlx_new_image(mlx->mlx_ptr, width, height);
	b.data = (int *)mlx_get_data_addr(b.img_ptr, &b.bpp, &b.size_l, &b.endian);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			b.data[i * width + j] = 0x000000;
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, b.img_ptr, 0, 0);
}


void	paint_map(t_mlx *mlx, t_map *map, t_img *img)
{
	int	i;
	int	j;

	paint_background(mlx, map->width * 72, map->height * 72);
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->map[i][j] == '1')
				paint_img(mlx, img, '1', j * 72, i * 72);
			if (map->map[i][j] == 'P')
				paint_img(mlx, img, 'P', j * 72, i * 72);
			if (map->map[i][j] == 'C')
				paint_img(mlx, img, 'C', j * 72, i * 72);
			if (map->map[i][j] == 'E')
				paint_img(mlx, img, 'E', j * 72, i * 72);
		}
	}
}
