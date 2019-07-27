/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:15:13 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/27 17:38:30 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	keyboard(int key, t_mega *megastruct)
{
	if (key == 53)
		exit(0);
	if (key >= 123 && key <= 126)
		shift_xy(megastruct, key);
	if (key == 69 || key == 78)
	{
		megastruct->iso_coords = copy_structure(megastruct);
		if (key == 69)
			megastruct->zoom += 3;
		else if (key == 78)
			if (megastruct->zoom > 3)
				megastruct->zoom -= 3;
		zoom(megastruct, megastruct->zoom);
		if (megastruct->proj == 1)
			rotation(megastruct);
		centre(megastruct);
	}
	if (key == 49)
	{
		megastruct->iso_coords = copy_structure(megastruct);
		zoom(megastruct, megastruct->zoom);
		if (megastruct->proj == 1)
			megastruct->proj = 0;
		else if (megastruct->proj == 0)
			rotation(megastruct);
		shift(megastruct);
		centre(megastruct);
	}
	display_map(megastruct);
	return (0);
}
