/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_processing_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 05:27:18 by abibi             #+#    #+#             */
/*   Updated: 2020/09/26 16:12:54 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	print_error(const char *s)
{
	if ((write(2, s, ft_strlen(s))) < 0)
		return ;
}

void	make_screenshot_write_error(t_game *el, unsigned char *bmp, int fd)
{
	map_free(el);
	free_textures(el);
	sprites_free(el);
	free(el->mlx_ptr);
	free(bmp);
	if (fd > 0)
		close(fd);
	print_error("Error\ncan not write screenshot\n");
	exit(1);
}

void	make_screenshot_malloc_error(t_game *el)
{
	map_free(el);
	free_textures(el);
	sprites_free(el);
	free(el->mlx_ptr);
	print_error("Error\nmemory allocation failed\n");
	exit(1);
}

void	mlx_new_image_error(t_game *el)
{
	print_error("Error\ncreating image failed\n");
	map_free(el);
	free_textures(el);
	sprites_free(el);
	mlx_destroy_window(el->mlx_ptr, el->win_ptr);
	free(el->mlx_ptr);
	exit(1);
}

void	mlx_get_data_addr_error(t_game *el)
{
	print_error("Error\ncreating image data array failed\n");
	map_free(el);
	free_textures(el);
	sprites_free(el);
	mlx_destroy_image(el->mlx_ptr, el->img_ptr);
	mlx_destroy_window(el->mlx_ptr, el->win_ptr);
	free(el->mlx_ptr);
	exit(1);
}
