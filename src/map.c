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

static int count_obj(t_map *map, char obj)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (y < map->h)
	{
		x = 0;
		while (x < map->w)
		{
			count += (map->lvl[y][x] == obj);
			++x;
		}
		++y;
	}
	return (count);
}

static int	get_pos(t_map *map, t_entity *entity, char c)
{
	int			x;
	int			y;
	t_entity	*p;

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
	if (p == entity)
		return (-1);
	return (0);
}

static t_entity	*set_obj_group(t_map *map, size_t count, char obj)
{
	size_t		i;
	t_entity	*group;

	group = ft_calloc(count, sizeof(*group));
	if (!group)
		return (NULL);
	i = 0;
	while (i < count)
	{
		get_pos(map, group, obj);
		++i;
	}
	return (group);
}

static int	init_objects(t_map *map)
{
	map->coin_count = count_obj(map, 'C');
	if (!map->coin_count)
	{
		free_all(map);
		print_error("Map Invalid: No Coins found!\n");
		exit(1);
	}
	map->b0_count = count_obj(map, 'B');
	map->b0 = set_obj_group(map, (size_t)map->b0_count, 'B');
	map->coin = set_obj_group(map, (size_t)map->coin_count, 'C');
	if (get_pos(map, &map->player, 'P')  == -1 || \
		get_pos(map, &map->exit, 'E') == -1)
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
