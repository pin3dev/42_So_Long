# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 13:03:08 by ivbatist          #+#    #+#              #
#    Updated: 2023/06/01 19:29:25 by ivbatist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT	= ./libft/libft.a
LIBFT_DIR = ./libft

MINILIBX = ./minilibx-linux/libmlx_Linux.a
MINILIBX_DIR = ./minilibx-linux

CC	= cc -Wall -Wextra -Werror
RM	= rm -f

SRCSOLONG = 	./srcs/main.c ./srcs/map_extra.c ./srcs/errors.c ./srcs/map_checker_cont.c \
			./srcs/map_utils.c ./srcs/moves.c ./srcs/put_images.c ./srcs/path_checker.c \
		       	./srcs/flood_fill.c ./srcs/map_checker.c ./srcs/moves_cont.c ./srcs/moves_valid.c ./srcs/find_duped.c

NAME = so_long

all:	$(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MINILIBX):
	make -C $(MINILIBX_DIR)

$(NAME): $(LIBFT) $(MINILIBX)
	$(CC) -g $(SRCSOLONG) $(MINILIBX) -lXext -lX11 $(LIBFT) -o $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MINILIBX_DIR)

fclean:	clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re:	fclean all

.SILENT:
