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
#include "ft_printf.h"
#include "input.h"
#include "structs.h"
#include "draw.h"

int	close_window(t_app *game)
{
	mlx_destroy_window(game->app, game->win);
	exit(0);
}

void init_game(t_app *game)
{
	game->app = mlx_init();
	game->win = mlx_new_window(game->app, WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");

	t_entity player;
	player.tex = mlx_xpm_file_to_image(game->app, "textures/slime.xpm", &player.x, &player.y);
	ft_printf("%i, %i\n", player.x, player.y);
	mlx_put_image_to_window(game->app, game->win, player.tex, WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
	mlx_hook(game->win, 17, 0, close_window, game);

	mlx_key_hook(game->win, key_hook, game);

	mlx_loop(game->app);
}

