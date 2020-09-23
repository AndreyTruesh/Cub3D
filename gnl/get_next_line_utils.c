/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 17:02:45 by abibi             #+#    #+#             */
/*   Updated: 2020/06/26 19:51:39 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			n_in_str(t_strwptr buf)
{
	int i;

	i = 0;
	if (buf.ptr)
		i = buf.ptr - buf.s;
	while (i < buf.size)
	{
		if (buf.s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

t_strwsiz	strpump(t_strwsiz old, t_strwptr buf, int size)
{
	int			i;
	int			j;
	t_strwsiz	new;

	i = 0;
	if (!(new.s = (char *)malloc(old.size + size + 1)))
	{
		if (old.size)
			free(old.s);
		new.size = -1;
		return (new);
	}
	new.size = old.size + size + 1;
	while (i < old.size && old.s[i] != '\0')
	{
		new.s[i] = old.s[i];
		i++;
	}
	j = 0;
	while (j < size)
		new.s[i++] = buf.s[j++];
	new.s[i] = '\0';
	if (old.size)
		free(old.s);
	return (new);
}

t_strwptr	buf_s_to_ptr(t_strwptr buf)
{
	t_strwptr	new;

	new.size = buf.size - (buf.ptr - buf.s);
	new.s = buf.ptr;
	return (new);
}
