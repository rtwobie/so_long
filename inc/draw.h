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

#ifndef WINDOW_H
# define WINDOW_H

# include "structs.h"

int		close_window(t_app *game);
char	**read_map(char *filename);
void	init_game(t_app *game, char *mapname);

#endif // !WINDOW_H
