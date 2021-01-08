/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 22:37:34 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/10/18 13:04:02 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int		create_rgb(t_vars *ap)
{
	return (ap->r << 16 | ap->g << 8 | ap->b);
}

int		check_repeat_rgb(t_vars *ap, int *f_or_c)
{
	if ((*f_or_c != -1) && ((ap->rgb != -1) || (ap->r != -1)
		|| (ap->g != -1) || (ap->b != -1)))
	{
		*f_or_c = -12;
		return (0);
	}
	else
		return (1);
}

int		creat_color_rgb(int i, char *str, t_vars *ap)
{
	while (str[i] == ' ')
		i++;
	i = create_color_r(str, i, ap, 0);
	while (str[i] == ' ')
		i++;
	if (str[i] == ',')
		i = create_color_g(str, ++i, ap, 0);
	while (str[i] == ' ')
		i++;
	if (str[i] == ',')
		i = create_color_b(str, ++i, ap, 0);
	if (str[i] != '\0')
		return (0);
	return (1);
}

void	zero_rgb(t_vars *ap)
{
	ap->r = -1;
	ap->g = -1;
	ap->b = -1;
}

int		put_color(t_vars *ap, char *str, int *f_or_c)
{
	int		i;

	if (check_repeat_rgb(ap, f_or_c))
	{
		i = 0;
		if ((str[i] == 'F' && str[i + 1] != ' ')
			|| (str[i] == 'C' && str[i + 1] != ' '))
			return (0);
		i++;
		if (!(creat_color_rgb(i, str, ap)))
			return (0);
		if (ap->r != -1 && ap->g != -1 && ap->b != -1)
		{
			*f_or_c = create_rgb(ap);
			return (1);
		}
		else if ((ap->r == -1 && ap->g == -1 && ap->b == -1) || *f_or_c == -1)
			return (0);
	}
	return (1);
}
