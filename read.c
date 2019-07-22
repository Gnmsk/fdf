/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbruen <dbruen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:17:23 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/22 14:04:14 by dbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

void	fdf_read(t_mega megastruct)
{
	char		*argv;
	char		**splitted_argv;
	t_stroka	*tmp;
	int			i;

	megastruct.str_quantity = 0;
	while (get_next_line(megastruct.fd, &argv))
	{
		if (!(splitted_argv = ft_strsplit(argv, ' ')))
			pizdec('b');
		if (megastruct.str_quantity == 0)
			tmp = stroka_new(splitted_argv);
		else
			stroka_push_front(&tmp, splitted_argv);
		megastruct.str_quantity++;
	}
	stroka_reverse(&tmp);
	i = counter(argv, ' ') + 1;
	ft_strdel(&argv);
	megastruct.coords = fdf_cords_point(tmp, megastruct.str_quantity * i);
}

t_point	**fdf_cords_point(t_stroka *tmp, int size)
{
	t_point		**cords;
	int			x;
	int			k;
	int			y;

	if (!(cords = (t_point **)malloc(sizeof(t_point *) * size)))
		pizdec('e');
	k = 0;
	y = 0;
	while (tmp)
	{
		x = 0;
		while (tmp->data[x])
		{
			if (!(cords[k] = (t_point *)malloc(sizeof(t_point))))
				pizdec('f');
			cords[k]->z = ft_atoi(tmp->data[x]);
			cords[k]->x = x;
			cords[k]->y = y;
			cords[k++]->color = (ft_atoi(tmp->data[x++]) > 0) ? 'r' : 'w';
			printf("%d %d %d %c\n", cords[k-1]->x, cords[k-1]->y, cords[k-1]->z, cords[k-1]->color);
		}
		printf("\n");
		tmp = tmp->next;
		y++;
	}
	return (cords);
}