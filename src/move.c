/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 16:25:03 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/19 16:25:18 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	move_forw(t_wolf *e)
{
	if (e->map[(int)(e->player.pos.x + e->player.dir.x *\
		e->player.speed_move)][(int)e->player.pos.y] == 0)
		e->player.pos.x += e->player.dir.x * e->player.speed_move;
	if (e->map[(int)e->player.pos.x][(int)(e->player.pos.y +\
		e->player.dir.y * e->player.speed_move)] == 0)
		e->player.pos.y += e->player.dir.y * e->player.speed_move;
}

void	move_back(t_wolf *e)
{
	if (e->map[(int)(e->player.pos.x - e->player.dir.x *\
		e->player.speed_move)][(int)e->player.pos.y] == 0)
		e->player.pos.x -= e->player.dir.x * e->player.speed_move;
	if (e->map[(int)e->player.pos.x][(int)(e->player.pos.y -\
		e->player.dir.y * e->player.speed_move)] == 0)
		e->player.pos.y -= e->player.dir.y * e->player.speed_move;
}

void	move_right(t_wolf *e)
{
	t_dxy	old;

	old.x = e->player.dir.x;
	e->player.dir.x = e->player.dir.x * cos(-e->player.speed_turn) -\
	e->player.dir.y * sin(-e->player.speed_turn);
	e->player.dir.y = old.x * sin(-e->player.speed_turn) + e->player.dir.y *\
	cos(-e->player.speed_turn);
	old.x = e->player.plane.x;
	e->player.plane.x = e->player.plane.x * cos(-e->player.speed_turn) -\
	e->player.plane.y * sin(-e->player.speed_turn);
	e->player.plane.y = old.x * sin(-e->player.speed_turn) +\
	e->player.plane.y * cos(-e->player.speed_turn);
}

void	move_left(t_wolf *e)
{
	t_dxy	old;

	old.x = e->player.dir.x;
	e->player.dir.x = e->player.dir.x * cos(e->player.speed_turn) -\
	e->player.dir.y * sin(e->player.speed_turn);
	e->player.dir.y = old.x * sin(e->player.speed_turn) + e->player.dir.y *\
	cos(e->player.speed_turn);
	old.x = e->player.plane.x;
	e->player.plane.x = e->player.plane.x * cos(e->player.speed_turn) -\
	e->player.plane.y * sin(e->player.speed_turn);
	e->player.plane.y = old.x * sin(e->player.speed_turn) + e->player.plane.y *\
	cos(e->player.speed_turn);
}


