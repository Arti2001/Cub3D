/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:46:03 by mstencel          #+#    #+#             */
/*   Updated: 2025/01/09 11:01:22 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include "../include/libft/libft.h"
# include "../include/mlx42/include/MLX42/MLX42.h"

# include <stdio.h>
# include <fcntl.h>
# include <math.h>

#define ERR_NO_ARG "Incorrect number of arguments\n"
#define ERR_MAP_NAME "Incorrect map name. Use \033[3mname\033[0m.cub format\n"
#define ERR_NO_PATH_FOUND "Some paths could not be found.\n"
#define ERR_OUT_OF_RANGE_F "Incorrect floor color input\n"
#define ERR_OUT_OF_RANGE_C "Incorrect ceiling color input\n"


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

typedef struct s_tex_map
{
	char*		no_path;
	char*		so_path;
	char*		we_path;
	char*		ea_path;
	
	t_ceiling*	ceiling;
	t_floor*	floor;
	
	char**		map;
}	t_texmap;



// map checks
void	name_check(char *file);
char	is_white_space_nline(char c);

void	pars_texmap(char* arg);
char	**splitbywhite(char const *s, char c);

// errors
void	error_p(char *str);
void	error_bye_texmap(t_texmap *texmap, char *str);

//free
void	free_texmap(t_texmap *texmap);

#endif