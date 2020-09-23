/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 18:11:29 by abibi             #+#    #+#             */
/*   Updated: 2020/09/22 18:14:57 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		ft_isspace(char c)
{
	return (c == '\t' || c == ' ' || c == '\f' || c == '\r' || c == '\v');
}

char	*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		id_num(char **id)
{
	if (ft_strlen(*id) == 0)
		return (10);
	while (ft_isspace(**id))
		((*id)++);
	if (ft_strncmp(*id, "R", 1) == 0)
		return (1);
	if (ft_strncmp(*id, "NO", 2) == 0)
		return (2);
	if (ft_strncmp(*id, "SO", 2) == 0)
		return (3);
	if (ft_strncmp(*id, "WE", 2) == 0)
		return (4);
	if (ft_strncmp(*id, "EA", 2) == 0)
		return (5);
	if (ft_strncmp(*id, "S", 1) == 0)
		return (6);
	if (ft_strncmp(*id, "F", 1) == 0)
		return (7);
	if (ft_strncmp(*id, "C", 1) == 0)
		return (8);
	return (-8);
}

int		check_fields(t_game el)
{
	return (el.w > 0 && el.h > 0 && el.c_color_flag > 0
			&& el.f_color_flag > 0 && el.no_tex_p != 0 && el.so_tex_p != 0
				&& el.ea_tex_p != 0 && el.we_tex_p != 0 && el.s_tex_p != 0);
}

void	tgame_init(t_game *el)
{
	el->w = 0;
	el->h = 0;
	el->no_tex_p = 0;
	el->so_tex_p = 0;
	el->ea_tex_p = 0;
	el->we_tex_p = 0;
	el->s_tex_p = 0;
	el->f_color = 0;
	el->c_color = 0;
	el->f_color_flag = 0;
	el->c_color_flag = 0;
	el->ea_tex.img_ptr = NULL;
	el->we_tex.img_ptr = NULL;
	el->so_tex.img_ptr = NULL;
	el->no_tex.img_ptr = NULL;
	el->s_tex.img_ptr = NULL;
	el->map.w = 0;
	el->map.h = 0;
}
