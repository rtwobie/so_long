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
#include "structs.h"
#include "draw.h"
#include "utils.h"

void	load_textures(t_app *game)
{
	int	w;
	int	h;

	game->tex._0 = mlx_xpm_file_to_image \
		(game->app, "textures/0.xpm", &w, &h);
	game->tex._0_b = mlx_xpm_file_to_image \
		(game->app, "textures/0_b.xpm", &w, &h);
	game->tex._1 = mlx_xpm_file_to_image \
		(game->app, "textures/1.xpm", &w, &h);
	game->tex._c = mlx_xpm_file_to_image \
		(game->app, "textures/c.xpm", &w, &h);
	game->tex._e = mlx_xpm_file_to_image \
		(game->app, "textures/e.xpm", &w, &h);
	game->tex._p_w = mlx_xpm_file_to_image \
		(game->app, "textures/p_back.xpm", &w, &h);
	game->tex._p_a = mlx_xpm_file_to_image \
		(game->app, "textures/p_face_left.xpm", &w, &h);
	game->tex._p_s = mlx_xpm_file_to_image \
		(game->app, "textures/p_front.xpm", &w, &h);
	game->tex._p_d = mlx_xpm_file_to_image \
		(game->app, "textures/p_face_right.xpm", &w, &h);
	game->tex._p_e = mlx_xpm_file_to_image \
		(game->app, "textures/p_front_e.xpm", &w, &h);
	game->tex._p = game->tex._p_s;
}

void	destroy_textures(t_app *game)
{
	mlx_destroy_image(game->app, game->tex._0);
	mlx_destroy_image(game->app, game->tex._0_b);
	mlx_destroy_image(game->app, game->tex._1);
	mlx_destroy_image(game->app, game->tex._c);
	mlx_destroy_image(game->app, game->tex._e);
	mlx_destroy_image(game->app, game->tex._p_w);
	mlx_destroy_image(game->app, game->tex._p_a);
	mlx_destroy_image(game->app, game->tex._p_s);
	mlx_destroy_image(game->app, game->tex._p_d);
	mlx_destroy_image(game->app, game->tex._p_e);
}

static void	render_cell(t_app *game, int x, int y)
{
	void	*texture;
	char	cell;

	texture = NULL;
	cell = game->map->lvl[y][x];
	if (cell == '0')
		texture = game->tex._0;
	else if (cell == 'B')
		texture = game->tex._0_b;
	else if (cell == '1')
		texture = game->tex._1;
	else if (cell == 'P')
		texture = game->tex._p;
	else if (cell == 'C')
		texture = game->tex._c;
	else if (cell == 'E')
		texture = game->tex._e;
	if (texture)
		mlx_put_image_to_window \
			(game->app, game->win, texture, x * TILE_SIZE, y * TILE_SIZE);
	else
	{
		print_error("Texture not found!");
		close_window(game);
	}
}

int	draw_map(t_app *game)
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
