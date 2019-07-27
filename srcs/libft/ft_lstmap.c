/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:51:40 by tkelsie           #+#    #+#             */
/*   Updated: 2019/04/21 14:12:29 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst || !(tmp = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(tmp = f(lst)))
	{
		ft_lstdel(&tmp, (void *)ft_lstdelone);
		return (NULL);
	}
	new = tmp;
	while (lst->next)
	{
		lst = lst->next;
		if (!f(lst))
		{
			ft_lstdel(&new, (void *)ft_lstdelone);
			return (NULL);
		}
		tmp->next = f(lst);
		tmp = tmp->next;
	}
	return (new);
}
