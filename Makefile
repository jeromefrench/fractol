# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/18 12:42:22 by jchardin          #+#    #+#              #
#    Updated: 2019/01/22 18:57:16 by jchardin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c  \
	file_math_util.c \
	file_mlx_init.c \
	file_mandelbrot.c \
	file_julia.c \
	file_burning_ship.c

SRC_Dir = ./srcs/
C_Sources = $(addprefix $(SRC_Dir),$(SRC))

INCLUDE = -I ./includes/
LIBRARY = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit



CC = gcc
DEBUG = -g
FLAG = -Wall -Wextra -Werror

all:
	clear
	$(CC) $(DEBUG) $(DEBUG)  $(INCLUDE) $(LIBRARY) $(C_Sources) -o $(NAME) ./libft/libft.a



