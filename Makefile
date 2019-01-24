# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/18 12:42:22 by jchardin          #+#    #+#              #
#    Updated: 2019/01/24 14:57:52 by jchardin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c  \
	file_math_util.c \
	file_mlx_init.c \
	file_mandelbrot.c \
	file_julia.c \
	file_burning_ship.c \
	file_mandelbrot_seconde.c \
	file_menu.c

OBJ = $(SRC:.c=.o)
OBJ_Dir = ./obj/
SRC_Dir = ./srcs/
CSources = $(addprefix $(SRC_Dir), $(SRC))
CObjects = $(addprefix $(OBJ_Dir), $(OBJ))
FLAGS = -Wall -Wextra -Werror
CC = gcc -g
INCLUDE = -I ./includes 
LIBRARY = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

$(NAME):$(CObjects)
	make -C ./libft
	$(CC) $(FLAGS) $(CObjects) -o $(NAME) $(INCLUDE) $(LIBRARY) ./libft/libft.a

$(OBJ_Dir)%.o:$(SRC_Dir)%.c
	mkdir $(OBJ_Dir) 2> /dev/null || true
	$(CC) $(FLAGS) $(INCLUDE)  -c $< -o $@

clean:
	/bin/rm -rf $(CObjects)
	make fclean -C ./libft

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean $(NAME)

me: re

.PHONY: all clean fclean re
