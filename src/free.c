/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:49:16 by mstencel          #+#    #+#             */
/*   Updated: 2025/01/14 12:24:20 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	del_list(t_cublist *map)
{
	t_cublist	*current;

	while (map != NULL)
	{
		ft_free_string(&map->line);
		current = map->next;
		free(map);
		map = current;
	}
	free(map);
}

void	free_data(t_cube *data)
{
	if (data->p)
		free (data->p);
	if (data->cub_file)
		del_list(data->cub_file);
	if (data->texmap)
	{
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
		free(data->texmap);
	}
}
