/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: amysiv <amysiv@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/13 07:35:14 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/27 08:01:20 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static t_ceiling	*init_ceiling(t_root *data)
{
	t_ceiling	*ceiling;

	ceiling = malloc(sizeof(t_ceiling));
	if (!ceiling)
		error_bye_data(data, "malloc failed in init_ceiling()\n");
	ceiling->r = -1;
	ceiling->g = -1;
	ceiling->b = -1;
	return (ceiling);
}

static t_floor	*init_floor(t_root *data)
{
	t_floor	*floor;

	floor = malloc(sizeof(t_floor));
	if (!floor)
		error_bye_data(data, "malloc failed in init_floor()\n");
	floor->r = -1;
	floor->g = -1;
	floor->b = -1;
	return (floor);
}

static t_map	*init_map(t_root *data)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		error_bye_data(data, "malloc failed in init_map()\n");
	ft_memset(map, 0, sizeof(t_map));
	map->ceiling = init_ceiling(data);
	map->floor = init_floor(data);
	map->map = NULL;
	return (map);
}

static t_player	*init_player(t_root *data)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		error_bye_data(data, "malloc failed in init_player()\n");
	ft_memset(player, 0, sizeof(t_player));
	return (player);
}

static t_ray	*init_ray(t_root *data)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		error_bye_data(data, "malloc failed in init_ray()\n");
	ft_memset(ray, 0, sizeof(t_ray));
	return (ray);
}

void	init_root(t_root *data)
{
	ft_memset(data, 0, sizeof(t_root));
	data->map = init_map(data);
	data->p = init_player(data);
	data->ray = init_ray(data);
	data->map_list = NULL;
}
