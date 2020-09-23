/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 20:50:24 by abibi             #+#    #+#             */
/*   Updated: 2020/05/15 20:31:08 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	unsigned char *ptrbuf;

	ptrbuf = (unsigned char *)ptr;
	while (n-- > 0)
		if (*ptrbuf == (unsigned char)c)
			return (ptrbuf);
		else
			ptrbuf++;
	return ((void *)0);
}
