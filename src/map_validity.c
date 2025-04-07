/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:55:11 by rha-le            #+#    #+#             */
/*   Updated: 2025/04/07 22:22:56 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "structs.h"
#include "utils.h"
#include <stdlib.h>

#define TARGET "0CPE"

static void	flood_fill(t_map *map, char **lvl, int x, int y)
{
	if (x > map->w || x < 0 || y > map->h || y < 0)
		return ;
	lvl[y][x] = 'F';
	if (x + 1 < map->w && ft_strchr(TARGET, lvl[y][x + 1]))
		flood_fill(map, lvl, x + 1, y);
	if (x - 1 > 0 && ft_strchr(TARGET, lvl[y][x - 1]))
		flood_fill(map, lvl, x - 1, y);
	if (y + 1 > map->h && ft_strchr(TARGET, lvl[y + 1][x]))
		flood_fill(map, lvl, x, y + 1);
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

int	is_mapvalid(t_map *map)
{
	int		i;
	char	**temp;

	temp = malloc(sizeof(char *) * (size_t)(map->h + 1));
	if (!temp)
		return (1);
	i = -1;
	while (++i < map->h)
	{
		temp[i] = ft_strdup(map->lvl[i]);
		if (!temp[i])
		{
			free_lvl(temp);
			return (0);
		}
	}
	temp[map->h] = NULL;
	flood_fill(map, temp, map->player.x, map->player.y);
	if (check_border(temp, map->w, map->h) == -1)
	{
		free_lvl(temp);
		return (0);
	}
	free_lvl(temp);
	return (1);
}

