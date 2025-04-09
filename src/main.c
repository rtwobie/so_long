/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:55:35 by rha-le            #+#    #+#             */
/*   Updated: 2025/04/08 18:41:55 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "draw.h"
#include "libft.h"
#include "structs.h"
#include "map.h"
#include "utils.h"

/*static void print_map(char **lvl)*/
/*{*/
/*	for (int i = 0; lvl[i]; i++)*/
/*	{*/
/*		ft_putstr_fd(lvl[i], 1);*/
/*		ft_putchar_fd('\n', 1);*/
/*	}*/
/*}*/

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	t_app	*game;
	t_map	*map;

	game = ft_calloc(1, sizeof(*game));
	if (!game)
		return (1);
	map = ft_calloc(1, sizeof(*map));
	if (!map)
		return (1);

	init_map(map, argv[1]);

	game->map = map;
	init_game(game);

	free_all(map);
	free(game);
	close_window(game);
	return (0);
}
