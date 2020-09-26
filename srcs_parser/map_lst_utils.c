/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_lst_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 17:34:23 by abibi             #+#    #+#             */
/*   Updated: 2020/09/26 20:25:21 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	lstdestroyer(t_list **lst, t_list *el)
{
	t_list	*buf;

	buf = *lst;
	if (*lst == el)
	{
		*lst = (*lst)->next;
		free(el->content);
		free(el);
		return ;
	}
	while (buf)
	{
		if (buf->next == el)
		{
			buf->next = el->next;
			free(el->content);
			free(el);
			return ;
		}
		buf = buf->next;
	}
}

void	lstclear(t_list **map_lines)
{
	t_list *runner;
	t_list *buf;

	runner = *map_lines;
	while (runner != NULL)
	{
		buf = runner;
		runner = runner->next;
		free(buf->content);
		free(buf);
	}
}

int		map_is_empty(t_list *map_lines)
{
	while (map_lines)
	{
		if (!check_last_symbols(map_lines->content))
			return (0);
		map_lines = map_lines->next;
	}
	return (1);
}

int		list_malloc_error(t_list **map_lines, char *buf, int i, t_game *el)
{
	if (i == -1)
	{
		lstclear(map_lines);
		free_tex_paths(el);
		return (0);
	}
	free_tex_paths(el);
	lstclear(map_lines);
	free(buf);
	if (i == 1)
		get_next_line(0, NULL, 1);
	return (0);
}

int		get_map_err(int fd, int error)
{
	close(fd);
	return (error);
}
