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
	gcc -o fdf main.c read.c keyboard.c get_next_line.c struct_create.c libft/libft.a -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit

clean:
fclean: clean
re: fclean all