/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:19:01 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/27 03:48:41 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "defs.h"
#include "get_next_line.h"
#include "input.h"
#include "structs.h"
#include "draw.h"

int	close_window(t_app *game)
{
	mlx_destroy_window(game->app, game->win);
	exit(0);
}

void init_game(t_app *game, char *mapname)
{
	game->app = mlx_init();
	game->win = mlx_new_window(game->app, WIN_WIDTH, WIN_HEIGHT, "so_long");

	// init map
	(void)mapname;
	/*char **map = read_map(mapname);*/

	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop(game->app);
}

