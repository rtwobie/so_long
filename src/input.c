/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:23:41 by rha-le            #+#    #+#             */
/*   Updated: 2025/04/09 17:43:22 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "defs.h"
#include "ft_printf.h"
#include "structs.h"
#include "draw.h"

static void	update_map(t_app *game, t_map *map, int x, int y)
{
	if (map->lvl[y][x] == 'C')
	{
		++game->score;
		map->lvl[y][x] = '0';
		ft_printf("coins: %i/%i\n", game->score, map->coin_count);
	}
	if (map->player.y == map->exit.y && map->player.x == map->exit.x)
		map->lvl[map->player.y][map->player.x] = 'E';
	else
		map->lvl[map->player.y][map->player.x] = '0';
	map->player.x = x;
	map->player.y = y;
}

/*static void rotate_player(t_texture *tex, int keycode)*/
/*{*/
/*	if (keycode == KEY_W)*/
/*		tex->_p = tex->_p_b;*/
/*	else if (keycode == KEY_A)*/
/*		tex->_p = tex->_p_l;*/
/*	else if (keycode == KEY_S)*/
/*		tex->_p = tex->_p_fr;*/
/*	else if (keycode == KEY_D)*/
/*		tex->_p = tex->_p_r;*/
/*}*/

static void	move_player(t_app *game, t_map *map, int x, int y)
{
	if (map->lvl[y][x] == '1')
		return ;
	if (map->lvl[y][x] == 'E' && game->score == map->coin_count)
		close_window(game);
	update_map(game, map, x, y);
	map->lvl[y][x] = 'P';
	++game->moves;
	ft_printf("moves: %i\n", game->moves);
}

int	key_hook(int keycode, t_app *game)
{
	int	x;
	int	y;

	x = game->map->player.x;
	y = game->map->player.y;
	if (keycode == KEY_ESCAPE)
		close_window(game);
	if (keycode == KEY_W)
		move_player(game, game->map,x, y - 1);
	if (keycode == KEY_A)
		move_player(game, game->map, x - 1, y);
	if (keycode == KEY_S)
		move_player(game, game->map, x, y + 1);
	if (keycode == KEY_D)
		move_player(game, game->map, x + 1, y);
	return (0);
}
