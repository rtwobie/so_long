/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 20:38:55 by rha-le            #+#    #+#             */
/*   Updated: 2025/04/09 17:10:29 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_entity
{
	int		x;
	int		y;
}	t_entity;

typedef struct s_map
{
	char		**lvl;
	int			w;
	int			h;
	int			coin_count;
	t_entity	*coin;
	t_entity	exit;
	t_entity	player;
}	t_map;

typedef struct s_texture
{
	void	*_1;
	void	*_0;
	void	*_c;
	void	*_e;
	void	*_p;
	void	*_p_w;
	void	*_p_a;
	void	*_p_s;
	void	*_p_d;
}	t_texture;

typedef struct s_app
{
	void		*app;
	void		*win;
	void		*frame;
	t_map		*map;
	t_texture	tex;
	int			moves;
	int			score;
}	t_app;

#endif // !STRUCTS_H
