NAME = cub3D

SRCS = srcs/check_map_2.c srcs/color_2.c srcs/color.c srcs/cub3d.c \
srcs/get_next_line_utils.c srcs/get_next_line.c srcs/make_square_map.c srcs/other_2.c srcs/other.c srcs/parse_map.c srcs/player.c srcs/press_key_2.c srcs/press_key.c srcs/raycast_2.c srcs/raycast.c srcs/raycast_3.c srcs/texture.c srcs/window.c\
srcs/screenshot.c srcs/sprite_2.c srcs/sprite.c srcs/check_map.c

OBJS = $(SRCS:.c=.o)
HEADER = ./srcs/cub_3d.h

FLAGS = $(-Wall -Wextra -Werror)

LIB = libmlx.dylib

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	gcc $(OBJS) $(LIB) -framework OpenGL -framework AppKit -o $(NAME)

$(LIB):
	$(MAKE) -C mlx
	mv mlx/$(LIB) ./

$(OBJS): %.o:%.c $(HEADER)
	gcc $(FLAGS) -Imlx -c $< -o $@

clean:
	/bin/rm -f srcs/*.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
