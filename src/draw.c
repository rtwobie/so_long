/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:19:01 by rha-le            #+#    #+#             */
/*   Updated: 2025/04/18 03:10:08 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "defs.h"
#include "structs.h"
#include "draw.h"
#include "utils.h"

static void	putnb_to_hud(t_app *game, int n, int x, int i)
{
	if (n >= 999)
		n = 999;
	while (i--)
	{
		mlx_put_image_to_window \
			(game->app, game->win, game->tex._hud[n % 10], x, 0);
		n /= 10;
		x -= 32;
	}
}

static void	render_hud(t_app *game, t_texture *tex, int moves, int score)
{
	mlx_put_image_to_window \
		(game->app, game->win, tex->_hud[10], (32 * 1), 0);
	mlx_put_image_to_window \
		(game->app, game->win, tex->_hud[12], (32 * 2), 0);
	putnb_to_hud(game, moves, (32 * 5), 3);
	mlx_put_image_to_window \
		(game->app, game->win, tex->_hud[11], game->win_w - (32 * 5), 0);
	mlx_put_image_to_window \
		(game->app, game->win, tex->_hud[12], game->win_w - (32 * 4), 0);
	putnb_to_hud(game, score, game->win_w - (32 * 2), 2);
}

static void	render_border(t_app *game, t_texture *tex, int win_w, int win_h)
{
	int	i;

	i = 32;
	while (i < win_h - 32)
	{
		mlx_put_image_to_window(game->app, game->win, tex->_border[5], 0, i);
		mlx_put_image_to_window \
			(game->app, game->win, tex->_border[6], win_w - 32, i);
		i += 32;
	}
	i = 32;
	while (i < win_w - 32)
	{
		mlx_put_image_to_window(game->app, game->win, tex->_border[4], i, 0);
		mlx_put_image_to_window \
			(game->app, game->win, tex->_border[7], i, win_h - 32);
		i += 32;
	}
	mlx_put_image_to_window(game->app, game->win, tex->_border[0], 0, 0);
	mlx_put_image_to_window \
		(game->app, game->win, tex->_border[1], win_w - 32, 0);
	mlx_put_image_to_window \
		(game->app, game->win, tex->_border[2], 0, win_h - 32);
	mlx_put_image_to_window \
		(game->app, game->win, tex->_border[3], win_w - 32, win_h - 32);
}

static void	render_cell(t_app *game, t_texture *tex, int x, int y)
{
	void	*texture;
	char	cell;

	texture = NULL;
	cell = game->map->lvl[y][x];
	if (cell == '0')
		texture = tex->_0;
	else if (cell == 'B')
		texture = tex->_0_b;
	else if (cell == 'l' || cell == 'L')
		texture = tex->_l;
	else if (cell == 'K' || cell == 'k')
		texture = tex->_k;
	else if (cell == '1')
		texture = tex->_1;
	else if (cell == 'P')
		texture = tex->_p;
	else if (cell == 'C')
		texture = tex->_c;
	else if (cell == 'E')
		texture = tex->_e;
	mlx_put_image_to_window \
		(game->app, game->win, texture, x * TILE_SIZE + 32, y * TILE_SIZE + 32);
}

int	draw_map(t_app *game)
{
	int		y;
	int		x;

	render_border(game, &game->tex, game->win_w, game->win_h);
	render_hud(game, &game->tex, game->moves, game->score);
	y = 0;
	while (y < game->map->h)
	{
		x = 0;
		while (x < game->map->w)
		{
			render_cell(game, &game->tex, x, y);
			++x;
		}
		++y;
	}
	return (1);
}
