/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 18:37:24 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/10/13 18:37:28 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int			check_wall_up(t_vars *ap)
{
	int		height;
	int		width;

	height = 0;
	width = 0;
	while ((ap->pl_pix_y + (sin(ap->player_a) * 55) >= height))
		height = height + ap->block_h;
	height = (height / ap->block_h) - 1;
	while ((ap->pl_pix_x + (cos(ap->player_a) * 55) >= width))
		width = width + ap->block_w;
	width = (width / ap->block_w) - 1;
	if (ap->map[height][width] == '1')
		return (0);
	return (1);
}

int			check_wall_down(t_vars *ap)
{
	int		height;
	int		width;

	height = 0;
	width = 0;
	while ((ap->pl_pix_y - (sin(ap->player_a) * 55)) >= height)
		height = height + ap->block_h;
	height = (height / ap->block_h) - 1;
	while ((ap->pl_pix_x - (cos(ap->player_a) * 55)) >= width)
		width = width + ap->block_w;
	width = (width / ap->block_w) - 1;
	if (ap->map[height][width] == '1')
		return (0);
	return (1);
}

int			check_wall_right(t_vars *ap)
{
	int		height;
	int		width;

	height = 0;
	width = 0;
	while ((ap->pl_pix_y + (sin(ap->player_a + M_PI_2) * 32)) >= height)
		height = height + ap->block_h;
	height = (height / ap->block_h) - 1;
	while ((ap->pl_pix_x + (cos(ap->player_a + M_PI_2) * 32)) >= width)
		width = width + ap->block_w;
	width = (width / ap->block_w) - 1;
	if (ap->map[height][width] == '1')
		return (0);
	return (1);
}

int			check_wall_left(t_vars *ap)
{
	int		height;
	int		width;

	height = 0;
	width = 0;
	while ((ap->pl_pix_y - (sin(ap->player_a + M_PI_2) * 32)) >= height)
		height = height + ap->block_h;
	height = (height / ap->block_h) - 1;
	while ((ap->pl_pix_x - (cos(ap->player_a + M_PI_2) * 32)) >= width)
		width = width + ap->block_w;
	width = (width / ap->block_w) - 1;
	if (ap->map[height][width] == '1')
		return (0);
	return (1);
}

int			press_key(int key, t_vars *ap)
{
	if (key == 13 || key == 1 || key == 0 || key == 2)
		key_13_1_0_2(key, ap);
	if (key == 53)
	{
		mlx_destroy_window(ap->mlx, ap->win);
		exit(0);
	}
	if (key == 123 || key == 124 || key == 125 || key == 126)
		key_123_124_125_126(key, ap);
	mlx_destroy_image(ap->mlx, ap->img);
	ap->img = mlx_new_image(ap->mlx, ap->win_x, ap->win_y);
	ap->addr = mlx_get_data_addr(ap->img, &ap->bits_per_pixel, &ap->line_length,
								&ap->endian);
	raycast_sprite(ap);
	return (key);
}
