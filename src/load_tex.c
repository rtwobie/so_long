/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 02:39:43 by rha-le            #+#    #+#             */
/*   Updated: 2025/04/18 03:01:34 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include <mlx.h>

void	load_player_textures(t_app *game)
{
	int	w;
	int	h;

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
	game->tex._p_b = mlx_xpm_file_to_image \
		(game->app, "textures/p_front_b.xpm", &w, &h);
	game->tex._p_t1 = mlx_xpm_file_to_image \
		(game->app, "textures/p_trap1.xpm", &w, &h);
	game->tex._p_t2 = mlx_xpm_file_to_image \
		(game->app, "textures/p_trap2.xpm", &w, &h);
}

void	load_platform_textures(t_app *game)
{
	int	w;
	int	h;

	game->tex._1 = mlx_xpm_file_to_image \
		(game->app, "textures/1.xpm", &w, &h);
	game->tex._0 = mlx_xpm_file_to_image \
		(game->app, "textures/0.xpm", &w, &h);
	game->tex._0_b = mlx_xpm_file_to_image \
		(game->app, "textures/0_b.xpm", &w, &h);
	game->tex._t1 = mlx_xpm_file_to_image \
		(game->app, "textures/trap1.xpm", &w, &h);
	game->tex._t2 = mlx_xpm_file_to_image \
		(game->app, "textures/trap2.xpm", &w, &h);
	game->tex._t3 = mlx_xpm_file_to_image \
		(game->app, "textures/trap3.xpm", &w, &h);
	game->tex._c = mlx_xpm_file_to_image \
		(game->app, "textures/c.xpm", &w, &h);
	game->tex._e = mlx_xpm_file_to_image \
		(game->app, "textures/e.xpm", &w, &h);
}

void	load_hud_nb_textures(t_app *game)
{
	int	w;
	int	h;

	game->tex._hud[0] = mlx_xpm_file_to_image \
		(game->app, "textures/HUD_0.xpm", &w, &h);
	game->tex._hud[1] = mlx_xpm_file_to_image \
		(game->app, "textures/HUD_1.xpm", &w, &h);
	game->tex._hud[2] = mlx_xpm_file_to_image \
		(game->app, "textures/HUD_2.xpm", &w, &h);
	game->tex._hud[3] = mlx_xpm_file_to_image \
		(game->app, "textures/HUD_3.xpm", &w, &h);
	game->tex._hud[4] = mlx_xpm_file_to_image \
		(game->app, "textures/HUD_4.xpm", &w, &h);
	game->tex._hud[5] = mlx_xpm_file_to_image \
		(game->app, "textures/HUD_5.xpm", &w, &h);
	game->tex._hud[6] = mlx_xpm_file_to_image \
		(game->app, "textures/HUD_6.xpm", &w, &h);
	game->tex._hud[7] = mlx_xpm_file_to_image \
		(game->app, "textures/HUD_7.xpm", &w, &h);
	game->tex._hud[8] = mlx_xpm_file_to_image \
		(game->app, "textures/HUD_8.xpm", &w, &h);
	game->tex._hud[9] = mlx_xpm_file_to_image \
		(game->app, "textures/HUD_9.xpm", &w, &h);
}

void	load_hud_extra_textures(t_app *game)
{
	int	w;
	int	h;

	game->tex._hud[10] = mlx_xpm_file_to_image \
		(game->app, "textures/HUD_p.xpm", &w, &h);
	game->tex._hud[11] = mlx_xpm_file_to_image \
		(game->app, "textures/HUD_c.xpm", &w, &h);
	game->tex._hud[12] = mlx_xpm_file_to_image \
		(game->app, "textures/HUD_x.xpm", &w, &h);
}

void	load_border_textures(t_app *game)
{
	int	w;
	int	h;

	game->tex._border[0] = mlx_xpm_file_to_image \
		(game->app, "textures/border1.xpm", &w, &h);
	game->tex._border[1] = mlx_xpm_file_to_image \
		(game->app, "textures/border2.xpm", &w, &h);
	game->tex._border[2] = mlx_xpm_file_to_image \
		(game->app, "textures/border3.xpm", &w, &h);
	game->tex._border[3] = mlx_xpm_file_to_image \
		(game->app, "textures/border4.xpm", &w, &h);
	game->tex._border[4] = mlx_xpm_file_to_image \
		(game->app, "textures/border5.xpm", &w, &h);
	game->tex._border[5] = mlx_xpm_file_to_image \
		(game->app, "textures/border6.xpm", &w, &h);
	game->tex._border[6] = mlx_xpm_file_to_image \
		(game->app, "textures/border7.xpm", &w, &h);
	game->tex._border[7] = mlx_xpm_file_to_image \
		(game->app, "textures/border8.xpm", &w, &h);
}
