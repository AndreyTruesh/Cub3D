/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_processing_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 05:27:18 by abibi             #+#    #+#             */
/*   Updated: 2020/09/22 05:27:20 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	print_error(const char *s)
{
	write(2, s, ft_strlen(s));
}

void	mlx_new_image_error(t_game *el)
{
	print_error("Error\ncreating image failed");
	map_free(el);
	free_textures(el);
	sprites_free(el);
	mlx_destroy_window(el->mlx_ptr, el->win_ptr);
	free(el->mlx_ptr);
	exit(1);
}

void	mlx_get_data_addr_error(t_game *el)
{
	print_error("Error\ncreating image data array failed");
	map_free(el);
	free_textures(el);
	sprites_free(el);
	mlx_destroy_image(el->mlx_ptr, el->img_ptr);
	mlx_destroy_window(el->mlx_ptr, el->win_ptr);
	free(el->mlx_ptr);
	exit(1);
}
