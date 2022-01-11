/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_key_event.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmilan <gmilan@.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 15:22:00 by gmilan            #+#    #+#             */
/*   Updated: 2022/01/11 17:15:39 by gmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	checker_items(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
			if (map->map[i][j] == 'C')
				return (0);
	}
	return (1);
}

static void	print_count_move(t_map *map)
{
	char	*str;

	map->count_move++;
	str = ft_itoa(map->count_move);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	free(str);
}

static void	change_player_location(t_map *map, int x, int y)
{
	if (x > 0 && y > 0 && x < map->height && y < map->width)
	{
		if (map->map[x][y] == 'E')
		{
			if (checker_items(map))
				exit(0);
		}
		else if (map->map[x][y] != '1')
		{
			if (map->map[x][y] == 'C')
				map->map[x][y] = '0';
			map->map[map->player_x][map->player_y] = '0';
			map->map[x][y] = 'P';
			map->player_y = y;
			map->player_x = x;
			paint_map(&map->mlx, map, &map->img);
			print_count_move(map);
		}
	}
}

void	handler_key_event(int key_code, t_map *map)
{
	if (key_code == KEY_ESC)
	{
		write(1, "You enter the ESC key. Program exit!\n", 37);
		exit(0);
	}
	if (key_code == KEY_W || key_code == KEY_UP)
		change_player_location(map, map->player_x - 1, map->player_y);
	if (key_code == KEY_S || key_code == KEY_DOWN)
		change_player_location(map, map->player_x + 1, map->player_y);
	if (key_code == KEY_A || key_code == KEY_LEFT)
		change_player_location(map, map->player_x, map->player_y - 1);
	if (key_code == KEY_D || key_code == KEY_RIGHT)
		change_player_location(map, map->player_x, map->player_y + 1);
}
