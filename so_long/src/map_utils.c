/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:01:27 by ivbatist          #+#    #+#             */
/*   Updated: 2024/10/24 00:15:54 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	windowsize(t_data *gameinfo)
{
	int	i;

	i = 0;
	gameinfo->windowx = 0;
	gameinfo->windowy = 0;
	while (gameinfo->map[0][i])
	{
		gameinfo->windowx++;
		i++;
	}
	i = 0;
	while (gameinfo->map[i])
	{
		gameinfo->windowy++;
		i++;
	}
}

void	clearmap(t_data *gameinfo)
{
	int	i;

	i = 0;
	while (gameinfo->map[i])
	{
		free(gameinfo->map[i]);
		i++;
	}
	free(gameinfo->map);
}
