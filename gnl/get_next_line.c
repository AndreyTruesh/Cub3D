/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 19:37:24 by abibi             #+#    #+#             */
/*   Updated: 2020/06/27 16:23:01 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	form_res_from_buf(char **line, t_strwptr *buf)
{
	char	*s;
	int		i;

	s = (char *)malloc(sizeof(char) * (n_in_str(*buf) + 1));
	if (!s)
		return (-1);
	i = 0;
	while (*(buf->ptr) != '\n')
	{
		s[i] = *(buf->ptr);
		i++;
		(buf->ptr)++;
	}
	s[i] = '\0';
	*line = s;
	(buf->ptr)++;
	return (1);
}

static int	form_res_from_buf_and_file(int fd, char **line, t_strwptr *buf)
{
	t_strwsiz	res;

	res.size = 0;
	res = strpump(res, buf_s_to_ptr(*buf), buf_s_to_ptr(*buf).size);
	buf->ptr = (void *)0;
	while ((buf->size = read(fd, buf->s, BUFFER_SIZE)) > 0 &&
			n_in_str(*buf) == -1 && res.size >= 0)
		res = strpump(res, *buf, buf->size);
	if (res.size < 0)
		return (-3);
	if (buf->size == -1)
	{
		if (res.size)
			free(res.s);
		return (-1);
	}
	if (buf->size > 0)
	{
		res = strpump(res, *buf, n_in_str(*buf));
		buf->ptr = buf->s + n_in_str(*buf) + 1;
		*line = res.s;
		return (1);
	}
	*line = res.s;
	return (0);
}

static int	form_res_from_file(int fd, char **line, t_strwptr *buf)
{
	t_strwsiz	res;

	res.size = 0;
	if (!(buf->s = (char *)malloc(sizeof(char) * BUFFER_SIZE)))
		return (-2);
	while ((buf->size = read(fd, buf->s, BUFFER_SIZE)) > 0 &&
			n_in_str(*buf) == -1 && res.size >= 0)
		res = strpump(res, *buf, buf->size);
	if (res.size < 0)
		return (-3);
	if (buf->size == -1)
	{
		if (res.size)
			free(res.s);
		return (-1);
	}
	if (buf->size > 0)
	{
		res = strpump(res, *buf, n_in_str(*buf));
		buf->ptr = buf->s + n_in_str(*buf) + 1;
		*line = res.s;
		return (1);
	}
	*line = strpump(res, *buf, buf->size).s;
	return (0);
}

int			get_next_line(int fd, char **line, int clear)
{
	static t_strwptr	buf;
	int					r;

	if (clear == 1)
		free(buf.s);
	if (BUFFER_SIZE < 1 || line == NULL || clear == 1)
		return (-1);
	if (buf.ptr && n_in_str(buf) != -1)
		r = (form_res_from_buf(line, &buf));
	else if (buf.ptr)
		r = (form_res_from_buf_and_file(fd, line, &buf));
	else
		r = (form_res_from_file(fd, line, &buf));
	if (r == 0 || r == -1 || r == -3 || ((r == 1) && (*line == NULL)))
	{
		free(buf.s);
		buf.ptr = NULL;
	}
	if (r < 0 || ((r == 1) && (*line == NULL)))
	{
		*line = NULL;
		return (-1);
	}
	else
		return (r);
}
