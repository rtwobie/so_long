/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:19:26 by rha-le            #+#    #+#             */
/*   Updated: 2025/04/08 18:28:53 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "libft.h"
#include "structs.h"
#include "utils.h"
#include <stdlib.h>

static void	count_coins(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	map->coin_count = 0;
	while (y < map->h)
	{
		x = 0;
		while (x < map->w)
		{
			map->coin_count += (map->lvl[y][x] == 'C');
			++x;
		}
		++y;
	}
}

static void	get_pos(t_map *map, t_entity *entity, char c)
{
	int	x;
	int	y;
	t_entity *p;

	y = 0;
	p = entity;
	while (y < map->h)
	{
		x = 0;
		while (x < map->w)
		{
			if (map->lvl[y][x] == c)
			{
				p->x = x;
				p->y = y;
				++p;
			}
			++x;
		}
		++y;
	}
}

static t_entity	*init_coins(t_map *map, size_t count)
{
	size_t		i;
	t_entity	*coins;

	coins = ft_calloc(count, sizeof(*coins));
	if (!coins)
		return (NULL);
	i = 0;
	while (i < count)
	{
		get_pos(map, coins, 'C');
		++i;
	}
	return (coins);
}

static int	init_objects(t_map *map)
{
	count_coins(map);
	if (!map->coin_count)
	{
		free_all(map);
		print_error("Map Invalid: No Coins found!\n");
		exit(1);
	}
	map->coin = init_coins(map, (size_t)map->coin_count);
	get_pos(map, &map->player, 'P');
	get_pos(map, &map->exit, 'E');
	if ((!map->player.x && !map->player.y) || (!map->exit.x && !map->exit.y))
	{
		free_all(map);
		print_error("Map Invalid: No Player and/or Exit found!\n");
		exit(1);
	}
	return (0);
}

int	init_map(t_map *map, char *filename)
{
	create_lvl(filename, map);
	if (!map->lvl)
		exit(1);
	init_objects(map);
	if (!is_mapvalid(map))
	{
		free_all(map);
		print_error("Map Invalid: Open Walls or Objectives not reachable!\n");
		exit(1);
	}
	return (0);
}
