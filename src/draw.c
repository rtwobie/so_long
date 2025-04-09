/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:19:01 by rha-le            #+#    #+#             */
/*   Updated: 2025/04/09 18:09:38 by rha-le           ###   ########.fr       */
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
	destroy_textures(game);
	free(game->app);
	free(game);
	exit(0);
}

void	render_cell(t_app *game, int x, int y)
{
	void	*texture;
	char	cell;

	texture = NULL;
	cell = game->map->lvl[y][x];
	if (cell == '0')
		texture = game->tex._0;
	if (cell == '1')
		texture = game->tex._1;
	if (cell == 'P')
		texture = game->tex._p;
	if (cell == 'C')
		texture = game->tex._c;
	if (cell == 'E')
		texture = game->tex._e;
	mlx_put_image_to_window(game->app, game->win, texture, x * TILE_SIZE, y * TILE_SIZE);
}

int draw_map(t_app *game)
{
	int		y;
	int		x;
	int		i;
	int		j;

	y = 0;
	i = -1;
	while (++i < game->map->h)
	{
		x = 0;
		j = -1;
		while (++j < game->map->w)
		{
			render_cell(game, x, y);
			++x;
		}
		++y;
	}
	return (1);
}

void	load_textures(t_app *game)
{
	int w;
	int h;
	game->tex._0 = mlx_xpm_file_to_image \
		(game->app, "textures/bg.xpm", &w, &h);
	game->tex._1 = mlx_xpm_file_to_image \
		(game->app, "textures/wall.xpm", &w, &h);
	game->tex._p = mlx_xpm_file_to_image \
		(game->app, "textures/slime3x.xpm", &w, &h);
	game->tex._c = mlx_xpm_file_to_image \
		(game->app, "textures/ph_coin.xpm", &w, &h);
	game->tex._e = mlx_xpm_file_to_image \
		(game->app, "textures/ph_door.xpm", &w, &h);
}

void	destroy_textures(t_app *game)
{
	mlx_destroy_image(game->app, game->tex._0);
	mlx_destroy_image(game->app, game->tex._1);
	mlx_destroy_image(game->app, game->tex._p);
	mlx_destroy_image(game->app, game->tex._c);
	mlx_destroy_image(game->app, game->tex._e);
}

void	init_game(t_app *game)
{
	game->app = mlx_init();
	if (!game->app)
		return ;
	game->win = mlx_new_window(game->app, WIN_WIDTH, WIN_HEIGHT, "so_long");
	if (!game->win)
		return ;

	load_textures(game);
	draw_map(game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop(game->app);
	free(game->app);
	free(game);
}

