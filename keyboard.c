/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:15:13 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/26 21:28:04 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	keyboard(int key, t_mega *megastruct)
{
	if (key == 53)
		exit(0);
	if (key == 123)
	{
		mlx_clear_window(megastruct->discriptor, megastruct->win);
		megastruct->offset.z -= 4;
		shift_x(megastruct);
		draw(megastruct);
		mlx_put_image_to_window(megastruct->discriptor, megastruct->win,
	megastruct->img, 0, 0);
	}
	else if (key == 124)
	{
		mlx_clear_window(megastruct->discriptor, megastruct->win);
		megastruct->offset.z += 4;
		shift_x(megastruct);
		draw(megastruct);
		mlx_put_image_to_window(megastruct->discriptor, megastruct->win,
	megastruct->img, 0, 0);
	}
	else if (key == 125)
	{
		mlx_clear_window(megastruct->discriptor, megastruct->win);
		megastruct->offset.color += 4;
		shift_y(megastruct);
		draw(megastruct);
		mlx_put_image_to_window(megastruct->discriptor, megastruct->win,
	megastruct->img, 0, 0);
	}
	else if (key == 125)
	{
		mlx_clear_window(megastruct->discriptor, megastruct->win);
		megastruct->offset.color -= 4;
		shift_y(megastruct);
		draw(megastruct);
		mlx_put_image_to_window(megastruct->discriptor, megastruct->win,
	megastruct->img, 0, 0);
	}
	else
		write(1, "PRESS ESC", 9);
	return (0);
}
