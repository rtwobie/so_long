/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:55:35 by rha-le            #+#    #+#             */
/*   Updated: 2025/04/09 17:51:09 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "structs.h"
#include "map.h"
#include "game.h"
#include "utils.h"

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
	ft_printf("moves: %i\n", game->moves);
	init_game(game);

	free_all(map);
	close_window(game);
	return (0);
}
