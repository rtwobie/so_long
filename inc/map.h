/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:04:23 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/28 18:50:55 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "structs.h"
# include <unistd.h>

# ifndef BYTES_RD
#  define BYTES_RD 1024
# endif

int	read_map(char *filename, t_map *map);
int	get_dimensions(char *s, int *x, int *y);

#endif //!MAP_H
