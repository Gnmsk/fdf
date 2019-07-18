/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:16:09 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/18 14:17:16 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	t_okno		window;
	t_stroka	*argv_postrochno;
	int			fd;

	if (ac != 2 || (!(fd = open(av[1], O_RDONLY))))
		pizdec('a');
	window.discriptor = mlx_init();
	window.win = mlx_new_window(window.discriptor, WIDTH, HIGHT, NAME);
	fdf_read(fd, window, &argv_postrochno);
	mlx_hook(window.win, 2, 0, keyboard, 0);
	mlx_loop(window.discriptor);
	zbs();
	return (0);
}

void	pizdec(char i)
{
	write(1, "error ", 6);
	write(1, &i, 1);
	exit(0);
}

void	zbs(void)
{
	exit(0);
}
