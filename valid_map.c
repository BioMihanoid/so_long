#include "so_long.h"

static void	map_error()
{
	printf("Error! Invalid Map!\n");
	exit(1);
}

static void	check_char(t_check *check, char c)
{
	if (c != 'P' && c != 'C' && c != 'E' && c != '1')
		map_error();
	if (c == 'P')
	{
		if (check->player == 1)
			map_error();
		else
			check->player = 1;
	}
	if (c == 'C')
		check->collect = 1;
	if (c == 'E')
		check->exit = 1;
}

void	player_place(t_map *map, int x, int y, char c)
{
	if (c == 'P')
	{
		map->position_player_x = x;
		map->position_player_y = y;
	}
	if (c == '0')
		map->empty_cell++;
}

void	valid_map(t_map *map)
{
	int		i;
	int		j;
	t_check	check;

	i = -1;
	check = (t_check){0, 0, 0};
	map->empty_cell = 0;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width - 1)
		{
			if (i == 0 || j == 0 || i == map->height - 1 || j == map->width
			 * -1)
				if (map->map[i][j] != '1')
					map_error();
			if (map->map[i][j] != '0')
				check_char(&check, map->map[i][j]);
			player_place(map, i, j, map->map[i][j]);
		}
	}
	if (check.exit == 0 || check.collect == 0)
		map_error();
}