/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:36:12 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/10/14 11:36:13 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void		key_13_1_0_2(int key, t_vars *ap)
{
	if (key == 13)
		if (check_wall_up(ap))
		{
			ap->pl_pix_y += sin(ap->player_a) * 16;
			ap->pl_pix_x += cos(ap->player_a) * 16;
		}
	if (key == 1)
		if (check_wall_down(ap))
		{
			ap->pl_pix_y -= sin(ap->player_a) * 16;
			ap->pl_pix_x -= cos(ap->player_a) * 16;
		}
	if (key == 0)
		if (check_wall_left(ap))
		{
			ap->pl_pix_y -= sin(ap->player_a + M_PI_2) * 10;
			ap->pl_pix_x -= cos(ap->player_a + M_PI_2) * 10;
		}
	if (key == 2)
		if (check_wall_right(ap))
		{
			ap->pl_pix_y += sin(ap->player_a + M_PI_2) * 10;
			ap->pl_pix_x += cos(ap->player_a + M_PI_2) * 10;
		}
}

void		key_123_124_125_126(int key, t_vars *ap)
{
	if (key == 123)
		ap->player_a -= 0.1;
	if (key == 124)
		ap->player_a += 0.1;
	if (key == 125)
		if (check_wall_down(ap))
		{
			ap->pl_pix_y -= (sin(ap->player_a) * 16);
			ap->pl_pix_x -= (cos(ap->player_a) * 16);
		}
	if (key == 126)
		if (check_wall_up(ap))
		{
			ap->pl_pix_y += (sin(ap->player_a) * 16);
			ap->pl_pix_x += (cos(ap->player_a) * 16);
		}
}
