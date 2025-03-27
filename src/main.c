/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:55:35 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/27 02:59:21 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "ft_printf.h"
#include "structs.h"
#include "draw.h"

int	main(int argc, char **argv)
{
	(void)argc;
	/*t_app		game;*/
	/*t_entity	player;*/
	/*game.player = &player;*/
	char **map = read_map(argv[1]);
	while (map)
	{
		ft_printf("%s\n", *map);
		++map;
	}

	/*init_game(&game, argv[1]);*/
	return (0);
}
