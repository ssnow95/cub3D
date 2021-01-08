/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:30:19 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/10/14 13:10:27 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void		free_texture(t_vars *ap)
{
	if (ap->n)
		mlx_destroy_image(ap->mlx, ap->n->img);
	if (ap->s)
		mlx_destroy_image(ap->mlx, ap->s->img);
	if (ap->east)
		mlx_destroy_image(ap->mlx, ap->east->img);
	if (ap->west)
		mlx_destroy_image(ap->mlx, ap->west->img);
	if (ap->sprite)
		mlx_destroy_image(ap->mlx, ap->sprite->img);
}

int			parse_texture(t_vars *ap, char *str)
{
	int		i;

	i = 0;
	if (str[i] == 'N' && str[i + 1] == 'O' && str[i + 2] == ' '
			&& ap->flag_n == 0)
		ap->n = make_t(ap->mlx, str, ap->flag_n++, ap);
	else if (str[i] == 'S' && str[i + 1] == 'O' && str[i + 2] == ' '
			&& ap->flag_s == 0)
		ap->s = make_t(ap->mlx, str, ap->flag_s++, ap);
	else if (str[i] == 'E' && str[i + 1] == 'A' && str[i + 2] == ' '
			&& ap->flag_east == 0)
		ap->east = make_t(ap->mlx, str, ap->flag_east++, ap);
	else if (str[i] == 'W' && str[i + 1] == 'E' && str[i + 2] == ' '
			&& ap->flag_west == 0)
		ap->west = make_t(ap->mlx, str, ap->flag_west++, ap);
	else if (str[i] == 'S' && str[i + 1] == ' ' && ap->flag_sprite == 0)
		ap->sprite = make_t(ap->mlx, str, ap->flag_sprite++, ap);
	else
		return (0);
	return (1);
}

t_texture	*make_t(void *mlx_ptr, char *s, int flag, t_vars *ap)
{
	t_texture		*t;
	int				bpp;
	int				len;
	int				end;

	while ((*s >= 'A' && *s <= 'Z') || *s == ' ')
		s++;
	if (!(t = malloc(sizeof(t_texture))))
		return (0);
	if (!(t->img = mlx_xpm_file_to_image(ap->mlx, s, &t->width, &t->height)))
		return (0);
	t->addr = (int *)mlx_get_data_addr(t->img, &bpp, &len, &end);
	return (t);
}
