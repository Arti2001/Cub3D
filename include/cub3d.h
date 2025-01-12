/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gosia <gosia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:46:03 by mstencel          #+#    #+#             */
/*   Updated: 2025/01/12 12:07:05 by gosia            ###   ########.fr       */
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


# define ERR_NO_PATH_FOUND "Some paths could not be found.\n"
# define ERR_OUT_OF_RANGE_F "Incorrect floor's color value: Out of range: 0...255\n"
# define ERR_OUT_OF_RANGE_C "Incorrect ceiling's color value: Out of range: 0...255\n"
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

typedef struct s_ceiling
{
	int	r;
	int	g;
	int	b;
}	t_ceiling;

typedef struct s_floor
{
	int	r;
	int	g;
	int	b;
}	t_floor;

typedef struct s_cublist
{
	char				*line;
	struct s_cublist	*next;
	int					height;
}	t_cublist;

typedef struct s_player
{
	double		x_pos;
	double		y_pos;
	char		pos;
}	t_player;

typedef struct s_texmap
{
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	char		**map;
	int			height;
	t_floor		*floor;
	t_ceiling	*ceiling;
}	t_texmap;

typedef	struct s_cub3d
{
	t_texmap	*texmap;
	t_cublist	*cub_file;
	t_cublist	*end_texture;
	t_player	*p;
}	t_cube;


// map checks
void	name_check(char *file);
void	map_check(t_cube *data);

//map parsing
char	is_white_space_nline(char c);

//parse utils
char	**splitbywhite(char const *s, char c);
void	del_list(t_cublist *map);
t_cublist	*add_node(char *line);
long	node_count(t_cublist *map);

// errors
void	error_p(char *str);
void	err_fd_data_bye(t_cube *data, int fd, int flag);
void	error_bye_data(t_cube *data, char *str);

//freeing
void	free_data(t_cube *data);

void	if_valid_add(t_cube *data);

void	floor_rgb(char* str, t_cube *data);
void	ceiling_rgb(char* str, t_cube *data);

int		are_digits(char *str);
bool	is_full(t_texmap *texmap);

void	read_taxmap(char *file, t_cube *data);
bool	is_struct_full(t_ceiling *ceiling, t_floor *floor);
void	del_list(t_cublist *map);

#endif