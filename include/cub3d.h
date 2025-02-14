/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: amysiv <amysiv@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 10:46:03 by mstencel      #+#    #+#                 */
/*   Updated: 2025/02/14 11:33:32 by mstencel      ########   odam.nl         */
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
# define MMTH 60 //tile height
# define MMTW 60 //tile width
# define FOV 60 //field of view
# define RAYS_NUMB 320 //number of rays
# define MMPP 10
# define NAME "cub3D"
# define WALL 0
# define FLOOR 1
# define SPACE 2
# define RAY 3
# define X 0
# define Y 1
# define HB 0.2
# define EPSILON 1e30
# define MM_DIMENSION 360
# 

typedef enum e_moves
{
	FORWARD = 1,
	BACKWARD = 2,
	RIGHT_MOVE = 3,
	LEFT_MOVE = 4,
	TURN_RIGHT = 5,
	TURN_LEFT = 6,
}	t_moves;

typedef enum e_sides
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3,
}	t_sides;

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
	t_img				img_map;
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

typedef struct s_wall
{
	int		height;
	int		start;
	int		end;
	int		map_tile; //the current tile on the map
	int		tex_x; //x coordinate on the texture
	int		tex_y; //calculated with wall.step
	int		tex_width; //width of the texture (from the file)
	int		tex_height; //height of the texture (from the file)
	int		tex_start; //tex starting position in integer
	double	hit_point; //exact hit point for y for EW wall or x for NS wall
	double	step; //the amount to increase the texture coordinate per pixel
	double	tex_pos; //the texture's starting position
}	t_wall;

typedef struct s_ray //data for the raycasting
{
	double	camera_x; // x-coordinate along the camera line
	double	distance; //distance of between the player & wall (total ray length)
	double	dir_x; //x direction of the ray
	double	dir_y; //y direction of the ray
	int		x_map; //player's position on the grid
	int		y_map; //player's position on the grid
	double	x_off; //distance -> the actual player's position and nearest x
	double	y_off; //distance -> the actual player's position and nearest y
	double	steps_x; //x_step's length (number of y's in between x1 & x2)
	double	steps_y; //y_step's length (number of x's in between y1 & y2)
	int		flag; //to show if the step is taken in x or in y direction
	int		side; //NORTH SOUTH EAST WEST
}	t_ray;

typedef struct s_maplist
{
	char				*line;
	struct s_maplist	*next;
	int					height;
	int					line_len;
}	t_maplist;

typedef struct s_player
{
	double			x_pos;
	double			y_pos;
	double			plane_x;
	double			plane_y;
	double			x_dir;
	double			y_dir;
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
	int					mm_start_x;
	int					mm_start_y;
	t_floor				floor;
	t_ceiling			ceiling;
}	t_map;

typedef struct s_root
{
	t_map				map;
	t_maplist			*map_list;
	t_maplist			*map_search;
	t_player			p;
	t_ray				ray;
	t_cubmlx			cub_mlx;
	mlx_texture_t		*textures[4];
}	t_root;

//freeing
void		free_data(t_root *data);
void		free_mlx(t_root *data);
char		*new_mem(char *str, t_root *data);

// errors
void		error_p(char *str);
void		err_fd_data_bye(t_root *data, int fd, int flag);
void		error_bye_data(t_root *data, char *str);
void		error_bye_mlx_data(t_root *data, char *str);
void		free_data_arr(t_root *data, char *str, char **arr);

						/**********		PARSING		**********/
//map parsing
void		read_taxmap(char *file, t_root *data);
void		fill_map(t_root *data);

// map checks
void		map_check(t_root *data);
void		player_found(t_root *data, long y, long x, bool *position);

//parse utils
char		is_white_space_nline(char c);
char		**splitbywhite(char const *s, char c);
void		del_list(t_maplist *map);

//texture
void		floor_rgb(char *str, t_root *data);
void		ceiling_rgb(char *str, t_root *data);
bool		is_c_full(t_ceiling ceiling);
bool		is_f_full(t_floor floor);
void		if_valid_add(t_root *data);
void		floor_rgb(char *str, t_root *data);
void		ceiling_rgb(char *str, t_root *data);
int			are_digits(char *str);
bool		validate_format(char *str);
bool		is_full(t_map map);
bool		comma_checker(char *str);
char		*new_mem(char *str, t_root *data);
int			skip_all_space(char *str, int i);

						/**********		RENDERING		**********/
void		run_mlx(t_root *data);
void		draw_game(void *param);
void		key_hooks( void *param);
void		add_mini_map(t_root *data);

//drawing
void		draw_player(t_root *data);
uint32_t	ft_my_pixel(uint32_t r, uint32_t g, uint32_t b, uint32_t a);
void		blue_it_all(t_root *data, uint32_t col);

//math
void		get_rays(t_root *data, int i);

#endif