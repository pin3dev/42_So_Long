/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: xxxx/xx/xx xx:xx:xx by ivbatist          #+#    #+#             */
/*   Updated: 2023/05/30 13:46:24 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>
# include <limits.h>
// LIBFT
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t nitems, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
// GET_NEXT_LINE
char	*ft_new_line(char *s);
char	*ft_get_line(char *s);
char	*get_next_line(int fd);
char	*ft_read(int fd, char *str);
char	*ft_free_join(char *s1, char *s2);
// FT_PRINTF
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_print_hex(unsigned int n, int c);
int		ft_print_pointer(unsigned long long ptr);
int		ft_print_unsig(unsigned int n, int fd);
int		ft_putnbr(int n, int fd);
int		ft_printf(const char *format, ...);
int		ft_putchar_fd(char c, int fd);

#endif
