/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 02:47:31 by rha-le            #+#    #+#             */
/*   Updated: 2025/04/18 03:02:03 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include <mlx.h>

void	destroy_platform_textures(t_app *game)
{
	mlx_destroy_image(game->app, game->tex._1);
	mlx_destroy_image(game->app, game->tex._0);
	mlx_destroy_image(game->app, game->tex._0_b);
	mlx_destroy_image(game->app, game->tex._t1);
	mlx_destroy_image(game->app, game->tex._t2);
	mlx_destroy_image(game->app, game->tex._t3);
	mlx_destroy_image(game->app, game->tex._c);
	mlx_destroy_image(game->app, game->tex._e);
}

void	destroy_player_textures(t_app *game)
{
	mlx_destroy_image(game->app, game->tex._p_w);
	mlx_destroy_image(game->app, game->tex._p_a);
	mlx_destroy_image(game->app, game->tex._p_s);
	mlx_destroy_image(game->app, game->tex._p_d);
	mlx_destroy_image(game->app, game->tex._p_e);
	mlx_destroy_image(game->app, game->tex._p_b);
	mlx_destroy_image(game->app, game->tex._p_t1);
	mlx_destroy_image(game->app, game->tex._p_t2);
}

void	destroy_hud_textures(t_app *game)
{
	mlx_destroy_image(game->app, game->tex._hud[0]);
	mlx_destroy_image(game->app, game->tex._hud[1]);
	mlx_destroy_image(game->app, game->tex._hud[2]);
	mlx_destroy_image(game->app, game->tex._hud[3]);
	mlx_destroy_image(game->app, game->tex._hud[4]);
	mlx_destroy_image(game->app, game->tex._hud[5]);
	mlx_destroy_image(game->app, game->tex._hud[6]);
	mlx_destroy_image(game->app, game->tex._hud[7]);
	mlx_destroy_image(game->app, game->tex._hud[8]);
	mlx_destroy_image(game->app, game->tex._hud[9]);
	mlx_destroy_image(game->app, game->tex._hud[10]);
	mlx_destroy_image(game->app, game->tex._hud[11]);
	mlx_destroy_image(game->app, game->tex._hud[12]);
}

void	destroy_border_textures(t_app *game)
{
	mlx_destroy_image(game->app, game->tex._border[0]);
	mlx_destroy_image(game->app, game->tex._border[1]);
	mlx_destroy_image(game->app, game->tex._border[2]);
	mlx_destroy_image(game->app, game->tex._border[3]);
	mlx_destroy_image(game->app, game->tex._border[4]);
	mlx_destroy_image(game->app, game->tex._border[5]);
	mlx_destroy_image(game->app, game->tex._border[6]);
	mlx_destroy_image(game->app, game->tex._border[7]);
}
