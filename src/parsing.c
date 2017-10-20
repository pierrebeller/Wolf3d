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

void	read_init(int fd, t_wolf *e)
{
	char	*line;
	char	**splited;
	int		i;

	i = 0;
	if (get_next_line(fd, &line) < 1)
		error_map(e);
	splited = ft_strsplit(line, ' ');
	free(line);
	while (splited[i] != '\0')
		i++;
	if (i != 4)
		error_map(e);
	e->map_width = ft_atoi(splited[0]);
	e->map_heigth = ft_atoi(splited[1]);
	e->player.pos.x = ft_atoi(splited[2]) + 0.5;
	e->player.pos.y = ft_atoi(splited[3]) + 0.5;
	i = 0;
	while (splited[i] != '\0')
		free(splited[i++]);
	free(splited);
	if (e->map_heigth < 0 || e->map_width < 0 || e->player.pos.x < 0\
		|| e->player.pos.y < 0 || e->player.pos.x >= e->map_width ||\
		e->player.pos.y >= e->map_width)
		error_map(e);
}

void	read_line(char *line, int y, t_wolf *e, int **map)
{
	int		x;
	char	**splited;

	x = 0;
	if (y >= e->map_heigth)
		error_map(e);
	splited = ft_strsplit(line, ' ');
	map[y] = (int *)ft_x_malloc(sizeof(int *) * e->map_width);
	while (splited[x] != '\0')
	{
		if (!(splited[x][0] >= '0' && splited[x][0] <= '9' &&\
			ft_atoi(splited[x]) >= 0 && x < e->map_width))
			error_map(e);
		map[y][x] = ft_atoi(splited[x]);
		if ((x == 0 || x == e->map_width - 1 || y == 0 ||\
			y == e->map_heigth - 1) && map[y][x] == 0)
			error_map(e);
		free(splited[x]);
		x++;
	}
	free(splited[x]);
	free(splited);
	if (x != e->map_width)
		error_map(e);
}

int		read_map(int fd, t_wolf *e)
{
	char	*line;
	int		y;
	int		**map;

	y = 0;
	read_init(fd, e);
	map = (int **)ft_x_malloc(sizeof(int **) * e->map_heigth);
	while (get_next_line(fd, &line) == 1)
	{
		read_line(line, y, e, map);
		free(line);
		y++;
	}
	free(line);
	if (map[(int)e->player.pos.x][(int)e->player.pos.y] != 0)
		error_map(e);
	e->map = map;
	close(fd);
	return (1);
}

int		parsing(t_wolf *e, char *path)
{
	int	fd;

	fd = open(path, O_DIRECTORY);
	if (fd >= 0)
		return (0);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	return (read_map(fd, e));
}
