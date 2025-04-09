/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:19:01 by rha-le            #+#    #+#             */
/*   Updated: 2025/04/08 18:47:02 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "defs.h"
#include "input.h"
#include "structs.h"
#include "draw.h"

int	close_window(t_app *game)
{
	mlx_destroy_window(game->app, game->win);
	exit(0);
}

int draw_map(t_app *game)
{
	int		y;
	int		x;

	y = 0;
	for (int i = 0; i < game->map->h; i++)
	{
		x = 0;
		for (int j = 0; j < game->map->w; j++)
		{
				mlx_put_image_to_window(game->app, game->win, game->_0.tex, x, y);
			x += game->_0.w;
		}
		y += game->_0.h;
	}

	y = 0;
	for (int i = 0; i < game->map->h; i++)
	{
		x = 0;
		for (int j = 0; j < game->map->w; j++)
		{
			if (game->map->lvl[i][j] == '1')
				mlx_put_image_to_window(game->app, game->win, game->_1.tex, x, y);
			x += game->_1.w;
		}
		y += game->_1.h;
	}

	x = game->map->player.x * game->_p.w;
	y = game->map->player.y * game->_p.h;
	mlx_put_image_to_window(game->app, game->win, game->_p.tex, x, y);
	return (0);
}

int	draw_obj(t_app *game)
{
	game->frame = mlx_new_image(game->app, game->_0.w * game->map->w, game->_0.h * game->map->h);
	return (1);
}

void	load_textures(t_app *game)
{
	game->_0.tex = mlx_xpm_file_to_image(game->app, "textures/bg.xpm", &game->_0.w, &game->_0.h);
	game->_1.tex = mlx_xpm_file_to_image(game->app, "textures/wall.xpm", &game->_1.w, &game->_1.h);
	game->_p.tex = mlx_xpm_file_to_image(game->app, "textures/slime3x.xpm", &game->_p.w, &game->_p.h);
	game->_c.tex = mlx_xpm_file_to_image(game->app, "textures/ph_coin.xpm", &game->_c.w, &game->_c.h);
	game->_e.tex = mlx_xpm_file_to_image(game->app, "textures/ph_door.xpm", &game->_e.w, &game->_e.h);
}

void	init_game(t_app *game)
{
	game->app = mlx_init();
	if (!game->app)
		return ;
	game->win = mlx_new_window(game->app, WIN_WIDTH, WIN_HEIGHT, "so_long");

	load_textures(game);
	draw_map(game);
	mlx_loop_hook(game->app, draw_obj, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop(game->app);
}

