/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:16:09 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/27 20:42:16 by tkelsie          ###   ########.fr       */
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
	megastruct.img = mlx_new_image(megastruct.discriptor, WIDTH, HIGHT);
	megastruct.data_adress = (unsigned int *)mlx_get_data_addr(megastruct.img,
	&megastruct.bits_per_pixel, &megastruct.size_line, &megastruct.endian);
	gradient(&megastruct);
	default_state(&megastruct);
	display_map(&megastruct);
	mlx_hook(megastruct.win, 2, 0, keyboard, &megastruct);
	mlx_hook(megastruct.win, 17, 0, close_window, &megastruct);
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

void	valid(t_mega *megastruct)
{
	int i;

	i = 0;
	while (megastruct->coords && megastruct->coords[i])
	{
		if (i >= megastruct->size)
			pizdec('g');
		i++;
	}
	if (i != megastruct->size)
		pizdec('g');
}

void	valid_data(char *data)
{
	int i;

	i = 0;
	while (data && data[i])
	{
		if (!(ft_isdigit(data[i])) || !(ft_isalpha(data[i])) || \
					data[i] != ' ' || data[i] != '\n')
			pizdec('g');
		i++;
	}
}
