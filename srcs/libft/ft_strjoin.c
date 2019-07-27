/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:54:19 by tkelsie           #+#    #+#             */
/*   Updated: 2019/04/15 22:12:31 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*res;
	size_t		i;

	res = NULL;
	i = 0;
	if (s1 && s2 && (res = ft_strnew((ft_strlen(s1) + ft_strlen(s2)))))
	{
		while (*s1)
			res[i++] = *s1++;
		while (*s2)
			res[i++] = *s2++;
		res[i] = '\0';
	}
	return (res);
}
