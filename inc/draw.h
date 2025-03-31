/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:22:00 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/27 02:23:15 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "structs.h"

int		close_window(t_app *game);
void	init_game(t_app *game, char *mapname);

#endif // !DRAW_H
