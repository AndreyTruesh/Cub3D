/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 05:33:13 by abibi             #+#    #+#             */
/*   Updated: 2020/09/22 05:38:28 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static t_sprite_di	get_sprite_drawinfo(double sprite_x,
		double sprite_y, t_game el)
{
	double			invdet;
	double			transform_x;
	t_sprite_di		di;

	invdet = 1.0 / (el.pos.plane_x * el.pos.dir_y - el.pos.dir_x *
			el.pos.plane_y);
	transform_x = invdet * (el.pos.dir_y * sprite_x - el.pos.dir_x * sprite_y);
	di.transform_y = invdet * (-el.pos.plane_y * sprite_x + el.pos.plane_x *
			sprite_y);
	di.spritescreen_x = (int)((el.w / 2) * (1 + transform_x / di.transform_y));
	di.spriteheight = abs((int)(el.h / (di.transform_y)));
	di.drawstart_y = -di.spriteheight / 2 + el.h / 2;
	if (di.drawstart_y < 0)
		di.drawstart_y = 0;
	di.drawend_y = di.spriteheight / 2 + el.h / 2;
	if (di.drawend_y >= el.h)
		di.drawend_y = el.h - 1;
	di.spritewidth = abs((int)(el.h / (di.transform_y)));
	di.drawstart_x = -di.spritewidth / 2 + di.spritescreen_x;
	if (di.drawstart_x < 0)
		di.drawstart_x = 0;
	di.drawend_x = di.spritewidth / 2 + di.spritescreen_x;
	if (di.drawend_x >= el.w)
		di.drawend_x = el.w - 1;
	return (di);
}

static void			draw_sprite_col(t_sprite_di di, int x, int tex_x,
		t_game el)
{
	int d;
	int tex_y;
	int y;
	int color;

	y = di.drawstart_y;
	while (y < di.drawend_y)
	{
		d = y * 256 - el.h * 128 + di.spriteheight * 128;
		tex_y = ((d * el.s_tex.height) / di.spriteheight) / 256;
		color = get_pixel_col(tex_x, tex_y, el.s_tex);
		if (color != 0)
			el.img_data[y * el.w + x] = color;
		y++;
	}
}

static void			draw_sprite(t_sprite_di di, t_game el)
{
	int x;
	int tex_x;

	x = di.drawstart_x;
	while (x < di.drawend_x)
	{
		tex_x = (int)(256 * (x - (-di.spritewidth / 2 + di.spritescreen_x))
				* el.s_tex.width / di.spritewidth) / 256;
		if (di.transform_y > 0 && x > 0 && x < el.w && di.transform_y <
				el.pwd_arr[x])
			draw_sprite_col(di, x, tex_x, el);
		x++;
	}
}

void				draw_sprites_new3(t_game el)
{
	int			i;
	t_sprite_di di;

	i = 0;
	while (i < el.sprite_count)
	{
		di = get_sprite_drawinfo(el.sprite_arr[i].x - el.pos.pos_x,
				el.sprite_arr[i].y - el.pos.pos_y, el);
		draw_sprite(di, el);
		i++;
	}
}
