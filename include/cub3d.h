/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 10:46:03 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/09 12:06:52 by mstencel      ########   odam.nl         */
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
# define ERR_NEW_NODE "Error creating new node in add_node()\n"
# define ERR_MAP_MALLOC "malloc() failed while creating the map in fill_map()\n"
# define ERR_LINE_DUP "ft_strdup() failed in fill_map()!\n"
# define ERR_GARBAGE_IN_THE_MAP "Alien character detected in the map!\n"
# define ERR_GARBAGE_AFTER_MAP "Alien object detected after the map!\n"
# define ERR_TOO_MANY_PLAYERS "Provide only 1 player's starting position!\n"
# define ERR_PLAYER_MISSING "Missing player's starting position!\n"
# define ERR_OPEN_MAP "Provide an enclosed map!\n"

typedef struct s_map
{
	char			*line;
	struct s_map	*next;
}	t_map;

typedef struct s_player
{
	double	x_pos;
	double	y_pos;
	char	pos;
}	t_player;

typedef struct s_tex_map
{
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	char		*floor;
	char		*ceiling;
	char		**map;
	long		map_height;
	t_player	p;
}	t_texmap;

// map checks
void	name_check(char *file);
void	map_check(t_texmap *tmap);

//map parsing
void	pars_texmap(char *arg);
void	get_map(int fd, t_texmap *texmap);

//parse utils
char	**splitbywhite(char const *s);
void	del_list(t_map *map);
t_map	*add_node(char *line);
long	node_count(t_map *map);

// errors
void	error_p(char *str);
void	error_bye_texmap(t_texmap *texmap, char *str);
void	list_error(t_map *map_list, t_texmap *texmap, char *str);

//freeing
void	free_texmap(t_texmap *texmap);

// to delete
void	print_texmap(t_texmap *texmap);

#endif