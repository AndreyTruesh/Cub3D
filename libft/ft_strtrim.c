/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 02:20:26 by abibi             #+#    #+#             */
/*   Updated: 2020/05/12 09:30:00 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	first_ind(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (ft_strchr(set, s1[i]) != (char *)0 && i < ft_strlen(s1))
		i++;
	return (i);
}

static size_t	last_ind(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1);
	while (ft_strchr(set, s1[i]) != (char *)0 && i > 0)
		i--;
	return (i);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*buf;

	if (s1 == (char *)0 || set == (char *)0)
		return ((char *)0);
	start = first_ind(s1, set);
	end = last_ind(s1, set);
	if (end < start)
	{
		buf = (char *)malloc(sizeof(char));
		if (!buf)
			return ((char *)0);
		buf[0] = '\0';
		return (buf);
	}
	buf = (char *)malloc(end - start + 2);
	if (!buf)
		return ((char *)0);
	i = 0;
	while (start <= end)
		buf[i++] = s1[start++];
	buf[i] = '\0';
	return (buf);
}
