/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 03:29:49 by rha-le            #+#    #+#             */
/*   Updated: 2025/04/18 03:38:17 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

static void	toggle_trap(t_map *map, char trap, int count, int toggle)
{
	int	i;

	i = -1;
	if (!count)
		return ;
	if (toggle)
	{
		if (trap == 'l')
			while (++i < count)
				map->lvl[map->l[i].y][map->l[i].x] = 'L';
		else if (trap == 'K')
			while (++i < count)
				map->lvl[map->k[i].y][map->k[i].x] = 'K';
	}
	else if (!toggle)
	{
		if (trap == 'l')
			while (++i < count)
				map->lvl[map->l[i].y][map->l[i].x] = 'l';
		else if (trap == 'K')
			while (++i < count)
				map->lvl[map->k[i].y][map->k[i].x] = 'k';
	}
}

void	update_traps(t_app *game, t_map *map)
{
	if (!map->l_count && !map->k_count)
		return ;
	++map->trap_state;
	if (map->trap_state == 1)
	{
		toggle_trap(map, 'K', map->k_count, 0);
		game->tex._l = game->tex._t2;
		game->tex._k = game->tex._t1;
	}
	else if (map->trap_state == 2)
	{
		toggle_trap(map, 'l', map->l_count, 1);
		game->tex._l = game->tex._t3;
		game->tex._k = game->tex._t2;
	}
	else if (map->trap_state == 3)
	{
		toggle_trap(map, 'l', map->l_count, 0);
		toggle_trap(map, 'K', map->k_count, 1);
		game->tex._l = game->tex._t1;
		game->tex._k = game->tex._t3;
		map->trap_state = 0;
	}
}
