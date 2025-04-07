/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 21:51:23 by rha-le            #+#    #+#             */
/*   Updated: 2025/04/07 21:07:20 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "structs.h"
#include <stdio.h>
#include <stdlib.h>

void	*free_lvl(char **p)
{
	size_t	i;

	i = 0;
	while (p[i])
		free(p[i++]);
	free(p);
	return (NULL);
}

void	*free_all(t_map *map)
{
	if (map->lvl)
		free_lvl(map->lvl);
	if (map->coin)
		free(map->coin);
	free(map);
	return (NULL);
}

void	print_error(char *s)
{
	ft_putstr_fd("Error\n", 2);
	if (ft_strrchr(s, '\n'))
		ft_putstr_fd(s, 2);
	else
		perror(s);
}

