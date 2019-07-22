/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:17:45 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/18 14:54:52 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_stroka	*stroka_new(char **content)
{
	t_stroka	*l;

	if (!(l = (t_stroka *)malloc(sizeof(t_stroka))) || !(content))
		pizdec('c');
	l->data = content;
	l->next = NULL;
	return (l);
}

void		stroka_push_front(t_stroka **list, char **data)
{
	t_stroka *first;

	first = *list;
	*list = stroka_new(data);
	if (first)
		(*list)->next = first;
}

void		stroka_reverse(t_stroka **begin_list)
{
	t_stroka *third;
	t_stroka *second;
	t_stroka *first;

	first = *begin_list;
	if (!first || !(first->next))
		return ;
	second = first->next;
	third = second->next;
	first->next = 0;
	second->next = first;
	while (third)
	{
		first = second;
		second = third;
		third = third->next;
		second->next = first;
	}
	*begin_list = second;
}