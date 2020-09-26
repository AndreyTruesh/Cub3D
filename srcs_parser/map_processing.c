/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 17:42:53 by abibi             #+#    #+#             */
/*   Updated: 2020/09/26 20:23:32 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	free_arr(t_game *el, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		free(el->map.map[i]);
		i++;
	}
	free(el->map.map);
	free_tex_paths(el);
	return (0);
}

static int	list_to_matrix(t_game *el, t_list *map_lines)
{
	int	i;
	int	j;

	el->map.map = (char **)malloc(sizeof(char *) * el->map.h);
	if (!(el->map.map))
	{
		free_tex_paths(el);
		return (0);
	}
	i = 0;
	while (i < el->map.h)
	{
		el->map.map[i] = (char *)malloc(sizeof(char) * el->map.w + 1);
		ft_bzero(el->map.map[i], sizeof(char) * el->map.w + 1);
		if (!(el->map.map[i]))
			return (free_arr(el, i));
		ft_strcpy(el->map.map[i], map_lines->content);
		j = ft_strlen(map_lines->content);
		while (j < el->map.w)
			el->map.map[i][j++] = ' ';
		check_for_pos(el, i);
		map_lines = map_lines->next;
		i++;
	}
	return (1);
}

static int	validate_0(t_map map, int n, int m)
{
	int i;
	int j;

	j = m;
	while (j > -1 && map.map[n][j] != '1')
		if (map.map[n][j--] == ' ')
			return (-1);
	if (j == -1)
		return (-1);
	j = m;
	while (j < map.w && map.map[n][j] != '1')
		if (map.map[n][j++] == ' ')
			return (-1);
	i = n;
	while (i > -1 && map.map[i][m] != '1')
		if (map.map[i--][m] == ' ')
			return (-1);
	if (i == -1 || j == map.w)
		return (-1);
	while (n < map.h && map.map[n][m] != '1')
		if (map.map[n++][m] == ' ')
			return (-1);
	if (n == map.h)
		return (-1);
	return (1);
}

static int	validate_map(t_map map)
{
	int i;
	int j;

	i = 0;
	while (i < map.h)
	{
		j = 0;
		while (j < map.w)
		{
			if (map.map[i][j] == '0' || map.map[i][j] == '2')
			{
				if (validate_0(map, i, j) == -1)
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int			get_map(t_game *el, int fd)
{
	t_list *map_lines;

	if (!map_to_list(&map_lines, el, fd))
		return (get_map_err(fd, -6));
	el->map.h = validate_last_empty_lines(map_lines);
	if (el->map.h < 1 || el->map.w < 1)
	{
		lstclear(&map_lines);
		free_tex_paths(el);
		return (get_map_err(fd, el->map.h));
	}
	if (!list_to_matrix(el, map_lines))
	{
		lstclear(&map_lines);
		return (get_map_err(fd, -6));
	}
	lstclear(&map_lines);
	if (validate_map(el->map) != 1)
	{
		free_tex_paths(el);
		map_free(el);
		return (get_map_err(fd, -5));
	}
	close(fd);
	return (1);
}
