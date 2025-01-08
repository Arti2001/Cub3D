/* ************************************************************************** */
/*                                                                            */
<<<<<<< HEAD
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:46:03 by mstencel          #+#    #+#             */
/*   Updated: 2025/01/07 20:03:06 by amysiv           ###   ########.fr       */
=======
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 10:46:03 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/06 14:51:44 by mstencel      ########   odam.nl         */
>>>>>>> ddb468a8ee46510a260f967a273c344d0196b789
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include "../include/libft/libft.h"
# include "../include/mlx42/include/MLX42/MLX42.h"

# include <stdio.h>
# include <fcntl.h>
# include <math.h>

<<<<<<< HEAD
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

=======
// map checks
int	map_check(char *file);

// errors
void	error_p(char *str);
>>>>>>> ddb468a8ee46510a260f967a273c344d0196b789

#endif