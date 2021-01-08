/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 22:13:24 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/10/18 13:03:39 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int			adge_of_map2(t_vars *ap, int i, int j)
{
	if (i == 0 && (ap->map[i][j] != ' ' && ap->map[i][j] != '1'))
		return (0);
	if (i > 0)
		if (!(check_first_row(ap, i)))
			return (0);
	if (i > 0)
		if (!(check_last_row(ap, i)))
			return (0);
	return (1);
}

int			adge_of_map(t_vars *ap, int i, int j)
{
	while (ap->map[i] != '\0')
	{
		j = 0;
		while (ap->map[i][j] != '\0')
		{
			if (!(adge_of_map2(ap, i, j)))
				return (0);
			if (i == ap->map_h && (ap->map[i][j] != '1'
				&& ap->map[i - 1][j] != ' '))
				return (0);
			if (j == 0 && ((ap->map[i][j] != '1')
				&& ap->map[i][j] != ' '))
				return (0);
			if (j == (ft_strlen(ap->map[i]) - 1) && ((ap->map[i][j] != '1')
				&& ap->map[i][j] != ' '))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int			check_sym_map(char c)
{
	char	*str;
	int		i;

	i = 0;
	str = "012NSWE";
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int			search_space(t_vars *ap)
{
	int		i;
	int		j;

	i = 0;
	while (ap->map[i] != '\0')
	{
		j = 0;
		while (ap->map[i][j] != '\0')
		{
			if (ap->map[i][j] == '2' || ap->map[i][j] == '0')
			{
				if ((!check_sym_map(ap->map[i][j - 1]) ||
				!(check_sym_map(ap->map[i][j + 1]))))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int			check_map(t_vars *ap)
{
	if (!(adge_of_map(ap, 0, 0)))
		return (0);
	if (!(search_space(ap)))
		return (0);
	else
		return (1);
}
