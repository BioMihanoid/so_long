//
// Created by Gormon Milan on 12/21/21.
//

#ifndef SO_LONG_SO_LONG_H
# define SO_LONG_SO_LONG_H

# include "mlx_opengl/mlx.h"
# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
}	t_mlx;

typedef struct s_img
{
	void	*wall;
	void	*player;
	void	*background;
	void	*collectable_item;
	void	*exit;
}	t_img;

typedef struct s_map
{
	int	width;
	int	height;
	int	empty_cell;
	int	position_player_x;
	int position_player_y;
	char **map;
}	t_map;

typedef struct s_check
{
	int	player;
	int	exit;
	int	collect;
}	t_check;

void	so_long(char *filename);
void	parsing_map(t_map *map, char *filename);
void	valid_map(t_map *map);
void	init_img(t_mlx *mlx, t_img *img);

#endif //SO_LONG_SO_LONG_H
