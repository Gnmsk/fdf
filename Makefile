# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/18 14:18:22 by tkelsie           #+#    #+#              #
#    Updated: 2019/07/23 16:00:20 by tkelsie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
MLX = -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror 

all: 
	$(NAME)

$(NAME):
	make -C ./libft
	make -C ./minilibx_macos
	gcc $(FLAGS) -c 

mac:
	gcc -o fdf main.c read.c keyboard.c struct_create.c draw.c libft/libft.a -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit

linux:
	gcc -o linux main.c read.c keyboard.c struct_create.c draw.c libft/libft.a -L/usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11

clean:
fclean: clean
re: fclean all
