/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 20:38:55 by rha-le            #+#    #+#             */
/*   Updated: 2025/04/07 19:55:13 by rha-le           ###   ########.fr       */
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
	void	*tex;
	int		w;
	int		h;
}	t_texture;

typedef struct s_app
{
	void		*app;
	void		*win;
	void		*frame;
	t_map		*map;
	t_texture	_1;
	t_texture	_0;
	t_texture	_p;
	t_texture	_c;
	t_texture	_e;
}	t_app;

#endif // !STRUCTS_H
