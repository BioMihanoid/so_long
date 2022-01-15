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

static void	print_count_move(t_map *map)
{
	char	*str;

	map->count_move++;
	if (map->count_move == INT_MAX)
	{
		write(1, "Your idiot\n", ft_strlen("Your idiot\n"));
		exit(0);
	}
	str = ft_itoa(map->count_move);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	free(str);
}

static void	change_img(t_map *map, int key_code)
{
	if (key_code == KEY_A || key_code == KEY_LEFT)
		map->img.player = map->img.player_mirror;
	if (key_code == KEY_D || key_code == KEY_RIGHT)
		map->img.player = map->img.player_not_mirror;
}

static int check_death_exit(t_map *map, int x, int y)
{
	if (map->map[x][y] == 'A')
	{
		print_count_move(map);
		write(1, "Your death!\n", 12);
		exit(0);
	}
	else if (map->map[x][y] == 'E')
	{
		if (map->count_collectable == 0)
		{
			print_count_move(map);
			write(1, "Your win!\n", 10);
			exit(0);
		}
		return (0);
	}
	return (1);
}

static void	change_player_location(t_map *map, int x, int y, int key_code)
{
	if (x > 0 && y > 0 && x < map->height && y < map->width)
	{
		change_img(map, key_code);
		if (check_death_exit(map, x, y) && map->map[x][y] != '1')
		{
			change_img(map, key_code);
			if (map->map[x][y] == 'C')
			{
				map->map[x][y] = '0';
				map->count_collectable--;
				if (map->count_collectable == 0)
					map->img.exit = map->img.exit_open;
			}
			map->map[map->player_x][map->player_y] = '0';
			map->map[x][y] = 'P';
			map->player_y = y;
			map->player_x = x;
			print_count_move(map);
			paint_map(&map->mlx, map, &map->img, &map->move);
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
		change_player_location(map, map->player_x - 1, map->player_y, key_code);
	if (key_code == KEY_S || key_code == KEY_DOWN)
		change_player_location(map, map->player_x + 1, map->player_y, key_code);
	if (key_code == KEY_A || key_code == KEY_LEFT)
		change_player_location(map, map->player_x, map->player_y - 1, key_code);
	if (key_code == KEY_D || key_code == KEY_RIGHT)
		change_player_location(map, map->player_x, map->player_y + 1, key_code);
}
