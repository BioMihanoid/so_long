#include "so_long.h"

static void	*init_img_utils(t_mlx *mlx, char *filename)
{
	void	*result;
	int 	wight;
	int		height;

	wight = 0;
	height = 0;
	result = mlx_xpm_file_to_image(mlx->mlx_ptr, filename, &wight, &height);
	if (result == NULL)
		printf("NULL");
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

