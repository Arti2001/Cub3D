# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mstencel <mstencel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2025/01/06 09:23:22 by mstencel      #+#    #+#                  #
#    Updated: 2025/01/06 11:59:51 by mstencel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

.PHONY = all, clean, fclean, re

NAME = cub3D

SRC_PATH = src

SRC_FILES = src/main.c

OBJ_PATH = obj

# this is a pattern substitution:
# the SRC_FILES will have a list with their full paths
# the SRC_PATH/%.c are the source of the files that will be replaced
# the OBJ_PATH/%.o are the replacement of the /%.c
OBJ_FILES = $(SRC_FILES:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)

HEADER = include/cub3D.h

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

MLX42_PATH = ./mlx42
MLX42 = $(MLX42_PATH)/libmlx42.a

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
MLX42FLAGS = -Iinclude -ldl -lglfw -pthread -lm

RM = rm -f
RD = rm -rf

all: $(MLX42) $(LIBFT) $(NAME)

$(MLX42):
	cmake -S $(MLX42_PATH) -B $(MLX42_PATH)/build
	make -C $(MLX42_PATH)/build -j4

$(LIBFT):
	make -C $(LIBFT_PATH)

$(NAME): $(OBJ_FILES) $(HEADER)
	$(CC) $(OBJ_FILES) $(CFLAGS) $(MLX42FLAGS) -o $(NAME) $(LIBFT) $(MLX42)

# the $(@D) - The directory part of the file name of the target,
# with the trailing slash removed. 
# e.g. if the value of ‘$@’ is dir/foo.o then ‘$(@D)’ is dir. 
# This value is . if ‘$@’ does not contain a slash.
$(OBJ_PATH)/%.o:$(SRC_PATH)%.c
	@if [! -d "$(@D)"]; then mkdir $(@D) & echo "$(@D) MADE"; fi
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_FILES)
	$(RD) $(OBJ_PATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all