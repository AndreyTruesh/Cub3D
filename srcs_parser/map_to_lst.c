/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 18:06:55 by abibi             #+#    #+#             */
/*   Updated: 2020/09/22 18:11:01 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	validate_symbols_in_line(char *line, int *flag)
{
	int i;

	i = 0;
	if (check_last_symbols(line))
		return (0);
	while (*line != '\0')
	{
		if (!(*line == ' ' || *line == '0' || *line == '1' || *line == '2'
			|| *line == 'W' || *line == 'S' || *line == 'N' || *line == 'E'))
			return (-1);
		if ((*line == 'W' || *line == 'S' || *line == 'N' || *line == 'E') &&
				(*flag == 1))
			return (-1);
		if (*line == 'W' || *line == 'S' || *line == 'N' || *line == 'E')
			*flag = 1;
		i++;
		line++;
	}
	if (i == 0)
		return (0);
	return (1);
}

int			validate_last_lines(t_list *map_lines, int i)
{
	while (map_lines)
	{
		if (!check_last_symbols(map_lines->content))
			return (-10);
		map_lines = map_lines->next;
	}
	return (i);
}

int			validate_last_empty_lines(t_list *map_lines)
{
	int i;
	int r;
	int flag;

	i = 0;
	flag = 0;
	if (map_is_empty(map_lines))
		return (-9);
	while (map_lines)
	{
		r = validate_symbols_in_line(map_lines->content, &flag);
		if (r == 0 && flag == 1)
			return (validate_last_lines(map_lines, i));
		if (r == 0 && flag == 0)
			return (-5);
		if (r == -1)
			return (-5);
		map_lines = map_lines->next;
		i++;
	}
	if (flag == 1)
		return (i);
	else
		return (-5);
}

static void	del_first_empty_lines(t_list **map_lines)
{
	t_list *runner;
	t_list *buf;

	runner = *map_lines;
	while (runner->next != NULL && ft_strlen((char *)runner->content) == 0)
	{
		buf = runner;
		runner = runner->next;
		lstdestroyer(map_lines, buf);
	}
}

int			map_to_list(t_list **map_lines, t_game *el, int fd)
{
	char	*buf;
	t_list	*new;
	int		i;

	*map_lines = NULL;
	el->map.w = 0;
	while ((i = get_next_line(fd, &buf, 0)) > 0)
	{
		if ((int)ft_strlen(buf) > el->map.w)
			el->map.w = ft_strlen(buf);
		if ((new = ft_lstnew(buf)) == NULL)
			return (list_malloc_error(map_lines, buf, i, el));
		ft_lstadd_back(map_lines, new);
	}
	if (i == 0)
	{
		if ((new = ft_lstnew(buf)) == NULL)
			return (list_malloc_error(map_lines, buf, i, el));
		ft_lstadd_back(map_lines, new);
	}
	if (i == -1)
		return (list_malloc_error(map_lines, NULL, i, el));
	del_first_empty_lines(map_lines);
	return (1);
}
