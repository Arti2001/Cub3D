/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: amysiv <amysiv@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/08 10:49:16 by mstencel      #+#    #+#                 */
/*   Updated: 2025/02/11 09:12:23 by mstencel      ########   odam.nl         */
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
	if (data->map.no_path)
		ft_free_string(&data->map.no_path);
	if (data->map.so_path)
		ft_free_string(&data->map.so_path);
	if (data->map.we_path)
		ft_free_string(&data->map.we_path);
	if (data->map.ea_path)
		ft_free_string(&data->map.ea_path);
	if (data->map.map)
		ft_free_array(data->map.map);
}

void	free_textures(t_root *data)
{
	if (data->textures[0])
		mlx_delete_texture(data->textures[0]);
	if (data->textures[1])
		mlx_delete_texture(data->textures[1]);
	if (data->textures[2])
		mlx_delete_texture(data->textures[2]);
	if (data->textures[3])
		mlx_delete_texture(data->textures[3]);
}

void	free_mlx(t_root *data)
{
	if (data->cub_mlx.img_map.img_ptr)
		mlx_delete_image(data->cub_mlx.win, data->cub_mlx.img_map.img_ptr);
	if (data->cub_mlx.img.img_ptr)
		mlx_delete_image(data->cub_mlx.win, data->cub_mlx.img.img_ptr);
	free_textures(data);
	if (data->cub_mlx.win)
	{
		mlx_close_window(data->cub_mlx.win);
		mlx_terminate(data->cub_mlx.win);
	}
}
