/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 01:10:43 by abibi             #+#    #+#             */
/*   Updated: 2020/05/14 05:49:36 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*srcbuf;
	unsigned char	*dstbuf;

	if (dst == (void *)0 && src == (void *)0)
		return ((void *)0);
	srcbuf = (unsigned char *)src;
	dstbuf = (unsigned char *)dst;
	while (n-- > 0)
	{
		*dstbuf = *srcbuf;
		srcbuf++;
		dstbuf++;
	}
	return (dst);
}
