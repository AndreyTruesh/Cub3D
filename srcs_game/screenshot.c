/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 05:23:37 by abibi             #+#    #+#             */
/*   Updated: 2020/09/25 16:26:06 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	make_screenshot(t_game *el)
{
	unsigned char	*bmp;
	int				fd;
	int				size;

	size = el->w * el->h / 8 * el->bpp + 54;
	if (!(bmp = (unsigned char *)malloc(sizeof(char) * size)))
		make_screenshot_malloc_error(el);
	ft_bzero(bmp, size);
	ft_memcpy(&bmp[0], "BM", 2);
	fd = 54;
	ft_memcpy(&bmp[10], &fd, 4);
	fd = 40;
	ft_memcpy(&bmp[14], &fd, 4);
	ft_memcpy(&bmp[18], &el->w, 4);
	fd = -el->h;
	ft_memcpy(&bmp[22], &fd, 4);
	fd = 1;
	ft_memcpy(&bmp[26], &fd, 2);
	ft_memcpy(&bmp[28], &el->bpp, 2);
	ft_memcpy(&bmp[54], el->img_data, size - 54);
	fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if ((fd = write(fd, bmp, size)) < 0)
		make_screenshot_write_error(el, bmp);
	free(bmp);
	close(fd);
}

static void	render_image_ss(t_game *el)
{
	el->img_ptr = mlx_new_image(el->mlx_ptr, el->w, el->h);
	if (!el->img_ptr)
		mlx_new_image_error(el);
	el->img_data = (int *)mlx_get_data_addr(el->img_ptr, &el->bpp,
			&el->size_line, &el->endian);
	if (!el->img_data)
		mlx_get_data_addr_error(el);
	render_walls(el);
	if (el->sprite_count > 0)
	{
		sort_sprites(el);
		draw_sprites(*el);
	}
}

void		exit_after_ss(t_game *el)
{
	map_free(el);
	free_textures(el);
	sprites_free(el);
	free(el->mlx_ptr);
	exit(0);
}

void		init_game_screenshot(char *f_path, t_game *el)
{
	int error;

	if ((error = parse_input(f_path, el)) < 1)
		parse_inp_error(error);
	el->mlx_ptr = mlx_init();
	if (!el->mlx_ptr)
		mlx_init_error(el);
	if (!load_textures(el))
		load_textures_error(el);
	if (get_sprites(el) < 1)
		get_sprites_error(el);
	render_image_ss(el);
	make_screenshot(el);
	mlx_destroy_image(el->mlx_ptr, el->img_ptr);
	exit_after_ss(el);
}
