/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 14:46:05 by abibi             #+#    #+#             */
/*   Updated: 2020/05/12 11:43:56 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	unsigned char	*buf;
	size_t			totalsize;

	ptr = malloc(count * size);
	if (!ptr)
		return ((void *)0);
	buf = ptr;
	totalsize = (count * size);
	while (totalsize-- > 0)
	{
		*buf = 0;
		buf++;
	}
	return (ptr);
}
