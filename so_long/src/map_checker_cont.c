/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_cont.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:51:53 by ivbatist          #+#    #+#             */
/*   Updated: 2024/10/24 00:15:54 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	check_empty(t_data *gameinfo)
{
	int	x;
	int	y;

	y = 0;
	while (gameinfo->map[y])
	{
		x = 0;
		while (gameinfo->map[y][x])
		{
			if (gameinfo->map[y][x] != 'P' && gameinfo->map[y][x] != 'E' &&
				gameinfo->map[y][x] != '0' && gameinfo->map[y][x] != 'C' &&
				gameinfo->map[y][x] != '1')
				error(2, gameinfo);
			x++;
		}
		y++;
	}
}

void	check_rectangle(t_data *gameinfo)
{
	int	x;
	int	y;
	int	i;
	int	j;

	y = 0;
	j = 0;
	while (gameinfo->map[y])
	{
		x = 0;
		i = 0;
		while (gameinfo->map[y][x])
		{
			i++;
			x++;
		}
		if (i != gameinfo->windowx)
			error(2, gameinfo);
		j++;
		y++;
	}
	if (j != gameinfo->windowy)
		error(2, gameinfo);
}
