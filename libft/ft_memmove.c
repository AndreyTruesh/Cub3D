/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:13:05 by abibi             #+#    #+#             */
/*   Updated: 2020/05/14 05:59:17 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*dstbuf;
	unsigned char	*srcbuf;

	if (dst == (void *)0 && src == (void *)0)
		return ((void *)0);
	srcbuf = (unsigned char *)src;
	dstbuf = (unsigned char *)dst;
	if (srcbuf > dstbuf)
		while (n-- > 0)
			*dstbuf++ = *srcbuf++;
	else
	{
		dstbuf += n;
		srcbuf += n;
		while (n-- > 0)
		{
			dstbuf--;
			srcbuf--;
			*dstbuf = *srcbuf;
		}
	}
	return (dst);
}
