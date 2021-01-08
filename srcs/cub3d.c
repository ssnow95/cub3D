/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:31:19 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/10/18 11:44:00 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int			errors(t_vars *ap)
{
	if (ap->win_x < 0 || ap->win_y < 0)
		write(1, "invalid map's size('R')", 24);
	else if (!(coord_player(ap, ap->map, 0, 0)))
		write(1, "invalid player's coordinate", 28);
	else if (!ap->flag_n || !ap->flag_s || !ap->flag_west
		|| !ap->flag_east || !ap->flag_sprite)
		write(1, "texture can't upload", 21);
	else if (ap->floor < 0 || ap->ceil < 0)
		write(1, "invalid floor or ceil('C' or 'F')", 33);
	else if (!check_map(ap))
		write(1, "invalid map", 12);
	else
		return (1);
	return (0);
}

int			parse(int fd, t_vars *ap, int i)
{
	while (get_next_line(fd, &ap->line) > 0 && ap->find_wrong == 1)
	{
		ap->tmp2 = ap->line;
		if (ap->line[0] == 'R' && ap->line[1] == ' ')
			ap->find_wrong = make_size_window(ap, ap->line);
		else if (ap->line[0] == '\0' && !ap->map)
			ap->find_wrong = 1;
		else if (ap->line[0] == 'N' || ap->line[0] == 'S' ||
			ap->line[0] == 'W' || ap->line[0] == 'E')
			ap->find_wrong = parse_texture(ap, ap->line);
		else if (ap->line[0] == 'F')
			ap->find_wrong = put_color(ap, ap->line, &ap->floor);
		else if (ap->line[0] == 'C')
			ap->find_wrong = put_color(ap, ap->line, &ap->ceil);
		else if (ap->line[0] == '1' || ap->line[0] == '2' ||
				ap->line[0] == ' ' || ap->line[0] == '0')
			ap->find_wrong = parse_map(ap, ap->line, i++, 0);
		else
			ap->find_wrong = 0;
		free(ap->tmp2);
	}
	if (ap->line[0] != '\0')
		ap->find_wrong = 0;
	free(ap->line);
	return (ap->find_wrong);
}

void		raycast_sprite(t_vars *ap)
{
	t_sprite *a;

	a = ap->sprites;
	raycast(ap, -1);
	while (1)
	{
		while (a)
		{
			raycast_sprite2(ap, a);
			a = a->next;
		}
		if (ap->x == 0 && ap->y == 0 && ap->dist == 0)
			break ;
		draw_sprite(ap, find_sprite_from_lst(ap, ap->y, ap->x), 0);
		ap->x = 0;
		ap->y = 0;
		ap->dist = 0;
		a = ap->sprites;
	}
	free(ap->arr_rays);
	mlx_put_image_to_window(ap->mlx, ap->win, ap->img, 0, 0);
}

void		make_map(int fd, int argc)
{
	t_vars ap;

	make_struct(&ap);
	make_struct1(&ap);
	if (!parse(fd, &ap, 0))
		make_map_2(&ap, fd);
	if (!errors(&ap) || !make_map_sprite(&ap))
		exit(0);
	make_lst_sprites(&ap);
	make_square_map(&ap);
	ap.win = mlx_new_window(ap.mlx, ap.win_x, ap.win_y, "ssnowbir");
	ap.img = mlx_new_image(ap.mlx, ap.win_x, ap.win_y);
	ap.addr = mlx_get_data_addr(ap.img, &ap.bits_per_pixel, &ap.line_length,
							&ap.endian);
	raycast_sprite(&ap);
	if (argc == 2)
	{
		mlx_hook(ap.win, 2, 1L << 0, press_key, &ap);
		mlx_hook(ap.win, 17, 0L, ft_exit, &ap);
		mlx_loop(ap.mlx);
	}
	if (argc == 3)
		make_screenshot(&ap);
	ft_free_map(&ap);
}

int			main(int argc, char **argv)
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	if (argc == 2)
	{
		if (!check_type_map(argv[1]) || (fd = open(argv[1], O_RDONLY)) < 0)
		{
			write(1, "this map isn't valid\n", 21);
			return (0);
		}
		make_map(fd, argc);
	}
	if (argc == 3)
	{
		if ((!check_type_screen(argv[2]) && argc == 3))
		{
			write(1, "argv[2] isn't correct\n", 23);
			return (0);
		}
		make_map(fd, argc);
	}
	else
		write(1, "quantity of arguments isn't correct\n", 36);
	close(fd);
	return (0);
}
