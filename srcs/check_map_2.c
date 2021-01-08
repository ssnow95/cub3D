/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:36:42 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/10/18 12:30:32 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int		check_first_row(t_vars *ap, int j)
{
	int		i;

	i = 0;
	while (ap->map[j][i] != '\0')
	{
		if (ap->map[j][i] == '0' || ap->map[j][i] == '2')
		{
			if (i > ft_strlen(ap->map[j - 1]) - 1)
				return (0);
			if (ap->map[j - 1][i] == ' ')
				return (0);
		}
		if (ap->map[j][i] != '0' && ap->map[j][i] != '2' &&
			ap->map[j][i] != '1' && ap->map[j][i] != ' ' &&
			ap->map[j][i] != 'S' && ap->map[j][i] != 'W' &&
			ap->map[j][i] != 'E' && ap->map[j][i] != 'N')
			return (0);
		i++;
	}
	return (1);
}

int		check_last_row(t_vars *ap, int i)
{
	int		j;

	j = 0;
	while (ap->map[i][j] != '\0')
	{
		if (ap->map[i][j] == '0' || ap->map[i][j] == '2')
		{
			if (j > (ft_strlen(ap->map[i + 1]) - 1))
				return (0);
			if (ap->map[i + 1][j] == ' ')
				return (0);
		}
		if (ap->map[i][j] != '0' && ap->map[i][j] != '2' &&
			ap->map[i][j] != '1' && ap->map[i][j] != ' ' &&
			ap->map[i][j] != 'S' && ap->map[i][j] != 'W' &&
			ap->map[i][j] != 'E' && ap->map[i][j] != 'N')
			return (0);
		j++;
	}
	return (1);
}
