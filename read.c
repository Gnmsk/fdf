/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:17:23 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/18 14:48:52 by tkelsie          ###   ########.fr       */
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
	fdf_cords_int(tmp, str_quantity * i);
	ft_strdel(&argv);
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
