/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:02:27 by ivbatist          #+#    #+#             */
/*   Updated: 2023/05/26 13:02:30 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	clear_duped(t_data *gameinfo)
{
	int	i;

	i = 0;
	while (i < gameinfo->windowy)
	{
		free(gameinfo->duped_map[i]);
		i++;
	}
	free(gameinfo->duped_map);
}

void	copy_map(t_data *gameinfo, char **temp)
{
	int	i;
	int	j;

	i = 0;
	while (gameinfo->map[i])
	{
		j = 0;
		while (gameinfo->map[i][j])
		{
			temp[i][j] = gameinfo->map[i][j];
			j++;
		}
		temp[i][j] = '\0';
		i++;
	}
	gameinfo->duped_map = temp;
}

void	dupe_map(t_data *gameinfo)
{
	char	**temp;
	int		i;

	i = 0;
	temp = (char **)ft_calloc(gameinfo->windowy + 1, sizeof(char *));
	if (!temp)
		return ;
	while (i < gameinfo->windowy)
	{
		temp[i] = malloc((gameinfo->windowx + 1) * sizeof(char ));
		i++;
	}
	copy_map(gameinfo, temp);
}

void	check_path(t_data *gameinfo)
{
	flood_fill(gameinfo);
}
