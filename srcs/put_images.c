/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:52:06 by ivbatist          #+#    #+#             */
/*   Updated: 2023/05/26 12:52:10 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	drawmap_extra(t_data *gameinfo, int y, int x)
{
	if (gameinfo->map[y][x] == '1')
		mlx_put_image_to_window(gameinfo->mlx, gameinfo->mlx_window,
			gameinfo->img_wall, x * 64, y * 64);
	else if (gameinfo->map[y][x] == '0')
		mlx_put_image_to_window(gameinfo->mlx, gameinfo->mlx_window,
			gameinfo->img_floor, x * 64, y * 64);
	else if (gameinfo->map[y][x] == 'P')
		mlx_put_image_to_window(gameinfo->mlx, gameinfo->mlx_window,
			gameinfo->img_player, x * 64, y * 64);
	else if (gameinfo->map[y][x] == 'C')
		mlx_put_image_to_window(gameinfo->mlx, gameinfo->mlx_window,
			gameinfo->img_collect, x * 64, y * 64);
	else if (gameinfo->map[y][x] == 'E')
		mlx_put_image_to_window(gameinfo->mlx, gameinfo->mlx_window,
			gameinfo->img_exit, x * 64, y * 64);
}

void	drawmap(t_data *gameinfo)
{
	int	x;
	int	y;

	load_images(gameinfo);
	y = 0;
	while (gameinfo->map[y])
	{
		x = 0;
		while (gameinfo->map[y][x])
		{
			drawmap_extra(gameinfo, y, x);
			x++;
		}
		y++;
	}
}
