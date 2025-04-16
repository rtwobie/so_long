/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 21:34:41 by rha-le            #+#    #+#             */
/*   Updated: 2025/04/16 21:34:56 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include <mlx.h>

void	load_textures(t_app *game)
{
	int	w;
	int	h;

	game->tex._0 = mlx_xpm_file_to_image \
		(game->app, "textures/0.xpm", &w, &h);
	game->tex._0_b = mlx_xpm_file_to_image \
		(game->app, "textures/0_b.xpm", &w, &h);
	game->tex._t1 = mlx_xpm_file_to_image \
		(game->app, "textures/trap1.xpm", &w, &h);
	game->tex._t2 = mlx_xpm_file_to_image \
		(game->app, "textures/trap2.xpm", &w, &h);
	game->tex._t3= mlx_xpm_file_to_image \
		(game->app, "textures/trap3.xpm", &w, &h);
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
	game->tex._p_b = mlx_xpm_file_to_image \
		(game->app, "textures/p_front_b.xpm", &w, &h);
	game->tex._p_t1 = mlx_xpm_file_to_image \
		(game->app, "textures/p_trap1.xpm", &w, &h);
	/*game->tex._p_t2 = mlx_xpm_file_to_image \*/
	/*	(game->app, "textures/p_trap2.xpm", &w, &h);*/
	game->tex._p = game->tex._p_s;
	game->tex._l = game->tex._t1;
	game->tex._k = game->tex._t3;
}

void	destroy_textures(t_app *game)
{
	mlx_destroy_image(game->app, game->tex._0);
	mlx_destroy_image(game->app, game->tex._0_b);
	mlx_destroy_image(game->app, game->tex._t1);
	mlx_destroy_image(game->app, game->tex._t2);
	mlx_destroy_image(game->app, game->tex._t3);
	mlx_destroy_image(game->app, game->tex._1);
	mlx_destroy_image(game->app, game->tex._c);
	mlx_destroy_image(game->app, game->tex._e);
	mlx_destroy_image(game->app, game->tex._p_w);
	mlx_destroy_image(game->app, game->tex._p_a);
	mlx_destroy_image(game->app, game->tex._p_s);
	mlx_destroy_image(game->app, game->tex._p_d);
	mlx_destroy_image(game->app, game->tex._p_e);
	mlx_destroy_image(game->app, game->tex._p_b);
	mlx_destroy_image(game->app, game->tex._p_t1);
	/*mlx_destroy_image(game->app, game->tex._p_t2);*/
}

