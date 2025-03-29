/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:03:53 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/28 22:03:18 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "map.h"
#include "defs.h"
#include "structs.h"
#include "libft.h"
#include "utils.h"
#include "get_next_line.h"

int	get_dimensions(char *s, int *x, int *y)
{
	*x = 0;
	*y = 0;
	while (*s)
	{
		if (!ft_strchr(CHARSET, *s))
			return (1);
		if (*s == '\n' && *y > 1 && *((s - *x) - 1) != '\n')
			return (1);
		if (*s == '\n')
			++(*y);
		if (*y == 0)
			++(*x);
		++s;
	}
	if (*(s - 1) != '\n' && *((s - *x) - 1) == '\n')
		++(*y);
	else if (*(s - 1) == '\n' && *((s - *x) - 2) != '\n')
		return (1);
	else if (*y < 3)
		return (1);
	return (0);
}

char	*read_map(char *filename, t_map *map, int fd)
{
	ssize_t	bread;
	char *buf;

	buf = malloc(sizeof(*buf) * BYTES_RD);
	bread = 1;
	while (bread != 0)
	{
		bread = read(fd, buf, BYTES_RD);
		if (bread == -1)
		{
			free(buf);
			return (NULL);
		}
		if (bread == BYTES_RD)
		{
			buf =
		}
	}
	/*if (get_dimensions(buf, &map->w, &map->h))*/
	/*{*/
	/*	print_error("Failed to get dimensions\n");*/
	/*	exit(1);*/
	/*}*/
	return (0);
}

int	create_map(char *filename, t_map *map)
{
	int	fd;
	int	i;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		print_error("Failed to open map");
		exit(1);
	}
	map->lvl = ft_split(buf, '\n');
		map->lvl[map->h] = NULL;
	i = 0;
	while (i < map->h)
	{
		map->lvl[i] = get_next_line(fd);
		if (!map->lvl[i])
		{
			free_
		}
	}
	return (0);
}

