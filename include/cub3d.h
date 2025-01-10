/* ************************************************************************** */
/*		*/
/*	:::	 ::::::::   */
/*   cub3d.h		:+:	 :+:	:+:   */
/*		+:+ +:+	 +:+	*/
/*   By: amysiv <amysiv@student.42.fr>		 +#+  +:+	  +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2025/01/06 10:46:03 by mstencel	  #+#	#+#		*/
/*   Updated: 2025/01/10 11:02:07 by amysiv	   ###   ########.fr	  */
/*		*/
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
# define ERR_NO_PATH_FOUND "Some paths could not be found.\n"
# define ERR_OUT_OF_RANGE_F "Incorrect floor's color value: Out of range: 0...255\n"
# define ERR_OUT_OF_RANGE_C "Incorrect ceiling's color value: Out of range: 0...255\n"
# define ERR_TO_FEW_PARAM_F "To few parameters to make a floor's color.\n"
# define ERR_TO_FEW_PARAM_C "To few parameters to make a ceiling's color.\n"
# define ERR_TO_MANY_PARAM_C "To many parameters to make a ceiling's color.\n"
# define ERR_TO_MANY_PARAM_F "To many parameters to make a floor's color.\n"
# define ERR_MAP_MALLOC "malloc failed while creating the map in fill_map()\n"
# define ERR_MALLOC_LINE "malloc failed in coping the line in add_node()\n"



typedef struct s_ceiling
{
	int				r;
	int				g;
	int				b;
}	t_ceiling;

typedef struct s_floor
{
	int				r;
	int				g;
	int				b;
}	t_floor;

typedef struct s_cublist
{
	int				height;
	char			*line;
	struct s_cublist	*next;
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
	t_ceiling	*ceiling;
	t_floor		*floor;
	char		**map;
}	t_texmap;

typedef struct s_cub3d
{
	t_cublist	*cub_file;
	t_texmap	*texmap;
	t_player	*p;
}	t_data;


// map checks
void	name_check(char *file);
char	is_white_space_nline(char c);

void	pars_texmap(char* arg);
char	**splitbywhite(char const *s, char c);

// errors
void	error_p(char *str);
void	error_bye_data(t_data *data, char *str);

//free
void	free_texmap(t_texmap *texmap);

void	read_taxmap(char *file, t_data *data);

void	if_valid_add(t_data *data);

void	floor_rgb(char* str, t_data *data);
void	ceiling_rgb(char* str, t_data *data);

int		are_digits(char *str);
bool		is_full(t_texmap *texmap);

int		open_texmapfile(char *file);
void	read_taxmap(char *file, t_data *data);
bool	is_struct_full(t_ceiling *ceiling, t_floor *floor);
void	del_list(t_cublist *map);

#endif