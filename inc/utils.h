/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 21:51:54 by rha-le            #+#    #+#             */
/*   Updated: 2025/04/09 16:36:37 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structs.h"

void	print_error(char *s);
void	*free_lvl(char **p);
void	*free_all(t_map *map);
void	print_map(char **lvl);

#endif // !UTILS_H
