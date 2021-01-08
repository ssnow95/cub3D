/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 13:05:18 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/10/14 11:35:22 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void		raycast_sprite2(t_vars *ap, t_sprite *a)
{
	if (a->displayed == 1 && a->dist > ap->dist)
	{
		ap->x = a->x_2d;
		ap->y = a->y_2d;
		ap->dist = a->dist;
	}
}

int			make_malloc(t_vars *ap, int len)
{
	len = ft_strlen(ap->tmp[ap->map_h]);
	if (!(ap->map[ap->map_h] = (char*)malloc((len + 1) * sizeof(char))))
		return (0);
	ap->map[ap->map_h++][len] = '\0';
	return (1);
}

void		make_map_2(t_vars *ap, int fd)
{
	write(1, "invalid map or parametrs from the file\n", 39);
	close(fd);
	exit(0);
}

int			*ft_free(char **str, int i, int size)
{
	int		j;
	int		x;

	x = 0;
	j = 0;
	while (x < i)
	{
		while (j++ < size)
			free(str[j - 1]);
		free(str[x]);
		x++;
	}
	return (NULL);
}

void		make_struct(t_vars *ap)
{
	ap->flag_for_player = 0;
	ap->block_h = 64;
	ap->block_w = 64;
	ap->fov = M_PI / 3;
	ap->flag_player = 0;
	ap->pos_x = -1;
	ap->pos_y = -1;
	ap->flag_n = 0;
	ap->flag_s = 0;
	ap->flag_west = 0;
	ap->flag_east = 0;
	ap->flag_sprite = 0;
	ap->map = NULL;
	ap->tmp = NULL;
	ap->map_w = -1;
	ap->map_h = -1;
	ap->floor = -1;
	ap->ceil = -1;
}
