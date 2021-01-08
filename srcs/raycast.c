/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:33:18 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/10/14 11:33:19 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int		grid(t_vars *ap, int x, int y)
{
	if (x >= 0 && x <= ap->map_w && y >= 0 &&
		y <= ap->map_h && ap->map[y][x] == '2')
	{
		ap->map_spr[y][x] = '1';
		get_sprite(ap, find_sprite_from_lst(ap, y, x), y, x);
	}
	if (x >= 0 && x <= ap->map_w && y >= 0 &&
		y <= ap->map_h && ap->map[y][x] != '1')
		return (1);
	return (0);
}

void	check_angle(t_vars *ap)
{
	while (ap->angle < 0)
		ap->angle += 2 * M_PI;
	while (ap->angle > 2 * M_PI)
		ap->angle -= 2 * M_PI;
}

void	check_wall_0_to_m_pi(t_vars *ap)
{
	if (ap->len_h == ap->len_v)
	{
		ap->len_v = ap->pre_vertical;
		ap->len_h = ap->pre_horizontal;
	}
	if (ap->angle > 0 && ap->angle < M_PI / 2)
	{
		if (ap->len_v < ap->len_h)
			ap->wall_site = 'E';
		else
			ap->wall_site = 'N';
	}
	if (ap->angle > M_PI / 2 && ap->angle < M_PI)
	{
		if (ap->len_v < ap->len_h)
			ap->wall_site = 'W';
		else
			ap->wall_site = 'N';
	}
}

void	check_wall_m_pi_to_2_m_pi(t_vars *ap)
{
	if (ap->angle > M_PI && ap->angle < 3 * M_PI / 2)
	{
		if (ap->len_v < ap->len_h)
			ap->wall_site = 'W';
		else
			ap->wall_site = 'S';
	}
	if (ap->angle > 3 * M_PI / 2 && ap->angle < 2 * M_PI)
	{
		if (ap->len_v < ap->len_h)
			ap->wall_site = 'E';
		else
			ap->wall_site = 'S';
	}
	if (ap->wall_site == 'E' || ap->wall_site == 'W')
		ap->tex_pos = (float)((int)ap->by % 64);
	else
		ap->tex_pos = (float)((int)ap->ax % 64);
}
