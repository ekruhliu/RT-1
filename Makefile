# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/12 13:30:51 by ekruhliu          #+#    #+#              #
#    Updated: 2018/10/12 13:30:52 by ekruhliu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RT

FLAGS = -c -Wall -Wextra -Werror -O3

SDL = -framework OpenCL -rpath @loader_path/frameworks/ -I frameworks/SDL2.framework/Headers -I frameworks/SDL2_image.framework/Headers -I frameworks/SDL2_ttf.framework/Headers -lm -framework SDL2 -framework SDL2_image -framework SDL2_ttf -F ./frameworks

HEADER = ./rt_open_cl.h ./frameworks/textBox/tinyfiledialogs.h ./frameworks/libJson/nxjson.h

LIBFT = ./libft/libft.a

SRCS = ./float3_lib/float3_lib.c ./srcs/hooks.c ./srcs/rt_draw.c ./srcs/rt_open_cl.c ./srcs/triangle.c ./frameworks/textBox/tinyfiledialogs.c ./ui/change_values.c ./ui/clear_ui.c \
./ui/create_buttons.c ./ui/figure_selection.c ./ui/init_ui.c ./ui/interface_win.c ./ui/query_textures.c ./ui/screenshot.c ./ui/ui.c \
./ui/using_filters.c ./ui/zero_maker.c ./frameworks/libJson/nxjson.c ./ui/light_mouse.c ./ui/object_window.c ./ui/object_window_part_one.c \
./ui/object_window_part_two.c ./srcs/valid.c ./parsing/rt_json.c ./srcs/set_rotation.c ./srcs/moves.c ./srcs/main.c ./srcs/ft_atof.c ./float3_lib/add_min.c ./float3_lib/mathm.c \
./float3_lib/set_rotate.c ./srcs/ocl_error.c ./srcs/write_cl_data.c ./srcs/cl_mem_create_write.c ./srcs/obj_to_normal.c ./parsing/pars_val_and_cams.c ./srcs/initialization.c \
./srcs/perlin.c ./srcs/load_file.c ./srcs/shit_happens.c ./srcs/frames.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@ make -C libft/
		@ gcc -o $(NAME) $(OBJ) $(LIBFT) $(SDL)
		@ echo "\033[1m\033[32mCompile!\033[0m"

%.o: %.c $(HEADER)
		@ gcc $(FLAGS) -o  $@ $<

clean:
		@ /bin/rm -f $(OBJ)
		@ make -C libft/ clean
		@ echo "\033[1m\033[31mAll the object files have been deleted.\033[0m"

fclean: clean
		@ /bin/rm -f $(NAME)
		@ make -C libft/ fclean
		@ echo "\033[1m\033[31m$(NAME) has been deleted.\033[0m"

re: fclean all
