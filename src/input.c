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

#include "defs.h"
#include "ft_printf.h"
#include "structs.h"
#include "utils.h"

static int	is_on_obj(t_entity *obj, int obj_count, int x, int y)
{
	int i;

	i = -1;
	while (++i < obj_count)
	{
		if (y == obj[i].y && x == obj[i].x)
			return (1);
	}
	return (0);
}

static char	place_surface(t_map *map, t_entity *player)
{
	if (player->y == map->exit.y && player->x == map->exit.x)
		return ('E');
	if (is_on_obj(map->b0, map->b0_count, player->x, player->y))
			return ('1');
	if (is_on_obj(map->l, map->l_count, player->x, player->y))
			return ('l');
	if (is_on_obj(map->k, map->k_count, player->x, player->y))
			return ('K');
	return ('0');
}

static void	update_map(t_app *game, t_map *map, int x, int y)
{
	if (map->lvl[y][x] == 'C')
	{
		++game->score;
		map->lvl[y][x] = '0';
		ft_printf("coins: %i/%i\n", game->score, map->coin_count);
	}
	if (y == map->exit.y && x == map->exit.x)
		game->tex._p = game->tex._p_e;
	else if (is_on_obj(map->b0, map->b0_count, x, y))
		game->tex._p = game->tex._p_b;
	else if (is_on_obj(map->l, map->l_count, x, y) || is_on_obj(map->k, map->k_count, x, y))
		game->tex._p = game->tex._p_b;
	map->lvl[map->player.y][map->player.x] = place_surface(map, &map->player);
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

static void lava_trap_state(t_app *game, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (map->trap_state == 0)
	{
		while (++i < map->l_count)
			map->lvl[map->l[i].y][map->l[i].x] = 'L';
		while (++j < map->k_count)
			map->lvl[map->k[j].y][map->k[j].x] = 'k';
		game->tex._l = game->tex._l1;
		game->tex._k = game->tex._l0;
	}
	else if (map->trap_state == 2)
	{
		while (++i < map->l_count)
			map->lvl[map->l[i].y][map->l[i].x] = 'l';
		while (++j < map->k_count)
			map->lvl[map->k[j].y][map->k[j].x] = 'K';
		game->tex._l = game->tex._l0;
		game->tex._k = game->tex._l1;
	}
	if (map->trap_state == 3)
		map->trap_state = 0;
	else
		++map->trap_state;
	ft_printf("state: %i\n", map->trap_state);
}

static void	move_player(t_app *game, int x, int y, int keycode)
{
	rotate_player(&game->tex, keycode);
	if (game->map->lvl[y][x] == '1')
		return ;
	lava_trap_state(game, game->map);
	if (game->map->lvl[y][x] == 'E' && game->score == game->map->coin_count)
	{
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
		move_player(game, x, y - 1, keycode);
	if (keycode == KEY_A)
		move_player(game, x - 1, y, keycode);
	if (keycode == KEY_S)
		move_player(game, x, y + 1, keycode);
	if (keycode == KEY_D)
		move_player(game, x + 1, y, keycode);
	return (0);
}
