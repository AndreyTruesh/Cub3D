/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 16:11:11 by abibi             #+#    #+#             */
/*   Updated: 2020/05/12 14:28:06 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	i;
	char			*buf;

	if (!s || !f)
		return ((char *)0);
	len = ft_strlen(s);
	buf = (char *)malloc((len + 1) * sizeof(char));
	if (!buf)
		return ((char *)0);
	i = 0;
	buf[len] = '\0';
	while (i < len)
	{
		buf[i] = (*f)(i, s[i]);
		i++;
	}
	return (buf);
}
