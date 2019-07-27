# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/18 14:18:22 by tkelsie           #+#    #+#              #
#    Updated: 2019/07/27 17:49:53 by tkelsie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
MLX = -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror 
SRCS = ./srcs/main.c \
./srcs/read.c \
./srcs/keyboard.c \
./srcs/struct_create.c \
./srcs/draw.c \
./srcs/coloring.c \
./srcs/rotation.c \
./srcs/window.c

all: 
	$(NAME)

$(NAME):
	make -C ./libft
	make -C ./minilibx_macos
	gcc $(FLAGS) -c 

mac:
	gcc -o fdf $(SRCS) ./srcs/libft/libft.a -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit

linux:
	gcc -o linux $(SRCS) libft/libft.a -L/usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11

clean:
fclean: clean
re: fclean all
