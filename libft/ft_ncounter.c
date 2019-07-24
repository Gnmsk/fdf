/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ncounter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 18:35:10 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/24 18:45:37 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ncounter(char *s, int c)
{
	int		i;
	int		n;
	char	ch;

	i = 0;
	n = 0;
	ch = (char)c;
	while (s[i])
	{
		if ((char)s[i] == ch && ((char)s[i + 1] != ch || s[i + 1] == '\0'))
			n++;
		i++;
	}
	return (n);
}
