/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 17:32:44 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/20 17:32:45 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void		new_player(t_wolf *e)
{
	e->player.pos.x = 0;
	e->player.pos.y = 0;
	e->player.dir.x = -1;
	e->player.dir.y = 0;
	e->player.z = 0;
	e->player.plane.x = 0;
	e->player.plane.y = 0.66;
	e->player.speed_turn = 0.05;
	e->player.speed_move = 0.10;
	e->player.move_forw = 0;
	e->player.move_back = 0;
	e->player.move_right = 0;
	e->player.move_left = 0;
	e->player.move_jump = 0;
	e->player.is_jump = 0;
}

void		new_mlx(t_wolf *e)
{
	e->ptr = mlx_init();
	e->img = mlx_new_image(e->ptr, WIN_W, WIN_H);
	e->data = mlx_get_data_addr(e->img, &(e->color), &(e->size), &(e->endian));
}

t_wolf		*new_env(void)
{
	t_wolf	*e;

	e = (t_wolf *)ft_x_malloc(sizeof(t_wolf));
	e->width = WIN_W;
	e->heigth = WIN_H;
	new_player(e);
	new_mlx(e);
	e->color_1 = 0xff9600;
	e->color_2 = 0x73ff00;
	e->color_3 = 0xff00fc;
	e->color_4 = 0x46fffc;
	e->color_sky = 0x00cdff;
	e->color_floor = 0x2700ff;
	return (e);
}
