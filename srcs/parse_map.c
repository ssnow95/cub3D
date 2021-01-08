/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:28:38 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/10/14 11:28:41 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int		check_type_map(char *str)
{
	int		i;
	char	*type;

	type = ".cub";
	i = 0;
	while (str[i] != '\0')
		i++;
	if (i < 6)
		return (0);
	i -= 4;
	while (str[i++] == *type++)
	{
		if (str[i] == '\0' && *type == '\0')
			return (1);
	}
	return (0);
}

int		make_new_map(t_vars *ap, char *str, int i)
{
	int		a;
	int		len;

	while (ap->map_h < i)
		make_malloc(ap, len);
	len = ft_strlen(str);
	if (!(ap->map[ap->map_h] = (char*)malloc((len + 1) * sizeof(char))))
		return (0);
	ap->map[ap->map_h][ft_strlen(str)] = '\0';
	ap->map_h = 0;
	while (ap->map[ap->map_h] != '\0' && ap->map_h < i)
	{
		a = 0;
		while (a++ < ft_strlen(ap->tmp[ap->map_h]))
			ap->map[ap->map_h][a - 1] = ap->tmp[ap->map_h][a - 1];
		free(ap->tmp[ap->map_h]);
		ap->map_h++;
	}
	free(ap->tmp);
	a = 0;
	while (a++ < ft_strlen(str))
		ap->map[ap->map_h][a - 1] = str[a - 1];
	return (1);
}

int		make_arr_cpy(int i, t_vars *ap, int len, int j)
{
	int		a;
	int		b;

	if (!(ap->tmp = (char**)malloc((i + 1) * sizeof(char*))))
		return (0);
	ap->tmp[i] = NULL;
	while (j++ < i)
	{
		b = ft_strlen(ap->map[j - 1]);
		if (!(ap->tmp[j - 1] = (char*)malloc(b + 1 * sizeof(char))))
			return (0);
		ap->tmp[j - 1][ft_strlen(ap->map[j - 1])] = '\0';
	}
	j = 0;
	while (ap->tmp[j++] != '\0')
	{
		a = 0;
		len = ft_strlen(ap->map[j - 1]);
		while (a++ < len)
			ap->tmp[j - 1][a - 1] = ap->map[j - 1][a - 1];
		free(ap->map[j - 1]);
	}
	free(ap->map);
	return (1);
}

int		make_one_str(t_vars *ap, int len, char *str)
{
	int			j;
	int			a;

	a = 0;
	j = 0;
	if (!(ap->map[j] = (char*)malloc((len + 1) * sizeof(char))))
		return (0);
	ap->map[j][len] = '\0';
	while (a < len)
	{
		ap->map[j][a] = str[a];
		a++;
	}
	return (1);
}

int		parse_map(t_vars *ap, char *str, int i, int flag)
{
	int		a;
	char	*tmp;

	if (i == 0)
		flag++;
	else
	{
		if (!make_arr_cpy(i, ap, ft_strlen(str), 0))
			return (0);
	}
	if (!(ap->map = (char**)malloc((i + 2) * sizeof(char*))))
		return (0);
	ap->map[i + 1] = NULL;
	if (flag == 1)
		if (!(make_one_str(ap, ft_strlen(str), str)))
			return (0);
	if (flag == 0)
	{
		a = 0;
		ap->map_h = 0;
		if (!(make_new_map(ap, str, i)))
			return (0);
	}
	return (1);
}
