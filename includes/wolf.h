/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 20:25:31 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/20 20:25:34 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define WIN_W 1280
# define WIN_H 800

typedef struct		s_dxy
{
	double			x;
	double			y;
}					t_dxy;

typedef struct		s_ixy
{
	int				x;
	int				y;
}					t_ixy;

typedef struct		s_player
{
	t_dxy			pos;
	t_dxy			dir;
	t_dxy			plane;
	char			move_forw;
	char			move_back;
	char			move_left;
	char			move_right;
	double			speed_turn;
	double			speed_move;
}					t_player;

typedef struct		s_ray
{
	t_dxy			pos;
	t_dxy			dir;
	t_ixy			map;
	t_ixy			step;
	t_dxy			delta;
	t_dxy			side;
	double			dist;
	double			cam;
	int				hit;
	int				hit_side;
}					t_ray;

typedef	struct		s_wolf
{
	t_player		player;
	t_ray			ray;
	void			*ptr;
	void			*win;
	void			*img;
	char			*data;
	int				color;
	int				size;
	int				endian;
	int				**map;
	int				map_width;
	int				map_heigth;
	int				width;
	int				heigth;
	unsigned int	color_1;
	unsigned int	color_2;
	unsigned int	color_3;
	unsigned int	color_4;
	unsigned int	color_sky;
	unsigned int	color_floor;
}					t_wolf;

int					ft_exit(t_wolf *e);
void				error_usage(t_wolf *e);
void				error_map(t_wolf *e);

void				parsing(t_wolf *e);

t_wolf				*new_env(void);

void				ft_set_hooks(t_wolf *e);
int					ft_quit(t_wolf *e);
int					key_press(int k, t_wolf *e);
int					key_hook(int k, t_wolf *e);

int					loop_hook(t_wolf *e);

void				raycasting(t_wolf *e);

void				move_left(t_wolf *e);
void				move_right(t_wolf *e);
void				move_back(t_wolf *e);
void				move_forw(t_wolf *e);
void				move_jump(t_wolf *e);

void				ft_draw(t_wolf *e, int x, int start, int finish);
#endif
