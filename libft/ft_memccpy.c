/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 02:49:38 by abibi             #+#    #+#             */
/*   Updated: 2020/05/15 18:59:17 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*srcbuf;
	unsigned char	*dstbuf;

	srcbuf = (unsigned char *)src;
	dstbuf = (unsigned char *)dst;
	while (n-- > 0)
	{
		*dstbuf = *srcbuf;
		if (*dstbuf == (unsigned char)c)
			return (dstbuf + 1);
		dstbuf++;
		srcbuf++;
	}
	return ((void *)0);
}
