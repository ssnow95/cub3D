/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 14:39:37 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/08/21 19:34:27 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*resave_line(char *save_str)
{
	int		i;
	int		j;
	char	*new_arr;

	i = 0;
	j = 0;
	if (!save_str)
		return (0);
	while (save_str[i] && save_str[i] != '\n')
		i++;
	if (!save_str[i])
	{
		free(save_str);
		return (0);
	}
	if (!(new_arr = malloc(sizeof(char) * ((ft_strlen(save_str) - i) + 1))))
		return (0);
	i++;
	while (save_str[i])
		new_arr[j++] = save_str[i++];
	new_arr[j] = '\0';
	free(save_str);
	return (new_arr);
}

char		*get_one_line(char *save_str)
{
	int		i;
	char	*new_arr;

	i = 0;
	if (!save_str)
		return (0);
	while (save_str[i] && save_str[i] != '\n')
		i++;
	if (!(new_arr = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while ((save_str[i] && save_str[i] != '\n'))
	{
		new_arr[i] = save_str[i];
		i++;
	}
	new_arr[i] = '\0';
	return (new_arr);
}

int			check_new_line(char *save_str)
{
	int		i;

	i = 0;
	if (save_str)
	{
		while (save_str[i])
		{
			if (save_str[i] == '\n')
				return (1);
			i++;
		}
	}
	return (0);
}

int			get_next_line(int fd, char **line)
{
	char			*buf;
	static char		*save_str;
	int				quant_sym;
	char			*delete;

	quant_sym = 1;
	if (fd < 0 || !line || 10 <= 0 ||
		!(buf = malloc(sizeof(char) * (10 + 1))))
		return (-1);
	while (!check_new_line(save_str) && quant_sym != 0)
	{
		if ((quant_sym = read(fd, buf, 10)) == -1)
		{
			free(buf);
			return (-1);
		}
		buf[quant_sym] = '\0';
		delete = save_str;
		save_str = ft_strjoin(save_str, buf);
		free(delete);
	}
	free(buf);
	*line = get_one_line(save_str);
	save_str = resave_line(save_str);
	return (quant_sym == 0) ? 0 : 1;
}
