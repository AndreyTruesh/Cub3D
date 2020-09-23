/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 04:21:43 by abibi             #+#    #+#             */
/*   Updated: 2020/05/12 09:25:45 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		len;
	int		neg;
	char	*res;

	len = 0;
	if (n == 0)
		return (ft_strdup("0"));
	neg = n < 0 ? 1 : 0;
	len = ft_intlen(n) + neg;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return ((char *)0);
	if (neg)
		res[0] = '-';
	res[len] = '\0';
	while (len-- > neg)
	{
		res[len] = (n % 10) * (1 - 2 * neg) + '0';
		n /= 10;
	}
	return (res);
}
