/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_cont.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:00:50 by ivbatist          #+#    #+#             */
/*   Updated: 2024/10/24 00:15:54 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	swap_top(t_data *gameinfo, int y, int x, char type)
{
	char	swap;

	if (type == 'u' && gameinfo->map[y - 1][x] != '1')
	{
		swap = gameinfo->map[y][x];
		gameinfo->map[y][x] = gameinfo->map[y - 1][x];
		gameinfo->map[y - 1][x] = swap;
	}
	else if (type == 'd' && gameinfo->map[y + 1][x] != '1')
	{
		swap = gameinfo->map[y][x];
		gameinfo->map[y][x] = gameinfo->map[y + 1][x];
		gameinfo->map[y + 1][x] = swap;
	}
}

void	update_position(t_data *gameinfo, char type)
{
	int		x;
	int		y;
	char	swap;

	x = gameinfo->positionx;
	y = gameinfo->positiony;
	swap_top(gameinfo, y, x, type);
	if (type == 'l' && gameinfo->map[y][x - 1] != '1')
	{
		swap = gameinfo->map[y][x];
		gameinfo->map[y][x] = gameinfo->map[y][x - 1];
		gameinfo->map[y][x - 1] = swap;
	}
	else if (type == 'r' && gameinfo->map[y][x + 1] != '1')
	{
		swap = gameinfo->map[y][x];
		gameinfo->map[y][x] = gameinfo->map[y][x + 1];
		gameinfo->map[y][x + 1] = swap;
	}
}

void	find_position(t_data *gameinfo)
{
	int	y;
	int	x;

	y = 0;
	while (gameinfo->map[y])
	{
		x = 0;
		while (gameinfo->map[y][x])
		{
			if (gameinfo->map[y][x] == 'P')
			{
				gameinfo->positionx = x;
				gameinfo->positiony = y;
			}
			x++;
		}
		y++;
	}
}
