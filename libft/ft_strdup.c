/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 19:26:39 by abibi             #+#    #+#             */
/*   Updated: 2020/05/12 12:12:50 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned int	l;
	unsigned int	i;
	char			*buf;

	l = 0;
	while (s1[l] != '\0')
		l++;
	l++;
	buf = (char *)malloc(sizeof(*s1) * l);
	if (!buf)
		return ((char *)0);
	i = 0;
	while (i < l)
	{
		buf[i] = s1[i];
		i++;
	}
	return (buf);
}
