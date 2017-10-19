#ifndef WOLF_H
# define WOLF_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>

# define WIDTH 800
# define HEIGTH 600

typedef	struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			color;
	int			size;
	int			endian;

}				t_mlx;

typedef struct	s_player
{
	t_dpoint	*pos;
	t_dpoint	*dir;
	t_dpoint	*plane;
}				t_player;

typedef struct	s_ray
{
	t_dpoint	*pos;
	t_dpoint	*dir;
	t_dpoint	*map;
}				t_ray;

typedef	struct	s_wolf
{
	t_mlx		mlx;
	t_player	player;
	t_ray		ray;
	char		*path;
	int			color_1;
	int			color_2;
	int			color_3;
	int			color_4;
	int			color_sky;
	int			color_floor;
}				t_wolf;
