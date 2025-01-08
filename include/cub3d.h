/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 10:46:03 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/08 09:09:07 by mstencel      ########   odam.nl         */
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


typedef struct s_tex_map
{
	char*	no_path;
	char*	so_path;
	char*	we_path;
	char*	ea_path;

	char*	floor;
	char*	ceiling;

	char	**map;
}	t_texmap;

// map checks
void	name_check(char *file);

void	pars_texmap(char* arg);
char	**splitbywhite(char const *s);

// errors
void	error_p(char *str);

#endif