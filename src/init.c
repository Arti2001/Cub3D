/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/13 07:35:14 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/13 08:33:51 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static t_ceiling *init_ceiling(void)
{
	t_ceiling *ceiling = malloc(sizeof(t_ceiling));
	if (!ceiling)
		return NULL;
	ceiling->r = -1;
	ceiling->g = -1;
	ceiling->b = -1;
	return (ceiling);
}

static t_floor *init_floor(void)
{
	t_floor *floor = malloc(sizeof(t_floor));
	if (!floor)
		return NULL;
	floor->r = -1;
	floor->g = -1;
	floor->b = -1;
	return (floor);
}

static t_texmap	*init_texmap(void)
{
	t_texmap	*texmap;

	texmap = malloc(sizeof(t_texmap));
	if (!texmap)
		return (NULL);
	ft_memset(texmap, 0, sizeof(t_texmap));
	texmap->ceiling = init_ceiling();
	texmap->floor = init_floor();
	texmap->map = NULL;
	return (texmap);
}

static t_player *init_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	ft_memset(player, 0, sizeof(t_player));
	return (player);
}

void	init_cube(t_cube *data)
{	
	ft_memset(data, 0, sizeof(t_cube));
	
	data->texmap = init_texmap();
	data->cub_file = NULL;
	data->p = init_player();
}