/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/08 10:49:16 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/08 10:51:47 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_texmap(t_texmap *texmap)
{
	if (texmap->no_path)
		ft_free_string(&texmap->no_path);
	if (texmap->so_path)
		ft_free_string(&texmap->so_path);
	if (texmap->we_path)
		ft_free_string(&texmap->we_path);
	if (texmap->ea_path)
		ft_free_string(&texmap->ea_path);
	if (texmap->ceiling)
		ft_free_string(&texmap->ceiling);
	if (texmap->floor)
		ft_free_string(&texmap->floor);
	if (texmap->map)
		ft_free_array(texmap->map);
}
