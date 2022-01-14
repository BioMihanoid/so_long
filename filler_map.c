/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmilan <gmilan@.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 15:22:00 by gmilan            #+#    #+#             */
/*   Updated: 2022/01/11 17:15:38 by gmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			b.data[i * width + j] = 0x05ccff;
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, b.img_ptr, 0, 0);
}

void	print_wall(t_mlx *mlx, t_map *map, t_img *img)
{
	if (map->x == 0 && map->y == 0)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
								img->wall_up_left, map->y * 72, map->x * 72);
	else if (map->x == 0 && map->y > 0 && map->y < map->width - 2)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
								img->wall_up, map->y * 72, map->x * 72);
	else if (map->x == 0 && map->y == map->width - 2)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
								img->wall_up_right, map->y * 72, map->x * 72);
	else if (map->x > 0 && map->x < map->height - 1 && map->y == 0)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
								img->wall_left, map->y * 72, map->x * 72);
	else if (map->x > 0 && map->x < map->height - 1 && map->y == map->width - 2)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
								img->wall_right, map->y * 72, map->x * 72);
	else if (map->x == map->height - 1 && map->y == 0)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
								img->wall_down_left, map->y * 72, map->x * 72);
	else if (map->x == map->height - 1 && map->y == map->width - 2)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
								img->wall_down_right, map->y * 72, map->x * 72);
	else if (map->x == map->height - 1 && map->y > 0 && map->y < map->width - 1)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
								img->wall_down, map->y * 72, map->x * 72);
	else
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
								img->wall, map->y * 72, map->x * 72);
}

void	paint_map(t_mlx *mlx, t_map *map, t_img *img)
{
	paint_background(mlx, map->width * 72, map->height * 72);
	map->x = -1;
	while (++map->x < map->height)
	{
		map->y = -1;
		while (++map->y < map->width)
		{
			if (map->map[map->x][map->y] == '1')
				print_wall(mlx, map, img);
			if (map->map[map->x][map->y] == 'P')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
					img->player, map->y * 72, map->x * 72);
			if (map->map[map->x][map->y] == 'C')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
					img->collectable_item, map->y * 72, map->x * 72);
			if (map->map[map->x][map->y] == 'E')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
					img->exit, map->y * 72, map->x * 72);
		}
	}
}
