/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:13:16 by tkelsie           #+#    #+#             */
/*   Updated: 2019/04/18 16:18:01 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb >= 10 || nb <= -10)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd(((nb % 10) * (-1 + 2 * (nb > 0)) + '0'), fd);
	}
	else
	{
		if (nb < 0)
			ft_putchar_fd('-', fd);
		ft_putchar_fd(((nb % 10) * (-1 + 2 * (nb > 0)) + '0'), fd);
	}
}
