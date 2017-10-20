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

unsigned int	smog(unsigned int c, double d)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = c;
	g = c >> 8;
	b = c >> 16;
	d = 7 / (100 / d);
	if (d > 0.9)
		d = 0.9;
	if (r > 0)
		r = r - (r * d);
	if (g > 0)
		g = g - (g * d);
	if (b > 0)
		b = b - (b * d);
	return ((r << 16) + (g << 8) + b);
}

void			ft_draw(t_wolf *e, int x, int start, int finish)
{
	int		i;
	int		c;

	c = color(e);
	c = smog(c, e->ray.dist);
	i = -1;
	while (++i < start + e->player.z)
		pixel_put(e, x, i, e->color_sky);
	i--;
	while (++i <= finish + e->player.z && i < e->heigth)
		pixel_put(e, x, i, c);
	i--;
	while (++i < e->heigth)
		pixel_put(e, x, i, smog(e->color_floor, abs(i - e->heigth) * 0.040));
}
