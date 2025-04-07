/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 21:51:54 by rha-le            #+#    #+#             */
/*   Updated: 2025/04/07 19:57:34 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structs.h"

void	print_error(char *s);
void	*free_lvl(char **p);
void	*free_all(t_map *map);

#endif // !UTILS_H
