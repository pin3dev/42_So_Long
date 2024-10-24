/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:00:37 by ivbatist          #+#    #+#             */
/*   Updated: 2024/10/24 13:35:42 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	move_w(t_data *gameinfo)
{
	find_position(gameinfo);
	if (move_isvalid(gameinfo, 'u') == 1)
	{
		mlx_put_image_to_window(gameinfo->mlx, gameinfo->mlx_window,
			gameinfo->img_floor, gameinfo->positionx * 64,
			gameinfo->positiony * 64);
		mlx_put_image_to_window(gameinfo->mlx, gameinfo->mlx_window,
			gameinfo->img_player, gameinfo->positionx * 64,
			(gameinfo->positiony - 1) * 64);
		update_position(gameinfo, 'u');
		gameinfo->moves++;
		ft_printf("Moves: %d\n", gameinfo->moves);
	}
}

void	move_s(t_data *gameinfo)
{
	find_position(gameinfo);
	if (move_isvalid(gameinfo, 'd') == 1)
	{
		mlx_put_image_to_window(gameinfo->mlx, gameinfo->mlx_window,
			gameinfo->img_floor, gameinfo->positionx * 64,
			gameinfo->positiony * 64);
		mlx_put_image_to_window(gameinfo->mlx, gameinfo->mlx_window,
			gameinfo->img_player, gameinfo->positionx * 64,
			(gameinfo->positiony + 1) * 64);
		update_position(gameinfo, 'd');
		gameinfo->moves++;
		ft_printf("Moves: %d\n", gameinfo->moves);
	}
}

void	move_a(t_data *gameinfo)
{
	find_position(gameinfo);
	if (move_isvalid(gameinfo, 'l') == 1)
	{
		mlx_put_image_to_window(gameinfo->mlx, gameinfo->mlx_window,
			gameinfo->img_floor, gameinfo->positionx * 64,
			gameinfo->positiony * 64);
		mlx_put_image_to_window(gameinfo->mlx, gameinfo->mlx_window,
			gameinfo->img_player, (gameinfo->positionx - 1) * 64,
			gameinfo->positiony * 64);
		update_position(gameinfo, 'l');
		gameinfo->moves++;
		ft_printf("Moves: %d\n", gameinfo->moves);
	}
}

void	move_d(t_data *gameinfo)
{
	find_position(gameinfo);
	if (move_isvalid(gameinfo, 'r') == 1)
	{
		mlx_put_image_to_window(gameinfo->mlx, gameinfo->mlx_window,
			gameinfo->img_floor, gameinfo->positionx * 64,
			gameinfo->positiony * 64);
		mlx_put_image_to_window(gameinfo->mlx, gameinfo->mlx_window,
			gameinfo->img_player, (gameinfo->positionx + 1) * 64,
			gameinfo->positiony * 64);
		update_position(gameinfo, 'r');
		gameinfo->moves++;
		ft_printf("Moves: %d\n", gameinfo->moves);
	}
}

void	moves(int key, t_data *gameinfo)
{
	if (key == KEY_UP)
		move_w(gameinfo);
	else if (key == KEY_DOWN)
		move_s(gameinfo);
	else if (key == KEY_LEFT)
		move_a(gameinfo);
	else if (key == KEY_RIGHT)
		move_d(gameinfo);
}
