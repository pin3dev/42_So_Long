# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 13:03:08 by ivbatist          #+#    #+#              #
#    Updated: 2024/10/24 16:33:48 by pin3dev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

################################################################################
# 							Dir	Path	Variables 							   #
################################################################################

SRCDIR = src
OBJDIR = obj

################################################################################
# 						Compiler and Flags	Variables						   #
################################################################################

CC = cc
CFLAGS = -Wall -Wextra -Werror -I inc -I $(LIBFT_DIR)/inc -I $(PRINTF_DIR)/inc -I $(GNL_DIR)/inc
RM = rm -f
RMD = rm -rf

################################################################################
# 							Libft Variables 								   #
################################################################################

LIBFT_DIR = ../../42_Libft/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_REPO = git@github.com:pin3dev/42_Libft.git

################################################################################
# 					  			Printf Variables 							   #
################################################################################

PRINTF_DIR = ../../42_ft_Printf/printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
PRINTF_REPO = git@github.com:pin3dev/42_ft_Printf.git

################################################################################
# 					  			Gnl Variables 								   #
################################################################################

GNL_DIR = ../../42_GetNextLine/gnl
GNL = $(GNL_DIR)/libgnl.a
GNL_REPO = git@github.com:pin3dev/42_GetNextLine.git

################################################################################
# 					  			Minilbx Variables 								   #
################################################################################

#MINILIBX_DIR = ../../minilibx-linux
#MINILIBX = $(MINILIBX_DIR)/libmlx_Linux.a
#MINILIBX_REPO = git@github.com:42Paris/minilibx-linux.git


UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	MINILIBX_DIR = ../../minilibx-linux
	MINILIBX = $(MINILIBX_DIR)/libmlx_Linux.a
	MINILIBX_REPO = git@github.com:42Paris/minilibx-linux.git
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
	MLX_EXTRA = -lm -lbsd
	CFLAGS += -I/usr/include -I$(MINILIBX_DIR)
else ifeq ($(UNAME), Darwin)
	MINILIBX_DIR = ../../minilibx-macos
	MINILIBX = $(MINILIBX_DIR)/libmlx_OpenBSD.a
	MINILIBX_REPO = git@github.com:dannywillems/minilibx-mac-osx.git
	MLX_FLAGS = -L$(MINILIBX_DIR) -lmlx_intel-mac -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
	CFLAGS += -I/opt/X11/include -I$(MINILIBX_DIR)
endif

################################################################################
# 							Files	Path	Variables 						   #
################################################################################

SRC =   $(SRCDIR)/so_long.c \
        $(SRCDIR)/map_extra.c \
		$(SRCDIR)/errors.c \
        $(SRCDIR)/map_checker_cont.c \
        $(SRCDIR)/map_utils.c \
        $(SRCDIR)/moves.c \
        $(SRCDIR)/put_images.c \
        $(SRCDIR)/path_checker.c \
        $(SRCDIR)/flood_fill.c \
        $(SRCDIR)/map_checker.c \
		$(SRCDIR)/moves_valid.c \
        $(SRCDIR)/moves_cont.c \
        $(SRCDIR)/find_duped.c \

OBJS = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

################################################################################
# 							Manual	Targets		 							   #
################################################################################

all: $(OBJDIR) $(LIBFT) $(PRINTF) $(GNL) $(MINILIBX) $(NAME)

clean:
	@$(RM) $(OBJS)
#	@$(MAKE) -C $(GNL_DIR) clean
#	@$(MAKE) -C $(PRINTF_DIR) clean
#	@$(MAKE) -C $(MINILIBX_DIR) clean
	@echo "Arquivos objetos removidos"

fclean: clean
	@$(RM) $(NAME)
	@$(RMD) $(OBJDIR)
# @$(MAKE) -C $(MINILIBX_DIR) fclean
#	@$(RMD) ../../42_Libft
#	@$(RMD) ../../42_GetNextLine
#	@$(RMD) ../../42_ft_Printf
#	@$(RMD) ../../minilibx-linux
	@echo "$(NAME) e dependências removidos"

re: fclean all


################################################################################
# 							Dependencies Targets							   #
################################################################################

$(LIBFT):
	@if [ ! -d $(LIBFT_DIR) ]; then \
		echo "Clonando Libft..."; \
		git clone $(LIBFT_REPO) ../../42_Libft; \
	fi
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	@if [ ! -d $(PRINTF_DIR) ]; then \
		echo "Clonando ft_Printf..."; \
		git clone $(PRINTF_REPO) ../../42_ft_Printf; \
	fi
	@$(MAKE) -C $(PRINTF_DIR)

$(MINILIBX):
	@if [ ! -d $(MINILIBX_DIR) ]; then \
		echo "Clonando MiniLibX..."; \
		git clone $(MINILIBX_REPO) $(MINILIBX_DIR); \
	fi
	@$(MAKE) -C $(MINILIBX_DIR)

$(GNL):
	@if [ ! -d $(GNL_DIR) ]; then \
		echo "Clonando GetNextLine..."; \
		git clone $(GNL_REPO) ../../42_GetNextLine; \
	fi
	@$(MAKE) -C $(GNL_DIR)

################################################################################
# 						Auto Targets 				 						   #
################################################################################


$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(MINILIBX) $(GNL)
	$(CC) $(CFLAGS) $(OBJS) $(MINILIBX) $(MLX_FLAGS) $(MLX_EXTRA) $(LIBFT) $(PRINTF)  $(GNL) -o $(NAME)
	@echo "$(NAME) compilado com sucesso!"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compilado $< em $@"

################################################################################
# 										PS		 	 						   #
################################################################################

.PHONY: all clean fclean re

#$(CC) $(CFLAGS) $(OBJS) $(MINILIBX) -lXext -lX11 $(LIBFT) $(GNL) -o $(NAME)