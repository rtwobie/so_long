/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:55:11 by rha-le            #+#    #+#             */
/*   Updated: 2025/04/09 16:49:04 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "libft.h"
#include "structs.h"
#include "utils.h"
#include <stdlib.h>

static void	flood_fill(t_map *map, char **lvl, int x, int y)
{
	if (x > map->w || x < 0 || y > map->h || y < 0)
		return ;
	lvl[y][x] = 'F';
	if (x + 1 < map->w && ft_strchr(TARGET, lvl[y][x + 1]))
		flood_fill(map, lvl, x + 1, y);
	if (y + 1 < map->h && ft_strchr(TARGET, lvl[y + 1][x]))
		flood_fill(map, lvl, x, y + 1);
	if (x - 1 > 0 && ft_strchr(TARGET, lvl[y][x - 1]))
		flood_fill(map, lvl, x - 1, y);
	if (y - 1 > 0 && ft_strchr(TARGET, lvl[y - 1][x]))
		flood_fill(map, lvl, x, y - 1);
}

static int	check_border(char **lvl, int w, int h)
{
	int	i;

	i = -1;
	while (++i < w)
		if (lvl[0][i] == 'F')
			return (-1);
	while (--i)
		if (lvl[h - 1][i] == 'F')
			return (-1);
	while (--h)
		if (lvl[h][0] == 'F' || lvl[h][w - 1] == 'F')
			return (-1);
	return (0);
}

static int	is_obj_reachable(t_map *map, char **filled_lvl)
{
	int	i;

	if (filled_lvl[map->exit.y][map->exit.x] != 'F')
		return (0);
	i = 0;
	while (i < map->coin_count)
	{
		if (filled_lvl[map->coin[i].y][map->coin[i].x] != 'F')
			return (0);
		++i;
	}
	return (1);
}

char	**copy_lvl(char **lvl, int h)
{
	int		i;
	char	**copy;

	copy = malloc(sizeof(char *) * (size_t)(h + 1));
	if (!copy)
		return (0);
	i = -1;
	while (++i < h)
	{
		copy[i] = ft_strdup(lvl[i]);
		if (!copy[i])
		{
			free_lvl(copy);
			return (0);
		}
	}
	copy[h] = NULL;
	return (copy);
}

int	is_mapvalid(t_map *map)
{
	char	**temp;

	temp = copy_lvl(map->lvl, map->h);
	if (!temp)
		return (0);
	flood_fill(map, temp, map->player.x, map->player.y);
	if (check_border(temp, map->w, map->h) == -1)
	{
		free_lvl(temp);
		return (0);
	}
	if (!is_obj_reachable(map, temp))
	{
		free_lvl(temp);
		return (0);
	}
	free_lvl(temp);
	return (1);
}
