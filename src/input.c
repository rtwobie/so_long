/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:23:41 by rha-le            #+#    #+#             */
/*   Updated: 2025/04/18 03:39:08 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "ft_printf.h"
#include "structs.h"
#include "utils.h"

void	update_traps(t_app *game, t_map *map);

static char	place_surface(char **original_lvl, t_entity *player)
{
	if (original_lvl[player->y][player->x] == 'E')
		return ('E');
	if (original_lvl[player->y][player->x] == 'B')
		return ('1');
	if (original_lvl[player->y][player->x] == 'l')
		return ('l');
	if (original_lvl[player->y][player->x] == 'K')
		return ('K');
	return ('0');
}

static void	update_map(t_app *game, t_map *map, int x, int y)
{
	if (map->lvl[y][x] == 'C')
	{
		++game->score;
		map->lvl[y][x] = '0';
	}
	else if (map->og_lvl[y][x] == 'E')
		game->tex._p = game->tex._p_e;
	else if (map->og_lvl[y][x] == 'B')
		game->tex._p = game->tex._p_b;
	else if (game->map->trap_state == 1 && map->og_lvl[y][x] == 'l')
		game->tex._p = game->tex._p_t2;
	else if (game->map->trap_state == 0 && map->og_lvl[y][x] == 'l')
		game->tex._p = game->tex._p_t1;
	else if (game->map->trap_state == 1 && map->og_lvl[y][x] == 'K')
		game->tex._p = game->tex._p_t1;
	else if (game->map->trap_state == 2 && map->og_lvl[y][x] == 'K')
		game->tex._p = game->tex._p_t2;
	map->lvl[map->player.y][map->player.x] = \
		place_surface(map->og_lvl, &map->player);
	map->player.x = x;
	map->player.y = y;
}

static void	rotate_player(t_texture *tex, int keycode)
{
	if (keycode == KEY_W)
		tex->_p = tex->_p_w;
	else if (keycode == KEY_A)
		tex->_p = tex->_p_a;
	else if (keycode == KEY_S)
		tex->_p = tex->_p_s;
	else if (keycode == KEY_D)
		tex->_p = tex->_p_d;
}

static void	move_player(t_app *game, int x, int y, int keycode)
{
	if (game->map->lvl[y][x] == '1')
		return ;
	rotate_player(&game->tex, keycode);
	update_traps(game, game->map);
	if (game->map->lvl[y][x] == 'E' && game->score == game->map->coin_count)
	{
		ft_printf("Total Moves:\t%i\n", ++game->moves);
		ft_printf("Level Complete!\n");
		close_window(game);
	}
	if (game->map->lvl[y][x] == 'L' || game->map->lvl[y][x] == 'K')
	{
		ft_printf("You Died!\n");
		close_window(game);
	}
	update_map(game, game->map, x, y);
	game->map->lvl[y][x] = 'P';
	++game->moves;
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
		move_player(game, x, y - 1, keycode);
	if (keycode == KEY_A)
		move_player(game, x - 1, y, keycode);
	if (keycode == KEY_S)
		move_player(game, x, y + 1, keycode);
	if (keycode == KEY_D)
		move_player(game, x + 1, y, keycode);
	return (0);
}
