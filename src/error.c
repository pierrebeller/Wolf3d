#include "../include/wolf.h"

void		error_usage(t_wolf *e)
{
	ft_putstr_fd("Usage <filename> <map>\n", 2);
	exit (1);
}

void		error_map(t_wolf *e)
{
	ft_putstr_fd("Invalid map", 2);
	exit (1);
}