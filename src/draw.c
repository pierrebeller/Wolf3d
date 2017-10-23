/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 14:38:55 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/19 14:38:58 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void			pixel_put(t_wolf *e, int x, int y, int c)
{
	int		i;

	i = (x * 4) + (y * e->size);
	e->data[i] = c;
	e->data[++i] = c >> 8;
	e->data[++i] = c >> 16;
}

int				color(t_wolf *e)
{
	if (e->ray.hit_side == 1)
	{
		if ((e->ray.step.x == -1 && e->ray.step.y == -1) ||\
			(e->ray.step.x == 1 && e->ray.step.y == -1))
			return (e->color_1);
		if ((e->ray.step.x == -1 && e->ray.step.y == 1) ||\
			(e->ray.step.x == 1 && e->ray.step.y == 1))
			return (e->color_2);
	}
	if ((e->ray.step.x == -1 && e->ray.step.y == -1) ||\
		(e->ray.step.x == -1 && e->ray.step.y == 1))
		return (e->color_3);
	return (e->color_4);
}

void			ft_draw(t_wolf *e, int x, int start, int finish)
{
	int		i;
	int		c;

	c = color(e);
	i = -1;
	while (++i < start)
		pixel_put(e, x, i, e->color_sky);
	i--;
	while (++i <= finish && i < e->heigth)
		pixel_put(e, x, i, c);
	i--;
	while (++i < e->heigth)
		pixel_put(e, x, i, e->color_floor);
}
