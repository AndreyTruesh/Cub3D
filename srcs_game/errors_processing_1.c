/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_processing_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 05:25:33 by abibi             #+#    #+#             */
/*   Updated: 2020/09/22 05:26:35 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	load_textures_error(t_game *el)
{
	print_error("Error\nTexture loading failed");
	map_free(el);
	free(el->mlx_ptr);
	exit(0);
}

void	parse_inp_error(int error)
{
	if (error == -1)
		print_error("Error\nInvalid map name");
	if (error == -100)
		perror("Error\nMessage ");
	if (error == -2)
		print_error("Error\nFloor/Ceil color error");
	if (error == -3)
		print_error("Error\nResolution error");
	if (error == -4)
		print_error("Error\nGet texture error");
	if (error == -5)
		print_error("Error\nInvalid map");
	if (error == -6)
		print_error("Error\nMalloc error");
	if (error == -7)
		print_error("Error\nGet next line error");
	if (error == -8)
		print_error("Error\nBad symbol at start of line");
	if (error == -9)
		print_error("Error\nBad map, some params are missing");
	if (error == -10)
		print_error("Erorr\nBad symbol after map");
	exit(1);
}

void	get_sprites_error(t_game *el)
{
	print_error("Error\n creating array for sprites failed");
	map_free(el);
	free_textures(el);
	free(el->mlx_ptr);
	exit(1);
}

void	mlx_init_error(t_game *el)
{
	print_error("Error\n creating mlx ptr failed");
	map_free(el);
	free_tex_paths(el);
	exit(1);
}

void	mlx_new_window_error(t_game *el)
{
	print_error("Error\n creating window failed");
	map_free(el);
	free_textures(el);
	sprites_free(el);
	free(el->mlx_ptr);
	exit(1);
}
