# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: amysiv <amysiv@student.42.fr>                +#+                      #
#                                                    +#+                       #
#    Created: 2025/01/06 09:23:22 by mstencel      #+#    #+#                  #
#    Updated: 2025/02/14 13:51:54 by mstencel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

RESET = \033[0m
GREEN = \033[38;5;82m
RED = \033[31;1m

NAME = cub3D

SRC_DIR = src

SRC_FILES = src/errors.c \
			src/free.c \
			src/main.c \
			src/parsing/check_map.c \
			src/parsing/get_player.c \
			src/parsing/parse_map.c \
			src/parsing/parse_map2.c \
			src/parsing/parse_texture_utils.c \
			src/parsing/parse_texture.c \
			src/parsing/parse_texture2.c \
			src/parsing/splitbywhite.c \
			src/render/draw_utils.c \
			src/render/draw.c \
			src/render/key_hooks.c \
			src/render/mini_map_utils.c \
			src/render/mini_map.c \
			src/render/mlx_init.c \
			src/render/rays.c

OBJ_DIR = obj

# this is a pattern substitution:
# the SRC_FILES will have a list with their full paths
# the SRC_DIR/%.c are the source of the files that will be replaced
# the OBJ_DIR/%.o are the replacement of the /%.c
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

HEADER = include/cub3d.h

LIBFT_PATH = include/libft
LIBFT = $(LIBFT_PATH)/libft.a

MLX42_PATH = include/mlx42
MLX42 = $(MLX42_PATH)/build/libmlx42.a

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -Ofast
MLX42FLAGS = -Iinclude -ldl -lglfw -pthread -lm

RM = rm -rf


all: $(MLX42) $(LIBFT) $(NAME)

$(MLX42):
	@cmake -S $(MLX42_PATH) -B $(MLX42_PATH)/build
	@make -C $(MLX42_PATH)/build -j4
	@echo "$(GREEN)MLX42 BUILT$(RESET)"

$(LIBFT):
	@make -C $(LIBFT_PATH)
	@echo "$(GREEN)LIBFT BUILT$(RESET)"

$(NAME): $(OBJ_FILES) $(HEADER)
	@$(CC) $(OBJ_FILES) $(CFLAGS) $(MLX42FLAGS) -o $(NAME) $(LIBFT) $(MLX42)
	@echo "$(GREEN)cub3D made$(RESET)"

# the $(@D) - The directory part of the file name of the target,
# with the trailing slash removed. 
# e.g. if the value of ‘$@’ is dir/foo.o then ‘$(@D)’ is dir. 
# This value is . if ‘$@’ does not contain a slash.
$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@if [ ! -d "$(@D)" ]; then mkdir $(@D); fi
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_FILES)
	@$(RM) $(OBJ_DIR)
	@echo ".o files & .obj $(RED)removed$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "cub3D $(RED)removed$(RESET)"

re: fclean all

.PHONY = all, clean, fclean, re