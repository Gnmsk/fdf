/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 19:09:01 by tkelsie           #+#    #+#             */
/*   Updated: 2019/04/18 16:44:58 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_puti(int n, size_t len, size_t pwr)
{
	char	*str;
	size_t	i;

	i = (0 > n) ? 1 : 0;
	if (!(str = ft_strnew(len + i)))
		return (NULL);
	str[len + i] = '\0';
	str[0] = (i == 1) ? '-' : '0';
	n = (0 > n) ? -n : n;
	while (len--)
	{
		str[i++] = (n / pwr) + '0';
		n = n % pwr;
		pwr /= 10;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	size_t	len;
	size_t	pwr;
	char	*str;
	int		tmp;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	pwr = 1;
	tmp = n * (-1 + 2 * (0 < n));
	len = 1;
	while (tmp / 10)
	{
		len++;
		pwr *= 10;
		tmp /= 10;
	}
	return ((str = ft_puti(n, len, pwr)) ? str : NULL);
}
