/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_square_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:33:37 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/10/14 13:55:59 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void		add_one_to_line_start(t_vars *ap, int j, char *line)
{
	while (line[j] == ' ')
	{
		ap->new_arr[j] = '1';
		j++;
	}
	while (line[j])
	{
		ap->new_arr[j] = line[j];
		j++;
	}
}

void		add_one_to_line_end(t_vars *ap, int j, char *line)
{
	while (line[j])
	{
		ap->new_arr[j] = line[j];
		j++;
	}
	while (j < ap->map_w + 1)
	{
		ap->new_arr[j] = '1';
		j++;
	}
}

char		*add_one_to_line(t_vars *ap, char *line, int i)
{
	int		j;

	j = 0;
	if (ft_strlen(line) < ap->map_w + 1)
	{
		ap->new_arr = (char*)malloc(ap->map_w + 2 * sizeof(char));
		ap->new_arr[ap->map_w + 1] = '\0';
		if (line[j] == ' ')
			add_one_to_line_start(ap, j, line);
		else
			add_one_to_line_end(ap, j, line);
		free(line);
		return (ap->new_arr);
	}
	return (line);
}

void		make_square_map(t_vars *ap)
{
	char		*line;
	int			i;

	line = NULL;
	i = 0;
	while (ap->map[i] != '\0')
	{
		ap->map[i] = add_one_to_line(ap, ap->map[i], i);
		ap->map[i] = add_one_to_line(ap, ap->map[i], i);
		i++;
	}
}
