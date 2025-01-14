/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/13 07:35:14 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/14 09:11:47 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static t_ceiling	*init_ceiling(t_cube *data)
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

static t_floor	*init_floor(t_cube *data)
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

static t_texmap	*init_texmap(t_cube *data)
{
	t_texmap	*texmap;

	texmap = malloc(sizeof(t_texmap));
	if (!texmap)
		error_bye_data(data, "malloc failed in init_texmap()\n");
	ft_memset(texmap, 0, sizeof(t_texmap));
	texmap->ceiling = init_ceiling(data);
	texmap->floor = init_floor(data);
	texmap->map = NULL;
	return (texmap);
}

static t_player	*init_player(t_cube *data)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		error_bye_data(data, "malloc failed in init_player()\n");
	ft_memset(player, 0, sizeof(t_player));
	return (player);
}

void	init_cube(t_cube *data)
{
	ft_memset(data, 0, sizeof(t_cube));
	data->texmap = init_texmap(data);
	data->p = init_player(data);
	data->cub_file = NULL;
}
