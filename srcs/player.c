/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:30:34 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/10/14 11:30:35 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void		player_direct(t_vars *ap, char direction, int i, int j)
{
	ap->pl_pix_x = ((j * ap->block_w) + (ap->block_w / 2));
	ap->pl_pix_y = ((i * ap->block_h) + (ap->block_h / 2));
	if (direction == 'N')
		ap->player_a = 3 * M_PI_2;
	if (direction == 'E')
		ap->player_a = 0;
	if (direction == 'W')
		ap->player_a = M_PI;
	if (direction == 'S')
		ap->player_a = M_PI_2;
}

int			coord_player(t_vars *ap, char **str, int i, int j)
{
	the_longest_row(ap);
	i = -1;
	while (str[++i] != '\0')
	{
		j = -1;
		while (str[i][++j] != '\0')
		{
			if (ap->flag_for_player == 0 && (str[i][j] == 'N' ||
			str[i][j] == 'S' || str[i][j] == 'E' || str[i][j] == 'W'))
			{
				ap->flag_for_player = 1;
				player_direct(ap, str[i][j], i, j);
				if (i == 0 || i == ap->map_h || j == (ft_strlen(str[i]) - 1)
				|| j == 0)
					return (0);
			}
			else if ((ap->flag_for_player == 1 && (str[i][j] == 'N' ||
			str[i][j] == 'S' || str[i][j] == 'E' || str[i][j] == 'W')))
				return (0);
		}
	}
	if (ap->flag_for_player == 0)
		return (0);
	return (1);
}
