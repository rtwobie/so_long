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

void	render_update(t_app *game, int x, int y)
{
	mlx_put_image_to_window(game->app, game->win, game->tex._p, x * TILE_SIZE, y * TILE_SIZE);
	if (game->map->lvl[game->map->player.y][game->map->player.x] == 'E')
		mlx_put_image_to_window(game->app, game->win, game->tex._e, game->map->exit.x * TILE_SIZE, game->map->exit.y * TILE_SIZE);
	else
		mlx_put_image_to_window(game->app, game->win, game->tex._0, game->map->player.x * TILE_SIZE, game->map->player.y * TILE_SIZE);
}

void	move_player(t_app *game, int x, int y)
{
	if (game->map->lvl[y][x] == '1')
		return ;
	if (game->map->lvl[y][x] == 'E' && game->score != game->map->coin_count)
		return ;
	render_update(game, x, y);
	if (game->map->lvl[y][x] == 'E')
		close_window(game);
	if (game->map->lvl[y][x] == 'C')
	{
		++game->score;
		game->map->lvl[y][x] = '0';
		ft_printf("coins: %i/%i\n", game->score, game->map->coin_count);
	}
	game->map->player.x = x;
	game->map->player.y = y;
	++game->moves;
	ft_printf("moves: %i\n", game->moves);
}

int	key_hook(int keycode, t_app *game)
{
	//ft_printf("%i\n", keycode); // NOTE: Delete after!
	if (keycode == KEY_ESCAPE)
		close_window(game);
	if (keycode == KEY_W)
		move_player(game, game->map->player.x, game->map->player.y - 1);
	if (keycode == KEY_A)
		move_player(game, game->map->player.x - 1, game->map->player.y);
	if (keycode == KEY_S)
		move_player(game, game->map->player.x, game->map->player.y + 1);
	if (keycode == KEY_D)
		move_player(game, game->map->player.x + 1, game->map->player.y);
	return (0);
}
