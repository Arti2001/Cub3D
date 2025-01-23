/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: amysiv <amysiv@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 10:46:03 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/23 07:57:30 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../include/libft/libft.h"
# include "../include/mlx42/include/MLX42/MLX42.h"

# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define ERR_NO_ARG "Incorrect number of arguments\n"
# define ERR_MAP_NAME "Incorrect map name. Use \033[3mname\033[0m.cub format\n"
# define ERR_NO_MAP "Incorrect file: no map found\n"
# define ERR_EMPTY_MAP "Empty map! Provide file with correct content.\n"
# define ERR_TOO_MANY_LINES "The file is too big. Max number of lines: 350\n"
# define ERR_TOO_LONG_LINE "too long line in the file. max length: 300\n"
# define ERR_TOO_MANY_TEXTURES "Incorrect file format: multiple textures\n"
# define ERR_COMMA "Incorrect color: values must be separeted by a comma\n"
# define ERR_COLOR_DIGIT "Incorrect color value: Only digits allowed\n" 
# define ERR_NO_PATH_FOUND "Some paths could not be found.\n"
# define ERR_OUT_OF_RANGE_F "Incorrect color value: Out of range: 0..255\n"
# define ERR_OUT_OF_RANGE_C "Incorrect color value: Out of range: 0...255\n"
# define ERR_TO_FEW_PARAM_F "To few parameters to make a floor's color.\n"
# define ERR_TO_FEW_PARAM_C "To few parameters to make a ceiling's color.\n"
# define ERR_TO_MANY_PARAM_C "To many parameters to make a ceiling's color.\n"
# define ERR_TO_MANY_PARAM_F "To many parameters to make a floor's color.\n"

# define ERR_MAL_NEW_NODE "malloc failed while creating node in add_node()\n"
# define ERR_MAP_MALLOC "malloc failed while creating the map in fill_map()\n"
# define ERR_MALLOC_LINE "malloc failed in coping the line in add_node()\n"
# define ERR_MALLOC_MAP_LINE "malloc failed in fill_map()!\n"

# define ERR_GARBAGE_BEFORE_MAP "Alien object detected before the map!\n"
# define ERR_GARBAGE_IN_THE_MAP "Alien character detected in the map!\n"
# define ERR_GARBAGE_AFTER_MAP "Alien object detected after the map!\n"
# define ERR_TOO_MANY_PLAYERS "Provide only 1 player's starting position!\n"
# define ERR_PLAYER_MISSING "Missing player's starting position!\n"
# define ERR_OPEN_MAP "Provide an enclosed map!\n"

# define TH 64 //tile height
# define TW 64 //tile width
# define MMTH 35 //tile height
# define MMTW 35 //tile width
# define ANG 60 //player's angle
# define MMPP 10
# define NAME "cub3D"
# define PLAYER 0
# define WALL 1
# define FLOOR 2
# define RAY 3
# define SPACE 4
# define X 0
# define Y 1
# define HITBOX 0.2

typedef struct s_img
{
	mlx_image_t			*img_ptr;
}	t_img;

typedef struct s_cubmlx
{
	mlx_t				*win;
	int					win_h;
	int					win_w;
	t_img				img;
}	t_cubmlx;

typedef struct s_ceiling
{
	int					r;
	int					g;
	int					b;
}	t_ceiling;

typedef struct s_floor
{
	int					r;
	int					g;
	int					b;
}	t_floor;

typedef struct s_maplist
{
	char				*line;
	struct s_maplist	*next;
	int					height;
	int					line_len;
}	t_maplist;

typedef struct s_player
{
	float			x_pos;
	float			y_pos;
	char			pos;
}	t_player;

typedef struct s_map
{
	char				*no_path;
	char				*so_path;
	char				*we_path;
	char				*ea_path;
	char				**map;
	int					height;
	int					lenght;
	t_floor				*floor;
	t_ceiling			*ceiling;
}	t_map;

typedef struct s_root
{
	t_map				*map;
	t_maplist			*map_list;
	t_maplist			*map_search;
	t_player			*p;
	t_cubmlx			cub_mlx;
}	t_root;

//initialisations
void		init_root(t_root *data);

//freeing
void		free_data(t_root *data);

// errors
void		error_p(char *str);
void		err_fd_data_bye(t_root *data, int fd, int flag);
void		error_bye_data(t_root *data, char *str);
void		free_data_arr(t_root *data, char *str, char **arr);

						/**********		PARSING		**********/
//map parsing
void		read_taxmap(char *file, t_root *data);
void		fill_map(t_root *data);

// map checks
void		map_check(t_root *data);

//parse utils
char		is_white_space_nline(char c);
char		**splitbywhite(char const *s, char c);
t_maplist	*add_node(char *line, t_root *data);
void		del_list(t_maplist *map);

//texture
void		floor_rgb(char *str, t_root *data);
void		ceiling_rgb(char *str, t_root *data);
bool		is_cf_full(t_ceiling *ceiling, t_floor *floor);
void		if_valid_add(t_root *data);
void		floor_rgb(char *str, t_root *data);
void		ceiling_rgb(char *str, t_root *data);
int			are_digits(char *str);
int			first_digit(char *str);
bool		is_full(t_map *map);
bool		comma_checker(char *str);

						/**********		RENDERING		**********/
void		run_mlx(t_root *data);

void		ft_resize(int32_t width, int32_t height, void *param);

//drawing utils
uint32_t	ft_my_pixel(uint32_t r, uint32_t g, uint32_t b, uint32_t a);

//hooks
void		key_hooks(mlx_key_data_t keydata, void *param);

//mini_map
void		add_mini_map(t_root *data);

//to delete
void		print_map(t_map *map);

//color
uint32_t	extract_rgb(mlx_texture_t *texture, int x, int y);

#endif