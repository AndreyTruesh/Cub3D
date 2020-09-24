/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 17:22:06 by abibi             #+#    #+#             */
/*   Updated: 2020/09/24 23:19:37 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int			check_last_symbols(char *line)
{
	while (ft_isspace(*line))
		line++;
	if (*line == '\0')
		return (1);
	else
		return (0);
}

static void	skip_spaces_comma(char **line)
{
	int comma;

	comma = 0;
	while (ft_isspace(**line) || **line == ',')
	{
		if (**line == ',' && comma == 1)
			return ;
		if (**line == ',' && comma == 0)
			comma = 1;
		(*line)++;
	}
	if (comma == 0 && !ft_isdigit(*(*line - 1)))
		(*line)--;
}

static int	get_single_col(char **line, int *col)
{
	int i;

	i = 0;
	*col = 0;
	while (ft_isdigit(**line))
	{
		*col = *col * 10 + (int)(**line - '0');
		(*line)++;
		i++;
	}
	if (!(ft_isspace(**line) || **line == ',' || **line == '\0'))
		return (0);
	if (*col < 0 || *col > 255)
		return (0);
	if (i == 0)
		return (0);
	return (1);
}

static int	get_col(char *line)
{
	int color;
	int res;

	while (ft_isspace(*line))
		line++;
	if (get_single_col(&line, &color))
		res = color * pow(16, 4);
	else
		return (-1);
	skip_spaces_comma(&line);
	if (get_single_col(&line, &color))
		res += color * pow(16, 2);
	else
		return (-1);
	skip_spaces_comma(&line);
	if (get_single_col(&line, &color))
		res += color;
	else
		return (-1);
	if (check_last_symbols(line))
		return (res);
	else
		return (-1);
}

int			get_color(t_game *el, char *line, int id)
{
	line++;
	if (id == 7)
	{
		if (el->f_color_flag == 1 || !ft_isspace(*line))
			return (-2);
		el->f_color = get_col(line);
		if (el->f_color == -1)
			return (-2);
		el->f_color_flag = 1;
	}
	if (id == 8)
	{
		if (el->c_color_flag == 1 || !ft_isspace(*line))
			return (-2);
		el->c_color = get_col(line);
		if (el->c_color == -1)
			return (-2);
		el->c_color_flag = 1;
	}
	return (1);
}
