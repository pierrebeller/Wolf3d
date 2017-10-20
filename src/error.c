/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 17:32:00 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/20 17:32:03 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void		error_usage(t_wolf *e)
{
	ft_putstr_fd("Usage <filename> <map>\n", 2);
	ft_quit(e);
	exit(1);
}

void		error_map(t_wolf *e)
{
	ft_putstr_fd("Invalid map", 2);
	ft_quit(e);
	exit(1);
}
