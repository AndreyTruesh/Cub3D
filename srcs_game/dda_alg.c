/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_alg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 05:13:11 by abibi             #+#    #+#             */
/*   Updated: 2020/09/22 05:14:27 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		dda_get_initial_dists(t_rc *rc, t_game *el)
{
	if (rc->raydir_x < 0)
	{
		rc->step_x = -1;
		rc->sidedist_x = (el->pos.pos_x - rc->map_x) * rc->deltadist_x;
	}
	else
	{
		rc->step_x = 1;
		rc->sidedist_x = (rc->map_x + 1.0 - el->pos.pos_x) * rc->deltadist_x;
	}
	if (rc->raydir_y < 0)
	{
		rc->step_y = -1;
		rc->sidedist_y = (el->pos.pos_y - rc->map_y) * rc->deltadist_y;
	}
	else
	{
		rc->step_y = 1;
		rc->sidedist_y = (rc->map_y + 1.0 - el->pos.pos_y) * rc->deltadist_y;
	}
}

static void		dda_initial_calcs(double raydir_x, double raydir_y, t_rc *rc,
		t_game *el)
{
	rc->map_x = el->pos.pos_x;
	rc->map_y = el->pos.pos_y;
	rc->raydir_x = raydir_x;
	rc->raydir_y = raydir_y;
	rc->deltadist_x = fabs(1 / rc->raydir_x);
	rc->deltadist_y = fabs(1 / rc->raydir_y);
	dda_get_initial_dists(rc, el);
}

static t_rc_res	calculate_rc_res(t_rc rc, t_game *el)
{
	t_rc_res res;

	if (rc.side == 0)
		res.pwalldist = (rc.map_x - el->pos.pos_x + (1 - rc.step_x) / 2) /
			rc.raydir_x;
	else
		res.pwalldist = (rc.map_y - el->pos.pos_y + (1 - rc.step_y) / 2) /
			rc.raydir_y;
	res.side = rc.side;
	res.raydir_x = rc.raydir_x;
	res.raydir_y = rc.raydir_y;
	res.lineheight = (int)(el->h / res.pwalldist);
	return (res);
}

t_rc_res		apply_dda(double raydir_x, double raydir_y, t_game *el)
{
	int			hit;
	t_rc		rc;

	hit = 0;
	dda_initial_calcs(raydir_x, raydir_y, &rc, el);
	while (hit == 0)
	{
		if (rc.sidedist_x < rc.sidedist_y)
		{
			rc.sidedist_x += rc.deltadist_x;
			rc.map_x += rc.step_x;
			rc.side = 0;
		}
		else
		{
			rc.sidedist_y += rc.deltadist_y;
			rc.map_y += rc.step_y;
			rc.side = 1;
		}
		if (el->map.map[rc.map_y][rc.map_x] == '1')
			hit = 1;
	}
	return (calculate_rc_res(rc, el));
}
