/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:28:49 by tkelsie           #+#    #+#             */
/*   Updated: 2019/04/19 19:42:56 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_reverse(t_list **begin_list)
{
	t_list *third;
	t_list *second;
	t_list *first;

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
