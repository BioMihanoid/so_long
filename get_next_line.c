/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmilan <gmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:31:36 by gmilan            #+#    #+#             */
/*   Updated: 2021/10/14 19:26:31 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_static_str(int fd, char *sstr)
{
	char	*buff;
	int		read_check;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	read_check = -1;
	while (!ft_check_endl(sstr) && read_check)
	{
		read_check = read(fd, buff, BUFFER_SIZE);
		if (read_check == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[read_check] = '\0';
		sstr = ft_strjoin(sstr, buff);
	}
	free(buff);
	return (sstr);
}

char	*get_next_line(int fd)
{
	static char	*sstr;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	sstr = ft_read_static_str(fd, sstr);
	if (!sstr)
		return (NULL);
	line = ft_get_line(sstr);
	if (!ft_strlen(line))
	{
		free(line);
		if (sstr)
		{
			free(sstr);
			sstr = NULL;
		}
		return (NULL);
	}
	sstr = ft_new_static_str(sstr);
	return (line);
}
