# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 13:03:08 by ivbatist          #+#    #+#              #
#    Updated: 2024/10/25 01:18:21 by pin3dev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED=\033[0;31m
GREEN=\033[0;32m
RESET=\033[0m
BKGRAY=\033[47;90m
BKGRAYGREEN=\033[1;92m
BKGRAYRED=\033[1;91m

################################################################################
# 									Executable	 	 						   #
################################################################################

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
	MINILIBX_REPO = git@github.com:pin3dev/42_minilibx-macos.git
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

all: $(LIBFT) $(PRINTF) $(GNL) $(MINILIBX) $(OBJDIR) $(NAME)

clean:
	@$(RM) $(OBJS)
	@if [ -d "$(OBJDIR)" ]; then $(RMD) $(OBJDIR); fi
	@echo "${BKGRAY}So_Long:${BKGRAYRED}- Obj${RESET}"

fclean: clean
	@$(RM) $(NAME)
	@echo "${BKGRAY}So_Long: ${BKGRAYRED}- Exec${RESET}"

re: fclean all

################################################################################
# 							Dependencies Targets							   #
################################################################################

$(LIBFT):
	@if [ ! -d $(LIBFT_DIR) ]; then \
		git clone $(LIBFT_REPO) ../../42_Libft > /dev/null 2>&1; \
	fi
	@printf "${BKGRAY}Libft:${RESET} "; 
	@$(MAKE) -C $(LIBFT_DIR) all

$(PRINTF):
	@if [ ! -d $(PRINTF_DIR) ]; then \
		git clone $(PRINTF_REPO) ../../42_ft_Printf > /dev/null 2>&1; \
	fi
	@printf "${BKGRAY}Printf:${RESET} "; 
	@$(MAKE) -C $(PRINTF_DIR) all

$(GNL):
	@if [ ! -d $(GNL_DIR) ]; then \
		git clone $(GNL_REPO) ../../42_GetNextLine > /dev/null 2>&1; \
	fi
	@printf "${BKGRAY}GNL:${RESET} "; 
	@$(MAKE) -C $(GNL_DIR) all

$(MINILIBX):
	@if [ ! -d $(MINILIBX_DIR) ]; then \
		git clone $(MINILIBX_REPO) $(MINILIBX_DIR) > /dev/null 2>&1; \
	fi
	@printf "${BKGRAY}MLX:${RESET} "; 
	@$(MAKE) -C $(MINILIBX_DIR)
	
################################################################################
# 						Auto Targets 				 						   #
################################################################################

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(MINILIBX) $(GNL)
	@$(CC) $(CFLAGS) $(OBJS) $(MINILIBX) $(MLX_FLAGS) $(MLX_EXTRA) $(LIBFT) $(PRINTF)  $(GNL) -o $(NAME) & \
	./gui_load.sh "So_Long"
	@wait

################################################################################
# 										PS		 	 						   #
################################################################################

.PHONY: all clean fclean re
