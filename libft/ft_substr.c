/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 00:47:35 by abibi             #+#    #+#             */
/*   Updated: 2020/05/15 20:32:51 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buf;
	size_t	i;

	if (s == (char *)0)
		return ((char *)0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	len = len < (ft_strlen(s) - start) ? len : ft_strlen(s) - start;
	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (!buf)
		return ((char *)0);
	i = 0;
	while (i < len && s[start])
		buf[i++] = s[start++];
	buf[i] = '\0';
	return (buf);
}
