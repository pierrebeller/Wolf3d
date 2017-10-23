/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 17:32:16 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/20 17:32:18 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int			ft_exit(t_wolf *e)
{
	mlx_destroy_image(e->ptr, e->img);	
	mlx_destroy_window(e->ptr, e->win);
	exit(0);
}

int			main(void)
{
	t_wolf	*e;

	e = new_env();
	parsing(e);
	e->win = mlx_new_window(e->ptr, WIN_W, WIN_H, "Wolf3d");
	mlx_do_key_autorepeatoff(e->ptr);
	mlx_loop_hook(e->ptr, loop_hook, e);
	mlx_hook(e->win, 2, (1L << 0), key_press, e);
	mlx_hook(e->win, 17, 0, ft_exit, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_loop(e->ptr);
	return (0);
}
