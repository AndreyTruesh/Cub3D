/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 19:48:51 by abibi             #+#    #+#             */
/*   Updated: 2020/07/13 15:52:22 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_strwptr
{
	char		*s;
	char		*ptr;
	int			size;
}				t_strwptr;

typedef struct	s_strwsiz
{
	char		*s;
	int			size;
}				t_strwsiz;

int				n_in_str(t_strwptr buf);
t_strwsiz		strpump(t_strwsiz old, t_strwptr buf, int bytes);
int				get_next_line(int fd, char **line, int clear);
t_strwptr		buf_s_to_ptr(t_strwptr buf);

#endif
