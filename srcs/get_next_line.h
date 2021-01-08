/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 16:02:48 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/10/14 11:37:11 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int				get_next_line(int fd, char **line);
char			*resave_line(char *save_str);
char			*get_one_line(char *save_str);
int				check_new_line(char *save_str);
int				ft_strlen(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);
#endif
