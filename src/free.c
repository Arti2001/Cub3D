/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/08 10:49:16 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/10 12:16:49 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_data(t_cube *data)
{
	if (data->p)
		free (data->p);
	if (data->cub_file)
		del_list(data->cub_file);
	if (data->texmap->map)
		ft_free_array(data->texmap->map);
	if (data->texmap->ceiling)
		free (data->texmap->ceiling);
	if (data->texmap->floor)
		free (data->texmap->floor);
	if (data->texmap->no_path)
		ft_free_string(&data->texmap->no_path);
	if (data->texmap->so_path)
		ft_free_string(&data->texmap->so_path);
	if (data->texmap->ea_path)
		ft_free_string(&data->texmap->ea_path);
	if (data->texmap->we_path)
		ft_free_string(&data->texmap->ea_path);
	
	//free all the data
}
