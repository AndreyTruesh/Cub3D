/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 21:06:01 by abibi             #+#    #+#             */
/*   Updated: 2020/05/12 13:24:46 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1buf;
	unsigned char	*s2buf;

	s1buf = (unsigned char *)s1;
	s2buf = (unsigned char *)s2;
	if (!s1 && !s2)
		return (0);
	if (n == 0)
		return (0);
	while (--n > 0 && *s1buf - *s2buf == 0)
	{
		s1buf++;
		s2buf++;
	}
	return (*s1buf - *s2buf);
}
