/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 05:15:01 by abibi             #+#    #+#             */
/*   Updated: 2020/09/23 06:31:08 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	pos_correction(t_game *el, float oldpos_x, float oldpos_y)
{
	if (el->pos.pos_x - floor(el->pos.pos_x) == 0 &&
		el->map.map[(int)el->pos.pos_y][(int)el->pos.pos_x - 1] == '1')
	{
		el->pos.pos_x = oldpos_x;
		el->pos.pos_y = oldpos_y;
	}
	if (el->pos.pos_y - floor(el->pos.pos_y) == 0 &&
		el->map.map[(int)el->pos.pos_y - 1][(int)el->pos.pos_x] == '1')
	{
		el->pos.pos_x = oldpos_x;
		el->pos.pos_y = oldpos_y;
	}
	if (el->pos.pos_y - floor(el->pos.pos_y) == 0 &&
	el->pos.pos_x - floor(el->pos.pos_x) == 0 &&
	el->map.map[(int)el->pos.pos_y - 1][(int)el->pos.pos_x - 1] == '1')
	{
		el->pos.pos_y = oldpos_y;
		el->pos.pos_x = oldpos_x;
	}
}

static void	pos_move_left_right(int key, t_game *el)
{
	double	ms;
	float	oldpos_x;
	float	oldpos_y;

	ms = 0.5;
	oldpos_x = el->pos.pos_x;
	oldpos_y = el->pos.pos_y;
	if (el->map.map[(int)(el->pos.pos_y + el->pos.dir_x * ms)]
			[(int)(el->pos.pos_x)] == '0' && key == KEY_D)
		el->pos.pos_y += el->pos.dir_x * ms;
	if (el->map.map[(int)(el->pos.pos_y)]
			[(int)(el->pos.pos_x - el->pos.dir_y * ms)] == '0' && key == KEY_D)
		el->pos.pos_x -= el->pos.dir_y * ms;
	if (el->map.map[(int)(el->pos.pos_y - el->pos.dir_x * ms)]
			[(int)(el->pos.pos_x)] == '0' && key == KEY_A)
		el->pos.pos_y -= el->pos.dir_x * ms;
	if (el->map.map[(int)(el->pos.pos_y)]
			[(int)(el->pos.pos_x + el->pos.dir_y * ms)] == '0' && key == KEY_A)
		el->pos.pos_x += el->pos.dir_y * ms;
	pos_correction(el, oldpos_x, oldpos_y);
}

static void	pos_move_fw_bk(int key, t_game *el)
{
	double	ms;
	float	oldpos_x;
	float	oldpos_y;

	oldpos_x = el->pos.pos_x;
	oldpos_y = el->pos.pos_y;
	ms = 0.5;
	if (el->map.map[(int)(el->pos.pos_y + el->pos.dir_y * ms)]
			[(int)(el->pos.pos_x)] == '0' && key == KEY_W)
		el->pos.pos_y += el->pos.dir_y * ms;
	if (el->map.map[(int)(el->pos.pos_y)]
			[(int)(el->pos.pos_x + el->pos.dir_x * ms)] == '0' && key == KEY_W)
		el->pos.pos_x += el->pos.dir_x * ms;
	if (el->map.map[(int)(el->pos.pos_y - el->pos.dir_y * ms)]
			[(int)(el->pos.pos_x)] == '0' && key == KEY_S)
		el->pos.pos_y -= el->pos.dir_y * ms;
	if (el->map.map[(int)(el->pos.pos_y)]
			[(int)(el->pos.pos_x - el->pos.dir_x * ms)] == '0' && key == KEY_S)
		el->pos.pos_x -= el->pos.dir_x * ms;
	pos_correction(el, oldpos_x, oldpos_y);
}

static void	pos_rotate(int key, t_game *el)
{
	double olddir_x;
	double oldplane_x;
	double rsp;

	rsp = M_PI / 4;
	olddir_x = el->pos.dir_x;
	oldplane_x = el->pos.plane_x;
	if (key == KEY_R_ARR)
	{
		el->pos.dir_x = el->pos.dir_x * cos(rsp) - el->pos.dir_y * sin(rsp);
		el->pos.dir_y = olddir_x * sin(rsp) + el->pos.dir_y * cos(rsp);
		el->pos.plane_x = el->pos.plane_x * cos(rsp) - el->pos.plane_y *
			sin(rsp);
		el->pos.plane_y = oldplane_x * sin(rsp) + el->pos.plane_y * cos(rsp);
	}
	if (key == KEY_L_ARR)
	{
		el->pos.dir_x = el->pos.dir_x * cos(-rsp) - el->pos.dir_y * sin(-rsp);
		el->pos.dir_y = olddir_x * sin(-rsp) + el->pos.dir_y *
			cos(-rsp);
		el->pos.plane_x = el->pos.plane_x * cos(-rsp) - el->pos.plane_y *
			sin(-rsp);
		el->pos.plane_y = oldplane_x * sin(-rsp) + el->pos.plane_y * cos(-rsp);
	}
}

int			deal_key(int key, t_game *el)
{
	if (key == KEY_W || key == KEY_S)
		pos_move_fw_bk(key, el);
	if (key == KEY_A || key == KEY_D)
		pos_move_left_right(key, el);
	if (key == KEY_L_ARR || key == KEY_R_ARR)
		pos_rotate(key, el);
	if (key == KEY_ESC)
		close_event(el);
	render_image(el);
	return (1);
}
