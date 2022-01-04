#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_opengl/mlx.h"
# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

# define KEY_EXIT 17
# define KEY 2
# define KEY_ESC 53
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
}	t_mlx;

typedef struct s_img
{
	void	*wall;
	void	*player;
	void	*collectable_item;
	void	*exit;
}	t_img;

typedef struct s_map
{
	struct s_mlx	mlx;
	struct s_img	img;
	int	width;
	int	height;
	int	empty_cell;
	int	position_player_x;
	int position_player_y;
	int count_move;
	char **map;
}	t_map;

typedef struct s_check
{
	int	player;
	int	exit;
	int	collect;
}	t_check;

typedef struct s_back
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_back;

void	so_long(char *filename);
void	parsing_map(t_map *map, char *filename);
void	valid_map(t_map *map);
void	init_img(t_mlx *mlx, t_img *img);
void	paint_map(t_mlx *mlx, t_map *map, t_img *img);
void	handler_key_event(int key_code, t_map *map);
char	*ft_itoa(int n);

#endif
