/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:15:29 by rha-le            #+#    #+#             */
/*   Updated: 2025/04/11 16:24:14 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "structs.h"
#include "draw.h"
#include "input.h"
#include "utils.h"
#include <mlx.h>
#include <stdlib.h>

static void	set_window_size(t_map *map, int *w, int *h)
{
	*w = map->w * TILE_SIZE;
	*h = map->h * TILE_SIZE;
	if (*h > MAX_WIN_HEIGHT)
		*h = MAX_WIN_HEIGHT;
	if (*w > MAX_WIN_WIDTH)
		*w = MAX_WIN_WIDTH;
}

void	init_game(t_app *game)
{
	int	win_h;
	int	win_w;

	game->app = mlx_init();
	if (!game->app)
		return ;
	set_window_size(game->map, &win_w, &win_h);
	game->win = mlx_new_window(game->app, win_w, win_h, "so_long");
	if (!game->win)
		return ;
	load_textures(game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop_hook(game->app, draw_map, game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop(game->app);
	free(game->app);
	free(game);
}
