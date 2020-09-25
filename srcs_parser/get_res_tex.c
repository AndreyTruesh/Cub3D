/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_res_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 17:27:43 by abibi             #+#    #+#             */
/*   Updated: 2020/09/25 03:18:20 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int			get_res(t_game *el, char *line)
{
	line++;
	if (el->w > 0 || el->h > 0 || !ft_isspace(*line))
		return (-3);
	while (ft_isspace(*line))
		line++;
	while (ft_isdigit(*line))
		el->w = el->w * 10 + (int)(*line++ - '0');
	if (el->w <= 0)
		return (-3);
	while (ft_isspace(*line))
		line++;
	while (ft_isdigit(*line))
		el->h = el->h * 10 + (int)(*line++ - '0');
	if (el->h <= 0)
		return (-3);
	if (!check_last_symbols(line))
		return (-3);
	return (1);
}

static int	get_path(char *line, char **path)
{
	int		i;
	char	*rem;

	i = 0;
	line += 2;
	while (ft_isspace(*line))
		line++;
	if (*line == '\0')
		return (-4);
	rem = line;
	while (*line != '\0' && !ft_isspace(*line))
	{
		line++;
		i++;
	}
	if ((*path = (char *)malloc(sizeof(char) * i + 1)) == NULL)
		return (-6);
	i = 0;
	while (rem < line)
	{
		(*path)[i++] = *rem;
		rem++;
	}
	(*path)[i] = '\0';
	return (check_last_symbols(line));
}

static int	check_for_second_call(t_game *el, int id)
{
	if (id == 2 && el->no_tex_p != NULL)
		return (-4);
	if (id == 3 && el->so_tex_p != NULL)
		return (-4);
	if (id == 4 && el->we_tex_p != NULL)
		return (-4);
	if (id == 5 && el->ea_tex_p != NULL)
		return (-4);
	if (id == 6 && el->s_tex_p != NULL)
		return (-4);
	return (1);
}

int			get_tex(t_game *el, char *line, int id)
{
	char	*buf;
	int		error;

	if (check_for_second_call(el, id) != 1)
		return (-4);
	if (id > 1 && id < 6 && !ft_isspace(*(line + 2)))
		return (-4);
	if (id == 6 && !ft_isspace(*(line + 1)))
		return (-4);
	if ((error = get_path(line, &buf)) > 0)
	{
		if (id == 2)
			el->no_tex_p = buf;
		if (id == 3)
			el->so_tex_p = buf;
		if (id == 4)
			el->we_tex_p = buf;
		if (id == 5)
			el->ea_tex_p = buf;
		if (id == 6)
			el->s_tex_p = buf;
	}
	else
		return (error);
	return (1);
}
