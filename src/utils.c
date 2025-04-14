/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 21:51:23 by rha-le            #+#    #+#             */
/*   Updated: 2025/04/09 16:36:21 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "libft.h"
#include "structs.h"
#include <mlx.h>
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

int	close_window(t_app *game)
{
	destroy_textures(game);
	mlx_destroy_window(game->app, game->win);
	mlx_destroy_display(game->app);
	if (game->map)
		free_all(game->map);
	if (game->app)
		free(game->app);
	free(game);
	exit(0);
}

void	print_error(char *s)
{
	ft_putstr_fd("Error\n", 2);
	if (ft_strrchr(s, '\n'))
		ft_putstr_fd(s, 2);
	else
		perror(s);
}

void print_map(char **lvl)
{
	int	i;

	i = -1;
	while (lvl[++i])
	{
		ft_putstr_fd(lvl[i], 1);
		ft_putchar_fd('\n', 1);
	}
}

