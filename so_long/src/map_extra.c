/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_extra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:02:06 by ivbatist          #+#    #+#             */
/*   Updated: 2024/10/24 13:33:47 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	load_images(t_data *gameinfo)
{
	int	x;
	int	y;

	y = 64;
	x = 64;
	gameinfo->imagex = &x;
	gameinfo->imagey = &y;
	gameinfo->img_player = mlx_xpm_file_to_image
		(gameinfo->mlx, "./assets/sprites/player1.xpm",
			gameinfo->imagex, gameinfo->imagey);
	gameinfo->img_wall = mlx_xpm_file_to_image
		(gameinfo->mlx, "./assets/sprites/wall.xpm",
			gameinfo->imagex, gameinfo->imagey);
	gameinfo->img_collect = mlx_xpm_file_to_image
		(gameinfo->mlx, "./assets/sprites/collect.xpm",
			gameinfo->imagex, gameinfo->imagey);
	gameinfo->img_exit = mlx_xpm_file_to_image
		(gameinfo->mlx, "./assets/sprites/exit.xpm",
			gameinfo->imagex, gameinfo->imagey);
	gameinfo->img_floor = mlx_xpm_file_to_image
		(gameinfo->mlx, "./assets/sprites/floor.xpm",
			gameinfo->imagex, gameinfo->imagey);
	if (gameinfo->img_player == NULL || gameinfo->img_wall == NULL || \
		gameinfo->img_collect == NULL || gameinfo->img_exit == NULL || \
		gameinfo->img_floor == NULL)
	{
		ft_printf("Error\n");
		ft_printf("Error loading images\n");
		exit(0);
	}
}

void	check_empty_line(char *line, t_data *gameinfo)
{
	int	i;

	i = 0;
	gameinfo->emptyline = 0;
	while (line[i])
	{
		if (line[0] == '\n')
			gameinfo->emptyline = 1;
		if (line[i] == '\n' && line[i + 1] == '\n')
			gameinfo->emptyline = 1;
		i++;
	}
	i = 0;
	while (line[i])
		i++;
	if (i == 0)
	{
		free(line);
		error(0, gameinfo);
		exit(1);
	}
}

void	read_map(char *filepath, t_data *gameinfo)
{
	int		fd;
	char	*line;
	char	*all_lines;
	char	*temp;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		error(0, gameinfo);
	all_lines = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = all_lines;
		all_lines = ft_strjoin(temp, line);
		free(line);
		free(temp);
	}
	close(fd);
	check_empty_line(all_lines, gameinfo);
	gameinfo->map = ft_split(all_lines, '\n');
	free(all_lines);
}
