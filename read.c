/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:17:23 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/18 15:07:00 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

int		fdf_read(int fd, t_okno window, t_stroka **argv_postrochno)
{
	char		*argv;
	int			str_quantity;
	char		**splitted_argv;
	t_stroka	*tmp;
	int			i;

	str_quantity = 0;
	while (get_next_line(fd, &argv))
	{
		if (!(splitted_argv = ft_strsplit(argv, ' ')))
			pizdec('b');
		if (str_quantity == 0)
			tmp = stroka_new(splitted_argv);
		else
			stroka_push_front(&tmp, splitted_argv);
		str_quantity++;
	}
	stroka_reverse(&tmp);
	*argv_postrochno = tmp;
	ft_strdel(&argv);
	fdf_cords_int(tmp, str_quantity * i);
	fdf_cords_color(tmp, str_quantity * i);
	return (str_quantity);
}

int		*fdf_cords_int(t_stroka *tmp, int size)
{
	int			*cords;
	int			i;
	int			k;

	if (!(cords = (int *)malloc(sizeof(int) * size)))
		pizdec('d');
	k = 0;
	while (tmp)
	{
		i = 0;
		while (tmp->data[i])
		{
			cords[k++] = ft_atoi(tmp->data[i++]);
			printf("%d ", cords[k - 1]);
		}
		printf("\n");
		tmp = tmp->next;
	}
	return (cords);
}

char	*fdf_cords_color(t_stroka *tmp, int size)
{
	char		*cords;
	int			i;
	int			k;

	if (!(cords = ft_strnew(size + 1)))
		pizdec('d');
	k = 0;
	while (tmp)
	{
		i = 0;
		while (tmp->data[i])
		{
			cords[k++] = (ft_atoi(tmp->data[i++]) > 0) ? 'r' : 'w';
			printf("%c ", cords[k - 1]);
		}
		printf("\n");
		tmp = tmp->next;
	}
	cords[k] = '\0';
	return (cords);
}
