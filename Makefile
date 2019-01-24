# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/18 12:42:22 by jchardin          #+#    #+#              #
#    Updated: 2019/01/24 19:27:11 by jchardin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c  \
	file_math_util.c \
	file_mandelbrot.c \
	file_menu.c

OBJ = $(SRC:.c=.o)
OBJ_Dir = ./obj/
SRC_Dir = ./srcs/
CSources = $(addprefix $(SRC_Dir), $(SRC))
CObjects = $(addprefix $(OBJ_Dir), $(OBJ))
FLAGS = -Wall -Wextra -Werror
CC = gcc
INCLUDE = -I ./includes 
LIBRARY = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

$(NAME):$(CObjects)
	make -C ./libft
	$(CC) $(FLAGS) $(CObjects) -o $(NAME) $(INCLUDE) $(LIBRARY) ./libft/libft.a
	ctags -R .

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
	ctags -R .

.PHONY: all clean fclean re
