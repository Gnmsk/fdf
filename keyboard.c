/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:15:13 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/26 21:51:49 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				put_pixel(int x, int y, int color, t_mega *megastruct)
{
	megastruct->data_adress[y * WIDTH + x] = color;
}

void				fill_backgound(int color, t_mega *megastruct)
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

int	keyboard(int key, t_mega *megastruct)
{
	if (key == 53)
		exit(0);
	if (key == 123)
		shift_x(megastruct, -4);
	if (key == 124)
		shift_x(megastruct, 4);
	if (key == 125)
		shift_y(megastruct, 4);
	if (key == 126)
		shift_y(megastruct, -4);
	else
		write(1, "PRESS ESC", 9);
	fill_backgound(0, megastruct);
	draw(megastruct);
	mlx_put_image_to_window(megastruct->discriptor, megastruct->win,
		megastruct->img, 0, 0);
	fill_backgound(0, megastruct);
	return (0);
}
