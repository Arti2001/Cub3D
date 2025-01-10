/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 10:46:03 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/10 12:29:23 by mstencel      ########   odam.nl         */
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
# define ERR_MAL_NEW_NODE "malloc failed while creating node in add_node()\n"
# define ERR_MAP_MALLOC "malloc failed while creating the map in fill_map()\n"
# define ERR_MALLOC_LINE "malloc failed in coping the line in add_node()\n"
# define ERR_LINE_DUP "ft_strdup() failed in fill_map()!\n"
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
	double	x_pos;
	double	y_pos;
	char	pos;
}	t_player;

typedef struct s_texmap
{
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	char		**map;
	t_floor		*floor;
	t_ceiling	*ceiling;
}	t_texmap;

typedef	struct s_cub3d
{
	t_texmap	*texmap;
	t_cublist	*cub_file;
	t_player	*p;
}	t_cube;


// map checks
void	name_check(char *file);
void	map_check(t_cube *data);

//map parsing
void	read_taxmap(char *file, t_cube *data);

//parse utils
char	**splitbywhite(char const *s);
void	del_list(t_cublist *map);
t_cublist	*add_node(char *line);
long	node_count(t_cublist *map);

// errors
void	error_p(char *str);
void	error_bye_data(t_cube *data, char *str);
void	list_error(t_cublist *map_list, t_cube *data, char *str);

//freeing
void	free_data(t_cube *data);

// to delete
void	print_texmap(t_cube *data);

#endif