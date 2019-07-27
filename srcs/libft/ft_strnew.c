/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 21:18:51 by tkelsie           #+#    #+#             */
/*   Updated: 2019/04/18 17:42:50 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*mem;

	if (!(mem = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	mem[size] = '\0';
	while (size--)
		mem[size] = '\0';
	return (mem);
}
