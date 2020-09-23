/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 01:32:58 by abibi             #+#    #+#             */
/*   Updated: 2020/05/07 02:09:02 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buf;

	if (s1 == (char *)0 || s2 == (char *)0)
		return ((char *)0);
	buf = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!buf)
		return ((char *)0);
	ft_strlcpy(buf, s1, ft_strlen(s1) + 1);
	ft_strlcat(buf, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (buf);
}
