/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:04:23 by rha-le            #+#    #+#             */
/*   Updated: 2025/04/07 22:23:58 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "structs.h"

# ifndef BYTES_RD
#  define BYTES_RD 1024
# endif

int		init_map(t_map *map, char *filename);
int		create_lvl(char *filename, t_map *map);
int		is_mapvalid(t_map *map);
char	**copy_lvl(char **lvl, int h);

#endif //!MAP_H
