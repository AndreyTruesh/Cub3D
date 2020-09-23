/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 05:22:34 by abibi             #+#    #+#             */
/*   Updated: 2020/09/22 05:22:55 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	map_free(t_game *el)
{
	int i;

	i = 0;
	while (i < el->map.h)
	{
		free(el->map.map[i]);
		i++;
	}
	free(el->map.map);
}

void	sprites_free(t_game *el)
{
	if (el->sprite_count > 0)
	{
		free(el->sprite_arr);
		free(el->pwd_arr);
	}
}

int		close_event(t_game *el)
{
	map_free(el);
	free_textures(el);
	sprites_free(el);
	mlx_destroy_window(el->mlx_ptr, el->win_ptr);
	free(el->mlx_ptr);
	exit(0);
}

int		exp_event(t_game *el)
{
	render_image(el);
	return (1);
}

void	check_screen_size(t_game *el)
{
	int sizex;
	int sizey;

	mlx_get_screen_size(el->mlx_ptr, &sizex, &sizey);
	if (el->w > sizex)
		el->w = sizex;
	if (el->h > sizey)
		el->h = sizey;
}
