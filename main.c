/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbruen <dbruen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:16:09 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/19 17:19:02 by dbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	t_mega megastruct;
	int			fd;

	if (ac != 2 || (!(fd = open(av[1], O_RDONLY))))
		pizdec('a');
	megastruct.discriptor = mlx_init();
	megastruct.win = mlx_new_window(megastruct.discriptor, WIDTH, HIGHT, NAME);
	megastruct.coords = fdf_read(fd);
	megastruct.img = mlx_new_image(megastruct.discriptor, WIDTH, HIGHT);
	megastruct.data_adress = mlx_get_data_addr(megastruct.img, &megastruct.bits_per_pixel, &megastruct.size_line, &megastruct.endian);
	draw(&megastruct);
	mlx_hook(megastruct.win, 2, 0, keyboard, 0);
	mlx_loop(megastruct.discriptor);
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
