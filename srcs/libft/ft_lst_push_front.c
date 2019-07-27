/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:25:57 by tkelsie           #+#    #+#             */
/*   Updated: 2019/04/19 19:41:15 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_push_front(t_list **list, void const *data, size_t size)
{
	t_list *first;

	first = *list;
	*list = ft_lstnew(data, size);
	if (first)
	{
		(*list)->next = first;
	}
}
