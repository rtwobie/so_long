/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 20:38:55 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/27 03:48:45 by rha-le           ###   ########.fr       */
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

typedef struct s_app
{
	void	*app;
	void	*win;
	t_entity *player;
}	t_app;

#endif // !STRUCTS_H
