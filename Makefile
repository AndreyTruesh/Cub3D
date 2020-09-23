# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abibi <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/22 00:31:18 by abibi             #+#    #+#              #
#    Updated: 2020/09/23 18:29:12 by abibi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D
FLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=8
LIBS = -L libft -lft -L minilibx-linux -lmlx -lXext -lX11 -lm
INCLUDES = -I include -I minilibx-linux -I gnl -I libft
HEADERS = include/cub.h libft/libft.h gnl/get_next_line.h
SRCS_G_DIR = ./srcs_game
SRCS_P_DIR = ./srcs_parser
SRCS_GNL_DIR = ./gnl
OBJS_DIR = ./objs
SRCS_G = dda_alg.c errors_processing_1.c errors_processing_2.c events_move.c game.c load_textures.c mem_free.c render_sprites.c render_walls.c screenshot.c sprites_processing.c
SRCS_P = cub.c get_color.c get_res_tex.c map_get_pos.c map_processing.c map_to_lst.c parser_utils.c map_lst_utils.c
SRCS_GNL = get_next_line.c get_next_line_utils.c
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS_G:c=o)) $(addprefix $(OBJS_DIR)/, $(SRCS_P:c=o)) $(addprefix $(OBJS_DIR)/, $(SRCS_GNL:c=o))

.PHONY: all, re, clean, fclean

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/ bonus
	make -C minilibx-linux
	gcc $(FLAGS) $(INCLUDES) $(OBJS)  $(LIBS) -o $(NAME)

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_G_DIR)/%.c $(HEADERS) | $(OBJS_DIR)
	gcc $(FLAGS) -c $< -o $@ $(INCLUDES)

$(OBJS_DIR)/%.o: $(SRCS_P_DIR)/%.c $(HEADERS) | $(OBJS_DIR)
	gcc $(FLAGS) -c $< -o $@ $(INCLUDES)

$(OBJS_DIR)/%.o: $(SRCS_GNL_DIR)/%.c $(HEADERS) | $(OBJS_DIR)
	gcc $(FLAGS) -c $< -o $@ $(INCLUDES)

clean:
	/bin/rm -rf $(OBJS_DIR)
	make -C libft/ clean
	make -C minilibx-linux/ clean

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean
	$(NAME)


