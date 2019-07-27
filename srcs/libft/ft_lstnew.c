/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:48:47 by tkelsie           #+#    #+#             */
/*   Updated: 2019/04/18 18:53:12 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*l;

	if (!(l = (t_list *)malloc(sizeof(t_list) * content_size)))
		return (NULL);
	if (content == NULL)
		l->content = NULL;
	else
	{
		if (!(l->content = (void *)malloc(content_size)))
			return (NULL);
		ft_memcpy(l->content, content, content_size);
	}
	l->content_size = (content) ? content_size : 0;
	l->next = NULL;
	return (l);
}
