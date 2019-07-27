/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 22:03:08 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/27 10:58:28 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			interface(t_mega *megastructura)
{
	mlx_string_put(megastructura->discriptor, megastructura->win, 0, 0,
	0xFF, "left-right-up-down for move on x/y/z axis");
	mlx_string_put(megastructura->discriptor, megastructura->win, 0, 0,
	0xFF, " + or - for zoom");
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
		{
			megastruct->data_adress[y * WIDTH + x] = color;
			x++;
		}
		y++;
	}
}
