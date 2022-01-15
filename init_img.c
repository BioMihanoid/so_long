/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmilan <gmilan@.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 15:22:00 by gmilan            #+#    #+#             */
/*   Updated: 2022/01/11 17:15:39 by gmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*init_img_utils(t_mlx *mlx, char *filename)
{
	void	*result;
	int		wight;
	int		height;

	wight = 0;
	height = 0;
	result = mlx_xpm_file_to_image(mlx->mlx_ptr, filename, &wight, &height);
	if (height == 0 || wight == 0)
	{
		perror("Image error");
		exit(1);
	}
	return (result);
}

void	init_img(t_mlx *mlx, t_img *img)
{
	img->player = init_img_utils(mlx, "images/player1.xpm");
	img->wall = init_img_utils(mlx, "images/wall2.xpm");
	img->exit_not_open = init_img_utils(mlx, "images/door1.xpm");
	img->exit_open = init_img_utils(mlx, "images/door2.xpm");
	img->collectable_item = init_img_utils(mlx, "images/item.xpm");
	img->exit = img->exit_not_open;
	img->wall_up = init_img_utils(mlx, "images/wall_up.xpm");
	img->wall_down = init_img_utils(mlx, "images/wall_down.xpm");
	img->wall_right = init_img_utils(mlx, "images/wall_right.xpm");
	img->wall_left = init_img_utils(mlx, "images/wall_left.xpm");
	img->wall_up_left = init_img_utils(mlx, "images/wall_left_up.xpm");
	img->wall_down_left = init_img_utils(mlx, "images/wall_left_down.xpm");
	img->wall_up_right = init_img_utils(mlx, "images/wall_right_up.xpm");
	img->wall_down_right = init_img_utils(mlx, "images/wall_right_down.xpm");
	img->player_mirror = init_img_utils(mlx, "images/player_mirror.xpm");
	img->player_not_mirror = img->player;
	img->bomb = init_img_utils(mlx, "images/bomb.xpm");
}
