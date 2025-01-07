/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:46:03 by mstencel          #+#    #+#             */
/*   Updated: 2025/01/07 20:03:06 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include "../include/libft/libft.h"
# include "../include/mlx42/include/MLX42/MLX42.h"

# include <stdio.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_tex_map
{
	char*	no_path;
	char*	so_path;
	char*	we_path;
	char*	ea_path;

	char*	floor;
	char*	ceiling;

	char	*map;
}	t_texmap;


char	**splitbywhite(char const *s);


#endif