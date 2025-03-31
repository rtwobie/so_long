/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 21:51:23 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/28 21:51:40 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	*free_all(char **p)
{
	size_t	i;

	i = 0;
	while (p[i])
		free(p[i++]);
	free(p);
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

