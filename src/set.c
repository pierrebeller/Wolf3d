#include "../include/wolf.h"

void		new_player(t_wolf *e)
{
	e->player->pos->x = 0;
	e->player->pos->y = 0;
	e->player->dir->x = 0;
	e->player->dir->y = 0;
	e->player->plane->x = 0;
	e->player->plane->y = 0.66;
}

void		new_mlx(t_wolf *e)
{
	e->mlx.mlx = mlx_init;
	e->mlx.win = mlx_new_window(e->mlx.mlx, WIDTH, HEIGTH, "Wolf3d");
	e->mlx.img = mlx_new_image(e->mlx.mlx, WIDTH, HEIGTH);
	e->mlx.data = mlx_get_data_addr(e->mlx.img, &(window->color),\
		&(window->size), &(window->endian));
}

t_wolf		*new_env(void)
{
	t_wolf	*e;

	e = ft_xmalloc(sizeof(t_wolf));
	e->width = WIDTH;
	e->heigth = HEIGTH;
	new_player(e);
	new_mlx(e);
	e->color_1 = 0xff9600;
	e->color_2 = 0x73ff00;
	e->color_3 = 0xff00fc;
	e->color_4 = 0x46fffc;
	e->color_sky = 0x00cdff;
	e->color_floor = 0x2700ff;
	return (e);
}