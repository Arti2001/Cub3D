/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: amysiv <amysiv@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/08 10:49:16 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/28 08:00:26 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	del_list(t_maplist *map)
{
	t_maplist	*current;

	while (map != NULL)
	{
		ft_free_string(&map->line);
		current = map->next;
		free(map);
		map = current;
	}
	free(map);
}

void	free_data(t_root *data)
{
	if (data->map_list)
		del_list(data->map_list);
	if (data->map.map)
		ft_free_array(data->map.map);
	if (data->map.no_path)
		ft_free_string(&data->map.no_path);
	if (data->map.so_path)
		ft_free_string(&data->map.so_path);
	if (data->map.ea_path)
		ft_free_string(&data->map.ea_path);
	if (data->map.we_path)
		ft_free_string(&data->map.ea_path);
}
