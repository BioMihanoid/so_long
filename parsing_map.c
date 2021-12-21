#include "so_long.h"

static void	map_error(void)
{
	printf("Error! Invalid Map!\n");
	exit(1);
}

static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

static void check_error(int fd, int size1, int size2)
{
	char	*line;
	if ((size1 - size2) == 1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return;
		else
		{
			free(line);
			map_error();
		}
	}
	else
		map_error();
}

static int	check_map(char *filename, t_map *map)
{
	char	*line;
	int		fd;
	int		size;
	int		height;

	fd = open(filename, O_RDONLY);
	if (fd < 0 || ft_strcmp(".ber", &filename[ft_strlen(filename) - 4]))
		map_error();
	size = 0;
	height = 0;
	line = get_next_line(fd);
	while (1)
	{
		if (line == NULL)
			break;
		if (size == 0)
			size = ft_strlen(line);
		if (size != ft_strlen(line))
			check_error(fd, size, ft_strlen(line));
		height++;
		free(line);
		line = get_next_line(fd);
	}
	map->height = height;
	return (size);
}

void	parsing_map(t_map *map, char *filename)
{
	int		i;
	int		j;
	int		fd;
	char	*line;

	map->width = check_map(filename, map);
	fd = open (filename, O_RDONLY);
	if (fd < 0)
		map_error();
	map->map = (char **)malloc(sizeof(char *) * map->height);
	if (map->map == NULL)
		map_error();
	i = -1;
	line = get_next_line(fd);
	while (1)
	{
		if (line == NULL)
			break;
		j = -1;
		map->map[++i] = malloc (map->width + 1);
		while (++j < map->width)
			map->map[i][j] = line[j];
		map->map[i][j] = '\0';
		free(line);
		line = get_next_line(fd);
	}
	valid_map(map);
}

