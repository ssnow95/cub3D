/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 20:12:42 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/10/18 11:45:16 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D_H
# define CUB_3D_H

# include <stdio.h>
# include <math.h>
# include "../mlx/mlx.h"
# include <fcntl.h>
# include "get_next_line.h"

typedef struct			s_texture
{
	void				*img;
	int					*addr;
	int					bpp;
	int					len;
	int					end;
	int					width;
	int					height;
}						t_texture;

typedef struct			s_sprite
{
	struct s_sprite		*next;
	int					displayed;
	float				dist;
	int					x_3d;
	int					y_3d;
	int					x_2d;
	int					y_2d;
}						t_sprite;

typedef struct			s_vars
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	float				dist_to_pp;
	float				angle;
	int					win_x;
	int					win_y;
	float				fov;
	int					rgb;
	float				len_v;
	float				len_h;
	float				ax;
	float				ay;
	float				bx;
	float				by;
	int					xa_v;
	float				ya_v;
	int					ya_h;
	float				xa_h;
	char				wall_site;
	float				pix_x;
	float				pix_y;
	int					pre_win_x;
	int					pre_win_y;
	int					r;
	int					g;
	int					b;
	int					x;
	int					y;
	int					h_of;
	int					v_of;
	int					color;
	float				sprite_dir;
	float				sprite_dist;
	size_t				s_scr_size;
	size_t				j;
	int					color_col;
	float				dist;
	float				pre_horizontal;
	float				pre_vertical;
	char				direction;
	float				tex_pos;
	int					flag_player;
	char				**map_spr;
	float				pos_x;
	float				final_x;
	float				final_y;
	int					flag;
	int					flag_n;
	int					flag_s;
	int					flag_west;
	int					flag_east;
	int					wall_size;
	int					centre;
	int					start;
	int					y2;
	char				*new_arr;
	char				*line;
	char				*tmp2;
	int					find_wrong;
	int					flag_sprite;
	float				*arr_rays;
	int					x_h;
	int					flag_for_player;
	int					y_h;
	int					x_v;
	int					y_v;
	int					block_w;
	int					block_h;
	float				pl_pix_x;
	float				pl_pix_y;
	float				pos_y;
	float				player_a;
	char				**map;
	char				**tmp;
	int					map_w;
	int					map_h;
	t_sprite			*sprites;
	int					floor;
	int					ceil;
	t_texture			*n;
	t_texture			*s;
	t_texture			*west;
	t_texture			*east;
	t_texture			*sprite;
}						t_vars;

int						my_get_color(t_vars *ap, int x, int y);
void					make_struct(t_vars *ap);
void					make_struct1(t_vars *ap);
t_texture				*make_t(void *mlx_ptr, char *s, int flag, t_vars *ap);
void					make_screenshot(t_vars *ap);
void					ft_lstadd_back(t_sprite **sprite, t_sprite *new);
int						check_type_screen(char *str);
int						make_map_sprite(t_vars *ap);
int						make_lst_sprites(t_vars *ap);
int						pix_color_s(t_texture *text, int x, int y, float line);
int						get_variables(t_vars *ap, t_sprite *sprite, size_t i);
void					draw_sprite(t_vars *ap, t_sprite *sprite, size_t i);
int						*ft_free(char **str, int i, int size);
int						make_new_map(t_vars *ap, char *str, int i);
int						make_arr_cpy(int i, t_vars *ap, int len, int j);
int						make_one_str(t_vars *ap, int len, char *str);
int						parse_map(t_vars *ap, char *str, int i, int flag);
int						create_rgb(t_vars *ap);
t_sprite				*find_sprite_from_lst(t_vars *ap, int y, int x);
void					draw_sprite2(t_vars *ap, size_t i, size_t j);
void					raycast(t_vars *ap, int i);
void					raycast_vertical(t_vars *ap, int i);
void					get_xa_h_and_ya_h(t_vars *ap);
void					raycast_horizontal(t_vars *ap, int i);
int						make_malloc(t_vars *ap, int len);
void					key_123_124_125_126(int key, t_vars *ap);
void					key_13_1_0_2(int key, t_vars *ap);
void					draw_column(t_vars *ap, int col_nmb, float step);
void					get_sprite(t_vars *ap, t_sprite *sprite, int y, int x);
void					get_ya_v_and_xa_v(t_vars *ap);
void					add_one_to_line_start(t_vars *ap, int j, char *line);
void					add_one_to_line_end(t_vars *ap, int j, char *line);
char					*add_one_to_line(t_vars *ap, char *line, int i);
void					make_square_map(t_vars *ap);
void					draw_column(t_vars *ap, int col_nmb, float step);
int						grid(t_vars *ap, int grid_x, int grid_y);
int						create_color_b(char *str, int i, t_vars *ap, int flag);
int						create_color_g(char *str, int i, t_vars *ap, int flag);
int						create_color_r(char *str, int i, t_vars *ap, int flag);
int						check_repeat_rgb(t_vars *ap, int *f_or_c);
int						put_color(t_vars *ap, char *str, int *f_or_c);
int						parse_texture(t_vars *ap, char *str);
void					free_texture(t_vars *ap);
void					check_angle(t_vars *ap);
void					get_color_wall(t_vars *ap, int col_nmb);
void					check_wall_0_to_m_pi(t_vars *ap);
void					check_wall_m_pi_to_2_m_pi(t_vars *ap);
void					my_mlx_pixel_put(t_vars *ap, int x, int y, int color);
int						check_type_map(char *str);
int						make_size_window(t_vars *ap, char *line);
int						coord_player(t_vars *ap, char **str, int i, int j);
int						adge_of_map(t_vars *ap, int i, int j);
int						check_sym_map(char c);
int						search_space(t_vars *ap);
int						check_map(t_vars *ap);
int						errors(t_vars *ap);
int						parse(int fd, t_vars *ap, int i);
void					raycast_sprite2(t_vars *ap, t_sprite *a);
void					raycast_sprite(t_vars *ap);
void					make_map_2(t_vars *ap, int fd);
void					the_longest_row(t_vars *ap);
void					print_player(t_vars *ap);
int						check_wall_down(t_vars *ap);
int						check_wall_up(t_vars *ap);
int						check_wall_left(t_vars *ap);
int						check_wall_right(t_vars *ap);
int						press_key(int key, t_vars *ap);
void					make_map(int fd, int argc);
int						check_first_row(t_vars *ap, int j);
int						check_last_row(t_vars *ap, int i);
void					player_direct(t_vars *ap, char direction, int i, int j);
int						coord_player(t_vars *ap, char **str, int i, int j);
int						make_size_window(t_vars *ap, char *line);
int						get_size_window(t_vars *ap, char *line, int i);
void					ft_free_map(t_vars *ap);
int						ft_exit(t_vars *ap);
void					my_mlx_pixel_put(t_vars *ap, int x, int y, int color);
void					ft_lstadd_back(t_sprite **sprite, t_sprite *new);
t_sprite				*find_sprite_from_lst(t_vars *ap, int y, int x);
int						main();

#endif
