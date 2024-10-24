/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_duped.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:54:45 by ivbatist          #+#    #+#             */
/*   Updated: 2024/10/24 00:14:00 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_position_duped(t_data *gameinfo)
{
	int	y;
	int	x;

	y = 0;
	while (gameinfo->duped_map[y])
	{
		x = 0;
		while (gameinfo->duped_map[y][x])
		{
			if (gameinfo->duped_map[y][x] == 'P')
			{
				gameinfo->duped_positionx = x;
				gameinfo->duped_positiony = y;
			}
			x++;
		}
		y++;
	}
}
