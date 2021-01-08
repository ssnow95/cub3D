/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 13:10:53 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/10/14 12:02:00 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void		ft_free_map(t_vars *ap)
{
	int		i;
	int		j;

	i = 0;
	while (ap->map[i])
	{
		j = ap->map_h;
		while (j--)
			free(ap->map[j]);
		free(ap->map[i]);
		i++;
	}
	free(ap->map);
}

int			ft_exit(t_vars *ap)
{
	mlx_destroy_window(ap->mlx, ap->win);
	exit(0);
}

void		the_longest_row(t_vars *ap)
{
	int		i;
	int		j;

	i = 0;
	while (ap->map[i] != '\0')
	{
		j = 0;
		while (ap->map[i][j] != '\0')
		{
			if (j > ap->map_w)
				ap->map_w = j;
			j++;
		}
		i++;
	}
}

void		my_mlx_pixel_put(t_vars *ap, int x, int y, int color)
{
	char	*dst;

	dst = ap->addr + (y * ap->line_length + x * (ap->bits_per_pixel / 8));
	*(long long int*)dst = color;
}

void		make_struct1(t_vars *ap)
{
	ap->mlx = mlx_init();
	ap->win_x = -2;
	ap->win_y = -2;
	ap->rgb = -1;
	ap->r = -1;
	ap->g = -1;
	ap->b = -1;
	ap->flag = 0;
	ap->dist = 0;
	ap->line = NULL;
	ap->find_wrong = 1;
	ap->x = 0;
	ap->y = 0;
	ap->ya_v = 0;
	ap->xa_h = 0;
	ap->tex_pos = 0;
	ap->start = -1;
}
