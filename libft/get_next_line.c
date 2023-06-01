/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 00:07:50 by ivbatist          #+#    #+#             */
/*   Updated: 2022/12/03 00:08:16 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read(int fd, char *str)
{
	char	*array;
	int		count;

	array = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!array)
		return (NULL);
	count = 1;
	while (!ft_strchr(str, '\n') && count != 0)
	{
		count = read(fd, array, BUFFER_SIZE);
		if (count == -1)
		{
			free(array);
			return (NULL);
		}
		array[count] = '\0';
		str = ft_free_join(str, array);
	}
	free(array);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*s;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s = ft_read(fd, s);
	if (!s)
		return (NULL);
	line = ft_get_line(s);
	s = ft_new_line(s);
	return (line);
}

/*#include <fcntl.h>
int	main(void)
{
	int		fd;
	char	*prt;
	fd = open("files/test.txt", O_RDONLY);
	prt = get_next_line(fd);
	printf("\nFunc Return: %s\n", prt);
	free(prt);
	prt = get_next_line(fd);
	printf("\nFunc Return: %s\n", prt);
	free(prt);
	prt = get_next_line(fd);
	printf("\nFunc Return: %s\n", prt);
	free(prt);
	close(fd);
}*/
/*#include <fcntl.h>
int	main(void)
{
	int		fd;
	char	*prt;
	int		i = 0;
	fd = open("files/1-brouette.txt", O_RDONLY);
	printf("fd = %d\n", fd);
	while (i < 80)
	{
		prt = get_next_line(fd);
		printf("%s", prt);
		free(prt);
		i++;
	}
	close(fd);
}*/
/*#include <fcntl.h>
int	main(void)
{
	int		fd;
	char	*prt;
	int		i = 0;
	fd = open("files/42_no_nl", O_RDONLY);
	printf("fd = %d\n", fd);
	while (i < 1)
	{
		prt = get_next_line(fd);
		printf("%s", prt);
		free(prt);
		i++;
	}
	close(fd);
}*/
