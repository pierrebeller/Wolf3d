#include "../include/wolf.h"

void		parsing_check(t_wolf *e, int ac, char **av)
{
	if (ac != 2)
		error_usage(e);
	e->path = av[1];
	if (parsing(e) == 0)
		error_map(e);
}

int			main(int ac, char **av)
{
	t_wolf	*e;

	e = new_env()
	parsing_check(e, ac, av);
	e->mlx.win = mlx_new_window(e->mlx.mlx, WIDTH, HEIGTH, "Wolf3d");
	mlx_hook(e->win, 2, (1L << 0), key_press, e);
	mlx_hook(e->win, 17, 0, ft_quit, e);
	return (0);
}