/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 22:03:08 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/27 19:48:56 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	interface(t_mega *megastructura)
{
	mlx_string_put(megastructura->discriptor, megastructura->win, 10, 5,
	0xFFF, "left-right-up-down for move on x/y/z axis");
	mlx_string_put(megastructura->discriptor, megastructura->win, 10, 30,
	0xFFF, " + or - for zoom");
	mlx_string_put(megastructura->discriptor, megastructura->win, 10, 55,
	0xFFF, " Press SPACE to change projection");
	mlx_string_put(megastructura->discriptor, megastructura->win, 10, 80,
	0xFFF, " Press 1 - 6 to rotate");
	mlx_string_put(megastructura->discriptor, megastructura->win, 10, 105,
	0xFFF, " Press ESCAPE to exit");
}

void	put_pixel(int x, int y, int color, t_mega *megastruct)
{
	megastruct->data_adress[y * WIDTH + x] = color;
}

void	fill_backgound(int color, t_mega *megastruct)
{
	int				x;
	int				y;

	y = 0;
	while (y < HIGHT)
	{
		x = 0;
		while (x < WIDTH)
			put_pixel(x++, y, color, megastruct);
		y++;
	}
}

void	display_map(t_mega *megastruct)
{
	fill_backgound(0, megastruct);
	interface(megastruct);
	draw(megastruct);
	mlx_put_image_to_window(megastruct->discriptor, megastruct->win,
	megastruct->img, 0, 140);
	fill_backgound(0, megastruct);
}

int		close_window(void *param)
{
	(void)param;
	exit(0);
}
