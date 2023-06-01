# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: xxxx/xx/xx xx:xx:xx by ivbatist          #+#    #+#              #
#    Updated: 2023/05/30 13:52:26 by ivbatist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME                    = libft.a

SRCS			= ft_strlen.c ft_calloc.c ft_substr.c \
			  ft_strjoin.c ft_split.c ft_printf.c \
			  ft_print_hex.c ft_print_pointer.c \
			  ft_print_unsig.c ft_putchar.c \
			  ft_putnbr.c ft_putstr.c ft_strdup.c \
			  get_next_line.c get_next_line_utils.c

OBJS			= $(SRCS:.c=.o)

CC			= cc
AR			= ar rcs
RM			= rm -f
CFLAGS			= -Wall -Wextra -Werror

 
MSG1                    = @echo "Libft, Printf & GNL Compilation complete"
MSG2                    = @echo "Libft, Prinf & GNL Cleaning complete"
MSG3					= @echo "Libft, Printf & GNL ReCompilation complete"


$(NAME):		$(OBJS)
				$(AR) $(NAME) $(OBJS)
				$(MSG1)

all:                    $(NAME)

clean:
				$(RM) $(OBJS) 
				$(MSG2)

fclean:			clean
				$(RM) $(NAME)
				$(MSG2)


re:			fclean all
				$(MSG3)

.PHONY:			all clean fclean re bonus
