/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:27:11 by tkelsie           #+#    #+#             */
/*   Updated: 2019/04/19 19:41:19 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_push_back(t_list **list, void const *data, size_t size)
{
	t_list *last;

	last = *list;
	if (last)
	{
		while (last->next)
			last = last->next;
		last->next = ft_lstnew(data, size);
	}
	else
		*list = ft_lstnew(data, size);
}
