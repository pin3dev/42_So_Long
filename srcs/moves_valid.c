/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:01:06 by ivbatist          #+#    #+#             */
/*   Updated: 2023/05/26 13:01:09 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	moves_w(t_data *gameinfo, int x, int y)
{
	if (gameinfo->map[y - 1][x] == 'C')
	{
		gameinfo->map[y - 1][x] = '0';
		gameinfo->collected++;
	}
	if (gameinfo->map[y - 1][x] == 'E'
		&& gameinfo->collected == gameinfo->totalcollectables)
		error(1, gameinfo);
	if ((gameinfo->map[y - 1][x] == 'E'
		&& gameinfo->collected != gameinfo->totalcollectables))
		return (0);
	return (1);
}

int	moves_s(t_data *gameinfo, int x, int y)
{
	if (gameinfo->map[y + 1][x] == 'C')
	{
		gameinfo->map[y + 1][x] = '0';
		gameinfo->collected++;
	}
	if (gameinfo->map[y + 1][x] == 'E'
		&& gameinfo->collected == gameinfo->totalcollectables)
		error(1, gameinfo);
	if ((gameinfo->map[y + 1][x] == 'E'
		&& gameinfo->collected != gameinfo->totalcollectables))
		return (0);
	return (1);
}

int	moves_a(t_data *gameinfo, int x, int y)
{
	if (gameinfo->map[y][x - 1] == 'C')
	{
		gameinfo->map[y][x - 1] = '0';
		gameinfo->collected++;
	}
	if (gameinfo->map[y][x - 1] == 'E'
		&& gameinfo->collected == gameinfo->totalcollectables)
		error(1, gameinfo);
	if ((gameinfo->map[y][x - 1] == 'E'
		&& gameinfo->collected != gameinfo->totalcollectables))
		return (0);
	return (1);
}

int	moves_d(t_data *gameinfo, int x, int y)
{
	if (gameinfo->map[y][x + 1] == 'C')
	{
		gameinfo->map[y][x + 1] = '0';
		gameinfo->collected++;
	}
	if (gameinfo->map[y][x + 1] == 'E'
		&& gameinfo->collected == gameinfo->totalcollectables)
		error(1, gameinfo);
	if ((gameinfo->map[y][x + 1] == 'E'
		&& gameinfo->collected != gameinfo->totalcollectables))
		return (0);
	return (1);
}

int	move_isvalid(t_data *gameinfo, char type)
{
	int		x;
	int		y;
	int		r;

	x = gameinfo->positionx;
	y = gameinfo->positiony;
	r = 0;
	if (type == 'u' && gameinfo->map[y - 1][x] != '1')
		r = moves_w(gameinfo, x, y);
	else if (type == 'd' && gameinfo->map[y + 1][x] != '1')
		r = moves_s(gameinfo, x, y);
	else if (type == 'l' && gameinfo->map[y][x - 1] != '1')
		r = moves_a(gameinfo, x, y);
	else if (type == 'r' && gameinfo->map[y][x + 1] != '1')
		r = moves_d(gameinfo, x, y);
	return (r);
}
