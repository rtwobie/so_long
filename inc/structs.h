/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 20:38:55 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/31 18:03:42 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_entity
{
	void	*tex;
	int		w;
	int		h;
	int		x;
	int		y;
}	t_entity;

typedef struct s_map
{
	char	**lvl;
	int		w;
	int		h;
	int		start_x;
	int		start_y;
}	t_map;

typedef struct s_app
{
	void		*app;
	void		*win;
	t_entity	*player;
}	t_app;

#endif // !STRUCTS_H
