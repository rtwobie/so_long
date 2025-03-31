/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:55:35 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/31 18:31:07 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "structs.h"
#include "map.h"
#include "utils.h"

static void print_map(t_map *map)
{
	for (int i = 0; map->lvl[i]; i++)
	{
		ft_putstr_fd(map->lvl[i], 1);
		ft_putchar_fd('\n', 1);
	}
}

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

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	/*t_app		game;*/
	/*t_entity	player;*/
	/*game.player = &player;*/
	t_map map;

	create_map(argv[1], &map);

	print_map(&map);
	ft_printf("w: %i, h: %i\n", map.w, map.h);

	if (!start_pos(&map))
	{
		free_all(map.lvl);
		return (1);
	}
	print_map(&map);
	ft_printf("x: %i, y: %i\n", map.start_x, map.start_y);

	free_all(map.lvl);
	return (0);
}
