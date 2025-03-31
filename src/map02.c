/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map02.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:55:11 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/31 18:19:47 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

int	start_pos(t_map *map)
{
	map->start_x = 0;
	map->start_y = 0;
	while (map->start_y < map->h)
	{
		map->start_x = 0;
		while (map->start_x < map->w \
			&& map->lvl[map->start_y][map->start_x] != 'P')
			++map->start_x;
		if (map->lvl[map->start_y][map->start_x] == 'P')
			return (1);
		++map->start_y;
	}
	return (0);
}

char	**flood_fill(t_map *map)
{
	char target = '0';
}


