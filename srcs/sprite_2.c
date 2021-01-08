/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:29:06 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/10/14 11:29:49 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void		ft_lstadd_back(t_sprite **sprite, t_sprite *new)
{
	if (!sprite || !new)
		return ;
	if (!*sprite)
		*sprite = new;
	else
	{
		while ((*sprite)->next)
			sprite = &(*sprite)->next;
		(*sprite)->next = new;
	}
}

t_sprite	*find_sprite_from_lst(t_vars *ap, int y, int x)
{
	t_sprite	*find_sprite;

	find_sprite = ap->sprites;
	while (find_sprite)
	{
		if (find_sprite->x_2d == x && find_sprite->y_2d == y)
			break ;
		find_sprite = find_sprite->next;
	}
	return (find_sprite);
}

void		get_sprite(t_vars *ap, t_sprite *sprite, int y, int x)
{
	if (sprite->displayed != 1)
	{
		sprite->displayed = 1;
		sprite->x_3d = (x * ap->block_w) + (ap->block_w / 2);
		sprite->y_3d = (y * ap->block_h) + (ap->block_h / 2);
		sprite->dist = sqrt(pow(ap->pl_pix_x - sprite->x_3d, 2)
						+ pow(ap->pl_pix_y - sprite->y_3d, 2));
	}
}

void		draw_sprite2(t_vars *ap, size_t i, size_t j)
{
	ap->color = pix_color_s(ap->sprite, i, ap->j, ap->s_scr_size);
	if (ap->color != 0 && ((ap->h_of + i) < ap->win_x)
		&& ((ap->v_of + ap->j) < ap->win_y) && ap->sprite_dist
		< ap->arr_rays[ap->h_of + i])
		my_mlx_pixel_put(ap, ap->h_of + i, ap->v_of + ap->j, ap->color);
}
