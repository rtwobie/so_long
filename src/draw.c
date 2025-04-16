/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:19:01 by rha-le            #+#    #+#             */
/*   Updated: 2025/04/16 21:36:37 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "defs.h"
#include "structs.h"
#include "draw.h"
#include "utils.h"

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
	else if (cell == 'l' || cell == 'L')
		texture = game->tex._l;
	else if (cell == 'K' || cell == 'k')
		texture = game->tex._k;
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
			(game->app, game->win, texture, x * TILE_SIZE, y * TILE_SIZE + 32);
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
