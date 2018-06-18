# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwood <gwood@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/30 14:30:20 by mhurd             #+#    #+#              #
#    Updated: 2018/06/17 06:35:56 by gwood            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

SRC		= main.c \
		  parser.c \
		  renderer.c \
		  hooks.c

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

LIBFT	= ./libft/libft.a
LIBINC	= -I./libft
LIBLINK	= -L./libft -lft

MLX		= ./minilibx/libmlx.a
MLXINC	= -I./minilibx
MLXLINK	= -L./minilibx -lmlx -framework OpenGL -framework AppKit

LIBGFX		= ./libgfx/libgfx.a
LIBGFXINC	= -I./libgfx
LIBGFXLINK	= -L./libgfx -lgfx

SRCDIR	= ./src/
INCDIR	= ./includes/
OBJDIR	= ./obj/

all: obj libft mlx libgfx $(NAME)

gfx:
	rm -rf $(NAME)
	rm -rf $(OBJDIR)
	make -C ./libgfx fclean
	make

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(LIBINC) $(MLXINC) $(LIBGFXINC) -I $(INCDIR) -o $@ -c $<

libft: $(LIBFT)

mlx: $(MLX)

libgfx: $(LIBGFX)

$(LIBFT):
	make -C ./libft

$(MLX):
	make -C ./minilibx

$(LIBGFX):
	make -C ./libgfx

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(MLXLINK) $(LIBGFXLINK) $(LIBLINK)

clean:
	rm -rf $(OBJDIR)
	make -C ./libft clean
	make -C ./minilibx clean
	make -C ./libgfx clean

fclean: clean
	rm -rf $(NAME)
	make -C ./libft fclean
	make -C ./libgfx fclean

re: fclean all
