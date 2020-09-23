/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 18:15:16 by abibi             #+#    #+#             */
/*   Updated: 2020/09/22 18:15:34 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	dir_no_so(t_game *el, char c)
{
	if (c == 'N')
	{
		el->pos.dir_x = 0;
		el->pos.dir_y = -1;
		el->pos.plane_x = 0.66;
		el->pos.plane_y = 0;
	}
	else if (c == 'S')
	{
		el->pos.dir_x = 0;
		el->pos.dir_y = 1;
		el->pos.plane_x = -0.66;
		el->pos.plane_y = 0;
	}
}

static void	dir_ea_we(t_game *el, char c)
{
	if (c == 'E')
	{
		el->pos.dir_x = 1;
		el->pos.dir_y = 0;
		el->pos.plane_x = 0;
		el->pos.plane_y = 0.66;
	}
	else if (c == 'W')
	{
		el->pos.dir_x = -1;
		el->pos.dir_y = 0;
		el->pos.plane_x = 0;
		el->pos.plane_y = -0.66;
	}
}

static void	pos_to_struct(t_game *el, char c, int i, int j)
{
	el->pos.pos_x = (float)j + 0.5;
	el->pos.pos_y = (float)i + 0.5;
	if (c == 'W' || c == 'E')
		dir_ea_we(el, c);
	else
		dir_no_so(el, c);
}

int			check_for_pos(t_game *el, int n)
{
	int		i;
	char	c;

	i = 0;
	while (i < (int)ft_strlen(el->map.map[n]))
	{
		c = el->map.map[n][i];
		if (c == 'W' || c == 'S' || c == 'E' || c == 'N')
		{
			pos_to_struct(el, c, n, i);
			el->map.map[n][i] = '0';
			return (1);
		}
		i++;
	}
	return (0);
}
