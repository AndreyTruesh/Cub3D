/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 05:29:43 by abibi             #+#    #+#             */
/*   Updated: 2020/09/25 16:20:41 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		get_pixel_col(int x, int y, t_tex tex)
{
	int color;

	color = ((int *)(tex.img_data))[y * tex.width + x];
	return (color);
}

void	render_image(t_game *el)
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
		draw_sprites_new(*el);
	}
	mlx_put_image_to_window(el->mlx_ptr, el->win_ptr, el->img_ptr, 0, 0);
	mlx_destroy_image(el->mlx_ptr, el->img_ptr);
}

void	init_game_regular(char *f_path, t_game *el)
{
	int error;

	if ((error = parse_input(f_path, el)) < 1)
		parse_inp_error(error);
	el->mlx_ptr = mlx_init();
	if (!el->mlx_ptr)
		mlx_init_error(el);
	check_screen_size(el);
	if (!load_textures(el))
		load_textures_error(el);
	if (get_sprites(el) < 1)
		get_sprites_error(el);
	el->win_ptr = mlx_new_window(el->mlx_ptr, el->w, el->h, "abibi's cub");
	if (!el->win_ptr)
		mlx_new_window_error(el);
	render_image(el);
	mlx_hook(el->win_ptr, 17, 1L << 17, close_event, el);
	mlx_hook(el->win_ptr, 15, 1L << 16, exp_event, el);
	mlx_key_hook(el->win_ptr, deal_key, el);
	mlx_loop(el->mlx_ptr);
}

int		main(int argc, char **argv)
{
	t_game el;

	if (argc < 2 || argc > 3)
	{
		print_error("Error\nNo arguments or arguments > 3");
		return (1);
	}
	if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save", 7) == 0)
			init_game_screenshot(argv[1], &el);
		else
		{
			print_error("Error\nSecond argument is found, but not --save");
			return (1);
		}
	}
	init_game_regular(argv[1], &el);
	return (0);
}
