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
	img->player = init_img_utils(mlx, "images/player.xpm");
	img->wall = init_img_utils(mlx, "images/wall.xpm");
	img->exit = init_img_utils(mlx, "images/exit.xpm");
	img->collectable_item = init_img_utils(mlx, "images/item.xpm");
}
