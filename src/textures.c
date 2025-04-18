/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 21:34:41 by rha-le            #+#    #+#             */
/*   Updated: 2025/04/18 03:00:31 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include <mlx.h>

void	load_platform_textures(t_app *game);
void	load_player_textures(t_app *game);
void	load_hud_nb_textures(t_app *game);
void	load_hud_extra_textures(t_app *game);
void	load_border_textures(t_app *game);
void	destroy_platform_textures(t_app *game);
void	destroy_player_textures(t_app *game);
void	destroy_hud_textures(t_app *game);
void	destroy_border_textures(t_app *game);

void	load_textures(t_app *game)
{
	load_platform_textures(game);
	load_player_textures(game);
	load_hud_nb_textures(game);
	load_hud_extra_textures(game);
	load_border_textures(game);
	game->tex._p = game->tex._p_s;
	game->tex._l = game->tex._t1;
	game->tex._k = game->tex._t3;
}

void	destroy_textures(t_app *game)
{
	destroy_platform_textures(game);
	destroy_player_textures(game);
	destroy_hud_textures(game);
	destroy_border_textures(game);
}
