/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:58:53 by ivbatist          #+#    #+#             */
/*   Updated: 2024/10/24 15:14:46 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keys(int key, t_data *gameinfo)
{
	if (key == KEY_ESC)
		error(1, gameinfo);
	else
		moves(key, gameinfo);
	return (0);
}

int	x_button(t_data *gameinfo)
{
	exit_clean(gameinfo);
	return (0);
}

void	start_mlx(t_data *gameinfo)
{
	gameinfo->collected = 0;
	gameinfo->mlx = mlx_init();
	if (gameinfo->mlx == NULL)
	{
		ft_printf("Error\n");
		ft_printf("Error initializing mlx\n");
		exit(0);
	}
	gameinfo->mlx_window = mlx_new_window(gameinfo->mlx, gameinfo->windowx * 64,
			gameinfo->windowy * 64, "so_long");
	if (gameinfo->mlx_window == NULL)
	{
		ft_printf("Error\n");
		ft_printf("Error creating window\n");
		exit(0);
	}
	drawmap(gameinfo);
	mlx_hook(gameinfo->mlx_window, 17, (1L << 0), x_button, gameinfo);
	mlx_key_hook(gameinfo->mlx_window, &keys, gameinfo);
	//mlx_hook(gameinfo->mlx_window, 2, 1L<<0, keys, gameinfo);
	mlx_loop(gameinfo->mlx);
}

void	ck_type(char *type)
{
	char	*tmp;
	size_t	i;
	int		j;

	j = 0;
	tmp = ".ber";
	i = 0;
	while (i < ft_strlen(type) - 4)
		i++;
	while (i < ft_strlen(type))
	{
		if (type[i] != tmp[j])
		{
			ft_printf("Error\n");
			ft_printf("Wrong map file, try .ber");
			exit(0);
		}
		i++;
		j++;
	}
}

int	main(int ac, char **av)
{
	t_data	gameinfo;

	gameinfo.moves = 0;
	if (ac == 2)
	{
		ck_type(av[1]);
		read_map(av[1], &gameinfo);
		if (gameinfo.map[0] == NULL)
			error(0, &gameinfo);
		windowsize(&gameinfo);
		check_map(&gameinfo);
		ft_printf("Moves: %d\n", gameinfo.moves);
		start_mlx(&gameinfo);
		clearmap(&gameinfo);
	}
	else
		ft_printf("Error\n");
	return (0);
}
