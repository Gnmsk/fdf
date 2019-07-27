/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 20:21:56 by tkelsie           #+#    #+#             */
/*   Updated: 2019/04/12 20:22:32 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	while (s1 != NULL && s2 != NULL && *s1 && *s2 && n--)
	{
		if (*(char *)s1++ != *(char*)s2++)
			return (0);
	}
	return (1);
}
