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
#include <stdio.h>

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
	if (k == 53)
		ft_exit(e);
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
