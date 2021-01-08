/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 18:36:13 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/10/18 11:57:04 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int			get_size_window(t_vars *ap, char *line, int i)
{
	while (line[i] == ' ')
		i++;
	if (line[i] >= '0' && line[i] <= '9' && line[i] != '\0')
		ap->win_x++;
	while (line[i] >= '0' && line[i] <= '9')
	{
		if ((ap->win_x * 10 + (line[i] - '0')) > 21474836)
			return (0);
		ap->win_x = ap->win_x * 10 + (line[i++] - '0');
	}
	while (line[i] == ' ')
		i++;
	if (line[i] >= '0' && line[i] <= '9' && line[i] != '\0')
		ap->win_y++;
	while (line[i] >= '0' && line[i] <= '9')
	{
		if ((ap->win_y * 10 + (line[i] - '0')) > 21474836)
			return (0);
		ap->win_y = ap->win_y * 10 + (line[i++] - '0');
	}
	while (line[i] == ' ')
		i++;
	if (line[i] != '\0' || ap->win_y < 0 || ap->win_y < 0)
		return (0);
	return (1);
}

int			make_size_window(t_vars *ap, char *line)
{
	line++;
	if (ap->win_x++ == -2 && ap->win_y++ == -2)
	{
		if (!(get_size_window(ap, line, 1)))
			return (0);
		mlx_get_screen_size(ap->mlx, &ap->pre_win_x, &ap->pre_win_y);
		if (ap->win_x > 2560)
			ap->win_x = ap->pre_win_x;
		if (ap->win_y > 1440)
			ap->win_y = ap->pre_win_y;
		if (ap->win_x < 30)
			ap->win_x = 30;
		if (ap->win_y < 30)
			ap->win_y = 30;
		return (1);
	}
	return (0);
}
