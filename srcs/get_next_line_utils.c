/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 16:22:08 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/08/25 17:15:31 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_strlen(const char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char		*arr;
	int			len1;
	size_t		sum;
	size_t		i;

	i = 0;
	if (!s2 && !s1)
		return (0);
	len1 = ft_strlen((char*)s1);
	sum = (len1 + ft_strlen((char*)s2)) + 1;
	if (!(arr = (char*)malloc(sizeof(char) * sum)))
		return (NULL);
	if (!(!s1))
		while (*s1 != '\0')
			arr[i++] = *s1++;
	while (*s2 != '\0')
		arr[i++] = *s2++;
	arr[i] = '\0';
	return (arr);
}
