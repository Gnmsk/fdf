/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:16:09 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/26 22:23:05 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

int		main(int ac, char **av)
{
	t_mega megastruct;

	if (ac != 2 || (!(megastruct.fd = open(av[1], O_RDONLY))))
		pizdec('a');
	megastruct.discriptor = mlx_init();
	megastruct.win = mlx_new_window(megastruct.discriptor, WIDTH, HIGHT, NAME);
	fdf_read(&megastruct);
	rotation(&megastruct);
	megastruct.img = mlx_new_image(megastruct.discriptor, WIDTH, HIGHT);
	megastruct.data_adress = (unsigned int *)mlx_get_data_addr(megastruct.img,
	&megastruct.bits_per_pixel, &megastruct.size_line, &megastruct.endian);
	fill_backgound(0, &megastruct);
	gradient(&megastruct);
	interface(&megastruct);
	draw(&megastruct);
	mlx_put_image_to_window(megastruct.discriptor, megastruct.win,
	megastruct.img, 20, 25);
	mlx_hook(megastruct.win, 2, 0, keyboard, &megastruct);
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

void		new_image(t_mega *megastruct)
{
	mlx_destroy_image(megastruct->discriptor, megastruct->img);
}
