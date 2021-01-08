/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:28:14 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/10/14 11:28:17 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void		raycast(t_vars *ap, int i)
{
	ap->arr_rays = (float*)malloc((ap->win_x + 1) * sizeof(float));
	ap->arr_rays[ap->win_x] = '\0';
	while (++i < ap->win_x)
	{
		ap->angle = ap->player_a - ap->fov / 2 + ap->fov / (float)ap->win_x * i;
		if (ap->angle > 2 * M_PI || ap->angle < 0)
			check_angle(ap);
		raycast_horizontal(ap, i);
		raycast_vertical(ap, i);
		check_wall_0_to_m_pi(ap);
		check_wall_m_pi_to_2_m_pi(ap);
		if (ap->len_h < ap->len_v)
		{
			ap->arr_rays[i] = ap->len_h;
			draw_column(ap, i, ap->len_h);
		}
		if (ap->len_h > ap->len_v)
		{
			ap->arr_rays[i] = ap->len_v;
			draw_column(ap, i, ap->len_v);
		}
	}
}

void		raycast_vertical(t_vars *ap, int i)
{
	if (i > 0)
		ap->pre_vertical = ap->len_v;
	if ((0 <= ap->angle && ap->angle < M_PI_2) ||
		(3 * M_PI_2 < ap->angle && ap->angle <= 2 * M_PI))
		ap->bx = ((int)ap->pl_pix_x / 64) * (64) + 64;
	if ((M_PI_2 < ap->angle && ap->angle <= M_PI) ||
		(M_PI < ap->angle && ap->angle <= 3 * M_PI_2))
		ap->bx = ((int)ap->pl_pix_x / 64) * (64) - 0.001;
	ap->by = ap->pl_pix_y - (ap->pl_pix_x - ap->bx) * tan(ap->angle);
	ap->x_v = ap->bx / 64;
	ap->y_v = ap->by / 64;
	if (grid(ap, ap->x_v, ap->y_v) && ap->map[ap->y_v][ap->x_v] != '1')
	{
		get_ya_v_and_xa_v(ap);
		ap->len_v = sqrt(pow(ap->pl_pix_x - ap->bx, 2) +
			pow(ap->pl_pix_y - ap->by, 2));
	}
	else
		ap->len_v = sqrt(pow(ap->pl_pix_x - ap->bx, 2) +
			pow(ap->pl_pix_y - ap->by, 2));
}

void		get_xa_h_and_ya_h(t_vars *ap)
{
	if (M_PI < ap->angle && ap->angle < 2 * M_PI)
		ap->xa_h = 64 / tan(ap->angle) * (-1);
	else
		ap->xa_h = 64 / tan(ap->angle);
	if ((0 < ap->angle && ap->angle < M_PI_2)
		|| (M_PI_2 < ap->angle && ap->angle < M_PI))
		ap->ya_h = 64;
	else if ((M_PI < ap->angle && ap->angle < 3 * M_PI_2)
		|| (3 * M_PI_2 < ap->angle && ap->angle < 2 * M_PI))
		ap->ya_h = -64;
	while (grid(ap, ap->x_h, ap->y_h) && ap->map[ap->y_h][ap->x_h] != '1')
	{
		ap->ax = ap->ax + ap->xa_h;
		ap->ay = ap->ay + ap->ya_h;
		ap->x_h = ap->ax / 64;
		ap->y_h = ap->ay / 64;
	}
}

void		raycast_horizontal(t_vars *ap, int i)
{
	if (i > 0)
		ap->pre_horizontal = ap->len_h;
	if ((0 < ap->angle && ap->angle <= M_PI_2)
		|| (M_PI_2 < ap->angle && ap->angle <= M_PI))
		ap->ay = ((int)ap->pl_pix_y / 64) * (64) + 64;
	if ((M_PI < ap->angle && ap->angle <= 3 * M_PI_2)
		|| (3 * M_PI_2 < ap->angle && ap->angle <= 2 * M_PI))
		ap->ay = ((int)ap->pl_pix_y / 64) * (64) - 0.001;
	ap->ax = ap->pl_pix_x + (ap->pl_pix_y - ap->ay) / tan(ap->angle) * (-1);
	ap->x_h = ap->ax / 64;
	ap->y_h = ap->ay / 64;
	if (grid(ap, ap->x_h, ap->y_h) && ap->map[ap->y_h][ap->x_h] != '1')
	{
		get_xa_h_and_ya_h(ap);
		ap->len_h = sqrt(pow(ap->pl_pix_x - ap->ax, 2)
			+ pow(ap->pl_pix_y - ap->ay, 2));
	}
	else
		ap->len_h = sqrt(pow(ap->pl_pix_x - ap->ax, 2)
			+ pow(ap->pl_pix_y - ap->ay, 2));
}

void		get_ya_v_and_xa_v(t_vars *ap)
{
	if (ap->angle < 3 * M_PI / 2 && ap->angle > M_PI / 2)
		ap->ya_v = 64 * tan(ap->angle) * (-1);
	else
		ap->ya_v = 64 * tan(ap->angle);
	if ((0 <= ap->angle && ap->angle < M_PI / 2)
		|| (3 * M_PI / 2 < ap->angle && ap->angle < 2 * M_PI))
		ap->xa_v = 64;
	else if ((M_PI / 2 < ap->angle && ap->angle < M_PI)
		|| (M_PI < ap->angle && ap->angle < 3 * M_PI / 2))
		ap->xa_v = -64;
	while (grid(ap, ap->x_v, ap->y_v) && ap->map[ap->y_v][ap->x_v] != '1')
	{
		ap->bx = ap->bx + ap->xa_v;
		ap->by = ap->by + ap->ya_v;
		ap->x_v = ap->bx / 64;
		ap->y_v = ap->by / 64;
	}
}
