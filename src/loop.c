/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 12:58:27 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/19 12:58:29 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include <stdio.h>

int		loop_hook(t_wolf *e)
{
	if (e->player.move_forw)
		move_forw(e);
	if (e->player.move_back)
		move_back(e);
	if (e->player.move_left)
		move_left(e);
	if (e->player.move_right)
		move_right(e);
	raycasting(e);
	mlx_put_image_to_window(e->ptr, e->win, e->img, 0, 0);
	return (0);
}
