/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 05:42:36 by abibi             #+#    #+#             */
/*   Updated: 2020/09/22 05:47:11 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	draw_ceiling_and_floor(int x, int drawstart, int drawend,
		t_game el)
{
	int i;

	i = 0;
	while (i < drawstart)
	{
		el.img_data[i * el.w + x] = el.c_color;
		i++;
	}
	i = drawend;
	while (i < el.h)
	{
		el.img_data[i * el.w + x] = el.f_color;
		i++;
	}
}

static void	draw_tex(t_drawinfo drawinfo, t_tex tex, t_game el)
{
	int		drawstart;
	int		drawend;
	double	step;
	double	texpos;
	int		tex_y;

	if ((drawstart = -drawinfo.lineheight / 2 + el.h / 2) < 0)
		drawstart = 0;
	if ((drawend = drawinfo.lineheight / 2 + el.h / 2) >= el.h)
		drawend = el.h - 1;
	step = 1.0 * tex.height / drawinfo.lineheight;
	texpos = (drawstart - el.h / 2 + drawinfo.lineheight / 2) * step;
	draw_ceiling_and_floor(drawinfo.x, drawstart, drawend, el);
	while (drawstart < drawend)
	{
		tex_y = (int)texpos < tex.height ? (int)texpos : (int)texpos - 1;
		texpos += step;
		el.img_data[drawstart * el.w + drawinfo.x] =
			get_pixel_col(drawinfo.tex_x, tex_y, tex);
		drawstart++;
	}
}

static void	draw_tex_so_no(t_rc_res rc_res, t_drawinfo drawinfo, t_game *el)
{
	double	wall_x;

	wall_x = el->pos.pos_x + rc_res.pwalldist * rc_res.raydir_x;
	wall_x -= floor((wall_x));
	if ((rc_res.raydir_y <= 0 && rc_res.raydir_x <= 0) ||
			(rc_res.raydir_y <= 0 && rc_res.raydir_x >= 0))
	{
		drawinfo.tex_x = (int)(wall_x * (double)(el->so_tex.width));
		drawinfo.tex_x = el->so_tex.width - drawinfo.tex_x - 1;
		draw_tex(drawinfo, el->so_tex, *el);
	}
	if ((rc_res.raydir_y >= 0 && rc_res.raydir_x <= 0) ||
			(rc_res.raydir_y >= 0 && rc_res.raydir_x >= 0))
	{
		drawinfo.tex_x = (int)(wall_x * (double)(el->no_tex.width));
		drawinfo.tex_x = el->no_tex.width - drawinfo.tex_x - 1;
		draw_tex(drawinfo, el->no_tex, *el);
	}
}

static void	draw_tex_ea_we(t_rc_res rc_res, t_drawinfo drawinfo, t_game *el)
{
	double wall_x;

	wall_x = el->pos.pos_y + rc_res.pwalldist * rc_res.raydir_y;
	wall_x -= floor((wall_x));
	if ((rc_res.raydir_y <= 0 && rc_res.raydir_x <= 0) ||
			(rc_res.raydir_y >= 0 && rc_res.raydir_x <= 0))
	{
		drawinfo.tex_x = (int)(wall_x * (double)(el->ea_tex.width));
		if (rc_res.raydir_x < 0)
			drawinfo.tex_x = el->ea_tex.width - drawinfo.tex_x - 1;
		draw_tex(drawinfo, el->ea_tex, *el);
	}
	if ((rc_res.raydir_y >= 0 && rc_res.raydir_x >= 0) ||
			(rc_res.raydir_y <= 0 && rc_res.raydir_x >= 0))
	{
		drawinfo.tex_x = (int)(wall_x * (double)(el->we_tex.width));
		if (rc_res.raydir_x < 0)
			drawinfo.tex_x = el->we_tex.width - drawinfo.tex_x - 1;
		draw_tex(drawinfo, el->we_tex, *el);
	}
}

void		render_walls(t_game *el)
{
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	t_drawinfo	drawinfo;
	t_rc_res	rc_res;

	drawinfo.x = 0;
	while (drawinfo.x < el->w)
	{
		camera_x = 2 * drawinfo.x / (double)el->w - 1;
		raydir_x = el->pos.dir_x + el->pos.plane_x * camera_x;
		raydir_y = el->pos.dir_y + el->pos.plane_y * camera_x;
		rc_res = apply_dda(raydir_x, raydir_y, el);
		drawinfo.lineheight = rc_res.lineheight;
		if (el->sprite_count > 0)
			el->pwd_arr[drawinfo.x] = rc_res.pwalldist;
		if (rc_res.side == 1)
			draw_tex_so_no(rc_res, drawinfo, el);
		else
			draw_tex_ea_we(rc_res, drawinfo, el);
		drawinfo.x++;
	}
}
