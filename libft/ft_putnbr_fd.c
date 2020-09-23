/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 03:16:53 by abibi             #+#    #+#             */
/*   Updated: 2020/05/12 09:26:35 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

void		ft_putnbr_fd(int n, int fd)
{
	char	buf;

	if (ft_abs(n / 10) > 0)
	{
		ft_putnbr_fd(n / 10, fd);
		buf = ft_abs(n % 10) + '0';
		write(fd, &buf, 1);
	}
	else
	{
		if (n < 0)
			write(fd, "-", 1);
		buf = ft_abs(n % 10) + '0';
		write(fd, &buf, 1);
	}
}
