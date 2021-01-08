/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 18:28:32 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/10/13 18:28:35 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int			make_lst_sprites(t_vars *ap)
{
	int			i;
	int			j;
	t_sprite	*new;

	i = -1;
	ap->sprites = NULL;
	while (ap->map[++i] != '\0')
	{
		j = -1;
		while (ap->map[i][++j] != '\0')
		{
			if (ap->map[i][j] == '2')
			{
				if (!(new = (t_sprite*)malloc(sizeof(t_sprite))))
					return (0);
				new->displayed = -1;
				new->x_2d = j;
				new->y_2d = i;
				new->next = NULL;
				ft_lstadd_back(&ap->sprites, new);
			}
		}
	}
	return (1);
}

int			make_map_sprite(t_vars *ap)
{
	int		i;
	int		j;

	i = -1;
	if (!(ap->map_spr = (char**)malloc((ap->map_h + 2) * sizeof(char*))))
		return (0);
	ap->map_spr[ap->map_h + 1] = NULL;
	while (++i <= ap->map_h)
	{
		if (!(ap->map_spr[i] = (char*)malloc((ap->map_w + 2) * sizeof(char))))
			return (0);
		ap->map_spr[i][ap->map_w + 1] = '\0';
	}
	i = -1;
	while (ap->map_spr[++i] != '\0')
	{
		j = -1;
		while (++j <= ap->map_w)
			ap->map_spr[i][j] = '0';
	}
	return (1);
}

int			pix_color_s(t_texture *text, int x, int y, float line)
{
	int		index;
	int		*dst;

	x = x * text->width / line;
	y = y * text->height / line;
	index = (x + y * text->width);
	dst = text->addr + index;
	return (*(unsigned int*)dst);
}

int			get_variables(t_vars *ap, t_sprite *spr, size_t i)
{
	ap->sprite_dir = atan2(spr->y_3d - ap->pl_pix_y, spr->x_3d - ap->pl_pix_x);
	while (ap->sprite_dir - ap->player_a > M_PI)
		ap->sprite_dir -= 2 * M_PI;
	while (ap->sprite_dir - ap->player_a < -M_PI)
		ap->sprite_dir += 2 * M_PI;
	ap->sprite_dist = sqrt(pow(ap->pl_pix_x - spr->x_3d, 2)
					+ pow(ap->pl_pix_y - spr->y_3d, 2));
	ap->s_scr_size = (ap->block_h * ap->dist_to_pp / ap->sprite_dist);
	ap->h_of = (ap->sprite_dir - ap->player_a) * ((ap->win_x) /
					(M_PI / 3)) + (ap->win_x) / 2 - ap->s_scr_size / 2;
	ap->v_of = ap->win_y / 2 - ap->s_scr_size / 2;
	if (ap->h_of < 0)
		i = (ap->h_of * (-1) - 1);
	return (i);
}

void		draw_sprite(t_vars *ap, t_sprite *sprite, size_t i)
{
	if (ap->sprite)
	{
		get_variables(ap, sprite, i);
		while (++i < ap->s_scr_size)
		{
			ap->j = -1;
			if (ap->h_of + (int)i < 0 || ap->h_of + i >= ap->win_x)
				continue ;
			while (++ap->j < ap->s_scr_size)
			{
				if (ap->v_of + (int)ap->j < 0 || ap->v_of + ap->j >= ap->win_y)
					continue ;
				draw_sprite2(ap, i, ap->j);
			}
		}
		sprite->displayed = 0;
	}
	else
	{
		write(1, "texture's sprite can't be taken\n", 33);
		exit(0);
	}
}
