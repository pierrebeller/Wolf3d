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

void		parsing_check(t_wolf *e, int ac, char **av)
{
	if (ac != 2)
		error_usage(e);
	if (parsing(e, av[1]) == 0)
		error_map(e);
}

int			main(int ac, char **av)
{
	t_wolf	*e;

	e = new_env();
	parsing_check(e, ac, av);
	e->win = mlx_new_window(e->ptr, WIN_W, WIN_H, "Wolf3d");
	mlx_do_key_autorepeatoff(e->ptr);
	mlx_loop_hook(e->ptr, loop_hook, e);
	mlx_hook(e->win, 2, (1L << 0), key_press, e);
	mlx_hook(e->win, 17, 0, ft_exit, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_loop(e->ptr);
	return (0);
}
