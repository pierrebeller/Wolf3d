/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 17:32:29 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/20 17:32:30 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	build_wall(t_wolf *e)
{
	int i;

	i = 0;
	while (i <= 20)
	{
		if (i % 3 == 0)
		{
			e->map[i][i] = 1;
			e->map[i + 1][i] = 1;
			e->map[i][i + 1] = 1;
		}
		e->map[i][0] = 1;
		e->map[i][20] = 1;
		e->map[0][i] = 1;
		e->map[20][i] = 1;
		i++;
	}
}

void	build_floor(t_wolf *e)
{
	int x;
	int y;

	y = 0;
	e->map = (int **)ft_x_malloc(sizeof(int *) * 21);
	while (y <= 20)
	{
		x = 0;
		e->map[y] = (int *)ft_x_malloc(sizeof(int) * 21);
		while (x <= 20)
		{
			e->map[y][x] = 0;
			x++;
		}
		y++;
	}
}

void	parsing(t_wolf *e)
{
	build_floor(e);
	build_wall(e);
	e->map_width = 21;
	e->map_heigth = 21;
}
