/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_processing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 05:40:36 by abibi             #+#    #+#             */
/*   Updated: 2020/09/22 05:41:32 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int		get_sprite_count(t_game *el)
{
	int i;
	int j;

	el->sprite_count = 0;
	i = 0;
	while (i < el->map.h)
	{
		j = 0;
		while (j < el->map.w)
		{
			if (el->map.map[i][j] == '2')
				el->sprite_count++;
			j++;
		}
		i++;
	}
	if (el->sprite_count)
		el->sprite_arr = malloc(el->sprite_count * sizeof(t_sprite));
	if (el->sprite_count > 0 && !el->sprite_arr)
		el->sprite_count = -1;
	return (el->sprite_count);
}

static void		get_sprites_arr(t_game *el)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (i < el->map.h)
	{
		j = 0;
		while (j < el->map.w)
		{
			if (el->map.map[i][j] == '2')
			{
				el->sprite_arr[k].x = j + 0.5;
				el->sprite_arr[k++].y = i + 0.5;
			}
			j++;
		}
		i++;
	}
}

int				get_sprites(t_game *el)
{
	get_sprite_count(el);
	if (el->sprite_count == -1)
		return (0);
	if (el->sprite_count > 0)
	{
		el->pwd_arr = malloc(sizeof(double) * el->w);
		if (!el->pwd_arr)
		{
			el->sprite_count = -1;
			free(el->sprite_arr);
			return (0);
		}
		get_sprites_arr(el);
	}
	return (1);
}

static void		calc_sprites_dist(t_game *el)
{
	int i;

	i = 0;
	while (i < el->sprite_count)
	{
		el->sprite_arr[i].distance = (el->pos.pos_x - el->sprite_arr[i].x) *
			(el->pos.pos_x - el->sprite_arr[i].x) +
			(el->pos.pos_y - el->sprite_arr[i].y) *
			(el->pos.pos_y - el->sprite_arr[i].y);
		i++;
	}
}

void			sort_sprites(t_game *el)
{
	int			i;
	int			j;
	t_sprite	buff;

	calc_sprites_dist(el);
	i = 0;
	while (i < el->sprite_count)
	{
		j = 0;
		while (j < el->sprite_count - 1)
		{
			if (el->sprite_arr[j].distance < el->sprite_arr[j + 1].distance)
			{
				buff = el->sprite_arr[j];
				el->sprite_arr[j] = el->sprite_arr[j + 1];
				el->sprite_arr[j + 1] = buff;
			}
			j++;
		}
		i++;
	}
}
