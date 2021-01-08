/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 22:42:41 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/10/18 13:06:19 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int		create_color_b(char *str, int i, t_vars *ap, int flag)
{
	ap->b = -1;
	while (str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (flag == 0)
		{
			flag++;
			ap->b = 0;
		}
		ap->b = ap->b * 10 + (str[i] - '0');
		i++;
	}
	if (ap->b > 255)
		ap->b = -1;
	return (i);
}

int		create_color_g(char *str, int i, t_vars *ap, int flag)
{
	ap->g = -1;
	while (str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (flag == 0)
		{
			flag++;
			ap->g = 0;
		}
		ap->g = ap->g * 10 + (str[i] - '0');
		i++;
	}
	if (ap->g > 255)
		ap->g = -1;
	return (i);
}

int		create_color_r(char *str, int i, t_vars *ap, int flag)
{
	ap->r = -1;
	while (str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (flag == 0)
		{
			flag++;
			ap->r = 0;
		}
		ap->r = ap->r * 10 + (str[i] - '0');
		i++;
	}
	if (ap->r > 255)
		ap->r = -1;
	return (i);
}
