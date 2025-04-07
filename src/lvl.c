/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:03:53 by rha-le            #+#    #+#             */
/*   Updated: 2025/04/07 22:08:00 by rha-le           ###   ########.fr       */
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

static int	check_charset(char *c)
{
	static unsigned char	check = 0x00;

	if (!ft_strchr(CHARSET, *c) && *c != '\n')
		return (1);
	if (ft_strchr("PE", *c))
	{
		if (*c == 'P' && !(check & 1))
			check |= 1;
		else if (*c == 'E' && !(check & (1 << 1)))
			check |= (1 << 1);
		else
			return (1);
	}
	if (*c == '\n' && *(c + 1) == '\n')
		return (1);
	return (0);
}

static int	get_dimensions(char *s, int *x, int *y)
{
	*x = 0;
	*y = 0;
	if (!s)
		return (1);
	while (*s)
	{
		if (check_charset(s))
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

static void	append_buf(char **s, char *buf)
{
	char	*temp;

	if (*s)
		temp = *s;
	else
		temp = "";
	*s = ft_strjoin(temp, buf);
	if (!temp)
		free(temp);
}

static char	*read_file(t_map *map, int fd)
{
	ssize_t	bread;
	char	*file;
	char	*buf;

	buf = ft_calloc(sizeof(*buf), BYTES_RD);
	if (!buf)
		return (NULL);
	file = NULL;
	while (1)
	{
		bread = read(fd, buf, BYTES_RD);
		if (bread == 0)
			break ;
		if (bread == -1)
			return (free(buf), NULL);
		append_buf(&file, buf);
	}
	free(buf);
	if (get_dimensions(file, &map->w, &map->h))
	{
		print_error("Map Invalid: Inconsistent Dimensions!\n");
		(free(file), free_all(map));
		(close(fd), exit(1));
	}
	return (file);
}

int	create_lvl(char *filename, t_map *map)
{
	int		fd;
	char	*buf;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		print_error("Failed to open map");
		exit(1);
	}
	buf = read_file(map, fd);
	if (!buf)
	{
		print_error("Failed to read map");
		close(fd);
		exit(1);
	}
	map->lvl = ft_split(buf, '\n');
	free(buf);
	close(fd);
	return (0);
}
