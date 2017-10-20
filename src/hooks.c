/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:05:52 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/19 10:05:54 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int			ft_quit(t_wolf *e)
{
	int		y;

	y = 0;
	if (e->ptr && e->win)
		mlx_destroy_window(e->ptr, e->win);
	exit(0);
}

int			key_move(int k, t_wolf *e)
{
	if (k == 13)
		e->player.move_forw = !e->player.move_forw;
	if (k == 1)
		e->player.move_back = !e->player.move_back;
	if (k == 0)
		e->player.move_left = !e->player.move_left;
	if (k == 2)
		e->player.move_right = !e->player.move_right;
	if (k == 49 && e->player.move_jump == 0)
		e->player.move_jump = 1;
	if (k == 53)
		ft_quit(e);
	return (0);
}

int			key_press(int k, t_wolf *e)
{
	key_move(k, e);
	return (0);
}

int			key_hook(int k, t_wolf *e)
{
	key_move(k, e);
	return (0);
}
