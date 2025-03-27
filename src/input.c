/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:23:41 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/27 02:59:07 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "defs.h"
#include "ft_printf.h"
#include "structs.h"
#include "draw.h"

int	key_hook(int keycode, t_app *game)
{
	ft_printf("%i\n", keycode); // NOTE: Delete after!
	if (keycode == KEY_ESCAPE)
		close_window(game);
	return (0);
}
