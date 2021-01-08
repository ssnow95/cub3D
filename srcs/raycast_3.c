/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:31:48 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/10/14 11:33:04 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int		pix_color(t_texture *text, int x, int y, float line)
{
	int		index;
	int		*dst;

	y = y * text->height / line;
	index = (x + y * text->width);
	dst = text->addr + index;
	return (*(unsigned int*)dst);
}

void	get_color_wall(t_vars *ap, int col_nmb)
{
	if (ap->wall_site == 'N' && ap->n)
		ap->color_col = pix_color(ap->n, ap->tex_pos, ap->y2, ap->wall_size);
	if (ap->wall_site == 'S' && ap->s)
		ap->color_col = pix_color(ap->s, ap->tex_pos, ap->y2, ap->wall_size);
	if (ap->wall_site == 'E' && ap->east)
		ap->color_col = pix_color(ap->east, ap->tex_pos, ap->y2, ap->wall_size);
	if (ap->wall_site == 'W' && ap->west)
		ap->color_col = pix_color(ap->west, ap->tex_pos, ap->y2, ap->wall_size);
	if (!ap->n || !ap->west || !ap->s || !ap->east)
	{
		write(1, "texture's color can't be taken\n", 32);
		exit(0);
	}
	my_mlx_pixel_put(ap, col_nmb, ap->y_h, ap->color_col);
	ap->y_h++;
	ap->y2++;
}

void	draw_column(t_vars *ap, int col_nmb, float step)
{
	ap->start = -1;
	step = step * cos(ap->player_a - ap->angle);
	ap->dist_to_pp = (ap->win_x / 2) / tan(M_PI / 6);
	ap->wall_size = ap->block_h * ap->dist_to_pp / step;
	ap->centre = ap->win_y / 2;
	ap->y_h = ap->centre - (ap->wall_size / 2);
	if (ap->wall_size > ap->win_y)
	{
		ap->y_h = 0;
		ap->y2 = (ap->wall_size - ap->win_y) / 2;
	}
	else
		ap->y2 = 0;
	while (ap->y_h > ++ap->start)
		my_mlx_pixel_put(ap, col_nmb, ap->start, ap->ceil);
	while (ap->y2 < ap->wall_size && ap->y_h < ap->win_y - 1)
		get_color_wall(ap, col_nmb);
	while (ap->y_h < ap->win_y - 1)
	{
		my_mlx_pixel_put(ap, col_nmb, ap->y_h, ap->floor);
		ap->y_h++;
	}
}

int		check_vert_horiz_coord(t_vars *ap)
{
	if (ap->bx < 0 || ap->bx > ap->win_x || ap->by < 0 || ap->by > ap->win_y)
		return (0);
	if (ap->ax < 0 || ap->ax > ap->win_x || ap->ay < 0 || ap->ay > ap->win_y)
		return (2);
	return (1);
}
