/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 05:52:33 by abibi             #+#    #+#             */
/*   Updated: 2020/09/22 05:53:42 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void			free_tex_paths(t_game *el)
{
	if (el->no_tex_p != NULL)
		free(el->no_tex_p);
	if (el->we_tex_p != NULL)
		free(el->we_tex_p);
	if (el->ea_tex_p != NULL)
		free(el->ea_tex_p);
	if (el->so_tex_p != NULL)
		free(el->so_tex_p);
	if (el->s_tex_p != NULL)
		free(el->s_tex_p);
}

static t_tex	load_tex(t_game *el, char *path)
{
	t_tex tex;

	tex.img_ptr = mlx_xpm_file_to_image(el->mlx_ptr, path,
			&tex.width, &tex.height);
	if (!tex.img_ptr)
		return (tex);
	tex.img_data = (int *)mlx_get_data_addr(tex.img_ptr, &tex.bpp,
			&tex.sizeline, &tex.endian);
	if (!tex.img_data)
	{
		mlx_destroy_image(el->mlx_ptr, tex.img_ptr);
		tex.img_ptr = NULL;
	}
	return (tex);
}

void			free_textures(t_game *el)
{
	if (el->ea_tex.img_ptr)
		mlx_destroy_image(el->mlx_ptr, el->ea_tex.img_ptr);
	if (el->no_tex.img_ptr)
		mlx_destroy_image(el->mlx_ptr, el->no_tex.img_ptr);
	if (el->so_tex.img_ptr)
		mlx_destroy_image(el->mlx_ptr, el->so_tex.img_ptr);
	if (el->we_tex.img_ptr)
		mlx_destroy_image(el->mlx_ptr, el->we_tex.img_ptr);
	if (el->s_tex.img_ptr)
		mlx_destroy_image(el->mlx_ptr, el->s_tex.img_ptr);
}

int				load_textures(t_game *el)
{
	el->s_tex = load_tex(el, el->s_tex_p);
	el->no_tex = load_tex(el, el->no_tex_p);
	el->ea_tex = load_tex(el, el->ea_tex_p);
	el->so_tex = load_tex(el, el->so_tex_p);
	el->we_tex = load_tex(el, el->we_tex_p);
	free_tex_paths(el);
	if (el->ea_tex.img_ptr == NULL || el->no_tex.img_ptr == NULL ||
		el->so_tex.img_ptr == NULL || el->we_tex.img_ptr == NULL ||
		el->s_tex.img_ptr == NULL)
	{
		free_textures(el);
		return (0);
	}
	return (1);
}
