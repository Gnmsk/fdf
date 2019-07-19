# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbruen <dbruen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/18 14:18:22 by tkelsie           #+#    #+#              #
#    Updated: 2019/07/19 17:24:41 by dbruen           ###   ########.fr        #
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
	gcc -o fdf main.c read.c keyboard.c struct_create.c libft/libft.a -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit

clean:
fclean: clean
re: fclean all
