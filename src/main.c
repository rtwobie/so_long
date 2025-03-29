/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:55:35 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/28 18:52:16 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "ft_printf.h"
#include "draw.h"
#include "structs.h"
#include "map.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	/*t_app		game;*/
	/*t_entity	player;*/
	/*game.player = &player;*/
	t_map map;
	read_map(argv[1], &map);
	ft_printf("%i\n", map.w);
	ft_printf("%i\n", map.h);
	/*init_game(&game, &map);*/
	return (0);
}
